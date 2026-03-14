#include "submodule_types.h"
#include "personality_table.h"

extern const subModule_t submod_setup[];
/** Pointer to the array of submodules configuration */
const subModule_t *g_submodules_ptr = submod_setup; 

/** Array containing default subModules configuration */
const subModule_t submod_setup[] = {
    {
        /* Submodule 0 - LCD TOUCHSCREEN */
        .personalityId = SYS_TOUCH_LCD,
        .config = {
            .rawConfig={0}, /* No configuration for this submodule */
        },
        .introMsgId   = DISP_TOUCHSCREEN_LCD_ID,
        .introMsgDLC  = DISP_TOUCHSCREEN_LCD_DLC,
        .submod_flags = SUBMOD_FLAG_DISPLAY | 
                        SUBMOD_FLAG_OUTPUT |
                        SUBMOD_FLAG_READ_ONLY,
        .runTime = {0},
    },
    {
        /* Submodule 1 - GPIO OUTPUT, Backlight */
        .personalityId = PERS_GPIO_OUTPUT,
        .config = {
            .gpioOutput = {
                .mode = OUT_MODE_PWM,
                .param1 = 100, /* 1khz PWM frequency in 10Hz increments */
                .param2 = LEDC_13BIT_100PCT, /* 100% duty cycle */
            },
        },
        .introMsgId = DISP_ANALOG_BACKLIGHT_ID,
        .introMsgDLC = DISP_ANALOG_BACKLIGHT_DLC,
        .submod_flags = SUBMOD_FLAG_DISPLAY |
                        SUBMOD_FLAG_OUTPUT,
        .runTime = {0}
    },
    {
        /* Submodule 2 - GPIO OUTPUT, RED LED */
        .personalityId = PERS_GPIO_OUTPUT,
        .config = {
            .gpioOutput = {
                .mode = OUT_MODE_PWM,
                .param1 = 100, /* 1khz PWM frequency in 10Hz increments */
                .param2 = LEDC_13BIT_0PCT, /* 0% duty cycle */
            },
        },
        .introMsgId = DISP_ANALOG_LED_STRIP_ID,
        .introMsgDLC = DISP_ANALOG_LED_STRIP_DLC,
        .submod_flags = SUBMOD_FLAG_DISPLAY |
                        SUBMOD_FLAG_OUTPUT,
        .runTime = {0}
    },
    {
        /* Submodule 3 - GPIO OUTPUT, GREEN LED */
        .personalityId = PERS_GPIO_OUTPUT,
        .config = {
            .gpioOutput = {
                .mode = OUT_MODE_PWM,
                .param1 = 100, /* 1khz PWM frequency in 10Hz increments */
                .param2 = LEDC_13BIT_0PCT, /* 0% duty cycle */
            },
        },
        .introMsgId = DISP_ANALOG_LED_STRIP_ID,
        .introMsgDLC = DISP_ANALOG_LED_STRIP_DLC,
        .submod_flags = SUBMOD_FLAG_DISPLAY |
                        SUBMOD_FLAG_OUTPUT,
        .runTime = {0}
        },
        {
        /* Submodule 4 - GPIO OUTPUT, BLUE LED */
        .personalityId = PERS_GPIO_OUTPUT,
        .config = {
            .gpioOutput = {
                .mode = OUT_MODE_PWM,
                .param1 = 100, /* 1khz PWM frequency in 10Hz increments */
                .param2 = LEDC_13BIT_0PCT, /* 0% duty cycle */
            },
        },
        .introMsgId = DISP_ANALOG_LED_STRIP_ID,
        .introMsgDLC = DISP_ANALOG_LED_STRIP_DLC,
        .submod_flags = SUBMOD_FLAG_DISPLAY |
                        SUBMOD_FLAG_OUTPUT,
        .runTime = {0}
        },
    {
        /* Submodule 5 - Light dependent resistor, ANALOG INPUT */
        .personalityId = PERS_ANALOG_INPUT,
        .config = {
            .analogInput = {
                .overSampleFlag = OVERSAMPLE_ESP32_MEDIUM, /* Medium oversampling */
                .reserved1 = 0, /* Padding - reserved */
                .reserved2 = 0  /* Padding - reserved */
            },
        },
        .introMsgId = DATA_ADC_RAW_ID,
        .introMsgDLC = DATA_ADC_RAW_DLC,
        .submod_flags = SUBMOD_FLAG_INPUT,
        .runTime = {0}
    }, {
        /* Submodule 6 - Analog speaker output */
        .personalityId = PERS_ANA_OUTPUT,
        .config = {
            .analogOutput = {
                .outputMode = DAC_MODE_CONTINUOUS, 
                .param1 = 0, /* TODO DAC stuff */
                .param2 = 0  /* TODO DAC stuff */
            },
        },
        .introMsgId = DATA_ADC_RAW_ID,
        .introMsgDLC = DATA_ADC_RAW_DLC,
        .submod_flags = SUBMOD_FLAG_OUTPUT,
        .runTime = {0}
    }
    // Add more submodule configurations as needed
};

/** Number of submodules */
uint8_t g_submodules_count = 
    sizeof(submod_setup) / sizeof(subModule_t);