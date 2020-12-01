#include <iostream>
#include <math.h>
using namespace std;
typedef struct
{
    int a, b;
}PS;

ostream& operator << (ostream& os, PS& p)
{
    os << p.a << "/" << p.b;
    return os;
}
istream& operator >> (istream& is, PS& p)
{
    cout<<"Tu va Mau: ";
    is >> p.a >> p.b;
    return is;
}

int uscln(int x, int y)
{
    x = abs(x); y = abs(y);
    int n; int uscln = 1;
    if (x > y)
    {
        n = y;
    }else
    {
        n = x;
    }
    for (int i = 1; i <= n; i++)
    {
        if (x % i == 0 && y % i == 0)
        {
            uscln = i;
        }
    }
    return uscln;
}

PS operator * (PS p1, PS p2)
{
    PS psm;
    psm.a = p1.a * p2.a;
    psm.b = p1.b * p2.b;
    return psm;
}

PS operator + (PS p1, PS p2)
{
    PS psm, p1m, p2m;
    if (p1.b == p2.b)
    {
        psm.a = p1.a + p2.a;
        psm.b = p1.b;
    }else if (p1.b != p2.b)
    {
        p1m.a = p1.a * p2.b;
        p2m.a = p2.a * p1.b;
        p1m.b = p1.b * p2.b;
        p2m.b = p1.b * p2.b;	
        psm.a = p1m.a + p2m.a;
        psm.b = p1m.b;
    }
    return psm;
}

PS operator - (PS p1, PS p2)
{
    PS psm, p1m, p2m;
    if (p1.b == p2.b)
    {
        psm.a = p1.a - p2.a;
        psm.b = p1.b;
    }else if (p1.b != p2.b)
    {
        p1m.a = p1.a * p2.b;
        p2m.a = p2.a * p1.b;
        p1m.b = p1.b * p2.b;
        p2m.b = p1.b * p2.b;
        psm.a = p1m.a - p2m.a;
        psm.b = p1m.b;
    }
    return psm;
}

PS operator / (PS p1, PS p2)
{
    PS psm;
    psm.a = p1.a * p2.b;
    psm.b = p1.b * p2.a;
    return psm;
}

PS rutgon (PS p)
{
    int sc = uscln(p.a, p.b);
    p.a = (p.a) / sc;
    p.b = (p.b) / sc;
    return p;
}

int main()
{
    PS p, q, z, u, v;
    PS s;
    cout << "Nhap cac phan so p, q, z, u, v\n";
    cin >> p >> q >> z >> u >> v;
    s = rutgon((p - q * z) / (u + v));
    cout << "Phan so s = " << s << endl;
}
