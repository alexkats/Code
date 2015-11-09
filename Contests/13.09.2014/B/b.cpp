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

#define NAME "b"
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
#define N 300005

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int n;
ll x;
int t1 [N * 4];
int t2 [N * 4];
int a [N];

void build_max (int v, int l, int r)
{
    if (l == r)
        t1 [v] = a [l];
    else
    {
        int m = (l + r) >> 1;
        build_max (v * 2, l, m);
        build_max (v * 2 + 1, m + 1, r);
        t1 [v] = max (t1 [v * 2], t1 [v * 2 + 1]);
    }
}

void build_min (int v, int l, int r)
{
    if (l == r)
        t2 [v] = a [l];
    else
    {
        int m = (l + r) >> 1;
        build_min (v * 2, l, m);
        build_min (v * 2 + 1, m + 1, r);
        t2 [v] = min (t2 [v * 2], t2 [v * 2 + 1]);
    }
}

int find_max (int v, int l, int r, int left, int right)
{
    if (left > right)
        return 0;

    if (l == left && r == right)
        return t1 [v];

    int m = (l + r) >> 1;
    return max (find_max (v * 2, l, m, left, min (m, right)), find_max (v * 2 + 1, m + 1, r, max (m + 1, left), right));
}

int find_min (int v, int l, int r, int left, int right)
{
    if (left > right)
        return INF;

    if (l == left && r == right)
        return t2 [v];

    int m = (l + r) >> 1;
    return min (find_min (v * 2, l, m, left, min (m, right)), find_min (v * 2 + 1, m + 1, r, max (m + 1, left), right));
}

int main ()
{
    while (cin >> n >> x)
    {

    int start = 0;
    int ans = -(INF);
    ll sum = 0ll;

    rep0(i, n)
        scanf ("%d", &a [i]);

    int curr = 0;
    int r = a [0];
    int l = a [0];
    build_min (1, 0, n - 1);
    build_max (1, 0, n - 1);
    char fin = 0;
    int ans_l, ans_r;

    while (!fin)
    {
        sum += a [curr];

        if (sum > x || fin)
        {
            sum -= a [curr];

            if (curr > start)
            {
                l = find_min (1, 0, n - 1, start, curr - 1);
                r = find_max (1, 0, n - 1, start, curr - 1);
            }
            else
            {
                l = min (find_min (1, 0, n - 1, start, n - 1), find_min (1, 0, n - 1, 0, curr - 1));
                r = max (find_max (1, 0, n - 1, start, n - 1), find_max (1, 0, n - 1, 0, curr - 1));
            }

            int res = r - l;

            if (res > ans)
            {
                ans = res;
                ans_l = start;
                ans_r = curr ? curr - 1 : n - 1;
            }

            sum += a [curr];

            while (sum > x)
            {
                sum -= a [start];
                start++;
                
                if (start == n)
                    fin = 1;

                start %= n;
            }
        }

        curr++;
        curr %= n;

        if (curr == start && start == 0)
        {
            printf ("%d %d\n", 1, n);
            fin = 2;
            break;
        }
    }

    if (fin == 1)
        printf ("%d %d\n", ++ans_l, ++ans_r);
    
    }

    return 0;
}
