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

#define NAME "si"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

struct pt
{
	int x, y;
};

inline int area (pt a, pt b, pt c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1 (int a, int b, int c, int d)
{
	if (a > b)
		swap (a, b);

	if (c > d)
		swap (c, d);

	return max (a, c) <= min (b, d);
}

bool intersect (pt a, pt b, pt c, pt d)
{
	return intersect_1 (a.x, b.x, c.x, d.x) && intersect_1 (a.y, b.y, c.y, d.y) && area (a, b, c) * area (a, b, d) <= 0 && area (c, d, a) * area (c, d, b) <= 0;
}

pt a, b, c, d;

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> a.x >> a.y;
	in >> b.x >> b.y;
	in >> c.x >> c.y;
	in >> d.x >> d.y;

	out << intersect (a, b, c, d) << endl;	

	return 0;

}	