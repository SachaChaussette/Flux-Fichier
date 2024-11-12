#include "Macro.h"
#include "StreamFunctions.h"



int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    locale::global(locale("fr_FR"));

    /*Demo();z
    return 0;*/

    const string& _fullPath = ComputePath("", "coucou","txt");

    /*Mail _mail;
    _mail.AddContact(_fullPath, _mail.CreateContact());

    return 0;*/


    const int _rowsCount = 5, _startRowIndex = 0;
    //DisplayByRow(_fullPath, _rowsCount, _startRowIndex);

    const int _charsCount = 5, _startCharIndex = 0;
    //DisplayByChar(_fullPath, _charsCount, _startCharIndex);

    //AddValue(_fullPath, "TEST", 2);

    //cout << ComputeBufferAtIndex(_fullPath, 0);

    RemoveLine(_fullPath, 1);

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
    cout << "Par caractère : " << endl;
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
        // Par caractère
        DisplayCharacterByIndex(_readStream, _loop);
    }
}

void Demo()
{
    /* Dans le cas console <iostream> */
         // 'cout' permet d'envoyer un type à la console => flux sortant
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

    // les deux héritent de basic_ios donc on peut faire polymorphisme
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
        // différent moyen de lire

        //// Tout le fichier
        //cout << "Tout le fichier :\n";
        //string _text;
        //while (_readStream >> _text)
        //{
        //    cout << _text << endl;
        //}

        //_readStream.seekg(_readStream.beg);// seekg permet de bouger le curseur et beg le met au début du fichier

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
            "\n1- Donnée à une Ligne"
            "\n2- Tableau de donnée à une Ligne\n";
        cin >> _entry;

        if (_entry == 1)
        {
            string _dataToAdd;
            cout << "Quelle donnée voulez vous ajouter ?\n";
            cin >> _dataToAdd;
            const int _dataToAddLenght = sizeof(_dataToAdd) / sizeof(string);

            u_int _line;
            cout << "Quelle ligne voulez vous ajouter la donnée ?\n";
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
    // _stream gère un fichier 
    //
    //if (_writeStream.is_open())
    //{
    //    cout << "bonjour !\n"; // si le fichier est ouvert alors on affiche bonjour
    //}
    //
    //// toujours testé si c valid
    //if (_writeStream)
    //{
    //    // Ecrire dans le fichier
    //    _writeStream << "\nmargueritte\n"; // stream peut écrire dans le fichier
    //    string _string;
    //    // _writeStream >> _string; ne peux pas récupérer seulement sortant 
    //    _readStream >> _string;
    //
    //    /* 
    //        out
    //        si il n'y pas de fichier il va le créer automatiquement
    //        si il y a un fichier il écrase ce qu'il y a dedans et remplace
    //    */
    //
    //    /*
    //        app (append)
    //        si il n'y pas de fichier il va le créer automatiquement
    //        si il y a un fichier il écrit à la fin du fichier
    //    */
    //
    //    /*
    //        in
    //        si il n'y pas de fichier il ne va pas le créer automatiquement il va juste la lire
    //    */
    //}
    //else
    //{
    //    cerr << "ERREUR => Aucun fichier n'as été trouvé à l'adresse : \'" + _fullPath + "\' !\n";
    //    // cerr console error => s'affiche aussi dans les fichiers de log
    //}


    /*
        depuis la racine du projet => .sln (parfois depuis le .exe)

        reègle toujours tester

    */


    delete _stream;
}
