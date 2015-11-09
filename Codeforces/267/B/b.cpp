#define NAME "b"

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

#define pb push_back
#define mp make_pair
#define frs first
#define snd second

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <bool> vb;

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;

typedef vector <pii> vpii;
typedef vector <pil> vpil;
typedef vector <pli> vpli;
typedef vector <pll> vpll;

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

template <typename T>
T sqr (T a)
{
    return a * a;
}

int n, m, k;
int x [1005];
int my;

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++)
        cin >> x [i];

    cin >> my;

    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        int bits = 1 << (n - 1);
        int cnt = 0;

        while (1)
        {
            int res1 = (bits & x [i]);
            int res2 = (bits & my);

            if (res1 != res2)
                cnt++;

            if (bits == 1)
                break;

            bits |= (bits >> 1);
            bits &= (bits >> 1);
        }

        if (cnt <= k)
            ans++;
    }

    cout << ans << endl;

    return 0;
}
