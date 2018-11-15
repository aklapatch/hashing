
#include "Hash.hpp"
#include "TimeInterval.h"
#include<fstream>
#include <iostream>
// get words to load into hash
std::list<std::string> getWords(std::string f_name){
    
    std::list<std::string> ret;
    
    std::ifstream infile;

	infile.open(f_name.data(), std::ios::in);

    std::string tmp;

    if(infile.is_open()){

        while( getline(infile, tmp)){
            ret.push_back(tmp);
        }

    } else {
        std::cerr << " was not able to open file\n";
    }

    return ret;
}

int main(){

    std::list<std::string> words = getWords("Dictionary.txt");

    // make a vector to load hash
    std::vector<std::string> word_vec(words.size());

    for(int i =0; !words.empty(); ++i){
        word_vec[i] = words.front();
        words.pop_front();
    }

    Hash test(26);

    test.load(word_vec);

    // get user input
    std::string usr_in;
    std::list<std::string> matches;

    std::cout << "Type the phrase to search for and press enter.\n If you wnat to quit type ...\n\n";

    // make interval object
    TimeInterval interval;

    while (true){
        std::cin >> usr_in;
        if(usr_in == "..."){
            break;
        }

        try {

            interval.start();

            test.getMatches(usr_in, matches);
            // output all results

            interval.stop();

            if(matches.empty()){
                std::cout << "False\n";
            
            } else {

                std::cout << "True\n\n";

                while(!matches.empty()){
                    std::cout << matches.front() << "\n\n";
                    matches.pop_front();
                }

                std::cout << interval.GetInterval() << " micro-sec\n";
            }

            std::cout << "Input another word\n";

        } catch(...){
            std::cout << "False\n\n";
        }

    }
    return 0;
}
