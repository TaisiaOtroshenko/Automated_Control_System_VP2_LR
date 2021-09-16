#include <iostream>
#include <fstream>
#include <vector>

#include "CMenu.h"
#include "Client.h"
#include "Employee.h"
#include "Account.h"
//#include "Func.h"

using namespace std;
using namespace otv;

#pragma region ���������

typedef int(*func)();

string CLI = "client.bin", EMP = "employee.bin", ACC = "account.bin",

MENU_AUTH = "menu_auth.txt",
MENU_CLI = "menu_client.txt",
MENU_EMP = "menu_employee.txt",
MENU_LIST = "menu_list.txt";
ifstream FIN_TXT;

char* buff = new char[1024]{};

vector <Client> CLIENT{};
vector <Employee> EMPLOYEE{};
vector <Account> ACCOUNT{};
User* CUR_USER{};
#pragma endregion

#pragma region ������ ������� (.h)

//�������� �� ����������� ������
int AddClient();
int AddEmployee();
int Verify();

//�������� �� ����������� ������
int EditUser();

int OutputAcc(/*�������� � ������� - �����*/);
int AddAcc(); 
int DelAcc(/*�� �������� - �������� � �������*/);
int DelCli(/*�� �������� - �������� � �������*/);

int ListAcc();
int ListCli();
int DelEmp();

//�������� �� ����������� ������
int VerifyOut();

int AddIt();
int DelIt();
int EditIt();
int SortIt();
int FilterIt();
int ListOut();

//�������� �� ����������� ������
void Screen_0();
void Screen_1();
void Screen_2();
void Screen_3();

void Begin();
void Save(/*�� ��������*/);
#pragma endregion

int main()
{
	setlocale(0, "");

	Begin();

	while (CUR_USER == nullptr)
	{
		Screen_0();
		if (!CUR_USER->GetLvl())
		{
			Screen_1();
		}
		else
		{
			Screen_2();
		}
	}
	
	system("pause");
	return 0;
}


#pragma region ������� ���� �����������
	int AddClient()
		//��������� ������� � ������
	{
		Client tmp_cli{};
		tmp_cli.In();
		CLIENT.push_back(tmp_cli);
		return 0;
	}
	int AddEmployee()
		//��������� ���������� � ������
	{
		Employee tmp_emp{};
		tmp_emp.In();
		EMPLOYEE.push_back(tmp_emp);
		return 0;
	}
	int Verify()
		//�������� �� �������� �������������, ������� ������ � ������
	{
		User tmp_user{};
		tmp_user.In();
		for (int i = 0; i < CLIENT.size(); i++)
		{
			if (tmp_user.GetLogin() == CLIENT[i].GetLogin())
			{
				cout << "������������ ������" << endl;
				if (tmp_user.GetPass() == CLIENT[i].GetPass()) {
					CUR_USER = &CLIENT[i];
					cout << "������ ������" << endl;
				}
				else
				{
					cout << "�������� ������" << endl;
				}
			}
		}
		for (int i = 0; i < EMPLOYEE.size(); i++)
		{
			if (tmp_user.GetLogin() == EMPLOYEE[i].GetLogin())
			{
				cout << "������������ ������" << endl;
				if (tmp_user.GetPass() == EMPLOYEE[i].GetPass()) {
					CUR_USER = &EMPLOYEE[i];
					cout << "������ ������" << endl;
				}
				else
				{
					cout << "�������� ������" << endl;
				}
			}
		}
		if (CUR_USER == nullptr)
		{
			cout << "������� ������� ������" << endl;
		}
		return 0;
	}
#pragma endregion
void Screen_0()
{
#pragma region ���������� ������� ������� ���� �����������

	FIN_TXT.open(MENU_AUTH);

	size_t item_count_1{};
	FIN_TXT >> item_count_1;
	FIN_TXT.ignore();

	ItemMenu* items_1 = new ItemMenu[item_count_1]{};
	for (int i = 0; i < item_count_1 && FIN_TXT.is_open(); i++)
	{
		FIN_TXT.getline(buff, 1023);
		items_1[i].SetItemName(buff);
	}
	FIN_TXT.close();


	items_1[0].SetFunc(AddClient);
	items_1[1].SetFunc(AddEmployee);
	items_1[2].SetFunc(Verify);
#pragma endregion
#pragma region ����� ���� ����������

	CMenu menu_auth = CMenu("���� �����", items_1, item_count_1, Save);

	while (CUR_USER == nullptr)
	{
		cout << menu_auth;
		cin >> menu_auth;
	}
#pragma endregion
}



