#ifndef GAMAL_H
#define GAMAL_H
#include <randomgenerator.h>
#include <primalitytest.h>
//#include <bitvector.h>
#include <NTL/ZZ.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace NTL;
using namespace std;
class gamal
{
public:
    gamal(int );
    void encrypt(ZZ);
    void decrypt();
    ZZ RaizPrimitiva();
    ZZ phiEuler(ZZ);
    ZZ inverse(ZZ,ZZ);
    ZZ module(ZZ,ZZ);
    ZZ expModule(ZZ,ZZ,ZZ);
    //atributos publicos
    ZZ raiz_primitiva;
    ZZ public_key_B;
    ZZ p;

private:
    ZZ N1,N2;//los dos mensajes que seran enviados
    ZZ ni;
    ZZ private_key;
    int size;
    string alfabeto="abcdefghijklmnopqrstuvwxyz#";

};

#endif // GAMAL_H
