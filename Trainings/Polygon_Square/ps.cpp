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

#define NAME "ps"
#define maxn 1000

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

struct point
{
	int x, y;
};

point a [maxn];
int n;

double triangle_area (int x1, int y1, int x2, int y2, int x3, int y3)
{
	return ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) / 2.0);
}	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> n;

	for (int i = 0; i < n; i++)
		in >> a [i].x >> a [i].y;

	double s = 0.0;	

	for (int i = 0; i < (n - 1); i++)
		s += triangle_area (0, 0, a [i].x, a [i].y, a [i + 1].x, a [i + 1]. y);

	s += triangle_area (0, 0, a [n - 1].x, a [n - 1].y, a [0].x, a [0].y);

	out << fabs (s) << endl;	

	return 0;

}	