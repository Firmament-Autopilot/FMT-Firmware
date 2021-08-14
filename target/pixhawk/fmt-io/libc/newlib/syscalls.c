#include <reent.h>
#include <sys/errno.h>
#include <sys/time.h>

/* Reentrant versions of system calls.  */

int
_close_r(struct _reent* ptr, int fd)
{
	return 0;
}

int
_execve_r(struct _reent* ptr, const char* name, char* const* argv, char* const* env)
{
	/* return "not supported" */
	ptr->_errno = ENOTSUP;
	return -1;
}

int
_fcntl_r(struct _reent* ptr, int fd, int cmd, int arg)
{
	/* return "not supported" */
	ptr->_errno = ENOTSUP;
	return -1;
}

int
_fork_r(struct _reent* ptr)
{
	/* return "not supported" */
	ptr->_errno = ENOTSUP;
	return -1;
}

int
_fstat_r(struct _reent* ptr, int fd, struct stat* pstat)
{
	/* return "not supported" */
	ptr->_errno = ENOTSUP;
	return -1;
}

int
_getpid_r(struct _reent* ptr)
{
	return 0;
}

int
_isatty_r(struct _reent* ptr, int fd)
{
	if(fd >= 0 && fd < 3) return 1;

	/* return "not supported" */
	ptr->_errno = ENOTSUP;
	return -1;
}

int
_kill_r(struct _reent* ptr, int pid, int sig)
{
	/* return "not supported" */
	ptr->_errno = ENOTSUP;
	return -1;
}

int
_link_r(struct _reent* ptr, const char* old, const char* new)
{
	/* return "not supported" */
	ptr->_errno = ENOTSUP;
	return -1;
}

_off_t
_lseek_r(struct _reent* ptr, int fd, _off_t pos, int whence)
{
	return 0;
}

int
_mkdir_r(struct _reent* ptr, const char* name, int mode)
{
	return 0;
}

int
_open_r(struct _reent* ptr, const char* file, int flags, int mode)
{
	return 0;
}

_ssize_t
_read_r(struct _reent* ptr, int fd, void* buf, size_t nbytes)
{
	return 0;
}

int
_rename_r(struct _reent* ptr, const char* old, const char* new)
{
	return 0;
}

extern unsigned long _end[];
void*
_sbrk_r(struct _reent* ptr, ptrdiff_t incr)
{
	static unsigned char* heap = NULL;
	unsigned char* prev_heap;

	if(heap == NULL) {
		heap = (unsigned char*)_end;
	}

	prev_heap = heap;
	heap += incr;
	return (void*)prev_heap;
}

int
_stat_r(struct _reent* ptr, const char* file, struct stat* pstat)
{
	return 0;
}

_CLOCK_T_
_times_r(struct _reent* ptr, struct tms* ptms)
{
	/* return "not supported" */
	ptr->_errno = ENOTSUP;
	return -1;
}

int
_unlink_r(struct _reent* ptr, const char* file)
{
	return 0;
}

int
_wait_r(struct _reent* ptr, int* status)
{
	/* return "not supported" */
	ptr->_errno = ENOTSUP;
	return -1;
}

extern void console_putc(uint8_t ch);

_ssize_t
_write_r(struct _reent* ptr, int fd, const void* buf, size_t nbytes)
{
	size_t i = 0;
	uint8_t* ch = (uint8_t*)buf;

	if(fd < 3) {
		while(nbytes--) {
			if(ch[i] == '\n') {
				console_putc('\r');
			}

			console_putc(ch[i++]);
		}
	}

	return nbytes;
}


void
_exit(int status)
{
	while (1);
}

void
_system(const char* s)
{
	/* not support this call */
}

void __libc_init_array(void)
{
	/* we not use __libc init_aray to initialize C++ objects */
}

