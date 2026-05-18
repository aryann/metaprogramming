#ifndef METAPROGRAMMING_MP_PLUS_H_
#define METAPROGRAMMING_MP_PLUS_H_

#include <type_traits>

namespace mp {
namespace detail {

template <class... Elements> struct mp_plus;

template <> struct mp_plus<> {
  using value = std::integral_constant<int, 0>;
};

} // namespace detail

template <class... Elements>
using mp_plus = detail::mp_plus<Elements...>::value;

namespace detail {

template <class Front, class... Rest> struct mp_plus<Front, Rest...> {
  static constexpr auto _sum = Front::value + ::mp::mp_plus<Rest...>::value;

  using value =
      std::integral_constant<std::remove_const_t<decltype(_sum)>, _sum>;
};

// An optimization to speed up evaluation:
template <class E0, class E1, class E2, class E3, class E4, class E5, class E6,
          class E7, class E8, class E9, class... Rest>
struct mp_plus<E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, Rest...> {
  static constexpr auto _sum = E0::value + E1::value + E2::value + E3::value +
                               E4::value + E5::value + E6::value + E7::value +
                               E8::value + E9::value +
                               ::mp::mp_plus<Rest...>::value;

  using value =
      std::integral_constant<std::remove_const_t<decltype(_sum)>, _sum>;
};

} // namespace detail

} // namespace mp

#endif // METAPROGRAMMING_MP_PLUS_H_
