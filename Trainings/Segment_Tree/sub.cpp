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

#define NAME "sub"
#define maxn 1000

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

struct data
{
	int sum, pref, suff, ans;
};

data t [maxn * 4];

int a [maxn], n;

data combine (data l, data r)
{
	data res;

	res.sum = l.sum + r.sum;
	res.pref = max (l.pref, l.sum + r.pref);
	res.suff = max (r.suff, r.sum + l.pref);
	res.ans = max (max (l.ans, r.ans), l.suff + r.pref);

	return res;
}

data make_data (int val)
{
	data res;

	res.sum = val;
	res.pref = res.suff = res.ans = max (0, val);

	return res;
}

void build (int a [], int v, int trl, int trr)
{
	if (trl == trr)
		t [v] = make_data (a [trl]);
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
		t [v] = make_data (new_val);
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

data query (int v, int trl, int trr, int l, int r)
{
	if (l == trl && r == trr)
		return t [v];

	int trm = (trl + trr) / 2;

	if (r <= trm)
		return query (v * 2, trl, trm, l, r);

	if (l > trm)
		return query (v * 2 + 1, trm + 1, trr, l, r);

	return combine (query (v * 2, trl, trm, l, trm), query (v * 2 + 1, trm + 1, trr, trm + 1, r));
}	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> n;

	for (int i = 0; i < n; i++)
		in >> a [i];

	build (a, 1, 0, n - 1);

	data k = query (1, 0, n - 1, 4, 7);

	out << k.ans << endl;	

	return 0;

}	