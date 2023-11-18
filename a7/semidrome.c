#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome (const char *s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

bool semidrome_help (char *s, int start) {

    //if at the end of the string return true
    if (start == strlen(s)) return true;

    //loop through the array to try all combinations
    for (int i = start+1; i < strlen(s); i++) {

        //if the smaller string is a palindrome, then check if the rest of the string is
        if (is_palindrome(s,start,i) && semidrome_help(s, i+1)) return true;
    }

    return false;
}

bool is_semidrome (char *s) {
    if (strlen(s) == 0) return false;
    return semidrome_help(s, 0);
}


/*int main(void){

    printf("%d\n", is_semidrome("aaababbbabaaabacceessssracecar"));
    assert(is_semidrome("popeye"));
    assert(is_semidrome("racecar"));
    assert(!is_semidrome("aab"));
    assert(!is_semidrome(""));

    return 0;
}*/
