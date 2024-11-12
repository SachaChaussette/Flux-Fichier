#pragma once

#include "Macro.h"

int GetNumber(const string& _question)
{
	do
	{
		DISPLAY(_question, true);
		int _result;

		if (cin >> _result)
		{
			CLEAR;
			return _result;
		}
		CLEAR;
		DISPLAY("ERREUR => Tu n'as pas donné de nomber entier !!!", true);
		system("pause");
		system("cls");
	} while (true);
}

string GetString(const string& _question)
{
	DISPLAY(_question, true);
	string _result;
	getline(cin, _result);
	return _result;
}