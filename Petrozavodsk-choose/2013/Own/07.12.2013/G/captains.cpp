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
#include <cctype>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>
 
#define NAME "captains"
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

int n;
int a [100];
int s1 = 0;
int s2 = 0;

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
		scanf ("%d", &a [i]);

	int curr = 0;
	sort (a, a + n);
	reverse (a, a + n);

	rep0(i, n / 2)
	{
		(curr == 0 ? s1 : s2) += a [i * 2];
		(curr == 0 ? s2 : s1) += a [i * 2 + 1];
		curr++;
		curr %= 2;
	}

	if (s1 > s2)
	{
		puts ("YES");
		printf ("%d %d\n", s1, s2);
	}
	else
	{
		puts ("NO");
		printf ("%d %d\n", s1, s2);
	}	

	return 0;

}	