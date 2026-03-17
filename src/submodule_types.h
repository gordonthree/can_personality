#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "canbus_project.h"   // for MAX_SUB_MODULES

/* ===========================================================================
 *  TYPEDEFS
 * ========================================================================== */

/**
 * @brief Structure to define a producer and hold its runtime state
 */
typedef struct __attribute__((packed))
{
    /* ============================
     *  RUNTIME SNAPSHOT
     * ============================ */
    uint32_t last_change_ms;        /**< Timestamp of last state change (ms) */
    uint32_t adc_value;             /**< Last sampled ADC value */
    uint8_t  state;                 /**< Logical digital input state */
    uint8_t  last_hardware_output;  /**< Last value written to the hardware output pin */

    /* ============================
     *  PRODUCER CONFIG
     * ============================ */
    uint8_t  kind;                  /**< Producer kind (producer_kind_t) */
    uint8_t  valueSource;           /**< Which runtime field to publish */
    uint16_t period_ms;             /**< Publish period in milliseconds (0 = disabled) */

    /* ============================
     *  PRODUCER RUNTIME
     * ============================ */
    uint32_t last_published_value;  /**< Last value sent over CAN for change-only detection */

} runTime_t;


/** 
 * @brief structure to define a sub module */
typedef struct __attribute__((packed)) subModule_t
{
uint8_t personalityId;          /**< Hardware personality, defines capabilities */
uint8_t personalityIndex;       /**< Personality table index */

/**
 * @note 24-bit user configuration (behavior-level only) */
union __attribute__((packed)) {
    uint8_t rawConfig[3];

    struct { 
        uint8_t mode;        // OUT_MODE_*
        uint8_t param1;      // momentary duration / pwm freq / blink delay
        uint8_t param2;      // pwm duty / strobe pattern / reserved
    } gpioOutput;

    struct {
        uint8_t pull;        // pull-up/down/float
        uint8_t invert;      // logical inversion
        uint8_t reserved;
    } gpioInput;

    struct {
        uint8_t reserved;
        uint8_t ledCount;
        uint8_t colorOrder;
    } argb;

    struct {
        uint8_t overSampleFlag;  /**< ADC oversampling count */
        uint8_t reserved1;       /**< Padding - reserved */
        uint8_t reserved2;       /**< Padding - reserved */
    } analogInput;

    /** Analog RGB/RGBW strips */
    struct {
        uint8_t  configIndex;    /**< led strip configuration index */
        uint8_t  reserved1;       /**< Padding */
        uint8_t  reserved2;       /**< Padding */
    } analogStrip;

    /** Analog DAC outputs */
    struct {
        uint8_t  outputMode;     /**< Index for output mode, 0 = one-shot, 1 = cosine  */
        uint8_t  param1;         /**< output parameter byte 1 */
        uint8_t  param2;         /**< output parameter byte 2 */
    } analogOutput;

    /* Additional personalities as needed */
} config;

/* User-level semantic identity */
uint16_t introMsgId;
uint8_t  introMsgDLC;

/* Per-function flags (bitfield) */
uint8_t submod_flags;           /**< SUBMOD_FLAG_* */
uint8_t router_flags;           /**< ROUTER_FLAG_* */
uint8_t producer_flags;         /**< PRODUCER_FLAG_* */

/* Producer configuration and runtime data */
runTime_t runTime;              /**< Producer config and current runtime state */
} subModule_t;


/** 
 * @brief Structure to define a node
 * 
 */
struct __attribute__((packed)) nodeInfo_t {                                 
subModule_t subModule[MAX_SUB_MODULES]; /**< Sub module configurations associated with this node */
uint32_t    nodeID;                     /**< Unique 32-bit node id number. */
uint16_t    nodeTypeMsg;                /**< An 11-bit message id that defines the node type, used for introduction, set to 0 if node not present. */
uint8_t     nodeTypeDLC;                /**< Data length code for the node type message. */
uint8_t     subModCnt;                  /**< Sub module count for this node. */
};    

/* ===========================================================================
 *  FUNCTION PROTOTYPES
 * ========================================================================== */

const subModule_t *getSubModuleDefaults(uint8_t index);

/* ===========================================================================
 *  GLOBALS 
 * ========================================================================== */

extern const subModule_t submod_setup[];
extern const uint8_t g_submodules_count;

#ifdef __cplusplus
}
#endif

