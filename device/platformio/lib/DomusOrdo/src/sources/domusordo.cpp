#include <domusordo.hpp>

#include <utils/timer.hpp>
#include "core_esp8266_features.h"

void domo::update() {
   // Update timers
   domo::RepeatTimer::update_timers(micros());
}
