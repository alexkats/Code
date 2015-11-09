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
#include <memory>
#include <ctime>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "d"
#define INF 1000000000
#define EPS 0.000000001
#define mp make_pair
#define frs first
#define snd second
#define pb push_back
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif	

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

const int sz = 70;

int n, m;
int max_cost;
char a [sz][sz];
char used [sz][sz];
int ans;
int d [sz][sz];
int num [sz][sz];

void dfs (int x, int y, int next_x, int next_y, int cost)
{
	used [x][y] = 1;

	if (num [x][y] != -1)
	{
		max_cost = max (max_cost, cost);
		d [x][y] = 1;
	}
	else
		d [x][y] = 0;

	if ((x < n - 1) && (a [x + 1][y] == '|') && ((x + 2 != next_x) || (y != next_y)))
	{
		dfs (x + 2, y, x, y, cost + 1);
		d [x][y] |= d [x + 2][y];
	}

	if ((x > 0) && (a [x - 1][y] == '|') && ((x - 2 != next_x) || (y != next_y)))
	{
		dfs (x - 2, y, x, y, cost + 1);
		d [x][y] |= d [x - 2][y];
	}

	if ((y < m - 1) && (a [x][y + 1] == '-') && ((x != next_x) || (y + 2 != next_y)))
	{
		dfs (x, y + 2, x, y, cost + 1);
		d [x][y] |= d [x][y + 2];
	}

	if ((y > 0) && (a [x][y - 1] == '-') && ((x != next_x) || (y - 2 != next_y)))
	{
		dfs (x, y - 2, x, y, cost + 1);
		d [x][y] |= d [x][y - 2];
	}

	ans += d [x][y] * 2;
}	

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);
	memset (used, 0, sizeof (used));
	memset (num, -1, sizeof (num));

	scanf ("%d %d\n", &n, &m);
	int q = 0;

	rep0(i, n)
	{
		rep0(j, m)
		{
			char c;
			scanf ("%c", &c);

			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
			{
				num [i][j] = q;
				q++;
			}
		}

		scanf ("\n");
	}

	rep0(i, n)
	{
		rep0(j, m)
			scanf ("%c", &a [i][j]);

		scanf ("\n");
	}

	if (!q)
	{
		puts ("0");
		return 0;
	}

	ans = 0;
	max_cost = 0;
	dfs (0, 0, -1, -1, 0);
	ans -= max_cost + 2;

	rep0(i, n)
		rep0(j, m)
			if (!used [i][j] && num [i][j] != -1)
			{
				puts ("NIE");
				return 0;
			}	

	printf ("%d\n", ans);	

	return 0;
}	