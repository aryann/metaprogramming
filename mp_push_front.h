#ifndef METAPROGRAMMING_MP_PUSH_FRONT_H_
#define METAPROGRAMMING_MP_PUSH_FRONT_H_

#include <type_traits>

namespace mp {
namespace detail {

template <class List, class Element> struct mp_push_front;

template <template <class...> class Container, class... Args, class Element>
struct mp_push_front<Container<Args...>, Element> {
  using value = Container<Element, Args...>;
};

} // namespace detail

template <class List, class Element>
using mp_push_front = detail::mp_push_front<List, Element>::value;

} // namespace mp

#endif // METAPROGRAMMING_MP_PUSH_FRONT_H_
