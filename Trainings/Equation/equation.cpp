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

#define NAME "equation"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

struct point
{
	int x, y;
};

int A (point p, point q)
{
	return (p.y - q.y);
}

int B (point p, point q)
{
	return (q.x - p.x);
}

int C (point p, point q)
{
	return -(A (p, q) * p.x + B (p, q) * p.y);
}

point p, q;	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> p.x >> p.y;
	in >> q.x >> q.y;

	if (A (p, q) != 0)
		out << A (p, q) << "x";

	if (B (p, q) != 0)		
		if (B (p, q) < 0 || B (p, q) > 0 && A (p, q) == 0)
			out << B (p, q) << "y";
		else
			out << "+" << B (p, q) << "y";
			
	if (C (p, q) != 0)
		if (C (p, q) < 0 || C (p, q) > 0 && A (p, q) == 0 && B (p, q) == 0)
			out << C (p, q) << endl;
		else
			out << "+" << C (p, q) << endl;	

	return 0;

}	