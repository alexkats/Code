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

#define NAME "square"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int triangle_area_2 (int x1, int y1, int x2, int y2, int x3, int y3)
{
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

double square (int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs (triangle_area_2 (x1, y1, x2, y2, x3, y3)) / 2.0;
}

bool clockwise (int x1, int y1, int x2, int y2, int x3, int y3)
{
	return triangle_area_2 (x1, y1, x2, y2, x3, y3) < 0;
}

bool counter_clockwise (int x1, int y1, int x2, int y2, int x3, int y3)
{
	return triangle_area_2 (x1, y1, x2, y2, x3, y3) > 0;
}	

int cx1, cy1, cx2, cy2, cx3, cy3;	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> cx1 >> cy1;
	in >> cx2 >> cy2;
	in >> cx3 >> cy3;

	out << triangle_area_2 (cx1, cy1, cx2, cy2, cx3, cy3) << endl;
	out << square (cx1, cy1, cx2, cy2, cx3, cy3) << endl;
	out << clockwise (cx1, cy1, cx2, cy2, cx3, cy3) << endl;

	return 0;

}	