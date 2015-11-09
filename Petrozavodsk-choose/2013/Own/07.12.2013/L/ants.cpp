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
 
#define NAME "ants"
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
int x [100000], y [100000];
char k;
int st [100000];

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &m);

	rep0(i, n)
	{
		scanf ("%d %d %c", &x [i], &y [i], &k);
		
		if (k == 'N')
			st [i] = 0;
		else if (k == 'S')
			st [i] = 1;
		else if (k == 'W')
			st [i] = 2;
		else
			st [i] = 3;
	}

	int ans = 6 * m * m;
	int v = 0;
	int h = 0;
	bool used_v [15001] = {0};
	bool used_h [15001] = {0};

	rep0(i, n)
		if (!used_h [y [i]] && st [i] > 1)
		{
			used_h [y [i]] = 1;
			h++;
		}
		else if (!used_v [x [i]] && st [i] < 2)
		{
			used_v [x [i]] = 1;
			v++;
		}

	ans -= 4 * h * m;
	ans -= 4 * v * m;
	ans += 2 * v * h;

	printf ("%d\n", ans);

	return 0;

}	