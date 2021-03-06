/*
 * Copyright (c) 2015-2017 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.intel.podm.client.events;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.intel.podm.client.OdataTypes;
import com.intel.podm.client.WebClientRequestException;
import com.intel.podm.client.reader.ResourceSupplier;
import com.intel.podm.client.resources.ExternalServiceResourceImpl;
import com.intel.podm.client.resources.ODataId;

import java.util.Set;

import static com.intel.podm.common.types.redfish.OdataTypeVersions.VERSION_PATTERN;
import static java.util.Collections.emptySet;

@OdataTypes({
    "#EventService" + VERSION_PATTERN + "EventService"
})
public class EventServiceResource extends ExternalServiceResourceImpl {
    @JsonProperty("EventTypesForSubscription")
    private Set<String> eventTypesForSubscription;

    @JsonProperty("Subscriptions")
    private ODataId subscriptions;

    public Set<String> getEventTypesForSubscription() {
        if (eventTypesForSubscription == null) {
            return emptySet();
        }
        return eventTypesForSubscription;
    }

    public Iterable<ResourceSupplier> getSubscriptions() throws WebClientRequestException {
        return processMembersListResource(subscriptions);
    }
}
