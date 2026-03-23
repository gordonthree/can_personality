#include "personality_table.h"

const personalityDef_t templateTable[] = {
    {
    .personalityId = NET_ARGB_REMOTE,
    .capabilities  = CAP_NETWORK | CAP_ARGB,
    .gpioPin       = NO_GPIO_ASSIGNED,
    .pwmChannel    = NO_PWM_ASSIGNED,
    .pwmTimer      = NO_PWM_ASSIGNED,
    .isSinkDriver  = false,
    .dataMsgId     = SET_ARGB_STRIP_COLOR_ID,
    .dataMsgDlc    = SET_ARGB_STRIP_COLOR_DLC,   // nodeID
    .flags         = BUILDER_FLAG_IS_NETWORK_NODE | BUILDER_FLAG_USER_DEFINED
    }
};

