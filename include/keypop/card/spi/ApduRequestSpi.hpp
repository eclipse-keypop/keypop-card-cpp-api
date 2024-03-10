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
namespace spi {

/**
 * Data to build a single APDU command to be sent to a card.
 *
 * @see org.calypsonet.terminal.card.ApduResponseApi
 * @since 1.0.0
 */
class ApduRequestSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~ApduRequestSpi() = default;

    /**
     * Gets the APDU bytes to be sent to the card.
     *
     * @return A array of at least 4 bytes.
     * @since 1.0.0
     */
    virtual std::vector<uint8_t> getApdu() const = 0;

    /**
     * Gets the list of status words that must be considered successful for the
     * APDU.
     *
     * @return A set of integer values containing at least 9000h.
     * @since 1.0.0
     */
    virtual const std::vector<int>& getSuccessfulStatusWords() const = 0;

    /**
     * Gets the information about this APDU request (e.g. command name).
     *
     * <p>These information are intended to improve the logging.
     *
     * @return Null if no information has been defined.
     * @since 1.0.0
     */
    virtual const std::string& getInfo() const = 0;

    /**
     *
     */
    friend std::ostream&
    operator<<(std::ostream& os, const ApduRequestSpi& ars) {
        const std::vector<uint8_t> apdu = ars.getApdu();
        const std::vector<int> sw = ars.getSuccessfulStatusWords();

        std::stringstream ssApdu;
        for (const auto val : apdu) {
            ssApdu << std::uppercase << std::hex << std::setfill('0')
                   << std::setw(2) << static_cast<int>(val);
        }

        std::stringstream ssSw;
        for (auto it = std::begin(sw); it != std::end(sw); ++it) {
            ssSw << std::uppercase << std::hex << std::setfill('0')
                 << std::setw(4) << static_cast<int>(*it);
            if (it != sw.end() - 1) {
                ssSw << ", ";
            }
        }

        os << "APDU_REQUEST_SPI: {"
           << "APDU: " << ssApdu.str() << ", "
           << "SUCCESSFUL_STATUS_WORD: " << ssSw.str() << ", "
           << "INFO: " << ars.getInfo() << "}";

        return os;
    }

    /**
     *
     */
    friend std::ostream&
    operator<<(std::ostream& os, const std::shared_ptr<ApduRequestSpi> ars) {
        os << *ars.get();

        return os;
    }

    /**
     *
     */
    friend std::ostream&
    operator<<(
        std::ostream& os,
        const std::vector<std::shared_ptr<ApduRequestSpi>>& arss) {
        os << "APDU_REQUEST_SPIS: {";

        for (auto it = std::begin(arss); it != std::end(arss); ++it) {
            os << *it;
            if (it != arss.end() - 1) {
                os << ", ";
            }
        }

        os << "}";

        return os;
    }
};

} /* namespace spi */
} /* namespace card */
} /* namespace keypop */
