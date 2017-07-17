#ifndef RSA_H
#define RSA_H
#include "randomgeneration.h"
#include "primalitytest.h"
#include <vector>
#include <string>
#include <sstream>
#include <NTL/ZZ.h>
#include <algorithm>
using namespace NTL;
using namespace std;
class RSA
{
public:
    RSA(int);
    RSA(ZZ,ZZ);
    ZZ module(ZZ,ZZ);
    string intToString(int);
    int stringToInt(string);
    int size_number(ZZ);
    string encrypt(string );
    string decrypt(string );

private:
    int size;
    ZZ d;//clave privada
    ZZ e;//clave publica
    ZZ N;//n
    ZZ p;//primos p y q
    ZZ q;//primos p y q
    string alfabeto="abcdefghijklmnopqrstuvwxyz#";
};

#endif // RSA_H
