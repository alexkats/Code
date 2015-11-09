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
#include <cctype>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>
 
#define NAME "vars"
#define INF 1000000000
#define EPS 0.000000001
#define sqr(a) a*a
#define mp make_pair
#define pb push_back
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld; 
 
using namespace std;

string s;
int ans0 = 0;
int ans1 = 0;
int ans2 = 0;
int ans3 = 0;

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);

	while (getline (cin, s))
	{
		int q = 0;
		string cur = "";
		int curr = 0;

		int n = (int) s.length ();

		rep0(i, n)
			if (s [i] != ' ')
			{
				curr = i;
				break;
			}	

		rep(i, curr, n)
		{
			if (s [i] != ' ' && s [i] != ',' && s [i] != ':')
				continue;
			else if (s [i] == ' ')
				continue;
			else if (s [i] == ',')
				q++;
			else if (s [i] == ':')
			{
				q++;
				curr = i + 1;
				break;
			}
		}

		rep(i, curr, n)
			if (s [i] != ' ')
			{
				curr = i;
				break;
			}

		rep(i, curr, n)
			if (s [i] != ' ' && s [i] != ';')
				cur += s [i];
			else
			{
				if (cur == "boolean")
					ans0 += q;
				else if (cur == "char")
					ans1 += q;
				else if (cur == "double")
					ans2 += q;
				else
					ans3 += q;

				break;
			}
	}

	printf ("boolean: %d\nchar: %d\ndouble: %d\ninteger: %d\n", ans0, ans1, ans2, ans3);

	return 0;

}	