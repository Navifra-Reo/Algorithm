#include <iostream>
using namespace std;

int n;
int d[1000001];
int lis[1000001];

int main()
{
    int k=0;
    cin >> n;
    for(int i=0;i<n;i++) cin >> d[i];
    
    for(int i=0;i<n;i++)
    {
        int s=0,e=k;
        while(s<e)
        {
            int mid = (s+e)/2;
            if(lis[mid] > d[i]) e = mid - 1;
            else if(lis[mid] < d[i]) s = mid + 1;
            else {
                s = mid;
                break;
            }
        }
        if(lis[s] < d[i] && lis[s]!=0)
        {
            s++;
        }
        if(s>=k) k++;
        lis[s]=d[i];
    }
    cout << k;
    return 0;
}