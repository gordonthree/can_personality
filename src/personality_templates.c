#include "personality_table.h"
#include "stddef.h"

const personalityDef_t templateTable[] = {
    {
    .personalityId      = NET_ARGB_REMOTE,
    .capabilities       = CAP_NETWORK | CAP_ARGB,
    .gpioPin            = NO_GPIO_ASSIGNED,
    .pwmChannel         = NO_PWM_ASSIGNED,
    .pwmTimer           = NO_PWM_ASSIGNED,
    .isSinkDriver       = false,
    .dataMsgId          = SET_ARGB_STRIP_COLOR_ID,
    .dataMsgDlc         = SET_ARGB_STRIP_COLOR_DLC,   
    .period_ms          = PRODUCER_PERIOD_100MS,
     
    .flags              = BUILDER_FLAG_IS_NETWORK_NODE | BUILDER_FLAG_USER_DEFINED
    },
    {
    .personalityId      = INTERNAL_WIFI_RSSI,
    .capabilities       = CAP_NONE,
    .gpioPin            = NO_GPIO_ASSIGNED,
    .pwmChannel         = NO_PWM_ASSIGNED,
    .pwmTimer           = NO_PWM_ASSIGNED,
    .isSinkDriver       = false,
    .dataMsgId          = DATA_WIFI_RSSI_ID,
    .dataMsgDlc         = DATA_WIFI_RSSI_DLC,   
    .introMsgId         = SENSOR_WIFI_RSSI_ID,
    .introMsgDlc        = SENSOR_WIFI_RSSI_DLC,
    .period_ms          = PRODUCER_PERIOD_2000MS,
     
    .flags              = BUILDER_FLAG_IS_INTERNAL | BUILDER_FLAG_USER_DEFINED
    },
    {
    .personalityId      = INTERNAL_FREE_HEAP,
    .capabilities       = CAP_NONE,
    .gpioPin            = NO_GPIO_ASSIGNED,
    .pwmChannel         = NO_PWM_ASSIGNED,
    .pwmTimer           = NO_PWM_ASSIGNED,
    .isSinkDriver       = false,
    .dataMsgId          = DATA_RTOS_FREE_HEAP_ID,
    .dataMsgDlc         = DATA_RTOS_FREE_HEAP_DLC,   

    .introMsgId         = SENSOR_RTOS_FREE_HEAP_ID,
    .introMsgDlc        = SENSOR_RTOS_FREE_HEAP_DLC,
    .period_ms          = PRODUCER_PERIOD_2000MS,
    
    .flags              = BUILDER_FLAG_IS_INTERNAL | BUILDER_FLAG_USER_DEFINED
    },
    {
    .personalityId      = INTERNAL_RTOS_HIGHWATERMARK,
    .capabilities       = CAP_NONE,
    .gpioPin            = NO_GPIO_ASSIGNED,
    .pwmChannel         = NO_PWM_ASSIGNED,
    .pwmTimer           = NO_PWM_ASSIGNED,
    .isSinkDriver       = false,
    .dataMsgId          = DATA_RTOS_HIGH_WATER_ID,
    .dataMsgDlc         = DATA_RTOS_HIGH_WATER_DLC,   
    .period_ms          = PRODUCER_PERIOD_1000MS,
    .flags              = BUILDER_FLAG_IS_INTERNAL | BUILDER_FLAG_USER_DEFINED
    },
    {
    .personalityId      = INTERNAL_RESET_REASON,
    .capabilities       = CAP_NONE,
    .gpioPin            = NO_GPIO_ASSIGNED,
    .pwmChannel         = NO_PWM_ASSIGNED,
    .pwmTimer           = NO_PWM_ASSIGNED,
    .isSinkDriver       = false,

    .dataMsgId          = DATA_RESET_REASON_ID,
    .dataMsgDlc         = DATA_RESET_REASON_DLC,

    .introMsgId         = SENSOR_RESET_REASON_ID,
    .introMsgDlc        = SENSOR_RESET_REASON_DLC,

    .period_ms          = PRODUCER_PERIOD_ONCE,        /* publish once at boot */

    .flags              = BUILDER_FLAG_IS_INTERNAL |
                          BUILDER_FLAG_USER_DEFINED
    },
    {
    .personalityId      = INTERNAL_BROWNOUT_STATUS,
    .capabilities       = CAP_NONE,
    .gpioPin            = NO_GPIO_ASSIGNED,
    .pwmChannel         = NO_PWM_ASSIGNED,
    .pwmTimer           = NO_PWM_ASSIGNED,
    .isSinkDriver       = false,

    .dataMsgId          = DATA_BROWNOUT_STATUS_ID,
    .dataMsgDlc         = DATA_BROWNOUT_STATUS_DLC,

    .introMsgId         = SENSOR_BROWNOUT_STATUS_ID,
    .introMsgDlc        = SENSOR_BROWNOUT_STATUS_DLC,

    .period_ms          = PRODUCER_PERIOD_1000MS,

    .flags              = BUILDER_FLAG_IS_INTERNAL |
                          BUILDER_FLAG_USER_DEFINED
    },
    {
    .personalityId      = INTERNAL_UPTIME_MS,
    .capabilities       = CAP_NONE,
    .gpioPin            = NO_GPIO_ASSIGNED,
    .pwmChannel         = NO_PWM_ASSIGNED,
    .pwmTimer           = NO_PWM_ASSIGNED,
    .isSinkDriver       = false,

    .dataMsgId          = DATA_UPTIME_MS_ID,
    .dataMsgDlc         = DATA_UPTIME_MS_DLC,

    .introMsgId         = SENSOR_UPTIME_MS_ID,
    .introMsgDlc        = SENSOR_UPTIME_MS_DLC,

    .period_ms          = PRODUCER_PERIOD_1000MS,

    .flags              = BUILDER_FLAG_IS_INTERNAL |
                          BUILDER_FLAG_USER_DEFINED
    },
    {
    .personalityId      = INTERNAL_WIFI_CHANNEL,
    .capabilities       = CAP_NONE,
    .gpioPin            = NO_GPIO_ASSIGNED,
    .pwmChannel         = NO_PWM_ASSIGNED,
    .pwmTimer           = NO_PWM_ASSIGNED,
    .isSinkDriver       = false,

    .dataMsgId          = DATA_WIFI_CHANNEL_ID,
    .dataMsgDlc         = DATA_WIFI_CHANNEL_DLC,
    .introMsgId         = SENSOR_WIFI_CHANNEL_ID,
    .introMsgDlc        = SENSOR_WIFI_CHANNEL_DLC,

    .period_ms          = PRODUCER_PERIOD_5000MS,     /* 0.2 Hz */

    .flags              = BUILDER_FLAG_IS_INTERNAL |
                          BUILDER_FLAG_USER_DEFINED
    },
    {
    .personalityId      = INTERNAL_CAN_ERROR_COUNTERS,
    .capabilities       = CAP_NONE,
    .gpioPin            = NO_GPIO_ASSIGNED,
    .pwmChannel         = NO_PWM_ASSIGNED,
    .pwmTimer           = NO_PWM_ASSIGNED,
    .isSinkDriver       = false,

    .dataMsgId          = DATA_CAN_ERROR_COUNTERS_ID,
    .dataMsgDlc         = DATA_CAN_ERROR_COUNTERS_DLC,  /* TEC + REC */

    .introMsgId         = SENSOR_CAN_ERR_COUNT_ID,
    .introMsgDlc        = SENSOR_CAN_ERR_COUNT_DLC,

    .period_ms          = PRODUCER_PERIOD_1000MS,

    .flags              = BUILDER_FLAG_IS_INTERNAL |
                          BUILDER_FLAG_USER_DEFINED
    },
    {
    .personalityId      = INTERNAL_CAN_BUS_STATE,
    .capabilities       = CAP_NONE,
    .gpioPin            = NO_GPIO_ASSIGNED,
    .pwmChannel         = NO_PWM_ASSIGNED,
    .pwmTimer           = NO_PWM_ASSIGNED,
    .isSinkDriver       = false,

    .dataMsgId          = DATA_CAN_BUS_STATE_ID,
    .dataMsgDlc         = DATA_CAN_BUS_STATE_DLC, /* 1 byte enum */
    .introMsgId         = SENSOR_CAN_BUS_STATE_ID,
    .introMsgDlc        = SENSOR_CAN_BUS_STATE_DLC,

    .period_ms          = PRODUCER_PERIOD_1000MS,

    .flags              = BUILDER_FLAG_IS_INTERNAL |
                          BUILDER_FLAG_USER_DEFINED
    },
    {
    .personalityId      = INTERNAL_FIRMWARE_VERSION,
    .capabilities       = CAP_NONE,
    .gpioPin            = NO_GPIO_ASSIGNED,
    .pwmChannel         = NO_PWM_ASSIGNED,
    .pwmTimer           = NO_PWM_ASSIGNED,
    .isSinkDriver       = false,

    .dataMsgId          = DATA_FIRMWARE_VERSION_ID,
    .dataMsgDlc         = DATA_FIRMWARE_VERSION_DLC, /* e.g., 3 bytes: major/minor/patch */
    .introMsgId         = SENSOR_FIRMWARE_VER_ID,
    .introMsgDlc        = SENSOR_FIRMWARE_VER_DLC,
    .period_ms          = PRODUCER_PERIOD_ONCE,

    .flags              = BUILDER_FLAG_IS_INTERNAL |
                          BUILDER_FLAG_USER_DEFINED
    },
    {
    .personalityId      = INTERNAL_OTA_PARTITION_INFO,
    .capabilities       = CAP_NONE,
    .gpioPin            = NO_GPIO_ASSIGNED,
    .pwmChannel         = NO_PWM_ASSIGNED,
    .pwmTimer           = NO_PWM_ASSIGNED,
    .isSinkDriver       = false,

    .dataMsgId          = DATA_OTA_PARTITION_INFO_ID,
    .dataMsgDlc         = DATA_OTA_PARTITION_INFO_DLC, /* e.g., partition type + subtype */
    .introMsgId         = SENSOR_OTA_PART_INFO_ID,
    .introMsgDlc        = SENSOR_OTA_PART_INFO_DLC,
    .period_ms          = PRODUCER_PERIOD_ONCE,

    .flags              = BUILDER_FLAG_IS_INTERNAL |
                          BUILDER_FLAG_USER_DEFINED
    }
    

};

/** Count number of personalities */
const uint8_t g_TemplateCount =
    sizeof(templateTable) / sizeof(templateTable[0]);


/**
 * @brief Returns a personalityDef_t struct associated with the given personalityId from the template table.
 * @param personalityId uint8_t identifier of the personality to retrieve.
 * @return personalityDef_t struct associated with the given personalityId, or a dummy struct with .personalityId = PERS_NONE if not found.
 */
personalityDef_t getPersonalityTemplate(uint8_t personalityId) 
{
    const personalityDef_t ret = {
        .personalityId = PERS_NONE
    };
    

    for (uint8_t i = 0; i < g_TemplateCount; i++) {
        if (templateTable[i].personalityId == personalityId) {
            return templateTable[i];
        }
    }
    return ret;
}