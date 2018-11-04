/**
 * fixedpoint_private.h
 */

#ifndef FIXED_FIXEDPOINT_PRIVATE_H_
#define FIXED_FIXEDPOINT_PRIVATE_H_

#include "fixedpoint_common.h"

#define FIXED_FRACUNIT(xtype, xfracbits) \
    ( (xtype)1 << (xfracbits) )

#define FIXED_ABS(xtype, x) \
    ( (xtype)( { xtype tmp = (x), sign = tmp >> ( 8 * sizeof(xtype) - 1); (tmp ^ sign) - sign; } ) )

#define FIXED_MUL(xtype, xfracbits, xenclosingtype, a, b) \
    ( (xtype)( (xenclosingtype)(a) * (b) >> (xfracbits) ) )

#define FIXED_DIV(xtype, xfracbits, xenclosingtype, a, b) \
    ( (xtype)( ( (xenclosingtype)(a) << (xfracbits) ) / (b) ) )

/**
 * @param xenclosingtype    Eclosing type
 */
#define INT_TO_FIXED(xtype, xfracbits, xenclosingtype, xval) \
    ( (xtype)((xenclosingtype)(xval) << (xfracbits)) )

#define FIXED_TO_DOUBLE(xtype, xfracbits, xval) \
    ( (double)(xval) / FIXED_FRACUNIT(xtype, xfracbits) )

#define DOUBLE_TO_FIXED(xtype, xfracbits, xval) \
    ( (xtype)( (xval) * FIXED_FRACUNIT(xtype, xfracbits) ) )

#endif /* FIXED_FIXEDPOINT_PRIVATE_H_ */
