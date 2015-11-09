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

string s;
int a [100000];

int main ()
{
	srand (time (0));

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	cin >> s;
	int n = (int) s.length ();

	rep0(i, n)
		a [i] = (int) (s [i]) - 48;

	ll ans = 1ll;
	int i = 1;

	while (i < n)
	{
		int curr = 1;

		while (i < n && a [i - 1] + a [i] == 9)
			curr++, i++;

		if (curr % 2)
			ans *= (curr + 1ll) / 2ll;

		i++;
	}

	printf (lld"\n", ans);	

	return 0;
}	