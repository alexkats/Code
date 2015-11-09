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

#define NAME "illumination"
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

const int N = 100005;

int n;
int a [N];
int b [N];
int t [N];
int start [N];
int len [N];

int main ()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    memset (len, 1, sizeof (len));

    cin >> n;

    rep0(i, n)
        cin >> a [i];

    rep0(i, n)
        cin >> b [i];

    rep0(i, n)
        t [i] = a [i] - b [i];

    int cnt = 0;

    rep0(i, n)
    {
        if (t [i] > 0 && i > 0 && t [i - 1] > 0)
        {
            len [cnt]++;
            continue;
        }

        if (t [i] > 0 && (i == 0 || t [i - 1] <= 0))
        {
            start [cnt] = i;
            continue;
        }

        if (t [i] < 0 && len [cnt] > 0)
        {
            cnt++;
            continue;
        }

        if (t [i] > 0 && (i == n - 1))
        {
            cnt++;
            continue;
        }
    }

    ll ans = 0ll;

    rep0(i, cnt)
    {
        ans += 1ll * len [i] * (len [i] + 1ll) / 2ll;

    return 0;
}
