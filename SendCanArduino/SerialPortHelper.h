#pragma once
#include <Windows.h>

/**
 * @brief External serial port handle
*/
extern HANDLE serialPort;

/**
 * @brief Open the serial port to the passed com name
 * @param portName the com port
 * @return true if the connection succeed
*/
bool OpenSerialPort(const char* portName);

/**
 * @brief Close the serial port handle
*/
void CloseSerialPort();