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

#define NAME "binstr"
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

int d [1000001];
int n, p;

int solve (int n)
{
	if (d [n] != -1)
		return d [n];

	if (n == 1)
		return d [n] = 2 % p;

	if (n % 2 == 0)
		d [n] = (solve (n - 1) * 2 - solve (n / 2) + p) % p;
	else
		d [n] = solve (n - 1) * 2 % p;

	return d [n];
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);	

	scanf ("%d%d", &n, &p);
	memset (d, -1, sizeof (d));
	printf ("%d\n", solve (n));

	return 0;
}	