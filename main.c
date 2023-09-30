#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
extern int narcissist();


int main() {

    assert(narcissist(1));
    assert(narcissist(9));
    assert(narcissist(153));
    assert(narcissist(370));
    assert(narcissist(92727));
    assert(narcissist(548834));
    assert(!narcissist(10));
    assert(!narcissist(92));
    assert(!narcissist(1535));
    assert(!narcissist(1234));
    assert(!narcissist(92726));
    assert(!narcissist(93083));

    return 0;
}
