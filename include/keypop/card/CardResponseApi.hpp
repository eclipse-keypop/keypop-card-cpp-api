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

#include <memory>
#include <ostream>
#include <string>
#include <vector>

#include "keypop/card/ApduResponseApi.hpp"

namespace keypop {
namespace card {

/**
 * Group of multiple APDU responses.
 *
 * <p>Contains a list of keypop::card::ApduResponseApi received from the card in
 * response to a keypop::card::spi::CardRequestSpi and the associated execution
 * status.
 *
 * <p>The execution status includes the state of the logical channel after the
 * operation and the information saying whether a response is present for all
 * APDUs in the keypop::card::spi::CardRequestSpi.
 *
 * <p>Responses may be missing when this object is embedded in an
 * keypop::card::AbstractApduException, for example, if the card is removed
 * durin processing or if an unsuccessful status word was received and
 * processing was requested to be stopped in this case (see
 * keypop::card::spi::CardRequestSpi::stopOnUnsuccessfulStatusWord()).
 *
 * @see keypop::card::spi::CardRequestSpi
 * @since 1.0.0
 */
class CardResponseApi {
public:
    /**
     *
     */
    virtual ~CardResponseApi() = default;

    /**
     * Gets a list of all responses received to the executed APDU requests.
     *
     * @return A not null list, empty if there is no response.
     * @since 1.0.0
     */
    virtual const std::vector<std::shared_ptr<ApduResponseApi>>&
    getApduResponses() const
        = 0;

    /**
     * Gets the state of the logical channel following the execution of the
     * request.
     *
     * @return True if the logical channel is open.
     * @since 1.0.0
     */
    virtual bool isLogicalChannelOpen() const = 0;

    /**
     *
     */
    friend std::ostream&
    operator<<(std::ostream& os, const CardResponseApi& cra) {
        os << "CARD_RESPONSE_API: {"
           << "APDU_RESPONSES: " << cra.getApduResponses() << ", "
           << "IS_LOGICAL_CHANNEL_OPEN: " << cra.isLogicalChannelOpen() << "}";

        return os;
    }

    /**
     *
     */
    friend std::ostream&
    operator<<(std::ostream& os, const std::shared_ptr<CardResponseApi> cra) {
        if (cra) {
            os << *cra.get();
        } else {
            os << "CARD_RESPONSE_API: null";
        }

        return os;
    }
};

} /* namespace card */
} /* namespace keypop */
