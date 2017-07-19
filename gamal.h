#ifndef GAMAL_H
#define GAMAL_H
#include <rsa.h>
#include <randomgenerator.h>
#include <primalitytest.h>
//#include <bitvector.h>
#include <NTL/ZZ.h>
#include <iostream>
#include <bitset>
using namespace NTL;
using namespace std;
RSA rsa;//pra fines de uso de algunas funciones del rsa
class gamal
{
public:
    gamal(int );
    string encrypt(string);
    void decrypt();
    ZZ RaizPrimitiva();
    ZZ phiEuler(ZZ);
    //atributos publicos
    ZZ raiz_primitiva;
    ZZ public_key_B;
    ZZ p;
private:
    ZZ e1;
    ZZ e2;
    ZZ private_key;
    int size;
    string alfabeto="abcdefghijklmnopqrstuvwxyz#";

};

#endif // GAMAL_H
