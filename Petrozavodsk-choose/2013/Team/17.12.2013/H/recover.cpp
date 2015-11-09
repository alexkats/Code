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

#define NAME "recover"
#define INF 2000000000
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

int n, m, k;
vector < pair < pair <int, int>, int > > g [100005];
set < pair <int, int> > s;
vector < pair <int, int> > res;
vector <int> ans;
int city [100005], dist [100005];
vector <int> cur;
char used [100005];
char fl = 0;

void dfs (int from, int to, int d)
{
	if (dist [from] > d)
		return;

	if (from == to)
	{
		fl = 1;

		rep0(i, (int) cur.size ())
			ans.pb (cur [i]);

		return;
	}

	rep0(i, (int) g [from].size ())
		if (dist [g [from][i].snd] == dist [from] + g [from][i].frs.frs)
		{
			cur.pb (g [from][i].frs.snd + 1);

			if (!used [g [from][i].snd])
			{
				used [g [from][i].snd] = 1;
				dfs (g [from][i].snd, to, d);
				used [g [from][i].snd] = 0;
			}

			cur.pop_back ();

			if (fl)
				return;
		}
}	

int main ()
{	
	srand (time (0));

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);
	memset (used, 0, sizeof (used));

	scanf ("%d %d", &n, &m);

	rep0 (i, m)
	{
		int a, b, c;
		scanf ("%d %d %d", &a, &b, &c);
		g [a].pb (mp (mp (c, i), b));
		g [b].pb (mp (mp (c, i), a));
	}	

	scanf ("%d", &k);

	rep0(i, k)
		scanf ("%d", &city [i]);

	rep0(i, n + 1)
	{
		dist [i + 1] = INF;
		
		if (i)
			s.insert (mp (dist [i], i));
	}	

	s.erase (mp (dist [city [0]], city [0]));
	dist [city [0]] = 0;
	s.insert (mp (0, city [0]));

	while ((int) s.size ())
	{
		int to = s.begin ()->snd;
		s.erase (s.begin ());

		rep0(i, (int) g [to].size ())
		{
			int tmp = g [to][i].snd;

			if (dist [tmp] > dist [to] + g [to][i].frs.frs)
			{
				s.erase (mp (dist [tmp], tmp));
				dist [tmp] = dist [to] + g [to][i].frs.frs;
				s.insert (mp (dist [tmp], tmp));
			}	
		}
	}

	int go = city [0];

	rep(i, 1, k)
		go = (dist [city [i]] > dist [go]) ? city [i] : go;

	rep0(i, n + 1)
	{
		dist [i + 1] = INF;

		if (i)
			s.insert (mp (dist [i], i));
	}	

	s.erase (mp (dist [go], go));
	dist [go] = 0;
	s.insert (mp (0, go));

	while ((int) s.size ())
	{
		int to = s.begin ()->snd;
		s.erase (s.begin ());

		rep0(i, (int) g [to].size ())
		{
			int tmp = g [to][i].snd;

			if (dist [tmp] > dist [to] + g [to][i].frs.frs)
			{
				s.erase (mp (dist [tmp], tmp));
				dist [tmp] = dist [to] + g [to][i].frs.frs;
				s.insert (mp (dist [tmp], tmp));
			}	
		}
	}	

	rep0(i, k)
		res.pb (mp (dist [city [i]], city [i]));

	sort (res.begin (), res.end ());

	rep0(i, k - 1)
	{
		fl = 0;
		dfs (res [i].snd, res [i + 1].snd, dist [res [i + 1].snd]);
	}	

	printf ("%d\n", (int) ans.size ());

	rep0(i, (int) ans.size ())
		printf ("%d ", ans [i]);

	printf ("\n");	

	return 0;
}	