#include <iostream>
#include <fstream>
#include <functional>
#include "stack.h"
using namespace std;

int main(int argc, char* argv[])
{
  Stack<int> expStack;
  expStack.push(12);
  expStack.push(13);
  expStack.push(14);
  cout << expStack.top() << endl;
  expStack.pop();
  cout << expStack.top() << endl;

}