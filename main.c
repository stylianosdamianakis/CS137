#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "a7/semidrome.c"

int main(void){
    assert(is_semidrome("popeye"));
    assert(is_semidrome("racecar"));
    assert(!is_semidrome("aab"));
    assert(!is_semidrome(""));
    return 0;
}
