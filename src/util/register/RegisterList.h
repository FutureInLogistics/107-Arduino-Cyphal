/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020-2023 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_LIST_H_
#define REGISTER_LIST_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include <map>
#include <vector>

#include "Register.hpp"

#include "../../Node.hpp"
#include "../../DSDL_Types.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RegisterList
{
public:
  RegisterList(Node & node_hdl);

  template <typename T>
  std::shared_ptr<impl::Register<T>> create(std::string const &name,
                                            Access const access,
                                            Persistent const is_persistent,
                                            T const & initial_val)
  {
    auto reg = std::make_shared<impl::Register<T>>(name, access, is_persistent, initial_val);
    _reg_list.push_back(reg);
    return reg;
  }

private:
  std::vector<std::shared_ptr<impl::RegisterBase>> _reg_list;

  typedef uavcan::_register::List::Request_1_0  TListRequest;
  typedef uavcan::_register::List::Response_1_0 TListResponse;
  ServiceServer _reg_list_srv;
  TListResponse onList_1_0_Request_Received(TListRequest const & req);

  typedef uavcan::_register::Access::Request_1_0  TAccessRequest;
  typedef uavcan::_register::Access::Response_1_0 TAccessResponse;
  ServiceServer _reg_access_srv;
  TAccessResponse onAccess_1_0_Request_Received(TAccessRequest const & req);
};

#endif /* REGISTER_LIST_H_ */
