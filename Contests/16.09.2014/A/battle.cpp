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

#define NAME "battle"
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

struct tt
{
    int timing;
    int index;

    tt () {}
    tt (int t, int i) { timing = t; index = i; }
};

bool cmp (tt a, tt b)
{
    return a.timing < b.timing;
}

tt t [100005];
int n;

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);

    scanf ("%d", &n);

    rep0(i, n)
    {
        int x;
        scanf ("%d", &x);
        t [i]  = tt (x, i);
    }

    sort (t, t + n, cmp);

    if (n > 6)
    {
        int cnt = 0;

        for (int i = 1; i < n; i++)
            if (t [i - 1].timing == t [i].timing)
                cnt++;
            else
                break;

        

    if (n % 3 == 0)
    {
        ll total = 0ll;
        
        rep0(i, n / 3)
        {
            total += (t [i * 3 + 2].timing - t [i * 3 + 1].timing);
            total += (t [i * 3 + 2].timing - t [i * 3].timing);
        }

        printf (lld" %d\n", total, n / 3);

        rep0(i, n / 3)
            printf ("3 %d %d %d\n", t [i * 3].index + 1, t [i * 3 + 1].index + 1, t [i * 3 + 2].index + 1);

        return 0;
    }

    ll res = INFLONG;
    int num;

    if (n % 3 == 1)
    {
        ll total = 0ll;

        for (int i = 3; i < n; i += 3)
            if ((3ll * t [i].timing - t[i - 1].timing - t [i - 2].timing - t [i - 3].timing) < res)
            {
                res = 3ll * t [i].timing - t [i - 1].timing - t [i - 2].timing - t [i - 3].timing;
                num = i;
            }

        int c = -1;

        rep0(i, n)
        {
            c++;
            c %= 3;

            if (num == i)
            {
                c--;
                continue;
            }

            if (c % 3 == 0 && num != (i + 3))
            {
                total += (t [i + 2].timing - t [i].timing);
                continue;
            }

            if (c % 3 == 0 && num == (i + 3))
            {
                total += (t [i + 3].timing - t [i].timing);
                continue;
            }

            if (c % 3 == 1 && num == (i + 2))
            {
                total += (t [i + 2].timing - t [i].timing);
                continue;
            }

            if (c % 3 == 1)
                total += (t [i + 1].timing - t [i].timing);

            if (c % 3 == 2 && num == (i + 1))
                total += (t [i + 1].timing - t [i].timing);
        }

        printf (lld" %d\n", total, n / 3);

        c = -1;

        rep0(i, n)
        {
            c++;
            c %= 3;

            if (c % 3 == 0 && num == i)
            {
                printf ("%d\n", t [i].index + 1);
                c--;
                continue;
            }

            if (c % 3 == 0 && num != (i + 3))
            {
                printf ("3 %d ", t [i].index + 1);
                continue;
            }

            if (c % 3 == 0 && num == (i + 3))
            {
                printf ("4 %d ", t [i].index + 1);
                continue;
            }

            if (c % 3 == 1)
            {
                printf ("%d ", t [i].index + 1);
                continue;
            }

            if (c % 3 == 2 && num != (i + 1))
                printf ("%d\n", t [i].index + 1);
            else
                printf ("%d ", t [i].index + 1);
        }

        return 0;
    }

    if (n == 5)
    {
        ll total = 0ll;
        total += 4ll * t [4].timing;
        total -= t [3].timing;
        total -= t [2].timing;
        total -= t [1].timing;
        total -= t [0].timing;
        printf (lld" 1\n", total);
        printf ("5 1 2 3 4 5\n");
        return 0;
    }

    rep0(i, n)
        t [i].index++;

    ll ans = INFLONG;
    int k = 0;
    int ans_k = 0;

    for (int i = 7; i < n; i += 3)
    {
        ll res1 = 0ll;
        ll res2 = 0ll;
        ll res3 = 0ll;
        res1 = 2ll * t [i - 5].timing - t [i - 6].timing - t [i - 7].timing;
        res1 += 4ll * t [i].timing - t [i - 1].timing - t [i - 2].timing - t [i - 3].timing - t [i - 4].timing;
        res2 = 2ll * t [i].timing - t [i - 1].timing - t [i - 2].timing;
        res2 += 4ll * t [i - 3].timing - t [i - 4].timing - t [i - 5].timing - t [i - 6].timing - t [i - 7].timing;
        res3 = 3ll * t [i].timing - t [i - 1].timing - t [i - 2].timing - t [i - 3].timing;
        res3 += 3ll * t [i - 4].timing - t [i - 5].timing - t [i - 6].timing - t [i - 7].timing;
        ll res = min (res1, min (res2, res3));
        
        if (res == res1)
            k = 1;

        if (res == res2)
            k = 2;

        if (res == res3)
            k = 3;

        ans = min (ans, res);
        
        if (ans == res)
        {
            ans_k = k;
            num = i - 7;
        }
    }

    ll total = 0ll;
    total += ans;
    int c = 0;

    rep0(i, n)
    {
        if (num == i)
        {
            i += 8;
            c = 0;
            continue;
        }

        if (c % 3 == 0)
        {
            total += (t [i + 2].timing - t [i].timing);
            c++;
            continue;
        }

        if (c % 3 == 1)
        {
            total += (t [i + 1].timing - t [i].timing);
            c++;
            continue;
        }

        if (c % 3 == 2)
            c = 0;
    }

    printf (lld" %d\n", total, n / 3);

    c = 0;

    rep0(i, n)
    {
        if (num == i)
        {
            if (ans_k == 1)
                printf ("3 %d %d %d\n5 %d %d %d %d %d\n", t [i].index, t [i + 1].index, t [i + 2].index, t [i + 3].index, t [i + 4].index, t [i + 5].index, t [i + 6].index, t [i + 7].index);

            if (ans_k == 2)
                printf ("5 %d %d %d %d %d\n3 %d %d %d\n", t [i].index, t [i + 1].index, t [i + 2].index, t [i + 3].index, t [i + 4].index, t [i + 5].index, t [i + 6].index, t [i + 7].index);

            if (ans_k == 3)
                printf ("4 %d %d %d %d\n4 %d %d %d %d\n", t [i].index, t [i + 1].index, t [i + 2].index, t [i + 3].index, t [i + 4].index, t [i + 5].index, t [i + 6].index, t [i + 7].index);

            i += 8;
            c = 0;
            continue;
        }

        if (c % 3 == 0)
        {
            printf ("3 %d %d %d\n", t [i].index, t [i + 1].index, t [i + 2].index);
            c++;
            continue;
        }

        if (c % 3 == 1)
        {
            c++;
            continue;
        }

        if (c % 3 == 2)
            c = 0;
    }
        
    return 0;
}
