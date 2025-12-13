#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/lettuce.h"

TEST_CASE( "it returns a * as its when it is a seedling" ) {
    Lettuce lettuce;
    REQUIRE( lettuce.symbol() == "*" );
    REQUIRE( !lettuce.matureFlag() );
}

TEST_CASE( "it returns a l when the lettuce sprouts" ) {
    Lettuce lettuce;
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.symbol() == "l" );
    REQUIRE( !lettuce.matureFlag() );
}

TEST_CASE( "it returns a L when the lettuce is mature" ) {
    Lettuce lettuce;
    for (int i=0; i<=4; i++)
        lettuce.end_day();
    REQUIRE( lettuce.symbol() == "L" );
    REQUIRE( lettuce.matureFlag() );
}

TEST_CASE( "it starts off with age 0" ) {
    Lettuce lettuce;
    REQUIRE( lettuce.get_age() == 0 );
}

TEST_CASE( "it has age 1 after we end the day one time" ) {
    Lettuce lettuce;
    lettuce.end_day();
    REQUIRE( lettuce.get_age() == 1 );
}

TEST_CASE( "it has age 2 after we end the day twice" ) {
    Lettuce lettuce;
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.get_age() == 2 );
}

TEST_CASE( "it increases the age by 2 when we end the day after watering" ) {
    Lettuce lettuce;
    lettuce.water();
    lettuce.end_day();
    REQUIRE( lettuce.get_age() == 2 );
}

TEST_CASE( "watering more than once per day has no effect" ) {
    Lettuce lettuce;
    lettuce.water();
    lettuce.water();
    lettuce.end_day();
    REQUIRE( lettuce.get_age() == 2 );
}

TEST_CASE( "watering on a given day should not affect future days" ) {
    Lettuce lettuce;
    lettuce.water();
    lettuce.end_day();
    lettuce.end_day();
    REQUIRE( lettuce.get_age() == 3 );
}

TEST_CASE( "ages the lettuce properly after many waterings on many days" ) {
    Lettuce lettuce;
    lettuce.water();
    lettuce.end_day();
    lettuce.water();
    lettuce.end_day();
    REQUIRE( lettuce.get_age() == 4 );
}
