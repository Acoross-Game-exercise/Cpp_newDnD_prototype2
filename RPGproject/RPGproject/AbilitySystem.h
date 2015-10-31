#pragma once

enum class AbilityType : int
{
	STR = 0,
	INT,
	WIS,
	DEX,
	CON,
	CHA,
	MAX
};

class CAbilitySystem
{
public:
	CAbilitySystem() = default;
	CAbilitySystem(int nStr, int nInt, int nWis, int nDex, int nCon, int nCha)
		: m_Abl{nStr, nInt, nWis, nDex, nCon, nCha}
	{}

	int GetAdjustment(AbilityType abl) const;
	
	bool SetAdjustment(int(&abl)[static_cast<int>(AbilityType::MAX)])
	{
		memcpy_s(m_Abl, sizeof(m_Abl), abl, sizeof(abl));
		return true;
	}

private:
	int m_Abl[static_cast<int>(AbilityType::MAX)]{ 0, };
};