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

int n, x [100], y [100], s1 = 0, s2 = 0;

int main ()
{

//	ifstream in (NAME".in");
//	ofstream out (NAME".out");

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x [i] >> y [i];

		s1 += x [i];
		s2 += y [i];
	}

	if (s1 % 2 == 0 && s2 % 2 == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	if ((s1 % 2 == 0 && s2 % 2 == 1) || (s1 % 2 == 1 && s2 % 2 == 0))
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < n; i++)
		if ((x [i] % 2) != (y [i] % 2))
		{
			cout << 1 << endl;
			return 0;
		}

	cout << -1 << endl;	

	return 0;

}	