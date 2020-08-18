#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class kiosk {

private:
	vector<string> burger = { "새우버거", "불고기버거", "싸이버거", "딥치즈버거" };
	vector<int>bprice = { 4300, 4500, 4700, 4900 };
	vector<string> side = { "치즈스틱","감자튀김","샐러드 (1500)","아이스크림" };
	vector<int>sprice = { 1500, 1000, 1500, 700 };
	vector<string> drink = { "사이다","콜라","환타","오렌지주스" };
	int dprice = 1000;
	vector<string> total = { "총 주문 메뉴" };
	ofstream writeFile;

public: kiosk();
	  int border, sorder, dorder; 
	  int b, s, d;
	  int cnt = 0;
	  void getburger(); //햄버거
	  void getside(); //사이드메뉴
	  void getdrink(); //음료수
	  void select(int a);//처음에 메뉴 선택?
	  void price();
	  void list();
	  ~kiosk();
};
kiosk::kiosk() {};
kiosk::~kiosk() {};

void kiosk::getburger() // 햄버거
{
	int k;
	for (k = 0; k < 4; k++)
	{
		cout << k + 1 << ". " << burger[k] <<"("<<bprice[k]<<")"<< endl;
	}
	cout << endl << "주문할 버거의 번호와 수량을 입력해주세요." << endl;
	cout << "ex-> 새우버거 2개 : 1 2" << endl;
	cin >> border >> b;

	if (border > 4 || border == 0)
	{
		while (border > 4 || border == 0)
		{
			cout << "존재하지 않는 메뉴를 선택하셨습니다." << endl;
			cout << "다시 선택해주십시오" << endl;
			cin >> border >> b;
		}
	}

	cout << burger[border - 1] << " " << b << "개가 주문되었습니다." << endl;
	//cout << "계속 선택하시겠습니까? ( y or 끝내려면 아무 키나 눌러주세요.)" << endl;
}
void kiosk::getside()
{
	int k;
	for (k = 0; k < 4; k++)
	{
		cout << k + 1 << ". " << side[k] << "(" << sprice[k] << ")"<< endl;
	}
	cout << endl << "주문할 사이드 메뉴의 번호와 수량을 입력해주세요." << endl;
	cout << "ex-> 치즈스틱 2개 : 1 2" << endl;
	cin >> sorder >> s;

	if (sorder > 4 || sorder == 0)
	{
		while (sorder > 4 || sorder == 0)
		{
			cout << "존재하지 않는 메뉴를 선택하셨습니다." << endl;
			cout << "다시 선택해주십시오" << endl;
			cin >> sorder >> s;
		}
	}
	cout << side[sorder - 1] << " " << s << "개가 주문되었습니다." << endl;
	//cout << "계속 선택하시겠습니까? ( y or 끝내려면 아무 키나 눌러주세요.)" << endl;
}
void kiosk::getdrink()
{
	int k;
	for (k = 0; k < 4; k++)
	{
		cout << k + 1 << ". " << drink[k] << "(" << dprice << ")"<< endl;
	}
	cout << endl << "주문할 음료수의 번호와 수량을 입력해주세요." << endl;
	cout << "ex-> 사이다 2개 : 1 2" << endl;
	cin >> dorder >> d;

	if (dorder > 4 || dorder == 0)
	{
		while (dorder > 4 || dorder == 0)
		{
			cout << "존재하지 않는 메뉴를 선택하셨습니다." << endl;
			cout << "다시 선택해주십시오" << endl;
			cin >> dorder >> d;
		}
	}

	cout << drink[dorder - 1] << " " << d << "개가 주문되었습니다." << endl;
}
void kiosk::select(int a)
{
	switch (a)
	{
	case 1:
		getburger();
		break;
	case 2:
		getside();
		break;
	case 3:
		getdrink();
		break;
	}
}
void kiosk::price() {
	cnt = cnt + (b * bprice[border - 1]);//버거 총가격
	cnt = cnt + (s * sprice[sorder - 1]);//사이드
	cnt = cnt + (d * dprice);//음료수
}
void kiosk :: list()
{
	writeFile.open("영수증.txt");
	writeFile<< "======== 영수증 ========\n";
	writeFile << burger[border - 1] << " " << b << "개" << endl;
	writeFile << side[sorder - 1] << " " << s << "개"<<endl;
	writeFile << drink[dorder - 1] << " " << d << "개" << endl;
	writeFile << "========================" << endl;

	writeFile << "총 가격은 " << cnt << "원입니다" << endl;
	writeFile << "감사합니다!" << endl;
	
	writeFile.close();

}

int main()
{
	kiosk one;
	int menunum;
	char keep;
	do
	{
		cout << "======== 메뉴 분류 ========" << endl;
		cout << "1. 햄버거" << endl;
		cout << "2. 사이드" << endl;
		cout << "3. 음료수" << endl;
		cout << "===========================" << endl;
		cout << endl << "몇번을 선택하시겠습니까 ? " << endl;
		cin >> menunum;

		if (menunum < 1 || menunum>3)
		{
			while (menunum < 1 || menunum > 3)
			{
				cout << "존재하지 않는 분류를 선택하셨습니다." << endl;
				cout << "다시 선택해주십시오" << endl;
				cin >> menunum;
				if (menunum > 0 || menunum < 4)
					break;
			}
		}

		one.select(menunum);
		cout << "계속 선택하시겠습니까? ( y or 끝내려면 아무 키나 눌러주세요.)" << endl;
		cin >> keep;
	} while (keep == 'y');

	one.price();
	cout << "영수증이 출력되었습니다." << endl;
	one.list();
}