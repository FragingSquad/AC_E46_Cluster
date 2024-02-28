#pragma once
#include <Windows.h>

extern HANDLE serialPort;

bool OpenSerialPort(const char* portName);

void CloseSerialPort();