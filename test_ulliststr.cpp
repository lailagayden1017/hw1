#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std; 

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

  list.push_back("L");
  list.push_back("C");
  list.push_back("D");

  list.push_front("A");
  list.push_front("D");

  for(size_t i = 0; i < list.size(); i++){
    cout << list.get(i);
  }
}
