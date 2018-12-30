#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>
#include <winuser.h>
#include <conio.h>

#define FILENAME "books.dat"

struct book{
    char regist[20],name[20],author[20],type[20],publish[20],publish_time[20],price[20];
    struct book *forward,*back;
    char* quality[7];
};