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

#define NAME "kmax"
#define maxn 1000
#define INF 1e7

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int a [maxn], n;

pair <int, int> t [maxn * 4];

pair <int, int> combine (pair <int, int> a, pair <int, int> b)
{
	if (a.first > b.first)
		return a;

	if (b.first > a.first)
		return b;

	return make_pair (a.first, a.second + b.second);
}

void build (int a [], int v, int trl, int trr)
{
	if (trl == trr)
		t [v] = make_pair (a [trl], 1);
	else
	{
		int trm = (trl + trr) / 2;
		build (a, v * 2, trl, trm);
		build (a, v * 2 + 1, trm + 1, trr);
		t [v] = combine (t [v * 2], t [v * 2 + 1]);
	}
}

pair <int, int> get_max (int v, int trl, int trr, int l, int r)
{
	if (l > r)
		return make_pair (-INF, 0);

	if (l == trl && r == trr)
		return t [v];

	int trm = (trl + trr) / 2;

	return combine (get_max (v * 2, trl, trm, l, min (r, trm)), get_max (v * 2 + 1, trm + 1, trr, max (l, trm + 1), r));
}

void update (int v, int trl, int trr, int pos, int new_val)
{
	if (trl == trr)
		make_pair (new_val, 1);
	else
	{
		int trm = (trl + trr) / 2;

		if (pos <= trm)
			update (v * 2, trl, trm, pos, new_val);
		else
			update (v * 2 + 1, trm + 1, trr, pos, new_val);

		t [v] = combine (t [v * 2], t [v * 2 + 1]);
	}
}	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> n;

	for (int i = 0; i < n; i++)
		in >> a [i];

	build (a, 1, 0, n - 1);

	pair <int, int> k = get_max (1, 0, n - 1, 1, 3);

	out << k.first << " " << k.second << endl;	

	return 0;

}	