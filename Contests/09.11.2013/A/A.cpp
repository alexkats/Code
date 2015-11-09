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

#define NAME "a"
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

const double INF = 1e10;

double d [1000000];
int n, m, q;

struct Point
{
	double x, y;
	
	Point () {}
	Point (double x, double y): x (x), y (y) {}

	void scan ()
	{
		scanf ("%lf%lf", &x, &y);
	}
};

bool oper (Point A, Point B)
{
	return A.y < B.y;
}

Point mod (Point A, Point B, int y)
{
	return Point ((B.x * (y - A.y) + A.x * (B.y - y)) / (B.y - A.y), y);
}

double fabs (double x)
{
	return (x < 0) ? -x : x;
}

Point a [1000000], b [1000000], c [1000000];	

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, n)
		a [i].scan ();

	scanf ("%d", &m);

	rep0(i, m)
		b [i].scan ();

	scanf ("%d", &q);

	rep0(i, q)
		c [i].scan ();

	rep0(i, n)
	{
		c [q] = a [i];
		q++;
	}

	rep0(i, m)
	{
		c [q] = b [i];
		q++;
	}

	int curr = 0;

	rep0(i, q)
		if ((a [0].y - c [i].y) <= EPS && (c [i].y - a [n - 1].y) <= EPS)
		{
			c [curr] = c [i];
			curr++;
		}

	q = curr;

	sort (c, c + q, oper);

	int curr_a = 1;
	int curr_b = 1;
	double ans = INF;
	double res = 0.0;
	bool fl = 0;

	for (int i = 0; i < q;)
	{
		for (; curr_a < n && a [curr_a].y + EPS < c [i].y; curr_a++);
		    fl = 1;
	    
	    for (; curr_b < m && b [curr_b].y + EPS < c [i].y; curr_b++);
		    fl = 1;

		Point A = mod (a [curr_a - 1], a [curr_a], c [i].y);
		Point B = mod (b [curr_b - 1], b [curr_b], c [i].y);
		double coord_y = c [i].y;
		d [0] = A.x;
		curr = 1;

		for (; i < q && fabs (c [i].y - coord_y) < EPS; i++)
			if (A.x <= c [i].x && c [i].x <= B.x)
			{
				d [curr] = c [i].x;
				curr++;
			}

		d [curr] = B.x;
		curr++;

		sort (d, d + curr);
		res = 0.0;

		for (int i = 0; i < curr - 1; i++)
			res = max (res, d [i + 1] - d [i]);

		ans = min (ans, res);
	}

	printf ("%.10lf\n", ans);	

	return 0;
}	