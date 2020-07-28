///
/// @file can_receiver.h
///

#ifndef CAN_RECEIVER_H
#define CAN_RECEIVER_H

#include <net/if.h>
#include <sys/socket.h>

#include "linux/can.h"

class CanDataReceiver
{
  public:
    void OpenCanSocket(const char* can_device_name);
    void AddCanFilter(const canid_t& can_id, const canid_t& can_mask);
    can_frame ReadCanData();
    void CloseSocket();

  private:
    unsigned int rfilter_size_{0};
    int socket_, nbytes_;
    sockaddr_can addr_;
    ifreq ifr_;
    can_frame frame_;
    can_filter rfilter_[1];
};

#endif  // CAN_RECEIVER_H