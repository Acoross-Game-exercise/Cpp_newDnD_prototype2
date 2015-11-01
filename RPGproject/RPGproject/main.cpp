#include <iostream>
#include <Windows.h>

#include "BaseDefines.h"
#include "DiceSystem.h"

#include "AbilitySystem.h"
#include "Character.h"
#include "BattleSystem.h"

using namespace std;

int TestAttack()
{
	CCharacter pc1(L"일환", 10, CAbilitySystem(9, 9, 9, 9, 9, 9));
	CCharacter enemy1(L"고블린", 3, CAbilitySystem(9, 9, 9, 9, 9, 9));

	BattleSystem::AttackResult ar = BattleSystem::Action_NormalAttack(pc1, enemy1);
	
	cout << (ar.bHit ? "true" : "false") << endl;
	cout << ar.nDamage << endl;

	return 0;
}

void TestBattle()
{
	CCharacter pc1(L"일환", 10, CAbilitySystem(9, 9, 9, 9, 9, 9));
	CCharacter enemy1(L"고블린", 3, CAbilitySystem(9, 9, 9, 9, 9, 9));

	while (true)
	{
		wprintf(L"\n");
		if (pc1.IsAlive() == false)
		{
			wprintf(L"너 죽었음\n");
			break;
		}
		else
		{
			wprintf(L"너의 공격!\n");
			BattleSystem::AttackResult ar = BattleSystem::Action_NormalAttack(pc1, enemy1);
			if (ar.bHit)
			{
				enemy1.ModifyHP(-ar.nDamage);
				wprintf(L"명중했다!\n");
				wprintf(L"%d의 대미지!\n", ar.nDamage);
			}
			else
			{
				wprintf(L"빗나갔다!\n");
			}	
		}

		if (enemy1.IsAlive() == false)
		{
			wprintf(L"너 이겼음.\n");
			break;
		}
		else
		{
			wprintf(L"고블린의 공격!\n");
			BattleSystem::AttackResult ar = BattleSystem::Action_NormalAttack(enemy1, pc1);
			if (ar.bHit)
			{
				pc1.ModifyHP(-ar.nDamage);
				wprintf(L"명중했다!\n");
				wprintf(L"%d의 대미지!\n", ar.nDamage);
			}
			else
			{
				wprintf(L"빗나갔다!\n");
			}
		}
	}
}

int main(int argc, char* args[])
{
	setlocale(LC_ALL, "");
	DiceSystem::Inst().Init();

	TestBattle();

	while (true)
	{
		Sleep(100);	// windows 함수
	}

	TestAttack();

	return 0;
}