#pragma once
#include "User.h"

class Employee : public User
{
	size_t m_salary = 60000;
public:
	Employee();
	void In();
	void Print() const;
	Employee operator=(Employee a);
	friend bool operator> (const Employee& a, const Employee& b);
	friend bool operator== (const Employee& a, const Employee& b);
};
