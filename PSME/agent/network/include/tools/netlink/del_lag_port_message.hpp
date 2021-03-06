/*!
 * @copyright
 * Copyright (c) 2015-2017 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * @file del_lag_port_message.hpp
 *
 * @brief Switch Del Lag Port configuration
 * */

#pragma once
#include "lag_port_message.hpp"

namespace agent {
namespace network {
namespace tools {
namespace netlink {

/*! Remove Lag Port Message */
class DelLagPortMessage: public LagPortMessage {
public:

    /*!
     * @brief Default constructor.
     *
     * @param[in] port Port interface name.
     * */
    DelLagPortMessage(const std::string& port);

    /*!
     * @brief Default destructor.
     * */
    virtual ~DelLagPortMessage();
};

}
}
}
}

