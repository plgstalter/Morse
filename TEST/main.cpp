// Modules et librairies nécessaires
#include <iostream>
#include <vector>
#include <string>

// Fichiers sources annexes
#include "include/morse_fr.h"
#include "include/audio_txt.h"

int main(int argc, char const *argv[])
{
    if (argc==1) {
        std::cerr << "veuillez renseigner code/decode" << std::endl;
        return 0;
    }
    std::cout << "Entrez votre texte" << std::endl;
    std::string entree;
    std::getline(std::cin, entree);
    if (strcmp(argv[1], "code")==0) {
        std::cout << "Sous quel nom enregistrer le fichier ?" << std::endl;
        std::string name;
        std::getline(std::cin, name);
        const char * pname = name.c_str();
        std::string morse = code(entree);
        create_wave_file(morse, pname);
        std::cout << "Votre fichier morse en .wav est enregistré : " << pname << std::endl;
    }
    else if (strcmp(argv[1], "decode")==0) {
        std::string decodee = decode(entree);
        std::cout << decodee << std::endl;
    }
    return 0;
}