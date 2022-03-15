#include <iostream>

using namespace std;

template<typename T>
T add(T a, T b) { return (a+b); }
template<typename T>
T dif(T a, T b) { return (a-b); }
template<typename T>
T mul(T a, T b) { return (a*b); }
template<typename T>
T div(T a, T b) { return (a/b); }

int main()
{
	double a,b;
    char op;
	cout << "--------------\n\n";
	cout << "+ : add\n\n";
	cout << "- : subtract\n\n";
	cout << "* : multiply\n\n";
	cout << "/ : divide\n\n";
	cout << "Q : quit\n\n";
	cout << "---------------\n\n";
    while(true)
    {
        int ans;
        cout << "Select an operator: ";
        cin >> op;
        if(op == 'Q')break;
        cout << "Input two number: ";
        cin >> a >> b;
        if(op == '+')ans = add(a,b);
        if(op == '-')ans = dif(a,b);
        if(op == '*')ans = mul(a,b);
        if(op == '/')
        {
            if(b==0)
            {
                cout << "invaild value\n\n";
                continue;
            }
            ans = div(a,b);
        }
        cout << "Answer: " << ans << "\n\n";
    }
}