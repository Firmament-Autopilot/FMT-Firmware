
/* RT-Thread config file */
#ifndef __RTTHREAD_CFG_H__
#define __RTTHREAD_CFG_H__

/* FMT config file */
#include <fmtconfig.h>

/* RT_NAME_MAX*/
#define RT_NAME_MAX	   20	//change log: change from 8 to 20

/* RT_ALIGN_SIZE*/
#define RT_ALIGN_SIZE	4

/* PRIORITY_MAX */
#define RT_THREAD_PRIORITY_MAX	32

/* Tick per Second */
#define RT_TICK_PER_SECOND	1000	//change from 100 to 1000, in order to get ms time unit

/* SECTION: RT_DEBUG */
/* Thread Debug */
#define RT_DEBUG
#define RT_USING_OVERFLOW_CHECK

/* Using Hook */
#define RT_USING_HOOK

#define IDLE_THREAD_STACK_SIZE     1024

/* Using Software Timer */
#define RT_USING_TIMER_SOFT
#define RT_TIMER_THREAD_PRIO		5
#define RT_TIMER_THREAD_STACK_SIZE	1024

/* SECTION: IPC */
/* Using Semaphore*/
#define RT_USING_SEMAPHORE

/* Using Mutex */
#define RT_USING_MUTEX

/* Using Event */
#define RT_USING_EVENT

/* Using MailBox */
#define RT_USING_MAILBOX

/* Using Message Queue */
#define RT_USING_MESSAGEQUEUE

/* SECTION: Memory Management */
/* Using Memory Pool Management*/
#define RT_USING_MEMPOOL

/* Using Dynamic Heap Management */
#define RT_USING_HEAP

/* Using Small MM */
#define RT_USING_SMALL_MEM

/* SECTION: Device System */
/* Using Device System */
#define RT_USING_DEVICE
#define RT_USING_DEVICE_IPC

/* SECTION: Console options */
#define RT_USING_CONSOLE
/* the buffer size of console*/
#define RT_CONSOLEBUF_SIZE	256

/* SECTION: finsh, a C-Express shell */
#define RT_USING_FINSH
/* Using symbol table */
#define FINSH_USING_SYMTAB
#define FINSH_USING_DESCRIPTION
/* Using msh style shell */
#define FINSH_USING_MSH
#define FINSH_USING_MSH_ONLY
#define DFS_USING_WORKDIR
#define FINSH_THREAD_STACK_SIZE 4096
/* Enable finsh history */
#define FINSH_USING_HISTORY
/* Finsh maximal arguments number */
#define FINSH_ARG_MAX   20

/* SECTION: device filesystem */
/* Using Device file system */
#define RT_USING_DFS
/* the max number of mounted filesystem */
#define DFS_FILESYSTEMS_MAX			4
/* the max number of opened files 		*/
#define DFS_FD_MAX					20

/* Using ELM FATFS */
#define RT_USING_DFS_ELMFAT
#define RT_DFS_ELM_WORD_ACCESS
/* Reentrancy (thread safe) of the FatFs module.  */
#define RT_DFS_ELM_REENTRANT
/* Number of volumes (logical drives) to be used. */
#define RT_DFS_ELM_DRIVES			2
#define RT_DFS_ELM_USE_LFN			3
#define RT_DFS_ELM_MAX_LFN			255
/* Maximum sector size to be handled. */
#define RT_DFS_ELM_MAX_SECTOR_SIZE  4096

/* Using ROM file system */
#define RT_USING_DFS_ROMFS

/* SDIO */
#define RT_USING_SDIO
#define RT_SDIO_STACK_SIZE 512
#define RT_SDIO_THREAD_PRIORITY 15
#define RT_MMCSD_STACK_SIZE 1024
#define RT_MMCSD_THREAD_PREORITY 22
#define RT_MMCSD_MAX_PARTITION 16

/* C standard library */
#define RT_USING_LIBC
// #define RT_USING_PTHREADS
// #define PTHREAD_NUM_MAX 8
// #define RT_USING_POSIX
// #define RT_USING_POSIX_MMAP
// #define RT_USING_POSIX_TERMIOS
// #define RT_USING_POSIX_AIO

/* samples: kernel and components samples */

/* SOC Define */
#define SOC_VEXPRESS_A9

/* USING C++ */
#define RT_USING_CPLUSPLUS

#define RT_SYSTEM_WORKQUEUE_STACKSIZE 2048

#endif
