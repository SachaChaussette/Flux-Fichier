#include "Macro.h"
#include <iostream> // FLUX CONSOLE
#include <fstream> // FLUX FICHIER
#include "Mail.h"



int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    locale::global(locale("fr_FR"));

    /*Demo();
    return 0;*/

    const string& _fullPath = ComputePath("", "coucou", "txt");

    /*Mail _mail;
    _mail.AddContact(_fullPath, _mail.CreateContact());

    return 0;*/


    const int _rowsCount = 5, _startRowIndex = 0;
    //DisplayByRow(_fullPath, _rowsCount, _startRowIndex);

    const int _charsCount = 5, _startCharIndex = 0;
    //DisplayByChar(_fullPath, _charsCount, _startCharIndex);

    AddValue(_fullPath, "TEST", 2);

    cout << ComputeBufferAtIndex(_fullPath, 0);

    return EXIT_SUCCESS;
}


void DisplayLinesByIndex(ifstream& _readStream, const int _numberOfLine)
{
    

    string _line;
    cout << "Par ligne : " << endl;
    for (u_int _index = 0; _index < _numberOfLine; _index++)
    {
        getline(_readStream, _line); // _readStream remplace le cin 
        cout << _line << endl;
    }
    
}

void DisplayCharacterByIndex(ifstream& _readStream, const char _numberOfChar)
{
    

    char _letter;
    cout << "Par caract�re : " << endl;
    for (u_int _index = 0; _index < _numberOfChar; _index++)
    {
        _readStream >> _letter;
        cout << _letter;
    }
}

void DisplayMenu(basic_ios<char, char_traits<char>>* _stream)
{
    ifstream& _readStream = dynamic_cast<ifstream&>(*_stream);

    int _entry;
    cout << "Que voulez vous faire ?"
        "\n1- Ligne"
        "\n2- Character\n";
    cin >> _entry;

    u_int _loop;
    cout << "Combien de fois voulez vous l'afficher ?\n";
    cin >> _loop;

    if (_entry == 1)
    {
        // Ligne
        DisplayLinesByIndex(_readStream, _loop);

    }
    else if (_entry == 2)
    {
        // Par caract�re
        DisplayCharacterByIndex(_readStream, _loop);
    }
}



string ComputePath(const string& _folderPath, const string& _filePath, const string& _fileExtension)
{
    return _folderPath + _filePath + "." + _fileExtension;
}

void DisplayByRow(const string& _filePath, const int _rowsCount, const int _startIndex)
{
    // Afficher un nombre n de ligne � partir d'un index
    ifstream _stream = ifstream(_filePath);

    if (!_stream)
    {
        cerr << "ERREUR => Le fichier : " << _filePath << " n'existe pas !\n";
        return;
    }
   
    string _line;
    for (int _index = 0; _index <= _startIndex + _rowsCount; _index++)
    {
        getline(_stream, _line);

        if (_index >= _startIndex)
        {
            cout << _line << endl;
        }
    }
}

void DisplayByChar(const string& _filePath, const int _charCount, const int _startIndex)
{
    // Afficher un nombre n de charact�re � partir d'un index
    ifstream _stream = ifstream(_filePath);
    char _char;

    if (!_stream)
    {
        cerr << "ERREUR => Le fichier : " << _filePath << " n'existe pas !\n";
        return;
    }

    _stream.seekg(streampos(_startIndex));
    for (int _index = 0; _index < _charCount; _index++)
    {
        _stream.get(_char);
        cout << _char << endl;
    }
}

int ComputeLengthOfFile(const string& _filePath)
{
    ifstream _stream = ifstream(_filePath);
    _stream.seekg(0, _stream.end);
    return _stream.tellg();
}

int SetCursorPositionByRow(const string& _filePath, const int _rowToMove)
{
    ifstream _stream = ifstream(_filePath);
    const int _fileLength = ComputeLengthOfFile(_filePath);
    char _char;
    int _currentRow = 0;

    _stream.tellg();

    for (int _index = 0; _index < _fileLength; _index++)
    {
        _stream.get(_char);
        if (_char == '\n' && ++_currentRow >= _rowToMove) return _index;
    }
}

string ComputeBufferAtIndex(const string& _filePath, const int _startIndex)
{
    ifstream _stream = ifstream(_filePath);

    // On d�finit la taille du fichier restant
    _stream.seekg(_startIndex, _stream.end);
    const int _length = _stream.tellg();
    _stream.seekg(0, _stream.beg);

    // On cr�er un tableau
    char* _buffer = new char[_length];
    _stream.read(_buffer, _length);
    string _text = _buffer;

    delete[] _buffer;



    /*string _text;
    char _char;

    while (_stream.get(_char))
    {
        _text += _char;
    }*/
    
    return _text;
}

