#ifndef PRIMALITYTEST_H
#define PRIMALITYTEST_H
#include <NTL/ZZ.h>
using namespace NTL;

class PrimalityTest
{
public:
    PrimalityTest();
    ZZ module(ZZ,ZZ);
    ZZ mulmod(ZZ,ZZ,ZZ);
    ZZ modulo(ZZ,ZZ,ZZ);
    bool Miller(ZZ,int);
};

#endif // PRIMALITYTEST_H
