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
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "e"
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

int n, a;

int solve (int n)
{
	if (n == 0)
		return 0;

	string s;
	int ans;

	cin >> s >> ans;

	ans += solve (n - 1);

	if (s == "WITHOUT")
		ans = -ans;

	return ans;
}	

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d\n%d", &n, &a);

	int ans = a + solve (n);

	printf ("%d\n", ans);

	return 0;
}	