void AddValue(const string& _filePath, const string& _value, const int _rowToAdd)
{
    ofstream _stream = ofstream(_filePath, ios_base::ate);

    _stream << "Bonjour !" << endl;
    _stream << "Je m'appelle" << endl;
    _stream << "Thomas !" << endl;
 
    const int _startIndex = SetCursorPositionByRow(_filePath, _rowToAdd);
    _stream.seekp(_startIndex);

    _stream << _value;
}


void Demo()
{
    /* Dans le cas console <iostream> */
         // 'cout' permet d'envoyer un type � la console => flux sortant
         // 'cin' => flux entrant

    int _entry;
    cout << "Que voulez vous faire ?"
        "\n1- Lire"
        "\n2- Ecrire\n";
    cin >> _entry;




    /* Dans le cas fichier <fstream> */
    const string& _folderPath = "";
    const string& _filePath = "coucou";
    const string& _fileExtension = "txt";
    const string& _fullPath = _folderPath + _filePath + "." + _fileExtension;

    // les deux h�ritent de basic_ios donc on peut faire polymorphisme
    basic_ios<char, char_traits<char>>* _stream = nullptr;
    ios_base::openmode _openMode;

    if (_entry == 1)
    {
        _openMode = ios_base::in;
        _stream = new ifstream(_fullPath, _openMode);
    }
    else if (_entry == 2)
    {
        _openMode = ios_base::app;
        _stream = new ofstream(_fullPath, _openMode);
    }


    string _string;
    if (_entry == 1)
    {
        // diff�rent moyen de lire

        //// Tout le fichier
        //cout << "Tout le fichier :\n";
        //string _text;
        //while (_readStream >> _text)
        //{
        //    cout << _text << endl;
        //}

        //_readStream.seekg(_readStream.beg);// seekg permet de bouger le curseur et beg le met au d�but du fichier

        //// par mot => '\0'
        //string _word;
        //_readStream >> _word;
        //cout << "Par mot : " << endl;
        //cout << _word << endl;

        //_readStream.seekg(_readStream.beg);

        //_readStream.ignore();
        //_readStream.seekg(_readStream.beg);

        DisplayMenu(_stream);
    }
    if (_entry == 2)
    {
        int _entry;
        cout << "Que voulez vous faire ?"
            "\n1- Donn�e � une Ligne"
            "\n2- Tableau de donn�e � une Ligne\n";
        cin >> _entry;

        if (_entry == 1)
        {
            string _dataToAdd;
            cout << "Quelle donn�e voulez vous ajouter ?\n";
            cin >> _dataToAdd;
            const int _dataToAddLenght = sizeof(_dataToAdd) / sizeof(string);

            u_int _line;
            cout << "Quelle ligne voulez vous ajouter la donn�e ?\n";
            cin >> _line;

            ofstream& _ofStream = dynamic_cast<ofstream&>(*_stream);
            _ofStream.seekp(_line, ofstream::beg);
            _ofStream << _dataToAdd;
        }
        if (_entry == 2)
        {

            dynamic_cast<ofstream&>(*_stream) << "ajout !\n";
        }
    }


    //ofstream _writeStream = ofstream(_fullPath, _openMode); // flux sortant
    //ifstream _readStream = ifstream(_fullPath, _openMode); // flux entrant
    //
    // _stream g�re un fichier 
    //
    //if (_writeStream.is_open())
    //{
    //    cout << "bonjour !\n"; // si le fichier est ouvert alors on affiche bonjour
    //}
    //
    //// toujours test� si c valid
    //if (_writeStream)
    //{
    //    // Ecrire dans le fichier
    //    _writeStream << "\nmargueritte\n"; // stream peut �crire dans le fichier
    //    string _string;
    //    // _writeStream >> _string; ne peux pas r�cup�rer seulement sortant 
    //    _readStream >> _string;
    //
    //    /* 
    //        out
    //        si il n'y pas de fichier il va le cr�er automatiquement
    //        si il y a un fichier il �crase ce qu'il y a dedans et remplace
    //    */
    //
    //    /*
    //        app (append)
    //        si il n'y pas de fichier il va le cr�er automatiquement
    //        si il y a un fichier il �crit � la fin du fichier
    //    */
    //
    //    /*
    //        in
    //        si il n'y pas de fichier il ne va pas le cr�er automatiquement il va juste la lire
    //    */
    //}
    //else
    //{
    //    cerr << "ERREUR => Aucun fichier n'as �t� trouv� � l'adresse : \'" + _fullPath + "\' !\n";
    //    // cerr console error => s'affiche aussi dans les fichiers de log
    //}


    /*
        depuis la racine du projet => .sln (parfois depuis le .exe)

        re�gle toujours tester

    */


    delete _stream;
}
