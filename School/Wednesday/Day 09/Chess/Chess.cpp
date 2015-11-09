#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

const int n = 8;

char s;
string str;
int istart, jstart, ifinish, jfinish, a [9][9];

void convert (char s, int i, int j)
{
	if (s == ".")
		a [i][j] = 0;

	if (s == "k")
		a [i][j] = -1;

	if (s == "K")
		a [i][j] = 1;

	if (s == "q")
		a [i][j] = -2;

	if (s == "Q")
		a [i][j] = 2;

	if (s == "r")
		a [i][j] = -3;

	if (s == "R")
		a [i][j] = 3;

	if (s == "n")
		a [i][j] = -4;

	if (s == "N")
		a [i][j] = 4;

	if (s == "b")
		a [i][j] = -5;

	if (s == "B")
		a [i][j] = 5;

	if (s == "p")
		a [i][j] = -6;

	if (s == "P")
		a [i][j] = 6;

	return 0;
}

void print (a [ifinish][jfinish])
{
	if (a [ifinish][jfinish] == -1)
		cout << "k";

	if (a [ifinish][jfinish] == 1)
		cout << "K";

	if (a [ifinish][jfinish] == -2)
		cout << "q";

	if (a [ifinish][jfinish] == 2)
		cout << "Q";

	if (a [ifinish][jfinish] == -3)
		cout << "r";

	if (a [ifinish][jfinish] == 3)
		cout << "R";

	if (a [ifinish][jfinish] == -4)
		cout << "n";

	if (a [ifinish][jfinish] == 4)
		cout << "N";

	if (a [ifinish][jfinish] == -5)
		cout << "b";

	if (a [ifinish][jfinish] == 5)
		cout << "B";

	if (a [ifinish][jfinish] == -6)
		cout << "p";

	if (a [ifinish][jfinish] == 6)
		cout << "P";

	return 0;
}	

int main ()
{

	freopen ("chess.in", "r", stdin);
	freopen ("chess.out", "w", stdout);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> s;
			convert (s, i, j);
		}	

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> str;
		istart = (int)str [1] - (int)"`";
		jstart = 9 - (int)str [2] - (int)"0";	
		ifinish = (int)str [3] - (int)"`";
		jfinish = 9 - (int)str [4] - (int)"0";
		a [ifinish][jfinish] = a [istart][jstart];
		a [istart][jstart] = 0;
		print (a [ifinish][jfinish]);
	}	

	return 0;

}	