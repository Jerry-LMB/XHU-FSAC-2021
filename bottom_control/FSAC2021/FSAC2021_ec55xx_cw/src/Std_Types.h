/*
 * Code generated for the formwork and Simulink model.
 *
 * FILE    : Std_Types.h
 *
 * VERSION : 1.000
 *
 * DATE    : Thu Apr 14 16:39:56 2011
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef STD_TYPES_H
#define STD_TYPES_H

#define E_OK 0u
#define E_NOT_OK 1u

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef unsigned char         boolean; /*                 TRUE .. FALSE                */
typedef signed char           sint8;   /*                 -128 .. +127                 */
typedef unsigned char         uint8;   /*                    0 .. 255                  */
typedef signed short          sint16;  /*               -32768 .. +32767               */
typedef unsigned short        uint16;  /*                    0 .. 65535                */
typedef signed int            sint32;  /*          -2147483648 .. +2147483647          */
typedef unsigned int          uint32;  /*                    0 .. 4294967295           */
typedef signed long long      sint64;  /* -9223372036854775808 .. 9223372036854775807  */
typedef unsigned long long    uint64;  /*                    0 .. 18446744073709551615 */
                                        
typedef signed int      sint8_least;  /* At least 7 bit + 1 bit sign    */
typedef unsigned int    uint8_least;  /* At least 8 bit                 */
typedef signed int      sint16_least; /* At least 15 bit + 1 bit sign   */
typedef unsigned int    uint16_least; /* At least 16 bit                */
typedef signed int      sint32_least; /* At least 31 bit + 1 bit sign   */
typedef unsigned int    uint32_least; /* At least 32 bit                */
                                        
typedef float  float32;
typedef double float64;
 
typedef unsigned char StatusType; /* OSEK compliance */
typedef uint8 Std_ReturnType; 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* STD_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
