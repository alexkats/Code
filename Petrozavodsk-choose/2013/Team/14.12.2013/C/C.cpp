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
 
#define NAME "c"
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
#define N 50000005

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif	
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld; 
 
using namespace std;

int a [N];
ll n;
int curr = 1;

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf (lld, &n);

	rep(i, 1, N)
	{
		if (!a [i])
			a [i] = i;

		int tmp = a [i];


		while ((curr <= N) && (tmp > 0))
		{
			a [curr] = i;
			curr++;
			tmp--;
		}
	}

	ll v = 1;
	ll q = 1;
	ll k = 1;

	rep(j, 1, N)
	{
		ll m = v + k * j;

		if (n < m)
		{
			ll p = (n - v) / (j * 1ll);
			printf (lld"\n", q + p);
			return 0;
		}

		ll nq = q + k;
		ll nk = a [j + 1];
		v = m;
		q = nq;
		k = nk;
	}	

	return 0;

}	
