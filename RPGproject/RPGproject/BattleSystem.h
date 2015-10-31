#pragma once
#include <iostream>

#include "BaseDefines.h"
#include "DiceSystem.h"
#include "Character.h"

namespace BattleSystem
{
	int GetHitRollNeedded(int AC)
	{
		if (AC > 9 && AC < -1)
			_ASSERT(0);

		return 19 - AC;
	}

	bool CheckHit(const CCharacter& Attacker, const CCharacter& Target)
	{
		// make hit rolls: 1d20 + mod(pow) + bonus(weapon)
		const int d20 =			DiceSystem::Inst().RollDice(DiceType::d20);
		const int nHitRoll =	d20 + Attacker.GetAdjustment(AbilityType::STR);

		// compare hit rolls and target AC
		const int nTargetHitRoll = GetHitRollNeedded(Target.AC());

		if (nHitRoll >= nTargetHitRoll)
		{
			return true;
		}

		return false;
	}

	int CalculateDamage(const CCharacter& Attacker)
	{

	}

	int Attack(const CCharacter& Attacker, const CCharacter& Target)
	{
		if (CheckHit(Attacker, Target) == true)
		{
			const int nDamageRoll = DiceSystem::Inst().RollDice(Attacker.AttackDice());
			const int nDamage = nDamageRoll + Attacker.GetAdjustment(AbilityType::STR);	//데미지에 힘 수정치 붙나???
		}
	}
}