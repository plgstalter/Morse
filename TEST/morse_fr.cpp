#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>


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

std::vector<std::string> separate_words(std::string morse) {
    int n = morse.size();
    int i = 0;
    std::string temp;
    std::vector<std::string> resultat;
    while (i<n) {
        if (separation_word(morse, i)) {
            resultat.push_back(temp);
            temp.resize(0);
            i = i + 6;
        }
        else if (i==n-1) {
            temp.push_back(morse[i]);
            resultat.push_back(temp);
        }
        else {
            temp.push_back(morse[i]);
        }
        i++;
    }
    return resultat;
}

std::string decode(std::string morse) {
    std::map<char, const char *> alpham = morse_alphabet();
    std::map<char, const char *>::iterator it;
    std::vector<std::string> words = separate_words(morse);
    std::string resultat, temp;
    int j;
    for (int i=0; i<words.size(); i++) {
        j = 0;
        std::string word = words[i];
        std::cout << word << std::endl;
        temp.resize(0);
        while (j<word.size()) {
            if (separation(word, j)) {
                const char * test = temp.c_str();
                for (it=alpham.begin(); it!=alpham.end(); it++) {
                    if (strcmp(it->second, test)==0) {
                        resultat.push_back(it->first);
                        break;
                    }
                }
                temp.resize(0);
                j = j + 2;
            }
            else if (j==word.size()-1){
                temp.push_back(word[j]);
                const char * test = temp.c_str();
                for (it=alpham.begin(); it!=alpham.end(); it++) {
                    if (strcmp(it->second, test)==0) {
                        resultat.push_back(it->first);
                        break;
                    }
                }
            }
            else {
                temp.push_back(word[j]);
            }
            j++; 
        }
        resultat.push_back(' ');
    }
    return resultat;
}


// De texte à morse
std::string code(std::string fr) {
    std::string resultat;
    std::map<char, const char *> alpham = morse_alphabet();
    int n = fr.size();
    for (int i=0; i<n; i++) {
        if (fr[i] == ' ') {
            resultat += "......."; //espace inter-mots
        }
        else {
            resultat += alpham[fr[i]];
            resultat += "..."; //espace inter-caractères
        } 
    }
    return resultat;
}