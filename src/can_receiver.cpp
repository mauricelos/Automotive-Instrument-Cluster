///
/// @file can_receiver.cpp
///

#include <string.h>
#include <iostream>
#include <unistd.h>

#include <sys/ioctl.h>

#include "linux/can/raw.h"

#include "can_receiver.h"

void CanDataReceiver::OpenCanSocket(const char* can_device_name)
{
    if ((socket_ = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0)
    {
        std::cerr << "Not able to connect socket" << '\n';
    }

    strcpy(ifr_.ifr_name, can_device_name);
    ioctl(socket_, SIOCGIFINDEX, &ifr_);

    memset(&addr_, 0, sizeof(addr_));
    addr_.can_family = AF_CAN;
    addr_.can_ifindex = ifr_.ifr_ifindex;

    if (bind(socket_, (struct sockaddr*)&addr_, sizeof(addr_)) < 0)
    {
        std::cerr << "Not able to bind socket" << '\n';
    }
}

void CanDataReceiver::AddCanFilter(const canid_t& can_id, const canid_t& can_mask)
{
    rfilter_[rfilter_size_].can_id = can_id;
    rfilter_[rfilter_size_].can_mask = can_mask;
    rfilter_size_++;

    setsockopt(socket_, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter_, sizeof(rfilter_));
}

can_frame CanDataReceiver::ReadCanData()
{
    nbytes_ = read(socket_, &frame_, sizeof(struct can_frame));

    if (nbytes_ < 0)
    {
        std::cerr << "Not able to read can data" << '\n';
    }

    return frame_;
}

void CanDataReceiver::CloseSocket()
{
    if (close(socket_) < 0)
    {
        std::cerr << "Not able to close socket" << '\n';
    }
}