#include "mp_bool.h"
#include "mp_count.h"
#include "mp_list.h"
#include "mp_plus.h"
#include "mp_push_front.h"
#include "mp_rename.h"
#include "mp_size.h"
#include "mp_transform.h"

#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <utility>

namespace mp {

template <int N> using int_c = std::integral_constant<int, N>;

// ----------------------------------------------------------------------------
// mp_count:
// ----------------------------------------------------------------------------

static_assert(std::is_same_v<mp_count<mp_list<>, int>, int_c<0>>);

static_assert(std::is_same_v<mp_count<mp_list<int>, int>, int_c<1>>);

static_assert(std::is_same_v<mp_count<mp_list<int, bool>, int>, int_c<1>>);

static_assert(std::is_same_v<mp_count<mp_list<int, bool, int, int, bool>, int>,
                             int_c<3>>);

static_assert(std::is_same_v<mp_count<mp_list<int, bool, int, int, bool>, bool>,
                             int_c<2>>);

// ----------------------------------------------------------------------------
// mp_count_if:
// ----------------------------------------------------------------------------

template <class N> using is_positive = mp_bool<(N::value > 0)>;
template <class N> using is_even = mp_bool<(N::value % 2 == 0)>;
template <class N> using is_zero = mp_bool<(N::value == 0)>;

static_assert(
    std::is_same_v<mp_count_if<mp_list<>, std::is_integral>, int_c<0>>);
static_assert(
    std::is_same_v<mp_count_if<mp_list<>, std::is_pointer>, int_c<0>>);
static_assert(std::is_same_v<mp_count_if<mp_list<>, is_positive>, int_c<0>>);

static_assert(
    std::is_same_v<
        mp_count_if<mp_list<int_c<-1>, int_c<0>, int_c<1>, int_c<2>, int_c<3>>,
                    is_positive>,
        int_c<3>>);

static_assert(
    std::is_same_v<
        mp_count_if<mp_list<int_c<-1>, int_c<0>, int_c<1>, int_c<2>, int_c<3>>,
                    is_even>,
        int_c<2>>);

static_assert(
    std::is_same_v<
        mp_count_if<mp_list<int_c<-1>, int_c<0>, int_c<1>, int_c<2>, int_c<3>>,
                    is_zero>,
        int_c<1>>);

// ----------------------------------------------------------------------------
// mp_plus:
// ----------------------------------------------------------------------------

static_assert(std::is_same_v<mp_plus<>, int_c<0>>);

static_assert(std::is_same_v<mp_plus<int_c<1>>, int_c<1>>);

static_assert(std::is_same_v<mp_plus<int_c<1>, int_c<1>, int_c<1>>, int_c<3>>);

static_assert(std::is_same_v<mp_plus<int_c<1>, int_c<2>, int_c<3>>, int_c<6>>);

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

static_assert(
    std::is_same_v<mp_transform<std::pair, mp_list<>, mp_list<>>, mp_list<>>);

static_assert(
    std::is_same_v<mp_transform<std::pair, mp_list<int>, mp_list<bool>>,
                   mp_list<std::pair<int, bool>>>);

static_assert(
    std::is_same_v<mp_transform<std::pair, mp_list<int, std::string>,
                                mp_list<bool, std::string_view>>,
                   mp_list<std::pair<int, bool>,
                           std::pair<std::string, std::string_view>>>);

static_assert(
    std::is_same_v<mp_transform<std::pair, std::tuple<int, int, bool>,
                                std::tuple<int, bool, int>>,
                   std::tuple<std::pair<int, int>, std::pair<int, bool>,
                              std::pair<bool, int>>>);

static_assert(std::is_same_v<mp_transform<mp_list, std::tuple<int, int, bool>,
                                          std::tuple<int, bool, int>>,
                             std::tuple<mp_list<int, int>, mp_list<int, bool>,
                                        mp_list<bool, int>>>);

} // namespace mp

int main() { return 0; }
