#define _CRT_SECURE_NO_WARNINGS
#include "Account.h"
using namespace std;

//���� ��������;

Account::Account()
{
	time_t now = time(0);
	m_date = ctime(&now);
}

void Account::Trans(Account scd, int summ_tr)
{
	m_balance -= summ_tr;
	scd.m_balance += summ_tr;
}

void Account::Print() const
{
	cout << "��� ����� - " << m_name << endl;
	cout << "����� ����� - " << m_id << endl;
	cout << "ID ��������� ����� - " << m_id_owner << endl;
	cout << "���� �������� ����� - " << m_date << endl;
	cout << "\t ������: " << m_balance << endl;
}
ostream& operator<< (ostream& out, const Account& acc)
{
	acc.Print();
	return out;
}

Account Account:: operator=(Account a)
{
	m_id = a.m_id;
	m_date = a.m_date;
	m_name = a.m_name;
	m_id_owner = a.m_id_owner;
	m_balance = a.m_balance;
	m_date = a.m_date;
	return a;
}
bool operator> (const Account& a, const Account& b)
{
	return a.m_name > b.m_name;
}