#pragma region ������� ���� �������
int EditUser()
{
	CUR_USER->PrintParent();
	cout << "\t������� ����� ������" << endl;
	CUR_USER->In();
	cout << "������ ������� ��������" << endl;
	return 0;
}
int OutputAcc()
{
	bool have = false;
	for (int i = 0; i < ACCOUNT.size(); i++)
	{
		if (ACCOUNT[i].GetIdOwner() == CUR_USER->GetId())
		{
			ACCOUNT[i].Print();
			have = true;
		}
	}
	if (!have)
	{
		cout << "� ��� ��� ����" << endl;
	}
	return 0;
}
int AddAcc()
{
	Account tmp_acc(CUR_USER->GetId());
	tmp_acc.In();
	ACCOUNT.push_back(tmp_acc);
	return 0;
}
int DelAcc(/*�� ��������*/)
{
	cout << "������� ����� �����, ������� ������ �������" <<
		"\n�������������, ��� ������ ����� ����� �������. ������� �������������� ������ � ���������." << endl;
	size_t id;
	cin >> id;
	// ����� ������ �������� � �������� id
	bool have = false;
	for (size_t i = 0; i < ACCOUNT.size(); i++)
	{
		if (ACCOUNT[i].GetId() == id)
		{
			have = true;
			id = i;
			break;
		}
	}
	//��������. ����� � �� ��������. ���� �� ��������
	if (!have)
	{
		cout << "��� ����� � ����� ��������" << endl;
	}
	else
	{
			CLIENT.erase(CLIENT.begin() + (id - 1));
			cout << "����� �������" << endl;
	}
	return 0;
}
int DelCli()
{
	size_t id = CUR_USER->GetId();
	for (int i = 0; i < CLIENT.size(); i++)
	{
		if (id == CLIENT[i].GetId())
		{
			CLIENT.erase(CLIENT.begin() + (id-1001));
			cout << "������������ ������� ������" << endl;
			system("pause");
			VerifyOut();
			break;
		}
	}
	return 0;
}
int VerifyOut()
{
	CUR_USER = nullptr;
	system("cls");
	return 0;
}
#pragma endregion
void Screen_1()
{
#pragma region ���������� ������� ������� ���� �������

	FIN_TXT.open(MENU_CLI);

	size_t item_count{};
	FIN_TXT >> item_count;
	FIN_TXT.ignore();

	ItemMenu* item = new ItemMenu[item_count]{};
	for (int i = 0; i < item_count && FIN_TXT.is_open(); i++)
	{
		FIN_TXT.getline(buff, 1023);
		item[i].SetItemName(buff);
	}
	FIN_TXT.close();


	item[0].SetFunc(EditUser);
	item[1].SetFunc(OutputAcc);
	item[2].SetFunc(AddAcc);
	item[3].SetFunc(DelAcc);
	item[4].SetFunc(DelCli);
	item[5].SetFunc(VerifyOut);

#pragma endregion
#pragma region ����� ���� �������

	CMenu menu_cli = CMenu("���� �������", item, item_count, Save);

	while (CUR_USER != nullptr)
	{
		cout << menu_cli;
		cin >> menu_cli;
	}
#pragma endregion
}


#pragma region ������� ���� ����������
int ListAcc()
{
	return 0;
}
int ListCli()
{
	return 0;
}
int DelEmp()
{
	size_t id{};
	for (int i = 0; i < CLIENT.size(); i++)
	{
		if (CUR_USER->GetId() == CLIENT[i].GetId())// �� ������ ���� ���������
		{
		id = CUR_USER->GetId();
		CLIENT.erase(CLIENT.begin() + id);
		CUR_USER = nullptr;
		cout << "������������ ������� ������" << endl;
		break;
		}
	}
	return 0;
}
#pragma endregion
void Screen_2()
{
#pragma region ���������� ������� ������� ���� ����������
	ifstream FIN_TXT;
	FIN_TXT.open(MENU_EMP);
	size_t item_count{};
	FIN_TXT >> item_count;

	ItemMenu* item = new ItemMenu[item_count]{};
	for (int i = 0; i < item_count && FIN_TXT.is_open(); i++)
	{
		FIN_TXT >> buff;
		item[i].SetItemName(buff);
	}
	FIN_TXT.close();

	item[0].SetFunc(EditUser);
	item[1].SetFunc(ListAcc);
	item[2].SetFunc(ListCli);
	item[3].SetFunc(DelEmp);
	item[4].SetFunc(VerifyOut);
#pragma endregion
#pragma region ����� ���� ����������
CMenu menu_emp = CMenu("���� ����������", item, item_count, Save);
	while (CUR_USER!=nullptr)
	{
		cout << menu_emp;
		cin >> menu_emp;
	}
#pragma endregion
}


