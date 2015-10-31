#pragma once
#include <iostream>
#include <string>

#include "BaseDefines.h"
#include "AbilitySystem.h"
#include "DiceSystem.h"

// Armour 는 다른 파일로 이동 필요.
struct Armour
{
	const int			ID;
	const std::wstring	Name;
	const int			AC;
};

struct Weapon
{
	const int	ID;
	const std::wstring Name;
	const DiceType DamageDice;
};

class CCharacter
{
public:
	NO_COPY(CCharacter);
	CCharacter() = default;
	~CCharacter() = default;

public:
	bool Set(CAbilitySystem abl);

	inline int GetAdjustment(AbilityType abl) const
	{
		return m_AbilitySystem.GetAdjustment(abl);
	}
	inline int AC() const
	{
		// armor AC + DEX adjustment
		return m_Armour.AC + m_AbilitySystem.GetAdjustment(AbilityType::DEX);
	}
	inline DiceType AttackDice() const
	{
		return m_Weapon.DamageDice;
	}
private:
	CAbilitySystem m_AbilitySystem;
	Weapon m_Weapon{ 0, L"no", DiceType::d4 };
	Armour m_Armour{ 0, L"no", 9 };
};