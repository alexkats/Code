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

int n, t, c [20];

int main ()
{

//	ifstream in (NAME".in");
//	ofstream out (NAME".out");

	cin >> t;

	for (int e = 0; e < t; e++)
	{
		cin >> n;

		int mi = 100;
		int ma = 0;
		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> c [i];
			mi = min (mi, c [i]);
			ma = max (ma, c [i]);
		}	

		ans = 2 * (ma - mi);

		cout << ans << endl;
	}	

	return 0;

}	