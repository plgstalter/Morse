// Modules et librairies nécessaires
#include <iostream>
#include <vector>
#include <algorithm>

// Fichiers sources annexes
#include "morse_fr.h"
#include "audio_txt.h"

int main(int argc, char const *argv[])
{
    if (argc < 2) {
        std::cerr << "Veuillez renseigner ce que vous voulez faire : 'code' pour passer de français à morse, 'decode' pour le contraire" << std::endl;
    }
    else if (argv[1] == "code")
    {
        std::cout << "Entrez votre texte à coder" << std::endl;
        // on récupère le texte à coder
        // on le code en morse
        // on génère le fichier audio
    }
    else if (argv[1] == "decode")
    {
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
