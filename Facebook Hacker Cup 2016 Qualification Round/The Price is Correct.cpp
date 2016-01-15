#include <iostream>
#include <fstream>
using namespace std;
long long boxs[100000+10];
int main()
{
    ifstream cin("price.in");
    ofstream cout("price.out");
    int t, n;
    long long p;
    cin>>t;
    for(int c = 1; c <= t; c++){
        long long cnt = 0;
        cin>>n>>p;
        for(int i = 0; i < n; i++)
            cin>>boxs[i];
        /*
        for(int i = 0; i < n; i++){
            unsigned int tmp = 0;
            for(int j = i; j < n; j++){
                tmp += boxs[j];
                if(tmp <= p)
                    cnt++;
                else
                    break;
            }
        }
        */
        int i = 0, j = 0;
        long long sum = boxs[j];
        while(i < n){
            while(sum <= p && j < n-1)
                sum += boxs[++j];
            if(j == n-1){
                if(sum <= p)
                    cnt += j - i + 1;
                else
                    cnt += j - i;
            }
            else
                cnt += j - i;
            sum -= boxs[i];
            i++;
            if(i > j)
                sum = boxs[j = i];
        }
        cout<<"Case #"<<c<<": "<<cnt<<endl;
    }
    return 0;
}
