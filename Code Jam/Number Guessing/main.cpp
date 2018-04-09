#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    
    while(T--){
        int a, b, n;
        cin >> a >> b;
        cin >> n;
        
        int low = a + 1;
        int high = b;
        string str;
        while(true){
            assert(str != "WRONG_ANSWER");
            int guess = (high + low)/2;
            cout << guess;
            cout.flush();
            cin >> str;
        
            if(str == "TOO_BIG"){
                high = guess - 1; 
            }else if(str == "TOO_SMALL"){
                low = guess + 1;
            }
        }
        
    }
    return 0;
}