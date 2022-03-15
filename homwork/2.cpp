#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <windows.h>
#include <conio.h>
#define clrscr() system("cls")
#define getkey() getch()

using namespace std;

int count = 10;

class AbstractMenu
{
    string title;

public:
    AbstractMenu(string s) : title(s) {}
    virtual ~AbstractMenu() {}

    string getTitle() { return title; }

    virtual void command() = 0;
};

class MenuItem : public AbstractMenu
{
    int id;

public:
    MenuItem(string s, int i) : AbstractMenu(s), id(i) {}
    virtual void command()
    {
        cout << getTitle() << "is selected." << endl;
        Sleep(1000);
    }
};
class PopupMenu : public AbstractMenu
{
    vector<AbstractMenu *> v;

public:
    PopupMenu(string s) : AbstractMenu(s) {}
    ~PopupMenu()
    {
        for (int i = 0; i < v.size(); i++)
            delete v[i];
    }
    void addMenu(AbstractMenu *p)
    {
        v.push_back(p);
    }
    virtual void command()
    {
        while (true)
        {
            clrscr();
            int size = v.size();
            if (getTitle() == "보물")
            {
                cout << "성공!" << endl;
                exit(0);
            }
            if (count == 0)
            {
                cout << "실패" << endl;
                exit(0);
            }
            cout << "남은기회 : " << count << endl;
            for (int i = 0; i < size; i++)
                cout << i + 1 << ". " << v[i]->getTitle() << endl;
            cout << size + 1 << ". << Back" << endl;
            cout << "Select an item >> ";
            int cmd;
            cin >> cmd;
            if (cmd == size + 1)
                break;
            if (cmd < 1 || cmd > size + 1)
                continue;
            count--;
            v[cmd - 1]->command();
        }
    }
};
int main()
{
    cout << "보물찾기" << endl;
    cout << "10번 내에 보물을 찾아주세요";

    random_device rand;

    PopupMenu *p[15];

    int tmp = 1, c = 0, level = 0;
    for (int i = 0; i < 15; i++)
    {
        c++;
        if (c > tmp)
        {
            tmp *= 2;
            c = 1;
            level++;
        }
        p[i] = new PopupMenu(to_string((i + 1) % 2 + 1) + "_level" + to_string(level));
    }
    PopupMenu *treasure = new PopupMenu("보물");
    p[rand() % 8 + 7]->addMenu(treasure);

    for (int i = 1; i < 15; i++)
    {
        p[(i - 1) / 2]->addMenu(p[i]);
    }

    p[0]->command();

    for (int i = 0; i < 15; i++)
        delete p[i];

    return 0;
}