#ifndef POINT_H
#define POINT_H
#include "BasePoint.h"

class Point:public BasePoint{ //initializing class Point with inheritance from superclass BasePoint

public:

  //initializing member functions
  Point();
  void printLayout();
  void checkCoordinates(int playerTurn, int x);
  int checkWin(int playerTurn);
  void playGame();

private:

  int coordinates[6][7]; //initializing member variables of class

};

#endif
