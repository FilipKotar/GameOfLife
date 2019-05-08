/**
 *  \file GameState.cpp
 *  \author Filip Skotarski, 400112313
 *  \brief A module to determine the next state of the game
 *  \date 04/09/2019
 */

#include "GameState.h"

//Main Constructor
GameState::GameState(unsigned int rows, unsigned int columns, std::string textFile){
  this->grid = grid;
  this->textFile = textFile;
  this->alive = 0;
  this->dead = 0;
  this->rows = rows;
  this->columns = columns;
}

std::vector<std::vector<char> > GameState::getState(){
  return grid;
}

std::vector<std::vector<char> > GameState::getNextState(){
  return nextGrid;
}

void GameState::initialState(){

  char value;

  std::ifstream inBinaryGrid;
  //inBinaryGrid.open(textFile);
  inBinaryGrid.open(textFile.c_str());


  for(int i=0; i < rows; i++){

    std::vector<char> temp;

      for (int j=0; j < columns; j++){
        inBinaryGrid >> value;
        if (value) {
          temp.push_back(value);
        }
      }
  this->grid.push_back(temp);
  }
}


//Determining the state of the game
unsigned int GameState::getAlive(){

  this->alive = 0;//For every new state we want to see the alive cells, so reinitialize to 0 for the object

  // Counting Cells
  for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++){
        if(grid[i][j] == '@'){
          this->alive++;
        }
      }
  }
  return alive;
}

unsigned int GameState::getDead(){

  this->dead = 0;

  // Counting Cells
  for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++){
        if(grid[i][j] == '-'){
          this->dead++;
        }
      }
  }
  return dead;
}

//Determining the state of the game
unsigned int GameState::getNextAlive(){

  this->alive = 0;//For every new state we want to see the alive cells, so reinitialize to 0 for the object

  // Counting Cells
  for (int i = 0; i < nextGrid.size(); i++) {
      for (int j = 0; j < nextGrid[i].size(); j++){
        if(nextGrid[i][j] == '@'){
          this->alive++;
        }
      }
  }
  return alive;
}

unsigned int GameState::getNextDead(){

  this->dead = 0;

  // Counting Cells
  for (int i = 0; i < nextGrid.size(); i++) {
      for (int j = 0; j < nextGrid[i].size(); j++){
        if(nextGrid[i][j] == '-'){
          this->dead++;
        }
      }
  }
  return dead;
}

