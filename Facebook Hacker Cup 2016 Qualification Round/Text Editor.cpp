#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>
using namespace std;
string s[310];
int dis[310][310];
int dp[310][310];
int main()
{
    ifstream cin("text_editor.in");
    ofstream cout("text_editor.out");
    int t, n, k;
    cin>>t;
    for(int ans = 1; ans <= t; ans++){
        cin>>n>>k;
        for(int i = 0; i < n; i++)
            cin>>s[i];
        sort(s, s + n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;
                int p = 0;
                while(p < s[i].size() && p < s[j].size() && s[i][p] == s[j][p])
                    p++;
                dis[i][j] = s[i].size() + s[j].size() - 2*p;
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < k; j++)
                dp[i][j] = 1e9;
        for(int i = 0; i < n; i++)
            dp[i][0] = s[i].size();
        for(int c = 1; c < k; c++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < i; j++){
                    dp[i][c] = dp[j][c-1] + dis[j][i] > dp[i][c] ? dp[i][c] : dp[j][c-1] + dis[j][i];
                }
        for(int i = 0; i < n; i++)
            dp[i][k-1] += s[i].size();
        int cnt = 1e9 + 10000;
        for(int i = 0; i < n; i++)
            cnt = dp[i][k-1] < cnt ? dp[i][k-1] : cnt;
        cout<<"Case #"<<ans<<": "<<cnt+k<<endl;
    }
    return 0;
}
