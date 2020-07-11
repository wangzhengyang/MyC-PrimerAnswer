#include "Chapter6.h"

int fact(int val)
{
    int ret = 1;
    int i = 1;
    while(i <= val){
        ret *= i++;
    }
    return ret;
}