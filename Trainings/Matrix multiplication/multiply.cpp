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

#define NAME "multiply"
#define INF 1000000000
#define EPS 0.000000001
#define INFLONG 1000000000000000000
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

struct Matrix
{
	int n, m;
	double a [50][50];

	Matrix ()
	{
		memset (a, 0, sizeof (a));
	}

	Matrix (int N, int M)
	{
		n = N;
		m = M;
		memset (a, 0, sizeof (a));
	}	

	Matrix operator * (const Matrix &A)
	{
		Matrix ans (n, A.m);

		rep0(i, n)
			rep0(j, A.m)
				rep0(k, m)
					ans.a [i][j] += a [i][k] * A.a [k][j];

		return ans;
	}
};	

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	int n, m;

	scanf ("%d %d", &n, &m);

	Matrix A (n, m);

	rep0(i, n)
		rep0(j, m)
			scanf ("%lf", &A.a [i][j]);

	scanf ("%d %d", &n, &m);

	Matrix B (n, m);

	rep0(i, n)
		rep0(j, m)
			scanf ("%lf", &B.a [i][j]);

	Matrix ans (A.n, B.m);
	ans = A * B;

	rep0(i, ans.n)
	{
		rep0(j, ans.m)
			printf ("%.2lf ", ans.a [i][j]);

		printf ("\n");
	}	

	return 0;
}	