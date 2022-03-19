#include <iostream>
 using namespace std;

 int check[3001];
 int group[3001];
 pair<pair<int, int>, pair<int, int>> v[3001];

 int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
 {
     int s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
     s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

     if (s > 0)
         return 1;
     else if (s == 0)
         return 0;
     else
         return -1;
 }

 bool isIntercept(pair<pair<int, int>, pair<int, int>> l1, pair<pair<int, int>, pair<int, int>> l2)
 {
     pair<int, int> p1, p2, p3, p4;
     p1 = l1.first;
     p2 = l1.second;
     p3 = l2.first;
     p4 = l2.second;

     int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
     int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

     if (p1p2 == 0 && p3p4 == 0)
     {
         if (p1 > p2)
             swap(p2, p1);
         if (p3 > p4)
             swap(p3, p4);
         return p3 <= p2 && p1 <= p4;
     }
     return p1p2 <= 0 && p3p4 <= 0;
 }

 void init(int k)
 {
     for (int i = 1; i <= k; i++)
         group[i] = i;
 }
 int Find(int x)
 {
     if (group[x] == x)
         return x;
     return group[x] = Find(group[x]);
 }
 void Union(int x, int y)
 {
     x = Find(x);
     y = Find(y);
     group[y] = x;
 }
 int main()
 {
     int n;
     int ans = 0, a = 0;

     cin >> n;
     init(n);
     for (int i = 1; i <= n; i++)
     {
         int x1, y1, x2, y2;
         cin >> x1 >> y1 >> x2 >> y2;
         v[i].first.first = x1;
         v[i].first.second = y1;
         v[i].second.first = x2;
         v[i].second.second = y2;
         for (int j = 1; j < i; j++)
         {
             if (isIntercept(v[i], v[j]))
             {
                 Union(i, j);
             }
         }
     }
     for (int i = 1; i <= n; i++)
     {
         int g = Find(i);
         check[g]++;
         if (check[ans] < check[g])
             ans = g;
         if (check[g] == 1)
             a++;
     }
     cout << a << '\n'
          << check[ans];
     return 0;
 }