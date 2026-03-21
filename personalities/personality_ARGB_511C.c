/** @file personality_ARGB_511C.c */

#include "personality_table.h"

/** IMPORTANT: Not every personality will need this, some might need an stm32_defs.h */
#include "esp32_defs.h"  

/** Define the personality table first */
const personalityDef_t personalityTable[] = {
    /* ----------------------------------------------------------------------
     * Submodule 0 — ARGB LED Output
     * ---------------------------------------------------------------------- */
    {
        .personalityId = PERS_ARGB_OUTPUT,
        .capabilities  = CAP_ARGB,                    /**< ARGB LED strip */

        /* Hardware mapping */
        .gpioPin       = M5STAMP_CS_PIN_19,               /**< Pin 19 */
        .pwmChannel    = NO_PWM_ASSIGNED,             /**< Not PWM-capable */
        .pwmTimer      = NO_PWM_ASSIGNED,             /**< Not PWM-capable */
        .isSinkDriver  = false,                       /**< Not relevant */

        /* Data reporting / control */
        .dataMsgId     = SET_ARGB_STRIP_COLOR_ID,     /**< SET_ARGB_STRIP_COLOR */
        .dataMsgDlc    = SET_ARGB_STRIP_COLOR_DLC,    /**< nodeID x4 + displayId + colorIndex */

        /* Submodule builder flags */
        .flags         = BUILDER_FLAG_AUTO_CONFIGURE 
    },
    /* ----------------------------------------------------------------------
     * Submodule 1 — ARGB LED Output
     * ---------------------------------------------------------------------- */
    {
        .personalityId = PERS_ARGB_OUTPUT,
        .capabilities  = CAP_ARGB,                     /**< ARGB LED strip */

        /* Hardware mapping */
        .gpioPin       = M5STAMP_ARGB_PIN_27,           
        .pwmChannel    = NO_PWM_ASSIGNED,            
        .pwmTimer      = NO_PWM_ASSIGNED,            
        .isSinkDriver  = false,                      

        /* Data reporting / control */
        .dataMsgId     = SET_ARGB_STRIP_COLOR_ID,                       /**< SET_ARGB_STRIP_COLOR */
        .dataMsgDlc    = SET_ARGB_STRIP_COLOR_DLC,                      /**< nodeID x4 + displayId + colorIndex */

        /* Submodule builder flags */
        .flags         = BUILDER_FLAG_AUTO_CONFIGURE 

    },

    /* ----------------------------------------------------------------------
     * Submodule 2 — Digital GPIO Input
     * ---------------------------------------------------------------------- */
    {
        .personalityId = PERS_GPIO_INPUT,
        .capabilities  = CAP_INPUT,                   /**< Digital input */

        /* Hardware mapping */
        .gpioPin       = M5STAMP_BUTTON_PIN_39,          /**< Pin 39 */
        .pwmChannel    = NO_PWM_ASSIGNED,      
        .pwmTimer      = NO_PWM_ASSIGNED,                        
        .isSinkDriver  = false,                       /**< Inputs do not sink/source */

        /* Data reporting */
        .dataMsgId     = DATA_BUTTON_DOWN_ID,                       /**< INPUT_DIGITAL_GPIO data */
        .dataMsgDlc    = DATA_BUTTON_DOWN_DLC,                      /**< Payload size */

        /* Submodule builder flags */
        .flags         = BUILDER_FLAG_AUTO_CONFIGURE         
    }
};


/** Connect the pointer to the table second */
const personalityDef_t *g_personalityTable = personalityTable;

/** Count number of personalities last */
const uint8_t g_personalityCount =
    sizeof(personalityTable) / sizeof(personalityTable[0]);

/** Set the node type struct
 * @note EDIT THIS: Set the node type
 */
const personalityNode_t g_personalityNode = {
    .nodeTypeMsg = IFACE_ARGB_MULTI_ID,
    .nodeTypeDLC = IFACE_ARGB_MULTI_DLC,
    .subModCnt   = g_personalityCount
};
