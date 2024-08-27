/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <cstdint>
#include <memory>
#include <ostream>
#include <vector>

namespace keypop {
namespace card {

/**
 * Data received in response to an APDU command.
 *
 * <p>Consists in a data part of variable length and a status word (SW1SW2).
 *
 * @see keypop::card::spi::ApduRequestSpi
 * @since 1.0.0
 */
class ApduResponseApi {
public:
    /**
     * Gets the raw data received from the card (including the status word).
     *
     * @return An array of at least 2 bytes.
     * @since 1.0.0
     */
    virtual const std::vector<uint8_t>& getApdu() const = 0;

    /**
     * Gets the data part of the response received from the card (excluding the status word).
     *
     * @return A not null byte array.
     * @since 1.0.0
     */
    virtual const std::vector<uint8_t> getDataOut() const = 0;

    /**
     * Gets the status word of the APDU as an int.
     *
     * @return An integer between 0000h and FFFFh.
     * @since 1.0.0
     */
    virtual int getStatusWord() const = 0;

    /**
     *
     */
    friend std::ostream&
    operator<<(std::ostream& os, const std::shared_ptr<ApduResponseApi> ara) {
        os << "APDU_RESPONSE_API: {"
           << "APDU = " << ara->getApdu() << ", "
           << "DATA_OUT = " << ara->getDataOut() << ", "
           << "STATUS_WORD = " << ara->getStatusWord() << "}";

        return os;
    }

    /**
     *
     */
    friend std::ostream&
    operator<<(std::ostream& os, const std::vector<std::shared_ptr<ApduResponseApi>>& aras) {
        os << "APDU_RESPONSE_APIS: {";
        for (auto it = aras.begin(); it != aras.end(); ++it) {
            if (it != aras.begin())
                os << ", ";
            os << *it;
        }
        os << "}";

        return os;
    }
};

} /* namespace card */
} /* namespace keypop */
