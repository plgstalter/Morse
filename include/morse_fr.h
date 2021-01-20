#pragma once
std::vector<const char *> morse_alphabet();

bool separation(std::string vecteur, int rang);
bool separation_word(std::string vecteur, int rang);
std::vector<std::string> separate_words(std::string morse);
std::string decode(std::string morse);
std::vector<const char *> fr_to_morse(std::string fr);