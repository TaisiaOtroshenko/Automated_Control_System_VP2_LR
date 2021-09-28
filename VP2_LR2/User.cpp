#define _CRT_SECURE_NO_WARNINGS
#include "User.h"

User::User()
{
	m_id = ID_user++;
	time_t now = time(0);
	m_date = ctime(&now);
}

string User::GetLogin()
{
	return m_login;
}

string User::GetPass()
{
	return m_pass;
}

bool User::GetLvl()
{
	return m_lvl;
}

size_t User::GetId()
{
	return m_id;
}

void User::In()
{
	cout << "������� �����:	";
	cin >> m_login;
	cout << "������� ������: ";
	cin >> m_pass;
}


void User::PrintParent() const
{
	cout << "\t\t" << "������� ������ ������������" << endl;

	cout << "���� ������������ - " ;
	(m_lvl) ? (cout << "���������" << endl) : (cout << "������" << endl);

	cout << "ID - " << m_id << endl;
	cout << "����� - " << m_login << endl;
}
ostream& operator<<(ostream& out, const User& man)
{
	man.PrintParent();
	return out;
}

bool operator>(const User& a, const User& b)
{
	return (a.m_id > b.m_id) ? (true) : (false);
}
