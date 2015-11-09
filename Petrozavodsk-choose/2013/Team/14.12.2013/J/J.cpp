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
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>
 
#define NAME "j"
#define INF 1000000000000000000
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

int n, k;
int num [1000005];
ll res [1000005];
vector <int> g [1000005];
char used [1000005];
int next [1000005];

bool oper (int a, int b)
{
	return g [a].size () > g [b].size ();
}

ll sum (int l, int r, int key)
{
	ll sum = 0ll;

	rep(i, l, r + 1)
		sum += g [key][i];

	return sum;
}	

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);
	memset (used, 0, sizeof (used));

	scanf ("%d", &n);

	rep0(i, n)
	{
		scanf ("%d", &k);

		rep0(j, k)
		{
			int a;
			scanf ("%d", &a);
			g [i].pb (a);
		}

		reverse (g [i].begin (), g [i].end ());
	}

	rep0(i, n)
	{
		num [i] = i;
		used [(int) g [i].size ()] = 1;
	}

	sort (num, num + n, oper);

	int m = (int) g [num [0]].size ();

	rep(i, 1, m + 1)
		res [i] = -INF;

	int prev = 0;

	rep(i, 1, m + 1)
	{
		if (!used [i])
			continue;

		next [i] = prev;
		prev = i;
	}

	rep(i, 1, m + 1)
		rep0(j, n)
		{
			if ((int) g [num [j]].size () < i)
				break;

			if (!used [i])
				continue;

			res [i] = max (res [i], res [next [i]] + sum ((int) g [num [j]].size () - i, (int) g [num [j]].size () - 1 - next [i], num [j]));
		}

	ll ans = -INF;

	rep(i, 1, m + 1)
		ans = max (ans, res [i]);

	printf (lld"\n", ans);
			

	return 0;

}	
