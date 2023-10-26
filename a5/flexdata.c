#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

typedef struct FlexData {
    bool isInt;
    int value_int;
    double value_double;
}FlexData;

FlexData flexDivide(FlexData a, FlexData b){

    FlexData ret = {0};

    if (a.isInt && b.isInt) {
        ret.isInt = 1;
        ret.value_int = a.value_int/b.value_int;

    } else if (a.isInt && !b.isInt) {
        ret.isInt = 0;
        ret.value_double = a.value_int/b.value_double;

    } else if (!a.isInt && b.isInt) {
        ret.isInt = 0;
        ret.value_double = a.value_double/b.value_int;

    } else {
        ret.isInt = 0;
        ret.value_double = a.value_double/b.value_double;
    }

    return ret;
}
