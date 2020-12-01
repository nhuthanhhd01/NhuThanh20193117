#include <iostream>
using namespace std;

class PS
{
private:
    int a, b;
public:
//    friend ostream& operator<< (ostream&, PS);
//    friend istream& operator>> (istream&, PS&);
//    static int uscln(int, int );
//   static PS rutgon(PS);
    
    friend ostream& operator<< (ostream& os, PS p)  
    {
        os << p.a << "/" << p.b;
        return os;
    }
    friend istream& operator>> (istream& is, PS& p)
    {
        cout<<"\nTu va Mau: ";
        is >> p.a >> p.b;
        return is;
    }

    static int uscln(int a, int b) {
        int uscln;
        if(a < 0)
            a = -a;
        if(b < 0)
            b = -b;
        if(a == 0 || b == 0)
            uscln = a + b;
        else
            {
                while(a != b)
                    if(a > b)
                        a = a - b;
                    else
                        b = b - a;
            if(a == b)
                    uscln = a;
            }
        return uscln;
    }

    static PS rutgon(PS p) { 
        int USCLN = uscln(p.a, p.b);
        p.a = p.a / USCLN;                      
        p.b = p.b / USCLN;
        return p;
    }
                
    friend PS operator+(PS p1, PS p2) {
        PS kq;
        kq.a = p1.a * p2.b + p1.b * p2.a;           
        kq.b = p1.b * p2.b;
        return rutgon(kq);                    
    }                                          

    friend PS operator-(PS p1, PS p2) {
        PS kq;
        kq.a = p1.a * p2.b - p1.b * p2.a;          
        kq.b = p1.b * p2.b;
        return rutgon(kq);
    }

    friend PS operator*(PS p1, PS p2) {
        PS kq;
        kq.a = p1.a * p2.a;                    
        kq.b = p1.b * p2.b;
        return rutgon(kq);
    }

    friend PS operator/(PS p1, PS p2) {
        PS kq;
        kq.a = p1.a * p2.b;                
        kq.b = p1.b * p2.a;
        return rutgon(kq);
    }
};
int main() {
/*    PS p1, p2;
    PS tong, hieu, tich, thuong;

    cin>>p1;
    cout<<p1;
    cin>>p2;
    cout<<p2;
    cout<<endl;

    tong = p1 + p2;
    hieu = p1 - p2;
    tich = p1 * p2;
    thuong = p1 / p2;
    cout<<tong<<endl;
    cout<<hieu<<endl;
    cout<<tich<<endl;*/

    PS p, q, z, u, v;
    PS s;
    cout << "\nNhap cac phan so p, q, z, u, v\n";
    cin >> p >> q>> z>> u>> v;
    s = (p - q * z) / (u + v);
    cout << "\nPhan so s = " << s;
    return 0;
}


