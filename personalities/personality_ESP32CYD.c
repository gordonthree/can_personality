/** @file personality.c */

#include "personality_table.h"

/** IMPORTANT: Not every personality will need this, some might need an stm32_defs.h */
#include "esp32_defs.h"  

/** Set the node type message */
#define NODE_TYPE_MSG IFACE_TOUCHSCREEN_TYPE_A_ID
#define NODE_TYPE_DLC IFACE_TOUCHSCREEN_TYPE_A_DLC

/** Define the personality table first */
const personalityDef_t personalityTable[] = {

    /* ----------------------------------------------------------------------
     * Submodule 0 — 0x70B DISP_TOUCHSCREEN_LCD
     * ---------------------------------------------------------------------- */
    {  
        .personalityId = SYS_TOUCH_LCD,               /**< No user config available */
        .capabilities  = CAP_NONE,                    /**< ARGB LED strip */

        /* Hardware mapping */
        .gpioPin       = NO_GPIO_ASSIGNED,            /**< Not relevant */  
        .pwmChannel    = NO_PWM_ASSIGNED,             /**< Not relevant */
        .pwmTimer      = NO_PWM_ASSIGNED,             /**< Not relevant*/
        .isSinkDriver  = false,                       /**< Not relevant */

        /* Data reporting / control */ 
        .dataMsgId     = NO_DATA_REPORTING,                        /**< No data reporting */
        .dataMsgDlc    = NO_DATA_REPORTING,                        /**< No data reporting */

        /* Submodule builder flags */
        .flags         = BUILDER_FLAG_AUTO_CONFIGURE | BUILDER_FLAG_DEVICE_READONLY

    },

    /* ----------------------------------------------------------------------
     * Submodule 1 — Backlight, GPIO OUTPUT
     * ---------------------------------------------------------------------- */
    {
        .personalityId = PERS_GPIO_OUTPUT,
        .capabilities  = CAP_OUTPUT | CAP_PWM,        /**< Digital out, supports pwm */

        /* Hardware mapping */
        .gpioPin       = CYD_BACKLIGHT_PIN,           
        .pwmChannel    = ESP32_PWM_CHANNEL_0,              
        .pwmTimer      = ESP32_PWM_TIMER_0,                
        .isSinkDriver  = false,                       

        /* Data reporting */
        .dataMsgId     = SET_DISPLAY_BACKLIGHT_BRIGHTNESS_ID, 
        .dataMsgDlc    = SET_DISPLAY_BACKLIGHT_BRIGHTNESS_DLC,
        
        /* Submodule builder flags */
        .flags         = BUILDER_FLAG_AUTO_CONFIGURE         
    },
        /* ----------------------------------------------------------------------
     * Submodule 2— RED LED, GPIO OUTPUT
     * ---------------------------------------------------------------------- */
    {
        .personalityId = PERS_GPIO_OUTPUT,
        .capabilities  = CAP_OUTPUT | CAP_PWM,       /**< Digital out, supports pwm */

        /* Hardware mapping */
        .gpioPin       = CYD_LED_RED_PIN,           
        .pwmChannel    = ESP32_PWM_CHANNEL_1,              
        .pwmTimer      = ESP32_PWM_TIMER_1,                
        .isSinkDriver  = true,                       /**< CYD leds are use inverted logic, 0 = on, 1 = off */

        /* Data reporting */
        .dataMsgId     = SET_LED_STRIP_BRIGHTNESS_ID, 
        .dataMsgDlc    = SET_LED_STRIP_BRIGHTNESS_DLC,

        /* Submodule builder flags */
        .flags         = BUILDER_FLAG_AUTO_CONFIGURE 
    },
    /* ----------------------------------------------------------------------
     * Submodule 3— GREEN LED, GPIO OUTPUT
     * ---------------------------------------------------------------------- */
    {
        .personalityId = PERS_GPIO_OUTPUT,
        .capabilities  = CAP_OUTPUT | CAP_PWM,        /**< Digital out, supports pwm */

        /* Hardware mapping */
        .gpioPin       = CYD_LED_GREEN_PIN,           
        .pwmChannel    = ESP32_PWM_CHANNEL_2,              
        .pwmTimer      = ESP32_PWM_TIMER_2,                
        .isSinkDriver  = true,                       

        /* Data reporting */
        .dataMsgId     = SET_LED_STRIP_BRIGHTNESS_ID, 
        .dataMsgDlc    = SET_LED_STRIP_BRIGHTNESS_DLC,

        /* Submodule builder flags */
        .flags         = BUILDER_FLAG_AUTO_CONFIGURE 
    },
    /* ----------------------------------------------------------------------
     * Submodule 4— BLUE LED, GPIO OUTPUT
     * ---------------------------------------------------------------------- */
    {
        .personalityId = PERS_GPIO_OUTPUT,
        .capabilities  = CAP_OUTPUT | CAP_PWM,        /**< Digital out, supports pwm */

        /* Hardware mapping */
        .gpioPin       = CYD_LED_BLUE_PIN,           
        .pwmChannel    = ESP32_PWM_CHANNEL_3,              
        .pwmTimer      = ESP32_PWM_TIMER_3,                
        .isSinkDriver  = true,                       

        /* Data reporting */
        .dataMsgId     = SET_LED_STRIP_BRIGHTNESS_ID, 
        .dataMsgDlc    = SET_LED_STRIP_BRIGHTNESS_DLC,

        /* Submodule builder flags */
        .flags         = BUILDER_FLAG_AUTO_CONFIGURE 
    },
    /* ----------------------------------------------------------------------
     * Submodule 5— Light dependent resistor, ANALOG INPUT
     * ---------------------------------------------------------------------- */
    {
        .personalityId = PERS_ANALOG_INPUT,
        .capabilities  = CAP_ANALOG | CAP_INPUT,        

        /* Hardware mapping */
        .gpioPin       = CYD_LDR_PIN,           
        .pwmChannel    = NO_PWM_ASSIGNED,              
        .pwmTimer      = NO_PWM_ASSIGNED,                
        .isSinkDriver  = false,                       

        /* Data reporting */
        .dataMsgId     = DATA_ADC_RAW_ID, 
        .dataMsgDlc    = DATA_ADC_RAW_DLC,

        /* Submodule builder flags */
        .flags         = BUILDER_FLAG_AUTO_CONFIGURE 
    },

    /* ----------------------------------------------------------------------
     * Submodule 6- Speaker Analog Output
     * ---------------------------------------------------------------------- */
    {
        .personalityId = PERS_ANA_OUTPUT,
        .capabilities  = CAP_ANALOG | CAP_OUTPUT,     

        /* Hardware mapping */
        .gpioPin       = CYD_SPEAKER_PIN,           
        .pwmChannel    = NO_PWM_ASSIGNED,              
        .pwmTimer      = NO_PWM_ASSIGNED,                
        .isSinkDriver  = false,

        /* Data reporting */
        .dataMsgId     = DATA_ADC_RAW_ID, 
        .dataMsgDlc    = DATA_ADC_RAW_DLC,

        /* Submodule builder flags */
        .flags         = BUILDER_FLAG_AUTO_CONFIGURE
    }
};

/** Connect the pointer to the table second */
const personalityDef_t *g_personalityTable = personalityTable;

/** Count number of personalities last */
uint8_t g_personalityCount =
    sizeof(personalityTable) / sizeof(personalityTable[0]);
