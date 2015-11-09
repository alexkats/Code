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
#include <bitset>
#include <map>
#include <cassert>
#include <memory>
#include <ctime>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "examinator"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a
#define mp make_pair
#define frs first
#define snd second
#define pb push_back
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif	

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

const int N = 100010;

int n;
int st;
int l, r;

struct item
{
	int key, prior;
	item *l, *r, *p;
};

typedef item * pitem;

item element [N];
pitem t;
vector <pitem> res;

int fnd (pitem t)
{
	return t ? t->key : 0;
}

void push (pitem t)
{
	if (t)
	{
		t->key = fnd (t->l) + fnd (t->r) + 1;

		if (t->l)
			t->l->p = t;

		if (t->r)
			t->r->p = t;
	}
}

void split (pitem t, pitem &left, pitem &right, int key)
{
	if (!t)
		return void (left = right = 0);

	if (key <= fnd (t->l))
	{
		split (t->l, left, t->l, key);
		right = t;
	}
	else
	{
		split (t->r, t->r, right, key - fnd (t->l) - 1);
		left = t;
	}

	push (t);
}	

void merge (pitem &t, pitem left, pitem right)
{
	if (!(left && right))
		t = left ? left : right;
	else if (left->prior > right->prior)
	{
		merge (left->r, left->r, right);
		t = left;
	}
	else
	{
		merge (right->l, left, right->l);
		t = right;
	}

	push (t);
}	

int solve (pitem t)
{
	res.clear ();
	pitem s = t;
	int ans = 0;
	res.pb (s);

	while (s->p != 0)
	{
		s = s->p;
		res.pb (s);
	}

	ans = fnd (t->l);

	rep0(i, (int) res.size () - 1)
		ans += (res [i + 1]->r == res [i]) ? (fnd (res [i + 1]->l) + 1) : 0;

	return ans;
}	

int main ()
{
	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	scanf ("%d", &n);

	rep0(i, N)
		element [i].prior = -1;

	element [0].prior = (rand () << 17) + rand ();
	merge (t, t, &element [0]);
	t->p = 0;	

	rep0(i, n)
	{
		scanf ("%d", &st);

		if (st == 0)
		{
			scanf ("%d %d", &l, &r);

			if (element [l].prior == -1 || element [r].prior == -1)
			{
				puts ("0");
				continue;
			}

			int left = solve (&element [l]);
			int right = solve (&element [r]);

			printf ("%d\n", abs (right - left) + 1);

			continue;
		}

		if (st == 1)
		{
			scanf ("%d %d", &l, &r);

			element [l].prior = (rand () << 17) + rand ();
			element [l].p = 0;
			int a = solve (&element [r]);

			pitem s1, s2;
			split (t, s1, s2, a + 1);
			t->p = 0;
			merge (t, s1, &element [l]);
			t->p = 0;
			merge (t, t, s2);
			t->p = 0;

			continue;
		}

		if (st == 2)
		{
			scanf ("%d", &l);

			pitem s1, s2, s3;
			int a = solve (&element [l]);

			split (t, s1, s2, a);
			t->p = 0;
			split (s2, s2, s3, 1);
			t->p = 0;
			merge (t, s1, s3);
			t->p = 0;

			element [l].prior = -1;
		}
	}	

	return 0;
}	