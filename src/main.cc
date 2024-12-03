#include <day1.hh>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>

int
main( int argc, char *argv[] ) {
    if ( argc <= 1 ) {
        std::cout << "Usage: advent-of-code <input>" << std::endl;
        return 1;
    }

    std::filesystem::path path( argv[ 1 ] );
    std::ifstream         stream( path );

    auto [ left, right ] = day1::parse_data( stream );
    auto result_vector   = day1::diff( left, right );

    auto result = std::accumulate(
        result_vector.begin(), result_vector.end(), 0 );

    std::cout << result << std::endl;

    return 0;
}
