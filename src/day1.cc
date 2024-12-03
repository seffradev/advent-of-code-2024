#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <day1.hh>
#include <iostream>
#include <istream>
#include <ranges>
#include <utility>
#include <vector>

namespace day1 {

std::pair<std::vector<int32_t>, std::vector<int32_t>>
parse_data( std::istream &stream ) {
    std::vector<int32_t> left  = {};
    std::vector<int32_t> right = {};

    auto i = 0;
    std::ranges::for_each(
        std::ranges::istream_view<int32_t>( stream ),
        [ & ]( auto &e ) {
            if ( i++ % 2 == 0 ) {
                left.push_back( e );
            } else {
                right.push_back( e );
            }
        } );

    std::sort( left.begin(), left.end() );
    std::sort( right.begin(), right.end() );

    return std::make_pair( left, right );
}

std::vector<int32_t>
diff( std::vector<int32_t> left, std::vector<int32_t> right ) {
    assert( left.size() == right.size() );

    std::vector<int32_t> result;
    result.reserve( left.size() );

    for ( std::tuple<const int32_t &, const int32_t &> element :
          std::views::zip( left, right ) ) {
        auto left_element  = std::get<0>( element );
        auto right_element = std::get<1>( element );

        result.push_back( abs( left_element - right_element ) );
    }

    return result;
}

}
