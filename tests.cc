#include "mp_list.h"
#include "mp_push_front.h"
#include "mp_rename.h"
#include "mp_size.h"
#include "mp_transform.h"

#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

namespace mp {

// ----------------------------------------------------------------------------
// mp_push_front:
// ----------------------------------------------------------------------------

static_assert(std::is_same_v<mp_push_front<mp_list<>, int>, mp_list<int>>);

static_assert(
    std::is_same_v<mp_push_front<mp_list<>, int, bool>, mp_list<int, bool>>);

static_assert(
    std::is_same_v<mp_push_front<mp_list<int>, bool>, mp_list<bool, int>>);

static_assert(
    std::is_same_v<mp_push_front<std::tuple<std::string, int, int>, bool>,
                   std::tuple<bool, std::string, int, int>>);

static_assert(
    std::is_same_v<mp_push_front<std::tuple<std::string, int, int>, bool, int>,
                   std::tuple<bool, int, std::string, int, int>>);

// ----------------------------------------------------------------------------
// mp_rename:
// ----------------------------------------------------------------------------

static_assert(std::is_same_v<mp_rename<std::tuple<int, bool>, mp_list>,
                             mp_list<int, bool>>);

static_assert(
    std::is_same_v<mp_rename<std::tuple<int, bool, std::string>, mp_list>,
                   mp_list<int, bool, std::string>>);

static_assert(std::is_same_v<
              mp_rename<std::tuple<int, bool, const std::string *>, mp_list>,
              mp_list<int, bool, const std::string *>>);

static_assert(std::is_same_v<
              mp_rename<mp_list<int, bool, const std::string *>, std::tuple>,
              std::tuple<int, bool, const std::string *>>);

static_assert(std::is_same_v<mp_rename<std::pair<int, bool>, mp_list>,
                             mp_list<int, bool>>);

static_assert(std::is_same_v<
              mp_rename<mp_rename<std::tuple<int, bool>, mp_list>, std::tuple>,
              std::tuple<int, bool>>);

// ----------------------------------------------------------------------------
// mp_size:
// ----------------------------------------------------------------------------

template <std::size_t Size>
using SizeIs = std::integral_constant<std::size_t, Size>;

static_assert(std::is_same_v<mp_size<mp_list<>>, SizeIs<0>>);

static_assert(std::is_same_v<mp_size<mp_list<int>>, SizeIs<1>>);

static_assert(std::is_same_v<mp_size<mp_list<int, bool>>, SizeIs<2>>);

static_assert(std::is_same_v<mp_size<mp_list<int, bool, bool>>, SizeIs<3>>);

static_assert(
    std::is_same_v<mp_size<mp_rename<std::tuple<int, bool, bool>, mp_list>>,
                   SizeIs<3>>);

// ----------------------------------------------------------------------------
// mp_transform:
// ----------------------------------------------------------------------------

template <class T> using add_pointer = T *;

static_assert(std::is_same_v<mp_transform<add_pointer, mp_list<>>, mp_list<>>);

static_assert(
    std::is_same_v<mp_transform<add_pointer, mp_list<int, bool, std::string>>,
                   mp_list<int *, bool *, std::string *>>);

static_assert(
    std::is_same_v<mp_transform<add_pointer, mp_list<int>>, mp_list<int *>>);

} // namespace mp

int main() { return 0; }
