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
 
#define NAME "meeting"
#define INF 1000000000.0
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

int n;
double angle [20000];
double curr;
double ans = 0.0;
double res = INF;

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
		scanf ("%lf", &angle [i]);

	rep0(i, n)
	{
		curr = 0;

		rep0(j, n)
			curr += min (abs (angle [i] - angle [j]), abs (360 - abs (angle [i] - angle [j])));

		res <= curr ? ans = ans : ans = angle [i];
		res = min (res, curr);
	}

	printf ("%.9lf\n", ans);	

	return 0;

}	