#pragma once

#include <vector>

#include "PlayerRating.h"

class TeamRating final : public Rating
{
public:
	TeamRating(const std::vector<const PlayerRating> players, const size_t rank);
	~TeamRating() = default;

	const std::vector<const PlayerRating> Players;
	const size_t Rank;
};