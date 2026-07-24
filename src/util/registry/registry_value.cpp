/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Pavel Kirienko <pavel@opencyphal.org>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#include "registry_value.hpp"

namespace cyphal
{
namespace registry
{

bool coerce(Value& destination, const Value& source)
{
    return visit(detail::Coercer(), destination.union_value, source.union_value);
}

}  // namespace registry
}  // namespace cyphal
