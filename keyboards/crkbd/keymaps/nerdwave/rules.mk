RGBLIGHT_ENABLE = no # see if this works
RGB_MATRIX_ENABLE = yes # for backlight and underglow
OLED_ENABLE = yes # for OLED screen
WPM_ENABLE = yes
LTO_ENABLE = yes

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += rgb.c
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC+= oled.c
endif

ENCODER_MAP_ENABLE = yes
RGB_MATRIX_CUSTOM_USER = yes
OS_DETECTION_ENABLE = yes
# VIA_ENABLE=yes
