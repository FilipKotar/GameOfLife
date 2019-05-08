/**
 *  \file main.cpp
 *  \author Filip Skotarski, 400112313
 *  \brief A module to run the Conway's Game of Life
 *  \date 04/09/2019
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include "BinaryGrid.h"
#include "GameState.h"
#include "GridSize.h"


int main() {

  int rows = 0;
  int columns = 0;
  std::string textFile;

  std::cout << "Name of Initial State File: (example.txt)" << std::endl;
  std::cin >> textFile;

  //Get the size of the Grid, nxn should be the state invariant
  GridSize gridDimensions(textFile);
  gridDimensions.readDimensions();
  rows = gridDimensions.getRows();
  columns = gridDimensions.getColumns();
  std::cout << "\nGrid Size: " << rows << " x " << columns << "\n" << std::endl;

  //Programmer Note: we want to make a vector of vectors (2D Vector) to store text file information
  //Programmer Note: We want to use the BinaryGrid class vector and figure out the next state of the game
  GameState initialStateVector(rows, columns, textFile);//Create object for the initial state of the game
  initialStateVector.initialState();//Create vector of text file information
  initialStateVector.aliveVector();//Create vector of text file information
  initialStateVector.nextState();//Create vector of text file information

  //This set of code will display the initial state of the game
  std::cout << "The Binary Grid is... \n";
  BinaryGrid showBinaryVector(initialStateVector.getState(), initialStateVector.getNextState());//Create an object which is a vector of characters
  showBinaryVector.toSeq();//Output the vector
  std::cout << "\nAlive Cells: " << initialStateVector.getAlive() << std::endl;
  std::cout << "Dead Cells: " << initialStateVector.getDead() << std::endl;

  //This next set of code will display the next state of the game
  std::cout << "\nThe next Binary Grid is... \n";
  showBinaryVector.toNextSeq();
  std::cout << "\nAlive Cells: " << initialStateVector.getNextAlive() << std::endl;
  std::cout << "Dead Cells: " << initialStateVector.getNextDead() << std::endl;



  return 0;

}
