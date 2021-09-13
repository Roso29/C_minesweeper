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

#ifdef __cplusplus
}
#endif
