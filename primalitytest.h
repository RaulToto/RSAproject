#ifndef PRIMALITYTEST_H
#define PRIMALITYTEST_H


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
