#include<iostream>
#include <vector>

using namespace std;

pair<int,int> f(int depth, vector<int> discount, vector<int> emoticons, vector<vector<int>> users)
{
    if(emoticons.size()<=depth)
    {

        int count=0;
        int sum=0;
        for(int i=0;i<users.size();i++)
        {
            int usum=0;
            for(int j=0;j<emoticons.size();j++)
            {
                if((discount[j]*10) >= users[i][0])
                {
                    usum+=( (emoticons[j]/10) * (10-discount[j]) );
                }
            }
            if(usum >= users[i][1])
            {
                count++;
            }
            else sum+=usum;
            cout << usum << " ";
        }
        cout << endl;
        return {count,sum};
    }
    pair<int,int> c = {0,0};
    for(int i=1;i<=4;i++)
    {
        discount[depth]=i;
        pair<int,int> t = f(depth+1, discount, emoticons, users);
        if(t>c)c=t;
    }
    return c;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    pair<int,int> t = f(0,vector<int>(emoticons.size()),emoticons,users);
    answer.push_back(t.first);
    answer.push_back(t.second);
    return answer;
}

int main()
{
    cout << solution({{40,10000},{25,10000}},{7000,9000})[1];
    return 0;
}