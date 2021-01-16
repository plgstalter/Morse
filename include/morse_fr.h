#pragma once
std::vector<const char *> morse_alphabet();
std::vector<const char *> alphabet();
bool separation(std::vector<const char*> vecteur, int rang);
bool separation_word(std::vector<const char*> vecteur, int rang);
std::vector<std::vector<const char *> > separate_words(std::vector<const char*> morse);
std::vector<std::vector<const char *> >  separate_morse(std::vector<const char *> morse);
std::vector<const char *> morse_to_fr(std::vector<const char *> morse);
std::vector<const char *> fr_to_morse(std::vector<const char *> fr);