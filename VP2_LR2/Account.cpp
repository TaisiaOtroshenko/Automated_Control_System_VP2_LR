#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"

Account::Account()
{
	m_id = id_acc++;
}
Account::Account(size_t id_owner)
{
	m_id_owner = id_owner;
	m_id = id_acc++;
}
size_t Account::GetId()
{
	return m_id;
}
size_t Account::GetIdOwner()
{
	return m_id_owner;
}

void Account::In()
{
	cout << "Введите имя карты: ";
	cin >> m_name;
}

void Account::Print() const
{
	cout << "Имя карты - " << m_name << endl;
	cout << "Номер карты - " << m_id << endl;
	cout << "ID владельца карты - " << m_id_owner << endl;
	cout << "\t Баланс: " << m_balance << endl;
}
ostream& operator<< (ostream& out, const Account& acc)
{
	acc.Print();
	return out;
}

Account Account:: operator=(Account a)
{
	m_id = a.m_id;
	m_name = a.m_name;
	m_id_owner = a.m_id_owner;
	m_balance = a.m_balance;
	return a;
}
bool operator> (const Account& a, const Account& b)
{
	return 0 <= a.m_name.compare(b.m_name);
}