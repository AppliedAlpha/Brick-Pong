#pragma once
#include "header/stdafx.h"

class CoolDown
{
public:
    CoolDown(float delay);

    void Update(const float& dt);
    bool IsAvailable();
    void ReloadCoolDown();
    float GetCurrentCoolDown() { return coolDownLeft; };
    float GetCoolDelay() { return coolDelay; };

private:
    float coolDownLeft;
    float coolDelay;    
};