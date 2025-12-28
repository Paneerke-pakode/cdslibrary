#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>

typedef enum {
    CDS_SUCCESS = 0,
    CDS_FAILURE = -1,
    CDS_NULL_PTR = -2,
    CDS_OUT_OF_MEMORY = -3,
    CDS_EMPTY = -4,
    CDS_FULL = -5
} cds_status;

#endif
