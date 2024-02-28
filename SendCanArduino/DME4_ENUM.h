#pragma once

/**
 * @brief Enumeration for DME4 BYTE0 light byte mask
 */
enum DME4_BYTE0_LIGHTS_ENUM 
{
    BYTE0_LIGHTS_ENGINE     = (1 << 1), ///< Engine light on
    BYTE0_LIGHTS_CRUISE     = (1 << 3), ///< Cruise light on
    BYTE0_LIGHTS_EML        = (1 << 4), ///< Engine Management Light on
    BYTE0_LIGHTS_GAS_CAP    = (1 << 6), ///< Gas Cap light on
};

/**
 * @brief Enumeration for DME4 BYTE3 light byte mask
 */
enum DME4_BYTE3_LIGHTS_ENUM 
{
    BYTE3_LIGHTS_OIL_LEVEL  = (1 << 1), ///< Oil level light on
    BYTE3_LIGHTS_OVERHEAT   = (1 << 3), ///< Overheat light on
    BYTE3_LIGHTS_M3_7K_RPM  = (1 << 4), ///< 7K rpm light on
    BYTE3_LIGHTS_M3_6K5_RPM = (1 << 5), ///< 6.5K rpm light on
    BYTE3_LIGHTS_M3_5K5_RPM = (1 << 6), ///< 5.57K rpm light on
};