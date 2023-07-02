#include <Arduino.h>
#include <domusordo.hpp>
#include <utils/timer.hpp>
#include <connection/connection.hpp>

domo::Configuration cfg {
   domo::CONFIG_INIT,
   "Cockared",
   "gbgnymbs66ub"
};

void setup() {
   pinMode(LED_BUILTIN, OUTPUT);

   domo::connection::init(cfg);
}

void loop() {
   domo::update();
}