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
#define forup (i, 0, n) for (int i = 0; i < n; i++)
#define fordown (i, n, 0) for (int i = (n - 1); i > -1; i--)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

ull sqr (ll a)
{
	ull c = a * a;

	return c;
}	

using namespace std;
                              
int main ()
{

//	ifstream in (NAME".in");
//	ofstream out (NAME".out");

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a [i];

	vector <char> str;

	for (int i = 0; i < n; i++)
		str.push_back ();

	str.reverse (str.begin (), str.end () - 1);		

	return 0;

}	