#include "personality_table.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================ */
/* Define Global Variables                                                           
/* ============================================================================ */

personalityDef_t runtimePersonalityTable[MAX_RUNTIME_PERSONALITIES] = {0};
uint8_t runtimePersonalityCount = 0;  

/* ============================================================================ 
 * Public Functions                                                          
 * ==========================================================================*/

 /**
 * @brief Initializes the runtime personality table.
 * @details This function copies the built-in personality table into the runtime personality table.
 * @return The number of personalities copied into the runtime table. If no personalities are defined, returns -1.
 */
int initRuntimePersonalityTable(void)
{
    uint8_t count = 0;

    /** Clear runtimePersonalityTable array */
    memset(&runtimePersonalityTable, 0xFF, sizeof(personalityDef_t) * MAX_RUNTIME_PERSONALITIES);

    if (g_personalityCount == 0) {
      return -1; /* No personalities defined */
    }

    /* Copy built-in personalities into runtime table */
    for (uint8_t i = 0; i < g_personalityCount; i++) {
        runtimePersonalityTable[i] = g_personalityTable[i];
        count++;
    }

    return count;
}


/**
 * @brief Get the index of a free personality slot in the runtime table.
 * @details This function iterates over the runtime personality table and returns the index of the first free slot found.
 * @return The index of a free personality slot if found, -1 if the table is full.
 */
int getFreePersonalitySlot(void)
{
    for (uint8_t i = 0; i < MAX_RUNTIME_PERSONALITIES; i++) {
        if (runtimePersonalityTable[i].personalityId == 0xFF) {
            /* 0xFF indicates an empty slot, matching the 
            initialization value */
            return i;
        }
    }
    return -1;
}

#ifdef __cplusplus
}
#endif 

