#include <bits/stdc++.h>

using namespace std;
 
int main ()
{
    int n,m;
    int counter=0;
    while(true)
    {
        cin >> m >> n;
        if (n ==0 && m ==0) break;
        counter++;
        if (counter > 1) cout << '\n';
        int field[102][102] = {0};
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                char temp;
                cin >> temp;
                if (temp == '*'){
                    field[i][j] = -1;
                    if (field[i-1][j] != -1) field[i-1][j]++; //top
                    if (field[i-1][j-1] != -1) field[i-1][j-1]++; //top left
                    if (field[i-1][j+1] != -1) field[i-1][j+1]++; //top right
                    if (field[i][j-1] != -1) field[i][j-1]++;//left
                    if (field[i+1][j] != -1) field[i+1][j]++; // bottom
                    if (field[i+1][j+1] != -1) field[i+1][j+1]++; //bottom right
                    if (field[i+1][j-1] != -1) field[i+1][j-1]++; //bottom right
                    if (field[i][j+1] != -1) field[i][j+1]++; //right
                }
            }
        }
        cout << "Field #" << counter << ":\n";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (field[i][j] == -1) cout << '*';
                else cout << field[i][j];
            }
            cout << "\n";
        }
 
   }
   return 0;
}