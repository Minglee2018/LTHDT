#include <bits/stdc++.h>
using namespace std;
class LOPHOC;
class NGUOI
{
protected:
    char HT[20];
    char DATE[20];
    char HOMETOW[20];
public:
    void nhap();
    void xuat();
};
void NGUOI::nhap()
{
    cout<<"Ho ten";         fflush(stdin);      gets(HT);
    cout<<"Ngay sinh";      fflush(stdin);      gets(DATE);
    cout<<"Que quan";       fflush(stdin);      gets(HOMETOW);
}
void NGUOI::xuat()
{
    cout<<HT<<setw(10)<<DATE<<setw(10)<<HOMETOW;
}
class SINHVIEN:public NGUOI
{
    char MSV[20];
    char NGHANH[20];
    int KHOA;
public:
    void nhap();
    void xuat();
    friend void SX(LOPHOC &z);
    friend void dem(LOPHOC z);
};
void SINHVIEN::nhap()
{
    NGUOI::nhap();
    cout<<"Ma sinh vien";       fflush(stdin);      gets(MSV);
    cout<<"Nghanh";             fflush(stdin);      gets(NGHANH);
    cout<<"KHOA";                                   cin>>KHOA;
}
void SINHVIEN::xuat()
{
    NGUOI::xuat();
    cout<<setw(15)<<MSV<<setw(10)<<NGHANH<<setw(10)<<KHOA<<endl;
}
class LOPHOC
{
    char MLH[20];
    char TLH[20];
    char DATE[20];
    SINHVIEN *x;
    int n;
    char GV[20];
public:
    void nhap();
    void xuat();
    friend void SX(LOPHOC &z);
    friend void dem(LOPHOC z);
};
void LOPHOC::nhap()
{
    cout<<"Ma Lop Hoc";         fflush(stdin);  gets(MLH);
    cout<<"Ten Lop Hoc";        fflush(stdin);  gets(TLH);
    cout<<"Ngay mo";            fflush(stdin);  gets(DATE);
    cout<<"Giao Vien";          fflush(stdin);  gets(GV);
    cout<<"Nhap n=";                            cin>>n;
    x = new SINHVIEN[n];
    for(int i=0; i<n; i++){
        x[i].nhap();
    }
}
void LOPHOC::xuat()
{
    cout<<setw(15)<<"Ma Lop Hoc"<<setw(15)<<"Ten Lop Hoc"<<setw(15)<<"Ngay Mo"<<endl;
    cout<<setw(15)<<MLH<<setw(15)<<TLH<<setw(15)<<DATE<<endl;
    cout<<"Ho ten"<<setw(10)<<"Ngay Sinh"<<setw(10)<<"Que quan"<<setw(10)<<"Ma Sinh Vien"<<setw(10)<<"Nghanh"<<setw(10)<<"Khoa"<<endl;
    for(int i=0; i<n; i++) x[i].xuat();
}
void dem(LOPHOC z)
{
    int count=0;
    for(int i=0; i<z.n; i++)
    {
        if(z.x[i].KHOA==11)
            count++;
    }
    cout<<endl<<"so sinh vien khoa 11 la: "<<count<<endl;
}
void SX(LOPHOC &z)
{
    for(int i=0; i<z.n; i++)
        for(int j=i+1; j<z.n;j++)
        {
            if(z.x[i].KHOA > z.x[j].KHOA)
            {
                SINHVIEN temp=z.x[i];
                z.x[i]=z.x[j];
                z.x[j]=temp;
            }
        }
}

int main()
{
    LOPHOC a;
    a.nhap();
    cout<<endl;
    a.xuat();
    cout<<endl;
    dem(a);
    SX(a);
    a.xuat();
    return 0;
}

