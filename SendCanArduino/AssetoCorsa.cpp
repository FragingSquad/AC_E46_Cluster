#include <Windows.h>
#include "AssetoCorsa.h"


HANDLE hMapFile = NULL;
void* mapFileBuffer = nullptr;

/**
 * @brief Init the shared memory mapping with the game engine
*/
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

/**
 * @brief get the game shared memory structure
 * @return the game shared memory structure
*/
SPageFilePhysics* GetPageFilePhysics() 
{
    return (SPageFilePhysics*)mapFileBuffer;
}