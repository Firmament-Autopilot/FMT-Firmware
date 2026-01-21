#include <firmament.h>

#include "dfs_romfs.h"

static const char init_sh_data[] = "\
version\
";

static const struct romfs_dirent romfs_data[] = {
    { ROMFS_DIRENT_FILE, "init.sh", (rt_uint8_t*)init_sh_data, sizeof(init_sh_data) / sizeof(init_sh_data[0]) },
};

const struct romfs_dirent romfs_root = {
    ROMFS_DIRENT_DIR, "/", (rt_uint8_t*)romfs_data, sizeof(romfs_data) / sizeof(romfs_data[0])
};
