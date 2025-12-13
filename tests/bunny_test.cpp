#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/bunny.h"

TEST_CASE("Bunny construction and accessors") {
    Bunny b(2, 3);

    REQUIRE(b.getRow() == 2);
    REQUIRE(b.getCol() == 3);
    REQUIRE(b.getSymbol() == "&");
    REQUIRE(b.getState() == Bunny::State::Normal);
}


TEST_CASE("Bunny setState works") {
    Bunny b(0, 0);

    b.setState(Bunny::State::Scared);
    REQUIRE(b.getState() == Bunny::State::Scared);

    b.setState(Bunny::State::Normal);
    REQUIRE(b.getState() == Bunny::State::Normal);
}


TEST_CASE("Bunny adjacency check") {
    Bunny b(2, 3);

    // Adjacent positions
    REQUIRE(b.isPlayerAdjacent(1, 3) == true); // above
    REQUIRE(b.isPlayerAdjacent(3, 3) == true); // below
    REQUIRE(b.isPlayerAdjacent(2, 2) == true); // left
    REQUIRE(b.isPlayerAdjacent(2, 4) == true); // right

    // Non-adjacent positions
    REQUIRE(b.isPlayerAdjacent(0, 3) == false);
    REQUIRE(b.isPlayerAdjacent(2, 5) == false);
    REQUIRE(b.isPlayerAdjacent(4, 4) == false);
}


TEST_CASE("Bunny off-map detection") {
    Bunny b1(0,0);
    REQUIRE(b1.isOffMap(5,5) == false);

    Bunny b2(-1,0);
    REQUIRE(b2.isOffMap(5,5) == true);

    Bunny b3(0,5);
    REQUIRE(b3.isOffMap(5,5) == true);

    Bunny b4(5,5);
    REQUIRE(b4.isOffMap(5,5) == true);
}