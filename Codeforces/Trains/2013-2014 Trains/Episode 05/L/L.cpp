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

int n, m, q [20] = {0}, r;
string cand [20], party [20], t, ans;

int main ()
{

	freopen ("l.in", "r", stdin);
//	ofstream out (NAME".out");

	cin >> n;
	getline (cin, cand [0]);

	for (int i = 0; i < n; i++)
	{
		getline (cin, cand [i]);
		getline (cin, party [i]);	
	}

	cin >> m;
	getline (cin, t);

	r = 0;

	for (int i = 0; i < m; i++)
	{
		getline (cin, t);

		for (int j = 0; j < n; j++)
			if (t == cand [j])
			{
				q [j]++;

				if (q [j] == r)
					ans = "tie";

				if (q [j] > r)
				{
					r = q [j];
					ans = party [j];
				}

				break;
			}
	}

	cout << ans << endl;	

	return 0;

}	