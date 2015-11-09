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
 
#define NAME "bestcomb"
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
int ans = 0;
int a [2000][2000];
int d [2000][2000];

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &m);

	rep0(i, n)
		rep0(j, m)
			scanf ("%d", &a [i][j]);

	repd0(i, n)
		repd0(j, m)
			if (j == m - 1)
			{
				if (a [i][j] == 0)
					d [i][j] = 1;
				else
					d [i][j] = 0;	
			}	
			else if (a [i][j] == 0)
				d [i][j] = d [i][j + 1] + 1;
			else
				d [i][j] = 0;	

	rep0(i, m)
	{
		int curr = 0;
		int prev = 0;
		int cur = 0;

		while (1)
		{
			curr = 0;

			rep(j, prev, n)
			{
				if (a [j][i] == 1)
				{
					cur = j;
					break;
				}

				if (j == n - 1 && a [j][i] == 0)
					cur = n;
			}	

			rep(j, prev, cur)
				curr += d [j][i];

			prev = ++cur;

			ans = max (ans, curr);

			if (cur >= n)
				break;
		}	

		ans = max (ans, curr);
	}

	printf ("%d\n", ans);	

	return 0;

}	