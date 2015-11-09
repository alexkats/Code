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
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "num2brackets2"
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

string s = "";
int n;
ll k;
ll d [50][50];
char r [50];
int qr = 0;
ll curr;

void solve (int n, ll curr)
{
	int q = 0;
	ll cur = 0;

	repd0(i, n * 2)
	{
		if (q + 1 <= n)
			cur = d [i][q + 1] * (1 << ((i - q - 1) / 2));
		else
			cur = 0;	

		if (cur >= curr)
		{
			s += '(';
			r [qr] = '(';
			qr++;
			q++;
			continue;
		}

		curr -= cur;

		if (qr > 0 && r [qr - 1] == '(' && q - 1 >= 0)
			cur = d [i][q - 1] * (1 << ((i - q + 1) / 2));
		else
			cur = 0;

		if (cur >= curr)
		{
			s += ')';
			qr--;
			q--;
			continue;
		}

		curr -= cur;

		if (q + 1 <= n)
			cur = d [i][q + 1] * (1 << ((i - q - 1) / 2));
		else
			cur = 0;	

		if (cur >= curr)
		{
			s += '[';
			r [qr] = '[';
			qr++;
			q++;
			continue;
		}

		curr -= cur;
		s += ']';
		qr--;
		q--;
	}

	cout << s << endl;
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%I64d", &n, &k);

	d [0][0] = 1;

	rep(i, 1, n * 2)
		d [0][i] = 0;

	rep(i, 1, n * 2)
	{
		d [i][0] = d [i - 1][1];

		rep(j, 1, n * 2)
			d [i][j] = d [i - 1][j - 1] + d [i - 1][j + 1];
	}

	curr = k;

	solve (n, curr + 1);

	return 0;
}	