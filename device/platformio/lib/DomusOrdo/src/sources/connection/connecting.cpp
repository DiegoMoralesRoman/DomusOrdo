#include <connection/connection.hpp>

using namespace domo;

connection::ConnectionState connection::connecting(states::Signal signal, ConnectionContext& ctx) {
   
   return {connecting};
}

