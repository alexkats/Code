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

//#define NAME ""

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main ()
{

//	ifstream in (NAME".in");
//	ofstream out (NAME".out");

	stack <int> S;

	string s = "a";

	while (s != "exit")
	{
		cin >> s;

		if (s == "exit")
		{
			cout << "bye" << endl;
			continue;
		}	

		if (s == "pop")
		{
			cout << S.top () << endl;
			S.pop ();
			continue;
		}

		if (s == "back")
		{
			cout << S.top () << endl;
			continue;
		}	

		if (s == "size")
		{
			cout << S.size () << endl;
			continue;
		}

		if (s == "clear")
		{
			while (S.size () != 0)
				S.pop ();

			cout << "ok" << endl;
			continue;
		}

		s.erase (0, 5);
		cout << s << endl;
		int r = 0;

		while (s.size () != 0)
		{
			r = r * 10 + s [0] - 48;
			s.erase (s.begin ());
		}

		S.push (r);
		cout << "ok" << endl;
	}	

	return 0;

}	