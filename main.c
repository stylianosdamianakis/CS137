#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
extern int jump_stair_v1();
extern int jump_stair_v2();
extern int jump_stair_v3();


int main() {

    for(int i = 1; i < 30; i++){
        printf("%d: %d %d %d\n", i, jump_stair_v1(i), jump_stair_v2(i), jump_stair_v3(i));
    }


    assert(1==jump_stair_v1(1));
    assert(1==jump_stair_v2(1));
    assert(0==jump_stair_v3(1));
    assert(2==jump_stair_v1(2));
    assert(2==jump_stair_v2(2));
    assert(0==jump_stair_v3(2));
    assert(13==jump_stair_v1(6));
    assert(2==jump_stair_v2(6));
    assert(1==jump_stair_v3(6));
    assert(21==jump_stair_v1(7));
    assert(3==jump_stair_v2(7));
    assert(0==jump_stair_v3(7));
    assert(55==jump_stair_v1(9));
    assert(3==jump_stair_v2(9));
    assert(1==jump_stair_v3(9));

    return 0;
}
