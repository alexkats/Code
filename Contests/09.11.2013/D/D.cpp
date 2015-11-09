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
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "d"
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
string t1, t2, t3;

int main ()
{
//	freopen (NAME".in", "r", stdin);
//	freopen (NAME".out", "w", stdout);

	getline (cin, s);

	int n = s.length ();

	s [1] = (char) ((int) s [1] + 32);

	int st1 = -1;
	int st2 = -1;
	int st3 = -1;
	int len1 = 0;
	int len2 = 0;
	int len3 = 0;
	int curr = 0;

	rep0(i, n)
	{
		if (s [i] == '{')
		{
			st1 = i;
			continue;
		}

		if (s [i] == '}')
		{
			t1 = s.substr (st1 + 1, len1);

			if (curr == 0)
				t1 [0] = (char) ((int) s [st1 + 1] - 32);

			len1 = 0;
			st1 = -1;
			continue;
		}

		if (s [i] == '(')
		{
			st2 = i;
			continue;
		}

		if (s [i] == ')')
		{
			t2 = s.substr (st2 + 1, len2);
			len2 = 0;
			st2 = -1;
			continue;
		}

		if (s [i] == '[')
		{
			st3 = i;
			continue;
		}
	
		if (s [i] == ']')
		{
			t3 = s.substr (st3 + 1, len3);
			len3 = 0;
			st3 = -1;
			continue;
		}

		if (s [i] == ',')
		{
			curr++;
			cout << t1 << " " << t2 << " " << t3 << ",";
			t1 = "";
			t2 = "";
			t3 = "";
			continue;
		}	

		if (st1 != -1)
			len1++;
		else if (st2 != -1)
			len2++;
		else if (st3 != -1)
			len3++;

		if (t1 == "" && t2 == "" && t3 == "" && st1 == -1 && st2 == -1 && st3 == -1)
			cout << s [i];
	}

	cout << t1 << " " << t2 << " " << t3 << endl;	

	return 0;
}	