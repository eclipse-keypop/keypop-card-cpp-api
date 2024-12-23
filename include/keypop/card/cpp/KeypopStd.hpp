/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <iomanip>
#include <ostream>
#include <vector>

namespace std {

/**
 *
 */
inline std::ostream&
operator<<(std::ostream& os, const std::vector<uint8_t>& v) {
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        os << std::uppercase << std::hex << std::setfill('0') << std::setw(2)
           << static_cast<int>(v[i]);
    }

    return os;
}

/**
 *
 */
inline std::ostream&
operator<<(std::ostream& os, const std::vector<int>& v) {
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (i != 0) {
            os << ", ";
        }

        os << std::hex << std::setfill('0') << std::setw(8) << static_cast<int>(v[i]);
    }

    return os;
}
} /* namespace std */
