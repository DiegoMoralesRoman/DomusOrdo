#pragma once

#include <include/utils/state.hpp>
#include "include/domusordo.hpp"
#include "include/utils/timer.hpp"

namespace domo::connection {
   enum Signals : states::Signal {
      NOTHING,
      CONNECTED,
      DISCONNECTED,
      AUTH_ERROR,
      TIMER_TICK,
      CONN_TIMEOUT,
      INITIALIZATION
   };

   struct ConnectionContext {
      RepeatTimer led_timer{100};
      RepeatTimer led_timer_aux{100, true};
      Configuration cfg;
   };

   void update();
   void signal(ConnectionContext& ctx, const Signals s);
   void init(const Configuration& cfg);

   using ConnectionState = states::State<ConnectionContext>;
   // States
   ConnectionState disconnected(states::Signal signal, ConnectionContext& ctx);
   ConnectionState connecting(states::Signal signal, ConnectionContext& ctx);
   ConnectionState searching(states::Signal signal, ConnectionContext& ctx);
   ConnectionState HTTPServer(states::Signal signal, ConnectionContext& ctx);
   ConnectionState connected(states::Signal signal, ConnectionContext& ctx);
}
