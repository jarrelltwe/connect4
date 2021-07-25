#include <iostream>
#include <windows.h>
#include "Point.h"
#include "BasePoint.h"
using namespace std;

Point::Point(){ //initializing constructor of class Point

  readFile(); //calling readFile function
  for (int x = 0; x < 6; x++){ //loop 6 times

    for (int y = 0; y < 7; y++){ //loop 7 times

      coordinates[x][y] = 0; //assigning all values of 2d array to 0

    }
  }
}

void Point::checkCoordinates(int playerTurn, int x){ //initializing function with two parameters

  int status = 0, num = 1, y = 0; //initializing variables

  if (playerTurn == 1){ //checking if playerTurn is 1

    while (status < 1){ //flag loop

      int temp = y; //assigning value of y to temp variable
      coordinates[temp][x] = 1; //changing value of array to 1
      y += num; //adding to y

      if (y == 6){ //if statement to check if y = 6

        coordinates[temp][x] = 11; //changing value of array to 11
        status = 1; //changing status to 1 to exit loop

      }
      else if (coordinates[y][x] == 0){ //if statement to check if array element value = 0

        coordinates[temp][x] = 0; //changing value of array to 0
        coordinates[y][x] = 1; //changing value of array to 1

      }
      else if (coordinates[y][x] == 11 || coordinates[y][x] == 22){  //if statement to check if array element value = 11 or 22

        coordinates[temp][x] = 11; //changing value of array to 11
        status = 1; //changing status to 1 to exit loop

      }
    }
  }
  else if (playerTurn == 2){ //checking if playerTurn is 2

    while (status < 1){ //flag loop

      int temp = y; //assigning value of y to temp variable
      coordinates[temp][x] = 1; //changing value of array to 1
      y += num; //adding to y

      if (y == 6){ //if statement to check if y = 6

        coordinates[temp][x] = 22; //changing value of array to 22
        status = 1; //changing status to 1 to exit loop

      }
      else if (coordinates[y][x] == 0){  //if statement to check if array element value = 0

        coordinates[temp][x] = 0; //changing value of array to 0
        coordinates[y][x] = 1; //changing value of array to 1

      }
      else if (coordinates[y][x] == 11 || coordinates[y][x] == 22){  //if statement to check if array element value = 11 or 22

        coordinates[temp][x] = 22; //changing value of array to 22
        status = 1; //changing status to 1 to exit loop

      }
    }
  }
}

int Point::checkWin(int playerTurn)
{
  int win = 0; //initializing variable with value 0

  for (int x = 5; x >= 0; x--) //loop 6 times
  {
    for (int y = 6; y >= 0; y--){ //loop 7 times

      //checking for diagonal from right to left
      if (coordinates[x][y] == playerTurn && coordinates[x - 1][y - 1] == playerTurn && coordinates[x - 2][y - 2] == playerTurn && coordinates[x-3][y-3] == playerTurn){
        win = 1; //if true setting win to 1
      }

      //checking for horizontal
      else if (coordinates[x][y] == playerTurn && coordinates[x][y - 1] == playerTurn && coordinates[x][y - 2] == playerTurn && coordinates[x][y - 3] == playerTurn){
        win = 1; // result is a win
      }

      //checking for vertical
      else if (coordinates[x][y] == playerTurn && coordinates[x - 1][y] == playerTurn && coordinates[x - 2][y] == playerTurn && coordinates[x - 3][y] == playerTurn){
        win = 1; // result is a win
      }

      //checking for diagonal from left to right
      else if(coordinates[x][y] == playerTurn && coordinates[x + 1][y - 1] == playerTurn && coordinates[x + 2][y - 2] == playerTurn && coordinates[x + 3][y - 3] == playerTurn){
        win = 1; // result is a win
      }
    }
  }

  return win; //returning value of win
}

