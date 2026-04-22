#include <firmament.h>
#include <lwip/sockets.h>

#include "module/task_manager/task_manager.h"

#define UDP_RECV

#define SERVER_IP   "192.168.1.24"
#define SERVER_PORT 5000

static fmt_err_t task_init(void)
{
    return FMT_EOK;
}

static void task_entry(void* parameter)
{
#ifdef UDP_RECV
    int sock = -1;
    struct sockaddr_in local_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    uint8_t recv_buffer[128] = { 0 };
    int recv_len;

    sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        printf("Socket creation failed\n");
        return;
    }

    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(SERVER_PORT);
    local_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr*)&local_addr, sizeof(local_addr)) < 0) {
        printf("Bind failed\n");
        closesocket(sock);
        return;
    }

    printf("UDP receiver ready, listening on port %d...\n", SERVER_PORT);

    while (1) {
        recv_len = recvfrom(sock, recv_buffer, sizeof(recv_buffer), 0, (struct sockaddr*)&client_addr, &addr_len);

        if (recv_len > 0) {
            printf("\nReceived %d bytes from %s:%d\n",
                   recv_len,
                   inet_ntoa(client_addr.sin_addr),
                   ntohs(client_addr.sin_port));

            // printf("Hex data: ");
            // for (int i = 0; i < recv_len; i++) {
            //     printf("%02X ", recv_buffer[i]);
            //     if ((i + 1) % 16 == 0)
            //         printf("\n         ");
            // }
            // printf("\n");
            printf("%s\n", recv_buffer);
        } else {
            printf("No data received\n");
        }
    }
#else
    int sock = -1;
    struct sockaddr_in server_addr;
    uint8_t send_buffer[10] = { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA };

    sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock < 0) {
        printf("Socket creation failed\n");
        return;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = PF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    /* main loop */
    while (1) {
        sendto(sock, send_buffer, sizeof(send_buffer), 0, (struct sockaddr*)&server_addr, sizeof(struct sockaddr_in));
        printf("Sent %d bytes to server\n", sizeof(send_buffer));

        sys_msleep(1000);
    }
#endif
}

TASK_EXPORT __fmt_task_desc = {
    .name = "eth",
    .init = task_init,
    .entry = task_entry,
    .priority = 25,
    .auto_start = false,
    .stack_size = 4096,
    .param = NULL,
    .dependency = NULL
};
