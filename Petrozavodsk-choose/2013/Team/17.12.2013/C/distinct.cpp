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

#define NAME "distinct"
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

int max_possible (int n)
{
	int curr = 0;

	while ((curr * (curr + 1)) >> 1 < n)
		curr++;

	return curr;
}	

string solve (string s, int n, int len)
{
	if (n == 4)
		return "aaaa";

	int curr = 0;
	set <string> st;
	int m = (int) s.length ();
	string ans = "";
	int add = 0;

	rep0(i, m)
		rep(j, 1, m + 1)
			if (i + j <= m)
				st.insert (s.substr (i, j));
			else
				break;

	curr = (int) st.size ();

	if (len == m)
	{
		if (curr == n)
			return s;
		else
			return "";
	}

	rep0(i, len - m)
		add += m + i + 1;

	if (curr + add < n)
		return "";

	rep0(i, 26)
	{
		char c = (char) ('a' + i);
		ans = solve (s + c, n, len);

		if (ans != "")
			return ans;
	}

	return "";
}	

int main ()
{	
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);
	printf ("%s\n", solve ("", n, max_possible (n)).c_str ());

	return 0;
}	