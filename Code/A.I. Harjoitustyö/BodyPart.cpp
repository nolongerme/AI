#include "BodyPart.h"


BodyPart::BodyPart(BODY_PART_SIZE bodyPartSize)
{
	switch (bodyPartSize)
	{
	case SMALL:
		chanceToHit = 0.7;
		break;

	case MEDIUM:
		chanceToHit = 0.8;
		break;

	case LARGE:
		chanceToHit = 0.95;
		break;
	}
}


BodyPart::~BodyPart()
{
	delete armor;
}
