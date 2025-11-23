#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/soil.h"

TEST_CASE( "it returns a dot as its symbol" ) {
    Soil soil;
    REQUIRE( soil.symbol() == "." );
}

TEST_CASE( "end_day is a no-op" ) {
    Soil soil;
    soil.end_day();
    REQUIRE( soil.symbol() == "." );
    REQUIRE( !soil.matureFlag() );
}

TEST_CASE( "matureFlag is always false" ) {
    Soil soil;
    REQUIRE( !soil.matureFlag() );
}

TEST_CASE( "water is a no-op" ) {
    Soil soil;
    soil.water();
    REQUIRE( soil.symbol() == "." );
    REQUIRE( !soil.matureFlag() );
}
