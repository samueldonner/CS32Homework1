#include <iostream>
using namespace std;

int main()
{
    Map m;
    m.insert("A", 10);
    m.insert("B", 44);
    m.insert("C", 10);
    string all;
    double total = 0;
    for (int n = 0; n < m.size(); n++)
    {
        string k;
        double v;
        m.get(n, k, v);
        all += k;
        total += v;
    }
    cout << all << total;
}