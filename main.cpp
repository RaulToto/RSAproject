#include <iostream>
#include <NTL/ZZ.h>
#include "primalitytest.h"
#include "randomgeneration.h"
#include "rsa.h"
using namespace NTL;
using namespace std;
int main()
{
    cout << "  ///////////////////" << endl;
    cout << " /////////RSA///////" << endl;
    cout <<"///////////////////"  << endl;
    PrimalityTest primo;
    RandomGeneration random;
    RSA rsa(1024);
    rsa.encrypt("hola");

}
