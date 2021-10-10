#pragma once
#include <iostream>
#include "Constants.h"
using namespace std;

class User 
{
protected:
	size_t m_id{};
	string m_login{};
	string m_pass{};
	bool m_lvl{};
	string m_name{};

public:
	
	User();
	string GetLogin();
	string GetPass();
	bool GetLvl();
	size_t GetId();

	void In();
	virtual void PrintParent() const;
	friend ostream& operator<<(ostream& out, const User& man);

	friend bool operator>(const User& a, const User& b);
};