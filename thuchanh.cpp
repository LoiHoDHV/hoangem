#include<iostream>
#include<string>
#include <iomanip>
#include <fstream>
#define MAX 50
using namespace std;
class DATE{
    private:
        int ngay, thang, nam;
    public:
        DATE(int ngay = 0, int thang = 0 , int nam = 0){
            this->ngay = ngay;
            this->thang = thang;
            this->nam = nam;
        }
        DATE(DATE &other){
            ngay = other.ngay;
            thang = other.thang;
            nam = other.nam;
        }
        void dispDATE(){
            string ngayS = "";
            string thangS = "";
            string namS = to_string(nam);
            if(ngay < 10){
                ngayS = ngayS + "0"+to_string(ngay);
            }else{
                ngayS = to_string(ngay);
            }
            if (thang < 10){
                thangS = thangS + "0" + to_string(thang);
            }else{
                thangS = to_string(thang);
            }
            string ngay_thang = ngayS + "/" + thangS + "/" + namS;
            cout << setfill(' ') << setw(15) << left << ngay_thang;
            
        }
};
class NV{
    private:
        string hoten;
        DATE ngaythang;
        string gioitinh;
        string quequan;
        string trinhdo;
    public:
        NV(string hoten ,DATE ngaysinh, string gioitinh,string quequan,string trinhdo){
            this->hoten.assign(hoten);
            ngaythang = ngaysinh;
            this->gioitinh.assign(gioitinh);
            this->quequan.assign(quequan);
            this->trinhdo.assign(trinhdo);
        }
        virtual void add(){
            cout << "Ho ten nhann vienn: ";
            getline(std::cin>>std::ws,hoten);
            // su dung ham construct sao chep
            cout << "Ngay thang nam sinh";
            int ngay, thang, nam;
            cin >> ngay >> thang >> nam;
            DATE temp(ngay,thang,nam);
            this->ngaythang = temp;
            cout << "Gioi Tinh: ";
            getline(std::cin>>std::ws,gioitinh);
            cout << "Que quan: ";
            getline(std::cin>>std::ws,quequan);
            cout << "Trinh do";
            getline(std::cin>>std::ws,trinhdo);
        }
        virtual void display(){
            cout << setfill(' ') << setw(20) << left << hoten;
            ngaythang.dispDATE();
            cout << setfill(' ') << setw(10) << left << gioitinh
            << setfill(' ') << setw(20) << left << quequan 
            << setfill(' ' ) << setw(10) << left << trinhdo;
        }
        virtual float getMoney(){
            return 0;
        }
        virtual bool operator > ( NV &other){
            float a = getMoney();
            return a > other.getMoney();
        }
};
class NVCT : public NV{
    protected:
        string maNV;
        string chucVu;
        float hsLuong;
        float phuCap;
        float tienAnTrua;;
        float thucLinh;
    public:
        NVCT(string hoten ,DATE ngaysinh, string gioitinh,string quequan,string trinhdo,
        string maNV,string chucVu, float hsLuong, float phuCap, float tienAnTrua, float thucLinh)
        :NV(hoten,ngaysinh,gioitinh,quequan,trinhdo){
            this->maNV.assign(maNV);
            this->chucVu.assign(chucVu);
            this->hsLuong = hsLuong;
            this->phuCap = phuCap;
            this->tienAnTrua = tienAnTrua;
            this->thucLinh = thucLinh;
        }
        void add(){
            NV::add();
            cout << "Ma nhan vien: ";
            getline(std::cin>>std::ws,maNV);
            cout << "Chuc vu: ";
            getline(std::cin>>std::ws,chucVu);
            cout << "He so luong: ";
            cin >> hsLuong;
            cout << "Phu cap: ";
            cin >> phuCap;
            cout << "Tien an trua: ";
            cin >> tienAnTrua;
            cout << "Thuc linh: ";
            cin >> thucLinh;
        }
        
