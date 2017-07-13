// Friedirch12 Github
// Solved Solution for 673 - Parenthesis Balance

#include <stack>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
bool is_balanced(const string&);

int main(){
  int n_of_cases; vector<string> output;
  scanf("%d", &n_of_cases);  // Much faster for competitive programming
  while(n_of_cases--){
    string s;
    cin >> s;

    bool r = is_balanced(s);
    if(r){output.push_back("YES");}
    else{ output.push_back("NO");}
  }
  for(int i = 0; i < output.size(); i++){
    cout << output[i] << endl;
  }
}

bool is_balanced(const string& expression){
  const char LEFT = '(';
  const char RIGHT = ')';
  const char OTHER_LEFT = '[';
  const char OTHER_RIGHT = ']';

  if(expression.length() <= 1){
    return false;
  }

  stack<char> store;
  string::size_type i; // This will be the index to the string just an interger
  char next;           // Next character from the string
  bool failed = false; // Becomes true once it is found
  char a , b;

  for (i = 0; !failed && (i < expression.length()); ++i){
    next = expression[i];
    if((next == LEFT) || (next == OTHER_LEFT)){
      store.push(next); // Push it on the stack
    }else if((next == OTHER_RIGHT) && (store.empty())){
      return false;      // It has failed
    }else if((next == RIGHT) && (store.empty())){
      return false;      // It has failed
    }else if((next == OTHER_RIGHT) && (!store.empty())){
      a = store.top();
      store.pop();
    }else if((next == RIGHT) && (!store.empty())){
      b = store.top();
      store.pop();
    }
  }
  return (store.empty());
}
