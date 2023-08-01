#ifndef NLINK_TYPEDEF_H
#define NLINK_TYPEDEF_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  LINKTRACK_ROLE_NODE,
  LINKTRACK_ROLE_ANCHOR,
  LINKTRACK_ROLE_TAG,
  LINKTRACK_ROLE_CONSOLE,
  LINKTRACK_ROLE_DT_MASTER,
  LINKTRACK_ROLE_DT_SLAVE,
  LINKTRACK_ROLE_MONITOR,
} linktrack_role_e;

typedef uint32_t id_t;

#define MAX_ANCHOR_COUNT 16
#define MAX_TAG_COUNT 16

#ifdef __cplusplus
}
#endif
#endif // NLINK_TYPEDEF_H
