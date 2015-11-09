#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <map>
#include <ctime>
#include <cctype>
#include <cassert>
#include <memory>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <iterator>

#define NAME "j"
#define INF (int) 1e9 + 7
#define INFLONG (ll) 1e18 + 7
#define EPS 1e-9
#define pb push_back
#define mp make_pair
#define frs first
#define snd second
#define rep0(i, n) for (int i = 0; i < n; i++)
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repd0(i, n) for (int i = (n - 1); i > -1; i--)
#define repd(i, l, r) for (int i = (r - 1); i > (l - 1); i--)

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int main ()
{
    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    int x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4;

    scanf ("%d %d %d\n", &x1, &y1, &z1);
    scanf ("%d %d %d\n", &x2, &y2, &z2);
    scanf ("%d %d %d\n", &x3, &y3, &z3);
    scanf ("%d %d %d\n", &x4, &y4, &z4);

    ll res1 = 1ll * (ll) (x2 - x1) * (ll) (x4 - x3);
    ll res2 = 1ll * (ll) (y2 - y1) * (ll) (y4 - y3);
    ll res3 = 1ll * (ll) (z2 - z1) * (ll) (z4 - z3);
    ll res = res1 + res2 + res3;

    if (res != 0)
    {
        puts ("Invalid");
        return 0;
    }

    ll a1 = x3 - x1;
    ll a2 = y3 - y1;
    ll a3 = z3 - z1;
    ll a4 = x2 - x1;
    ll a5 = y2 - y1;
    ll a6 = z2 - z1;
    ll a7 = x4 - x3;
    ll a8 = y4 - y3;
    ll a9 = z4 - z3;

    ll det = 1ll * a1 * a5 * a9;
    det += 1ll * a2 * a6 * a7;
    det += 1ll * a3 * a4 * a8;
    det -= 1ll * a3 * a5 * a7;
    det -= 1ll * a2 * a4 * a9;
    det -= 1ll * a1 * a6 * a8;

    if (det != 0ll)
    {
        puts ("Invalid");
        return 0;
    }

    char good = 0;

/*
    ll del_cx = (ll) (y2 - y1) * (ll) (x4 - x3) - (ll) (y4 - y3) * (ll) (x2 - x1);
    ll del_cy = (ll) (x2 - x1) * (ll) (y4 - y3) - (ll) (x4 - x3) * (ll) (y2 - y1);
    ll del_cz = (ll) (y2 - y1) * (ll) (z4 - z3) - (ll) (y4 - y3) * (ll) (z2 - z1);
    ll p1 = (ll) (x2 - x1);
    ll q1 = (ll) (y2 - y1);
    ll r1 = (ll) (z2 - z1);
    ll p2 = (ll) (x4 - x3);
    ll q2 = (ll) (y4 - y3);
    ll r2 = (ll) (z4 - z3);
    ll chis_cx = (ll) (x1) * q1 * p2 - (ll) (x3) * q2 * p1 - (ll) (y1) * p1 * p2 + (ll) (y3) * p1 * p2;
    ll chis_cy = (ll) (y1) * p1 * q2 - (ll) (y3) * p2 * q1 - (ll) (x1) * q1 * q2 + (ll) (x3) * q1 * q2;
    ll chis_cz = (ll) (z1) * q1 * r2 - (ll) (z3) * q2 * r1 - (ll) (y1) * r1 * r2 + (ll) (y3) * r1 * r2;
    double cx = (double) ((ld) (chis_cx) / (ld) del_cx);
    double cy = (double) ((ld) (chis_cy) / (ld) del_cy);
    double cz = (double) ((ld) (chis_cz) / (ld) del_cz);
    char good = 0;

    if (fabs (del_cx) < EPS && fabs (del_cy) < EPS)
    {
        puts ("Invalid");
        return 0;
    }

    if (fabs (del_cx) < EPS && fabs (del_cz) < EPS)
    {
        puts ("Invalid");
        return 0;
    }

    if (fabs (del_cy) < EPS && fabs (del_cz) < EPS)
    {
        puts ("Invalid");
        return 0;
    }

    if (fabs (del_cx) < EPS)
        cx = 0.0;

    if (fabs (del_cy) < EPS)
        cy = 0.0;

    if (fabs (del_cz) < EPS)
        cz = 0.0;

    if ((x2 >= x1 && cx >= x2) || (x2 <= x1 && cx <= x2))
        good = 1;
    else
    {
        puts ("Invalid");
        return 0;
    }

    if ((y2 >= y1 && cy >= y2) || (y2 <= y1 && cy <= y2))
        good = 1;
    else
    {
        puts ("Invalid");
        return 0;
    }

    if ((z2 >= z1 && cz >= z2) || (z2 <= z1 && cz <= z2))
        good = 1;
    else
    {
        puts ("Invalid");
        return 0;
    }

    if ((x3 >= x4 && cx >= x3) || (x3 <= x4 && cx <= x3))
        good = 1;
    else
    {
        puts ("Invalid");
        return 0;
    }

    if ((y3 >= y4 && cy >= y3) || (y3 <= y4 && cy <= y3))
        good = 1;
    else
    {
        puts ("Invalid");
        return 0;
    }

    if ((z3 >= z4 && cz >= z3) || (z3 <= z4 && cz <= z3))
        good = 1;
    else
    {
        puts ("Invalid");
        return 0;
    }

*/

    if (((x1 >= x2) && (x2 >= x3)) && ((y1 >= y2) && (y2 >= y3)) && ((z1 >= z2) && (z2 >= z3)))
        good = 1;

    if (((x1 <= x2) && (x2 <= x3)) && ((y1 >= y2) && (y2 >= y3)) && ((z1 >= z2) && (z2 >= z3)))
        good = 1;

    if (((x1 >= x2) && (x2 >= x3)) && ((y1 <= y2) && (y2 <= y3)) && ((z1 >= z2) && (z2 >= z3)))
        good = 1;

    if (((x1 <= x2) && (x2 <= x3)) && ((y1 <= y2) && (y2 <= y3)) && ((z1 >= z2) && (z2 >= z3)))
        good = 1;

    if (((x1 >= x2) && (x2 >= x3)) && ((y1 >= y2) && (y2 >= y3)) && ((z1 <= z2) && (z2 <= z3)))
        good = 1;

    if (((x1 <= x2) && (x2 <= x3)) && ((y1 >= y2) && (y2 >= y3)) && ((z1 <= z2) && (z2 <= z3)))
        good = 1;

    if (((x1 >= x2) && (x2 >= x3)) && ((y1 <= y2) && (y2 <= y3)) && ((z1 <= z2) && (z2 <= z3)))
        good = 1;

    if (((x1 <= x2) && (x2 <= x3)) && ((y1 <= y2) && (y2 <= y3)) && ((z1 <= z2) && (z2 <= z3)))
        good = 1;

    char good2 = 0;
    
    if (((x2 >= x3) && (x3 >= x4)) && ((y2 >= y3) && (y3 >= y4)) && ((z2 >= z3) && (z3 >= z4)))
        good2 = 1;

    if (((x2 <= x3) && (x3 <= x4)) && ((y2 >= y3) && (y3 >= y4)) && ((z2 >= z3) && (z3 >= z4)))
        good2 = 1;

    if (((x2 >= x3) && (x3 >= x4)) && ((y2 <= y3) && (y3 <= y4)) && ((z2 >= z3) && (z3 >= z4)))
        good2 = 1;

    if (((x2 <= x3) && (x3 <= x4)) && ((y2 <= y3) && (y3 <= y4)) && ((z2 >= z3) && (z3 >= z4)))
        good2 = 1;

    if (((x2 >= x3) && (x3 >= x4)) && ((y2 >= y3) && (y3 >= y4)) && ((z2 <= z3) && (z3 <= z4)))
        good2 = 1;

    if (((x2 <= x3) && (x3 <= x4)) && ((y2 >= y3) && (y3 >= y4)) && ((z2 <= z3) && (z3 <= z4)))
        good2 = 1;

    if (((x2 >= x3) && (x3 >= x4)) && ((y2 <= y3) && (y3 <= y4)) && ((z2 <= z3) && (z3 <= z4)))
        good2 = 1;

    if (((x2 <= x3) && (x3 <= x4)) && ((y2 <= y3) && (y3 <= y4)) && ((z2 <= z3) && (z3 <= z4)))
        good2 = 1;

    char good3 = 0;

    if (((x2 >= x3) && (x3 >= x4)) && ((y1 >= y2) && (y2 >= y3)))
        good3 = 1;

    if (((x2 <= x3) && (x3 <= x4)) && ((y1 >= y2) && (y2 >= y3)))
        good3 = 1;

    if (((x2 >= x3) && (x3 >= x4)) && ((y1 <= y2) && (y2 <= y3)))
        good3 = 1;

    if (((x2 <= x3) && (x3 <= x4)) && ((y1 <= y2) && (y2 <= y3)))
        good3 = 1;

    if (((x2 >= x3) && (x3 >= x4)) && ((z1 >= z2) && (z2 >= z3)))
        good3 = 1;

    if (((x2 <= x3) && (x3 <= x4)) && ((z1 >= z2) && (z2 >= z3)))
        good3 = 1;

    if (((x2 >= x3) && (x3 >= x4)) && ((z1 <= z2) && (z2 <= z3)))
        good3 = 1;

    if (((x2 <= x3) && (x3 <= x4)) && ((z1 <= z2) && (z2 <= z3)))
        good3 = 1;

    if (((y2 >= y3) && (y3 >= y4)) && ((z1 >= z2) && (z2 >= z3)))
        good3 = 1;

    if (((y2 <= y3) && (y3 <= y4)) && ((z1 >= z2) && (z2 >= z3)))
        good3 = 1;

    if (((y2 >= y3) && (y3 >= y4)) && ((z1 <= z2) && (z2 <= z3)))
        good3 = 1;

    if (((y2 <= y3) && (y3 <= y4)) && ((z1 <= z2) && (z2 <= z3)))
        good3 = 1;

    if (!good || !good2 || !good3)
    {
        puts ("Invalid");
        return 0;
    }
    
    puts ("Valid");

    return 0;
}
