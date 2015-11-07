#include "Character.h"

#include <algorithm>

inline CCharacter::CCharacter(std::wstring Name, int nMaxHP, CAbilitySystem abl)
	: m_sName(std::move(Name)), m_AbilitySystem(std::move(abl))
{
	m_nMaxHP = std::max(1, nMaxHP);
	m_nHP = m_nMaxHP;
}

inline int CCharacter::ModifyHP(int nHPDiff)
{
	m_nHP += nHPDiff;
	m_nHP = std::max(0, m_nHP);
	m_nHP = std::min(m_nMaxHP, m_nHP);

	return m_nHP;
}