        void display(){
            NV:: display();
            cout << setfill(' ') << setw(10) << left << maNV
            << setfill(' ') << setw(15) << left << chucVu
            << setfill(' ') << setw(5) << left << hsLuong 
            << setfill(' ') << setw(8) << left << phuCap
            << setfill(' ') << setw(8) << left << tienAnTrua
            << setfill(' ') << setw(8) << left << thucLinh;
            cout << endl;
        }
        float getMoney(){
            return thucLinh;
        }
        bool operator > (NVCT other){
            return thucLinh > other.thucLinh;
        }
        
};
class NVHD:public NV{
    protected:
        float luong;
        DATE ngayVao;
        DATE ngayRa;
    public:
        NVHD(string hoten ,DATE ngaysinh, string gioitinh,string quequan,string trinhdo,float luong, DATE vao, DATE ra)
        :NV(hoten,ngaysinh,gioitinh,quequan,trinhdo){
            this->luong = luong;
            ngayVao = vao;
            ngayRa = ra;
        }
        void add(){
            NV::add();
            cout <<"Luong: "; cin >> luong;
            cout << "Ngay Thang Nam Ki hop dong: ";
            int n,thang,nam;
            cin >> n >> thang >> nam;
            DATE temp_vao(n,thang,nam);
            ngayVao = temp_vao;
            cout << "Ngay Thang Nam het hop dong:";
            cin >> n >>  thang >> nam;
            DATE temp_ra(n,thang,nam);
            ngayRa = temp_ra;
        }
        void display(){
            NV::display();
            cout << setfill(' ') << setw(8) << left << luong;
            ngayVao.dispDATE();
            ngayRa.dispDATE();
            cout << endl;
        }
        float getMoney(){
            return luong;
        }
};
void addTheList_NVCT(NV **p, string fileName){
    fstream inFile(fileName);
    int n;
    inFile >> n;
    for(int i = 0 ; i < n ; i++){
        string hoten;
        int ngay,thang,nam;
        string gioitinh;
        string quequan;
        string trinhdo;
        string maNV;
        string chucVu;
        float hsLuong;
        float phuCap;
        float tienAnTrua;;
        float thucLinh;
        getline(inFile>>std::ws,hoten);
        inFile >> ngay >> thang >> nam;
        DATE ngaythang(ngay,thang,nam);
        getline(inFile>>std::ws,gioitinh);
        getline(inFile>>std::ws,quequan);
        getline(inFile>>std::ws,trinhdo);
        getline(inFile>>std::ws,maNV);
        getline(inFile>>std::ws,chucVu);
        inFile >> hsLuong >> phuCap >> tienAnTrua >> thucLinh;
        p[i] = new NVCT(hoten,ngaythang,gioitinh,quequan,trinhdo
        ,maNV,chucVu,hsLuong,phuCap,tienAnTrua,thucLinh);
       
    }
    inFile.close();
}
void addTheList_NVHD(NV **p,string fileName){
    int n;
    fstream inFile(fileName);
    inFile>>n;
    for(int i = 0; i < n; i++){
        string hoten;
        int ngay,thang,nam;
        string gioitinh;
        string quequan;
        string trinhdo;
        float luong;
        getline(inFile>>std::ws,hoten);
        inFile >> ngay >> thang >> nam;
        DATE ngaythang(ngay,thang,nam);
        getline(inFile>>std::ws,gioitinh);
        getline(inFile>>std::ws,quequan);
        getline(inFile>>std::ws,trinhdo);
        inFile >> luong;
        inFile >> ngay >> thang >> nam;
        DATE ngayVao(ngay,thang,nam);
        inFile >> ngay >> thang >> nam;
        DATE ngayRa(ngay,thang,nam);
        p[i] = new NVHD(hoten,ngaythang,gioitinh,
        quequan,trinhdo,luong,ngayVao,ngayRa);
    }
    inFile.close();
}

