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
#define maxn 25

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

vector <int> time [maxn]

void change (int key, int curr)
{
	
}

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	int curr = 0;

	scanf ("%d%d%d", &n1, &n2, &m);

	while (!(n1 == 0 && n2 == 0 && m == 0))
	{	
		curr++;

		rep0(i, m)
		{
			if (t1 [a [i] % n1] == -1)
			{
				t1 [a [i] % n1] = a [i];
				continue;
			}

			int tmp = t1 [a [i] % n1];
			t1 [a [i] % n1] = a [i];

			change (1, tmp);
		}

		printf ("Case %d:\n", curr);

		bool fl1 = false;
		bool fl2 = false;

		rep0(i, n1)
			if (t1 [i] != -1)
			{
				fl1 = true;
				break;
			}

		if (fl1)
			printf ("Table 1\n");

		rep0(i, n1)
			if (t1 [i] != -1)
				printf ("%d:%d\n", i, t1 [i]);

		rep0(i, n2)
			if (t2 [i] != -1)
			{
				fl2 = true;
				break;
			}

		if (fl2)
			printf ("Table 2\n");

		rep0(i, n2)
			if (t2 [i] != -1)
				printf ("%d:%d\n", i, t2 [i]);	
				   
		scanf ("%d%d%d", &n1, &n2, &m);
	}	

	return 0;
}	