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

#define NAME "a"
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

int n, p;
string s [1010];
vector <int> g [1010];

void dfs (int v, int l)
{
	rep0(i, l)
		printf (".");

	cout << s [v] << endl;

	rep0(i, (int) g [v].size ())
		dfs (g [v][i], l + 1);
}	

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
	{
		scanf ("%d", &p);
		getline (cin, s [i]);
		getline (cin, s [i]);

		if (p != 0)
			g [p - 1].pb (i);
	}

	dfs (0, 0);	

	return 0;
}	