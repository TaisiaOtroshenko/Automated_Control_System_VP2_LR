#define _CRT_SECURE_NO_WARNINGS
#include "User.h"

User::User()
{
	m_id = id_us++;
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
	cout << "\tВвод данных пользователя" << endl;
	cout << "Введите логин:	";
	cin >> m_login;
	cout << "Введите пароль: ";
	cin >> m_pass;
}

void User::PrintParent() const
{
	cout << "\tТекущие данные пользователя" << endl;

	cout << "Роль пользователя - " ;
	(m_lvl) ? (cout << "Сотрудник" << endl) : (cout << "Клиент" << endl);

	cout << "ID - " << m_id << endl;
	cout << "Логин - " << m_login << endl;
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
