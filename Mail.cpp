#include "Mail.h"
#include <fstream> // FLUX FICHIER
#include "UserInteraction.h" // FLUX FICHIER



Contact Mail::CreateContact()
{
	string _name = GetString("Quel est son nom ?");
	u_int _age = GetNumber("Quel est son age ?");
	string _descripion = GetString("Quelle est sa description ?");

	return Contact(_name, _age, _descripion);
}

void Mail::AddContact(const string& _filePath, const Contact& _contact)
{
	ofstream _writeStream = ofstream(_filePath, ofstream::app);
	ifstream _readStream = ifstream(_filePath, ifstream::app);
	if (!_writeStream)
	{
		cerr << "ERREUR => Le fichier : " << _filePath << " n'existe pas !\n";
		return;
	}
	else
	{
		string _result; 
		_readStream >> _result;

		_writeStream << endl << _contact.name << " (" << _contact.age << " ans) :   " << _contact.description;
	}
}

void Mail::RemoveContact()
{

}
