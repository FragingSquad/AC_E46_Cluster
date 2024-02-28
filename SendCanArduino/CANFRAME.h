#pragma once

/**
 * @brief Represent one byte from the canframe with bit level access
*/
typedef union _CANBYTE 
{
    UINT8 byte;                 ///< Byte data
    ///< Individual bits within the byte
    UINT8 bit0 : 1;				///< Bit 0
    UINT8 bit1 : 1;				///< Bit 1
    UINT8 bit2 : 1;				///< Bit 2
    UINT8 bit3 : 1;				///< Bit 3
    UINT8 bit4 : 1;				///< Bit 4
    UINT8 bit5 : 1;				///< Bit 5
    UINT8 bit6 : 1;				///< Bit 6
    UINT8 bit7 : 1;				///< Bit 7
} CANBYTE;

/**
 * @brief Represents a raw CAN frame data structure.
 */
typedef struct _CANFRAME_RAW 
{
    enum CANID_ENUM canID;		///< CAN ID
    union 
    {
        UINT64 qword;           ///< 64-bit data
        CANBYTE bytes[8];       ///< Bytes array
    } data;
} CANFRAME_RAW;
