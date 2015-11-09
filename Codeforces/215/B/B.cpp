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

#define NAME "b"
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

int n, m;
int a [100000];
int ans [100000];
char used [100000];
int l;	

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &m);

	rep0(i, n)
		scanf ("%d", &a [i]);

	used [a [n - 1]] = 1;
	ans [n - 1] = 1;	

	repd(i, 0, n - 1)
	{
		if (!used [a [i]])
		{
			used [a [i]] = 1;
			ans [i] = ans [i + 1] + 1;
		}
		else
		{
			ans [i] = ans [i + 1];
		}
	}	

	rep0(i, m)
	{
		scanf ("%d", &l);
		printf ("%d\n", ans [l - 1]);
	}	

	return 0;
}	