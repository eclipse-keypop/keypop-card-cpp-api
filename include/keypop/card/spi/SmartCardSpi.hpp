/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

namespace keypop {
namespace card {
namespace spi {

/**
 * Marker interface providing run-time type information about data defining the
 * <b>keypop::reader::selection::spi::SmartCard</b> resulting of the selection process provided by
 * the <b>KeypopReader API</b>.
 *
 * <p>An adapter of this interface must also implement <b>SmartCard</b>.
 *
 * @since 1.0.0
 */
class SmartCardSpi {
public:
    /**
     *
     */
    virtual ~SmartCardSpi() = default;
};

} /* namespace spi */
} /* namespace card */
} /* namespace keypop */
