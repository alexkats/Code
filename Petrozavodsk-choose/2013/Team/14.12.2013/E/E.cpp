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
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>
 
#define NAME "e"
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

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif	
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld; 
 
using namespace std;

ll a [1005][1005], row [1005];
ll q1 [1005], q2 [1005];
ll sum;
int n, curr, cur;
ll main_diag, sec_diag;	

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);
	memset (row, 0ll, sizeof (row));

	scanf ("%d", &n);

	rep(i, 1, n + 1)
		rep(j, 1, n + 1)
		{
			scanf (lld, &a [i][j]);
			row [i] += a [i][j];	
		}

	curr = 0;
	cur = 0;
	main_diag = 0ll;
	sec_diag = 0ll;	

	rep(i, 1, n + 1)
	{
		main_diag += a [i][i];

		if (!a [i][i])
		{
			curr++;
			q1 [curr] = i;
		}
	}

	rep(i, 1, n + 1)
	{
		sec_diag += a [i][n - i + 1];

		if (!a [i][n - i + 1])
		{
			cur++;
			q2 [cur] = i;
		}
	}
	
	if (!curr)
	{
		rep(i, 1, n + 1)
		{
			rep(j, 1, n + 1)
			{
				if (!a [i][j])
					a [i][j] = main_diag - row [i];

				printf (lld" ", a [i][j]);
			}

			printf ("\n");
		}

		return 0;
	}

	if (!cur)
	{
		rep(i, 1, n + 1)
		{
			rep(j, 1, n + 1)
			{
				if (!a [i][j])
					a [i][j] = sec_diag - row [i];

				printf (lld" ", a [i][j]);
			}

			printf ("\n");
		}

		return 0;
	}

	sum = 0;

	if (curr != 1)
	{
		rep(i, 1, curr + 1)
			sum += row [q1 [i]] - main_diag;

		sum /= (curr - 1);

		rep(i, 2, curr + 1)
			sum += row [q1 [i]] - row [q1 [1]];

		a [q1 [1]][q1 [1]] = sum / curr;
		ll res = row [q1 [1]] + sum / curr;

		rep(i, 1, n + 1)
			rep(j, 1, n + 1)
				if (!a [i][j])
					a [i][j] = res - row [i];

		rep(i, 1, n + 1)
		{
			rep(j, 1, n + 1)
				printf (lld" ", a [i][j]);

			printf ("\n");
		}

		return 0;
	}

	sum = 0;

	if (cur != 1)
	{
		rep(i, 1, cur + 1)
			sum += row [q2 [i]] - sec_diag;

		sum /= (cur - 1);

		rep(i, 2, cur + 1)
			sum += row [q2 [i]] - row [q2 [1]];

		a [q2 [1]][n - q2 [1] + 1] = sum / cur;
		ll res = row [q2 [1]] + sum / cur;

		rep(i, 1, n + 1)
			rep(j, 1, n + 1)
				if (!a [i][j])
					a [i][j] = res - row [i];

		rep(i, 1, n + 1)
		{
			rep(j, 1, n + 1)
				printf (lld" ", a [i][j]);

			printf ("\n");
		}

		return 0;
	}

	int num = 1;

	rep(i, 2, n + 1)
		if (row [i] > row [num])
			num = i;

	rep(i, 1, n + 1)
	{
		rep(j, 1, n + 1)
		{
			if (!a [i][j])
				a [i][j] = row [num] - row [i] + 1000000000ll;

			printf (lld" ", a [i][j]);
		}

		printf ("\n");
	}	

	return 0;

}	