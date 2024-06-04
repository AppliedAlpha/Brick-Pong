#include "CoolDown.h"

CoolDown::CoolDown(float delay) : cool_down_left_(delay), cool_delay_(delay) { }

void CoolDown::Update(const float& dt)
{
    if (cool_down_left_ > 0.f)
    {
        cool_down_left_ -= dt;
        cool_down_left_ = std::max(cool_down_left_, 0.f);
    }
}

void CoolDown::ReloadCoolDown()
{
    cool_down_left_ = cool_delay_;
}

bool CoolDown::IsAvailable()
{
    return cool_down_left_ == 0.f;
}
