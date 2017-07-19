#ifndef RSA_H
#define RSA_H
#include "randomgenerator.h"
#include "primalitytest.h"
#include <vector>
#include <string>
#include <sstream>
#include <NTL/ZZ.h>
#include <algorithm>
#include <fstream>
using namespace NTL;
using namespace std;
class RSA
{
public:
    RSA();
    RSA(int);
    //other functions
    ZZ binary_gcd(ZZ,ZZ);
    ZZ inverse(ZZ,ZZ);//for e^-1modn
    ZZ module(ZZ,ZZ);
    string stringConvertInBlocks(vector<string> &,int);
    vector<ZZ> numberConvertInBlocks(string &,int);
    string intToString(ZZ);
    ZZ stringToInt(string);
    int size_number(ZZ);
    ZZ expModule(ZZ,ZZ,ZZ);
    //main functions
    string encrypt(string );
    void decrypt();


private:
    int size;
    ZZ d;//clave privada
    ZZ e;//clave publica
    ZZ N;//n
    ZZ p;//primos p y q
    ZZ q;//primos p y q
    ZZ phi_n;
    string encriptado;
    string alfabeto="abcdefghijklmnopqrstuvwxyz#";
};

#endif // RSA_H
