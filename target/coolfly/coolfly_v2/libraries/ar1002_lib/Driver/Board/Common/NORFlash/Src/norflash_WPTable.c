#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "data_type.h"
#include "nor_flash.h"

#define INFO(_jedec_id, _sector_size, _n_sectors, _flags, _pro_start, _pro_end, _s1, _s2, _s1_wp, _s2_wp)    \
        .id = {                                    \
            ((_jedec_id) >> 16) & 0xff,            \
            ((_jedec_id) >> 8) & 0xff,             \
            (_jedec_id) & 0xff,                    \
            },                                     \
        .id_len = (!(_jedec_id) ? 0 : 3),          \
        .sector_size = (_sector_size),             \
        .n_sectors = (_n_sectors),                 \
        .protect_start = (_pro_start),             \
        .protect_end = (_pro_end),                 \
        .page_size = 256,                          \
        .s1_map = _s1,                             \
        .s2_map = _s2,                             \
        .s1_wp_map = _s1_wp,                       \
        .s2_wp_map = _s2_wp,                       \
        .flags = (_flags),

const struct spi_flash_info spi_flash_ids[] = {
#ifdef CONFIG_SPI_FLASH_ATMEL        /* ATMEL */

#endif
#ifdef CONFIG_SPI_FLASH_EON          /* EON */

#endif
#ifdef CONFIG_SPI_FLASH_GIGADEVICE   /* GIGADEVICE */
    {"gd25q127c",       INFO(0xc84018,   64 * 1024,   256, RD_FULL | WR_QPP | SECT_4K, 0, 0xFFFFFF, BP2 | BP1 | BP0, 0, BP2 | BP1 | BP0, CMP) },
    {"gd25q32c",        INFO(0xc84016,   64 * 1024,    64, RD_FULL | WR_QPP | SECT_4K, 0, 0x3FFFFF, BP2 | BP1 | BP0, 0, BP2 | BP1 | BP0, CMP) },

#endif

#ifdef CONFIG_SPI_FLASH_XD
    {"xd25q32e",        INFO(0xd84016,   64 * 1024,    64, RD_FULL | WR_QPP | SECT_4K, 0, 0x3FFFFF, BP2 | BP1 | BP0, 0, BP2 | BP1 | BP0, CMP) },
    {"xd25q64e",        INFO(0xd84017,   64 * 1024,   128, RD_FULL | WR_QPP | SECT_4K, 0, 0x7FFFFF, BP2 | BP1 | BP0, 0, BP2 | BP1 | BP0, CMP) },
#endif

#ifdef CONFIG_SPI_FLASH_ISSI         /* ISSI */

#endif
#ifdef CONFIG_SPI_FLASH_MACRONIX     /* MACRONIX */
    {"mx25l3205d",      INFO(0xc22016,   64 * 1024,    64, RD_FULL | WR_QPP | SECT_4K, 0, 0x3FFFFF, BP3 | BP1 | BP0,    0, SRWD | BP3 | BP2 | BP1 | BP0,    0) },
    {"mx25l12835f",     INFO(0xc22018,   64 * 1024,   256, RD_FULL | WR_QPP | SECT_4K, 0, 0xFFFFFF,       BP2 | BP1, TB_2, SRWD | BP3 | BP2 | BP1 | BP0, TB_2) },
#endif
#ifdef CONFIG_SPI_FLASH_SPANSION     /* SPANSION */

#endif
#ifdef CONFIG_SPI_FLASH_STMICRO      /* STMICRO */

#endif
#ifdef CONFIG_SPI_FLASH_SST          /* SST */

#endif
#ifdef CONFIG_SPI_FLASH_WINBOND      /* WINBOND */
    {"w25q32bv",        INFO(0xef4016,   64 * 1024,    64, RD_FULL | WR_QPP | SECT_4K, 0, 0x3FFFFF, BP2,           CMP, SRP0 | BP0 | BP1 | BP2 | TB | SEC, CMP) },
    {"w25q32jv",        INFO(0xef7016,   64 * 1024,    64, RD_FULL | WR_QPP | SECT_4K, 0, 0x3FFFFF, BP2,           CMP, SRP0 | BP0 | BP1 | BP2 | TB | SEC, CMP) },
    {"p25q32h",         INFO(0x856016,   64 * 1024,    64, RD_FULL | WR_QPP | SECT_4K, 0, 0x3FFFFF, BP2,           CMP, SRP0 | BP0 | BP1 | BP2 | TB | SEC, CMP) },
    {"w25q128bv",       INFO(0xef4018,   64 * 1024,   256, RD_FULL | WR_QPP | SECT_4K, 0, 0xFFFFFF, TB | BP2 | BP0,  0, SRP0 | BP0 | BP1 | BP2 | TB | SEC, CMP) },
    {"w25q128jv",       INFO(0xef7018,   64 * 1024,   256, RD_FULL | WR_QPP | SECT_4K, 0, 0xFFFFFF, TB | BP2 | BP0,  0, SRP0 | BP0 | BP1 | BP2 | TB | SEC, CMP) },
#endif
    {},    /* Empty entry to terminate the list */
};
