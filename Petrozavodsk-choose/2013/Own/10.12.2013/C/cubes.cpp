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

#define NAME "cubes"
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

int n;
int a [105];
int g [105][105];

struct Graph
{
	int n;
	vector <vector <int> > g;
	vector <int> d, p, prev, fl;

	struct Edge
	{
		int from, to, c, flow, cost;

		Edge (int from, int to, int c, int cost = 0) : from (from), to (to), c (c), flow (0), cost (cost) {}
	};

	vector <Edge> e;

	Graph () {}
	
	Graph (int N)
	{
		n = N;
		g.resize (n);
	}

	void add_edge (int from, int to, int c, int cost = 0)
	{
		g [from].pb ((int) e.size ());
		e.pb (Edge (from, to, c, cost));
		g [to].pb ((int) e.size ());
		e.pb (Edge (to, from, 0, -cost));
	}

	int dijkstra ()
	{
		d.assign (n, INF);
		p.assign (n, 0);
		prev.assign (n, -1);
		fl.assign (n, 0);
		d [0] = 0;
		fl [0] = INF;

		set <pair <int, int> > s;

		rep0(i, n)
			s.insert (mp (d [i], i));

		while (!s.empty ())
		{
			int new_to = s.begin ()->snd;
			s.erase (s.begin ());

			rep0(i, (int) g [new_to].size ())
			{
				Edge curr = e [g [new_to][i]];

				if (curr.c == curr.flow)
					continue;

				if (d [curr.to] > d [new_to] + curr.cost + p [new_to] - p [curr.to])
				{
					s.erase (mp (d [curr.to], curr.to));
					d [curr.to] = d [new_to] + curr.cost + p [new_to] - p [curr.to];
					prev [curr.to] = g [new_to][i];
					fl [curr.to] = min (fl [new_to], curr.c - curr.flow);
					s.insert (mp (d [curr.to], curr.to));
				}
			}
		}

		rep0(i, n)
			p [i] += d [i];

		return fl [n - 1];
	}

	int min_cost ()
	{
		int ans = 0;

		while (1)
		{
			int flow = dijkstra ();

			if (!flow)
				break;

			int curr = n - 1;

			while (1)
			{
				if (curr == 0)
					break;

				e [prev [curr]].flow += flow;
				e [prev [curr] ^ 1].flow -= flow;
				ans += flow * e [prev [curr]].cost;
				curr = e [prev [curr]].from;
			}
		}

		return ans;
	}
};	
			
int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	int s = 0;

	rep0(i, n)
	{
		scanf ("%d", &a [i]);
		s += a [i];
	}

	rep0(i, n)
		rep0(j, n)
			scanf ("%d", &g [i][j]);

	rep0(i, n)
		rep0(j, n)
			rep0(k, n)
				g [j][k] = min (g [j][k], g [j][i] + g [i][k]);

	Graph gr ((n + 1) * 2);

	rep0(i, n)
	{
		gr.add_edge (0, i + 1, max (0, a [i] - s / n));
		gr.add_edge (i + n + 1, n * 2 + 1, max (0, s / n - a [i]));
	}

	rep0(i, n)
		rep0(j, n)
			gr.add_edge (i + 1, j + n + 1, INF, g [i][j]);

	int ans = gr.min_cost ();

	printf ("%d\n", ans);	

	return 0;
}	