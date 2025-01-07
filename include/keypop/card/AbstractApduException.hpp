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

#include "keypop/card/CardResponseApi.hpp"

namespace keypop {
namespace card {

/**
 * Generic exception carrying response data received from the card until a communication failure
 * occurs or an unexpected APDU status code is received.
 *
 * @since 1.0.0
 */
class AbstractApduException : public std::exception {
public:
    /**
     * Builds a new exception embedding card response data.
     *
     * @param cardResponseApi The card responses received so far.
     * @param isCardResponseComplete True if the number responses equals the number of requests
     *        present in the original calypsonet::terminal::card::spi::CardRequestSpi.
     * @param message The message to identify the exception context.
     * @since 1.0.0
     */
    AbstractApduException(
        const std::shared_ptr<CardResponseApi> cardResponseApi,
        const bool isCardResponseComplete,
        const std::string& message)
    : std::exception()
    , mCardResponseApi(cardResponseApi)
    , mIsCardResponseComplete(isCardResponseComplete) {
        (void)message;
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
    AbstractApduException(
        const std::shared_ptr<CardResponseApi> cardResponseApi,
        const bool isCardResponseComplete,
        const std::string& message,
        const std::shared_ptr<std::exception> cause)
    : std::exception(*cause)
    , mCardResponseApi(cardResponseApi)
    , mIsCardResponseComplete(isCardResponseComplete) {
        (void)message;
    }

    /**
     * Gets the response data received so far.
     *
     * @return A not null reference.
     * @since 1.0.0
     */
    const std::shared_ptr<CardResponseApi>
    getCardResponse() const {
        return mCardResponseApi;
    }

    /**
     * Indicates if all the responses expected from the corresponding
     * calypsonet::terminal::card::spi::CardRequestSpi have been received.
     *
     * @return True if all expected responses have been received.
     * @since 1.0.0
     */
    bool
    isCardResponseComplete() const {
        return mIsCardResponseComplete;
    }

private:
    /**
     *
     */
    const std::shared_ptr<CardResponseApi> mCardResponseApi;

    /**
     *
     */
    const bool mIsCardResponseComplete = false;
};

} /* namespace card */
} /* namespace keypop */
