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

#include "keypop/card/spi/CardSelectionRequestSpi.hpp"
#include "keypop/card/spi/SmartCardSpi.hpp"

namespace keypop {
namespace card {
namespace spi {

/**
 * Extension of the card selection for a specific card extension.
 *
 * <p>Provides the CardSelectionRequestSpi and interprets the result to provide a SmartCardSpi.
 *
 * <p>Backside of the <b>org.eclipse.keypop.reader.selection.spi.CardSelectionExtension</b>
 * interface present in the <b>Keypop Reader API</b>.
 *
 * <p>An adapter of this interface must also implement <b>CardSelectionExtension</b>.
 *
 * @since 2.0.0
 */
class CardSelectionExtensionSpi {
public:
    /**
     * Virtual destructor.
     */
    virtual ~CardSelectionExtensionSpi() = default;

    /**
     * Gets the card selection request containing the selection data prepared for this selection.
     *
     * @return A non-null reference.
     * @since 1.0.0
     */
    virtual const std::shared_ptr<CardSelectionRequestSpi> getCardSelectionRequest() const = 0;

    /**
     * Analyzes the response received from the card during the selection process and creates a
     * SmartCardSpi.
     *
     * @param cardSelectionResponseApi The card selection response.
     * @return A non-null reference.
     * @throw ParseException If the card selection response parsing failed.
     * @since 1.0.0
     */
    virtual std::shared_ptr<SmartCardSpi>
    parse(const std::shared_ptr<CardSelectionRequestSpi> cardSelectionResponseApi) const = 0;
};

} /* namespace spi */
} /* namespace card */
} /* namespace keypop */
