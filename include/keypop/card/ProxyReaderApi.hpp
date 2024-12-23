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

#include "keypop/card/CardResponseApi.hpp"
#include "keypop/card/ChannelControl.hpp"
#include "keypop/card/spi/CardRequestSpi.hpp"

namespace keypop {
namespace card {

using keypop::card::spi::CardRequestSpi;

/**
 * Reader able to transmit card requests and having control over the physical channel.
 *
 * <p>Backside of the <b>keypop::reader::CardReader</b> interface present in the
 * <b>Terminal Reader API</b>.
 *
 * <p>An adapter of this interface must also implement <b>CardReader</b>.
 *
 * <p>To use this API, simply cast a <b>CardReader</b> as a <b>ProxyReaderApi</b>.
 *
 * @since 1.0.0
 */
class ProxyReaderApi {
public:
    /**
     *
     */
    virtual ~ProxyReaderApi() = default;

    /**
     * Transmits a keypop::card::CardRequestSpi, applies the provided keypop::card::ChannelControl
     * policy and returns a keypop::card::CardResponseApi.
     *
     * <p>The APDUs (keypop::card::spi::ApduRequestSpi) contained in the
     * keypop::card::CardRequestSpi are sent to the card, their responses
     * (keypop::card::ApduResponseApi) are added to a new list (keypop::card::CardResponseApi).
     *
     * <p><b>Note:</b> in case of an error when sending an APDU (communication error, unexpected
     * status word), an keypop::card::AbstractApduException exception is thrown. Any responses from
     * previously transmitted APDU commands are attached to this exception.<br>
     * This allows the calling application to be tolerant to card tearing and to retrieve the
     * partial response to the keypop::card::CardRequestSpi or to have strict control over the
     * APDUs sent to the card (see keypop::card::CardRequestSpi::stopOnUnsuccessfulStatusWord()).
     *
     * @param cardRequest The card request.
     * @param channelControl The channel control policy to apply.
     * @return A not null reference.
     * @throw IllegalArgumentException If one of the provided parameters is null.
     * @throw ReaderBrokenCommunicationException If the communication with the reader has failed.
     * @throw CardBrokenCommunicationException If the communication with the card has failed.
     * @throw UnexpectedStatusWordException If any of the APDUs returned an unexpected status word
     *        and the card request specified the need to check them.
     * @since 1.0.0
     */
    virtual const std::shared_ptr<CardResponseApi> transmitCardRequest(
        const std::shared_ptr<CardRequestSpi> cardRequest, const ChannelControl channelControl)
        = 0;

    /**
     * Releases the communication channel previously established with the card.
     *
     * @throw ReaderBrokenCommunicationException If the communication with the reader has failed.
     * @since 1.0.0
     */
    virtual void releaseChannel() = 0;
};

} /* namespace card */
} /* namespace keypop */
