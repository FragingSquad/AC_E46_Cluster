#pragma once

//Asseto Corsa shared memory
#include "SharedFileOut.h"

/**
 * @brief Init the shared memory mapping with the game engine
*/
void InitPhysics();

/**
 * @brief get the game shared memory structure
 * @return the game shared memory structure
*/
SPageFilePhysics* GetPageFilePhysics();