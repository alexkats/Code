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

int a, n, ans, q [100001], prev [100001], d [100001];
bool z [100001];

int main ()
{

//	ifstream in (NAME".in");
//	ofstream out (NAME".out");

	cin >> n;

	for (int i = 0; i < 100000; i++)
		z [i + 1] = true;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		q [a]++;

		if (q [a] == 1)
			prev [a] = i;
		else if (q [a] == 2)
			d [a] = i - prev [a];
		else
		{
			if (d [a] != i - prev [a])
				z [a] = false;
		}

		prev [a] = i;
	}

	for (int i = 0; i < 100000; i++)
		if (z [i + 1] && q [i + 1] != 0)
			ans++;

	cout << ans << endl;

	for (int i = 0; i < 100000; i++)
		if (z [i + 1] && q [i + 1] != 0)
			cout << i + 1 << " " << d [i + 1] << endl;	

	return 0;

}	