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
 * @brief SMBIOS 2.1 entry point structure
 *
 * @header{Filesystem}
 * @file smbios/smbios_21_entry_point.hpp
 */

#pragma once

#include "smbios/smbios_entry_point.hpp"

namespace smbios {
namespace parser {

class Smbios21EntryPoint: public SmbiosEntryPoint {

public:
    /*!
     * @brief Create Entry point structure pointer
     * @param buf pointer to the bytes to be parsed
     * @param buf_size number of bytes to be parsed
     */
    Smbios21EntryPoint(const std::uint8_t* buf, const size_t buf_size);

    /*! Copy constructor */
    Smbios21EntryPoint(const Smbios21EntryPoint&) = default;

    /*! Assignment operator */
    Smbios21EntryPoint& operator=(const Smbios21EntryPoint&) = default;

    /*! Destructor */
    ~Smbios21EntryPoint() {}

    /*!
     * @brief Get anchor string which indicates the start of the entry point structure
     */
    std::string get_anchor_string() const override;

    /*!
     * @brief Get SMBIOS major version
     * @return numerical value of the SMBIOS major version
     */
    std::uint8_t get_major_version() const override;

    /*!
     * @brief Get SMBIOS minor version
     * @return numerical value of the SMBIOS minor version
     */
    std::uint8_t get_minor_version() const override;

    /*!
     * @brief Get revision number of the entry point structure
     * @return entry point structure revision
     */
    std::uint8_t get_revision() const override;

    /*!
     * @brief Get struct table address
     * @return return offset of start of struct table within the MDR region
     */
    std::uint64_t get_struct_table_address() const override;

    /*!
     * @brief Get intermediate anchor string
     * @return intermediate anchor string
     */
    std::string get_intermediate_anchor_string() const {
        return {reinterpret_cast<char const*>(m_entry_point->intermediate_anchor),
                sizeof(m_entry_point->intermediate_anchor)};
    }


#pragma pack(push, 1)

/*!
 * @brief Smbios 2.1 (32-bit) Entry point structure
 * */
    struct EntryPointStructure {
        uint8_t anchor[4];
        uint8_t checksum;
        uint8_t length;
        uint8_t major;
        uint8_t minor;
        uint16_t max_struct_size;
        uint8_t revision;
        uint8_t formatted_area[5];
        uint8_t intermediate_anchor[5];
        uint8_t intermediate_checksum;
        uint16_t struct_table_length;
        uint32_t struct_table_address;
        uint16_t struct_count;
        uint8_t bcd_revision;
    };

#pragma pack(pop)

private:
    const EntryPointStructure* m_entry_point;
};



}
}
