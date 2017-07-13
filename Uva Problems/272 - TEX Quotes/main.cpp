#include <iostream>
#include <string>

using namespace std;

int main(){
  //Keep reading until EOF
  string line; string output;
  bool first = true;
  while (getline(std::cin, line))
  {
    for(int i = 0; i < line.length(); i++){
      if(line[i] == '"'){
         if(first){ output = output + "``"; first = false;
         }else{ output = output + "''"; first = true; }
      }
      else{
        output = output + line[i];
      }
    }
    cout << output << endl;
  }

}
