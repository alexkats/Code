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

#define NAME "fibsum"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a
#define mp make_pair
#define frs first
#define snd second
#define pb push_back
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
int p;
ll a, b;
int f [15], ff [15];
int T;

struct Matrix
{
	int n, m;
	int element [15][15];

	Matrix () {memset (element, 0, sizeof (element));}

	Matrix (int N, int M)
	{
		memset (element, 0, sizeof (element));
		n = N;
		m = M;
	}

	Matrix operator * (const Matrix &A)
	{
		Matrix ans (n, A.m);

		rep0(i, n)
			rep0(j, A.m)
				rep0(k, m)
					ans.element [i][j] = ((ans.element [i][j] + 1ll * element [i][k] * A.element [k][j]) % p + p) % p;

		return ans;
	}
};	

Matrix M_pow (Matrix a, ll pw)
{
	if (pw == 1)
		return a;

	Matrix ans = M_pow (a, pw >> 1);
	ans = ans * ans;

	if (pw % 2 == 1)
		ans = ans * a;

	return ans;
}	

int get (ll k)
{
	if (k < 0)
		return 0;

	f [n] = 0;

	rep0(i, n)
		f [n] = (f [n] + f [i]) % p;

	ff [0] = f [0] % p;

	rep0(i, n)
		ff [i + 1] = (f [i + 1] + ff [i]) % p;

	if (k == 0)
		return ff [k];

	Matrix a (1, n + 1);
	Matrix b (n + 1, n + 1);

	rep0(i, n + 1)
		a.element [0][i] = ff [i];

	rep0 (i, n)
		b.element [i + 1][i] = 1;

	b.element [0][n] = p - 1;
	b.element [n][n] = 2 % p;
	b = M_pow (b, k);
	a = a * b;

	return a.element [0][0];
}	

int solve (ll l, ll r)
{
	int ans = 0;

	ans = get (r);
	ans -= get (l - 1);

	return ans;
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);	

	scanf ("%d", &T);

	rep0(o, T)
	{
		scanf ("%d", &n);

		rep0(i, n)
			scanf ("%d", &f [i]);

		scanf (lld" "lld" %d", &a, &b, &p);

		rep0(i, n)
			f [i] = (f [i] >= 0) ? (f [i] % p) : ((p - (-f [i] % p)) % p);

		int ans = solve (a, b);
		ans += p;
		ans %= p;

		printf ("%d\n", ans);
	}	

	return 0;
}	