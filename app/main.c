#include <stdio.h>
#include "minesweeper_lib/library.h"
#include <string.h>

/**
 * The main entry point to the application.
 *
 * @return  0 on success, otherwise an error code.
 */
int main(void) {

    printf("Enter dimensions of field.\nThen enter each row.\n");
    
    bool nextInput = true;
    
    while (nextInput){
        char* rowStr;
        char* colStr;

        char dims[30];
        
        scanf("%s %s", rowStr, colStr);
        printf("Rows: %s   Columns: %s\n",rowStr, colStr);
    }

    return 0;
}