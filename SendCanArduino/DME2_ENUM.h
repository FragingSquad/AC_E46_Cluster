#pragma once

/**
 * @brief Enumeration for DME2 pedal depressed states.
 */
enum DME2_PEDAL_DEPRESSED_ENUM
{
    PEDAL_DEPRESSED_NONE    = (1 << 0), ///< No pedal depressed
    PEDAL_DEPRESSED_BRAKE   = (1 << 1), ///< Brake pedal depressed
    PEDAL_DEPRESSED_PEDAL   = (1 << 2)  ///< Pedal depressed
};
