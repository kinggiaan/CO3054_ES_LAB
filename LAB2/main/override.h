#pragma once

// Force the inclusion of FreeRTOS config to make sure we can redefine any macro right after
#include "freertos/FreeRTOSConfig.h"

// New value for configIDLE_SHOULD_YIELD
#undef configIDLE_SHOULD_YIELD
#define configIDLE_SHOULD_YIELD                         1
#undef configUSE_TICKLESS_IDLE 
#define configUSE_TICKLESS_IDLE 0