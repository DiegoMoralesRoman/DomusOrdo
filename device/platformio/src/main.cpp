#include <Arduino.h>
#include <domusordo.hpp>
#include <utils/timer.hpp>

void setup() {
   pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
   static domo::RepeatTimer t(100);

   if (t.trigger()) {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
   }

   domo::update();
}
