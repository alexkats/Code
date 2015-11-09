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

#define NAME "c"
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

char s [100000];
int x [100000], y [100000], z [100000];

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%s", s);

	int n = strlen (s);
	x [0] = y [0] = z [0] = 0;

	rep0(i, n)
	{
		x [i + 1] = x [i] + (s [i] == 'x');
		y [i + 1] = y [i] + (s [i] == 'y');
		z [i + 1] = z [i] + (s [i] == 'z');
	}

	int T;
	scanf ("%d", &T);

	rep0(o, T)
	{
		int a, b;
		scanf ("%d%d", &a, &b);

		int new_x = x [b] - x [a - 1];
		int new_y = y [b] - y [a - 1];
		int new_z = z [b] - z [a - 1];
		char ok = 1;

		if (abs (new_x - new_y) > 1 || abs (new_x - new_z) > 1 || abs (new_y - new_z) > 1)
			ok = 0;

		if (new_x + new_y + new_z <= 2)
			ok = 1;

		puts (ok ? "YES" : "NO");
	}	

	return 0;
}	