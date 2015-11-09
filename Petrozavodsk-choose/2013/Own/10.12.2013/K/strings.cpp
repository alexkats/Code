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

#define NAME "strings"
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

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

const int N = 100005;
const int q [2] = {239, 997};
const int modulo [2] = {(int) (1e9) + 7, (int) (1e9) + 9};

string s, t;
int p [N][2];
int hash [2][N][2];
int n;
int a, b;

pair <int, int> get (int l, int r, int key)
{
	pair <int, int> ans;

	ans.frs = hash [key][r][0];
	
	if (l != 0)
		ans.frs -= hash [key][l - 1][0];

	ans.frs = (ans.frs + modulo [0]) % modulo [0];
	ans.frs = 1ll * ans.frs * p [N - l - 1][0] % modulo [0];

	ans.snd = hash [key][r][1];

	if (l != 0)
		ans.snd -= hash [key][l - 1][1];

	ans.snd = (ans.snd + modulo [1]) % modulo [1];
	ans.snd = 1ll * ans.snd * p [N - l - 1][1] % modulo [1];

	return ans;
}	

char check (int a, int b, int cut)
{
    pair <int, int> h1, h2;

	h1 = get (a, cut + a - 1, 0);
	h2 = get (b, cut + b - 1, 1);

	if (h1 == h2)
		return 1;
	else
		return 0;
}	

int solve (int a, int b)
{
	int l = 0;
	int r = min ((int) s.length () - a, (int) t.length () - b);

	while (l < r - 1)
	{
		int m = (l + r) / 2;
		
		if (check (a, b, m))
			l = m;
		else
			r = m;
	}

	return (check (a, b, r) ? r : l);
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);	

	cin >> s;
	cin >> t;

	p [0][0] = p [0][1] = 1;
	
	rep(i, 1, N)
	{
		p [i][0] = 1ll * p [i - 1][0] * q [0] % modulo [0];
		p [i][1] = 1ll * p [i - 1][1] * q [1] % modulo [1];
	}

	rep0(i, 2)
	{
		hash [0][0][i] = s [0];
		hash [1][0][i] = t [0];

		rep(j, 1, (int) s.length ())
			hash [0][j][i] = (hash [0][j - 1][i] + 1ll * s [j] * p [j][i]) % modulo [i];

		rep(j, 1, (int) t.length ())
			hash [1][j][i] = (hash [1][j - 1][i] + 1ll * t [j] * p [j][i]) % modulo [i];
	}

	scanf ("%d", &n);	

	rep0(i, n)
	{
		scanf ("%d%d", &a, &b);	
		printf ("%d\n", solve (a - 1, b - 1));
	}

	return 0;
}	