/******************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT.                                       *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#pragma once

#include <stdexcept>

namespace keypop {
namespace card {

/**
 * Policy for managing the physical channel after a card request is executed.
 *
 * @since 1.0.0
 */
enum class ChannelControl {
    /**
     * Leaves the physical channel open.
     *
     * @since 1.0.0
     */
    KEEP_OPEN,

    /**
     * Terminates communication with the card.<br>
     * The physical channel closes instantly or a card removal sequence is
     * initiated depending on the observation mode.
     *
     * @since 1.0.0
     */
    CLOSE_AFTER
};

/**
 * Returns the enum constant of this type with the specified value.
 *
 * @param value The value of the enum constant to be returned.
 * @return The enum constant with the specified value.
 * @throw std::invalid_argument If this enum has no constant with the specified
 * value.
 * @since 2.0.1
 */
inline ChannelControl
valueOf(const int value) {
    switch (value) {
    case static_cast<int>(ChannelControl::KEEP_OPEN):
        return ChannelControl::KEEP_OPEN;
    case static_cast<int>(ChannelControl::CLOSE_AFTER):
        return ChannelControl::CLOSE_AFTER;
    default:
        throw std::invalid_argument("invalid ChannelControl value");
    }
}

} /* namespace card */
} /* namespace keypop */
