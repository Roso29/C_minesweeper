#pragma once
// If the project gets compiled as C++, this will prevent namespace mangling.
#ifdef __cplusplus
extern "C" {
#endif

#include "Field.h"

char *hello(void);
Field *CreateField(int rows, int columns, char symbol);


#ifdef __cplusplus
}
#endif
