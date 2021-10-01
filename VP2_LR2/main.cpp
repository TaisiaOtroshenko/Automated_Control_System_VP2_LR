/*
������� - ������� ����������� �������
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "CMenu.h"
#include "Client.h"
#include "Employee.h"
#include "Account.h"
#include "Func.h"
#include "Constants.h"

using namespace std;
using namespace otv;

vector <Client> CLIENT{};
vector <Employee> EMPLOYEE{};
vector <Account> ACCOUNT{};

#pragma region ���������

int AddClient();
int AddEmployee();
int Verify();

int EditUser();

int OutputAcc(/*�������� � ������� - �����*/);
int AddAcc(); 
int DelAcc();
int DelCli();

int ListAcc();
int ListCli();
int DelEmp();

int VerifyOut();

//�� �������� �������� �������� � �������-�������. ������ ������.
int AddIt();
int DelIt();
int EditIt();
int SortIt();
int FilterIt();

int ListOut();

void Screen_0();
void Screen_1();
void Screen_2();
void Screen_3();

void Save();
#pragma endregion

int main()
{
	setlocale(0, "");

	ifstream fin_bin;
	int tmp_size{};
#pragma region �������� ����� ��������
	try
	{
		fin_bin.open(CLI, ios_base::in | ios::binary);
	}
	catch (...)
	{
		cout << "�� ������� ������� ����" << endl;
	}
	fin_bin.read((char*)&tmp_size, sizeof(int));
	Client tmp_client{};

	for (int i = 0; i < tmp_size && !fin_bin.eof(); i++)
	{
		fin_bin.read((char*)&tmp_client, sizeof(Client));
		if (tmp_client.GetId() > id_us)
		{
			id_us = tmp_client.GetId();
		}
		CLIENT.push_back(tmp_client);
	}
	fin_bin.close();
#pragma endregion
#pragma region �������� ����� �����������
	try
	{
		fin_bin.open(EMP, ios_base::in | ios::binary);
	}
	catch (...)
	{
		cout << "�� ������� ������� ����" << endl;
	}
	fin_bin.read((char*)&tmp_size, sizeof(int));
	Employee tmp_employee{};

	for (int i = 0; i < tmp_size && !fin_bin.eof(); i++)
	{
		fin_bin.read((char*)&tmp_employee, sizeof(Employee));
		if (tmp_employee.GetId() > id_us)
		{
			id_us = tmp_employee.GetId();
		}
		EMPLOYEE.push_back(tmp_employee);
	}
	fin_bin.close();
#pragma endregion
#pragma region �������� ����� ����
	try
	{
		fin_bin.open(ACC, ios_base::in | ios::binary);
	}
	catch (...)
	{
		cout << "�� ������� ������� ����" << endl;
	}
	
	fin_bin.read((char*)&tmp_size, sizeof(int));
	Account tmp_account{};

	for (int i = 0; i < tmp_size && !fin_bin.eof(); i++)
	{
		fin_bin.read((char*)&tmp_account, sizeof(Account));
		if (tmp_account.GetId() > id_acc)
		{
			id_acc = tmp_account.GetId();
		}
		ACCOUNT.push_back(tmp_account);
	}
	fin_bin.close();
#pragma endregion	

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
		try
		{
			for (int i = 0; i < CLIENT.size(); ++i)
			{
				if (CLIENT[i].GetLogin() == tmp_cli.GetLogin())
				{
					throw - 1;
				}
			}
			for (int i = 0; i < EMPLOYEE.size(); ++i)
			{
				if (EMPLOYEE[i].GetLogin() == tmp_cli.GetLogin())
				{
					throw - 1;
				}
			}
		}
		catch (int)
		{
			cout << "������������ � ����� ������� ��� ����������. ����������, ���������� ��� ��� � ������ �������." << endl;
			return 0;
		}
		CLIENT.push_back(tmp_cli);
		cout << "������������ ������." << endl;
		return 0;
	}
	int AddEmployee()
		//��������� ���������� � ������
	{
		Employee tmp_emp{};
		tmp_emp.In();
		try
		{
			for (int i = 0; i < CLIENT.size(); ++i)
			{
				if (CLIENT[i].GetLogin() == tmp_emp.GetLogin())
				{
					throw - 1;
				}
			}
			for (int i = 0; i < EMPLOYEE.size(); ++i)
			{
				if (EMPLOYEE[i].GetLogin() == tmp_emp.GetLogin())
				{
					throw - 1;
				}
			}
		}
		catch (int)
		{
			cout << "������������ � ����� ������� ��� ����������. ����������, ���������� ��� ��� � ������ �������." << endl;
			return 0;
		}
		EMPLOYEE.push_back(tmp_emp);
		cout << "������������ ������." << endl;
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
			cout << "���� �� ��������. ��������� ������������ ��������� ������ � ��������� �������." << endl;
		}
		return 0;
	}
