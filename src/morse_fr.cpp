#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// Ce programme contiendra de quoi faire la traduction morse/fr et fr/morse entre deux textes


// Alphabet Morse
std::map<char, const char *> morse_alphabet(){
    std::map<char, const char *> alphabet_morse;

    alphabet_morse['a'] = "=.===";
    alphabet_morse['b'] = "===.=.=.=";
    alphabet_morse['c'] = "===.=.===.=";
    alphabet_morse['d'] = "===.=.=";
    alphabet_morse['e'] = "=";
    alphabet_morse['f'] = "=.=.===.=";
    alphabet_morse['g'] = "===.===.=";
    alphabet_morse['h'] = "=.=.=.=";
    alphabet_morse['i'] = "=.=";
    alphabet_morse['j'] = "=.===.===.===";
    alphabet_morse['k'] = "===.=.===";
    alphabet_morse['l'] = "=.===.=.=";
    alphabet_morse['m'] = "===.===";
    alphabet_morse['n'] = "===.=";
    alphabet_morse['o'] = "===.===.===";
    alphabet_morse['p'] = "=.===.===.=";
    alphabet_morse['q'] = "===.===.=.===";
    alphabet_morse['r'] = "=.===.=";
    alphabet_morse['s'] = "=.=.=";
    alphabet_morse['t'] = "===";
    alphabet_morse['u'] = "=.=.===";
    alphabet_morse['v'] = "=.=.=.===";
    alphabet_morse['w'] = "=.===.===";
    alphabet_morse['x'] = "===.=.=.===";
    alphabet_morse['y'] = "===.=.===.===";
    alphabet_morse['z'] = "===.===.=.=";

    return alphabet_morse;
}


// De Morse à texte
bool separation(std::vector<const char*> vecteur, int rang) {
    return (strcmp(vecteur[rang], "."))&&(strcmp(vecteur[rang+1], "."))&&(strcmp(vecteur[rang+2], "."));
}

bool separation_word(std::vector<const char*> vecteur, int rang) {
    return (strcmp(vecteur[rang], "."))&&(strcmp(vecteur[rang+1], "."))&&(strcmp(vecteur[rang+2], "."))&&(strcmp(vecteur[rang+3], "."))&&(strcmp(vecteur[rang+4], "."))&&(strcmp(vecteur[rang+5], "."))&&(strcmp(vecteur[rang+6], "."));
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
            bis.resize(0);
        }
        else {
            bis.push_back(morse[i]);
        }
    }
    return result;
}

std::vector<char> morse_to_fr(std::vector<const char *> morse) {
    std::vector<std::vector<const char *> > morse_in_words = separate_words(morse);
    std::vector<char> resultat;
    std::map<char, const char *> alpham = morse_alphabet();
    for (int i=0; i<morse_in_words.size(); i++) {
        std::vector<std::vector<const char *> > word = separate_morse(morse_in_words[i]);
        int n = word.size();
        for (int j=0; j<n; j++) {
            //std::vector<const char *>::iterator res = std::find(alpham.begin(), alpham.end(), word[j]);
            //int index = std::distance(alpham.begin(), res);
            std::map<char, const char *>::iterator it;
            for (it=alpham.begin(); it!=alpham.end(); it++) {
                if (strcmp(it->second, word[j])==0) {
                    resultat.push_back(it->first);
                    break;
                }
        }
        resultat.push_back(' ');
    }
    return resultat;
}


// De texte à morse
std::vector<const char *> fr_to_morse(std::vector<char> fr) {
    std::vector<const char *> resultat;
    std::map<char, const char *> alpham = morse_alphabet();
    int n = fr.size();
    for (int i=0; i<n; i++) {
        if (fr[i] == ' ') {
            resultat.push_back("......."); //espace inter-mots
        }
        else {
            resultat.push_back(alpham[fr[i]]);
            resultat.push_back("..."); //espace inter-caractères
        } 
    }
    return resultat;
}

// Tests
int main(int argc, char const *argv[])
{
    std::cout << "Entrez votre texte à coder" << std::endl;
    // on récupère le texte à coder
    std::vector<char> a_coder;
    char index[100];
    std::cin.get(index, 100);
    for (int i=0; i<98; i++) {
        if (index[i]==index[i+1] && index[i+1]==index[i+2]) {
            break;
        }
        a_coder.push_back(index[i]);
    }
    //on encode en morse
    std::vector<const char *> morse_code = fr_to_morse(a_coder);
    for (int i=0; i<morse_code.size(); i++) {
        std::cout << morse_code[i];
    }
    std::cout << " " << std::endl;
    return 0;
}