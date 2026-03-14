/** @file personality_ARGB_511C.c */

#include "personality_table.h"

/** IMPORTANT: Not every personality will need this, some might need an stm32_defs.h */
#include "esp32_defs.h"  

/** Set the node type message */
#define NODE_TYPE_MSG IFACE_ARGB_MULTI_ID
#define NODE_TYPE_DLC IFACE_ARGB_MULTI_DLC

/**
 * @brief Pointer to the personality table.
 *
 * This pointer is used internally to quickly access the personality table.
 */
extern const personalityDef_t g_personalityTable[];

/**
 * @brief Pointer to the first element of the personality table.
 *
 * This pointer is a convenience wrapper around the personality table,
 * allowing for easy iteration over the table.
 */
const personalityDef_t *g_personalityTable_ptr = g_personalityTable;


const personalityDef_t g_personalityTable[] = {

    /* ----------------------------------------------------------------------
     * Submodule 0 — ARGB LED Output
     * ---------------------------------------------------------------------- */
    {
        .personalityId = PERS_ARGB_OUTPUT,
        .capabilities  = CAP_ARGB,                    /**< ARGB LED strip */

        /* Hardware mapping */
        .gpioPin       = ARGB_511C_PIN,               /**< Pin 19 */
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
        .gpioPin       = M5STAMP_ARGB_PIN,           
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
        .gpioPin       = M5STAMP_BUTTON_PIN,          /**< Pin 39 */
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


/** Number of personalities */
uint8_t g_personalityCount =
    sizeof(g_personalityTable) / sizeof(personalityDef_t);
