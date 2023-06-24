#include <connection/connection.hpp>

using namespace domo;

connection::ConnectionState connection::disconnected(states::Signal signal, ConnectionContext& ctx) {
   return {disconnected};
}

