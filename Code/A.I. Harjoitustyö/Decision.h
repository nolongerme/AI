#pragma once
#include <vector>
#include "BodyPart.h"
#include "Calculator.h"
#include "Character.h"


class Decision
{
public:
	Decision();
	~Decision();

	static float averageDmgDealt(BodyPart bodypart, Character chracter, Character attacker);
	static BodyPart charDecision(Character character, Character attacker, FIGHT_STYLE style);
};

