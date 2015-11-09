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

int n, m, t, c;

int main ()
{
    freopen ("parking.in", "r", stdin);
    freopen ("parking.out", "w", stdout);

    cin >> n >> m;

    t = n / 2;
    c = t;
    t = m / 2;
    c *= t;

    if (n % 2 == 0 && m % 2 == 0)
    {
    	cout << c;
    	return 0;
    }	

    if (n % 2 != 0)
        for (int i = 1; i <= m / 2; i++)
            c++;

    if (m % 2 != 0)
        for (int i = 1; i <= n / 2; i++)
            c++;

    if (n % 2 != 0 && m % 2 != 0)
    	c++;

    cout << c;

    return 0;
}