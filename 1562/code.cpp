#include<iostream>
using namespace std;

int n;
int ans;
int d[10]={0,1,1,1,1,1,1,1,1,1};

int main()
{
    cin >> n;

    for(int i=1;i<n;i++)
    {
        int t[10];
        copy(d,d+10,t);
        d[0]=t[1]%1000000000;
        d[1]=(t[0]+t[2])%1000000000;
        d[2]=(t[1]+t[3])%1000000000;
        d[3]=(t[2]+t[4])%1000000000;
        d[4]=(t[3]+t[5])%1000000000;
        d[5]=(t[4]+t[6])%1000000000;
        d[6]=(t[5]+t[7])%1000000000;
        d[7]=(t[6]+t[8])%1000000000;
        d[8]=(t[7]+t[9])%1000000000;
        d[9]=t[8]%1000000000;
    }

    for(int i=0;i<10;i++)ans+=d[i];

    cout << ans%1000000000 << endl;
    return 0;
}