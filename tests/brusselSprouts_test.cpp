#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/brusselSprouts.h"

TEST_CASE( "it returns a * as its when it is a seedling" ) {
    BrusselSprouts brusselSprouts;
    REQUIRE( brusselSprouts.symbol() == "*" );
    REQUIRE( !brusselSprouts.matureFlag() );
}

TEST_CASE( "it returns a r when the brusselSprouts sprouts" ) {
    BrusselSprouts brusselSprouts;
    for (int i=0; i<=5; i++)
        brusselSprouts.end_day();
    REQUIRE( brusselSprouts.symbol() == "r" );
    REQUIRE( brusselSprouts.matureFlag() );
}

TEST_CASE( "it returns a R when the brusselSprouts is mature" ) {
    BrusselSprouts brusselSprouts;
    for (int i=0; i<=15; i++)
        brusselSprouts.end_day();
    REQUIRE( brusselSprouts.symbol() == "R" );
    REQUIRE( brusselSprouts.matureFlag() );
}

TEST_CASE( "it starts off with age 0" ) {
    BrusselSprouts brusselSprouts;
    REQUIRE( brusselSprouts.get_age() == 0 );
}

TEST_CASE( "it has age 1 after we end the day one time" ) {
    BrusselSprouts brusselSprouts;
    brusselSprouts.end_day();
    REQUIRE( brusselSprouts.get_age() == 1 );
}

TEST_CASE( "it has age 2 after we end the day twice" ) {
    BrusselSprouts brusselSprouts;
    brusselSprouts.end_day();
    brusselSprouts.end_day();
    REQUIRE( brusselSprouts.get_age() == 2 );
}

TEST_CASE( "it increases the age by 2 when we end the day after watering" ) {
    BrusselSprouts brusselSprouts;
    brusselSprouts.water();
    brusselSprouts.end_day();
    REQUIRE( brusselSprouts.get_age() == 2 );
}

TEST_CASE( "watering more than once per day has no effect" ) {
    BrusselSprouts brusselSprouts;
    brusselSprouts.water();
    brusselSprouts.water();
    brusselSprouts.end_day();
    REQUIRE( brusselSprouts.get_age() == 2 );
}

TEST_CASE( "watering on a given day should not affect future days" ) {
    BrusselSprouts brusselSprouts;
    brusselSprouts.water();
    brusselSprouts.end_day();
    brusselSprouts.end_day();
    REQUIRE( brusselSprouts.get_age() == 3 );
}

TEST_CASE( "ages the brusselSprouts properly after many waterings on many days" ) {
    BrusselSprouts brusselSprouts;
    brusselSprouts.water();
    brusselSprouts.end_day();
    brusselSprouts.water();
    brusselSprouts.end_day();
    REQUIRE( brusselSprouts.get_age() == 4 );
}
