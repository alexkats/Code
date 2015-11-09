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

ll ans1 = 0;
ll ans2 = 0;
int a [10000];
int n, k;

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &k);

	rep0(i, n)
		scanf ("%d", &a [i]);

	rep0(i, n)
	{
		if (a [i] == k)
			continue;

		if (a [i] < k)
		{
			ans2 += k - a [i];
			continue;
		}

		ans1 += a [i] - k;
	}

	printf ("%I64d %I64d", ans1 , ans2);	

	return 0;
}	