#include <connection/connection.hpp>

using namespace domo;

connection::ConnectionState connection::connected(states::Signal signal, ConnectionContext& ctx) {
   
   return {connected};
}

