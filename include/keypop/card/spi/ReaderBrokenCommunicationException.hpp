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
#include <stdexcept>
#include <string>

#include "keypop/card/AbstractApduException.hpp"
#include "keypop/card/CardResponseApi.hpp"

namespace keypop {
namespace card {

/**
 * Exception carrying response data received from the card until a communication failure with the
 * reader occurs.
 *
 * @since 1.0.0
 */
class ReaderBrokenCommunicationException final : public AbstractApduException {
public:
    /**
     * Builds a new exception embedding card response data.
     *
     * @param cardResponseApi The card responses received so far.
     * @param isCardResponseComplete True if the number responses equals the number of requests
     *        present in the original calypsonet::terminal::card::spi::CardRequestSpi.
     * @param message Message to identify the exception context.
     * @since 1.0.0
     */
    ReaderBrokenCommunicationException(
        const std::shared_ptr<CardResponseApi> cardResponseApi,
        const bool isCardResponseComplete,
        const std::string& message)
    : AbstractApduException(cardResponseApi, isCardResponseComplete, message) {
    }

    /**
     * Builds a new exception embedding card response data with the originating exception.
     *
     * @param cardResponseApi The card responses received so far.
     * @param isCardResponseComplete True if the number responses equals the number of requests
     *        present in the original calypsonet::terminal::card::spi::CardRequestSpi.
     * @param message Message to identify the exception context.
     * @param cause The cause
     * @since 1.0.0
     */
    ReaderBrokenCommunicationException(
        const std::shared_ptr<CardResponseApi> cardResponseApi,
        const bool isCardResponseComplete,
        const std::string& message,
        const std::shared_ptr<exception> cause)
    : AbstractApduException(cardResponseApi, isCardResponseComplete, message, cause) {
    }
};

} /* namespace card */
} /* namespace keypop */
