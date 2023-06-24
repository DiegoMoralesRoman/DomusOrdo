#pragma once

#include "c_types.h"

namespace domo {
   class RepeatTimer {
      public:
      static void update_timers(const uint64_t time);

      RepeatTimer(const uint32_t period);
      
      bool trigger();
      void set_period(uint32_t period);

      private:
      uint64_t m_next_activation;
      uint32_t m_period;
      static uint64_t m_time;
   };

   class OneOffTimer {
      public:
      static void update_timers(const uint64_t time);

      OneOffTimer(const uint32_t period);

      bool trigger();
      void set_period(uint32_t period);
      void set();

      private:
      uint32_t m_period;
      uint64_t m_next_activation;
      static uint64_t m_time;
   };
}