#pragma endregion
void Screen_0()
{
	system("cls");
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
	//((Client*)CUR_USER)->Print(); - ������ - ��������� ���� ������� ��� ������ �� ������
	CUR_USER->PrintParent();
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
int DelAcc()
{
	size_t id_acc{};
	size_t id_owner = CUR_USER->GetId();
	cout << "\n������� id ��������, ������� ������ �������:" << endl;
	cin >> id_acc;
	for (int i = 0; i < ACCOUNT.size(); ++i)
	{
		if (id_owner == ACCOUNT[i].GetIdOwner() && id_acc == ACCOUNT[i].GetId())
		{
			ACCOUNT.erase(ACCOUNT.begin() + i);
			cout << "���� ����� ������� �������" << endl;
			system("pause");
			break;
		}
	}
	return 0;
}
int DelCli()
{
	size_t id = CUR_USER->GetId();
	for (int i = 0; i < CLIENT.size(); ++i)
	{
		if (id == CLIENT[i].GetId())
		{
CLIENT.erase(CLIENT.begin() + i);
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
	cur_list = 1;
	Screen_3();
	return 0;
}
int ListCli()
{
	cur_list = 0;
	Screen_3();
	return 0;
}
int DelEmp()
{
	size_t id{};
	for (int i = 0; i < CLIENT.size(); i++)
	{
		if (CUR_USER->GetId() == CLIENT[i].GetId())
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
//int VerifyOut � EditUser ������������ ��� ���������� � �������
#pragma endregion
void Screen_2()
{
#pragma region ���������� ������� ������� ���� ����������
	
	FIN_TXT.open(MENU_EMP);

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
int AddIt() 
{
	if (cur_list)
	{
		//Add<Client>(CLIENT);
	}
	else
	{
		//Add<Account>(ACCOUNT);
	}
	return 0;
};
int DelIt() 
{
	//(cur_list) ? (Del<Client>(CLIENT)) : (Del<Account>(ACCOUNT));
	return 0;
};
int EditIt() 
{
	//(cur_list) ? (Edit<Client>(CLIENT)) : (Edit<Account>(ACCOUNT));
	return 0;
};
int SortIt() 
{
	//(cur_list) ? (Sort<Client>(CLIENT)) : (Sort<Account>(ACCOUNT));
	return 0;
};
int FilterIt() 
{
	//(cur_list) ? (Filter<Client>(CLIENT)) : (Filter<Account>(ACCOUNT));
	return 0;
};
int ListOut() 
{
	cur_list = -1;
	system("cls");
	return 0;
}
#pragma endregion
void Screen_3()
{
	system("cls");
#pragma region ���������� ������� ������� ���� �������
	
	FIN_TXT.open(MENU_LIST);

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

	item[0].SetFunc(AddIt);
	item[1].SetFunc(DelIt);
	item[2].SetFunc(EditIt);
	item[3].SetFunc(SortIt);
	item[4].SetFunc(FilterIt);
	item[5].SetFunc(ListOut);
#pragma endregion
#pragma region ����� ���� �������
	string title = (cur_list) ? ("���� ������ ��������") : ("���� ������ ����");
	CMenu menu_list = CMenu(title, item, item_count, Save);
	while (cur_list != -1)
	{
		cout << menu_list;
		cin >> menu_list;
	}
#pragma endregion
}

void Save()
{
	//��������� ������� � ������ �������� � �����
	ofstream fout_bin{};
	size_t tmp_size{};
#pragma region �������� �������� � ����

	fout_bin.open(CLI, ios::binary | ios::out);
	fout_bin.clear();

	tmp_size = CLIENT.size();

	fout_bin.write((char*)&(tmp_size), sizeof(int));

	for (int i = 0; i < tmp_size && fout_bin.is_open(); i++)
	{
		fout_bin.write((char*)&(CLIENT[i]), sizeof(Client));
	}
	fout_bin.close();
#pragma endregion
#pragma region �������� ����������� � ����

	fout_bin.open(EMP, ios_base::out | ios::binary);
	fout_bin.clear();

	tmp_size = EMPLOYEE.size();

	fout_bin.write((char*)&(tmp_size), sizeof(int));

	for (int i = 0; i < tmp_size && fout_bin.is_open(); i++)
	{
		fout_bin.write((char*)&(EMPLOYEE[i]), sizeof(Employee));
	}
	fout_bin.close();
#pragma endregion
#pragma region �������� ���� � ����

	fout_bin.open(ACC, ios_base::out | ios::binary);
	fout_bin.clear();

	tmp_size = ACCOUNT.size();

	fout_bin.write((char*)&(tmp_size), sizeof(int));

	for (int i = 0; i < tmp_size && fout_bin.is_open(); i++)
	{
		fout_bin.write((char*)&(ACCOUNT[i]), sizeof(Account));
	}
	fout_bin.close();
#pragma endregion
}

