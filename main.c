#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.c>
//UI
int main(int argc, char const *argv[])
{
    while (1){
        //Draw UI
        char c;
        printf("Please enter your option:");
        scanf("%c",&c);
        //Options
        switch(c){
            case 'x': return 0;
        }
    }
    return 0;
}

