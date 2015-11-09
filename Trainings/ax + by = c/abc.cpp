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

#define NAME "abc"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int a, b, c, n;

int gcd (int a, int b, int & x, int & y)
{
	if (a == 0)
	{
		x = 0; y = 1;
		return b;
	}

	int x1, y1;
	int d = gcd (b % a, a, x1, y1);

	x = y1 - (b / a) * x1;
	y = x1;

	return d;
}	

void shift_solution (int & x, int & y, int a, int b, int cnt)
{
	x += cnt * b;
	y -= cnt * a;
}

bool find_any_solution (int a, int b, int c, int & x0, int & y0, int & g)
{
	g = gcd (abs (a), abs (b), x0, y0);

	if (c % g != 0)
		return false;

	x0 *= (c / g);
	y0 *= (c / g);

	if (a < 0)
		x0 *= -1;

	if (b < 0)
		y0 *= -1;

	return true;
}	

int find_solutions (int a, int b, int c, int minx, int maxx, int miny, int maxy)
{
	int x, y, g;

	if (! find_any_solution (a, b, c, x, y, g))
		return 0;

	a /= g;
	b /= g;

	int sign_a = a > 0 ? +1 : -1;
	int sign_b = b > 0 ? +1 : -1;

	shift_solution (x, y, a, b, (minx - x) / b);

	if (x < minx)
		shift_solution (x, y, a, b, sign_b);

	if (x > maxx)
		return 0;

	int lx1 = x;

	shift_solution (x, y, a, b, (maxx - x) / b);

	if (x > maxx)
		shift_solution (x, y, a, b, -sign_b);

	int rx1 = x;	

	shift_solution (x, y, a, b, -(miny - y) / a);

	if (y < miny)
		shift_solution (x, y, a, b, -sign_a);

	if (y > maxy)
		return 0;

	int lx2 = x;	

	shift_solution (x, y, a, b, -(maxy - y) / a);

	if (y > maxy)
		shift_solution (x, y, a, b, sign_a);

	int rx2 = x;	

	if (lx2 > rx2)
		swap (lx2, rx2);

	int lx = max (lx1, lx2);
	int rx = min (rx1, rx2);

	return (rx - lx) / abs (b) + 1;
}	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> a >> b >> c >> n;

	int f = find_solutions (a, b, c, 0, n, 0, n);

	out << f << endl;

	return 0;

}	