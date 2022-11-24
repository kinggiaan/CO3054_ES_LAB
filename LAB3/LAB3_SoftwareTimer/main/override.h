#pragma once

// Force the inclusion of FreeRTOS config to make sure we can redefine any macro right after
#include "freertos/FreeRTOSConfig.h"

// New value for configUSE_TIMERS //software timer lab
#undef configUSE_TIMERS 
#define configUSE_TIMERS 1                      