void sapXep(NV **p, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n-i-1; j++){
            if((*p[j]) > (*p[j+1])){
                NV *temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}
    
void hiends(NV **p, int n ){
    for(int i = 0; i < n; i++){
        cout << setfill(' ') << setw(5) << left << i+1;
        p[i]->display();
    }
}
void bannerChung(){
    cout << setfill(' ') << setw(5) << left << "STT" 
    << setfill(' ') << setw(20) << left << "HO TEN" 
    << setfill(' ') << setw(15) << left << "NGAY THANG" 
    << setfill(' ') << setw(10) << left << "GTINH" 
    << setfill(' ') << setw(20) << left << "QUE QUAN"
    << setfill(' ') << setw(10) << left << "TRINH DO";
}
void inGhiChu(){
    cout << endl;
    cout << setfill('=') << setw(113) << "";
    cout << endl;
    cout << setfill(' ') << setw(40) <<left<< "-/-/-/-/-/-/-"
    << "DANH SACH TRUOC KHI CAP NHAT" 
    << setfill(' ') << setw(45)<<right  << "-\\-\\-\\-\\-\\-\\-" << endl;
    cout << setfill('=') << setw(113) << "";
    cout << endl;
    
}
void inNVHD(NV **p,int n){
    cout << setfill(' ') << setw(40) <<left<< "-/-/-/-/-/-/-"
    << "--NHANH VIEN HOP DONG--" 
    << setfill(' ') << setw(45)<<right  << "-\\-\\-\\-\\-\\-\\-";
    inGhiChu();
    bannerChung();
    cout<< setfill(' ') << setw(8) << left <<  "LUONG"
    << setfill(' ') << setw(15) << left << "NGAY VAO"
    << setfill(' ') << setw(15) << left << "NGAY RA";
    cout << endl;
    hiends(p,n);
    cout << endl;
    cout << setfill('=') << setw(113) << "";
    cout << endl;
    cout << setfill(' ') << setw(40) <<left<< "-/-/-/-/-/-/-"
    << "DANH SACH SAU KHI CAP NHAT" 
    << setfill(' ') << setw(47)<<right  << "-\\-\\-\\-\\-\\-\\-" << endl;
    cout << setfill('=') << setw(113) << "";
    cout << endl;
    bannerChung();
    cout<< setfill(' ') << setw(8) << left <<  "LUONG"
    << setfill(' ') << setw(15) << left << "NGAY VAO"
    << setfill(' ') << setw(15) << left << "NGAY RA";
    cout << endl;
    sapXep(p,n);
    hiends(p,n);
    system("pause");
}
void inNVCT(NV **p, int n){
    cout << setfill(' ') << setw(40) <<left<< "-/-/-/-/-/-/-"
    << "-NHAN VIEN CHINH THUC-" 
    << setfill(' ') << setw(45)<<right  << "-\\-\\-\\-\\-\\-\\-";
    inGhiChu();
    bannerChung();
    cout << setfill(' ') << setw(10) << left << "MANV"
    << setfill(' ') << setw(15) << left << "CHUC VU"
    << setfill(' ') << setw(5) << left << "HESO" 
    << setfill(' ') << setw(8) << left << "P-CAP" 
    << setfill(' ') << setw(8) << left << "A-TRUA"
    << setfill(' ') << setw(8) << left << "T-LINH";
    cout << endl;
    hiends(p,n);
    cout << endl;
    cout << setfill('=') << setw(113) << "";
    cout << endl;
    cout << setfill(' ') << setw(40) <<left<< "-/-/-/-/-/-/-"
    << "DANH SACH SAU KHI CAP NHAT" 
    << setfill(' ') << setw(47)<<right  << "-\\-\\-\\-\\-\\-\\-" << endl;
    cout << setfill('=') << setw(113) << "";
    cout << endl;
    bannerChung();
    cout << setfill(' ') << setw(10) << left << "MANV"
    << setfill(' ') << setw(15) << left << "CHUC VU"
    << setfill(' ') << setw(5) << left << "HESO" 
    << setfill(' ') << setw(8) << left << "P-CAP" 
    << setfill(' ') << setw(8) << left << "A-TRUA"
    << setfill(' ') << setw(8) << left << "T-LINH";
    cout << endl;
    sapXep(p,n);
    hiends(p,n);
    system("pause");

}

int main(){
    fstream inFile("NVCT.txt");
    int n;
    inFile >> n;
    NV *listNVCT[n];
    inFile.close();
    addTheList_NVCT(listNVCT,"NVCT.txt");
    inNVCT(listNVCT,n);
    return 0;
    
    /* fstream inFile("NVHD.txt");
    int n;
    inFile >> n;
    NV *list_NVHD[n];
    inFile.close();
    addTheList_NVHD(list_NVHD,"NVHD.txt");
    inNVHD(list_NVHD,n);
    return 0; */
}

