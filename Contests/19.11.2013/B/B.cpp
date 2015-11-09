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
#include <map>
#include <cassert>
#include <ctime>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "b"
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

const int pace [4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int W, H, n, xs, ys, xf, yf, x, y, F, S, t, len, curr, xx, yy, v, u;
int a [600][600][4];
int dist [360000];
vector <int> e [360000];
vector <int> w [360000];
string s;
set <pair <int, int> > k;

bool tr (int x, int y)
{
	return (0 <= x && x < W && 0 <= y && y < H);
}

int modify (int x, int y)
{
	return x * (H + 1) + y;
}	

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d%d%d", &W, &H, &n);
	scanf ("%d%d%d%d", &xs, &ys, &xf, &yf);

	S = modify (xs, ys);
	F = modify (xf, yf);

	rep0(i, n)
	{
		scanf ("%d%d%d", &x, &y, &t);
		cin >> s;

		int len = s.length ();

		while (t --> 0)
		{
			rep0(j, len)
			{
				curr = -1;

				if (s [j] == 'U')
					curr = 0;
				else if (s [j] == 'D')
					curr = 1;
				else if (s [j] == 'L')
					curr = 2;
				else
					curr = 3;

				xx = x + pace [curr][0];
				yy = y + pace [curr][1];

				if (!tr (xx, yy))
					continue;

				a [x][y][curr]++;
				a [xx][yy][curr ^ 1]++;
				x = xx;
				y = yy;
			}
		}
	}

	rep0(i, W)
		rep0(j, H)
		{
			v = modify (i, j + 1);
			u = modify (i + 1, j + 1);
			e [v].pb (u);
			w [v].pb (a [i][j][1]);
			e [u].pb (v);
			w [u].pb (a [i][j][1]);
			v = modify (i + 1, j);
			e [v].pb (u);
			w [v].pb (a [i][j][3]);
			e [u].pb (v);
			w [u].pb (a [i][j][3]);
		}

	rep0(i, W)
	{
		v = modify (i, 0);
		u = modify (i + 1, 0);
		e [v].pb (u);
		w [v].pb (0);
		e [u].pb (v);
		w [u].pb (0);
	}

	rep0(i, H)
	{
		v = modify (0, i);
		u = modify (0, i + 1);
		e [v].pb (u);
		w [v].pb (0);
		e [u].pb (v);
		w [u].pb (0);
	}

	memset (dist, 63, sizeof (dist));

	k.insert (mp (0, S));
	dist [S] = 0;

	while (!k.empty ())
	{
		v = k.begin () -> second;
		k.erase (k.begin ());

		rep0(i, (int) (e [v].size ()))
		{
			if (dist [e [v][i]] > dist [v] + w [v][i])
			{
				k.erase (mp (dist [e [v][i]], e [v][i]));
				dist [e [v][i]] = dist [v] + w [v][i];
				k.insert (mp (dist [e [v][i]], e [v][i]));
			}
		}
	}

	printf ("%d\n", dist [F]);	

	return 0;
}	