#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

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
bool separation(std::string vecteur, int rang) {
    if (rang>=vecteur.size()-2) {
        return false;
    }
    return (vecteur[rang]=='.')&&(vecteur[rang+1]=='.')&&(vecteur[rang+2]=='.');
}

bool separation_word(std::string vecteur, int rang) {
    if (rang>=vecteur.size()-6) {
        return false;
    }
    return (vecteur[rang]=='.')&&(vecteur[rang+1]=='.')&&(vecteur[rang+2]=='.')&&(vecteur[rang+3]=='.')&&(vecteur[rang+4]=='.')&&(vecteur[rang+5]=='.')&&(vecteur[rang+6]=='.');
}

std::vector<char> decode(std::string morse) {
    int i=0;
    int n=morse.size();
    std::vector<char> resultat;
    std::string temp;
    std::map<char, const char *> alpham = morse_alphabet();
    std::cout << "n=" << n << std::endl;
    while (i<n) {
        std::cout << "i=" << i <<std::endl;
        if (separation_word(morse, i)) {
            resultat.push_back(' ');
            i = i + 7;
            std::cout << "i=" << i <<std::endl;
        }
        else {
            for (int j=i; j<n; j++) {
                std::cout << "i=" << i <<std::endl;
                if (separation(morse, j)) {
                    i = i + 3;
                    break;
                }
                else {
                    temp.push_back(morse[j]);
                    i++;
                }
            }
            std::map<char, const char *>::iterator it;
            const char * test = temp.c_str();
            for (it=alpham.begin(); it!=alpham.end(); it++) {
                if (strcmp(it->second, test)==0) {
                    resultat.push_back(it->first);
                    break;
                }
            }
            std::cout << "i=" << i <<std::endl;
            temp.resize(0);
        }
    }
    return resultat;
}


// De texte à morse
std::vector<const char *> fr_to_morse(std::string fr) {
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
    // std::cout << "Entrez votre texte à coder" << std::endl;
    // // on récupère le texte à coder
    // std::vector<char> a_coder;
    // char index[100];
    // std::cin.get(index, 100);
    // for (int i=0; i<98; i++) {
    //     if (index[i]==index[i+1] && index[i+1]==index[i+2]) {
    //         break;
    //     }
    //     a_coder.push_back(index[i]);
    // }
    // //on encode en morse
    // std::vector<const char *> morse_code = fr_to_morse(a_coder);
    // for (int i=0; i<morse_code.size(); i++) {
    //     std::cout << morse_code[i];
    // }
    // std::cout << " " << std::endl;




    std::cout << "Entrez votre texte à décoder" << std::endl;
    std::string entree;
    std::getline(std::cin, entree);
    //on décode
    std::vector<char> decodee = decode(entree);
    for (int i=0; i<decodee.size(); i++) {
        std::cout << decodee[i];
    }
    std::cout << " " << std::endl;
    std::cout << decodee.size() << std::endl;
    return 0;
}