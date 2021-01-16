// Modules et librairies nécessaires
#include <iostream>
#include <vector>
#include <algorithm>

// Fichiers sources annexes
#include "include/morse_fr.h"
#include "include/audio_txt.h"

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cerr << "Veuillez renseigner ce que vous voulez faire : 'code' pour passer de français à morse, 'decode' pour le contraire" << std::endl;
    }
    else if (strcmp(argv[1],"code") == 0)
    {
        std::cout << "Entrez votre texte à coder" << std::endl;
        // on récupère le texte à coder
        std::vector<const char *> a_coder;
        char index[100];
        std::cin.get(index, 100);
        for (int i=0; i<98; i++) {
            if (index[i]==index[i+1] && index[i+1]==index[i+2]) {
                break;
            }
            a_coder.push_back(&index[i]);
        }
        //on encode en morse
        std::vector<const char *> morse_code = fr_to_morse(a_coder);
        std::cout << "c'est bon ça a marché" << std::endl;
        for (int i=0; i<morse_code.size(); i++) {
            std::cout << morse_code[i];
        }
        std::cout << " " << std::endl;
        // on génère le fichier audio
    }
    else if (strcmp(argv[1],"decode") == 0)
    {
        std::cout << "Entrez votre fichier audio à décoder" << std::endl;
        // on récupère le fichier .wav
        // on le transforme en morse
        // on décode
        // on génère le fichier texte
    }
    else
    {
        std::cerr << "Veuillez renseigner ce que vous voulez faire : 'code' pour passer de français à morse, 'decode' pour le contraire" << std::endl;
    }
    return 0;
}
