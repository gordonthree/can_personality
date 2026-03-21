#pragma once

/** 
 * @file esp32_defs.h
 * @brief ESP32 hardware definitions for personality table
 */

/* only load for esp32 hardware */
#ifdef ESP32

/** CYD Cheap Yellow Display pin assignments */
#define CYD_BACKLIGHT_PIN      (21)
#define CYD_LED_RED_PIN        ( 4)
#define CYD_LED_BLUE_PIN       (17)
#define CYD_LED_GREEN_PIN      (16)
#define CYD_LDR_PIN            (34)
#define CYD_SPEAKER_PIN        (26)

/** M5Stamp PICO pin assignments and constants */
#define M5STAMP_BUTTON_COUNT   ( 1)
#define M5STAMP_ARGB_COUNT     ( 1)

#define M5STAMP_ARGB_PIN_27    (27)
#define M5STAMP_BUTTON_PIN_39  (39)
#define M5STAMP_CS_PIN_19      (19)
#define M5STAMP_SCK_PIN_18     (18)
#define M5STAMP_DAC1_PIN_25    (25)
#define M5STAMP_DAC2_PIN_26    (26)
#define M5STAMP_ADC_PIN_36     (36)

typedef enum {
    ESP32_PWM_CHANNEL_0 = 0,
    ESP32_PWM_CHANNEL_1,
    ESP32_PWM_CHANNEL_2,
    ESP32_PWM_CHANNEL_3,
    ESP32_PWM_CHANNEL_4,
    ESP32_PWM_CHANNEL_5,
    ESP32_PWM_CHANNEL_6,
    ESP32_PWM_CHANNEL_7
} esp32_pwm_channel_t;

typedef enum {
    ESP32_PWM_TIMER_0 = 0,
    ESP32_PWM_TIMER_1,
    ESP32_PWM_TIMER_2,
    ESP32_PWM_TIMER_3,
} esp32_pwm_timer_t;

#endif /* ESP32 */