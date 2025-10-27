#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.h"
#include "../src/farm.hpp"
#include "../src/carrot.h"

TEST_CASE( "it can be initialized with a single plot" ) {
    Player player;
    Farm farm(1, 1, &player);
    REQUIRE( farm.number_of_rows() == 1 );
    REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it can be initialized as a 1x2 farm" ) {
    Player player;
    Farm farm(1, 2, &player);
    REQUIRE( farm.number_of_rows() == 1 );
    REQUIRE( farm.number_of_columns() == 2 );
}

TEST_CASE( "it can be initialized as a 2x1 farm" ) {
    Player player;
    Farm farm(2, 1, &player);
    REQUIRE( farm.number_of_rows() == 2 );
    REQUIRE( farm.number_of_columns() == 1 );
}

TEST_CASE( "it returns the symbol for a single soil plot" ) {
    Player player;
    Farm farm(1, 1, &player);
    REQUIRE( farm.get_symbol(0, 0) == "@" );
}

TEST_CASE( "it returns the symbols for a 1x2 farm" ) {
    Player player;
    Farm farm(1, 2, &player);
    REQUIRE( farm.get_symbol(0, 0) == "@" );
    REQUIRE( farm.get_symbol(0, 1) == "." );
}

TEST_CASE( "it returns the symbols for a 2x1 farm" ) {
    Player player;
    Farm farm(2, 1, &player);
    REQUIRE( farm.get_symbol(0, 0) == "@" );
    REQUIRE( farm.get_symbol(1, 0) == "." );
}

TEST_CASE( "it allows us to plant a carrot" ) {
    Player player;
    Farm farm(1, 2, &player);
    Carrot *carrot = new Carrot();
    farm.plant(0, 1, carrot);
    REQUIRE( farm.get_symbol(0, 1) == "c" );
}

TEST_CASE("it updates day") {
    Player player;
    Farm farm(7, 8, &player);
    REQUIRE(farm.getDay() == 1);
    farm.end_day();
    REQUIRE(farm.getDay() == 2);
}

TEST_CASE("it allows growth") {
    Player player;
    Farm farm(7, 8, &player);
    Carrot *carrot = new Carrot();
    farm.plant(0, 1, carrot);
    REQUIRE(farm.get_symbol(0, 1) == "c");
    farm.end_day();
    REQUIRE(farm.get_symbol(0, 1) == "C");
}

TEST_CASE("it allows harvest") {
    Player player;
    Farm farm(7, 8, &player);
    Carrot *carrot = new Carrot();
    farm.plant(0, 1, carrot);
    REQUIRE(farm.get_symbol(0, 1) == "c");
    farm.harvest(0, 1);
    REQUIRE(farm.get_symbol(0, 1) == "c");
    farm.end_day();
    farm.harvest(0, 1);
    REQUIRE(farm.get_symbol(0, 1) == ".");
}

