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

char* morse_to_fr(std::vector<const char *> morse) {
    std::vector<std::vector<const char *> > morse_in_words = separate_morse(morse);
    std::vector<char[]> resultat;  
    for (int i=0; i<morse_in_words.size(); i++) {

    }
    
}

char* fr_to_morse(char* fr) {
    return "";
}