#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <utility>
#include <time.h>
#include <vector>
#include <algorithm>


#define pb push_back
#define pp pop_back
#define mp make_pair
#define infint 1e9
#define inflong 1e18
#define fori0 for(int i = 0; i < n; i++)
#define forj0 for(int j = 0; j < n; j++)
#define fori1 for(int i = 1; i <= n; i++)
#define forj1 for(int j = 1; j <= n; j++)
#define forxx(i, n, s) for(int i = 0; i < n; i += s)
#define name "spy"


typedef long long ll;
typedef unsigned long long ull;


using namespace std;


int main()
{
    freopen(name".in", "r", stdin);
    freopen(name".out", "w", stdout);
    ll r, ax, ay, bx, by;
    cin >> r >> ax >> ay >> bx >> by;
    ll a = by - ay;
    ll b = ax - bx;
    ll c = (ay * (-b) - ax * a);
 
    if (ay == by)
    {
    	a = 0;
       	b = 1;
        c = -ay;
    }
 
    if (ax == bx)
    {
        a = 1;
        b = 0;
        c = -ax;
    }
    bool f = 0;
    if (bx * bx + by * by >= c*c/(a*a + b*b) + (bx-ax)*(bx-ax) + (by-ay)*(by-ay))
    	f = 1;
    else
    	f = 0;

    if (f) 
    	cout << "YES";
    else             
    	cout << "NO";	   
       

    return 0;
}