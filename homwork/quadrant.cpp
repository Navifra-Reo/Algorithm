
#include <iostream>
using namespace std;
template<int N>

struct FACT<0> {

    enum { value = 1 };

};
struct FACT {

    enum { value = N * FACT<N-1>::value };

};

template<>

int main()
{
    int n=FACT<10>::value;
    cout << n;
}