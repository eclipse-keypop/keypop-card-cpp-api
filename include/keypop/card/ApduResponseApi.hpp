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

#include <cstdint>
#include <iomanip>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
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
     * C++
     */
    virtual void setApdu(const std::vector<std::uint8_t>& apdu) = 0;

    /**
     * Gets the data part of the response received from the card (excluding the
     * status word).
     *
     * @return A not null byte array.
     * @since 1.0.0
     */
    virtual std::vector<uint8_t> getDataOut() const = 0;

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
    operator<<(std::ostream& os, const ApduResponseApi& ara) {
        const std::vector<uint8_t>& apdu = ara.getApdu();
        const std::vector<uint8_t> dataOut = ara.getDataOut();

        std::stringstream ssApdu;
        for (const auto val : apdu) {
            ssApdu << std::uppercase << std::hex << std::setfill('0')
                   << std::setw(2) << static_cast<int>(val);
        }

        std::stringstream ssDataOut;
        for (const auto val : dataOut) {
            ssDataOut << std::uppercase << std::hex << std::setfill('0')
                      << std::setw(2) << static_cast<int>(val);
        }

        std::stringstream ssSw;
        ssSw << std::uppercase << std::hex << std::setfill('0') << std::setw(4)
             << ara.getStatusWord();

        os << "APDU_RESPONSE_API: {"
           << "APDU: " << ssApdu.str() << ", "
           << "DATA_OUT: " << ssDataOut.str() << ", "
           << "STATUS_WORD: " << ssSw.str() << "}";

        return os;
    }

    /**
     *
     */
    friend std::ostream&
    operator<<(std::ostream& os, const std::shared_ptr<ApduResponseApi> ara) {
        os << *ara.get();

        return os;
    }

    /**
     *
     */
    friend std::ostream&
    operator<<(
        std::ostream& os,
        const std::vector<std::shared_ptr<ApduResponseApi>>& aras) {
        os << "APDU_RESPONSE_APIS: {";

        for (auto it = std::begin(aras); it != std::end(aras); ++it) {
            os << *it;
            if (it != aras.end() - 1) {
                os << ", ";
            }
        }

        os << "}";

        return os;
    }
};

} /* namespace card */
} /* namespace keypop */
