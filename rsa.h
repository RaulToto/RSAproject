#ifndef RSA_H
#define RSA_H
#include "randomgeneration.h"
#include "primalitytest.h"
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;
class RSA
{
public:
    RSA();
    void encrypt();
    void decrypt();
};

#endif // RSA_H
