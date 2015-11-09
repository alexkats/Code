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

#define NAME "i"
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

ll ans = 0;
int n, m, k;
int w [100000];
int t [100000];

int main ()
{
	freopen ("right.in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d%d", &n, &m, &k);

	rep0(i, n)
		scanf ("%d", &w [i]);

	rep0(i, m)
		scanf ("%d", &t [i]);

	int prev = 0;	

	rep0(i, m)
	{
		if (t [i] <= (n - prev))
			ans += t [i] - prev;	
		else
			break;

		prev = -1;
		ll curr = 0;	
		                                                                   /*4 6 1 8 4     5 7 9 11 13 13*/
		repd0(j, t [i] - 1)
			if (curr + w [j] >= k)
			{
				prev = j;
				break;
			}
			else
			{
				curr += w [j];
			}	

		if (prev == -1)
			prev++;	
	}

	ans += n - prev;

	printf ("%I64d\n", ans);	

	return 0;
}	