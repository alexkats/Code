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

#define NAME "dt"
#define maxn 1000
#define INF 1000

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

vector <int> t [maxn * 4];

void build (int a [], int v, int trl, int trr)
{
	if (trl == trr)
		t [v] = vector <int> (1, a [trl]);
	else
	{
		int trm = (trl + trr) / 2;
		build (a, v * 2, trl, trm);
		build (a, v * 2 + 1, trm + 1, trr);
		merge (t [v * 2].begin (), t [v * 2].end (), t [v * 2 + 1].begin (), t [v * 2 + 1].end (), back_inserter (t [v]));
	}
}

int query (int v, int trl, int trr, int l, int r, int x)
{
	if (l > r)
		return INF;

	if (l == trl && r == trr)
	{
		vector <int>::iterator pos = lower_bound (t [v].begin (), t [v].end (), x);

		if (pos != t [v].end ())
			return *pos;

		return INF;
	}

	int trm = (trl + trr) / 2;

	return min (query (v * 2, trl, trm, l, min (r, trm), x), query (v * 2 + 1, trm + 1, trr, max (trm + 1, trr), r, x));
}

int a [maxn], n;	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> n;

	for (int i = 0; i < n; i++)
		in >> a [i];

	sort (a, a + n);	

	build (a, 1, 0, n - 1);

	out << query (1, 0, n - 1, 1, 3, 7) << endl;	

	return 0;

}	