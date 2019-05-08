/**
 *  \file GameState.h
 *  \author Filip Skotarski, 400112313
 *  \brief A module to determine the size of the text file
 *  \date 04/09/2019
 */

#ifndef A4_GRIDSIZE_H
#define A4_GRIDSIZE_H

#include <iostream>
#include <vector>
#include <fstream>


class GridSize {

public:

  /**
 *  \brief Construct integers and strings
 *  \details Store text file dimensions in these parameters
 *  \param textFile The inital state file of the game
 */
  GridSize(std::string textFile);

  /**
 *  \brief Set the rows of the text file
 *  \details Set the rows of the text file
 *  \return Set the rows of the text file
 */
  unsigned int getRows();

  /**
 *  \brief Set the columns of the text file
 *  \details Set the columns of the text file
 *  \return Set the columns of the text file
 */
  unsigned int getColumns();

  /**
 *  \brief Count rows and columns of file
 *  \details Set rows and columns of file
 */
  void readDimensions();

private:
  unsigned int rows;//Store amount of rows of the grid
  unsigned int columns;//Store amount of columns of the grid
  std::string textFile;//Store text file name
};



#endif
