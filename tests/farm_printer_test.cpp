#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/player.h"
#include "../src/farm.hpp"
#include "../src/farm_printer.h"

TEST_CASE( "it pretty prints a single plot of land" ) {
    Player player;
    Farm farm(1, 1, &player);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == "@ \n" );
}

TEST_CASE( "it pretty prints a 1x2 farm" ) {
    Player player;
    Farm farm(1, 2, &player);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == "@ . \n" );
}

TEST_CASE( "it pretty prints a 2x1 farm" ) {
    Player player;
    Farm farm(2, 1, &player);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == "@ \n. \n" );
}

TEST_CASE( "it pretty prints a 2x2 farm" ) {
    Player player;
    Farm farm(2, 2, &player);
    FarmPrinter printer(&farm);
    REQUIRE( printer.pp() == "@ . \n. . \n" );
}

TEST_CASE( "it prints on day 2" ) {
    Player player;
    Farm farm(2, 2, &player);
    FarmPrinter printer(&farm);
    farm.end_day();
    REQUIRE( printer.pp() == "\nDay: 2\n@ . \n. . \n" );
}

TEST_CASE( "it prints on day 3" ) {
    Player player;
    Farm farm(1, 1, &player);
    FarmPrinter printer(&farm);
    farm.end_day();
    farm.end_day();
    REQUIRE( printer.pp() == "\nDay: 3\n@ \n" );
}