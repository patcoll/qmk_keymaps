/*
 * `qmk chibios-confmigrate -i firmware/nachie/syndrome/chconf.h -r ../keymaps_qmk/platforms/chibios/boards/GENERIC_PROMICRO_RP2040/configs/chconf.h`
 */


#pragma once

#include_next <chconf.h>

#undef CH_CFG_SMP_MODE
#define CH_CFG_SMP_MODE                     TRUE

#undef CH_CFG_ST_RESOLUTION
#define CH_CFG_ST_RESOLUTION                32

#undef CH_CFG_ST_FREQUENCY
#define CH_CFG_ST_FREQUENCY                 1000000

#undef CH_CFG_INTERVALS_SIZE
#define CH_CFG_INTERVALS_SIZE               32

#undef CH_CFG_TIME_TYPES_SIZE
#define CH_CFG_TIME_TYPES_SIZE              32

#undef CH_CFG_ST_TIMEDELTA
#define CH_CFG_ST_TIMEDELTA                 100

