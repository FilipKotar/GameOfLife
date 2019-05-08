/**
 *  \file GameState.h
 *  \author Filip Skotarski, 400112313
 *  \brief A module for a class for the change of game state
 *  \date 04/09/2019
 */

#ifndef A4_GAMESTATE_H
#define A4_GAMESTATE_H
#include <iostream>
#include <vector>
#include <fstream>
#include <string>


class GameState {

public:

  /**
 *  \brief Construct a new game state
 *  \details Create a new instance of GameState given some initial elements and a maximum size.
 *  \param rows The x length of the grid file
 *  \param columns The y length of the grid file
 */
  GameState(unsigned int rows, unsigned int columns, std::string textFile);

  /**
 *  \brief Get the grid represented as a 2D vector
 *  \details Returns the vector of the initial state of the game
 *  \return A vector of the game state in before the first iteration
 */
  std::vector<std::vector<char> > getState();

  /**
 *  \brief Get the grid represented as a 2D vector
 *  \details Returns the vector of the next state of the game
 *  \return A vector of the game state in after the first iteration
 */
  std::vector<std::vector<char> > getNextState();

  /**
 *  \brief Get file and turn input into a 2D vector
 *  \details Will be used to determine the next state of the game
 */
  void initialState();


  //********************Determining the state of the game********************//

  /**
 *  \brief Get the amount of cells that are alive in the initial state
 *  \details Returns the amount of cells that are alive in the initial state
 *  \return An integer representing the alive cells for the initial state of the game
 */
  unsigned int getAlive();

  /**
 *  \brief Get the amount of cells that are dead in the initial state
 *  \details Returns the amount of cells that are dead in the initial state
 *  \return An integer representing the dead cells for the initial state of the game
 */
  unsigned int getDead();

  /**
 *  \brief Get the amount of cells that are alive in the next state
 *  \details Returns the amount of cells that are alive in the next state
 *  \return An integer representing the alive cells for the next state of the game
 */
  unsigned int getNextAlive();

  /**
 *  \brief Get the amount of cells that are dead in the next state
 *  \details Returns the amount of cells that are dead in the next state
 *  \return An integer representing the dead cells for the next state of the game
 */
  unsigned int getNextDead();

  /**
 *  \brief Get the amount of alive cells around each cell
 *  \details Returns the amount of live cells for a cell determined by the parameters
 *  \param i A integer used to determine the position of the grid used
 *  \param i A integer used to determine the position of the grid used
 *  \return An integer representing the amount of live cells around a specific cell
 */
  unsigned int aliveNeighbours(unsigned int i, unsigned int j);

  /**
 *  \brief Get the character of the position of the next cell
 *  \details Returns if the cell in the position will be alive of dead in the next state of the game
 *  \param i A integer used to determine the position of the liveGrid used
 *  \param i A integer used to determine the position of the liveGrid used
 *  \return An character representing if the cell lives or dies
 */
  char cellRules(unsigned int i, unsigned int j);

  /**
 *  \brief Get a vector that represents the amount of alive neighbours for each cell
 *  \details Will be used to determine the next state of the game
 */
  void aliveVector();

  /**
 *  \brief Get a vector that represents the next state of the game
 *  \details We push into a 2D vector
 */
  void nextState();

  /**
 *  \brief Create a text file which writes the new state of the game into it
 *  \details Gives the player an option to view the state of the game in a text file rather than in the output
 *  \param temp A 2D vector which represents the next state of the game
 */
  void writeToFile(std::vector<std::vector<char> > temp);

private:
  std::vector<std::vector<char> > grid;//Holds the initial state of the grid
  std::vector<std::vector<int> > liveGrid;//Holds the information of the neighbouring cells
  std::vector<std::vector<char> > nextGrid;//Holds the value of the next state of the game
  std::string textFile;//Holds the value of the text file (initial state) used
  int alive;//Holds the values of the alive cell
  int dead;//Holds the values of the dead cell
  int rows;//Holds amount of rows of the grid
  int columns;//Holds amount of columns of the grid

};

#endif
