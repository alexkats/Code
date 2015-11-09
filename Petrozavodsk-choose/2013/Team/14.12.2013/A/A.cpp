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
#include <ctime>
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

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif	
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld; 
 
using namespace std;

struct road
{
	int from, to, weight, num;
};

int n, m;
road a [300005], g [300005];
int t [300005], prior [300005];
char ans [300005];

bool oper (road a, road b)
{
	return a.weight < b.weight;
}

int fnd (int a)
{
	if (t [a] != a)
		t [a] = fnd (t [a]);

	return t [a];
}

void union_sets (int a, int b)
{
	a = fnd (a);
	b = fnd (b);

	if (prior [a] > prior [b])
		t [b] = a;

	if (prior [a] < prior [b])
		t [a] = b;

	if (prior [a] == prior [b])
	{
		prior [a]++;
		t [b] = a;
	}
}	

int main ()
{
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);
	memset (prior, 1, sizeof (prior));

	scanf ("%d%d", &n, &m);

	rep0(i, m)
	{
		scanf ("%d%d%d", &g [i + 1].from, &g [i + 1].to, &g [i + 1].weight);
		g [i + 1].num = i + 1;
	}

	sort (g + 1, g + m + 1, oper);

	g [0].weight = -1;

	rep0(i, n)
		t [i + 1] = i + 1;

	int curr = 0;
	int q = 0;

	rep(i, 1, m + 1)
	{
		if (g [i].weight == g [i - 1].weight)
		{
			curr++;
			a [curr] = g [i];
			continue;
		}

		rep(j, 1, curr + 1)
			if (fnd (a [j].from) != fnd (a [j].to))
				ans [a [j].num] = 1;

		rep(j, 1, curr + 1)
			if (fnd (a [j].from) != fnd (a [j].to))
			{
				union_sets (a [j].from, a [j].to);
				q++;
			}

		a [1] = g [i];
		curr = 1;
	}

	if (q != (n - 1))
	{
		rep0(i, m)
			puts ("NO");

		return 0;
	}

	rep(i, 1, m + 1)
		puts (ans [i] ? "YES" : "NO");	

	return 0;

}	