unsigned int GameState::aliveNeighbours(unsigned int i, unsigned int j){

  int aliveNeighbours = 0;
  // Counting Cells that have alive surrounding neighbours

  //We need multiple cases for the border of the grid

  //Top left corner
  if(i == 0 && j == 0){
    if(grid[i][j+1] == '@'){aliveNeighbours++;}
    if(grid[i+1][j] == '@'){aliveNeighbours++;}
    if(grid[i+1][j+1] == '@'){aliveNeighbours++;}
  }

  //Top Right corner
  else if(i == 0 && j == columns-1){
    if(grid[i][j-1] == '@'){aliveNeighbours++;}
    if(grid[i+1][j-1] == '@'){aliveNeighbours++;}
    if(grid[i+1][j] == '@'){aliveNeighbours++;}
  }

  //Bottom Left Corner
  else if(i == rows-1 && j == 0){
    if(grid[i-1][j] == '@'){aliveNeighbours++;}
    if(grid[i-1][j+1] == '@'){aliveNeighbours++;}
    if(grid[i][j+1] == '@'){aliveNeighbours++;}
  }

  //Bottom Right Corner
  else if(i == rows-1 && j == columns-1){
    if(grid[i-1][j] == '@'){aliveNeighbours++;}
    if(grid[i-1][j-1] == '@'){aliveNeighbours++;}
    if(grid[i][j-1] == '@'){aliveNeighbours++;}
  }

  //Ceiling
  else if(i == 0 && j != 0 && j != columns-1){

    //Middle Row
    if(grid[i][j-1] == '@'){aliveNeighbours++;}
    if(grid[i][j+1] == '@'){aliveNeighbours++;}

    //Bottom Row
    if(grid[i+1][j-1] == '@'){aliveNeighbours++;}
    if(grid[i+1][j] == '@'){aliveNeighbours++;}
    if(grid[i+1][j+1] == '@'){aliveNeighbours++;}
  }

  //Floor
  else if(i == rows-1 && j != 0 && j != columns-1){

    //Top Row
    if(grid[i-1][j-1] == '@'){aliveNeighbours++;}
    if(grid[i-1][j] == '@'){aliveNeighbours++;}
    if(grid[i-1][j+1] == '@'){aliveNeighbours++;}

    //Middle Row
    if(grid[i][j-1] == '@'){aliveNeighbours++;}
    if(grid[i][j+1] == '@'){aliveNeighbours++;}
  }

  //Right Wall
  else if(j == columns-1 && i != 0 && i != rows-1){

    //Top Row
    if(grid[i-1][j-1] == '@'){aliveNeighbours++;}
    if(grid[i-1][j] == '@'){aliveNeighbours++;}

    //Middle Row
    if(grid[i][j-1] == '@'){aliveNeighbours++;}

    //Bottom Row
    if(grid[i+1][j-1] == '@'){aliveNeighbours++;}
    if(grid[i+1][j] == '@'){aliveNeighbours++;}
  }

  //Left Wall
  else if(j == 0 && i != 0 && i != rows-1){

    //Top Row
    if(grid[i-1][j] == '@'){aliveNeighbours++;}
    if(grid[i-1][j+1] == '@'){aliveNeighbours++;}

    //Middle Row
    if(grid[i][j+1] == '@'){aliveNeighbours++;}

    //Bottom Row
    if(grid[i+1][j] == '@'){aliveNeighbours++;}
    if(grid[i+1][j+1] == '@'){aliveNeighbours++;}
  }

  //Every other cell inside the borders
  else{

    //Top Row
    if(grid[i-1][j-1] == '@'){aliveNeighbours++;}
    if(grid[i-1][j] == '@'){aliveNeighbours++;}
    if(grid[i-1][j+1] == '@'){aliveNeighbours++;}

    //Middle Row
    if(grid[i][j-1] == '@'){aliveNeighbours++;}
    if(grid[i][j+1] == '@'){aliveNeighbours++;}

    //Bottom Row
    if(grid[i+1][j-1] == '@'){aliveNeighbours++;}
    if(grid[i+1][j] == '@'){aliveNeighbours++;}
    if(grid[i+1][j+1] == '@'){aliveNeighbours++;}
  }

  return aliveNeighbours;

}


char GameState::cellRules(unsigned int i, unsigned int j){

  char value;

  if(grid[i][j] == '@' && (liveGrid[i][j] < 2)){
    value = '-';
  }
  else if(grid[i][j] == '@' && (liveGrid[i][j] == 2 || liveGrid[i][j] == 3)){
    value = '@';
  }
  else if(grid[i][j] == '@' && (liveGrid[i][j] > 3)){
    value = '-';
  }
  else if(grid[i][j] == '-' && (liveGrid[i][j] == 3)){
    value = '@';
  }
  else{
    value = '-';
  }
  return value;
}

void GameState::aliveVector(){

  int aliveNeighbours = 0;

  for(int i=0; i < rows; i++){
    std::vector<int> temp;
      for(int j=0; j < columns; j++){
        aliveNeighbours = GameState::aliveNeighbours(i, j);
        temp.push_back(aliveNeighbours);
        aliveNeighbours = 0;
      }
  liveGrid.push_back(temp);
  }
}

void GameState::nextState(){

  char value;

  for(int i=0; i < rows; i++){
    std::vector<char> temp;
      for(int j=0; j < columns; j++){
        value = GameState::cellRules(i, j);
        temp.push_back(value);
      }
    this->nextGrid.push_back(temp);
  }
    GameState::writeToFile(nextGrid);
}

void GameState::writeToFile(std::vector<std::vector<char> > temp){

  std::ofstream infile;
  infile.open("nextState.txt");

  for(int i=0; i < rows; i++){
      for(int j=0; j < columns; j++){
        infile << temp[i][j];
      }
      infile << "\n";
  }
  infile.close();
}
