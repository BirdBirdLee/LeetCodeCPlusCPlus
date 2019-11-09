//
// author: BirdBirdLee
// create:  2019/11/09 21:15
// description:
//

#include "P0058.h"

string P0058::generate() {
    return "This is a sentence ";
}

int P0058::lengthOfLastWord(string s) {
    int s_length = s.size();
    int word_length = 0;
    int i;
    for (i = s_length - 1; i >=0 ; --i) {
        if (s[i] != ' '){
            break;
        }
    }
    for (; i >= 0 ; --i) {
        if (s[i] == ' '){
            break;
        }
        ++word_length;
    }
    return word_length;
}


void P0058::run() {
    int word_length = lengthOfLastWord(generate());
    cout<<"length of lastword:"<<word_length<<endl;
}
