#include <iostream>

using namespace std;

int main ()
{
    cout << 100000 << endl;
    for (int i = 0; i < 100000; i++)
        cout << 'a';
    cout << endl;
    for (int i = 0; i < 100000; i++)
        cout << 'a';
    cout << endl;
    return 0;
}
