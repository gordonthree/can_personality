/* Current version */
#include "personality_table.h"

const personalityDef_t *getPersonality(uint8_t index)
{
    if (index >= g_personalityCount) {
        return NULL;
    }
    return &g_personalityTable[index];
}
