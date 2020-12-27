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

morse_code::morse_code(/* args */)
{
}

morse_code::~morse_code()
{
}

bool separation(std::vector vecteur, int rang) {
    return (vecteur[rang] == '.')&&(vecteur[rang+1] == '.')&&(vecteur[rang+2] == '.');
}

bool separation_word(std::vector vecteur, int rang) {
    return (vecteur[rang] == '.')&&(vecteur[rang+1] == '.')&&(vecteur[rang+2] == '.')&&(vecteur[rang+3] == '.')&&(vecteur[rang+4] == '.')&&(vecteur[rang+5] == '.')&&(vecteur[rang+6]=='.');
}

std::vector separate_words(std::vector morse) {
    std::vector<std::vector<char> > result ;
    std::vector<char> bis ;
    for (int i=0 ; i<morse.size()-6; i++) { // -6 pour éviter les problèmes à la fin du vecteur
        if (separation_word(morse, i)) {
            result.push_back(bis);
            bis = {};
        }
        else {
            bis.push_back(morse[i]);
        }
    }
    return result;
}

std::vector separate_morse(std::vector morse) {
    std::vector<std::vector<char> > result ;
    std::vector<char> bis ;
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

char* morse_to_fr(std::vector morse) {
    morse_in_words = separate_morse(morse);
    //for mot in morse_in_words
    // décoder le mot 
}

char* fr_to_morse(char* fr) {
    return "";
}