void Point::printLayout(){

  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

  for (int x = 0; x < 7; x++){ //loop 7 times

    cout << x + 1 << "   "; //outputting header for layout

  }
  cout << endl;
  for (int x = 0; x < 6; x++){ //loop 6 times

    for (int y = 0; y < 7; y++){ //loop 7 times

      if (coordinates[x][y] == 0){ //checking if array element value = 0

        SetConsoleTextAttribute(color, 7); //setting the color to white
        cout << "*" << "   "; //outputting *

      }
      else if (coordinates[x][y] == 1){ //checking if array element value = 1

        SetConsoleTextAttribute(color, 7); //setting color to white
        cout << "*" << "   "; //outputting *

      }
      else if (coordinates[x][y] == 11){ //checking if array element value = 11

        SetConsoleTextAttribute(color, 12); //setting the color to red
        cout << "X" << "   "; //outputting X

      }
      else if (coordinates[x][y] == 22){ //checking if array element value = 22

        SetConsoleTextAttribute(color, 10); //setting the color to green
        cout << "O" << "   "; //outputting O

      }
    }
    SetConsoleTextAttribute(color, 7); //setting the color back to white
    cout << endl;
  }
  cout << endl;
}

void Point::playGame(){

  int win = 0, playerTurn = 1, player = 11, x; //declaration and initialization of variables

  int player1, player2; //declaration of variables

  getUser(); //calling member function

  cout << "\nPlayer 1, please choose your account you would like to play with (1 - 5): "; //outputting and prompting the user for input
  cin >> player1; //assigning user input to variable
  cout << "You have picked " << getUser(player1 - 1) << " and will start with " << getScore(player1 - 1) << " point(s)." << endl; //outputting to console

  cout << "\nPlayer 2, please choose your account you would like to play with (1 - 5): "; //outputting and prompting the user for input
  cin >> player2; //assigning user input to variable
  cout << "You have picked " << getUser(player2 - 1) << " and will start with " << getScore(player2 - 1) << " point(s)." << endl; //outputting to console

  printLayout(); //calling member function

  while (win < 1){ //flag loop

    cout << getUser(player1 - 1) << ", please enter which column you would like to drop: "; //outputting and prompting the user for input
    cin >> x; //assigning user input to variable
    checkCoordinates(playerTurn, x - 1); //calling member function and passing arguments
    win = checkWin(player); //calling member function and passing arguments and assigning to variable
    printLayout(); //calling member function

    if (win == 1){ //checking if win = 1
      cout << getUser(player1 - 1) << " has won! "<< endl; //prompting user that player 1 has won

      setScoreWon(player1 - 1); //adding 1 point to player 1 score
      cout << getUser(player1 - 1) << " gets 1 point. " << endl; //prompting user that player 1 earns 1 point
      setScoreLost(player2 - 1); //subtracting 1 point to player 2 score
      cout << getUser(player2 - 1) << " loses 1 point." << endl; //prompting user that player loses 1 point
      writeFile(); //calling member function
      win = 1; //setting win to 1 to break the loop
      break;
    }
    
    playerTurn = 2; //changing player turn to 2
    player = 22; //changing value of variable to 22

    cout << getUser(player2 - 1) << ", please enter which column you would like to drop: "; //outputting and prompting the user for input
    cin >> x; //assigning user input to variable
    checkCoordinates(playerTurn, x - 1); //calling member function and passing arguments
    win = checkWin(player); //calling member function and passing arguments and assigning to variable
    printLayout(); //calling member function

    if (win == 1){ //checking if win = 1

      cout << getUser(player2 - 1) << " has won! "<< endl; //prompting user that player 2 has won

      setScoreWon(player2 - 1); //adding 1 point to player 2 score
      cout << getUser(player2 - 1) << " gets 1 point. "; //prompting user that player 1 earns 1 point
      setScoreLost(player1 - 1); //subtracting 1 point to player 2 score
      cout << getUser(player1 - 1) << " loses 1 point."; //prompting user that player loses 1 point
      writeFile(); //calling member function
      win = 1; //setting win to 1 to break the loop
    }
    playerTurn = 1; //changing player turn to 2
    player = 11; //changing value of variable to 22
  }
}
