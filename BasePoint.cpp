#include <iostream>
#include <fstream>
#include "BasePoint.h"
using namespace std;

void BasePoint::getUser(){ //declaration of function

  for (int x = 0; x < 5; x++){ //loop 5 times

    cout << x + 1 << ". " << user[x] << endl; //printing numbers and user

  }
}
string BasePoint::getUser(int a){ //declaration of function with parameter

  return user[a]; //returning string

}

int BasePoint::getScore(int a){ //declaration of function with parameter

  return score[a]; //returning score of user according to index

}
void BasePoint::setScoreWon(int a){ //declaration of function with parameter

  score[a] += 1; //adding to score of user according to index

}
void BasePoint::setScoreLost(int a){ //declaration of function with parameter

  score[a] -= 1; //subtracting score of user according to index

}

void BasePoint::readFile(){ //declaration of function

  fstream inputStream; //creating object from class fstream

  inputStream.open("user.txt"); //opening text file

  for (int x = 0; x < 5; x++){ //loop 5 times

    inputStream >> user[x]; //reading from file and inputting into array
    inputStream >> score[x]; //reading from file and inputting into array

  }

  inputStream.close(); //closing text file

}

void BasePoint::writeFile(){ //declaration of function

  ofstream outputStream; //creating object from class ofstream

  outputStream.open("user.txt"); //opening text file

  for (int x = 0; x < 5; x++){ //loop 5 times

    outputStream << user[x] << endl; //writing to text file from array
    outputStream << score[x] << endl; //writing to text file from array

  }
  outputStream.close(); //closing text file
}
