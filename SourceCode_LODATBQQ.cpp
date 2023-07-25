#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MonAn
{
private:
	string tenMonAn;
	int soLuong;
	int giaTien;
public:
	// Phương thức Get - Set
	string getTenMonAn()
	{
		return tenMonAn;
	}
	int getSoLuong()
	{
		return soLuong;
	}
	int getGiaTien()
	{
		return giaTien;
	}
	void setTenMonAn(string _tenMonAn)
	{
		tenMonAn = _tenMonAn;
	}
	void setSoLuong(int _soLuong)
	{
		soLuong = _soLuong;
	}
	void setGiaTien(int _giaTien)
	{
		giaTien = _giaTien;
	}
	// Phương thức khởi tạo
	MonAn(string _tenMonAn = "", int _soLuong = 0, int _giaTien = 0)
	{
		tenMonAn = _tenMonAn;
		soLuong = _soLuong;
		giaTien = _giaTien;
	}
	// Phương thức Copy
	MonAn(const MonAn& m)
	{
		tenMonAn = m.tenMonAn;
		soLuong = m.soLuong;
		giaTien = m.giaTien;
	}
	// Phương thức hủy
	~MonAn() {}
	// Quá tải >>, <<
	friend istream& operator >>(istream& is, MonAn& m)
	{
		is >> m.tenMonAn >> m.soLuong >> m.giaTien;
		return is;
	}
	friend ostream& operator <<(ostream& os, MonAn m)
	{
		os << m.tenMonAn << " " << m.soLuong;
		return os;
	}
	// Tính đa hình
	virtual int tienMonAn() {};
	virtual void Nhap() {};
	virtual void Xuat() {};
};

class DoNuong :public MonAn
{
private:
	bool kieu;
	int phuPhi;
public:
	bool getKieu()
	{
		return kieu;
	}
	int getPhuPhi()
	{
		return phuPhi;
	}
	void setKieu(bool _kieu)
	{
		kieu = _kieu;
	}
	void setPhuPhi(int _phuPhi)
	{
		phuPhi = _phuPhi;
	}
	DoNuong(string _tenMonAn = "", int _soLuong = 0, int _giaTien = 0, bool _kieu = 0, int _phuPhi = 0)
	{
		kieu = _kieu;
		phuPhi = _phuPhi;
	}
	DoNuong(const DoNuong& n) : MonAn(n)
	{
		kieu = n.kieu;
		phuPhi = n.phuPhi;
	}
	~DoNuong() {};
	int tienMonAn()
	{
		if (kieu)
		{
			return (getGiaTien() + phuPhi) * getSoLuong();
		}
		else
		{
			return getGiaTien() * getSoLuong();
		}
	}
	friend istream& operator >>(istream& is, DoNuong& n)
	{
		MonAn& m = n;
		is >> m;
		is >> n.kieu;
		is >> n.phuPhi;
		return is;
	}
	friend ostream& operator <<(ostream& os, DoNuong n)
	{
		os << n.getTenMonAn() << " ";
		os << n.getSoLuong() << " ";
		os << n.tienMonAn() << " ";
		return os;
	}
};

class DoLau : public MonAn
{
private:
	int kichThuoc;
	int phuPhi;
public:
	int getKichThuoc()
	{
		return kichThuoc;
	}
	int getPhuPhi()
	{
		return phuPhi;
	}
	void setKichThuoc(int _kichThuoc)
	{
		kichThuoc = _kichThuoc;
	}
	void setPhuPhi(int _phuPhi)
	{
		phuPhi = _phuPhi;
	}
	DoLau(string _tenMonAn = "", int _soLuong = 0, int _giaTien = 0, int _kichThuoc = 0, int _phuPhi = 0)
	{
		kichThuoc = _kichThuoc;
		phuPhi = _phuPhi;
	}
	DoLau(const DoLau& l) : MonAn(l)
	{
		kichThuoc = l.kichThuoc;
		phuPhi = l.phuPhi;
	}
	~DoLau() {};
	int tienMonAn()
	{
		if (kichThuoc == 0)
		{
			return getGiaTien() * getSoLuong();
		}
		else if (kichThuoc == 1)
		{
			return (getGiaTien() + phuPhi) * getSoLuong();
		}
		else if (kichThuoc == 2)
		{
			return (getGiaTien() + phuPhi * 1.5) * getSoLuong();
		}
	}
	friend istream& operator >>(istream& is, DoLau& l)
	{
		MonAn& m = l;
		is >> m;
		is >> l.kichThuoc;
		is >> l.phuPhi;
		return is;
	}
	friend ostream& operator <<(ostream& os, DoLau l)
	{
		os << "\t";
		os << l.getTenMonAn() << " ";
		os << l.getSoLuong() << " ";
		os << l.tienMonAn() << " ";
		return os;
	}
};

