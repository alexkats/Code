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

#define NAME "e"
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

int n, k;
double d [500][500];
double ans [500][500];

double solve (int a, int k)
{
	if (ans [a][k] > -0.5)
		return ans [a][k];

	if (k == 0)
		return (double) a;

	if (a == k)
		return 0.0;


	ans [a][k] = 0.0;
	double curr;

	rep(i, 1, n)
	{
		curr = 0.0;

		rep0(j, (min (i, k) + 1))
			curr += solve (max (a - k - i + j, k - j), (k - j)) * d [k][j] * d [a - k][i - j] / d [a][i];

		ans [a][k] = max (ans [a][k], curr);
	}

	return ans [a][k];
}	

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &k);

	d [0][0] = 1;

	rep0(i, n)
		rep0(j, (i + 1))
		{
			d [i + 1][j] += d [i][j];
			d [i + 1][j + 1] += d [i][j];
		}

	rep0(i, n)
		rep0(j, n)
			ans [i][j] = -1.0;

	int a = max ((n - k), k);
	double res = solve (a, k);

	printf ("%.9lf\n", res);	

	return 0;
}	