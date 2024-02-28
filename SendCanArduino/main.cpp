#include <Windows.h>
#include <iostream>
#include "AssetoCorsa.h"
#include "SerialPortHelper.h"
#include "Can_Utils.h"

#define SOFTWARE_NAME "Asseto Corsa BMW E46 cluster DRIVER V0.1"

int main()
{
    char comPortName[6] = "";

    SetConsoleTitleA(SOFTWARE_NAME);
    printf_s("%s \n", SOFTWARE_NAME);

    do
    {
        printf_s("Enter the port name (e.g., COM7): ");
        scanf_s("%s", comPortName, 5);

        if (OpenSerialPort(comPortName))
        {
            InitPhysics();
            SPageFilePhysics* Ph = GetPageFilePhysics();

            while (!GetAsyncKeyState(VK_INSERT))
            {
                float rpmtest = Ph->rpms / (float)(Ph->currentMaxRpm) * 6000.f; // 6000 being your cluser max
                CANFRAME_RAW frame = generateDME1Frame((UINT16)rpmtest);
                if (!SendCanFrame(frame)) break;

                frame = generateDME2Frame(Ph->airTemp, PEDAL_DEPRESSED_NONE, Ph->gas);
                if (SendCanFrame(frame)) break;
            }

            CloseSerialPort();
        }
    } while (true);

    return 0;
}
