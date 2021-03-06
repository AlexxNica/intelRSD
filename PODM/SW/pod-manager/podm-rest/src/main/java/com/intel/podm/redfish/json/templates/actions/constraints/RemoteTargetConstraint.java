/*
 * Copyright (c) 2017 Intel Corporation
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

package com.intel.podm.redfish.json.templates.actions.constraints;

import com.intel.podm.common.types.redfish.RedfishRemoteTarget;
import com.intel.podm.redfish.json.templates.actions.RemoteTargetPartialRepresentation;

import javax.validation.Constraint;
import javax.validation.ConstraintValidator;
import javax.validation.ConstraintValidatorContext;
import javax.validation.Payload;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.util.List;

@Constraint(validatedBy = RemoteTargetConstraint.RemoteTargetConstraintValidator.class)
@Target(ElementType.PARAMETER)
@Retention(RetentionPolicy.RUNTIME)
public @interface RemoteTargetConstraint {

    String message() default "Cannot update Remote Target with empty values";

    Class<?>[] groups() default {};

    Class<? extends Payload>[] payload() default {};

    class RemoteTargetConstraintValidator implements ConstraintValidator<RemoteTargetConstraint, RemoteTargetPartialRepresentation> {

        @Override
        public void initialize(RemoteTargetConstraint constraintAnnotation) {

        }

        @Override
        public boolean isValid(RemoteTargetPartialRepresentation value, ConstraintValidatorContext context) {
            if (value == null) {
                return false;
            }

            List<RedfishRemoteTarget.Initiator> initiators = value.getInitiator();
            List<RedfishRemoteTarget.Address> addresses = value.getAddresses();

            return initiators != null || addresses != null;
        }
    }
}
