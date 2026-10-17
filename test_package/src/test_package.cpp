/******************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT.                                       *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#include <iostream>

#include "keypop/card/ChannelControl.hpp"

int
main() {
    const auto control = keypop::card::valueOf(
        static_cast<int>(keypop::card::ChannelControl::CLOSE_AFTER));
    std::cout
        << "Keypop::Card header-only package resolved and linked correctly ("
        << (control == keypop::card::ChannelControl::CLOSE_AFTER ? "CLOSE_AFTER"
                                                                 : "KEEP_OPEN")
        << ")" << std::endl;
    return 0;
}
