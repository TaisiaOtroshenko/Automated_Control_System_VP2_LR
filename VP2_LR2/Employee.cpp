#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"

Employee::Employee()
{
	m_lvl = true;
}
void Employee::In()
{
	cout << "Введите логин: ";
	cin >> m_login;
	cout << "Введите пароль: ";
	cin >> m_pass;
	cout << "Введите имя: ";
	cin >> m_name;
}
void Employee::Print() const
{
	PrintParent();
	cout << "Имя - " << m_name << endl;
	cout << "Пароль - " << m_pass << endl;
	cout << "Зарплата - " << m_salary << endl;
}

Employee Employee:: operator=(Employee a)
{
	m_id = a.m_id;
	m_login = a.m_login;
	m_pass = a.m_pass;
	m_name = a.m_name;
	m_lvl = a.m_lvl;
	m_salary = a.m_salary;
	return *this;
}
bool operator> (const Employee& a, const Employee& b)
{
	return 0 <= a.m_name.compare(b.m_name);
}
bool operator== (const Employee& a, const Employee& b)
{
	return (a.m_login == b.m_login && a.m_pass == b.m_pass);
}