class HoaDon
{
private:
	int soHoaDon;
	string ngayDatHang;
	string tenKhachHang;
	string SDT;
	MonAn* monAn[100];
	int soLuongMonAn;
	int tongTien;
public:
	int getSoHoaDon()
	{
		return soHoaDon;
	}
	string getNgayDatHang()
	{
		return ngayDatHang;
	}
	string getTenKhachHang()
	{
		return tenKhachHang;
	}
	string getSDT()
	{
		return SDT;
	}
	int getSoLuongMonAn()
	{
		return soLuongMonAn;
	}
	int getTongTien()
	{
		return tongTien;
	}
	void setSoHoaDon(int _soHoaDon)
	{
		soHoaDon = _soHoaDon;
	}
	void setNgayDatHang(string _ngayDatHang)
	{
		ngayDatHang = _ngayDatHang;
	}
	void setTenKhachHang(string _tenKhachHang)
	{
		tenKhachHang = _tenKhachHang;
	}
	void setSDT(string _SDT)
	{
		SDT = _SDT;
	}
	void setSoLuongMonAn(int _soLuongMonAn)
	{
		soLuongMonAn = _soLuongMonAn;
	}
	void setTongTien(int _tongTien)
	{
		tongTien = _tongTien;
	}
	void setMonAn(MonAn* _monAn[], int _soLuongMonAn)
	{
		soLuongMonAn = _soLuongMonAn;
		for (int i = 0; i < soLuongMonAn; i++)
		{
			monAn[i] = _monAn[i];
		}
	}
	HoaDon(int _soHoaDon = 0, string _ngayDatHang = "", string _tenKhachHang = "", string _SDT = "", int _tongTien = 0, MonAn* _monAn[] = NULL, int _soLuongMonAn = 0)
	{
		soHoaDon = _soHoaDon;
		ngayDatHang = _ngayDatHang;
		tenKhachHang = _tenKhachHang;
		SDT = _SDT;
		soLuongMonAn = _soLuongMonAn;
		tongTien = _tongTien;
		for (int i = 0; i < soLuongMonAn; i++)
		{
			monAn[i] = _monAn[i];
		}
	}
	HoaDon(const HoaDon& h)
	{
		soHoaDon = h.soHoaDon;
		ngayDatHang = h.ngayDatHang;
		tenKhachHang = h.tenKhachHang;
		SDT = h.SDT;
		soLuongMonAn = h.soLuongMonAn;
		tongTien = h.tongTien;
		for (int i = 0; i < soLuongMonAn; i++)
		{
			monAn[i] = h.monAn[i];
		}
	}
	~HoaDon() {};
	int tinhTongTien()
	{
		int sum = 0;
		for (int i = 0; i < soLuongMonAn; i++)
		{
			sum += monAn[i]->tienMonAn();
		}
		return sum;
	}
	int VAT()
	{
		if (tinhTongTien() <= 500000)
		{
			return tinhTongTien() * 0.05;
		}
		else if (tinhTongTien() <= 1500000)
		{
			return tinhTongTien() * 0.1;
		}
		else if (tinhTongTien() > 1500000)
		{
			return tinhTongTien() * 0.15;
		}
	}
	friend istream& operator >>(istream& is, HoaDon& h)
	{
		is >> h.soHoaDon;
		cin.ignore();
		is.clear();
		getline(is, h.ngayDatHang);
		getline(is, h.tenKhachHang);
		is >> h.SDT;
		is >> h.soLuongMonAn;
		char c;
		for (int i = 0; i < h.soLuongMonAn; i++)
		{
			is >> c;
			if (c == 'N')
			{
				DoNuong* p = new DoNuong();
				is >> *p;
				h.monAn[i] = p;
			}
			else if (c == 'L')
			{
				DoLau* p = new DoLau();
				is >> *p;
				h.monAn[i] = p;
			}
		}
		return is;
	}
	friend ostream& operator <<(ostream& os, HoaDon h)
	{
		os << "So Hoa Don: " << h.soHoaDon << endl;
		os << "Ngay Dat Hang: ";
		if (h.ngayDatHang.length() == 8)
		{
			int count = 0;
			for (int i = 0; i < 8; i++)
			{
				count++;
				os << h.ngayDatHang[i];
				if (count == 2 || count == 4)
				{
					os << "/";
				}
			}
			os << endl;
		}
		else
		{
			string ngay = h.ngayDatHang.substr(0, 2);
			string thang = h.ngayDatHang.substr(3, 2);
			string nam = h.ngayDatHang.substr(6, 10);
			os << ngay << "/" << thang << "/" << nam << endl;
		}
		os << "Ten Khach Hang: " << h.tenKhachHang << endl;
		os << "So Dien Thoai: " << h.SDT << endl;
		os << "- Chi Tiet Hoa Don: " << endl;
		for (int i = 0; i < h.soLuongMonAn; i++)
		{
			os << "\t";
			os << *h.monAn[i] << " " << h.monAn[i]->tienMonAn() << endl;
		}
		os << "Tong Tien: " << h.tinhTongTien() << "VND" << endl;
		os << "VAT: " << h.VAT() << "VND" << endl;
		os << "=> Tong Cong: " << h.tinhTongTien() + h.VAT() << "VND" << endl;
		return os;
	}
};

int main()
{
    int n;
    cin >> n;
    vector<HoaDon> danhSachHoaDon;
    for (int i = 0; i < n; i++)
    {
        HoaDon h;
        cin >> h;
        danhSachHoaDon.push_back(h);
    }
    int _max = danhSachHoaDon[0].tinhTongTien();
    vector<int> positions;
    positions.push_back(0);

    for (int i = 1; i < n; i++)
    {
        int current = danhSachHoaDon[i].tinhTongTien();
        if (current > _max)
        {
            _max = current;
            positions.clear();
            positions.push_back(i);
        }
        else if (current == _max)
        {
            positions.push_back(i);
        }
    }

    cout << "HOA DON CO TONG TIEN LON NHAT:" << endl;
    for (int i : positions)
    {
        cout << danhSachHoaDon[i] << endl;
    }
    return 0;
}
