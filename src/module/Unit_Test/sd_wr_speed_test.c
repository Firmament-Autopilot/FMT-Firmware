
#include <firmament.h>
#include "module/shell_cmd/syscmd.h"
#include "module/console/console.h"
#include "module/file_manager/file_manager.h"

#define TEST_FILE_NAME      "/test_file.txt"

void sd_write_speed_test(void)
{
	uint8_t block_size[] = {4, 6, 8, 10, 12, 14, 16};
	uint32_t file_size = 10 * 1024 * 1024;
	char* buff_ptr = NULL;
	int fd = -1;

	console_printf("start sd write speed test.\n");

	uint8_t priority = 1;
	uint8_t cur_priority;
	rt_thread_t self = rt_thread_self();
	cur_priority = self->current_priority;

	// change current thread to highest priority
	rt_thread_control(self, RT_THREAD_CTRL_CHANGE_PRIORITY, &priority);

	for(uint8_t i = 0; i < sizeof(block_size); i++) {
		uint32_t total_time_ms, min_time_ms, max_time_ms, start_time_ms, end_time_ms;
		float avg_time_ms;
		uint32_t bsize = block_size[i] * 1024;

		console_printf("block size:%d KB, write size: %d KB\n", block_size[i], file_size / 1024);

		fd = open(TEST_FILE_NAME, O_WRONLY | O_CREAT, 0);

		if(fd < 0) {
			console_printf("fail to open file:%s\n", TEST_FILE_NAME);
			goto End;
		}

		// prepare write data
		buff_ptr = (char*)rt_malloc(bsize);

		if(buff_ptr == NULL) {
			console_printf("fail to malloc\n");
			goto End;
		}

		memset(buff_ptr, 0x55, bsize);

		// start test
		total_time_ms = max_time_ms = 0;
		min_time_ms = 0xFFFFFFFF;

		int wb = 0;

		while(wb < file_size) {

			start_time_ms = systime_now_ms();
			int b = write(fd, buff_ptr, bsize);

			if(b != bsize) {
				console_printf("write fail,%d %d\n", b, bsize);
				return;
			}

			wb += b;
			fsync(fd);
			end_time_ms = systime_now_ms();

			uint32_t time = end_time_ms - start_time_ms;
			total_time_ms += time;

			if(time < min_time_ms) {
				min_time_ms = time;
			}

			if(time > max_time_ms) {
				max_time_ms = time;
			}
		}

		avg_time_ms = (float)total_time_ms / (file_size / bsize);

		close(fd);
		unlink(TEST_FILE_NAME);

		if(buff_ptr) rt_free(buff_ptr);

		console_printf("  total time: %d ms\n", total_time_ms);
		console_printf("average time: %.2f ms\n", avg_time_ms);
		console_printf("    min time: %d ms\n", min_time_ms);
		console_printf("    max time: %d ms\n", max_time_ms);
		console_printf(" write speed: %d KB/s\n\n", file_size / total_time_ms);
	}

End:

	if(fd) close(fd);

	// if(buff_ptr) rt_free(buff_ptr);

	rt_thread_control(self, RT_THREAD_CTRL_CHANGE_PRIORITY, &cur_priority);
}