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

#define NAME "c"
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

struct A
{
	int mx, prev1, prev2;
};

string s;
char tmp [50];
A a [1000000];
int n, m, c, p;
int prev [1000000];
int q = 0;
int cnt = 1;	

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d%d\n", &n, &m);

	a [0].mx = 0;
	a [0].prev1 = 0;
	a [0].prev2 = 0;
	prev [1] = 0;

	rep0(i, n)
	{
		scanf ("%s", tmp);
		s = tmp;

		if (s == "learn")
		{
			scanf ("%d%d", &c, &p);
			q++;
			a [q].mx = p;
			a [q].prev1 = prev [c];
			a [q].prev2 = 0;
			prev [c] = q;
		}
		else if (s == "rollback")
		{
			scanf ("%d", &c);
			q++;
			a [q] = a [a [prev [c]].prev1];
			a [q].prev2 = prev [c];
			prev [c] = q;
		}
		else if (s == "relearn")
		{
			scanf ("%d", &c);
			q++;
			a [q] = a [a [prev [c]].prev2];
			prev [c] = q;
		}
		else if (s == "clone")
		{
			scanf ("%d", &c);
			q++;
			a [q] = a [prev [c]];
			cnt++;
			prev [cnt] = q;
		}
		else
		{
			scanf ("%d", &c);

			if (a [prev [c]].mx == 0)
				printf ("basic\n");
			else
				printf ("%d\n", a [prev [c]].mx);
		}
	}	

	return 0;
}	