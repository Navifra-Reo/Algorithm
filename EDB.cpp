#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

struct pos
{
	int x;
	int y;
	pos(int X, int Y) : x(X), y(Y) {}
};
void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void init(vector<string> &vec)
{
	vec['A'].assign(" A A AAAAA AA A");
	vec['B'].assign("BB B BBB B BBB ");
	vec['C'].assign(" C C CC  C C C ");
	vec['D'].assign("DD D DD DD DDD ");
	vec['E'].assign("EEEE  EEEE  EEE");
	vec['F'].assign("FFFF  FFFF  F  ");
	vec['G'].assign(" G G GG  GGG G ");
	vec['H'].assign("H HH HHHHH HH H");
	vec['I'].assign("III I  I  I III");
	vec['J'].assign("JJJ  J  JJ JJJ ");
	vec['K'].assign("K KKK K  KK K K");
	vec['L'].assign("L  L  L  L  LLL");
	vec['M'].assign("MMMMMMM MM MM M");
	vec['N'].assign("N NNNNNNNNNNN N");
	vec['O'].assign(" O O OO OO O O ");
	vec['P'].assign("PP P PPP P  P  ");
	vec['Q'].assign(" Q Q QQ QQQQ Q ");
	vec['R'].assign("RRRR RRR R RR R");
	vec['S'].assign("SSSS  SSS  SSSS");
	vec['T'].assign("TTT T  T  T  T ");
	vec['U'].assign("U UU UU UU UUUU");
	vec['V'].assign("V VV VV VV V V ");
	vec['W'].assign("W WW WW WWWWWWW");
	vec['X'].assign("X XX X X X XX X");
	vec['Y'].assign("Y YY Y Y  Y  Y ");
	vec['Z'].assign("ZZZ  Z Z Z  ZZZ");
}
void print(pos _pos, string ch)
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			gotoxy(_pos.y + j, _pos.x + i);
			cout << ch[i * 3 + j];
		}
	}
}
int main()
{
	vector<pos> sPos;
	vector<string> signal(128);
	string str;
	char direction;
	int move = 1;

	cout << "-input: ";
	cin >> str;
	cout << "-direction(L, R, U, D, R): ";
	cin >> direction;

	init(signal);

	system("cls");

	cout << direction << endl;
	for (int i = 0; i < str.size(); i++)
	{
		if (direction == 'L' || direction == 'R')
			sPos.push_back(pos(0, i * 7));
		else
			sPos.push_back(pos(i * 7, 0));
	}
	if (direction == 'R' || direction == 'D')
		move = -1;
	int s = 0;
	while (true)
	{
		for (int i = 0; i < str.size(); i++)
		{
			// cout << s << " " << move << endl;
			print(sPos[i], signal[toupper(str[s])]);
			s += 1;
			if (s == str.size())
				s = 0;
			Sleep(100);
		}
		s += move;
		if (s == str.size())
			s = 0;
		if (s == -1)
			s = str.size() - 1;
		Sleep(1000);
	}
}