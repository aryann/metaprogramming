#ifndef METAPROGRAMMING_MP_TRANSFORM_H_
#define METAPROGRAMMING_MP_TRANSFORM_H_

#include <type_traits>

namespace mp {
namespace detail {

template <template <class...> class Func, class List> struct mp_transform;

template <template <class...> class Func, template <class...> class Container,
          class... Elements>
struct mp_transform<Func, Container<Elements...>> {
  using value = Container<Func<Elements>...>;
};

} // namespace detail

template <template <class...> class Func, class List>
using mp_transform = detail::mp_transform<Func, List>::value;

} // namespace mp

#endif // METAPROGRAMMING_MP_TRANSFORM_H_
