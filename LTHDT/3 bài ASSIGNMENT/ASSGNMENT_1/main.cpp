#include <bits/stdc++.h>
using namespace std;
class PHIEU;
class HANG
{
private:
    char MSP[30];
    char TSP[50];
    int So_Luong;
    float Don_Gia;
public:
    void nhap(); void xuat();
    friend float Sum(HANG *a,int n);
    friend int check(HANG *a,int n);
    friend void Sap_Xep(HANG *x,int n);
//friend class PHIEU;
};
void HANG::nhap()
{
    cout<<"Ma san pham: ";      fflush(stdin);  gets(MSP);
    cout<<"Ten san pham: ";     fflush(stdin);  gets(TSP);
    cout<<"So luong: ";                         cin>>So_Luong;
    cout<<"Don gia: ";                          cin>>Don_Gia;
}
void HANG::xuat()
{
    cout<<setw(15)<<MSP<<setw(15)<<TSP<<setw(15)<<So_Luong<<setw(15)<<Don_Gia<<setw(15)<<So_Luong*Don_Gia<<endl;
}
float Sum(HANG *a,int n)
{
    float S=0;
    for(int i=0; i<n; i++)
        S+=a[i].So_Luong*a[i].Don_Gia;
    return S;
}
int check(HANG *a,int n)
{
    int dem=0;
    for(int i=0; i<n; i++)
    {
        if(a[i].So_Luong<80) dem++;
    }
    return dem;
}
class DATE{
private:    int D,M,Y;
public:     void nhap(); void xuat();
};
void DATE::nhap(){
    cout<<"Day = ";     cin>>D;
    cout<<"Month = ";   cin>>M;
    cout<<"Year = ";    cin>>Y;
}
void DATE::xuat(){
    cout<<"Ngay Lap: "<<D<<"/"<<M<<"/"<<Y;
}
class NHA_CUNG_CAP
{
private:
    char MNCC[50];
    char TNCC[50];
    char Location[50];
    char PHONE[20];
    DATE x;
public:
    void nhap(); void xuat();
};
void NHA_CUNG_CAP::nhap()
{
    cout<<"Ma nha cung cap: ";          fflush(stdin);  gets(MNCC);
    cout<<"Ten nha cung cap:   ";       fflush(stdin);  gets(TNCC);
    cout<<"Dia chi";                    fflush(stdin);  gets(Location);
    cout<<"So dien thoai: ";            fflush(stdin);  gets(PHONE);
}
void NHA_CUNG_CAP::xuat()
{
    cout<<"Ma nha cung cap: "<<MNCC<<setw(15)<<"Ten nha cung cap: "<<TNCC<<endl;
    cout<<"Dia chi: "<<Location<<setw(15)<<"SDT: "<<PHONE<<endl;
}
class PHIEU:public HANG
{
private:
    char MP[50];
    NHA_CUNG_CAP x;
    DATE y;
    HANG *z;
    int n;
    float SUM=0;
    int kq;
public:
    void nhap();    void xuat();
    friend void Truy_Cap(PHIEU x);
    friend void Sort(PHIEU x);
   // friend void Sort(PHIEU *z,int n);
};
void PHIEU::nhap()
{
    cout<<"Nhap ma phieu: ";        fflush(stdin);  gets(MP);
    x.nhap();
    y.nhap();
    cout<<"Nhap n= ";                               cin>>n;
    z = new HANG[n];
    for(int i=0; i<n; i++)
        z[i].nhap();
    SUM=Sum(z,n);
    kq=check(z,n);
}
void PHIEU::xuat()
{
    cout<<setw(15)<<"Dai hoc Victory"<<endl;
    cout<<setw(45)<<"PHIEU NHAP VAN PHONG PHAM"<<endl;
    cout<<setw(15)<<MP<<setw(15);   y.xuat();   cout<<endl;
    cout<<setw(15)<<"Ma san pham"<<setw(15)<<"Ten san pham"<<setw(15)<<"So luong"<<setw(15)<<"Don gia"<<setw(15)<<"Thanh tien"<<endl;
    for(int i=0; i<n; i++)
    {
        z[i].xuat();
    }
    cout<<setw(40)<<"Tong"<<setw(35)<<SUM<<endl<<endl;
}
void Truy_Cap(PHIEU x)
{
    cout<<"So luong san pham nhap nho hon 80 la: "<<x.kq<<endl;
}
void Sort(PHIEU x)
{
    Sap_Xep(x.z,x.n);
}
void Sap_Xep(HANG *z,int n)
{
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
        {
            if(z[i].So_Luong>z[j].So_Luong)
                swap(z[i],z[j]);
        }
}
int main()
{
   // freopen("input.txt","r",stdin);
    PHIEU a;
    a.nhap();
    a.xuat();
    Truy_Cap(a);
    cout<<"Sap xep danh sach theo chieu tang dan cua don gia"<<endl<<endl;
    Sort(a);
    a.xuat();
    return 0;
}


