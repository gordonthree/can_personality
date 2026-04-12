#include "submodule_types.h"    // subModule_t
#include "personality_table.h"  // personalityId
// #include "can_producer.h"       // producer_flags
// rebuild

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
                .reserved = 0,
                .ledCount = 1,
                .colorOrder = ARGB_COLOR_ORDER_RGB
            },
        },
        .introMsgId     = DISP_ARGB_BUTTON_BACKLIGHT_ID,
        .introMsgDLC    = DISP_ARGB_BUTTON_BACKLIGHT_DLC,
        .submod_flags   = SUBMOD_FLAG_DISPLAY,
        .producer_flags = 0
    },
    {
        /* Submodule 1 - DIGITAL INPUT */
        .personalityId = PERS_GPIO_INPUT,
        .config = {
            .gpioInput = {
                .flags       = INPUT_FLAG_MODE_MOMENTARY |
                               INPUT_FLAG_INVERT |
                               INPUT_FLAG_PULL_FLOAT,
                .debounce_ms = INPUT_DEBOUNCE_DISABLED,
                .reserved    = 0
            },
        },
        .introMsgId          = INPUT_DIGITAL_GPIO_ID,
        .introMsgDLC         = INPUT_DIGITAL_GPIO_DLC,
        .submod_flags        = SUBMOD_FLAG_DIRECTION, // flag set means input
        .producer_flags      = PRODUCER_FLAG_ACTIVE |
                               PRODUCER_FLAG_PUBLISH_ENABLED,
        .producer_period_ms  = 100, // PRODUCER_RATEMS_10HZ
        .producer_kind       = PRODUCER_KIND_PERIODIC,
    }
    // Add more submodule configurations as needed
};

/** Number of submodules */
const uint8_t g_submodules_count = 
    sizeof(submod_setup) / sizeof(subModule_t);