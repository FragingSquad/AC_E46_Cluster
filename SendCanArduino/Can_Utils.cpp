#include <math.h>
#include "SerialPortHelper.h"
#include "Can_Utils.h"

CANFRAME_RAW generateDME1Frame(UINT16 rpm)
{
    CANFRAME_DME1 frame = { CANID_DME1 };
    frame.data.qword = 0;
    frame.data.fields.rpm = (UINT16)(rpm * 6.4);
    return *(CANFRAME_RAW*)(&frame);
}

CANFRAME_RAW generateDME2Frame(float temperature, enum DME2_PEDAL_DEPRESSED_ENUM pedal_state, float throttle)
{
    CANFRAME_DME2 frame = { CANID_DME2 };
    frame.data.qword = 0;
    frame.data.fields.pedals = pedal_state;
    frame.data.fields.temp = ((UINT8)round((temperature + 48.373) / 0.75));
    frame.data.fields.pedals = (UINT8)(throttle * 254.0f);
    return *(CANFRAME_RAW*)(&frame);
}

CANFRAME_RAW generateDME4Frame(DME4_BYTE0_LIGHTS_ENUM byte0lights, DME4_BYTE3_LIGHTS_ENUM byte3lights)
{
    CANFRAME_RAW frame = { CANID_DME4 };
    frame.data.qword = 0;
    frame.data.bytes[0].byte = byte0lights;
    frame.data.bytes[3].byte = byte3lights;
    return frame;
}

bool SendCanFrame(const CANFRAME_RAW& frame) {
    // 2 bytes for ID and 8 bytes for data
    UINT8 buffer[10] = {};
    memcpy(buffer, &frame.canID, 2);
    memcpy(buffer + 2, &(frame.data.bytes), 8);


    UINT8 startMarker = 0x69;
    WriteFile(serialPort, &startMarker, sizeof(startMarker), NULL, NULL);

    // Send the struct
    WriteFile(serialPort, buffer, 10, NULL, NULL);

    // Send end marker
    UINT8 endMarker = '\n';
    WriteFile(serialPort, &endMarker, sizeof(endMarker), NULL, NULL);

    UINT8 incomingByte = 0;
    UINT8 result = 0;

    do
    {
        DWORD bytesRead;
        result = ReadFile(serialPort, &incomingByte, sizeof(incomingByte), &bytesRead, NULL);
        if (!result) return false;
    } while (incomingByte != 0x55);

    return true;
}