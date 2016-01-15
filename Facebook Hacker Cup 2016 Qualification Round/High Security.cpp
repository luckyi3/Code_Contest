#include <iostream>
#include <fstream>
using namespace std;
char cells[2][1010];
int main()
{
    ifstream cin("high_security.in");
    ofstream cout("high_security.out");
    int t, n;
    cin>>t;
    for(int c = 1; c <= t; c++){
        int cnt = 0;
        cin>>n;
        cin>>(cells[0]+1)>>(cells[1]+1);
        cells[0][0] = cells[1][0] = 'X';
        cells[0][n+1] = cells[1][n+1] = 'X';
        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= n; j++){
                if(cells[i][j] == '.' && cells[i][j-1] == 'X' && cells[i][j+1] == 'X'){
                    if(cells[1-i][j] == '.'){
                        cells[1-i][j] = 'G';
                        cells[i][j] = 'G';
                        cnt++;
                    }
                    else if(cells[1-i][j] == 'X'){
                        cells[i][j] = 'G';
                        cnt++;
                    }
                    else
                        cells[i][j] = 'G';
                }
            }
        }
        for(int i = 0; i < 2; i++){
            int num = 0, flag = 1;
            for(int j = 0; j <= n+1; j++){
                while(j <= n+1 && cells[i][j] == 'X')
                    j++;
                while(j <= n+1 && cells[i][j] != 'X'){
                    num++;
                    if(cells[i][j] == 'G')
                        flag = 0;
                    j++;
                }
                if(num >= 2 && flag == 1){
                    cnt++;
                }
                num = 0;
                flag = 1;
            }
        }
        cout<<"Case #"<<c<<": "<<cnt<<endl;
    }
    return 0;
}
