#pragma once
#include <iostream>

#include "BaseDefines.h"
#include "DiceSystem.h"
#include "Character.h"

namespace BattleSystem
{
	int AC2HitRollNeeded(int AC)
	{
		if (AC > 9 && AC < -1)
			_ASSERT(0);

		int nHitRollNeeded = 19 - AC;
		return nHitRollNeeded;
	}

	bool CheckHit(const CCharacter& Attacker, const CCharacter& Target)
	{
		// make hit rolls: 1d20 + mod(pow) + bonus(weapon)
		const int d20 =			DiceSystem::Inst().RollDice(DiceType::d20);
		const int nHitRoll =	d20 + Attacker.GetAdjustment(AbilityType::STR);

		// compare hit rolls and target AC
		const int nTargetHitRoll = AC2HitRollNeeded(Target.AC());

		if (nHitRoll >= nTargetHitRoll)
		{
			return true;
		}

		return false;
	}

	struct AttackResult
	{
		bool	bHit;
		int		nDamage;
	};

	// ����� �ϴ� �Ϲ� ���� �׼�
	AttackResult Action_NormalAttack(CCharacter& Attacker, CCharacter& Target)
	{
		if (CheckHit(Attacker, Target) == false)
		{
			return AttackResult{ false, 0 };
		}

		const DiceType attackDice = Attacker.DamageDice();
		const int nDamageRoll = DiceSystem::Inst().RollDice(attackDice);
		const int nDamage = nDamageRoll + Attacker.GetAdjustment(AbilityType::STR);	//�������� �� ����ġ �ٳ�???

		Target.ModifyHP( - nDamage);

		return AttackResult{ true, nDamage };
	}
}