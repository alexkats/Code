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

#define NAME "f"
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

int n, t;
bool g [310][310];
bool a [310];
bool ans [310];
int p [310];

void mult (bool a [310][310], bool b [310][310], bool c [310][310])
{
	bool ans [310][310] = {0};

	rep0(i, n)
		rep0(j, n)
			rep0(k, n)
				ans [i][j] ^= a [i][k] & b [k][j];

	rep0(i, n)
		rep0(j, n)
			c [i][j] = ans [i][j];
}

void pw (bool g [310][310], int a)
{
	bool d [310][310] = {0};

	rep0(i, n)
		d [i][i] = 1;

	while (a != 0)
	{
		if (a & 1)
			mult (d, g, d);

		mult (g, g, g);

		a >>= 1;
	}

	rep0(i, n)
		rep0(j, n)
			g [i][j] = d [i][j];
}	

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
		rep0(j, n)
			scanf ("%d", &g [i][j]);

	rep0(i, n)
		scanf ("%d", &a [i]);

	scanf ("%d", &t);

	pw (g, t);

	rep0(i, n)
		p [i] = i;

	bool fl = false;

	rep0(i, n)
	{
		if (!g [i][i])
		{
			int num = -1;

			rep(j, i + 1, n)
				if (g [i][j])
				{
					num = j;
					break;
				}

			if (num == -1)
			{
				if (a [i])
				{
					puts ("none");
					return 0;
				}

				fl = true;
				continue;
			}

			swap (p [i], p [num]);

			rep0(j, n)
				swap (g [j][i], g [j][num]);
		}

		rep(j, i + 1, n)
			if (g [j][i])
			{
				rep0(k, n)
					g [j][k] ^= g [i][k];

				a [j] ^= a [i];
			}
	}

	if (fl)
	{
		puts ("ambiguous");
		return 0;
	}

	repd0(i, n)
		repd(j, i + 1, n)
			if (g [i][j])
				a [i] ^= a [j];

	rep0(i, n)
		ans [p [i]] = a [i];

	rep0(i, n)
		printf ("%d ", ans [i]);

	printf ("\n");	

	return 0;
}	