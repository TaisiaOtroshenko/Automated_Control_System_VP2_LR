#define _CRT_SECURE_NO_WARNINGS
#include "User.h"
using namespace std;

//����������� ��������� ��������� �� int � char � ���������� 

string User::getLogin()
{
	return m_login;
}

string User::getPassword()
{
	return m_pass;
}

User::User()
{
	m_id = ID_user++;
	time_t now = time(0);
	m_date = ctime(&now);
}

void User::In()
{
	cout << "Enter login:	";
	
	cin >> m_login;

	cout << "\nEnter password:	";

	cin >> m_pass;
}




#pragma region  �����
string User::OutLvl()
{
	return (m_lvl) ? ("���������") : ("������");
}
void User::PrintParent() const
{
	//OutLvl();
	cout << "ID ������������ - " << m_id << endl;
	cout << "��� ������������ - " << m_name << endl;
}
ostream& operator<<(ostream& out, const User& man)
{
	man.PrintParent();
	return out;
}
#pragma endregion

