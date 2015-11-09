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

#define NAME "cli"
#define EPS 0.000000000001

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

double r, a, b, c;

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> r >> a >> b >> c;

	double x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);

	if (c * c > r * r * (a * a + b * b) + EPS)
		puts ("no points");
	else if (abs (c * c - r * r * (a * a + b * b)) < EPS)
	{
		puts ("1 point");
		out << x0 << ' ' << y0 << '\n';
	}
	else
	{
		double d = r * r - c * c / (a * a + b * b);
		double mult = sqrt (d / (a * a + b * b));
		double ax, ay, bx, by;

		ax = x0 + b * mult;
		bx = x0 - b * mult;
		ay = y0 - a * mult;
		by = y0 + a * mult;
		puts ("2 points");
		out << ax << ' ' << ay << '\n' << bx << ' ' << by << '\n';
	}	

	return 0;

}	