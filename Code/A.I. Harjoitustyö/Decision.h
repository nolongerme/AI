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

	float averageDmgDealt(BodyPart bodypart, Character chracter, Character attacker);
	BodyPart charDecision(Character character, Character attacker);
};

