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
  
#define NAME "smallnim"
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
 
int a, ans, n;
 
int main ()
{
 
    freopen (NAME".in", "r", stdin);
    freopen ("old.out", "w", stdout);
 
    scanf ("%d", &n);
 
    bool ok = 1;
 
    rep0(i, n)
    {
        scanf ("%d", &a);
         
        if (i == 0 && a == 1)
            ok = 0;
 
        if (i == 0)
            ans = a - 1;
 
        if (a == 1 && i != 0)
        {
            ok = !ok;
            ans = 1;
        }   
    }
 
    if (ok)
        printf ("YES\n%d\n", ans);
    else
        puts ("NO");    
 
    return 0;
 
}