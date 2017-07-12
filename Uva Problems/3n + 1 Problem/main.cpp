// My Uva Problem 100
// Friedrich Doku Github


#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

  // First Let's get the users input
  int i, j;
  while ( scanf ("%d %d", &i, &j) != EOF ){
    int tempi = i;
    int tempj = j;

    // Okay so this changes them around because we need
    // I to be bigger than j
    if(i > j) swap(i, j);

    // This is the maximum length recieved for the integers
    // we went through
    int max_length = 0;

    // This is just our temp
    int length;

    // Okay now lets just iterate until we reach our end
    while(i <= j){
      // I used unsigned because it shouldn't be negative
      unsigned int n = i;
      length = 1;

      // We don't do this 1 n is equal to 1 because( it won't work anyway)
      while(n != 1){
        if((n % 2) == 1){
          n = 3 * n + 1;
        }else{
          n = n / 2;
        }
        length +=1;
        // compare
        if(length > max_length){
          max_length = length;
        }
      }
      i++;
    }
  // Output and your done
  cout << tempi << " " << tempj <<  " " << max_length << endl;
  }
}
