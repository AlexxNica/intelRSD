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

package com.intel.podm.business.entities.dao;

import com.intel.podm.business.entities.redfish.RemoteTarget;

import javax.enterprise.context.ApplicationScoped;
import javax.persistence.TypedQuery;
import javax.transaction.Transactional;
import java.net.URI;
import java.util.List;

import static com.intel.podm.business.entities.redfish.RemoteTarget.GET_REMOTE_TARGET_BY_SOURCE_URI;
import static javax.transaction.Transactional.TxType.MANDATORY;

@ApplicationScoped
public class RemoteTargetDao extends Dao<RemoteTarget> {
    @Transactional(MANDATORY)
    public List<RemoteTarget> getAllBySourceUri(URI sourceUri) {
        TypedQuery<RemoteTarget> query = entityManager.createNamedQuery(GET_REMOTE_TARGET_BY_SOURCE_URI, RemoteTarget.class);
        query.setParameter("sourceUri", sourceUri);
        return query.getResultList();
    }
}
