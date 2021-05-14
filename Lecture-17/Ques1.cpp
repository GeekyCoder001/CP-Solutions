//Convert Little Endian to Big Endian and Vice Versa
#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    scanf("%x",&num); //Any number taken in hexadecimal value
    printf("Intiatially :- 0x%x\n",num);

    //Take all 8 bits one by one by bit masking
    int first=num&(0x000000FF);
    int second=num&(0x0000FF00);
    int third=num&(0x00FF0000);
    int forth=num&(0xFF000000);

    //Rearrange it
    first<<=24;
    second<<=8;
    third>>=8;
    forth>>=24;

    //Combine it
    num=first|second|third|forth;
    printf("Finally     :- 0x%x\n",num);
    return 0;
}