#pragma once
#include <iostream>
#include "Constants.h"
using namespace std;

class Account
{
	size_t m_id_owner{};
	size_t m_id{};
	string m_name{};
	unsigned long m_balance{};
public:
	Account();
	Account(size_t id_owner);

	size_t GetId();
	size_t GetIdOwner();

	void In();
	void Print() const;
	friend ostream& operator<<(ostream& out, const Account& acc);

	Account operator=(Account a);
	friend bool operator> (const Account& a, const Account& b);
};
