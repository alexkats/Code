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

#define NAME "b"
#define INF 1000000000
#define EPS 0.000000001
#define INFLONG 1000000000000000000
#define pb push_back
#define mp make_pair
#define frs first
#define snd second
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

int n;
ll a [100010], b [100010];

int main ()
{
	srand (time (0));

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
		scanf (lld, &a [i]);

	rep0(i, n)
		scanf (lld, &b [i]);

	ll ans = 0ll;

	rep0(i, n)
	{
		if (a [i] * 2ll < b [i])
		{
			ans--;
			continue;
		}

		if (a [i] * 2ll == b [i])
		{
			ans += 1ll * a [i] * a [i];
			continue;
		}

		if (b [i] % 2 == 0)
		{
			ans += 1ll * (b [i] / 2) * (b [i] / 2);
			continue;
		}

		ans += 1ll * (b [i] / 2) * (b [i] / 2 + 1);
	}

	printf (lld"\n", ans);	

	return 0;
}	