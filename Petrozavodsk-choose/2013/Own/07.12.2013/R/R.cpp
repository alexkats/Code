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

int ans, n;
int a [100];

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	bool ok = 0;
	bool fl = 1;
	int curr = 0;

	rep0(i, n)
		scanf ("%d", &a [i]);

	rep0(i, n)
	{
		if (curr)
		{
			curr--;
			continue;
		}	

		if (a [i] != 1 && !ok)
		{
			ok = 1;
			ans = a [i] - 1;
			continue;	
		}

		fl = !fl;
		curr++;	
	}

	if (ok)
		printf ("YES\n%d\n", ans);
	else if (fl)
		printf ("YES\n%d\n", 1);
	else	
		puts ("NO");	

	return 0;

}	