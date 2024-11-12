#pragma once

#include <string>
#include <iostream> // FLUX Console
#include <fstream> // FLUX FICHIER

using namespace std;

#define DISPLAY_ERROR(_text, _endl)	cerr << _text; \
								    if (_endl) cerr << endl;


/// <summary>
/// Donne le chemin d'accès d'un fichier
/// </summary>
/// <param name="_folderPath"></param>
/// <param name="_filePath"></param>
/// <param name="_fileExtension"></param>
/// <returns></returns>
static string ComputePath(const string& _folderPath, const string& _filePath, const string& _fileExtension)
{
    return _folderPath + _filePath + "." + _fileExtension;
}
/// <summary>
/// Affiche un nombre _rowsCount de ligne contenus dans un fichier à partir du charactère _startIndex 
/// </summary>
/// <param name="_filePath"></param>
/// <param name="_rowsCount"></param>
/// <param name="_startIndex"></param>
static void DisplayByRow(const string& _filePath, const int _rowsCount, const int _startIndex)
{
    // Afficher un nombre n de ligne à partir d'un index
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
/// <summary>
/// Affiche un nombre _charCount de charactère contenus dans un fichier à partir du charactère _startIndex 
/// </summary>
/// <param name="_filePath"></param>
/// <param name="_charCount"></param>
/// <param name="_startIndex"></param>
static void DisplayByChar(const string& _filePath, const int _charCount, const int _startIndex)
{
    // Afficher un nombre n de charactère à partir d'un index
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
/// <summary>
/// Retourne la taille d'un fichier donné
/// </summary>
/// <param name="_filePath"></param>
/// <returns></returns>
static int ComputeLengthOfFile(const string& _filePath)
{
    ifstream _stream = ifstream(_filePath);

    _stream.seekg(0, _stream.end);
    return _stream.tellg();
}
/// <summary>
/// Retourne le buffer dans un fichier à l'index _startIndex
/// </summary>
/// <param name="_filePath"></param>
/// <param name="_startIndex"></param>
/// <returns></returns>
static string ComputeBufferAtIndex(const string& _filePath, const int _startIndex)
{
    ifstream _stream = ifstream(_filePath);

    // On définit la taille du fichier restant
    _stream.seekg(_startIndex, _stream.end);
    const int _length = _stream.tellg();
    _stream.seekg(0, _stream.beg);

    // On créer un tableau
    char* _buffer = new char[_length];
    _stream.read(_buffer, _length);
    string _text = _buffer;

    delete[] _buffer;

    /* Version Schlag */
    /*string _text;
    char _char;

    while (_stream.get(_char))
    {
        _text += _char;
    }*/

    return _text;
}
/// <summary>
/// Positionne le curseur d'un fichier donné à une ligne _rowToMove
/// </summary>
/// <param name="_filePath"></param>
/// <param name="_rowToMove"></param>
/// <returns></returns>
static int SetCursorPositionByRow(const string& _filePath, const int _rowToMove)
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
/// <summary>
/// Ajoute une valeur au fichier à la ligne _rowToAdd
/// </summary>
/// <param name="_filePath"></param>
/// <param name="_value"></param>
/// <param name="_rowToAdd"></param>
static void AddValue(const string& _filePath, const string& _value, const int _rowToAdd, ios_base::openmode _openMode = ios_base::ate)
{
    ofstream _stream = ofstream(_filePath, _openMode);

    /*_stream << "Bonjour !" << endl;
    _stream << "Je m'appelle" << endl;
    _stream << "Thomas !" << endl;*/

    const int _startIndex = SetCursorPositionByRow(_filePath, _rowToAdd);
    _stream.seekp(_startIndex);

    _stream << _value;
}
/// <summary>
/// Retire les données d'un fichier à la ligne _rowToAdd
/// </summary>
/// <param name="_filePath"></param>
/// <param name="_rowToRemove"></param>
static void RemoveLine(const string& _filePath, const int _rowToRemove)
{
    ofstream _stream = ofstream(_filePath, ios_base::out);

    /*_stream << "Bonjour !" << endl;
    _stream << "Je m'appelle" << endl;
    _stream << "Thomas !" << endl;*/

   

}
