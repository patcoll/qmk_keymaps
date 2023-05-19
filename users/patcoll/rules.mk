SRC += patcoll.c

# AUDIO_ENABLE          = no
# AUTO_SHIFT_ENABLE     = no
# AUTOCORRECT_ENABLE    = no
# BACKLIGHT_ENABLE      = no
# BLUETOOTH_ENABLE      = no
BOOTMAGIC_ENABLE      = yes
# CAPS_WORD_ENABLE      = no
COMBO_ENABLE          = yes
# COMMAND_ENABLE        = no
# CONSOLE_ENABLE        = no
# DIGITIZER_ENABLE      = no
# DIP_SWITCH_ENABLE     = no
# ENCODER_ENABLE        = no
# DEFERRED_EXEC_ENABLE  = no
# DYNAMIC_MACRO_ENABLE  = no
# DYNAMIC_TAPPING_TERM_ENABLE = no
EXTRAKEY_ENABLE       = yes
# GRAVE_ESC_ENABLE      = no
# HAPTIC_ENABLE         = no
# HD44780_ENABLE        = no
# JOYSTICK_ENABLE       = no
# KEY_LOCK_ENABLE       = no
# KEY_OVERRIDE_ENABLE   = no
# LEADER_ENABLE         = no
# LED_MATRIX_ENABLE     = no
# MIDI_ENABLE           = no
MOUSEKEY_ENABLE       = yes
NKRO_ENABLE           = yes
# OLED_ENABLE           = no
# POINTING_DEVICE_ENABLE = no
# PROGRAMMABLE_BUTTON_ENABLE = no
# PS2_MOUSE_ENABLE      = no
# PS2_ENABLE            = no
# RAW_ENABLE            = no
# RGB_MATRIX_ENABLE     = no
# RGBLIGHT_ENABLE       = no
# SECURE_ENABLE         = no
# SEND_STRING_ENABLE    = yes
# SEQUENCER_ENABLE      = no
# SPACE_CADET_ENABLE    = no
# SPLIT_KEYBOARD        = no
# ST7565_ENABLE         = no
# STENO_ENABLE          = no
# SWAP_HANDS_ENABLE     = no
# TAP_DANCE_ENABLE      = no
# TRI_LAYER_ENABLE      = no
# UNICODE_ENABLE        = no
# USBPD_ENABLE          = no
# VELOCIKEY_ENABLE      = no
# VIA_ENABLE            = no
# WPM_ENABLE            = no

# Allow loading of `combos.def`
VPATH += keyboards/gboards/

ifneq ($(PLATFORM),CHIBIOS)
	LTO_ENABLE        = yes
endif

