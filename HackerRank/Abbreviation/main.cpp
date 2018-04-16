#include <bits/stdc++.h>

using namespace std;

map<char, bool>mymap;
/*
1
daBcd
ABC */

inline bool 
checkequal(string a, string b){
    for(int i = 0; i < a.length(); ++i){
        if(isupper(a[i])){
            mymap[a[i]] = true;
        }else{
            mymap[a[i]] = false;
        }
    }
    
}

int 
main(){
    int N;
    string a, b;
    while(N--){
        cin >> a >> b;
        if(checkequal(a,b)){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}