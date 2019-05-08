/**
 *  \file testGridSize.cpp
 *  \author Filip Skotarski, 400112313
 *  \brief Implementation of GridSize tests.
 *  \date 04/09/2019
 */

#include "catch.h"
#include <vector>
#include "GridSize.h"

// We make something above "Section", and we have a bunch of sections that test the output???

TEST_CASE("Tests for GridSize", "[GridSize]"){

  SECTION("Test getRows() and getColumns() contains the correct amount of rows and columns"){

    GridSize gridDimensions("initialState.txt");
    gridDimensions.readDimensions();
    rows = gridDimensions.getRows();
    columns = gridDimensions.getColumns();

    REQUIRE(rows == 32);
    REQUIRE(columns == 32);
  }
}
