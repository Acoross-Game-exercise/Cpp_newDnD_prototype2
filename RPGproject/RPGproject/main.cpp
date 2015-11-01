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
	CCharacter pc1(L"��ȯ", 10, CAbilitySystem(9, 9, 9, 9, 9, 9));
	CCharacter enemy1(L"���", 3, CAbilitySystem(9, 9, 9, 9, 9, 9));

	BattleSystem::AttackResult ar = BattleSystem::Action_NormalAttack(pc1, enemy1);
	
	cout << (ar.bHit ? "true" : "false") << endl;
	cout << ar.nDamage << endl;

	return 0;
}

void TestBattle()
{
	CCharacter pc1(L"��ȯ", 10, CAbilitySystem(9, 9, 9, 9, 9, 9));
	CCharacter enemy1(L"���", 3, CAbilitySystem(9, 9, 9, 9, 9, 9));

	while (true)
	{
		wprintf(L"\n");
		if (pc1.IsAlive() == false)
		{
			wprintf(L"�� �׾���\n");
			break;
		}
		else
		{
			wprintf(L"���� ����!\n");
			BattleSystem::AttackResult ar = BattleSystem::Action_NormalAttack(pc1, enemy1);
			if (ar.bHit)
			{
				enemy1.ModifyHP(-ar.nDamage);
				wprintf(L"�����ߴ�!\n");
				wprintf(L"%d�� �����!\n", ar.nDamage);
			}
			else
			{
				wprintf(L"��������!\n");
			}	
		}

		if (enemy1.IsAlive() == false)
		{
			wprintf(L"�� �̰���.\n");
			break;
		}
		else
		{
			wprintf(L"����� ����!\n");
			BattleSystem::AttackResult ar = BattleSystem::Action_NormalAttack(enemy1, pc1);
			if (ar.bHit)
			{
				pc1.ModifyHP(-ar.nDamage);
				wprintf(L"�����ߴ�!\n");
				wprintf(L"%d�� �����!\n", ar.nDamage);
			}
			else
			{
				wprintf(L"��������!\n");
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
		Sleep(100);	// windows �Լ�
	}

	TestAttack();

	return 0;
}