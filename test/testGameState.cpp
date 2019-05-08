/**
 *  \file testGameState.cpp
 *  \author Filip Skotarski, 400112313
 *  \brief Implementation of Game State tests.
 *  \date 04/09/2019
 */

 #include "catch.h"
 #include <vector>
 #include "GameState.h"

 // We make something above "Section", and we have a bunch of sections that test the output???

 TEST_CASE("Tests for GameState", "[GameState]"){

   SECTION("Test if we have the right count of the initial state of alive and dead cells"){

     GridSize gridDimensions(textFile);
     gridDimensions.readDimensions();
     rows = gridDimensions.getRows();
     columns = gridDimensions.getColumns();

     GameState initialStateVector(rows, columns, "initialState.txt");//Create object for the initial state of the game
     initialStateVector.initialState();//Create vector of text file information
     initialStateVector.aliveVector();//Create vector of text file information
     initialStateVector.nextState();//Create vector of text file information

     REQUIRE(initialStateVector.getAlive() == 51);
     REQUIRE(initialStateVector.getDead() == 973)
   }

   SECTION("Test if we have the right count of the next state of alive and dead cells"){

     GridSize gridDimensions(textFile);
     gridDimensions.readDimensions();
     rows = gridDimensions.getRows();
     columns = gridDimensions.getColumns();

     GameState initialStateVector(rows, columns, "initialState.txt");//Create object for the initial state of the game
     initialStateVector.initialState();//Create vector of text file information
     initialStateVector.aliveVector();//Create vector of text file information
     initialStateVector.nextState();//Create vector of text file information

     REQUIRE(initialStateVector.getNextAlive() == 78);
     REQUIRE(initialStateVector.getNextDead() == 946)
   }


 }
