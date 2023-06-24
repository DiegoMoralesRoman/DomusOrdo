#include <connection/connection.hpp>

using namespace domo;

connection::ConnectionState connection::searching(states::Signal signal, ConnectionContext& ctx) {
   
   return {searching};
}

