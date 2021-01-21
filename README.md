# Morse - C++ project for school

## Récapitulatif

Pas besoin de `Makefile` :)

Simplement, faire `g++ -o morse main.cpp src/*.cpp` puis `./morse ...`

On peut 

- [x] entrer du texte et recevoir un fichier `.wav`

  Pour cela, 
  
  - faire `./morse code`

  - Renseigner la chaine à coder

  - Renseigner le nom du fichier `wav` qu'on veut récupérer

  Le tour est joué !

- [x] entrer un texte "morse" et recevoir la traduction

  faire `./morse decode` puis entrer la chaîne à décoder

- [ ] rentrer un `.wav` et le décoder

  ... pas encore réussi à faire ça :/


## A faire

- [ ] décoder du `.wav` et sortir un `std::string`

- [ ] faire un `makefile` fonctionnel

## Remarques

Pour la partie création de fichier `.wav`, je me suis librement et largement inspiré d'un code trouvé sur internet (source : http://www.cplusplus.com/forum/beginner/166954/).
