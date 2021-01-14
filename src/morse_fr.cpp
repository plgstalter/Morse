#include <iostream>
#include <vector>
#include <algorithm>

// Ce programme contiendra de quoi faire la traduction morse/fr et fr/morse entre deux textes

class morse_code
{
private:
    /* data */
public:
    morse_code(/* args */);
    ~morse_code();
};

// Alphabet Morse

std::vector<const char *> morse_alphabet(){
    std::vector<const char *> alphabet_morse(26, "");

    alphabet_morse[0] = "=.===";
    alphabet_morse[1] = "===.=.=.=";
    alphabet_morse[2] = "===.=.===.=";
    alphabet_morse[3] = "===.=.=";
    alphabet_morse[4] = "=";
    alphabet_morse[5] = "=.=.===.=";
    alphabet_morse[6] = "===.===.=";
    alphabet_morse[7] = "=.=.=.=";
    alphabet_morse[8] = "=.=";
    alphabet_morse[9] = "=.===.===.===";
    alphabet_morse[10] = "===.=.===";
    alphabet_morse[11] = "=.===.=.=";
    alphabet_morse[12] = "===.===";
    alphabet_morse[13] = "===.=";
    alphabet_morse[14] = "===.===.===";
    alphabet_morse[15] = "=.===.===.=";
    alphabet_morse[16] = "===.===.=.===";
    alphabet_morse[17] = "=.===.=";
    alphabet_morse[18] = "=.=.=";
    alphabet_morse[19] = "===";
    alphabet_morse[20] = "=.=.===";
    alphabet_morse[21] = "=.=.=.===";
    alphabet_morse[22] = "=.===.===";
    alphabet_morse[23] = "===.=.=.===";
    alphabet_morse[24] = "===.=.===.===";
    alphabet_morse[25] = "===.===.=.=";

    return alphabet_morse;
}

std::vector<const char *> alphabet(){
    std::vector<const char *> alphabet_morse(26, "");

    alphabet_morse[0] = "a";
    alphabet_morse[1] = "b";
    alphabet_morse[2] = "c";
    alphabet_morse[3] = "d";
    alphabet_morse[4] = "e";
    alphabet_morse[5] = "f";
    alphabet_morse[6] = "g";
    alphabet_morse[7] = "h";
    alphabet_morse[8] = "i";
    alphabet_morse[9] = "j";
    alphabet_morse[10] = "k";
    alphabet_morse[11] = "l";
    alphabet_morse[12] = "m";
    alphabet_morse[13] = "n";
    alphabet_morse[14] = "o";
    alphabet_morse[15] = "p";
    alphabet_morse[16] = "q";
    alphabet_morse[17] = "r";
    alphabet_morse[18] = "s";
    alphabet_morse[19] = "t";
    alphabet_morse[20] = "u";
    alphabet_morse[21] = "v";
    alphabet_morse[22] = "w";
    alphabet_morse[23] = "x";
    alphabet_morse[24] = "y";
    alphabet_morse[25] = "z";

    return alphabet_morse;
}

bool separation(std::vector<const char*> vecteur, int rang) {
    return (vecteur[rang] == ".")&&(vecteur[rang+1] == ".")&&(vecteur[rang+2] == ".");
}

bool separation_word(std::vector<const char*> vecteur, int rang) {
    return (vecteur[rang] == ".")&&(vecteur[rang+1] == ".")&&(vecteur[rang+2] == ".")&&(vecteur[rang+3] == ".")&&(vecteur[rang+4] == ".")&&(vecteur[rang+5] == ".")&&(vecteur[rang+6] == ".");
}

std::vector<std::vector<const char *> > separate_words(std::vector<const char*> morse) {
    std::vector<std::vector<const char *> > result ;
    std::vector<const char *> bis ;
    for (int i=0 ; i<morse.size()-6; i++) { // -6 pour éviter les problèmes à la fin du vecteur
        if (separation_word(morse, i)) {
            result.push_back(bis);
            bis.resize(0);
        }
        else {
            bis.push_back(morse[i]);
        }
    }
    return result;
}

std::vector<std::vector<const char *> >  separate_morse(std::vector<const char *> morse) {
    std::vector<std::vector<const char *> > result ;
    std::vector<const char *> bis ;
    for (int i=0 ; i<morse.size()-2; i++) { // -2 pour éviter les problèmes à la fin du vecteur
        if (separation(morse, i)) {
            result.push_back(bis);
            bis = {};
        }
        else {
            bis.push_back(morse[i]);
        }
    }
    return result;
}

std::vector<const char *> morse_to_fr(std::vector<const char *> morse) {
    std::vector<std::vector<const char *> > morse_in_words = separate_words(morse);
    std::vector<const char *> resultat;  
    std::vector<const char *> alpham = morse_alphabet();
    std::vector<const char *> alpha = alphabet();
    for (int i=0; i<morse_in_words.size(); i++) {
        std::vector<std::vector<const char *> > word = separate_morse(morse_in_words[i]);
        int n = word.size();
        for (int j=0; j<n; j++) {
            std::vector<const char *>::iterator res = std::find(alpham.begin(), alpham.end(), word[j]);
            int index = std::distance(alpham.begin(), res);
            if (index != 26) {
                resultat.push_back(alpha[index]);
            }
            else {
                std::cerr << "bizarre !" << std::endl;
            }
        }
        resultat.push_back(" ");
    }
    return resultat;
}

std::vector<const char *> fr_to_morse(const char* fr) {
    std::vector<const char *> resultat;  
    std::vector<const char *> alpham = morse_alphabet();
    std::vector<const char *> alpha = alphabet();
    int n = sizeof(fr)/sizeof("a");
    for (int i=0; i<n; i++) {
        if (strcmp(fr[i], " ") == 0) {
            resultat.push_back("......."); //espace inter-mots
        }
        else {
            std::vector<const char *>::iterator res = std::find(alpha.begin(), alpha.end(), fr[i]);
            int index = std::distance(alpha.begin(), res);
            if (index != 26) {
                resultat.push_back(alpham[index]);
            }
            else {
                std::cerr << "bizarre !" << std::endl;
            }
            resultat.push_back("..."); //espace inter-caractères
        } 
    }
    return resultat;
}