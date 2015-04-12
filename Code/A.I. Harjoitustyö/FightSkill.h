#pragma once

enum PERSONALITY
{
	UNHONORABLE,
	NORMALLY_HONORABLE,
	HONORABLE
};

enum FIGHT_STYLE
{
	PASSIVE_STYLE,
	ADAPTIVE_STYLE,
	AGRESSIVE_STYLE
};

class FightSkill
{

public:
	FightSkill(PERSONALITY perso, FIGHT_STYLE style);
	~FightSkill();
	PERSONALITY _personality;
	FIGHT_STYLE _fightStyle;
};

