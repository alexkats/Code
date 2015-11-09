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

#define NAME "i"
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

int n, m, k;
int w [1000000], t [100000];
ll d [1000000];

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d%d%d", &n, &m, &k);

	rep0(i, n)
		scanf ("%d", &w [i]);

	rep0(i, m)
		scanf ("%d", &t [i]);

	int q = n - 1;
	int curr = 0;

	repd0(i, n)
	{
		while (q >= 0 && curr <= k)
		{
			curr += w [q];
			q--;
		}

		d [i] = q + 1;
		curr -= w [i];
	}

	q = 0;
	int curr_time = 1;
	t [m] = INF * 2;
	m++;

	rep0(i, m)
	{
		q += t [i] - curr_time;

		if (q >= n)
		{
			cout << t [i] - (q - n) - 1 << endl;
			return 0;
		}

		if (q != 0)
			q = d [q - 1];

		curr_time = t [i] + 1;
	}	

	return 0;
}	