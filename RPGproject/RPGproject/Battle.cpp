#include "Battle.h"

#include "BattleSystem.h"
#include "Character.h"

using namespace BattleSystem;

CBattle::CBattle()
{
}

CBattle::~CBattle()
{
}

void CBattle::Init()
{
	m_pPC = new CCharacter(L"일환", 10, CAbilitySystem(9, 9, 9, 9, 9, 9));
	m_pEnemy = new CCharacter(L"고블린", 3, CAbilitySystem(9, 9, 9, 9, 9, 9));
}

void CBattle::Process()
{
	const char inputChar = g_input.inputChar;
	g_input.inputChar = '\0';	//clear

	if (m_pPC == nullptr || m_pEnemy == nullptr)
	{
		return;
	}

	if (m_pPC->IsAlive())
	{
		AttackResult ar = Action_NormalAttack(*m_pPC, *m_pEnemy);
	}

	if (m_pEnemy->IsAlive())
	{
		AttackResult ar = Action_NormalAttack(*m_pEnemy, *m_pPC);
	}
}

Input g_input = { '\0' };