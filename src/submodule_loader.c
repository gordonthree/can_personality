/**
 * @file submodule_loader.c
 * @brief Load the appropriate submodule defaults file.
 *
 * @details I guess this is dynamic include, it should load the correct personality file based on NODE_TYPE build flag
 * 
 * @author Gordon McLellan
 * @date 2026-03-14
 * 
 */

#include "submodule_types.h"
#include "personality_table.h"

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define CONCAT_HELPER(a, b) a ## b
#define CONCAT(a, b) CONCAT_HELPER(a, b)

/** * Create the specific filename token by appending the NODE_TYPE.
 * If NODE_TYPE is defined as SENSOR_01, this becomes submodule_SENSOR_01.
 */
#define SUBMOD_ID CONCAT(submodule_, NODE_TYPE)

/**
 * Construct the final path string.
 * The 'file' argument is expanded before the STR macro performs stringification.
 */
#define SUBMOD_PATH(file) STR(../submodules/file.c)

#include SUBMOD_PATH(SUBMOD_ID)
