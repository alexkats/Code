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

#define NAME "castle"
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

const int sz = 6;

struct point
{
	double x, y;

	point () {};
	point (double X, double Y)
	{
		x = X;
		y = Y;
	}
};

point p [sz];
char un [sz];
string s;
vector <int> unknown;	

char check (vector <int> a)
{
	if ((int) a.size () > 3)
		return 1;

	if ((int) a.size () < 3)
		return 0;

	if (a [0] == 3 && a [1] == 4 && a [2] == 5)
		return 1;

	if (a [0] == 0 && a [1] == 1 && a [2] == 5)
		return 1;

	if (a [0] == 1 && a [1] == 2 && a [2] == 3)
		return 1;

	return 0;
}

void get1 (point p [], vector <int> unknown)
{
	while ((int) unknown.size ())
	{
		int num = unknown [0];
		unknown.erase (unknown.begin ());

		if (num == 0 || num == 2)
		{
			p [num].x = p [num + 1].x * 2 - p [num + 2].x;
			p [num].y = p [num + 1].y * 2 - p [num + 2].y;
			continue;
		}

		if (num == 1 || num == 3)
		{
			p [num].x = (p [num - 1].x + p [num + 1].x) / 2.0;
			p [num].y = (p [num - 1].y + p [num + 1].y) / 2.0;
			continue;
		}

		if (num == 4)
		{
			p [4].x = p [3].x * 2 - p [2].x;
			p [4].y = p [3].y * 2 - p [2].y;
			continue;
		}

		if (num == 5)
		{
			p [5].x = (p [0].x + p [4].x) / 2.0;
			p [5].y = (p [0].y + p [4].y) / 2.0;
			continue;
		}
	}
}

void get2 (point p [], vector <int> unknown)
{
	int q = (int) unknown.size ();

	while (q)
	{
		for (int i = 0; i < sz - 1; i += 2)
			if (un [i + 1] && !un [i] && !un [(i + 2) % sz])
			{
				p [i + 1].x = (p [i].x + p [(i + 2) % sz].x) / 2.0;
				p [i + 1].y = (p [i].y + p [(i + 2) % sz].y) / 2.0;
				un [i + 1] = 0;
				q--;
			}
   	
		rep(i, 1, sz + 1)
			if (!un [i % sz] && !un [i - 1])
			{
				if (i % 2 == 1 && un [(i + 1) % sz])
				{
					p [(i + 1) % sz].x = p [i % sz].x * 2 - p [i - 1].x;
					p [(i + 1) % sz].y = p [i % sz].y * 2 - p [i - 1].y;
					un [(i + 1) % sz] = 0;
					q--;
				}
				else if (i % 2 == 0 && un [(i + 4) % sz])
				{
					p [(i + 4) % sz].x = p [i - 1].x * 2 - p [i % sz].x;
					p [(i + 4) % sz].y = p [i - 1].y * 2 - p [i % sz].y;
					un [(i + 4) % sz] = 0;
					q--;
				}
			}	
	}
}

void get3 (point p [], vector <int> unknown)
{
	if (unknown [0] == 0 && unknown [1] == 2 && unknown [2] == 4)
	{
		p [0].x = p [5].x + p [1].x - p [3].x;
		p [0].y = p [5].y + p [1].y - p [3].y;
		p [2].x = p [1].x + p [3].x - p [5].x;
		p [2].y = p [1].y + p [3].y - p [5].y;
		p [4].x = p [5].x + p [3].x - p [1].x;
		p [4].y = p [5].y + p [3].y - p [1].y;

		return;	
	}

	get2 (p, unknown);
}	

void solve (point p [], vector <int> unknown)
{
	if ((int) unknown.size () == 3)
		get3 (p, unknown);

	if ((int) unknown.size () == 2)
		get2 (p, unknown);

	if ((int) unknown.size () == 1)
		get1 (p, unknown);

	rep0(i, sz)
		printf ("%.5lf %.5lf\n", p [i].x, p [i].y);	
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);
	memset (un, 0, sizeof (un));

	rep0(i, sz)
	{
		char t;

		scanf ("%c", &t);
		
		if (t == '?')
		{
			getline (cin, s);
			unknown.pb (i);
			un [i] = 1;
			continue;
		}

		getline (cin, s);
		s = t + s;
		int pos = 0;

		while (s [pos] != ' ')
			pos++;

		int a = atoi (s.substr (0, pos).c_str ());
		p [i].x = (double) a;
		s = s.substr (pos + 1, (int) s.length () - pos);
		a = atoi (s.c_str ());
		p [i].y = (double) a;
	}

	if (check (unknown))
	{
		puts ("IMPOSSIBLE");
		return 0;
	}
		
	puts ("POSSIBLE");
	solve (p, unknown);	

	return 0;
}	