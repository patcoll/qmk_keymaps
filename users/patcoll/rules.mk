SRC += patcoll.c

BOOTMAGIC_ENABLE      = no
COMBO_ENABLE          = yes
EXTRAKEY_ENABLE       = yes
MOUSEKEY_ENABLE       = yes
NKRO_ENABLE           = no
TAP_DANCE_ENABLE      = no
CONSOLE_ENABLE = no

VPATH += keyboards/gboards/

ifneq ($(PLATFORM),CHIBIOS)
    LTO_ENABLE        = yes
endif

SPACE_CADET_ENABLE    = no
GRAVE_ESC_ENABLE      = no

ifeq ($(strip $(QUICK_SWITCH)), yes)
    OPT_DEFS += -DQUICK_SWITCH
endif
