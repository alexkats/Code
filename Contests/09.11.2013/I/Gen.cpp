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

#define NAME "right"
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
	srand (time (0));

	freopen (NAME".in", "w", stdout);

	int n = 1 + rand () % (10);
	int m = 1 + rand () % (10);
	int k = 1 + rand () % (10);

	printf ("%d %d %d\n", n, m, k);

	rep0(i, n)
	{
		int a = 1 + rand () % (10);
		printf ("%d\n", a);
	}

	int prev = 1;

	rep0(i, m)
	{
		int a = prev + rand () % (10);
		prev = a;
		printf ("%d\n", a);
	} 	

	return 0;
}	