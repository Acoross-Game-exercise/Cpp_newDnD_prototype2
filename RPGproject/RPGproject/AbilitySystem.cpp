#include <iostream>

#include "AbilitySystem.h"

int CAbilitySystem::GetAdjustment(AbilityType abl) const
{
	int nAblType = static_cast<int>(abl);
	if (nAblType < 0 || nAblType >= static_cast<int>(AbilityType::MAX))
	{
		_ASSERT(0);
	}
	return m_Abl[nAblType];
}