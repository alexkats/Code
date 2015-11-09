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

#define NAME "h"
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

int a, b, n;
int t [10000], p [10000];
int l [10000], r [10000];
int q1 = 0;
int q2 = 0;
int prev1 [10000], prev2 [10000];
vector <int> g [1000];
bool used [10000];

bool dfs (int v)
{
	if (used [v])
		return false;

	used [v] = true;
	int to = -1;

	rep0(i, (int) (g [v].size ()))
	{
		to = g [v][i];

		if (l [to] == -1 || dfs (l [to]))
		{
			l [to] = v;
			return true;
		}
	}

	return false;
}	

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &a, &b);
	scanf ("%d", &n);

	rep0(i, n)
	{
		scanf ("%d%d", &t [i], &p [i]);

		if (p [i] == 0)
		{
			q1++;
			prev1 [q1 - 1] = i;
			r [q1 - 1] = t [i];
		}
	}

	rep0(i, n)
		if (p [i] == 1)
		{
			rep0(j, q1)
				if (r [j] <= t [i] && ((t [i] - r [j]) <= b || (t [i] - r [j]) >= a))
					g [j].pb (q2);

			q2++;
			prev2 [q2 - 1] = i;
		}

	rep0(i, q2)
		l [i] = -1;

	rep0(i, q1)
	{
		rep0(j, q1)
			used [j] = false;

		dfs (i);
	}

	rep0(i, q2)
		if (l [i] == -1)
		{
			printf ("Liar\n");
			return 0;
		}

	printf ("No reason\n");

	rep0(i, q2)
		printf ("%d %d\n", t [prev1 [l [i]]], t [prev2 [i]]);	

	return 0;
}	