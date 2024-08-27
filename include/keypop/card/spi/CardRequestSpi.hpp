/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <memory>
#include <vector>

#include "keypop/card/spi/ApduRequestSpi.hpp"

namespace keypop {
namespace card {
namespace spi {

/**
 * Request grouping multiple APDUs to be executed consecutively.
 *
 * <p>Contains a list of {@link ApduRequestSpi} to be sent to a card and a flag indicating whether
 * to stop processing in case of an unexpected status word in response to one of the APDUs.
 *
 * @see calypsonet::terminal::card::ApduResponseApi
 * @since 1.0.0
 */
class CardRequestSpi {
public:
    /**
     * virtual destructor.
     */
    virtual ~CardRequestSpi() = default;

    /**
     * Gets the list of calypsonet::terminal::card::spi::ApduRequestSpi.
     *
     * @return A not empty list.
     * @since 1.0.0
     */
    virtual const std::vector<std::shared_ptr<ApduRequestSpi>>& getApduRequests() const = 0;

    /**
     * Indicates if the processing of the requests must stop when an unexpected status word is
     * received.
     *
     * @return True if the process must stop at the first unsuccessful status word received.
     * @since 1.0.0
     */
    virtual bool stopOnUnsuccessfulStatusWord() const = 0;
};

} /* namespace spi */
} /* namespace card */
} /* namespace keypop */
