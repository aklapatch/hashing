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

bool compare(std::string in, std::string in2){
    size_t lowest = (in.length() < in2.length()) ? in.length(): in2.length();
    
    for (size_t i =0; i < lowest; ++i){
        if(in[i] != in2[i]){
            return false;
        }
    }

    return true;
}

class Hash {
    private:
        std::vector<std::deque<std::string> > table;

    public:
        Hash();
    
        Hash(int size);

        ~Hash();

        void load(std::vector<std::string> words);

       void getMatches(std::string word, std::list<std::string>& input);
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

void Hash::getMatches(std::string word, std::list<std::string>& input){
    int dex = hash(word[0]);
    // iterate and store all matches in list

    input.resize(0);

    for(int i =0; i < table[dex].size(); ++i){
        if(compare(word, table[dex][i])){
            input.push_back(table[dex][i]);
        }
    }
}
#endif // HASH_HPP
