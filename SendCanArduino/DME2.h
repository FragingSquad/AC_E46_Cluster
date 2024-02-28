#pragma once

/**
 * @brief Represents a CAN frame for the DME2 ECU.
*/
typedef struct _CANFRAME_DME2 
{
    enum CANID_ENUM canID;		///< CAN ID
    union 
    {
        UINT64 qword;           ///< 64-bit data
        struct 
        {
            UINT8 padding_000[1];       ///< Padding
            UINT8 temp;                 ///< Temperature data
            UINT8 padding_001[1];       ///< Padding
            struct 
            {
                UINT8 bits : 5;         ///< Bits field
                UINT8 add : 1;          ///< Add for cruise
                UINT8 sub : 1;          ///< Sub for cruise
                UINT8 enable : 1;       ///< Enable for cruise
            } cruise;                   ///< Cruise control fields
            UINT8 padding_002[1];       ///< Padding
            UINT8 throttlePos;          ///< Throttle position data
            UINT8 pedals;               ///< Pedals data
            UINT8 padding_003[1];       ///< Padding
        } fields;                       ///< Fields within the frame
    } data;
} CANFRAME_DME2;
