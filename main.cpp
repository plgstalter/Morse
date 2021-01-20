// Modules et librairies nécessaires
#include <iostream>
#include <vector>
#include <algorithm>

// Fichiers sources annexes
#include "include/morse_fr.h"
#include "include/audio_txt.h"

int main(int argc, char const *argv[])
{
    std::cout << "Entrez votre texte" << std::endl;
    std::string entree;
    std::getline(std::cin, entree);
    if (strcmp(argv[1], "code")==0) {
        std::vector<const char *> res = fr_to_morse(entree);
        for (int i=0; i<res.size(); i++) {
            std::cout << res[i];
        }
        std::cout << " " << std::endl;
    }
    else if (strcmp(argv[1], "decode")==0) {
        std::string decodee = decode(entree);
        std::cout << decodee << std::endl;
    }
    return 0;
}
