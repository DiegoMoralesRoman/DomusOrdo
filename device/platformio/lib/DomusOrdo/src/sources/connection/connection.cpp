#include <include/connection/connection.hpp>

#include <Arduino.h>
#include <ESP8266WiFi.h>

using namespace domo;

static connection::ConnectionContext ctx;
static connection::ConnectionState current_state = {connection::disconnected};

void connection::update(const Configuration& cfg) {
   // Check for wireless states
   
   if (ctx.led_timer.trigger() or ctx.led_timer_aux.trigger()) {
      digitalWrite(cfg.blink_led, !digitalRead(cfg.blink_led));
   }
}

void connection::signal(const Configuration &cfg, const Signals s) {
   current_state = current_state(s, ctx);
}
