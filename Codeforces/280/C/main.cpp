#define NAME "c"

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

#ifdef WIN32
    #define lld "%I64d"
#else
    #define lld "%lld"
#endif

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <char> vc;

typedef pair <int, int> pii;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <ll, ll> pll;

typedef vector <pii> vpii;
typedef vector <pil> vpil;
typedef vector <pli> vpli;
typedef vector <pll> vpll;

template <typename T>
T sqr (T a)
{
    return a * a;
}

int n, r, avg;

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);

    scanf ("%d %d %d", &n, &r, &avg);
    vpii exam;
    ll curr = 0ll;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf ("%d %d", &a, &b);
        exam.pb (mp (b, a));
        curr += a;
    }

    sort (exam.begin (), exam.end ());
    ll needed = n * 1ll * avg;

    if (curr >= needed)
    {
        puts ("0");
        return 0;
    }

    ll ans = 0ll;

    for (int i = 0; i < n; i++)
    {
        if (curr == needed)
            break;

        if (exam [i].snd == r)
            continue;

        if ((r - exam [i].snd) <= (needed - curr))
        {
            ans += exam [i].frs * 1ll * (r - exam [i].snd);
            curr += (r - exam [i].snd);
            exam [i].snd = r;
            continue;
        }

        ans += exam [i].frs * 1ll * (needed - curr);
        curr = needed;
        break;
    }

    printf (lld"\n", ans);

    return 0;
}
