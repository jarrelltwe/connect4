#ifndef BASEPOINT_H
#define BASEPOINT_H

class BasePoint{ //declaration of class

public:

  //listing and initializing member fuctions of class
  void readFile();
  void writeFile();
  void getUser();
  int getScore(int a);
  void setScoreWon(int a);
  void setScoreLost(int a);
  std::string getUser(int a);

private:

  //initializing private data members
  std::string user[5];
  int score[5];

};

#endif
