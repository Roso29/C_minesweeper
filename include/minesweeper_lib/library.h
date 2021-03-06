#pragma once
// If the project gets compiled as C++, this will prevent namespace mangling.
#ifdef __cplusplus
extern "C" {
#endif

#include "Field.h"
#include <stdbool.h>

char *hello(void);
Field *CreateField(int rows, int columns);
bool IsDimensionValid(int rows, int columns);
int AddRowToField(Field* fieldPtr, int rowIndex, char* rowStr);
void PrintField(Field* fieldPtr);
void PrintHints(Field* fieldPtr);
bool IsRowDimsValid(Field *fieldPtr, int rowIndex, int rowLength);
bool IsRowContentValid(char* rowString, int rowLength);
int CalculateFieldHints(Field* fieldPtr);
int CalculateSurroundingMines(Field* fieldPtr, int rowIndex, int columnIndex);

#ifdef __cplusplus
}
#endif
