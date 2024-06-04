#include "CoolDown.h"

CoolDown::CoolDown(float delay) : coolDownLeft(delay), coolDelay(delay) { }

void CoolDown::Update(const float& dt)
{
    if (coolDownLeft > 0.f)
    {
        coolDownLeft -= dt;
        coolDownLeft = std::max(coolDownLeft, 0.f);
    }
}

void CoolDown::ReloadCoolDown()
{
    coolDownLeft = coolDelay;
}

bool CoolDown::IsAvailable()
{
    return coolDownLeft == 0.f;
}


