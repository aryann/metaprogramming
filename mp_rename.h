#ifndef METAPROGRAMMING_MP_RENAME_H_
#define METAPROGRAMMING_MP_RENAME_H_

#include <type_traits>

namespace mp {
namespace detail {

template <class OldType, template <class...> class NewContainer>
struct mp_rename;

template <template <class...> class OldContainer, class... Args,
          template <class...> class NewContainer>
struct mp_rename<OldContainer<Args...>, NewContainer> {
  using value = NewContainer<Args...>;
};

} // namespace detail

template <class OldType, template <class...> class NewContainer>
using mp_rename = detail::mp_rename<OldType, NewContainer>::value;

} // namespace mp

#endif // METAPROGRAMMING_MP_RENAME_H_