#pragma region ������� ���� ������ �� ��������
int AddIt() {
	return 0;
};
int DelIt() {
	return 0;
};
int EditIt() {
	return 0;
};
int SortIt() {
	return 0;
};
int FilterIt() {
	return 0;
};
int ListOut() {
	return 0;
}
#pragma endregion
void Screen_3()
{
#pragma region ���������� ������� ������� ���� �������
	ifstream FIN_TXT;
	FIN_TXT.open(MENU_LIST);
	size_t item_count{};
	FIN_TXT >> item_count;

	ItemMenu* item = new ItemMenu[item_count]{};
	for (int i = 0; i < item_count && FIN_TXT.is_open(); i++)
	{
		FIN_TXT >> buff;
		item[i].SetItemName(buff);
	}
	FIN_TXT.close();

	item[0].SetFunc(AddIt);
	item[1].SetFunc(DelIt);
	item[2].SetFunc(EditIt);
	item[3].SetFunc(SortIt);
	item[4].SetFunc(FilterIt);
	item[5].SetFunc(VerifyOut);
#pragma endregion
#pragma region ����� ���� �������
	CMenu menu_list = CMenu("���� ������", item, item_count, Save);
	while (CUR_USER != nullptr) //����� ������� �������� �� ���������� �����
	{
		cout << menu_list;
		cin >> menu_list;
	}
#pragma endregion
}



void Begin()
{
	ifstream fin_bin;
#pragma region �������� ����� ��������

	fin_bin.open(CLI, ios_base::in | ios::binary);

	size_t item_count{};
	fin_bin >> item_count;
	fin_bin.ignore();


	Client tmp_client{};
	for (int i = 0; i < item_count && fin_bin.is_open(); i++)
	{
		fin_bin.read((char*)&tmp_client, sizeof(Client));
		CLIENT.push_back(tmp_client);
	}
	fin_bin.close();
#pragma endregion
#pragma region �������� ����� �����������

	fin_bin.open(EMP, ios_base::in | ios::binary);

	item_count = 0;
	fin_bin >> item_count;
	fin_bin.ignore();


	Employee tmp_employee{};
	for (int i = 0; i < item_count && fin_bin.is_open(); i++)
	{
		fin_bin.read((char*)&tmp_employee, sizeof(Employee));
		EMPLOYEE.push_back(tmp_employee);
	}
	fin_bin.close();
#pragma endregion
#pragma region �������� ����� ����

	fin_bin.open(ACC, ios_base::in | ios::binary);

	item_count = 0;
	fin_bin >> item_count;
	fin_bin.ignore();

	Account tmp_account{};
	for (int i = 0; i < item_count && fin_bin.is_open(); i++)
	{
		fin_bin.read((char*)&tmp_account, sizeof(Account));
		ACCOUNT.push_back(tmp_account);
	}
	fin_bin.close();
#pragma endregion
}
void Save()
{
	ofstream fout_bin{};
#pragma region �������� ����� ��������

	fout_bin.open(CLI, ios_base::out | ios::binary);
	fout_bin.clear();
	//fout_bin.clear(); ���� ����� ������������� ������
	for (int i = 0; i < CLIENT.size() && fout_bin.is_open(); i++)
	{
		fout_bin.write((char*)&CLIENT[i], sizeof(Client));
	}
	fout_bin.close();
#pragma endregion

#pragma region �������� ����� �����������

	fout_bin.open(EMP, ios_base::out | ios::binary);
	fout_bin.clear();

	for (int i = 0; i < EMPLOYEE.size() && fout_bin.is_open(); i++)
	{
		fout_bin.write((char*)&EMPLOYEE[i], sizeof(Employee));
	}
	fout_bin.close();
#pragma endregion

#pragma region �������� ����� ����

	fout_bin.open(ACC, ios_base::out | ios::binary);
	fout_bin.clear();

	for (int i = 0; i < ACCOUNT.size() && fout_bin.is_open(); i++)
	{
		fout_bin.write((char*)&ACCOUNT[i], sizeof(Account));
	}
	fout_bin.close();
#pragma endregion
}