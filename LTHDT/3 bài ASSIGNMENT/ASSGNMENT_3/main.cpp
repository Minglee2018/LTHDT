#include <bits/stdc++.h>
using namespace std;
class ps
{
    int t,m;
public:
    ps();
    ps(int x,int y);
    ps operator*(ps y);
    float operator-();
    friend  istream&operator>>(istream& x,ps& y);
    friend  ostream&operator<<(ostream& x,ps y);
};
ps::ps()
{
    t=0;
    m=1;
}
ps::ps(int x,int y)
{
    t=x,m=y;
}
ps ps::operator*(ps y)
{
    ps tg;
    tg.t=t*y.t;
    tg.m=m*y.m;
    return tg;
}
float ps::operator -()
{
    return (float)t/m;
}
istream&operator>>(istream& x,ps& y)
{
    cout<<"Nhap tu so: ";     x>>y.t;
    cout<<"Nhap mau so: ";    x>>y.m;
    return x;
}
ostream&operator<<(ostream&x,ps y)
{
    int z =__gcd(y.t,y.m);
    x<<y.t/z<<"/"<<y.m/z<<endl;
    return x;
}
int main()
{
    ps a,b,c;
    cout<<"Nhap phan so a"<<endl;
    cin>>a;
    cout<<"Nhap phan so b"<<endl;
    cin>>b;
    c=a*b;
    ofstream f("phanso.txt",ios::out);
    f<<"Hien thi dang phan so cua phan so c: "<<c<<endl;
    f<<"hien thi dang thap phan cua phan so c: "<<-b<<endl;
	f.close();
    return 0;
}
