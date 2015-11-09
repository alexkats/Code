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

#define NAME "polygon"
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

int n;
int a [10];
double ans;

double get_square (double a, double b, double c)
{
	double p = (a + b + c) / 2.0;
	double ans = sqrt (p * (p - a) * (p - b) * (p - c));
	return ans;
}

char good (double a, double b, double c)
{
	if (a + b < c || a + c < b || b + c < a)
		return 0;

	return 1;
}	

void solve (int curr, int s1, int s2, int s3)
{
	if (curr == n)
	{
		s1 = fabs (s1);
		s2 = fabs (s2);
		s3 = fabs (s3);

		if (!good (s1, s2, s3))
			return;

		ans = min (ans, get_square (s1, s2, s3));
		return;
	}

	solve (curr + 1, s1 + a [curr], s2, s3);
	solve (curr + 1, s1 - a [curr], s2, s3);
	solve (curr + 1, s1, s2 + a [curr], s3);
	solve (curr + 1, s1, s2 - a [curr], s3);
	solve (curr + 1, s1, s2, s3 + a [curr]);
	solve (curr + 1, s1, s2, s3 - a [curr]);
}	

int main ()
{	
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
		scanf ("%d", &a [i]);

	ans = (double) INF;	

	solve (0, 0, 0, 0);

	printf ("%.10lf\n", ans);	

	return 0;
}	