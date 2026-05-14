#ifndef METAPROGRAMMING_MP_SIZE_H_
#define METAPROGRAMMING_MP_SIZE_H_

#include "mp_list.h"

#include <type_traits>

namespace mp {
namespace detail {

template <class T> struct mp_size;

template <class... Args> struct mp_size<mp_list<Args...>> {
  using value = std::integral_constant<std::size_t, sizeof...(Args)>;
};

} // namespace detail

template <class T> using mp_size = detail::mp_size<T>::value;

} // namespace mp

#endif // METAPROGRAMMING_MP_SIZE_H_
