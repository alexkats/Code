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
#include <ctime>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "chords"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a
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

const int N = (int) (1e7);

int n;
int a [N];
int prev [N], next [N];
int t [N];
int ans [N];	

void update (int v, int l, int r, int key, int val)
{
	if (l == r)
		t [v] = val;
	else
	{
		int m = (l + r) / 2;

		if (key <= m)
			update (v * 2, l, m, key, val);
		else
			update (v * 2 + 1, m + 1, r, key, val);

		t [v] = t [v * 2] + t [v * 2 + 1];
	}
}

int solve (int v, int tl, int tr, int l, int r)
{
	if (l > r)
		return 0;

	if (tl == l && r == tr)
		return t [v];

	int tm = (tl + tr) / 2;
	int res1 = solve (v * 2, tl, tm, l, min (tm, r));
	int res2 = solve (v * 2 + 1, tm + 1, tr, max (l, tm + 1), r);
	int ans = res1 + res2;

	return ans;
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);	

	scanf ("%d", &n);
	memset (prev, -1, sizeof (prev));
	memset (ans, 0, sizeof (ans));
	memset (t, 0, sizeof (t));

	rep0(i, n * 4)
		if (i < n * 2)
			scanf ("%d", &a [i]);
		else
			a [i] = a [i - n * 2];

	rep0(i, n * 4)
	{
		if (prev [a [i]] != -1)
		{
			update (1, 0, n * 4 - 1, i, -1);
			next [prev [a [i]]] = i;
		}
		else
			update (1, 0, n * 4 - 1, i, 1);

		prev [a [i]] = i;
	}

	rep0(i, n * 2)
	{
		ans [a [i]] += solve (1, 0, n * 4 - 1, i, next [i]);
		update (1, 0, n * 4 - 1, next [i], 1);
	}

	rep0(i, n)
		printf ("%d\n", ans [i + 1] / 2);	

	return 0;
}	