#pragma once

#include "Character.h"

enum class RoundPhase
{
	PC_Phase,
	Enemy_Phase,
};

struct Input
{
	char inputChar;
};

extern Input g_input;

class CBattle
{
public:
	CBattle();
	~CBattle();
	void Init();

	void Process();

private:
	CCharacter* m_pPC{ nullptr };
	CCharacter* m_pEnemy{ nullptr };

	int m_nRound{ 0 };
	RoundPhase m_Phase{ RoundPhase::PC_Phase };
};

