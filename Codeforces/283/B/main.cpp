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

int n;
string s;

string shift_left (string s)
{
    string res = "";
    int k = (int) s.length ();

    for (int i = 1; i < k; i++)
        res += s [i];

    res += s [0];
    return res;
}

int main ()
{
    srand (time (0));

    //freopen (NAME".in", "r", stdin);
    //freopen (NAME".out", "w", stdout);
    
    cin >> n;
    cin >> s;
    vi a (n);

    for (int i = 0; i < n; i++)
        a [i] = (int) (s [i] - '0');

    string t = "";

    for (int i = 0; i < n; i++)
        t += '9';

    for (int j = 0; j < 10; j++)
    {
        for (int i = 0; i < n; i++)
            a [i] = (int) (s [i] - '0');

        for (int i = 0; i < n; i++)
        {
            a [i]++;
            a [i] %= 10;
            s [i] = (char) (a [i] + '0');
        }

        for (int i = 0; i < n; i++)
        {
            s = shift_left (s);
            t = min (t, s);
        }
    }

    cout << t << endl;

    return 0;
}
