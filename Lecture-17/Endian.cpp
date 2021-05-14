//Program to check whether our machine is Little of Big Endian
#include<bits/stdc++.h>
using namespace std;

int main(){
    //num taken in hexadecimal value
    int num=0x12345678;//Takes 4 bytes
    char *p;//Takes 1 bytes(because we need to access byte by byte)
    p=(char *)&num;//Type casting

    //If the following print in same order, Big Endian
    //Else, if in reverse, Little Endian
    printf("%x",*p);
    p++;
    printf("%x",*p);
    p++;
    printf("%x",*p);
    p++;
    printf("%x",*p);
    return 0;
}