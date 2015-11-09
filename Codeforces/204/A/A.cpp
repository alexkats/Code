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

int a, n, q [2];

int main ()
{

//	ifstream in (NAME".in");
//	ofstream out (NAME".out");

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;

		if (a == 0)
			q [0]++;
		else
			q [1]++;
	}

	if (q [1] < 9 && q [0] != 0)
	{
		cout << 0 << endl;
		return 0;
	}

	if (q [0] == 0)
	{
		cout << -1 << endl;
		return 0;
	}	

	for (int i = 0; i < ((q [1] / 9) * 9); i++)
		cout << 5;

	for (int i = 0; i < q [0]; i++)
		cout << 0;

	cout << endl;	

	return 0;

}	