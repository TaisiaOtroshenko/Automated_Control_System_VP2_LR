#pragma once
#include "User.h"

class Client : public User
{
private:
public:
	Client();
	void In();
	void Print() const;
	Client operator=(Client a);
	friend bool operator> (const Client& a, const Client& b);
	friend bool operator== (const Client& a, const Client& b);
};