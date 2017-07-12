#include <iostream>
#include <string>

using namespace std;

int main(){
  //Keep reading until EOF
  string line;
  while (getline(std::cin, line))
  {
    cout << line << std::endl;
    cout << line[0] << endl;
  }
}
