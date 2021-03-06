/*!
 * @copyright
 * Copyright (c) 2017 Intel Corporation
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
 * @file get_aggregated_health_sensor.cpp
 *
 * @brief GetAggregatedHealthSensor IPMI command request and response implementation.
 * */

#include "ipmi/command/sdv/rmm/get_aggregated_health_sensor.hpp"
#include "ipmi/command/sdv/enums.hpp"

using namespace ipmi;
using namespace ipmi::command::sdv;

request::GetAggregatedHealthSensor::GetAggregatedHealthSensor():
    Request(NetFn::INTEL, Cmd::GET_AGGREGATED_HEALTH_SENSOR) {}

void request::GetAggregatedHealthSensor::pack(IpmiInterface::ByteBuffer&) const {
}

response::GetAggregatedHealthSensor::GetAggregatedHealthSensor():
    Response(NetFn::INTEL + 1, Cmd::GET_AGGREGATED_HEALTH_SENSOR, RESPONSE_SIZE) {}

void response::GetAggregatedHealthSensor::unpack(const IpmiInterface::ByteBuffer& data) {
    m_health_status = data[HEALTH_OFFSET];
}
