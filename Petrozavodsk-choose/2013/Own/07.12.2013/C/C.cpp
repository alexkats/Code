#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <cassert>
#include <cctype>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>
 
#define NAME "chess"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a
#define mp make_pair
#define pb push_back
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld; 
 
using namespace std;

const int sz = 8;

char a [sz][sz];
int n;
string s;

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, sz)
		rep0(j, sz)
			a [i][j] = '.';

	rep0(i, sz)
	{
		a [1][i] = 'P';
		a [6][i] = 'p';
	}

	a [0][0] = a [0][7] = 'R';
	a [7][0] = a [7][7] = 'r';
	a [0][1] = a [0][6] = 'N';
	a [7][1] = a [7][6] = 'n';
	a [0][2] = a [0][5] = 'B';
	a [7][2] = a [7][5] = 'b';
	a [0][3] = 'Q';
	a [7][3] = 'q';
	a [0][4] = 'K';
	a [7][4] = 'k';
	int curr = 0;
	char to_type;
	int from_i, from_j, to_i, to_j;

	rep0(i, n)
	{
		cin >> s;

		if (s.length () == 3)
		{
			if (curr == 0)
			{
				a [0][6] = 'K';
				a [0][5] = 'R';
				a [0][4] = a [0][7] = '.';
				curr++;
				continue;
			}
			else
			{
				a [7][6] = 'k';
				a [7][5] = 'r';
				a [7][4] = a [7][7] = '.';
				curr--;
				continue;
			}
		}

		if (s.length () == 5)
		{
			if (curr == 0)
			{
				a [0][2] = 'K';
				a [0][3] = 'R';
				a [0][0] = a [0][4] = '.';
				curr++;
				continue;
			}
			else
			{
				a [7][2] = 'k';
				a [7][3] = 'r';
				a [7][0] = a [7][4] = '.';
				curr--;
				continue;
			}
		}	

		from_j = (int) (s [1] - 'a');
		from_i = (int) (s [2] - '1');
		to_j = (int) (s [4] - 'a');
		to_i = (int) (s [5] - '1');

		if (s.length () == 7)
			to_type = s [6];
		else
			to_type = '.';

		swap (a [from_i][from_j], a [to_i][to_j]);
		a [from_i][from_j] = '.';

		if (to_type != '.')
			a [to_i][to_j] = to_type;

		curr++;
		curr %= 2;
	}

	repd0(i, sz)
	{
		rep0(j, sz)
			printf ("%c", a [i][j]);

		printf ("\n");
	}	

	return 0;

}	