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

#define NAME "c"
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

int n, w;
int ans = 0;
int x [100010], y [100010];
map <pair <int, int>, int> k;

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
	{
		scanf ("%d%d%d", &x [i], &y [i], &w);
		k [mp (x [i], y [i])] += w;
	}

	rep0(i, n)
	{
		ans = max (ans, (k [mp (x [i], y [i])] + k [mp (x [i] + 1, y [i])] + k [mp (x [i], y [i] + 1)] + k [mp (x [i] + 1, y [i] + 1)]));
		ans = max (ans, (k [mp (x [i], y [i])] + k [mp (x [i] - 1, y [i])] + k [mp (x [i], y [i] + 1)] + k [mp (x [i] - 1, y [i] + 1)]));
	}

	printf ("%d / 1\n", ans);	

	return 0;
}	