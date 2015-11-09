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

#define NAME ""
#define INF 1000000000
#define INF_D 100000.0
#define EPS 0.0000000001

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ull sqr (ll a)
{
	ull c = a * a;

	return c;
}	

using namespace std;

int n, s2 = 0, q = 0, c = 0;
double x, s1 = 0.0, m;

int main ()
{                                                       

//	ifstream in (NAME".in");
//	ofstream out (NAME".out");

	cin >> n;

	for (int i = 0; i < (2 * n); i++)
	{
		cin >> x;

		s2 += floor (x);
		s1 += x;

		if (floor (x) == ceil (x))
			c++;

		if (floor (x) != ceil (x))
			q++;
	}

	for (int i = 0; i < ((q - c) / 2); i++)
		s2++;

	m = fabs (s1 - s2);	

	for (int i = 0; i < c; i++)
		if (fabs (s1 - s2 - 1) < m)
		{
			s2++;
			m = fabs (s1 - s2);
		}	

	double ans = fabs (s1 - s2);	

	printf ("%.3f\n", ans);	
	                      
	return 0;

}	