/*******************************************************************************
 * This file is part of openWNS (open Wireless Network Simulator)
 * _____________________________________________________________________________
 *
 * Copyright (C) 2004-2007
 * Chair of Communication Networks (ComNets)
 * Kopernikusstr. 16, D-52074 Aachen, Germany
 * phone: ++49-241-80-27910,
 * fax: ++49-241-80-22242
 * email: info@openwns.org
 * www: http://www.openwns.org
 * _____________________________________________________________________________
 *
 * openWNS is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License version 2 as published by the
 * Free Software Foundation;
 *
 * openWNS is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/

#ifndef WNS_NODE_COMPONENT_CONFIGCREATOR_HPP
#define WNS_NODE_COMPONENT_CONFIGCREATOR_HPP

#include <WNS/StaticFactory.hpp>
#include <WNS/pyconfig/View.hpp>

namespace wns { namespace node {
	class Interface;
}}

namespace wns { namespace node { namespace component {
	/**
	 * @brief Creator implementation to be used with StaticFactory.
	 *
	 * Useful for constructors with a Node and pyconfig::View parameter.
	 *
	 */
	template <typename T, typename KIND = T>
	struct ConfigCreator :
		public ConfigCreator<KIND, KIND>
	{
		virtual KIND* create(
			wns::node::Interface* node,
			const wns::pyconfig::View& config)
		{
			return new T(node, config);
		}
	};

	template <typename KIND>
	struct ConfigCreator<KIND, KIND>
	{
	public:
		virtual KIND* create(
			wns::node::Interface*,
			const wns::pyconfig::View&) = 0;

		virtual ~ConfigCreator()
		{}
	};

} // component
} // node
} // wns

#endif // NOT defined WNS_NODE_COMPONENT_CONFIGCREATOR_HPP

/*
  Local Variables:
  mode: c++
  fill-column: 80
  c-basic-offset: 8
  c-comment-only-line-offset: 0
  c-tab-always-indent: t
  indent-tabs-mode: t
  tab-width: 8
  End:
*/
