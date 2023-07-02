template<typename Context>
State<Context>& State<Context>::operator=(State<Context> &&other) {
    m_func = std::move(other.m_func);
    return *this;
}

template<typename Context>
State<Context> State<Context>::operator()(const Signal s, Context& ctx) {
    return m_func(s, ctx);
};
