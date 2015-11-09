#define NAME "c"

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif

int t, n, m, a[200000];
set <pair <int, int> > set1;
map <int, int> ps;

int main()
{
    freopen (NAME".in", "r", stdin);
    freopen (NAME".out", "w", stdout);
    //invariant: В set и map нет элементов, про которые мы точно знаем, что они закончились
    scanf("%d\n\n", &t);
    for (int i = 0; i < t; i++)
    {
        set1.clear();
        ps.clear();
        scanf("%d %d\n", &m, &n);
        int sub_from_all = 0;
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
            {
                scanf ("%d ", &a[j]);
            }
            else
            {
                scanf ("%d\n", &a[j]);
            }
            ps.insert(make_pair(j, a[j]));
            set1.insert(make_pair(a[j], j));
        }
        for (int j = 0; j < m - 1; j++)
        {
            int p, s;
            if (j == m - 2 && i == t - 1)
            {
                scanf("%d %d", &p, &s);
            }
            else
            {
                scanf("%d %d\n", &p, &s);
            }
            p--;
            if (s == 0)
            {
                if (p != -1)
                {
                    pair <int, int> tmp = *ps.find(p);
                    int fst = tmp.first;
                    int snd = tmp.second;
                    set1.erase(make_pair(snd, fst));
                    ps.erase(ps.find(p));
                    snd--;
                    if (snd != 0)
                    {
                        set1.insert(make_pair(snd, fst));
                        ps.insert(make_pair(fst, snd));
                    }
                }
                else
                {
                    sub_from_all++;
                }
            }
            else
            {
                pair <int, int> first = *set1.begin();
                set <pair <int, int> >::iterator it = set1.begin();
                it++;
                pair <int, int> second;
                if (it != set1.end())
                {
                    second = *it;
                }
                set <pair <int, int> >::iterator it1 = it;
                pair <int, int> third;
                if (it != set1.end())
                {
                    it1++;
                    if (it1 != set1.end())
                    {
                        third = *it1;
                    }
                }
                if (it1 == set1.end() || first.first != third.first) //Нет 3 одинаковых минимальных количеств. Если есть, то определенности не появится
                {
                    if (first.first <= sub_from_all && (it == set1.end() || second.first > sub_from_all || second.second == p))
                    {
                        sub_from_all -= first.first;
                        first.first = 0;
                        set1.erase(set1.begin());
                        ps.erase(ps.find(first.second));
                    }
                    else if (it != set1.end() && second.first <= sub_from_all && first.second == p) // Равное количество 1 и 2 блюд, при этом человеку достается 1 блюдо и он остается недовольным
                    {
                        sub_from_all -= second.first;
                        second.first = 0;
                        set1.erase(it);
                        ps.erase(ps.find(second.second));
                    }
                }
                if (p != -1)
                {
                    pair <int, int> tmp = *ps.find(p);
                    int fst = tmp.first;
                    int snd = tmp.second;
                    set1.erase(make_pair(snd, fst));
                    ps.erase(ps.find(p));
                    snd--;
                    set1.insert(make_pair(snd, fst));
                    ps.insert(make_pair(fst, snd));
                }
                else
                {
                    sub_from_all++;
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (ps.find(j) != ps.end() && ps[j] - sub_from_all > 0)
            {
                printf("N");
            }
            else
            {
                printf("Y");
            }
        }
        if (i != t - 1)
        {
            scanf("\n");
        }
        printf("\n");
    }
    return 0;
}
