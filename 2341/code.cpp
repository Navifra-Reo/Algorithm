#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

int code[4] = { 1, 86, 172, 256 };
int dynamic[100][4];
int way[100][4];
int n, W;

//함수의 반환값은 이전 픽셀의 코드이다
int print(int i, int depth)
{
    // 처음픽셀까지 도달했을때
    if(depth==0)
    {
        cout << bitset<2>(i);
        return i;
    }

    //이전 픽셀과 코드가 같은경우
    if(print(way[depth][i], depth-1) == i)
    {
        cout << 0;
    }
    //이전 픽셀과 코드가 다른경우
    else cout << 1 << bitset<2>(i);
    
    return i;
}

int main()
{

    int t;
    cin >> n >> W >> t;

    // dynamic[i][j]는 i번째 픽셀을 j번 코드로 변환했을때 최소값
    // 픽셀이 하나만 있을때 값 초기화
    dynamic[0][0b00] = abs(code[0]-t) + 2 * W;
    dynamic[0][0b01] = abs(code[1]-t) + 2 * W;
    dynamic[0][0b10] = abs(code[2]-t) + 2 * W;
    dynamic[0][0b11] = abs(code[3]-t) + 2 * W;
    
    for(int i=1;i<n;i++)
    {
        int a=0, b=0, c=0, d=0;
        cin >> t;
        for(int j=0;j<4;j++)
        {
            int m=1000000;
            int mm=m;
            for(int k=0;k<4;k++)
            {
                // i-1번 픽셀이 k번 코드이고 i번 픽셀이 j번 코드일때 최소값을 구함

                // i번픽셀이 i-1번 픽셀과 같은 코드일 경우
                if(j==k) m = min(m, dynamic[i-1][k] + W + abs(code[j]-t));

                // i번픽셀이 i-1번 픽셀과 다른 코드일 경우
                else m = min(m, dynamic[i-1][k] +  3 *W + abs(code[j]-t));

                // i번 픽셀을 j로 했을때 최소값이 갱신되면 추적용 배열에 k를 넣는다.
                if(mm!=m)way[i][j]=k;
                // 최소값을 갱신한다.
                mm=m;
            }
            //i번 픽셀을 j로 했을때 최소값을 넣어준다.
            dynamic[i][j] = m;
        }
    }

    int ans = 1000000, idx = 0;

    // 마지막 픽셀을 00,01,10,11코드들중 가장 최소값을 구하여 몇번 코드로 끝나는지 구한다.
    for(int i=0;i<4;i++)
    {
        if(ans>dynamic[n-1][i])
        {
            ans = dynamic[n-1][i];
            idx=i;
        }
    }
    cout << ans << '\n';

    // 백트래킹으로 처음 픽셀의 변환된 코드부터 출력한다.
    print(idx, n-1);

    return 0;
}