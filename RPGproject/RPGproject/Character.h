#pragma once
#include <iostream>
#include <string>
#include <algorithm>

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
	CCharacter(std::wstring Name, int nMaxHP, CAbilitySystem abl)
		: m_sName(std::move(Name)), m_AbilitySystem(std::move(abl))
	{
		m_nMaxHP = max(1, nMaxHP);
		m_nHP = m_nMaxHP;
	}
	~CCharacter() = default;

public:
	int ModifyHP(int nHPDiff)
	{
		m_nHP += nHPDiff;
		m_nHP = max(0, m_nHP);
		m_nHP = min(m_nMaxHP, m_nHP);

		return m_nHP;
	}

public:
	inline bool IsAlive() const
	{
		return m_nHP > 0 ? true : false;
	}
	inline int GetAdjustment(AbilityType abl) const
	{
		return m_AbilitySystem.GetAdjustment(abl);
	}
	inline int AC() const
	{
		// armor AC + DEX adjustment
		return m_Armour.AC - m_AbilitySystem.GetAdjustment(AbilityType::DEX);
	}
	inline DiceType DamageDice() const
	{
		return m_Weapon.DamageDice;
	}
private:
	const std::wstring m_sName{ L"" };
	int m_nMaxHP;
	int m_nHP;
	CAbilitySystem m_AbilitySystem;
	Weapon m_Weapon{ 0, L"no", DiceType::d4 };
	Armour m_Armour{ 0, L"no", 9 };
};