/**
 * @file personality_table.h
 * @brief Hardware personality definitions for all submodules.
 * @date 2026-03-15
 *
 * This file defines the firmware-side hardware mapping for each personality.
 * These definitions describe:
 *   - GPIO pins
 *   - PWM timer/channel assignments
 *   - Hardware capabilities (input/output/PWM/strobe/etc.)
 *   - CAN data message IDs and DLCs
 *   - Electrical topology (source vs sink driver)
 *
 * IMPORTANT:
 *   - This file contains *hardware* definitions only.
 *   - User-configurable behavior (mode, pull-up, blink delay, etc.)
 *     lives in subModule_t.config (3-byte config block).
 *   - User-level semantic identity (introMsgId/DLC) also lives in subModule_t.
 */

#pragma once            /** Prevent multiple inclusion */
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>     /**< For NULL */

#include "canbus_project.h"
#include "submodule_types.h"   /**< Sub-module type definitions */

/* --------------------------------------------------------------------------
 * Capability Flags
 * -------------------------------------------------------------------------- */

/**
 * @brief Capability bitmask for submodule hardware features.
 *
 * These flags describe what the hardware *can* do, not what the user configures.
 * Multiple flags may be combined (e.g., CAP_OUTPUT | CAP_PWM).
 */
#define CAP_NONE            (0x00)     /**< No capabilities */
#define CAP_INPUT           (1U << 0)  /**< Submodule can read digital/analog input */
#define CAP_OUTPUT          (1U << 1)  /**< Submodule can drive a GPIO output */
#define CAP_PWM             (1U << 2)  /**< Submodule supports PWM output */
#define CAP_STROBE          (1U << 3)  /**< Submodule supports strobe patterns */
#define CAP_ANALOG          (1U << 4)  /**< Submodule supports ADC input */
#define CAP_ARGB            (1U << 5)  /**< Submodule supports addressable RGB output */
#define CAP_ANALOGRGB       (1U << 6)  /**< Submodule supports analog RGB output.  */
#define CAP_HIZ_OFF         (1U << 7)  /**< Submodule output is high-impedance when off */
#define CAP_HIZ_ON          (1U << 8)  /**< Submodule output high-impedance when on */
#define CAP_OPEN_DRAIN      (CAP_HIZ_OFF | CAP_HIZ_ON) /**< Submodule output is open-drain */
#define CAP_OUTPUT_INVERTED (1U << 9)  /**< Submodule output is inverted */

#define NO_DATA_REPORTING 0x00
#define NO_GPIO_ASSIGNED  0xFF
#define NO_PWM_ASSIGNED   0xFF

#define M5STAMP_PIN_SCK  (18U)

#define INPUT_DEBOUNCE_DISABLED  (0u)


/* --------------------------------------------------------------------------
 * Personality Definition Structure
 * -------------------------------------------------------------------------- */

/**
 * @brief Firmware-defined hardware personality descriptor.
 *
 * This structure defines the *hardware* characteristics of a submodule.
 * It is compiled into firmware and never transmitted over CAN.
 *
 * Fields:
 *   - personalityId: Unique ID that matches subModule_t.personalityId
 *   - capabilities: Bitmask describing what the hardware can do
 *   - gpioPin: Physical pin number for GPIO/PWM
 *   - pwmChannel: PWM channel index (0xFF if not PWM-capable)
 *   - pwmTimer: PWM timer index (0xFF if not PWM-capable)
 *   - isSinkDriver: true = low-side switch, false = high-side
 *   - dataMsgId: CAN message ID used for runtime data reporting
 *   - dataMsgDlc: DLC for runtime data messages
 */
typedef struct {
    uint8_t   personalityId;     /**< Unique personality identifier */
    uint16_t  capabilities;      /**< CAP_* bitmask describing hardware features */

    /* Hardware mapping */
    uint8_t   gpioPin;           /**< Physical GPIO pin index */
    uint8_t   pwmChannel;        /**< PWM channel (0xFF if unused) */
    uint8_t   pwmTimer;          /**< PWM timer (0xFF if unused) */
    bool      isSinkDriver;      /**< true = low-side driver, false = high-side */

    /* CAN data reporting */
    uint16_t  dataMsgId;         /**< CAN ID for runtime data messages */
    uint8_t   dataMsgDlc;        /**< DLC for runtime data messages */

    /* Virtual submodule introduction message */
    uint16_t  introMsgId;        /**< CAN ID for submodule introduction messages */
    uint8_t   introMsgDlc;       /**< DLC for submodule introduction messages */

    /* Virtual submodule publish rate */
    uint16_t  period_ms;         /**< Publish rate in milliseconds */

    /* Submodule builder flags */
    uint8_t   flags;             /**< Submodule builder flags */

} personalityDef_t;

