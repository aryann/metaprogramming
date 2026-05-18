#include "mp_bool.h"
#include "mp_count.h"
#include "mp_list.h"
#include "mp_plus.h"
#include "mp_pop_front.h"
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

static_assert(
    std::is_same_v<
        mp_count_if<
            mp_list<int_c<1>, int_c<2>, int_c<3>, int_c<4>, int_c<5>, int_c<6>,
                    int_c<7>, int_c<8>, int_c<9>, int_c<10>, int_c<11>,
                    int_c<12>, int_c<13>, int_c<14>, int_c<15>, int_c<16>,
                    int_c<17>, int_c<18>, int_c<19>, int_c<20>, int_c<21>,
                    int_c<22>, int_c<23>, int_c<24>, int_c<25>, int_c<26>,
                    int_c<27>, int_c<28>, int_c<29>, int_c<30>, int_c<31>,
                    int_c<32>, int_c<33>, int_c<34>, int_c<35>, int_c<36>,
                    int_c<37>, int_c<38>, int_c<39>, int_c<40>, int_c<41>,
                    int_c<42>, int_c<43>, int_c<44>, int_c<45>, int_c<46>,
                    int_c<47>, int_c<48>, int_c<49>, int_c<50>, int_c<51>,
                    int_c<52>, int_c<53>, int_c<54>, int_c<55>, int_c<56>,
                    int_c<57>, int_c<58>, int_c<59>, int_c<60>, int_c<61>,
                    int_c<62>, int_c<63>, int_c<64>, int_c<65>, int_c<66>,
                    int_c<67>, int_c<68>, int_c<69>, int_c<70>, int_c<71>,
                    int_c<72>, int_c<73>, int_c<74>, int_c<75>, int_c<76>,
                    int_c<77>, int_c<78>, int_c<79>, int_c<80>, int_c<81>,
                    int_c<82>, int_c<83>, int_c<84>, int_c<85>, int_c<86>,
                    int_c<87>, int_c<88>, int_c<89>, int_c<90>, int_c<91>,
                    int_c<92>, int_c<93>, int_c<94>, int_c<95>, int_c<96>,
                    int_c<97>, int_c<98>, int_c<99>, int_c<100>>,
            is_even>,
        int_c<50>>);

// ----------------------------------------------------------------------------
// mp_plus:
// ----------------------------------------------------------------------------

static_assert(std::is_same_v<mp_plus<>, int_c<0>>);

static_assert(std::is_same_v<mp_plus<int_c<1>>, int_c<1>>);

static_assert(std::is_same_v<mp_plus<int_c<1>, int_c<1>, int_c<1>>, int_c<3>>);

static_assert(std::is_same_v<mp_plus<int_c<1>, int_c<2>, int_c<3>>, int_c<6>>);

// ----------------------------------------------------------------------------
// mp_pop_front:
// ----------------------------------------------------------------------------

static_assert(std::is_same_v<mp_pop_front<mp_list<int_c<1>>>, mp_list<>>);

static_assert(
    std::is_same_v<mp_pop_front<mp_list<int_c<1>, int_c<2>, int_c<3>>>,
                   mp_list<int_c<2>, int_c<3>>>);

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
