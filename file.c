#ifndef __STDIO_H__
    #define __STDIO_H__
    # include <stdio.h>
#endif

#ifndef __STDLIB_H__
    #define __STDLIB_H__  
    # include <stdlib.h>
#endif

#ifndef __STDBOOL_H__
    #define __STDBOOL_H__  
    # include <stdbool.h>
#endif

//#define __DEBUG_FILE__

FILE *file_open(const char *datebase,const char *mode){
    return fopen(datebase,mode);
}

bool file_close(FILE *stream_db){
    if (fclose(stream_db)==0) return true;
    else return false;
}

#ifdef __DEBUG_FILE__
int main(int argc, char const *argv[])
{
    FILE *book_db;
    book_db=file_open("books.db","a+");
    return 0;
}

#endif