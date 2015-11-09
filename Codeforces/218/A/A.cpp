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
#include <memory>
#include <ctime>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "a"
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

int n, k;
int a [100];
int q1 [100], q2 [100];

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &k);
	memset (q1, 0, sizeof (q1));
	memset (q2, 0, sizeof (q2));

	rep0(i, n)
		scanf ("%d", &a [i]);

	rep0(i, n)
		(a [i] == 1) ? q1 [i % k]++ : q2 [i % k]++;

	int ans = 0;

	rep0(i, n)
		(q1 [i] < q2 [i]) ? ans += q1 [i] : ans += q2 [i];

	printf ("%d\n", ans);	

	return 0;
}	