#pragma once

/**
 * @brief Represents a CAN frame for the DME1 ECU.
 */
typedef struct _CANFRAME_DME1 
{
    enum CANID_ENUM canID;		///< CAN ID
    union 
    {
        UINT64 qword;           ///< 64-bit data
        struct 
        {
            UINT8 padding_000[2];       ///< Padding
            UINT16 rpm;                 ///< RPM data
            UINT8 padding_001[4];       ///< Padding
        } fields;                       ///< Fields within the frame
    } data;
} CANFRAME_DME1;
