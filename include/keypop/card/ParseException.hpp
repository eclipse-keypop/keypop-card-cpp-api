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

namespace keypop {
namespace card {

/**
 * Indicates that the parsing of the card selection response has failed.
 *
 * <p>The most likely reason is that the select application command returned an invalid FCI
 * structure.
 *
 * @since 2.0.0
 */
class ParseException : public std::exception {
public:
    /**
     * @param message The message to identify the exception context.
     * @since 1.0.0
     */
    explicit ParseException(const std::string& message)
    : std::exception() {
        (void)message;
    }

    /**
     * @param message The message to identify the exception context.
     * @param cause The cause.
     * @since 1.0.0
     */
    ParseException(const std::string& message, const std::shared_ptr<std::exception> cause)
    : std::exception(*cause) {
        (void)message;
    }
};

} /* namespace card */
} /* namespace keypop */
