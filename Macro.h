#pragma once

#include <iostream>
#include <string>

using namespace std;
typedef unsigned int u_int;

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#define CLEAR	cin.clear(); \
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

#define DISPLAY(_text, _endl)	cout << _text; \
								if (_endl) cout << endl;


void DisplayLinesByIndex(ifstream & _readStream, const int _numberOfLine);
void DisplayCharacterByIndex(ifstream & _readStream, const char _numberOfChar);
void DisplayMenu(basic_ios<char, char_traits<char>>*_stream);
void Demo();

string ComputeBufferAtIndex(const string & _filePath, const int _startIndex);
void AddValue(const string & _filePath, const string & _value, const int _rowToAdd);
string ComputePath(const string & _folderPath, const string & _filePath, const string & _fileExtension);
void DisplayByRow(const string & _filePath, const int _rowsCount, const int _startIndex);
void DisplayByChar(const string & _filePath, const int _charCount, const int _startIndex);
