#include <iostream>
#include <string>
#include<fstream>
#include <iomanip>
#include <fstream>
#define MAX 50
using namespace std;

class BN
{
public:
    int mahoso;
    string hoten, gioitinh;
    string ngaysinh;

public:
    BN()
    {
        //mahoso=0;
    }
    BN(string name, string gioit, int mahs, string ngays)
    {
        hoten = name;
        gioitinh = gioit;
        mahoso = mahs;
        ngaysinh = ngays;
    }
    virtual void add()
    {
        /* cout << "Nhap MAHOSO : ";
        cin >> mahoso;
        cout << "Nhap Ho ten BN : ";
        cin.ignore();
        getline(cin, hoten);
        cout << "Nhap Gioi tinh : ";
        cin.ignore();
        getline(cin, gioitinh);
        cout << "Nhap ngay sinh : ";
        cin.ignore();
        getline(cin, ngaysinh); */
    }
    virtual void display()
    {
    	cout << setfill(' ') << setw(15) << left << mahoso
        << setfill(' ') << setw(20) << left << hoten
        << setfill(' ') << setw(15) << left << gioitinh 
        << setfill(' ' ) << setw(15) << left << ngaysinh;
    }
    void getMaHoSo()
    {
        cout << "\nNhap MAHOSO : ";
        cin >> mahoso;
    }
    int returnMaHoSo(){
        return mahoso;
    }

    // tim kiem theo ma ho so thi can gi phai co ham nay cho met
    /* virtual bool operator==(int mahoso)
    {
        return this->mahoso = mahoso;
    } */
};
class BNNT : public BN
{
private:
    string ngaynv, ngayxv;
    string chuandoan, tenkhoa;
    int sogiuong;

public:
    BNNT(string name, string gioit, string ngays, string chuand, string tenk, string nnv, string nxv, int mahs, int sog) : BN(name, gioit, mahs, ngays)
    {
        chuandoan = chuand;
        tenkhoa = tenk;
        ngaynv = nnv;
        ngayxv = nxv;
        sogiuong = sog;
    }
    void add()
    {
        BN::add();
        cout << "Nhap ngay nhap vien : ";
        cin.ignore();
        getline(cin, ngaynv);
        cout << "Nhap ngay xuat vien : ";
        cin.ignore();
        getline(cin, ngayxv);
        cout << "Nhap chuan doan  : ";
        cin.ignore();
        getline(cin, chuandoan);
        cout << "Nhap ten khoa : ";
        cin.ignore();
        getline(cin, tenkhoa);
        cout << "Nhap so giuong : ";
        cin >> sogiuong;
        cout << endl;
    }

    void display()
    {
        BN::display();
        cout << setfill(' ') << setw(20) << left << ngaynv
        << setfill(' ') << setw(20) << left << ngayxv
        << setfill(' ') << setw(15) << left << chuandoan 
        << setfill(' ') << setw(15) << left << tenkhoa
        << setfill(' ') << setw(15) << left << sogiuong;
        cout << endl;
    }

    bool operator==(BNNT &r)
    {
        if (mahoso == r.mahoso)
            return 1;
        else
            return 0;
    }
};
class BNNgoaiTru : public BN
{
private:
    string ngaykham;
    string chuandoan;
    int sobaohiem, matoathuoc;

public:
    BNNgoaiTru() : BN()
    {
        sobaohiem = 0;
        matoathuoc = 0;
    }
    BNNgoaiTru(string name, string gioit, string ngays, string chuand, string ngayk, int mahs, int sobh, int matt) : BN(name, gioit, mahs, ngays)
    {
        chuandoan = chuand;
        ngaykham = ngayk;
        sobaohiem = sobh;
        matoathuoc = matt;
    }
    void add()
    {
        BN::add();
        cout << "Nhap Ngay kham : ";
        cin.ignore();
        getline(cin, ngaykham);
        cout << "NHap chuan doan : ";
        cin.ignore();
        getline(cin, chuandoan);
        cout << "Nhap so bao hiem : ";
        cin >> sobaohiem;
        cout << "Nhap ma toa thuoc : ";
        cin >> matoathuoc;
        cout << endl;
    }
    void display()
    {
        BN::display();
         cout << setfill(' ') << setw(20) << left << ngaykham
            << setfill(' ') << setw(20) << left << chuandoan
            << setfill(' ') << setw(20) << left << sobaohiem 
            << setfill(' ') << setw(20) << left << matoathuoc;
        cout << endl;
    }
};
class BNCV : public BN
{
private:
    string chuandoan, noichuyen;
    string ngaychuyen;

public:
    BNCV() : BN()
    {
    }
    BNCV(string name, string gioit, string ngays, string chuand,
         string noic, string ngayc, int mahs) : BN(name, gioit, mahs, ngays)
    {
        chuandoan = chuand;
        noichuyen = noic;
        ngaychuyen = ngayc;
    }
    void add()
    {
        BN::add();
        cout << "Nhap Chuan doan : ";
        cin.ignore();
        getline(cin, chuandoan);
        cout << "Nhap Noi chuyen : ";
        cin.ignore();
        getline(cin, noichuyen);
        cout << "Nhap ngay chuyen";
        cin.ignore();
        getline(cin, ngaychuyen);
    }
    void display()
    {
        BN::display();
        cout << setfill(' ') << setw(20) << left << chuandoan
	        << setfill(' ') << setw(20) << left << noichuyen
	        << setfill(' ') << setw(20) << left << ngaychuyen ;
        cout << endl;

    }
    bool operator==(BNCV &r)
    {
        if (mahoso == r.mahoso)
            return 1;
        else
            return 0;
    }
};

