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

#define NAME "a"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a
#define mp make_pair
#define pb push_back
#define rep(i,n) for (int i = 0; i < n; i++)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n, a [1000];

using namespace std;

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep(i,n)
	{
		scanf ("%d", &a [i]);
	}

	if (n == 1)
	{
		printf ("no\n");
		return 0;
	}

	if (n == 2)
	{
		printf ("no\n");
		return 0;
	}	

	if (n == 3)
	{
		printf ("no\n");
		return 0;
	}

	for (int i = 3; i < n; i++)
		if ((a [i] >= a [i - 2] || a [i] <= a [i - 3]) && a [i] > a [i - 1])
		{
			printf ("yes\n");
			return 0;
		}
		else if ((a [i] <= a [i - 2] || a [i] >= a [i - 1]) && a [i] < a [i - 1])
		{
			printf ("yes\n");
			return 0;
		}

	printf ("no\n");	

	return 0;
}	