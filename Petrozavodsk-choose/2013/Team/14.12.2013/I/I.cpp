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
 
#define NAME "i"
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

const int N = 1000005;

int n, m, k;
int p [N];
int a [N];
int b [N];
int prev [N];
vector <int> pr [N];
int ans [N];
int colour [N];

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);
	memset (prev, -1, sizeof (prev));

	scanf ("%d%d%d", &n, &m, &k);

	rep0(i, n)
	{
		scanf ("%d", &p [i]);
		ans [i] = p [i];
		pr [p [i]].pb (i);
	}

	rep0(i, N)
		colour [i] = i;	

	rep0(i, m)
		scanf ("%d%d", &a [i], &b [i]);

	rep0(i, m)
	{
		colour [a [m - i - 1]] = colour [b [m - i - 1]];
		prev [m - i - 1] = colour [b [m - i - 1]];
	}

	rep0(i, m)
	{
		rep0(j, (int) pr [a [i]].size ())
			ans [pr [a [i]][j]] = prev [i];

		pr [a [i]].clear ();
	}	

	rep0(i, n)
		printf ("%d ", ans [i]);

	printf ("\n");	

	return 0;

}	
