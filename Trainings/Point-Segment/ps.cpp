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

#define NAME "ps"
#define INF 2000

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

struct new_point
{
	int pl, pr, pq;
};	

vector <int> l, r, lq, rq;
int n;

vector <new_point> t;

void QSort (vector <int> a, vector <int> aq, int bl, int br)
{
	int i = bl;
	int j = br;
	int x = a [rand () % (br - bl + 1) + bl];

	while (i <= j)
	{
		while (a [i] < x)
			i++;

		while (a [j] > x)
			j--;

		if (i <= j)
		{
			swap (a [i], a [j]);
			swap (aq [i], aq [j]);
			i++;
			j--;
		}
	}

	if (bl < j)
		QSort (a, aq, bl, j);

	if (i < br)
		QSort (a, aq, i, br);
}	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> n;

	for (int i = 0; i < n; i++)
	{
		in >> l [i];
		in >> r [i];
		lq [i] = i;
		rq [i] = i;
	}

	QSort (l, lq, 0, n - 1);
	QSort (r, rq, 0, n - 1);

	int k = 0;

	int li = 0, ri = 0;

	while (li < n || ri < n)
	{
		while (li < n && ri < n || l [li] <= r [ri])
		{
			t [k].pl = l [li];
			t [k].pr = INF;
			t [k].pq = lq [li];
			k++;
			li++;
		}

		if (ri < n)
		{
			t [k].pr = r [ri];
			t [k].pl = INF;
			t [k].pq = rq [ri];
			k++;
			ri++;
		}
	}	

		

	return 0;

}	