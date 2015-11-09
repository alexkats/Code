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
 
#define NAME "subtract"
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
int n;
vector <int> a, b;
vector <int> ans;

bool operator >= (vector <int> a, vector <int> b)
{
	if (a.size () > b.size ())
		return 1;

	if (a.size () < b.size ())
		return 0;

	int i = 0;
	int s = (int) a.size ();	

	while (a [i] == b [i])
	{
		i++;

		if (i == s)
			break;
	}	

	if (i == s)
		return 1;

	if (a [i] > b [i])
		return 1;

	return 0;
}

vector <int> sub (vector <int> a, vector <int> b)
{
	reverse (a.begin (), a.end ());
	reverse (b.begin (), b.end ());

	int carry = 0;

	rep0 (i, (int) b.size ())
	{
		a [i] -= b [i] + carry;
		carry = (a [i] < 0);
		a [i] += (carry ? 10 : 0);
	}

	int i = (int) a.size () - 1;

	a [i] -= carry;

	reverse (a.begin (), a.end ());

	i = 0;

	while (a [i] == 0)
		i++;

	if (i)
	{
		reverse (a.begin (), a.end ());

		rep0(j, i)
			a.pop_back ();

		reverse (a.begin (), a.end ());
	}

	if ((int) a.size () == 0)
		a.pb (0);

	return a;
}

vector <int> add (vector <int> a, vector <int> b)
{
	reverse (a.begin (), a.end ());
	reverse (b.begin (), b.end ());

	int carry = 0;

	rep0(i, max ((int) a.size (), (int) b.size ()))
	{
		if (i == (int) a.size ())
			a.pb (0);

		if (i == (int) b.size ())
			b.pb (0);	

		a [i] += carry + b [i];
		carry = (a [i] > 9);
		a [i] -= (carry ? 10 : 0);
	}

	if (carry)
		a.pb (1);

	reverse (a.begin (), a.end ());

	return a;
}	

int main ()
{

	freopen (NAME".in", "r", stdin);
	freopen (NAME".out", "w", stdout);	

	cin >> s;
	n = (int) s.length ();
	int sign_a = 0;
	int sign_b = 0;
	int sign = 0;

	if (s [0] == '-')
	{
		sign_a = 1;
		s = s.substr (1, n - 1);
		n--;
	}	

	rep0(i, n)
		a.pb (atoi (s.substr (i, 1).c_str ()));

	cin >> s;
	n = (int) s.length ();

	if (s [0] == '-')
	{
		sign_b = 1;
		s = s.substr (1, n - 1);
		n--;
	}	

	rep0(i, n)
		b.pb (atoi (s.substr (i, 1).c_str ()));	

	if (sign_a == 0 && sign_b == 0)
		if (a >= b)
		{
			ans = sub (a, b);
			sign = 0;
		}	
		else
		{
			ans = sub (b, a);
			sign = 1;
		}
	else if (sign_a == 0 && sign_b == 1)
	{
		ans = add (a, b);
		sign = 0;
	}
	else if (sign_a == 1 && sign_b == 0)
	{
		ans = add (a, b);
		sign = 1;
	}
	else
		if (a >= b)
		{
			ans = sub (a, b);
			sign = 1;
		}
		else
		{
			ans = sub (b, a);
			sign = 0;
		}

	if ((int) ans.size () == 1 && ans [0] == 0)
		sign = 0;
	
	if (sign)
		printf ("-");

	rep0(i, (int) ans.size ())
		printf ("%d", ans [i]);

	printf ("\n");	

	return 0;

}	