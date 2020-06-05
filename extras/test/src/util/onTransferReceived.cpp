/**
 * @brief   Test code for testing 107-Arduino-UAVCAN.
 * @license LGPL 3.0
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <test/util/onTransferReceived.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace util
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

Transfer::Transfer()
: _transfer_received{false}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

OnTransferReceivedFunc Transfer::onTransferReceived()
{
  return std::bind(&Transfer::internalOnTransferReceived, this, std::placeholders::_1);
}

bool Transfer::received() const
{ 
  return _transfer_received;
}

CanardTransfer & Transfer::operator()()
{ 
  return _transfer;
}

/**************************************************************************************
 * PRIVATE
 **************************************************************************************/

void Transfer::internalOnTransferReceived(CanardTransfer & transfer)
{
  _transfer = transfer;
  _transfer_received = true;
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* util */
