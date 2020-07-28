///
/// @file can_data.h
///

#ifndef CAN_DATA_H
#define CAN_DATA_H

#include <mutex>

#include "linux/can.h"

class CanData
{
  public:
    unsigned int GetVelocity();
    void SetData(const can_frame& can_frame);

  private:
    std::mutex m_mutex_;
    unsigned int velocity_{0};
    unsigned int rpm_{0};
};

#endif  // CAN_DATA_H