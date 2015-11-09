#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int w, h, a, b, w1, h1, kw, kh, q, wz, hz;

bool flag = true;

int main ()
{

	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	cin >> w >> h;
	cin >> a >> b;

	if (w % a == 0 && h % b == 0)
	{
		q = (w / a) * (h / b);
		cout << q;
		return 0;
	}

	if (w % a == 0)
	{
		q = (w / a) * (h / b);
		h1 = h % b;
		kh = b / h1;
		q += (w / a) / kh;
		
		if ((w / a) % kh != 0)
			q++;
		
		cout << q;
		return 0;
	}

	if (h % b == 0)
	{
		q = (w / a) * (h / b);
		w1 = w % a;
		kw = a / w1;
		q += (h / b) / kw;

		if ((h / b) % kw != 0)
			q++;

		cout << q;
		return 0;

	}	

	q = (w / a) * (h / b);
	w1 = w % a;
	h1 = h % b;
	wz = w / a;
	hz = h / b;
	kw = a / w1;
	kh = b / h1;
	q += (w / a) / kh;
	q += (h / b) / kw;

	if ((w / a) % kh != 0)
		q++;
	else
		flag = false;

	if ((h / b) % kw != 0)
	{
		q++;
		flag = true;
	}

	if (! flag)
		q++;

	cout << q;
	
	return 0;

}