#include <iostream>
#include <windows.h>
using namespace std;

int main(){

  HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  int k;

  SetConsoleTextAttribute(color, 12); // red
  cout << "bruh!"<< endl;

  SetConsoleTextAttribute(color, 10); //green
  cout << "lel" << endl;

  SetConsoleTextAttribute(color, 7); // back to white


  return 0;
}
