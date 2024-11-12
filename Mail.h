#pragma once

#include "Contact.h"

class Mail
{

public:
	Contact CreateContact();
	void AddContact(const string& _filePath, const Contact& _contact);
	void RemoveContact();
};

