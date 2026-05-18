#ifndef METAPROGRAMMING_MP_POP_FRONT_H_
#define METAPROGRAMMING_MP_POP_FRONT_H_

namespace mp {
namespace detail {

template <class List> struct mp_pop_front;

template <template <class...> class Container, class Front, class... Rest>
struct mp_pop_front<Container<Front, Rest...>> {
  using value = Container<Rest...>;
};

} // namespace detail

template <class List> using mp_pop_front = detail::mp_pop_front<List>::value;

} // namespace mp

#endif // METAPROGRAMMING_MP_POP_FRONT_H_
