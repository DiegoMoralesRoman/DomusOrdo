#pragma once

#include <cstdint>

namespace domo {
   constexpr uint32_t CONFIG_INIT = 2084280072;
   struct Configuration {
      uint32_t initialized_hash = 0;
      char SSID[32] = {0};
      char PSK[63] = {0};
      uint8_t blink_led = 2;
   };
   ///
   /// @brief Master update function. Has to be called with a certain periodicity for the code to work
   ///
   void update();
   void init(const Configuration& cfg);

}
