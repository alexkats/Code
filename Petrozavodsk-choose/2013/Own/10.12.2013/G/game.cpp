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

#define NAME "game"
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

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int n, k;
int a [100000];
int curr [500000];
int t [500000];

void update_one (int v, int l, int r)
{
	if (curr [v] != -1)
	{
		if (l != r)
		{
			curr [v * 2] = curr [v];
			curr [v * 2 + 1] = curr [v];
		}	

		t [v] = curr [v];
		curr [v] = -1;
	}
}	

void update (int v, int tl, int tr, int l, int r, int val)
{
	if (l > r)
		return;
	
	update_one (v, tl, tr);

	if (tl == l && tr == r)
	{
		curr [v] = val;
		update_one (v, tl, tr);
		return;
	}

	int tm = (tl + tr) / 2;
	update (v * 2, tl, tm, l, min (tm, r), val);
	update (v * 2 + 1, tm + 1, tr, max (l, tm + 1), r, val);
}

int solve (int v, int l, int r, int key)
{
	update_one (v, l, r);

	if (l == r)
		return t [v];

	int m = (l + r) / 2;

	if (key <= m)
		return solve (v * 2, l, m, key);
	else
		return solve (v * 2 + 1, m + 1, r, key);
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	memset (t, -1, sizeof (t));
	memset (curr, -1, sizeof (curr));

	scanf ("%d%d", &n, &k);

	rep0(i, n)
		scanf ("%d", &a [i]);

	update (1, 0, n - 1, 0, 0, 0);

	rep0(i, n)
	{
		if (n <= (i + k))
			continue;

		int res = solve (1, 0, n - 1, i);

		if (res == -1)
			continue;

		update (1, 0, n - 1, i + k, min (i + a [i], n - 1), i);
	}

	int res = solve (1, 0, n - 1, n - 1);

	if (res == -1)
	{
		puts ("IMPOSSIBLE");
		return 0;
	}

	puts ("POSSIBLE");

	vector <int> ans;
	int prev = n - 1;
	ans.pb (prev);

	while (prev)
	{
		prev = solve (1, 0, n - 1, prev);
		ans.pb (prev);
	}

	printf ("%d\n", (int) ans.size () - 1);
	reverse (ans.begin (), ans.end ());

	rep0(i, (int) ans.size () - 1)
		printf ("%d %d\n", ans [i] + 1, ans [i + 1] - ans [i]);	

	return 0;
}	