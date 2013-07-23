/*******************************************************************************
 * This file is part of IMTAphy
 * _____________________________________________________________________________
 *
 * Copyright (C) 2010
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

#include <IMTAPHY/Transmission.hpp>
#include <IMTAPHY/Link.hpp>

using namespace imtaphy;


Transmission::Transmission(Direction direction_, 
                           const std::vector< wns::ldk::CompoundPtr >& transportBlocks_, 
                           Link* link_, 
                           StationPhy* source_, 
                           StationPhy* destination_, 
                           const imtaphy::interface::PrbPowerPrecodingMap& perPRBpowerAndPrecoding_, 
                           unsigned int numTxAntennas_, 
                           unsigned int numLayers_) :
                    direction(direction_),
                    transportBlocks(transportBlocks_),
                    source(source_),
                    destination(destination_),
                    link(link_),
                    perPRBpowerAndPrecoding(perPRBpowerAndPrecoding_),
                    numTxAntennas(numTxAntennas_),
                    numLayers(numLayers_),
                    id(0)
{

}

