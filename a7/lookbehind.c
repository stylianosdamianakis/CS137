#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

bool compareStrings(const char* word, int index, const char* compString) {
    for (int i = index; i < index+strlen(compString); i++) {
        if (word[i] != compString[i-index]) return false;
    }

    return true;
}

void removeAtIndex(char* word, int index, unsigned long long charNum) {
    for (int j = 0; j < charNum; j++) {
        for (int i = index; i < strlen(word); i++) {
            word[i] = word[i + 1];
        }
    }
}

void lookBehind(const char* check, const char* s_sub, char* word) {

    char* newWord = word;

    //loop through every character in word
    for (int i = 0; i < strlen(word); i++) {

        //if the current character is the same as the check and the upcoming characters are the same as s_sub
        if (compareStrings(newWord, i, check) &&
        compareStrings(newWord, i+strlen(check), s_sub)) {

            //remove them and keep the same index
            removeAtIndex(newWord, i+strlen(check), strlen(s_sub));
            i--;
        }
    }

    newWord[strlen(word)] = '\0';
}


/*int main(void){

    char word[] = "foo bar loop hoop";
    lookBehind("l", "oo", word);
    assert(0==strcmp("foo bar lp hoop", word));
    lookBehind("o", "o", word);
    assert(0==strcmp("fo bar lp hop", word));

    char word3[] = "CS137137";
    lookBehind("CS", "137", word3);
    assert(0==strcmp("CS", word3));
    char word3b[] = "CS137 137" ;
    lookBehind("CS", "137", word3b);
    assert(0==strcmp("CS 137", word3b));

    char word4[] = "111111" ;
    lookBehind("1", "1", word4);
    assert(0==strcmp("1", word4));

    char word5[] = "wow" ;
    lookBehind("", "w", word5);
    assert(0==strcmp("o", word5));

    return 0;
}*/

