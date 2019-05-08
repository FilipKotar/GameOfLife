/**
 *  \file BinaryGrid.h
 *  \author Filip Skotarski, 400112313
 *  \brief A module for a class for a binary grid
 *  \date 04/09/2019
 */

#ifndef A4_BINARYGRID_H
#define A4_BINARYGRID_H
#include <iostream>
#include <vector>
#include <fstream>


class BinaryGrid {

public:

  /**
 *  \brief Construct multi-dimensional vectors
 *  \details Create a new instance of multidimensional vectors to use for a specific instance of GameState
 *  \param grid The initalState of the game
 *  \param nextGrid The nextState of the game
 */
  BinaryGrid(std::vector<std::vector<char> > grid, std::vector<std::vector<char> > nextGrid);

  /**
 *  \brief Output the vector
 *  \details Print the vector of the initial state of the game
  */
  void toSeq();

  /**
 *  \brief Output the vector
 *  \details Print the vector of the next state of the game
 */
  void toNextSeq();


  //void toLiveSeq();//Function for Testing, Deleted when submitted assignment

private:
  std::vector<std::vector<char> > grid;
  //std::vector<std::vector<int>> liveGrid;//Private vector for Testing, Deleted when submitted assingment
  std::vector<std::vector<char> > nextGrid;


};


#endif
