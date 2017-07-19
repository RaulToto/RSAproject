#include <iostream>
#include <NTL/ZZ.h>
#include "primalitytest.h"
#include "randomgenerator.h"
#include "rsa.h"
#include "gamal.h"
using namespace NTL;
using namespace std;
int main()
{

    cout << "  ///////////////////" << endl;
    cout << " /////////RSA///////" << endl;
    cout <<"///////////////////"  << endl;
    RSA rsa(1024);
    string message="the#rsa#algorithm";
    cout << "EL CIFRADO DE LA PALABRA  " << message << " ES :"<< endl;
    cout << rsa.encrypt(message) << endl;
    cout << "DESCRIFRANDO " ;
    rsa.decrypt();
    /*cout << "ELGAMAL" << endl;
    gamal gam(1024);
    ZZ message;
    cout << "INGRESE UN NUMERO PARA ENCRIPTAR" << endl;
    cin >> message;
    gam.encrypt(message);
    cout << endl;
    cout << "DESENCRIPTANDO.." << endl;
    cout << "RESULTADO-->";
    gam.decrypt();*/
}
