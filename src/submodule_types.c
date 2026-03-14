#include "submodule_types.h"

const subModule_t *g_submodules_ptr = NULL;

const subModule_t *getSubModuleDefaults(uint8_t index) {
    return &g_submodules_ptr[index];
}