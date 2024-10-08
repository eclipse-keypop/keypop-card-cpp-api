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
#include <ostream>
#include <vector>

#include "keypop/card/spi/CardRequestSpi.hpp"

namespace keypop {
namespace card {
namespace spi {

/**
 * Data provided as input to the selection process.
 *
 * <p>Embeds a card selector defining the target card profile and an optional card request to be
 * executed after the card selection when successful.
 *
 * @see calypsonet::terminal::card::CardSelectionResponseApi
 * @since 1.0.0
 */
class CardSelectionRequestSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~CardSelectionRequestSpi() = default;

    /**
     * Gets the card request.
     *
     * @return Null if no card request has been defined.
     * @since 1.0.0
     */
    virtual const std::shared_ptr<CardRequestSpi> getCardRequest() const = 0;

    /**
     *
     */
    friend std::ostream&
    operator<<(std::ostream& os, const std::shared_ptr<CardSelectionRequestSpi> csr) {
        (void)csr;

        os << "CARD_SELECTION_REQUEST_SPI: {"
           << "<TODO>"
           << "}";

        return os;
    }

    /**
     *
     */
    friend std::ostream&
    operator<<(
        std::ostream& os, const std::vector<std::shared_ptr<CardSelectionRequestSpi>>& csrs) {
        os << "CARD_SELECTION_REQUEST_SPIS: {";

        for (auto it = std::begin(csrs); it != std::end(csrs); ++it) {
            os << *it;
            if (it != csrs.end() - 1) {
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
