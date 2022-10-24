#ifndef __NOSYS_H
#define __NOSYS_H

#ifdef __cplusplus
extern "C"
{
#endif


//void *sbrk(ptrdiff_t increment);
void * _sbrk(int incr);

void cpp_run_init_array(void);

void cpp_run_fini_array(void);

#ifdef __cplusplus
}
#endif 


#endif
