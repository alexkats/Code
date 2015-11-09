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

#define NAME "black-white-balls"
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
#define N 105

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif	

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int n, best_a, best_b;
int black, white;
double f [N][N];
double p;

ld choose (int n, int k)
{
	if (k > n)
		return 0;

	if (k == 0 || n == k)
		return 1;

	return f [n - 1][k - 1] + f [n - 1][k];
}	

int main ()
{	
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	rep0(i, N)
		rep0(j, N)
			f [i][j] = choose (i, j);

	scanf ("%d %d %d", &n, &black, &white);
	cin >> p;

	best_a = -INF;
	best_b = INF;

	rep0(i, n + 1)
		rep(j, i, n + 1)
		{
			double tmp = 0;

			rep(k, i, j + 1)
				tmp += f [k][black] * f [n - k][white];

			if (p * f [n][black + white] * (double) (n + 1) - (tmp * (double) (black + white + 1) * 100.0) < EPS)
				if ((best_b - best_a) > (j - i))
				{
					best_a = i;
					best_b = j;
				}
		}

	printf ("%d %d\n", best_a, best_b);	

	return 0;
}	