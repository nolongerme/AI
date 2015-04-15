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

	float averageDmgDealt(BodyPart bodypart, Character target, Character attacker);
	BodyPart* charDecision(Character target, Character attacker, FIGHT_STYLE style);

private:
	std::vector<BodyPart*> _bodyParts;
};

