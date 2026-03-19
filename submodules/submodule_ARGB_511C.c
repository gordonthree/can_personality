#include "submodule_types.h"
#include "personality_table.h"

extern const subModule_t submod_setup[];
/** Pointer to the array of submodules configuration */
const subModule_t *g_submodules_ptr = submod_setup; 

/** Array containing default subModules configuration */
const subModule_t submod_setup[] = {
    {
        /* Submodule 0 - ARGB LED */
        .personalityId = PERS_ARGB_OUTPUT,
        .config = {
            .argb = {
                .reserved   = 0,
                .ledCount   = 1,
                .colorOrder = ARGB_COLOR_ORDER_RGB
            },
        },
        .introMsgId = DISP_ARGB_BUTTON_BACKLIGHT_ID,
        .introMsgDLC = DISP_ARGB_BUTTON_BACKLIGHT_DLC,
        .submod_flags = SUBMOD_FLAG_DISPLAY | SUBMOD_FLAG_OUTPUT,
        .runTime = {0}
    },
    { 
        /* Submodule 1 - ARGB STRIP 12 LEDS*/
        .personalityId = PERS_ARGB_OUTPUT,
        .config = {
            .argb = {
                .reserved   = 0,
                .ledCount   = 12,
                .colorOrder = ARGB_COLOR_ORDER_RGB
            },
        },
        .introMsgId = DISP_ARGB_LED_STRIP_ID,
        .introMsgDLC = DISP_ARGB_LED_STRIP_DLC,
        .submod_flags = SUBMOD_FLAG_DISPLAY | SUBMOD_FLAG_OUTPUT,
        .runTime = {0}
    },
    {
        /* Submodule 2 - DIGITAL INPUT */
        .personalityId = PERS_GPIO_INPUT,
        .config = {
            .gpioInput = {
                .debounce = 100,
                .invert   = 0,
                .pull     = 0
            },
        },
        .introMsgId = SW_MOM_PRESS_ID,
        .introMsgDLC = SW_MOM_PRESS_DLC,
        .submod_flags = SUBMOD_FLAG_INPUT,
        .runTime = {0}
    }
    // Add more submodule configurations as needed
};

/** Number of submodules */
const uint8_t g_submodules_count = 
    sizeof(submod_setup) / sizeof(subModule_t);