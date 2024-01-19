#pragma once

#include "Rating.h"

class PlayerRating final : public Rating
{
public:
	PlayerRating();
	PlayerRating(const Decimal mu, const Decimal sigma);

	~PlayerRating() = default;
};