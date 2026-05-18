#ifndef METAPROGRAMMING_MP_COUNT_H_
#define METAPROGRAMMING_MP_COUNT_H_

#include "mp_bool.h"
#include "mp_plus.h"

#include <type_traits>

namespace mp {
namespace detail {

template <class List, class Target> struct mp_count;

template <template <class...> class Container, class... Elements, class Target>
struct mp_count<Container<Elements...>, Target> {
  using value = ::mp::mp_plus<std::is_same<Elements, Target>...>;
};

template <class List, template <class...> class> struct mp_count_if;

template <template <class...> class Container, class... Elements,
          template <class...> class Predicate>
struct mp_count_if<Container<Elements...>, Predicate> {
  using value = ::mp::mp_plus<mp_bool<Predicate<Elements>::value != 0>...>;
};

} // namespace detail

template <class List, class Target>
using mp_count = detail::mp_count<List, Target>::value;

template <class List, template <class...> class Predicate>
using mp_count_if = detail::mp_count_if<List, Predicate>::value;

} // namespace mp

#endif // METAPROGRAMMING_MP_COUNT_H_
