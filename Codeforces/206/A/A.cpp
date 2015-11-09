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

int k, d;

int main ()
{

//	ifstream in (NAME".in");
//	ofstream out (NAME".out");

	cin >> k >> d;

	if (d == 0)
	{
		if (k == 1)
			cout << 0 << endl;
		else
			cout << "No solution" << endl;

		return 0;
	}

	cout << d;

	for (int i = 1; i < k; i++)
		cout << 0;

	cout << endl;	

	return 0;

}	