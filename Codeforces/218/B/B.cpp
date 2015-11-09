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

#define NAME "b"
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

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d%d", &a, &b);

	int q2_a = 0;
	int q3_a = 0;
	int q5_a = 0;
	int curr_a = 0;
	int q2_b = 0;
	int q3_b = 0;
	int q5_b = 0;
	int curr_b = 0;	

	while (a != 1)
	{
		if (a % 2 == 0)
		{
			q2_a++;
			a /= 2;
			continue;
		}

		if (a % 3 == 0)
		{
			q3_a++;
			a /= 3;
			continue;
		}

		if (a % 5 == 0)
		{
			q5_a++;
			a /= 5;
			continue;
		}

		curr_a = a;
		a /= a;
	}

	while (b != 1)
	{
		if (b % 2 == 0)
		{
			q2_b++;
			b /= 2;
			continue;
		}

		if (b % 3 == 0)
		{
			q3_b++;
			b /= 3;
			continue;
		}

		if (b % 5 == 0)
		{
			q5_b++;
			b /= 5;
			continue;
		}

		curr_b = b;
		b /= b;
	}

	if (curr_a != curr_b)
	{
		puts ("-1");
		return 0;
	}

	int ans = 0;
	ans += abs (q2_a - q2_b);
	ans += abs (q3_a - q3_b);
	ans += abs (q5_a - q5_b);

	printf ("%d\n", ans);	

	return 0;
}	