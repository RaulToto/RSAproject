#ifndef RANDOMGENERATION_H
#define RANDOMGENERATION_H
#include<iostream>
#include<NTL/ZZ.h>
#include<time.h>
#include<NTL/ZZ_pX.h>
#define OT unsigned long long

using namespace std;
using namespace NTL;

class RandomGeneration
{
public:
    RandomGeneration();
    ZZ module(ZZ,ZZ);
    OT mulmod(OT,OT,OT);
    OT modulo(OT , OT , OT );
    ZZ BBS(int);
};

#endif // RANDOMGENERATION_H
