#include<iostream>
#include<string>
#include <iomanip>
#include <fstream>

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
            /* hehehehehe */
            cout << endl;
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
class BNHAN{
    protected:
        int maHS;
        string hoTen;
        DATE ngaySinh;
        string gioiTinh;
    public:
        BNHAN(){
            maHS = 0;
            hoTen = "";
            gioiTinh = "";
        }
        BNHAN(int maHS,string hoTen,DATE A,string gioiTinh){
            this->maHS = maHS;
            this->hoTen.assign(hoTen);
            ngaySinh = A;
            this->gioiTinh.assign(gioiTinh);
        }
        BNHAN(BNHAN &other){
            this->maHS = maHS;
            this->hoTen.assign(other.hoTen);
            ngaySinh = other.ngaySinh;
            this->gioiTinh.assign(other.gioiTinh);
        }
        /**
         * Nếu xảy ra vấn đề trung thì phải kêu hàm này để set lại thủ công
         */
        void setLaiHoSo(){
            cout << "Xin moi nhap lai do Ma HO SO bi trung!! " << endl;
            cout << "Nhap MaHS: "; cin >> maHS;
        }
        int returnMaHS(){
            return maHS;
        }
        virtual void display(){
            cout << setfill(' ') << setw(10) << left << maHS
            << setfill(' ') << setw(20) << left << hoTen 
            << setfill(' ') << setw(10) << left << gioiTinh;
            ngaySinh.dispDATE();
        }
};
class BNHAN_NT:public BNHAN{
    protected:
        DATE ngayNhapVien;
        DATE ngayRaVien;
        string chanDoan;
        string tenKhoa;
        int soGiuong;
    public:
        BNHAN_NT(int maHS,string hoTen,DATE A,string gioiTinh,DATE nV,DATE rV,string chanDoan,
        string tenKhoa,int soGiuong):BNHAN(maHS,hoTen,A,gioiTinh){
            ngayNhapVien = nV;
            ngayRaVien = rV;
            this->chanDoan.assign(chanDoan);
            this->tenKhoa.assign(tenKhoa);
            this->soGiuong = soGiuong;
        }
        
        BNHAN_NT(BNHAN_NT &other):BNHAN((BNHAN &) other){
            ngayNhapVien = other.ngayNhapVien;
            ngayRaVien = other.ngayRaVien;
            chanDoan.assign(other.chanDoan);
            tenKhoa.assign(other.tenKhoa);
            soGiuong = other.soGiuong;
        }
        void display(){
            BNHAN::display();
            ngayNhapVien.dispDATE();
            ngayRaVien.dispDATE();
            cout << setfill(' ') << setw(20) << left << chanDoan
            << setfill(' ') << setw(20) << left << tenKhoa
            << setfill(' ') << setw(5) << left << soGiuong << endl;
        }

    
};
/**
 * @brief hàm nay tại sao lai co stheem j = 0
 * bởi vì mỗi p[i] là con trỏ trỏ tới dữ liệu BNHAN_NT
 * 
 * @param p 
 * @param n 
 * @param maHS 
 * @return true 
 * @return false 
 */
bool trungMaHS(BNHAN **p,int n,int maHS){
    bool TrungMHS = false;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 1; j++){
            if(p[i][j].returnMaHS() == maHS){
                return true;
            }
        }
    }
    return TrungMHS;
}
void add_BN_NTru(BNHAN **p,int n){
    fstream inFile("BENHNHAN.txt");
    int k =0;// mot cai bien gi de khu di dong dau tien
    inFile >> k;
    int i = 0;
    while(!inFile.eof()){
        string hoten,gioiTinh;
        int ngay,thang,nam,mahs;
        string chanDoan,tenKhoa;
        int soGiuong;
        inFile>>mahs;
        getline(inFile>>std::ws,hoten);
        inFile >> ngay >> thang >> nam;
        DATE temp_Birth(ngay,thang,nam);
        getline(inFile >> std::ws,gioiTinh);
        inFile >> ngay >> thang >> nam;
        DATE tempVaoVien(ngay,thang,nam);
        inFile >> ngay >> thang >> nam;
        DATE tempRaVien(ngay,thang,nam);
        getline(inFile>>std::ws,chanDoan);
        getline(inFile>>std::ws,tenKhoa);
        inFile >> soGiuong;
        /* p[i] = new BNHAN_NT(mahs,hoten,temp_Birth,gioiTinh,tempVaoVien,tempRaVien,chanDoan,
            tenKhoa,soGiuong);
        ++i; */
        if(trungMaHS(p,i-1,mahs)){
            cout << "Gia tri trung: " << mahs << endl;
            p[i] = new BNHAN_NT(mahs,hoten,temp_Birth,gioiTinh,tempVaoVien,tempRaVien,chanDoan,
            tenKhoa,soGiuong);
            p[i]->setLaiHoSo();
            ++i;
        }else{
            p[i] = new BNHAN_NT(mahs,hoten,temp_Birth,gioiTinh,tempVaoVien,tempRaVien,chanDoan,
            tenKhoa,soGiuong);
            ++i;
        }
        
    }
    inFile.close();
}
int main(){
    
    fstream  inFile("BENHNHAN.txt");
    int n;
    inFile>>n;
    BNHAN *p[n];
    add_BN_NTru(p,n);
    
    for(int i = 0; i < n; i++){
        p[i]->display();
    }

    system("pause");
    return 0;
}