# RSAproject
Para poder compilar este proyecto se nesecita la libreria NTL;
instalar en ubuntu
# sudo apt-get install libntl-dev
El entorno de desarrollo Qt creator(opcional) si en en el caso de que la tuvieras solo abres el #user.pro
# Ejecucion de RSA
tenemos el rsa al que le puse que encripte la palabra THE#RSA#ALGORTIHM 
el cual  sera primero convertido a numero es decir que se obtendran  las posiciones de cada letra y se añadira un vector
en este caso el rsa se crea de 1024 bits luego se utilizan funciones para agrupar en bloques  y por ultimo ya habiendo encriptado con la clave publica pasamos a desincriptar con la clave privada y nos muestra el mismo mensaje lo cual quiere decir que el algrtimo funciono 
![alt text](https://github.com/RaulToto/RSAproject/blob/master/DOS.png)
# Ejecucion de Ghamal 
primero se crea el ghamal de 1024 bits  este algoritmo nos pide un numero y este numero sera el mensaje que queramos enviar , luego encriptamos y nos dara como resultado dos Numeros que nos serviran para desencriptar al utilizarlos nos muestra el mismo mensaje que intruducimos por teclado entonces ese es nuestro mensaje desincriptado 
![alt text](https://github.com/RaulToto/RSAproject/blob/master/UNO.png)
