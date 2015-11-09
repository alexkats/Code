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
#include <ctime>
#include <cctype>
#include <cassert>
#include <memory>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "c"
#define INF 1000000000
#define EPS 0.000000001
#define pb push_back
#define mp make_pair
#define frs first
#define snd second
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

char good = 0;

void dfs (int i, int j, int prev)
{
	if (a [i][j] != (prev + 1) % 4)
		return d [i][j] = (a [i][j] == 3) ? 1 : 0;

		

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d %d", &n, &m);

	rep0(i, n)
	{
		rep0(j, m)
		{
			scanf ("%c", &c);

			if (c == 'D')
				a [i][j] = 0;
			else if (c == 'I')
				a [i][j] = 1;
			else if (c == 'M')
				a [i][j] = 2;
			else
				a [i][j] = 3;
		}	

		scanf ("\n");
	}

	rep0(i, n)
		rep0(j, m)
		{
			dfs (i, j, 3);
			d [i][j] = res;
		}

	if (!good)
	{
		puts ("Poor Dima!");
		return 0;
	}	

	int ans = INF;	

	rep0(i, n)
		rep0(j, m)
			ans = min (ans, d [i][j]);	

	return 0;
}	