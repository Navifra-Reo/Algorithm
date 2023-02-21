#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    for(int i=n-1; i>=0; i--)
    {
        if(deliveries[i]==0 && pickups[i]==0)continue;

        answer+=(i*2+2);
        int dcap=cap,pcap=cap;

        for(int j=i;j>=0;j--)
        {
            if(pcap==0 && dcap==0)break;
            if(deliveries[j]>=0 && dcap>0)
            {
                if(deliveries[j]>=dcap) { deliveries[j]-=dcap; dcap=0; }
                if(deliveries[j]<dcap) { dcap-=deliveries[j]; deliveries[j]=0; }
            }
            if(pickups[j]>=0 && pcap>0)
            {
                if(pickups[j]>=pcap) { pickups[j]-=pcap; pcap=0; }
                if(pickups[j]<pcap) { pcap-=pickups[j]; pickups[j]=0; }
            }
        }
    }
    return answer;
}

int main()
{
    cout << solution(2,2,2,2,1,1,4);
    return 0;
}