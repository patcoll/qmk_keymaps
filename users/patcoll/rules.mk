SRC += patcoll.c

BOOTMAGIC_ENABLE      = yes
COMBO_ENABLE          = yes
CONSOLE_ENABLE        = no
EXTRAKEY_ENABLE       = yes
MOUSEKEY_ENABLE       = yes
NKRO_ENABLE           = no
TAP_DANCE_ENABLE      = no
AUTO_SHIFT_ENABLE     = yes

# Allow loading of `combos.def`
VPATH += keyboards/gboards/

ifneq ($(PLATFORM),CHIBIOS)
	LTO_ENABLE        = yes
endif

SPACE_CADET_ENABLE    = no
GRAVE_ESC_ENABLE      = no
