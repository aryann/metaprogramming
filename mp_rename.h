#ifndef METAPROGRAMMING_MP_RENAME_H_
#define METAPROGRAMMING_MP_RENAME_H_

#include <type_traits>

namespace mp {

namespace detail {

template <class OldType, template <class...> class NewContainer>
struct mp_rename_impl;

template <template <class...> class OldContainer, class... Args,
          template <class...> class NewContainer>
struct mp_rename_impl<OldContainer<Args...>, NewContainer> {
  using result = NewContainer<Args...>;
};

} // namespace detail

template <class OldType, template <class...> class NewContainer>
using mp_rename = detail::mp_rename_impl<OldType, NewContainer>::result;

} // namespace mp

#endif // METAPROGRAMMING_MP_RENAME_H_
