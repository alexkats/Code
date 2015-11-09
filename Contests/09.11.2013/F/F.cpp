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

int n, k, p;
ll q = 0;
int ans [100000];

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &k);
	scanf ("%d", &p);

	rep0(i, (n - k))
		ans [i] = 1;

	int curr = 0;

	rep(i, (n - k), n)
		if ((curr * 100) >= p * i)
			ans [i] = ans [i - 1];
		else
		{
			ans [i] = ans [i - 1] + 1;
			curr = i;
		}

	rep0(i, n)
		q += ans [i];

	printf ("%I64d\n", q);

	rep0(i, n)
		printf ("%d ", ans [i]);

	printf ("\n");	

	return 0;
}	