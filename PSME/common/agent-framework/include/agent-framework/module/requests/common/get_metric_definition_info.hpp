/*!
 * @header{License}
 * @copyright Copyright (c) 2017 Intel Corporation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @header{Filesystem}
 * @file get_metric_definition_info.hpp
 */

#pragma once



#include "agent-framework/module/constants/common.hpp"
#include "agent-framework/module/constants/command.hpp"
#include "agent-framework/validators/procedure_validator.hpp"

#include <string>

namespace agent_framework {
namespace model {
namespace requests {

/*!
 * Class representing GetMetricDefinitionInfo GAMI request
 * */
class GetMetricDefinitionInfo {
public:
    explicit GetMetricDefinitionInfo(const std::string& metric_definition);


    /*!
     * Get command name
     *
     * @return Command name
     * */
    static std::string get_command() {
        return literals::Command::GET_METRIC_DEFINITION_INFO;
    }


    /*!
     * Get metric_definition UUID
     *
     * @return MetricDefinition UUID
     * */
    const std::string& get_uuid() const {
        return m_metric_definition;
    }


    /*!
     * Convert request object to json::Json
     *
     * @return Converted json::Json object
     * */
    json::Json to_json() const;


    /*!
     * Construct request object from json::Json object
     *
     * @param[in] json json::Json object used for construction
     * */
    static GetMetricDefinitionInfo from_json(const json::Json& json);


    static const jsonrpc::ProcedureValidator& get_procedure() {
        static const jsonrpc::ProcedureValidator procedure{
            get_command(),
            jsonrpc::PARAMS_BY_NAME,
            jsonrpc::JSON_STRING,
            literals::MetricDefinition::METRIC_DEFINITION, VALID_UUID,
            nullptr
        };
        return procedure;
    }


private:
    std::string m_metric_definition{};
};

}
}
}
