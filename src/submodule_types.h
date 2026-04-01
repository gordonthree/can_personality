#pragma once

#include <stddef.h> // for NULL

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
    uint32_t valueU32;              /**< Last sampled value */
    
    /* ============================
     *  PRODUCER RUNTIME
     * ============================ */
    uint32_t last_published_value;  /**< Last value sent over CAN for change-only detection */

} runTime_t;

/** Common industrial / automotive publish rates, in milliseconds */
typedef uint16_t producer_period_t; 

/** Constants for producer_period_t */
enum PRODUCER_PERIOD_CONSTANTS
{
    PRODUCER_PERIOD_DISABLED = 0,     /**< 0: Task is disabled */
    PRODUCER_PERIOD_10MS     = 10,    /**< 10: 10ms interval */
    PRODUCER_PERIOD_20MS     = 20,    /**< 20: 20ms interval */
    PRODUCER_PERIOD_50MS     = 50,    /**< 50: 50ms interval */
    PRODUCER_PERIOD_100MS    = 100,   /**< 100: 100ms interval */
    PRODUCER_PERIOD_250MS    = 250,   /**< 250: 250ms interval */
    PRODUCER_PERIOD_500MS    = 500,   /**< 500: 500ms interval */
    PRODUCER_PERIOD_1000MS   = 1000,  /**< 1000: 1000ms interval */
    PRODUCER_PERIOD_10000MS  = 10000, /**< 10000: 10000ms interval */
    PRODUCER_PERIOD_30000MS  = 30000  /**< 30000: 30000ms interval */
};

/* === Producer Constants === */
#define PRODUCER_FLAG_NONE            (0x00U)  /**< No producer flags set */
#define PRODUCER_FLAG_ACTIVE          (0x01U)  /**< Submodule participates in producer logic */
#define PRODUCER_FLAG_CHANGE_ONLY     (0x02U)  /**< Publish only on value change */
#define PRODUCER_FLAG_PUBLISH_ENABLED (0x04U)  /**< Publishing allowed */
#define PRODUCER_FLAG_RESERVED2       (0x08U)


#define DEFAULT_PUBLISH_RATE       (1000U)    /**< Default publish period in ms (1 Hz) */
// #define PRODUCER_PUBLISH_DISABLED  (0U)       /**< Publish period disabled */

// #define PRODUCER_RATEMS_1HZ        (1000U)    /**< Publish period 1000ms 1 Hz */
// #define PRODUCER_RATEMS_10HZ       (100U)     /**< Publish period 100ms 10 Hz */
// #define PRODUCER_RATEMS_100HZ      (10U)      /**< Publish period 10ms 100 Hz */

/**
 * @brief Producer behavioral type.
 */
typedef enum
{
    PRODUCER_KIND_NONE     = 0,  /**< No producer / disabled */
    PRODUCER_KIND_DIGITAL,       /**< Digital producer (0/1) */
    PRODUCER_KIND_ANALOG,        /**< Analog producer (0–4095, etc.) */
    PRODUCER_KIND_COUNTER,       /**< Counter / incrementing producer */
    PRODUCER_KIND_TIMER,         /**< Timer / decrementing producer */
    PRODUCER_KIND_PERIODIC,      /**< Periodic value producer */
    PRODUCER_KIND_CUSTOM         /**< User-defined or extended behavior */

} producer_kind_t;

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
        uint8_t flags;         /**< input resistor, logic invert, input mode - see INPUT_FLAG_* */
        uint8_t debounce_ms;   /**< input debounce delay in ms */
        uint8_t reserved;      /**< Padding reserved */
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
uint16_t             introMsgId;
uint8_t              introMsgDLC;

/* Per-function flags (bitfield) */
uint8_t              submod_flags;         /**< SUBMOD_FLAG_* */
uint8_t              router_flags;         /**< ROUTER_FLAG_* */
uint8_t              producer_flags;       /**< PRODUCER_FLAG_* */

/* Producer configuration and runtime data */
runTime_t            runTime;              /**< Producer runtime state */
producer_period_t    producer_period_ms;   /**< Producer publish period in ms */
uint8_t              producer_kind;        /**< Producer kind (obsolete producer_kind_t) */

/* Network node information */
uint32_t             networkNodeId;        /**< Remote node id */
uint32_t             lastSeen;             /**< Last time message received from node */
uint8_t              netConfig[4];         /**< Network configuration parameters */

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

