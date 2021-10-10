#define _CRT_SECURE_NO_WARNINGS
#include "Client.h"

Client::Client()
{
	m_lvl = false;
}
void Client::In()
{
	cout << "¬ведите логин: ";
	cin >> m_login;
	cout << "¬ведите пароль: ";
	cin >> m_pass;
	cout << "¬ведите им€: ";
	cin >> m_name;
}
void Client::Print() const
{
	PrintParent();
	cout << "»м€ - " << m_name << endl;
	cout << "ѕароль - " << m_pass << endl;
}

Client Client::operator=(Client a)
{
	m_id = a.m_id;
	m_lvl = a.m_lvl;
	m_name = a.m_name;
	m_login = a.m_login;
	m_pass = a.m_pass;
	return *this;
}
bool operator> (const Client& a, const Client& b)
{
	return 0<=a.m_name.compare(b.m_name);
}
bool operator== (const Client& a, const Client& b)
{
	return (a.m_login == b.m_login && a.m_pass == b.m_pass);
}
