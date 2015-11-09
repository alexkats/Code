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

#define NAME "f"
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
#define N 1000005

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif	

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

string s;
char a [N * 2];
vector <int> p;
int sum [N];
vector <int> l, r;
vector <int> un [N];
set <int> st;
char ok [N];
ll ans;

vector <int> palindrome (char a [], int n)
{
	vector <int> ans (n * 2 + 1, 1);
	int curr = 0;

	rep(i, 1, n * 2 + 1)
	{
		if (ans [curr] + curr - 1 >= i)
			ans [i] = min (ans [curr * 2 - i], ans [curr] + curr - i);

		while (1)
		{
			if (ans [i] + i > n * 2 || ans [i] > i || a [i - ans [i]] != a [i + ans [i]])
				break;

			ans [i]++;
		}

		if (ans [i] + i > curr + ans [curr])
			curr = i;
	}

	return ans;
}	

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);
	memset (a, '#', sizeof (a));
	memset (ok, 0, sizeof (ok));	

	cin >> s;

	int n = (int) s.length ();

	rep0(i, n)
		a [i * 2 + 1] = s [i];

	p = palindrome (a, n);	

	rep(i, 1, n * 2 + 1)
	{
		if (i % 2 == 0)
		{
			int tmp = p [i] / 2;

			if (!tmp)
				continue;

			l.pb ((i - 1) / 2 - tmp + 1);
			r.pb ((i - 1) / 2 + tmp);
		}
		else
		{
			int tmp = p [i] / 2;
			l.pb (i / 2 - tmp + 1);
			r.pb (i / 2 + tmp - 1);
		}
	}

	assert (l.size () == r.size ());

	rep0(i, (int) l.size ())
	{
		int left = l [i];
		int right = r [i];
		sum [(left + right) / 2 + 1]++;
		sum [right + 1]--;
	}

	int curr = 0;

	rep0(i, n)
	{
		curr += sum [i];

		if (curr)
			ok [i] = 1;
	}

	rep0(i, n)
		if (i)
			if (s [i] != s [i - 1])
				un [i].pb (i - 1);

	rep0(i, (int) l.size ())
	{
		int left = l [i];
		int right = r [i];

		if (left && right != n - 1)
			un [right + 1].pb (left - 1);
	}

	ans = 1;

	rep0(i, n)
	{
		if (ok [i])
			continue;

		st.clear ();

		rep0(j, (int) un [i].size ())
			st.insert (s [un [i][j]]);

		ans = (1ll * ans * (26 - (int) st.size ())) % (INF + 7);
	}

	printf (lld"\n", ans);	

	return 0;
}	