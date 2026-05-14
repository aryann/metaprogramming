#include "mp_list.h"
#include "mp_rename.h"

#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

namespace mp {

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

} // namespace mp

int main() { return 0; }
