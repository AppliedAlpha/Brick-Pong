#pragma once
#include "header/stdafx.h"

class CoolDown
{
public:
    CoolDown(float delay);

    void Update(const float& dt);
    bool IsAvailable();

private:
    float coolDownLeft;
    float coolDelay;    
};