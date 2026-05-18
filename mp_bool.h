#ifndef METAPROGRAMMING_MP_BOOL_H_
#define METAPROGRAMMING_MP_BOOL_H_

#include <type_traits>

namespace mp {

template <bool T> using mp_bool = std::integral_constant<bool, T>;

} // namespace mp

#endif // METAPROGRAMMING_MP_BOOL_H_
