#ifndef DEEPCRAFT_AI_FMT_H__
#define DEEPCRAFT_AI_FMT_H__

#include <firmament.h>

#ifdef __cplusplus
extern "C" {
#endif

fmt_err_t deepcraft_ai_task_init(void);
void deepcraft_ai_task_entry(void* parameter);

#ifdef __cplusplus
}
#endif

#endif /* DEEPCRAFT_AI_FMT_H__ */
