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

#define NAME "game"
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

int a, b;

int solve1 (int a, int b)
{
	int ans = 1;
	int curr = 1;

	while (a % 2 == 0)
	{
		ans += curr * 2;
		a /= 2;
		curr++;
		curr %= 2;
	}

	return ans;
}

int solve2 (int a, int b)
{
	int ans = 2;
	int curr = 0;

	while (a % 2 == 0)
	{
		ans += curr * 2;
		a /= 2;
		curr++;
		curr %= 2;
	}

	return ans;
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &a, &b);
	printf ("%d\n", (a < b) ? solve1 (a, b) : solve2 (b, a));

	return 0;
}	