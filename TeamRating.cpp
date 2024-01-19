#include "TeamRating.h"

const Rating CarculateTeamNormalDistribution(const std::vector<const PlayerRating>& players)
{
	float mu = 0.0f;
	float sigma = 0.0f;

	for (const PlayerRating& player : players)
	{
		mu = player.Mu;
		sigma = player.Mu;
	}

	return Rating(mu, sigma);
}

TeamRating::TeamRating(const std::vector<const PlayerRating> players, const size_t rank) : Rating(CarculateTeamNormalDistribution(players)), Rank(rank) { }