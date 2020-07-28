///
/// @file can_data.cpp
///

#include "can_data.h"

unsigned int CanData::GetVelocity()
{
    return velocity_;
}

void CanData::SetData(const can_frame& can_frame)
{
    m_mutex_.lock();
    if (can_frame.can_id == 0x42A)
    {
        velocity_ = 0;
        for (auto i = 0; i < can_frame.can_dlc; ++i)
        {
            velocity_ += can_frame.data[i];
        }
    }
    m_mutex_.unlock();
}