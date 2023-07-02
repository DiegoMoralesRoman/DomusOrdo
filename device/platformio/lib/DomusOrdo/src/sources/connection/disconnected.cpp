#include <include/connection/connection.hpp>
//#include <EEPROM.h>

using namespace domo;

connection::ConnectionState connection::disconnected(states::Signal signal, ConnectionContext& ctx) {
   switch(signal) {
      case INITIALIZATION: {
         
      }
   }
   return {disconnected};
}

