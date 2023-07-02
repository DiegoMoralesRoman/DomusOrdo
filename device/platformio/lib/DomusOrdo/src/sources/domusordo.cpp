#include <domusordo.hpp>

#include <utils/timer.hpp>
#include "connection/connection.hpp"
#include "core_esp8266_features.h"

void domo::update(const Configuration& cfg) {
   // Update timers
   auto t = micros();
   domo::RepeatTimer::update_timers(t);
   domo::RepeatTimer::update_timers(t);

   // Update state machine
   domo::connection::update(cfg);
}

