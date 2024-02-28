#pragma once
#include "Can.h"

/**
 * @brief Generate a frame from a DME1 ECU
 * @param rpm the engine RPM
 * @return the generated CANFRAME
*/
CANFRAME_RAW generateDME1Frame(UINT16 rpm);

/**
 * @brief Generate a frame from a DME3 ECU
 * @param temperature the oil temperature from -48.373 to 142.877 Celsius
 * @param pedal_state DME2_PEDAL_DEPRESSED_ENUM pedal pressed type
 * @param throttle the amount the throttle is pushed from 0 - 1.0f
 * @return the generated CANFRAME
*/
CANFRAME_RAW generateDME2Frame(float temperature, enum DME2_PEDAL_DEPRESSED_ENUM pedal_state, float throttle);

/**
 * @brief Generate a frame from a DME4 ECU
 * @param byte0lights DME4_BYTE0_LIGHTS_ENUM light type
 * @param byte3lights DME4_BYTE3_LIGHTS_ENUM light type
 * @return the generated CANFRAME
*/
CANFRAME_RAW generateDME4Frame(DME4_BYTE0_LIGHTS_ENUM byte0lights, DME4_BYTE3_LIGHTS_ENUM byte3lights);


/**
 * @brief Send a can fram to through the serial port
 * @param frame the frame reference to send
 * @return true if it is sent with success
*/
bool SendCanFrame(const CANFRAME_RAW& frame);