typedef struct {
    uint16_t nodeTypeMsg;                /**< An 11-bit message id that defines the node type, used for introduction, set to 0 if node not present. */
    uint8_t  nodeTypeDLC;                /**< Data length code for the node type message. */
    uint8_t  subModCnt;                  /**< Sub module count for this node. */
} personalityNode_t;

#define BUILDER_FLAG_NONE             (0)               /**< No flags */
#define BUILDER_FLAG_AUTO_CONFIGURE   (1U << 0)         /**< Submodule is auto-configured */
#define BUILDER_FLAG_IS_VIRTUAL       (1U << 1)         /**< Submodule is a virtual device */
#define BUILDER_FLAG_DEVICE_HIDDEN    (1U << 2)         /**< Submodule is hidden from user interface */
#define BUILDER_FLAG_DEVICE_DISABLED  (1U << 3)         /**< Submodule is disabled */
#define BUILDER_FLAG_DEVICE_READONLY  (1U << 4)         /**< Submodule is read-only */

/**
 * @brief Enumerates all hardware personality IDs.
 * @enum personalityId_t
 * 
 * These values appear in subModule_t.personalityId and must match
 * the entries in the personality table.
 */
typedef enum {
    PERS_NONE = 0,              /**< Unconfigured / invalid */

    /* Output personalities */
    PERS_GPIO_OUTPUT            = 1,       /**< Generic GPIO output (toggle/momentary/strobe/PWM) */
    PERS_ARGB_OUTPUT            = 2,       /**< Addressable ARGB LED strip (NeoPixelBus) */
    PERS_RGBW_OUTPUT            = 3,       /**< Analog RGBW LED strip (GPIO + PWM) */
    PERS_ANA_OUTPUT             = 4,       /**< Generic analog output (DAC) */

    /* Input personalities */
    PERS_GPIO_INPUT             = 10,        /**< Digital GPIO input */
    PERS_ANALOG_INPUT           = 11,        /**< ADC input */

    /* Virtual personalities */
    VIRT_FREE_HEAP              = 0xC0,      /**< Free heap size (bytes) */
    VIRT_WIFI_RSSI              = 0xC1,      /**< WiFi RSSI (dBm) */
    VIRT_RTOS_HIGHWATERMARK     = 0xC2,      /**< FreeRTOS high watermark (bytes) */
    VIRT_INTERNAL_TEMPERATURE   = 0xC3,      /**< Internal temperature (C) */
    VIRT_VREF_VOLTAGE           = 0xC4,      /**< Internal voltage reference (Vref) voltage (V) */

    /* System personalities */
    SYS_TOUCH_LCD                = 0xF0,     /**< Touchscreen (e.g., CYD / XPT2046) */
    SYS_NON_TOUCH_LCD            = 0xF1      /**< Generic display (e.g., SSD1306) */

    /* Add more as needed */
} personalityId_t;


/* --------------------------------------------------------------------------
 * Personality Table Declaration
 * -------------------------------------------------------------------------- */

/**
 * @brief Personality table for this node type.
 *
 * This table is generated per node type (via automation or build scripts).
 * The firmware selects the correct table at boot based on nodeTypeMsg.
 *
 * Example:
 *   extern const personalityDef_t personalityTable_0x700[];
 *   extern const uint8_t personalityCount_0x700;
 *
 * The actual table is defined in a node-type-specific .c file.
 */
extern const personalityDef_t personalityTable[];   /**< DECLARE global array for active personality table */
extern const personalityDef_t *g_personalityTable;  /**< DECLARE global pointer to active table */
extern const uint8_t g_personalityCount;                  /**< DECLARE global counter for number of personalities */
extern const personalityNode_t g_personalityNode;   /**< DECLARE global node definition */


/* --------------------------------------------------------------------------
 * Lookup Helpers
 * -------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif 
