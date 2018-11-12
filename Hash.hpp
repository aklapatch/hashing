#ifndef HASH_HPP
#define HASH_HPP

#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<ctype.h>
#include<deque>

int hash(char input){
    input = tolower(input); // get lowercase and return index
    return int(input) - int('a');
}

class Hash {
    private:
        std::vector<std::deque<std::string>> table;

    public:
        Hash();
    
        Hash(int size);

        ~Hash();

        void load(std::vector<std::string> words);

        std::list<std::string> getMatches(std::string word);
};

// set size to 32
Hash::Hash(){
    table.resize(32);
}

// set desired size
Hash::Hash(int size){
    table.resize(size);
}

//does nothing
Hash::~Hash() {}

// assumning 26 array spaces, go to spot matching
// for all int vector, put first char through hash(x) and put it in that linked
// list
void Hash::load(std::vector<std::string> words){
    
    for(int i =0; i < words.size(); ++i){
        int dex = hash(words[i][0]);
        table[dex].push_back(words[i]);
    }
}

std::list<std::string> Hash::getMatches(std::string word){
    int dex = hash(word[0]);
    // iterate and store all matches in list
    std::list<std::string> ret;

    for(int i =0; i < table[dex].size(); ++i){
        if(table[dex][i].find(word, 0) != std::string::npos){
            ret.push_back(table[dex][i]);
        }
    }

    return ret;
}

#endif // HASH_HPP