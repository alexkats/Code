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
#include <ctime>
#include <cctype>
#include <cassert>
#include <memory>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "foremen"
#define INF 1000000000
#define EPS 0.000000001
#define pb push_back
#define mp make_pair
#define frs first
#define snd second
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)
#define N 105

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int n, k;
int a [N][N];
int d [N][N][N * 2];
int prev [N][N][N * 2];
vector <int> cnt;
int q [N], ans [N];
int num [N];

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);
	memset (d, N, sizeof (d));
	memset (q, -1, sizeof (q));

	scanf ("%d %d", &n, &k);

	rep0(i, n)
		rep0(j, n)
			scanf ("%d", &a [i][j + 1]);	

	d [0][0][N] = 0;	

	rep0(i, n)
		rep0(j, n)
			rep0(r, N * 2)
			{
				if (d [i + 1][j][r + 1] > d [i][j][r])
				{
					d [i + 1][j][r + 1] = d [i][j][r];
					prev [i + 1][j][r + 1] = r;
				}
   	
				rep0(l, n)
					if (l <= r)
						if (d [i + 1][j + 1][r - l] > d [i][j][r] + a [i][l + 1])
						{
							d [i + 1][j + 1][r - l] = d [i][j][r] + a [i][l + 1];
							prev [i + 1][j + 1][r - l] = r;
						}
			}	

	printf ("%d\n", d [n][k][N]);	

	int i = n;
	int j = k;
	int r = N;

	while (1)
	{
		int curr = prev [i][j][r];

		if (curr >= r)
		{
			q [i - 1] = curr - r;
			num [i - 1] =  i - 1;
			cnt.pb (i);
			j--;
		}

		i--;
		r = curr;	

		if (!i)
			break;
	}

	sort (cnt.begin (), cnt.end ());

	rep0(i, (int) cnt.size ())
		ans [cnt [i] - 1] = i + 1;

	int curr = 0;

	rep0(i, n)
		if (q [i] == -1)
		{
			while (q [curr] <= 0)
				curr++;

			num [i] = curr;
			q [curr]--;
		}

	rep0(i, (int) cnt.size ())
		printf ("%d ", cnt [i]);

	printf ("\n");

	rep0(i, n)
		printf ("%d ", ans [num [i]]);

	printf ("\n");	

	return 0;
}	