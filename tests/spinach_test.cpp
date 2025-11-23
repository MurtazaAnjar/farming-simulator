#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/spinach.h"

TEST_CASE( "it returns a * as its when it is a seedling" ) {
    Spinach spinach;
    REQUIRE( spinach.symbol() == "*" );
    REQUIRE( !spinach.matureFlag() );
}

TEST_CASE( "it returns a s when the spinach sprouts" ) {
    Spinach spinach;
    spinach.end_day();
    spinach.end_day();
    REQUIRE( spinach.symbol() == "s" );
    REQUIRE( spinach.matureFlag() );
}

TEST_CASE( "it returns a S when the spinach is mature" ) {
    Spinach spinach;
    for (int i=0; i<=5; i++)
        spinach.end_day();
    REQUIRE( spinach.symbol() == "S" );
    REQUIRE( spinach.matureFlag() );
}

TEST_CASE( "it starts off with age 0" ) {
    Spinach spinach;
    REQUIRE( spinach.get_age() == 0 );
}

TEST_CASE( "it has age 1 after we end the day one time" ) {
    Spinach spinach;
    spinach.end_day();
    REQUIRE( spinach.get_age() == 1 );
}

TEST_CASE( "it has age 2 after we end the day twice" ) {
    Spinach spinach;
    spinach.end_day();
    spinach.end_day();
    REQUIRE( spinach.get_age() == 2 );
}

TEST_CASE( "it increases the age by 2 when we end the day after watering" ) {
    Spinach spinach;
    spinach.water();
    spinach.end_day();
    REQUIRE( spinach.get_age() == 2 );
}

TEST_CASE( "watering more than once per day has no effect" ) {
    Spinach spinach;
    spinach.water();
    spinach.water();
    spinach.end_day();
    REQUIRE( spinach.get_age() == 2 );
}

TEST_CASE( "watering on a given day should not affect future days" ) {
    Spinach spinach;
    spinach.water();
    spinach.end_day();
    spinach.end_day();
    REQUIRE( spinach.get_age() == 3 );
}

TEST_CASE( "ages the spinach properly after many waterings on many days" ) {
    Spinach spinach;
    spinach.water();
    spinach.end_day();
    spinach.water();
    spinach.end_day();
    REQUIRE( spinach.get_age() == 4 );
}
