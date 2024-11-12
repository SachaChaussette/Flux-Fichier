#pragma once

#include <iostream> // FLUX CONSOLE
#include <fstream> // FLUX FICHIER
#include <string>


using namespace std;
typedef unsigned int u_int;



#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#define CLEAR	cin.clear(); \
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

#define DISPLAY(_text, _endl)	cout << _text; \
								if (_endl) cout << endl;

#define COMPUTE_PATH(_folderPath,_filePath,_fileExtension) _folderPath + _filePath + "." + _fileExtension;

void DisplayLinesByIndex(ifstream & _readStream, const int _numberOfLine);
void DisplayCharacterByIndex(ifstream & _readStream, const char _numberOfChar);
void DisplayMenu(basic_ios<char, char_traits<char>>*_stream);
void Demo();


