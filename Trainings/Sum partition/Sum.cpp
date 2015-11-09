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
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "sum"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a
#define mp make_pair
#define pb push_back
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)

#ifdef WIN32
	#define I64d "%I64d"
#else
	#define I64d "%lld"
#endif	

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

ll ans [1010], d [1010][1010], n;

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%I64d", &n);

	rep(i, 1, (n + 1))
		d [0][i] = 0;

	ans [1] = 1;
	d [1][1] = 1;

	rep(i, 2, (n + 1))
	{
		ans [i] = 0;

		repd(j, (int) (i / 2), i)
			ans [i] += ans [j] - d [i - j - 1][j];

		ans [i]++;	

		rep(j, 1, (int) (i / 2 + 1))
			d [j][i] = d [j - 1][i] + ans [i - j] - d [j - 1][i - j];

		rep(j, (int) (i / 2 + 1), i)
			d [j][i] = d [j - 1][i];

		d [i][i] = d [i - 1][i] + 1;
	}

	printf ("%I64d\n", ans [n]);	

	return 0;
}	