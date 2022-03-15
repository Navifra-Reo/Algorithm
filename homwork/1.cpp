// 1. mystrcat [Easy]
#include <iostream>
#include <cstring>
using namespace std;

char *mystrcat(const char *str1, const char *str2)
{
    char *temp = (char *)malloc(sizeof(char) * (strlen(str1) + strlen(str2)));
    for (int i = 0; i < strlen(str1); i++)
        temp[i] = str1[i];
    for (int i = strlen(str1); i < strlen(str1) + strlen(str2); i++)
        temp[i] = str2[i - strlen(str1)];
    return temp;
}
int main()
{
    char *str = mystrcat("Hello!", "World!");
    cout << str << endl;
}