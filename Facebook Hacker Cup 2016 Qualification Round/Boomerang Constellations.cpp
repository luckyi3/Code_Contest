#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
int point[2010][2];
int dis[2010][2010];

int main()
{
    ifstream cin("boomerang_constellations.in");
    ofstream cout("boomerang_constellations.out");
    int t, n;
    cin>>t;
    for(int c = 1; c <= t; c++){
    	int cnt = 0;
        cin>>n;
        for(int i = 0; i < n; i++)
            cin>>point[i][0]>>point[i][1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == i)
                    dis[i][j] = 0;
                //else if(j < i)
                //    dis[i][j] = dis[j][i];
                else
                    dis[i][j] = (point[i][0]-point[j][0])*(point[i][0]-point[j][0])
                                    +(point[i][1]-point[j][1])*(point[i][1]-point[j][1]);
            }
            sort(dis[i], dis[i] + n);
            int num = dis[i][0], same = 1;
            for(int j = 1; j < n; j++){
            	if(dis[i][j] == 0)
            		continue;
            	if(dis[i][j] != num){
            		if(same >= 2)
            			cnt += (same*(same-1))/2;
            		num = dis[i][j];
            		same = 1;
            	}
            	else
            		same++;
            }
            if(same >= 2)
                cnt += (same*(same-1))/2;
        }
        cout<<"Case #"<<c<<": "<<cnt<<endl;
    }
    return 0;
}
