#include <include/connection/connection.hpp>

#include <Arduino.h>
#include <ESP8266WiFi.h>

using namespace domo;

static connection::ConnectionContext ctx;
static connection::ConnectionState current_state = {connection::disconnected};

void connection::update() {
   // Check for wireless states
   
   if (ctx.led_timer.trigger() or ctx.led_timer_aux.trigger()) {
      digitalWrite(ctx.cfg.blink_led, !digitalRead(ctx.cfg.blink_led));
   }
}

void connection::signal(ConnectionContext &ctx, const Signals s) {
   current_state = current_state(s, ctx);
}

void connection::init(const Configuration& cfg) {
   ctx.cfg = cfg;
   signal(ctx, Signals::INITIALIZATION);
}