void banner()
{
     
cout << setfill(' ')  << setw(15)  <<  left << "MA HO SO" 
     << setfill(' ')  << setw(20)  <<  left << "HO TEN" 
     << setfill(' ')  << setw(15)  <<  left << "GTOI TINH" 
     << setfill(' ')  << setw(15)  <<  left << "NGAY SINH"
     << setfill(' ')  << setw(20)  <<  left << "NGAY NHAP VIEN"
     << setfill(' ')  << setw(20)  << left  << "NGAY XUAT VIEN"
     << setfill(' ')  << setw(15)  << left  << "CHAN DOAN"
     << setfill(' ')  << setw(15)  << left  << "TEN KHOA "
     << setfill(' ')  << setw(15)  << left  << "SO GIUONG";
     cout<<endl;
 }

void NhapNT(BN **a, int &n)
{
    int i = 0;
    fstream inFile("noitru.txt");
    while (!inFile.eof())
    {
        string name,gioit,ngays,chuand,tenk,nnv,nxv;
        int mahs,sog;
        getline(inFile>>std::ws,name);
        getline(inFile>>std::ws,gioit);
        getline(inFile>>std::ws,ngays);
        getline(inFile>>std::ws,chuand);
        getline(inFile>>std::ws,tenk);
        getline(inFile>>std::ws,nnv);
        getline(inFile>>std::ws,nxv);
        inFile >> mahs >> sog;
        /* cout << "HEHE" << endl;
        cout << name << endl;
        cout << gioit << endl;
        cout << ngays << endl;
        cout << chuand << endl;
        cout << tenk << endl;
        cout << nnv << endl;
        cout << nxv << endl;
        cout << mahs << endl;
        cout << sog << endl; */
        n = n + 1;
        a[i] = new BNNT (name,gioit,ngays,chuand,tenk,nnv,nxv,mahs,sog);
        ++i;
    }
    n = i;
    inFile.close();
    
}
void NhapNgoaiTru(BN *b[], int &m)
{
    string name, name1, gioit, gioit1, ngays, ngays1;
    string chuand, chuand1, ngayk, ngayk1;
    int mahs, sobh, matt;
    freopen("ngoaitru.txt", "r+", stdin);
    while (true)
    {
        name = "";
        cin >> name;
        if (name.size() == 0)
            break;
        getline(cin, name1);
        name += name1;
        cin >> gioit;
        getline(cin, gioit1);
        gioit += gioit1;
        cin >> ngays;
        getline(cin, ngays1);
        ngays += ngays1;
        cin >> chuand;
        getline(cin, chuand1);
        chuand += chuand1;
        cin >> ngayk;
        getline(cin, ngayk1);
       ngayk += ngayk1;
        cin >> mahs >> sobh >> matt;
        b[m++] = new BNNgoaiTru(name, gioit, ngays, chuand, ngayk, mahs, sobh, matt);
    }
}
void NhapCV(BN *c[], int &v)
{
    string name, name1, gioit, gioit1, ngays, ngays1;
    string chuand, chuand1, noic, noic1, ngayc, ngayc1;
    int mahs;
    freopen("chuyenvien.txt", "r+", stdin);
    while (true)
    {
        name = "";
        cin >> name;
        if (name.size() == 0)
            break;
        getline(cin, name1);
        name += name1;
        cin >> gioit;
        getline(cin, gioit1);
        gioit += gioit1;
        cin >> ngays;
        getline(cin, ngays1);
        ngays += ngays1;
        cin >> chuand;
        getline(cin, chuand1);
        chuand += chuand1;
        cin >> noic;
        getline(cin, noic1);
        noic += noic1;
        cin >> ngayc;
        getline(cin, ngayc1);
        ngayc += ngayc1;
        cin >> mahs;
        c[v++] = new BNCV(name, gioit, ngays, chuand, noic, ngayc, mahs);
	}
}

void display(BN **p, int n)
{
    for (int i = 0; i < n; i++)
        p[i]->display();
        cout<<endl;
}

void indsnt(BN **p, int n)
{
    banner();
    for(int i = 0 ; i < n ; i++){
        (*p[i]).display();
    }
}
BN *timkiem(BN **p,int n){
    // tim kiem theo ma hoso nhi
    cout << "Nhap ma ho so: ";
    int mhs; cin >> mhs;
    BN *temp = NULL;
    for(int i = 0; i <= n; i++){
        if((*p[i]).returnMaHoSo() == mhs){
            temp = p[i];
            break;
        }
    }
    return temp;

}
int main()
{
	/* int n=0;
	BN *nt[n], *ngt[n];
	NhapNT(nt,n);
	cout<<"==============/////////////============BENH NHAN NOI TRU =================/////////========="<<endl;
	cout<<endl;
	indsnt(nt,n); */
    
    /* BN *temp = timkiem(nt,n);
    if(temp ==NULL){
        cout << "Khong co benh nhan nao ca!!";
    }else{
        temp->display();
    } */
    int n = 0;
    BN *nt[n];
    NhapNT(nt,n);
    cout << n << endl;
    nt[1]->display();
    system("Pause");

	//NhapNgoaiTru(ngt, n);

	//display(ngt,n);
    return 0;
}


