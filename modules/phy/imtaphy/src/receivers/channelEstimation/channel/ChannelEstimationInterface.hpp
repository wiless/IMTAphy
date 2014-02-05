/*******************************************************************************
 * This file is part of IMTAphy
 * _____________________________________________________________________________
 *
 * Copyright (C) 2012
 * Institute of Communication Networks (LKN)
 * Department of Electrical Engineering and Information Technology (EE & IT)
 * Technische Universitaet Muenchen
 * Arcisstr. 21
 * 80333 Muenchen - Germany
 * http://www.lkn.ei.tum.de/~jan/imtaphy/index.html
 * 
 * _____________________________________________________________________________
 *
 *   IMTAphy is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   IMTAphy is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with IMTAphy.  If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/

#ifndef IMTAPHY_RECEIVERS_CHANNELESTIMATIONINTERFACE_HPP
#define IMTAPHY_RECEIVERS_CHANNELESTIMATIONINTERFACE_HPP

#include <WNS/pyconfig/View.hpp>
#include <IMTAPHY/receivers/ReceiverInterface.hpp>

namespace imtaphy {

    namespace receivers {
        
        class LinearReceiver;
        
        namespace channelEstimation { namespace channel {
            
        class ChannelEstimationInterface
        {
        public:
            ChannelEstimationInterface(LinearReceiver* receiver, const wns::pyconfig::View& pyConfigView) {}
            ChannelEstimationInterface(LinearReceiver* receiver) {}
            
            virtual
            ~ChannelEstimationInterface() {}
            
            virtual 
            imtaphy::detail::ComplexFloatMatrixPtr estimateChannel(imtaphy::interface::PRB prb, imtaphy::Link* link, wns::Power txPower) = 0;
        };
        
    } // end of channelEstimation namespace
        typedef imtaphy::receivers::ReceiverModuleCreator<imtaphy::receivers::channelEstimation::channel::ChannelEstimationInterface> ChannelEstimationCreator;
        typedef wns::StaticFactory<ChannelEstimationCreator> ChannelEstimationFactory;
        
    }}}

#endif //