/**
 *  \file BinaryGrid.cpp
 *  \author Filip Skotarski, 400112313
 *  \brief A module to view the game in ASCII
 *  \date 04/09/2019
 */


#include "BinaryGrid.h"

//Main Constructor
BinaryGrid::BinaryGrid(std::vector<std::vector<char> > grid, std::vector<std::vector<char> > nextGrid){
  this->grid = grid;
  this->nextGrid = nextGrid;
}

void BinaryGrid::toSeq(){

  // Displaying the 2D vector, use grid from the class constructor
  for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++){
          std::cout << grid[i][j] << " ";
        }
      std::cout << std::endl;
  }
}

void BinaryGrid::toNextSeq(){

  // Displaying the 2D vector, use grid from the class constructor
  for (int i = 0; i < nextGrid.size(); i++) {
      for (int j = 0; j < nextGrid[i].size(); j++){
          std::cout << nextGrid[i][j] << " ";
        }
      std::cout << std::endl;
  }
}
