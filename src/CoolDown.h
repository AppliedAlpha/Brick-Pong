#pragma once
#include "header/stdafx.h"

class CoolDown
{
public:
    explicit CoolDown(float delay);

    void Update(const float& dt);
    bool IsAvailable();
    void ReloadCoolDown();
    float GetCurrentCoolDown() const { return cool_down_left_; };
    float GetCoolDelay() const { return cool_delay_; };

private:
    float cool_down_left_;
    float cool_delay_;
};