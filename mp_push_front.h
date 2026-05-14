#ifndef METAPROGRAMMING_MP_PUSH_FRONT_H_
#define METAPROGRAMMING_MP_PUSH_FRONT_H_

#include <type_traits>

namespace mp {
namespace detail {

template <class List, class... New> struct mp_push_front;

template <template <class...> class Container, class... Existing, class... New>
struct mp_push_front<Container<Existing...>, New...> {
  using value = Container<New..., Existing...>;
};

} // namespace detail

template <class List, class... New>
using mp_push_front = detail::mp_push_front<List, New...>::value;

} // namespace mp

#endif // METAPROGRAMMING_MP_PUSH_FRONT_H_
