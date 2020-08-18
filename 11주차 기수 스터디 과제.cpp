#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class kiosk {

private:
	vector<string> burger = { "�������", "�Ұ�����", "���̹���", "��ġ�����" };
	vector<int>bprice = { 4300, 4500, 4700, 4900 };
	vector<string> side = { "ġ�ƽ","����Ƣ��","������ (1500)","���̽�ũ��" };
	vector<int>sprice = { 1500, 1000, 1500, 700 };
	vector<string> drink = { "���̴�","�ݶ�","ȯŸ","�������ֽ�" };
	int dprice = 1000;
	vector<string> total = { "�� �ֹ� �޴�" };
	ofstream writeFile;

public: kiosk();
	  int border, sorder, dorder; 
	  int b, s, d;
	  int cnt = 0;
	  void getburger(); //�ܹ���
	  void getside(); //���̵�޴�
	  void getdrink(); //�����
	  void select(int a);//ó���� �޴� ����?
	  void price();
	  void list();
	  ~kiosk();
};
kiosk::kiosk() {};
kiosk::~kiosk() {};

void kiosk::getburger() // �ܹ���
{
	int k;
	for (k = 0; k < 4; k++)
	{
		cout << k + 1 << ". " << burger[k] <<"("<<bprice[k]<<")"<< endl;
	}
	cout << endl << "�ֹ��� ������ ��ȣ�� ������ �Է����ּ���." << endl;
	cout << "ex-> ������� 2�� : 1 2" << endl;
	cin >> border >> b;

	if (border > 4 || border == 0)
	{
		while (border > 4 || border == 0)
		{
			cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�." << endl;
			cout << "�ٽ� �������ֽʽÿ�" << endl;
			cin >> border >> b;
		}
	}

	cout << burger[border - 1] << " " << b << "���� �ֹ��Ǿ����ϴ�." << endl;
	//cout << "��� �����Ͻðڽ��ϱ�? ( y or �������� �ƹ� Ű�� �����ּ���.)" << endl;
}
void kiosk::getside()
{
	int k;
	for (k = 0; k < 4; k++)
	{
		cout << k + 1 << ". " << side[k] << "(" << sprice[k] << ")"<< endl;
	}
	cout << endl << "�ֹ��� ���̵� �޴��� ��ȣ�� ������ �Է����ּ���." << endl;
	cout << "ex-> ġ�ƽ 2�� : 1 2" << endl;
	cin >> sorder >> s;

	if (sorder > 4 || sorder == 0)
	{
		while (sorder > 4 || sorder == 0)
		{
			cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�." << endl;
			cout << "�ٽ� �������ֽʽÿ�" << endl;
			cin >> sorder >> s;
		}
	}
	cout << side[sorder - 1] << " " << s << "���� �ֹ��Ǿ����ϴ�." << endl;
	//cout << "��� �����Ͻðڽ��ϱ�? ( y or �������� �ƹ� Ű�� �����ּ���.)" << endl;
}
void kiosk::getdrink()
{
	int k;
	for (k = 0; k < 4; k++)
	{
		cout << k + 1 << ". " << drink[k] << "(" << dprice << ")"<< endl;
	}
	cout << endl << "�ֹ��� ������� ��ȣ�� ������ �Է����ּ���." << endl;
	cout << "ex-> ���̴� 2�� : 1 2" << endl;
	cin >> dorder >> d;

	if (dorder > 4 || dorder == 0)
	{
		while (dorder > 4 || dorder == 0)
		{
			cout << "�������� �ʴ� �޴��� �����ϼ̽��ϴ�." << endl;
			cout << "�ٽ� �������ֽʽÿ�" << endl;
			cin >> dorder >> d;
		}
	}

	cout << drink[dorder - 1] << " " << d << "���� �ֹ��Ǿ����ϴ�." << endl;
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
	cnt = cnt + (b * bprice[border - 1]);//���� �Ѱ���
	cnt = cnt + (s * sprice[sorder - 1]);//���̵�
	cnt = cnt + (d * dprice);//�����
}
void kiosk :: list()
{
	writeFile.open("������.txt");
	writeFile<< "======== ������ ========\n";
	writeFile << burger[border - 1] << " " << b << "��" << endl;
	writeFile << side[sorder - 1] << " " << s << "��"<<endl;
	writeFile << drink[dorder - 1] << " " << d << "��" << endl;
	writeFile << "========================" << endl;

	writeFile << "�� ������ " << cnt << "���Դϴ�" << endl;
	writeFile << "�����մϴ�!" << endl;
	
	writeFile.close();

}

int main()
{
	kiosk one;
	int menunum;
	char keep;
	do
	{
		cout << "======== �޴� �з� ========" << endl;
		cout << "1. �ܹ���" << endl;
		cout << "2. ���̵�" << endl;
		cout << "3. �����" << endl;
		cout << "===========================" << endl;
		cout << endl << "����� �����Ͻðڽ��ϱ� ? " << endl;
		cin >> menunum;

		if (menunum < 1 || menunum>3)
		{
			while (menunum < 1 || menunum > 3)
			{
				cout << "�������� �ʴ� �з��� �����ϼ̽��ϴ�." << endl;
				cout << "�ٽ� �������ֽʽÿ�" << endl;
				cin >> menunum;
				if (menunum > 0 || menunum < 4)
					break;
			}
		}

		one.select(menunum);
		cout << "��� �����Ͻðڽ��ϱ�? ( y or �������� �ƹ� Ű�� �����ּ���.)" << endl;
		cin >> keep;
	} while (keep == 'y');

	one.price();
	cout << "�������� ��µǾ����ϴ�." << endl;
	one.list();
}