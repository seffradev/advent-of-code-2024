#include <cassert>
#include <cstdint>
#include <day1.hh>
#include <numeric>
#include <ranges>
#include <sstream>

using namespace day1;

void
parse_data_test() {
    auto actual_left = {
        1,
        2,
        3,
        3,
        3,
        4,
    };

    auto actual_right = {
        3,
        3,
        3,
        4,
        5,
        9,
    };

    std::stringstream stream;

    stream << "3  4\n"
           << "4  3\n"
           << "2  5\n"
           << "1  3\n"
           << "3  9\n"
           << "3  3";

    auto [ left, right ] = parse_data( stream );

    for ( std::tuple<const int32_t &, const int32_t &> element :
          std::views::zip( left, actual_left ) ) {
        auto left_element  = std::get<0>( element );
        auto right_element = std::get<1>( element );

        assert( left_element == right_element );
    }

    for ( std::tuple<const int32_t &, const int32_t &> element :
          std::views::zip( right, actual_right ) ) {
        auto left_element  = std::get<0>( element );
        auto right_element = std::get<1>( element );

        assert( left_element == right_element );
    }
}

void
diff_test() {
    std::stringstream stream;

    stream << "3  4\n"
           << "4  3\n"
           << "2  5\n"
           << "1  3\n"
           << "3  9\n"
           << "3  3";

    auto [ left, right ] = parse_data( stream );

    auto actual = diff( left, right );

    auto expected = { 2, 1, 0, 1, 2, 5 };

    for ( std::tuple<const int32_t &, const int32_t &> element :
          std::views::zip( actual, expected ) ) {
        auto left_element  = std::get<0>( element );
        auto right_element = std::get<1>( element );

        assert( left_element == right_element );
    }
}

void
sum_test() {
    std::stringstream stream;

    stream << "3  4\n"
           << "4  3\n"
           << "2  5\n"
           << "1  3\n"
           << "3  9\n"
           << "3  3";

    auto [ left, right ] = parse_data( stream );

    auto result = diff( left, right );

    auto actual =
        std::accumulate( result.begin(), result.end(), 0 );

    auto expected = 11;

    assert( actual == expected );
}

int32_t
main( int, char *[] ) {
    parse_data_test();
    diff_test();
    sum_test();
    return 0;
}
