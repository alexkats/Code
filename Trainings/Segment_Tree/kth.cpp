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

#define NAME "kth"
#define maxn 1000

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

pair <int, int> t [maxn * 4];

int a [maxn], n;

pair <int, int> combine (pair <int, int> a, pair <int, int> b)
{
	if (b.first == 0)
		return make_pair (a.first, a.second);
	else
		return make_pair (a.first + b.first, b.second);
}	

void build (int a [], int v, int trl, int trr)
{
	if (trl == trr)
		if (a [trl] == 0)
			t [v] = make_pair (1, trl);
		else
			t [v] = make_pair (0, trl);
	else
	{
		int trm = (trl + trr) / 2;
		build (a, v * 2, trl, trm);
		build (a, v * 2 + 1, trm + 1, trr);
		t [v] = combine (t [v * 2], t [v * 2 + 1]);
	}
}

void update (int v, int trl, int trr, int pos, int new_val)
{
	if (trl == trr)
		if (new_val == 0)
			t [v] = make_pair (1, trl);
		else
			t [v] = make_pair (0, trl);
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

int quantity (int v, int trl, int trr, int l, int r)
{
	if (l > r)
		return 0;

	if (l == trl && r == trr)
		return t [v].first;

	int trm = (trl + trr) / 2;	

	return quantity (v * 2, trl, trm, l, min (r, trm)) + quantity (v * 2 + 1, trm + 1, trr, max (l, trm + 1), r);
}

int find_kth (int v, int trl, int trr, int k)
{
	if (k > t [v].second)
		return -1;

	if (trl == trr)
		return trl;

	int trm = (trl + trr) / 2;

	if (t [v * 2].second >= k)
		return find_kth (v * 2, trl, trm, k);
	else
		return find_kth (v * 2 + 1, trm + 1, trr, k);
}	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> n;

	for (int i = 0; i < n; i++)
		in >> a [i];

	build (a, 1, 0, n - 1);

	out << quantity (1, 0, n - 1, 0, 2) << endl;

	update (1, 0, n - 1, 0, 0);

	out << quantity (1, 0, n - 1, 0, 2) << endl;

	out << find_kth (1, 0, n - 1, 1) << endl;	

	return 0;

}	