#ifndef HASH_HPP
#define HASH_HPP

#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<ctype.h>
#include<deque>

// hash function, returns ascii values of the lowercase input character
int hash(char input){
    input = tolower(input); // get lowercase and return index
    return int(input) - int('a');
}

// compares to input strings and checks if the content matches
bool compare(std::string in, std::string in2){
    size_t lowest = (in.length() < in2.length()) ? in.length(): in2.length();
    
    for (size_t i =0; i < lowest; ++i){
        if(in[i] != in2[i]){
            return false;
        }
    }

    return true;
}

// class to facilitate hashing
class Hash {
    private:
        std::vector<std::deque<std::string> > table;

    public:
        Hash();
    
        Hash(int size);

        ~Hash();

		// load values into hash
        void load(std::list<std::string> words);

		// set input to be the matches to input word
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

// load words into the hash table
void Hash::load(std::list<std::string> words){
    
    while (!words.empty()) {
        int dex = hash(words.front()[0]);
        table[dex].push_back(words.front());
		words.pop_front();
    }
}

// for all int vector, put first char through hash(x) and put it in that linked
// list if it matches
void Hash::getMatches(std::string word, std::list<std::string>& input){
    int dex = hash(word[0]);
    
	// clear input list
    input.resize(0);

	// store all matches in return list
    for(int i =0; i < table[dex].size(); ++i){
        if(compare(word, table[dex][i])){
            input.push_back(table[dex][i]);
        }
    }
}
#endif // HASH_HPP
