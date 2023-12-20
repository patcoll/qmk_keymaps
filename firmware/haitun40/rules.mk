MCU = STM32F401
BOARD = GENERIC_STM32_F401XC


# BOOTLOADER = custom
# FIRMWARE_FORMAT = uf2
# UF2_FAMILY = 0xabcdf401
# MCU_LDSCRIPT=PlumBL_STM32F401

BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
ENCODER_ENABLE = no
UARTENABLE = no
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = yes        # Console for debug
NKRO_ENABLE = no          # Enable N-Key Rollover
RGBLIGHT_ENABLE = no    # Enable keyboard RGB underglow
WS2812_DRIVER = pwm
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812
ifeq ($(strip $(UARTENABLE)), yes)
  SRC += outputselect.c
  SRC += uartfly.c
	SRC += powermstop.c
	SRC += actionuart.c
	SRC += keymapcallback.c

  SRC += analog_qf.c
endif
# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
OPT_DEFS += -DQMK_MCU_STM32F401
OPT_DEFS += -DBOOTLOADER_TINYUF2

EEPROM_DRIVER = wear_leveling
WEAR_LEVELING_DRIVER = legacy

