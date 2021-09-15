#include "minesweeper_lib/library.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool IsDimensionValid(int rows, int columns){
    bool validDims = rows > 0 && rows <= 100 && columns > 0 && columns <= 100;
    return validDims;
}

Field *CreateField(int rows, int columns) {
    Field *fieldPtr = NULL;
    if (!IsDimensionValid(rows, columns)){
        return fieldPtr;
    }    

    fieldPtr = malloc(sizeof(Field));
    fieldPtr->rows = rows;
    fieldPtr->columns = columns;
    fieldPtr->fieldArray = malloc(rows * sizeof(char*));
    fieldPtr->hintArray = malloc(rows * sizeof(char*));
    for(int row=0; row<rows;row++){
        fieldPtr->fieldArray[row] = malloc(columns * sizeof(char));
        fieldPtr->hintArray[row] = malloc(columns * sizeof(char));
    }
    return fieldPtr;
}

bool IsRowDimsValid(Field* fieldPtr, int rowIndex, int rowLength){
    bool isValid = (rowLength==fieldPtr->columns) & (rowIndex < fieldPtr->rows);
    return isValid;
}

bool IsRowContentValid(char* rowString, int rowLength){
    bool isGoodCharacter = true;
    for(int charI = 0; charI<rowLength; charI++){
        isGoodCharacter = rowString[charI] == '*' || rowString[charI] == '-';
        if (!isGoodCharacter){
            return false;
        }
    }
    return true;
}

bool IsRowValid(Field* fieldPtr, int rowIndex, int rowLength, char* rowString){
    bool isValid = IsRowDimsValid(fieldPtr, rowIndex, rowLength) && IsRowContentValid(rowString,rowLength);
    return isValid;
}

int AddRowToField(Field* fieldPtr, int rowIndex, char* rowStr){
    int rowLength = strlen(rowStr);
    if (!IsRowValid(fieldPtr, rowIndex, rowLength, rowStr)){
        return 0;
    }
    char * rowAddr = fieldPtr->fieldArray[rowIndex];
    strncpy(rowAddr, rowStr, rowLength);

    return 1;
}  

int CalculateSurroundingMines(Field* fieldPtr, int rowIndex, int columnIndex){

    //Get ranges around space to check for mines
    //If space is on edge of field, don't go beyond that space (to off field)
    int lowerColumnIndex = (columnIndex-1 >= 0) ? columnIndex-1 : 0;
    int higherColumnIndex = (columnIndex+1 < fieldPtr->columns) ? columnIndex+1 : columnIndex;

    int lowerRowIndex = (rowIndex-1 >= 0)? rowIndex-1 : 0;
    int higherRowIndex = (rowIndex+1 < fieldPtr->rows) ? rowIndex+1 : rowIndex;

    int mineCount = 0;
    for (int rowI = lowerRowIndex; rowI<=higherRowIndex; rowI++){
        for (int columnI = lowerColumnIndex; columnI<=higherColumnIndex; columnI++){
            mineCount+=(fieldPtr->fieldArray[rowI][columnI] == '*');
        }
    }
    return mineCount;
}


int CalculateFieldHints(Field* fieldPtr){
    //Calculate field hints (ie the counts of surrounding mines)
    //Store hints in hintArray in fieldPtr
    //Iterate through rows and columns of fieldArray
    int rows = fieldPtr->rows;
    int columns = fieldPtr->columns;
    int surroundingMines = 0;

    for(int rowI=0; rowI<rows; rowI++){
        for(int colI=0; colI<columns; colI++){
            //First check if location is a mine, in which case add to hintArray as a mine.
            if(fieldPtr->fieldArray[rowI][colI] == '*'){
                fieldPtr->hintArray[rowI][colI] = '*';
            }
            //If not a mine, calculate number of mines in surrounding area
            else{
                //Adding a single digit int to '0' converts it to a character
                surroundingMines = CalculateSurroundingMines(fieldPtr, rowI, colI) + '0';
                fieldPtr->hintArray[rowI][colI] = surroundingMines;
            }
        }
    }    
}

void PrintField(Field* fieldPtr){
    int rows = fieldPtr->rows;
    int columns = fieldPtr->columns;
    char** fieldArray = fieldPtr->fieldArray;

    for(int row=0;row < rows; row++){
        printf("%s\n",fieldArray[row]);
    }
}

void PrintHints(Field* fieldPtr){
    int rows = fieldPtr->rows;
    int columns = fieldPtr->columns;
    char** hintArray = fieldPtr->hintArray;

    for(int row=0;row < rows; row++){
        printf("%s\n",hintArray[row]);
    }

}