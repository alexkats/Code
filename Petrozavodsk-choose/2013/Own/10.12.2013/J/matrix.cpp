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
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "matrix"
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

const int sz = 3;
const int max_size = 1 << 6;

int n, p;
char base [sz][sz];

struct Matrix
{
	int n, m;
	int a [max_size][max_size];

	Matrix () {memset (a, 0, sizeof (a));}

	Matrix (int n1, int m1)
	{
	    memset (a, 0, sizeof (a));
		n = n1;
		m = m1;
	}

	Matrix operator * (const Matrix &A)
	{
		Matrix ans (n, A.m);

		rep0(i, n)
			rep0(j, A.m)
				rep0(k, m)
					ans.a [i][j] = (ans.a [i][j] + 1ll * a [i][k] * A.a [k][j]) % p;

		return ans;
	}	
};

Matrix M_pow (Matrix A, int n)
{
	if (n == 1)
		return A;

	Matrix ans = M_pow (A, n / 2);
	ans = ans * ans;

	if (n % 2 == 1)
		ans = ans * A;

	return ans;
}

bool check (int a, int b)
{                      
	vector <vector <int> > v1 (3, vector <int> (2));
	vector <vector <int> > v2 (3, vector <int> (2));

	rep0(i, sz * 2)
	{
		v1 [i / 2][i % 2] = ((a & (1 << i)) > 0 ? 1 : 0);
		v2 [i / 2][i % 2] = ((b & (1 << i)) > 0 ? 1 : 0);
	}

	bool ans = 1;
	bool res = 1;

	rep0(i, sz)
		ans &= (v1 [i][1] == v2 [i][0]);

	rep0(i, sz)
		v1 [i].pb (v2 [i][1]);

	rep0(i, sz)
		rep0(j, sz)
			res &= (base [i][j] == 'X' || ((int) base [i][j] - 48 == v1 [i][j]));

	ans &= !res;

	return ans;
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &n, &p);

	Matrix m1 (1, max_size);
	Matrix m2 (max_size, max_size);

	rep0(i, sz)
		rep0(j, sz)
			cin >> base [i][j];

	rep0(i, max_size)	
		m1.a [0][i] = 1;

	rep0(i, max_size)
		rep0(j, max_size)
			m2.a [i][j] = check (i, j);

	m2 = M_pow (m2, n - 2);
	m1 = m1 * m2;
	int ans = 0;

	rep0(i, max_size)
	{
		ans += m1.a [0][i];
		ans %= p;
	}

	printf ("%d\n", ans);	
		
	return 0;
}	