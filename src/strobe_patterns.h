#pragma once
#include <stdint.h>

/* Pattern 1: ON 50ms, OFF 50ms, ON 50ms, OFF 400ms */
constexpr uint16_t STROBE_P1[] = { 50, 50, 50, 400 };

/* Pattern 2: 3x flash, pause, 5x flash, pause */
constexpr uint16_t STROBE_P2[] = { 50,50,50,200, 50,50,50,50,50,400 };

/* Add more patterns here... */

/* A simple struct to describe a pattern */
struct StrobePatternDef {
    const uint16_t* steps;
    uint8_t count;
};

/* Lookup table indexed by your STROBE_PATTERN_x enum values */
constexpr StrobePatternDef STROBE_PATTERNS[] = {
    /* index 0 unused or reserved */
    { nullptr, 0 },

    /* STROBE_PATTERN_1 = 1 */
    { STROBE_P1, sizeof(STROBE_P1) / sizeof(uint16_t) },

    /* STROBE_PATTERN_2 = 2 */
    { STROBE_P2, sizeof(STROBE_P2) / sizeof(uint16_t) },

    /* Add more entries as needed */
};
