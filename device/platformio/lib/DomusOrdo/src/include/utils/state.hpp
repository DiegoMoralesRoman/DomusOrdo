#pragma once

#include <functional>

// Simple state machine implementation
namespace states {

using Signal = int;

template<typename Context>
class State {
public:
  template <typename T> State<Context>(const T &func) : m_func(func) {}
  State() = default;
  State(State &&) = default;
  State &operator=(State &&other);

  State &operator=(const State &) = delete;
  State(const State &) = delete;

  State operator()(const Signal s, Context& ctx);

private:
  std::function<State(const Signal, Context& ctx)> m_func;
};

class StateMachine {
   public:

};

#include <utils/state.tcc>
}

