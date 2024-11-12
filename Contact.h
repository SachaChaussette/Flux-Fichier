#pragma once

#include "Macro.h"

struct Contact
{
	string name;
	u_int age;
	string description;

	Contact(const string& _name, const u_int& _age,const string& _description)
	{
		name = _name;
		age = _age;
		description = _description;
	}
};