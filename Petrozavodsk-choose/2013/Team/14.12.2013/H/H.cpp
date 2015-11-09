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
#include <memory>
#include <ctime>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "h"
#define INF 1000000000
#define EPS 0.000000001
#define mp make_pair
#define frs first
#define snd second
#define pb push_back
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)
#define N 205
#define K 15

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif	

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

const int sz = 3;
const int pw = 8;

int n, k;
int a [N][sz];
char used [sz];
int d [N][K][K][K][K];

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);
	memset (d, -INF, sizeof (d));

	scanf ("%d %d", &n, &k);

	rep0(i, sz)
		rep0(j, n)
			scanf ("%d", &a [j][i]);

	d [0][k][0][k][0] = 0;

	rep0(i, n)
		rep0(can1, k + 1)
			rep0(was1, k + 1)
				rep0(can2, k + 1)
					rep0(was2, k + 1)
					{
						int curr = d [i][can1][was1][can2][was2];

						if (curr < 0)
							continue;

						rep0(mask, pw)
						{
							memset (used, 0, sizeof (used));
							int sum = 0;

							rep0(j, sz)
								if ((1 << j) & mask)
								{
									sum += a [i][j];
									used [j] = 1;
								}

							if ((can1 == 0 && used [0]) || (can2 == 0 && used [1]) || (was2 == k && used [2]))
								continue;

							int next_can1 = min (can1 - used [0], k - used [1] - was1);
							int next_can2 = min (can2 - used [1], k - used [2] - was2);
							int next_was1 = was1 + used [1];
							int next_was2 = was2 + used [2];

							d [i + 1][next_can1][next_was1][next_can2][next_was2] = max (d [i + 1][next_can1][next_was1][next_can2][next_was2], curr + sum);
						}
					}

	int ans = -INF;

	rep0(i, n + 1)
		rep0(can1, k + 1)
			rep0(was1, k + 1)
				rep0(can2, k + 1)
					rep0(was2, k + 1)
						ans = max (ans, d [i][can1][was1][can2][was2]);

	printf ("%d\n", ans);	

	return 0;
}	