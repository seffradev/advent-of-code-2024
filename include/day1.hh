#include <cstdint>
#include <istream>
#include <utility>
#include <vector>

namespace day1 {

using Vec = std::vector<int32_t>;

std::pair<Vec, Vec>
parse_data( std::istream &stream );

Vec diff( Vec, Vec );

}
