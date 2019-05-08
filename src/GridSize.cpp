/**
 *  \file GridSize.cpp
 *  \author Filip Skotarski, 400112313
 *  \brief A module to determine the size of a text file
 *  \date 04/09/2019
 */

#include "GridSize.h"


GridSize::GridSize(std::string textFile){
  this->rows = 0;
  this->columns = 0;
  this->textFile = textFile;
}

unsigned int GridSize::getRows(){
  return columns;
}

unsigned int GridSize::getColumns(){
  return rows;
}

void GridSize::readDimensions(){

  unsigned int countRows = 0;
  unsigned int countColumns = 0;

  std::string line;

  std::ifstream inBinaryGrid;
  inBinaryGrid.open(textFile.c_str());

  //Calculate Amount of Rows, and columns
  while(getline(inBinaryGrid, line)){
    countRows++;
    countColumns= line.length();
  }

  this->rows = countRows;
  this->columns = countColumns-1;
}
