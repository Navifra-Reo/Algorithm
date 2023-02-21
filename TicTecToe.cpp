#include<stdio.h>
#include"RECT.h"

void PrintRect(const RECT *rt);
void _Width(const RECT *rt);
void _Height(const RECT *rt);

int main(void)
{
    RECT rect1= {10,20,30,40};
    PrintRect(&rect1);
    return 0;
}
void PrintRect(const RECT *rt)
{
    printf("[좌상단점=(%d %d),우하단점=(%d,%d),폭=%d,높이=%d]\n",rt->left,rt->top,rt->right,rt->bottom,_Width(rt),_Height(rt));
}

int _Width(const RECT *rt)
{
    int width = rt->right - rt->left;
    return width > 0 ? width : -width;
}

int _Height(const RECT *rt)
{
    int height = rt->bottom - rt->top;
    return height>0?height:-height;
}