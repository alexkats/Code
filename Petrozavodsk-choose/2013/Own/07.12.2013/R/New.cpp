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
#include <cctype>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>
 
#define NAME "smallnim"
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

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	int n;
	int a [100];

	scanf ("%d", &n);

	rep0(i, n)
		scanf ("%d", &a [i]);

	sort (a, a + n);
	int q = 0;

	rep0(i, n)
		if (a [i] == 1)
			q++;

	int ans = 0;
	bool ok;
	q % 2 == 0 ? ok = 1 : ok = 0;

	ans = a [0] - 1;
	ans == 0 ? ans++ : ans = ans;

	if (ok)
		printf ("YES\n%d\n", ans);
	else
		puts ("NO");	

	return 0;

}	