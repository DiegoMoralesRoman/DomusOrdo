#include <utils/timer.hpp>

using namespace domo;

//
// RepeatTimer
//

uint64_t RepeatTimer::m_time = 0;

void RepeatTimer::update_timers(const uint64_t time) {
   m_time = time;
}

RepeatTimer::RepeatTimer(const uint32_t period)
   : m_period(period * 1000) {
   m_next_activation = m_time + period * 1000;
}

bool RepeatTimer::trigger() {
   if (m_time > m_next_activation) {
      m_next_activation += m_period;
      return true;
   }
   return false;
}

void RepeatTimer::set_period(uint32_t period) {
   m_period = period;
}

//
// OneOffTimer
//

uint64_t OneOffTimer::m_time = 0;

void OneOffTimer::update_timers(const uint64_t time) {
   m_time = time;
}

OneOffTimer::OneOffTimer(const uint32_t period)
   : m_period(period) {
   m_next_activation = m_time + period * 1000;
}

bool OneOffTimer::trigger() {
   return m_time > m_next_activation;
}

void OneOffTimer::set_period(uint32_t period) {
   m_period = period;
}

void OneOffTimer::set() {
   m_next_activation = m_time + m_period;
}
