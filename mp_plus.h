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

} // namespace detail

} // namespace mp

#endif // METAPROGRAMMING_MP_PLUS_H_
