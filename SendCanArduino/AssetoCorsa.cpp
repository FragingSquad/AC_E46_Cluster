#include <Windows.h>
#include "AssetoCorsa.h"


/**
 * @brief Handle to the game's shared memory
*/
HANDLE hMapFile = NULL;

/**
 * @brief the address of the game's shared memory
*/
void* mapFileBuffer = nullptr;

void InitPhysics()
{
    TCHAR szName[] = TEXT("Local\\acpmf_physics");
    hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(SPageFilePhysics), szName);
    if (!hMapFile)
    {
        MessageBoxA(GetActiveWindow(), "CreateFileMapping failed", "ACS", MB_OK);
        return;
    }

    mapFileBuffer = (void*)MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, sizeof(SPageFilePhysics));
    if (!mapFileBuffer)
    {
        MessageBoxA(GetActiveWindow(), "MapViewOfFile failed", "ACS", MB_OK);
        return;
    }
}

SPageFilePhysics* GetPageFilePhysics() 
{
    return (SPageFilePhysics*)mapFileBuffer;
}