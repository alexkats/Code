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

#define NAME "treap"
#define maxn 1000

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

struct item
{
	int key, prior;
	item * l, * r;
	item () {}
	item (int key, int prior) : key (key), prior (prior), l (NULL), r (NULL) {}
};

typedef item * pitem;

void split (pitem t, int key, pitem & l, pitem & r)
{
	if (!t)
		l = r = NULL;
	else if (key < t->key)
		split (t->l, key, l, t->l), r = t;
	else
		split (t->r, key, t->r, r), l = t;
}

void insert (pitem & t, pitem it)
{
	if (!t)
		t = it;
	else if (it->prior > t->prior)
		split (t, it->key, it->l, it->r), t = it;
	else
		insert (it->key < t->key ? t->l : t->r, it);
}

	

int main ()
{

	ifstream in (NAME".in");
	ofstream out (NAME".out");

	in >> n;

	for (int i = 0; i < n; i++)
	{
		in >> a [i];
		insert (pitem (a [i]) -> n);
	}	

	return 0;

}	