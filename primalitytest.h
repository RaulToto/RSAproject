#ifndef PRIMALITYTEST_H
#define PRIMALITYTEST_H
#include <NTL/ZZ.h>
#include <iostream>
using namespace NTL;
using namespace std;

class PrimalityTest
{
public:
    PrimalityTest();
    ZZ module(ZZ,ZZ);
    ZZ power(ZZ , ZZ ,ZZ);
    bool miillerTest(ZZ,ZZ);
    bool isPrime(ZZ,ZZ);
    ~PrimalityTest();
};

#endif // PRIMALITYTEST_H
