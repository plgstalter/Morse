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
bool separation(std::vector<char> vecteur, int rang) {
    return (vecteur[rang]=='.')&&(vecteur[rang+1]=='.')&&(vecteur[rang+2]=='.');
}

bool separation_word(std::vector<char> vecteur, int rang) {
    return (vecteur[rang]=='.')&&(vecteur[rang+1]=='.')&&(vecteur[rang+2]=='.')&&(vecteur[rang+3]=='.')&&(vecteur[rang+4]=='.')&&(vecteur[rang+5]=='.')&&(vecteur[rang+6]=='.');
}

std::vector<std::vector<char> > separate_words(std::vector<char> morse) {
    std::vector<std::vector<char> > result ;
    std::vector<char> bis ;
    int j=0;
    while (j<morse.size()-6) { // -6 pour éviter les problèmes à la fin du vecteur
        if (separation_word(morse, j)) {
            result.push_back(bis);
            bis.resize(0);
            j = j+7;
        }
        else {
            bis.push_back(morse[j]);
            j++;
        }
    }
    return result;
}

std::vector<const char *>  separate_morse(std::vector<char> morse) {
    std::vector<const char *> result ;
    std::vector<char> bis ;
    int j=0;
    int l=0;
    while (j<morse.size()-2) { // -2 pour éviter les problèmes à la fin du vecteur
        if (separation_word(morse, j)) {
            const char * pointeur_bis = &bis[l-1];
            result.push_back(pointeur_bis);
            bis.resize(0);
            l=0;
            j = j+3;
        }
        else {
            if (l>0) {
                bis.push_back(bis[l]+morse[j]);
            }
            else {
                bis.push_back(morse[j]);
            }
            l++;
            j++;
        }
    }
    return result;
}

std::vector<char> morse_to_fr(std::vector<char> morse) {
    std::vector<std::vector<char> > morse_in_words = separate_words(morse);
    std::vector<char> resultat;
    std::map<char, const char *> alpham = morse_alphabet();
    for (int i=0; i<morse_in_words.size(); i++) {
        std::vector<const char *> word = separate_morse(morse_in_words[i]);
        int n = word.size();
        for (int j=0; j<n; j++) {
            std::map<char, const char *>::iterator it;
            for (it=alpham.begin(); it!=alpham.end(); it++) {
                const char * test = it->second;
                const char * test_ = word[j];
                if (strcmp(test, test_)==0) {
                    resultat.push_back(it->first);
                    break;
                }
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
    //on décode
    std::vector<char> decode = morse_to_fr(a_coder);
    for (int i=0; i<decode.size(); i++) {
        std::cout << decode[i];
    }
    std::cout << " " << std::endl;
    return 0;
}