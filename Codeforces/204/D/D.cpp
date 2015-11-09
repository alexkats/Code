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

int q, p [3000], n;
double ans [9000010];

int main ()
{

//	ifstream in (NAME".in");
//	ofstream out (NAME".out");

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> p [i];

	for (int i = 0; i < (n - 1); i++)
		for (int j = i + 1; j < n; j++)
			if (p [i] > p [j])
				q++;

	if (q == 0)
	{
		printf ("%.6f\n", 0.000000);
		return 0;
	}
	
	if (q == 1)
	{
		printf ("%.6f\n", 1.000000);
		return 0;
	}

	ans [0] = 0.0;
	ans [1] = 1.0;

	for (int i = 2; i <= q; i++)
		ans [i] = ans [i - 2] + 4.0;

	printf ("%.6f\n", ans [q]);	

	return 0;

}	