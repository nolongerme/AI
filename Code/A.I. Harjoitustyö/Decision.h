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

	float envittutiia(BodyPart bodypart, Character chracter, Character attacker);
	BodyPart charDecision(BodyPart head, BodyPart rightarm, BodyPart leftarm, BodyPart leftleg, BodyPart rightleg, BodyPart vittutorso, Character character, Character attacker);
};

