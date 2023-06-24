#pragma once

#include <utils/state.hpp>

namespace domo::connection {
   enum Signals : states::Signal {
      
   };

   struct ConnectionContext {

   };

   void update();

   using ConnectionState = states::State<ConnectionContext>;
   // States
   ConnectionState disconnected(states::Signal signal, ConnectionContext& ctx);
   ConnectionState connecting(states::Signal signal, ConnectionContext& ctx);
   ConnectionState searching(states::Signal signal, ConnectionContext& ctx);
   ConnectionState HTTPServer(states::Signal signal, ConnectionContext& ctx);
   ConnectionState connected(states::Signal signal, ConnectionContext& ctx);
}
