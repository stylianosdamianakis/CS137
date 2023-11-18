#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* merge(char* s1, char* s2) {
    char *res = malloc(strlen(s1) + strlen(s2) + 1);
    int s1len = 1;
    int s2len = 1;

    //find the number of words in each list
    for (int i = 0; i < strlen(s1); i++) {
        if (s1[i] == ' ') s1len++;
    }
    for (int i = 0; i < strlen(s2); i++) {
        if (s2[i] == ' ') {
            s2len++;
        }
    }

    //update res in the correct order
    bool db = true;
    int resIndex = 0;
    int s1used = 0;
    int s1index = 0;
    int s2used = 0;
    int s2index = 0;
    for (int i = 0; i < s1len+s2len; i++) {

        //checking which array to take the next word from
        if (db) {

            //if more words exist in the first array
            if (s1len > s1used) {

                //loop through the remaining array
                for (;s1index < strlen(s1); s1index++) {

                    //if at the end of a word record a space and stop
                    if (s1[s1index] == ' ') {
                        res[resIndex] = ' ';
                        resIndex++;
                        s1index++;
                        break;
                    }

                    res[resIndex] = s1[s1index];
                    resIndex++;
                }

                //on the last word of s1, if not at the very end of the phrase record a space
                if (s1index == strlen(s1) && resIndex+1 < strlen(s1) + strlen(s2)) {
                    res[resIndex] = ' ';
                    resIndex++;
                }

                s1used++;

            } else {
                i -= 1;
            }

            db = false;

        } else {

            //if more words exist in the second array
            if (s2len > s2used) {

                //loop through the remaining array
                for (;s2index < strlen(s2); s2index++) {

                    //if at the end of a word record a space and stop
                    if (s2[s2index] == ' ') {
                        res[resIndex] = ' ';
                        resIndex++;
                        s2index++;
                        break;
                    }

                    res[resIndex] = s2[s2index];
                    resIndex++;
                }

                //on the last word of s2, if not at the very end of the phrase record a space
                if (s2index == strlen(s2) && resIndex+1 < strlen(s1) + strlen(s2)) {
                    res[resIndex] = ' ';
                    resIndex++;
                }

                s2used++;

            } else {
                i -= 1;
            }

            db = true;
        }

    }

    res[resIndex] = '\0';
    return res;
}

/*int main(void){

    char s1[] = "The brown jumps the dog";
    char s2[] = "quick fox over lazy";
    char *s = merge(s1, s2);
    assert(!strcmp(s, "The quick brown fox jumps over the lazy dog"));
    free(s);

    char s3[] = "the brown";
    char s4[] = "quick fox is sleeping today";
    s = merge(s3,s4);
    assert(!strcmp(s, "the quick brown fox is sleeping today"));
    free(s);

    char* s5 = "happy to you";
    char* s6 = "birthday";
    s = merge(s5,s6);
    assert(!strcmp(s, "happy birthday to you"));
    free(s);

    return 0;
}*/
