#pragma once
#include <vector>
#include "BodyPart.h"
#include "Calculator.h"


class Decision
{
public:
	Decision();
	~Decision();

	float envittutiia(BodyPart bodypart);
	BodyPart charDecision(BodyPart head, BodyPart rightarm, BodyPart leftarm, BodyPart leftleg, BodyPart rightleg, BodyPart vittutorso);
};

