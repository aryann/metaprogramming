#ifndef METAPROGRAMMING_MP_TRANSFORM_H_
#define METAPROGRAMMING_MP_TRANSFORM_H_

#include <type_traits>

namespace mp {
namespace detail {

template <template <class...> class Func, class... List> struct mp_transform;

template <template <class...> class Func, template <class...> class List,
          class... Elements>
struct mp_transform<Func, List<Elements...>> {
  using value = List<Func<Elements>...>;
};

template <template <class...> class Func,                      //
          template <class...> class List1, class... Elements1, //
          template <class...> class List2, class... Elements2>
struct mp_transform<Func, List1<Elements1...>, List2<Elements2...>> {
  static_assert(sizeof...(Elements1) == sizeof...(Elements2),
                "Arguments to mp_transform2 must be of same length.");

  using value = List1<Func<Elements1, Elements2>...>;
};

} // namespace detail

template <template <class...> class Func, class... Lists>
using mp_transform = detail::mp_transform<Func, Lists...>::value;

} // namespace mp

#endif // METAPROGRAMMING_MP_TRANSFORM_H_
