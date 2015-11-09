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

#define NAME "a"
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

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int n, m, i, j, a, b, ans = 0;

int get (int x, int y)
{
	if (i % a != x % a || j % b != y % b)
		return INF;

	int ans1 = abs (x - i) / a;
	int ans2 = abs (y - j) / b;
	int ans = ans1 + ans2;

	if (ans % 2 == 0)
		return max (ans1, ans2);
	else
		return INF;
}	

char ok (int a, int b)
{
	if (a == 1 && b == 1)
		return 1;

	if (a == 1 && b == m)
		return 1;

	if (a == n && b == 1)
		return 1;

	if (a == n && b == m)
		return 1;

	return 0;
}	

void solve (int n, int m, int i, int j, int a, int b)
{
    if (ok (i, j))
    {
    	puts ("0");
    	return;
    }	
	
	if ((i - a < 1 && i + a > n) || (j - b < 1 && j + b > m))
	{
		puts ("Poor Inna and pony!");
		return;
	}

	ans = min (min (get (1, 1), get (1, m)), min (get (n, 1), get (n, m)));

	if (ans < INF)
		printf ("%d\n", ans);
	else
		puts ("Poor Inna and pony!");
}	

int main ()
{
	srand (time (0));

//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d %d %d %d %d %d", &n, &m, &i, &j, &a, &b);
	solve (n, m, i, j, a, b);

	return 0;
}	