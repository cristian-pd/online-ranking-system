#include <cmath>

#include "TeamRating.h"

constexpr Decimal Beta = 25.0f / 6.0f;
constexpr Decimal Kappa = 0.0001f;

const std::vector<const TeamRating> BradleyTerryFullPair(const std::vector<const TeamRating>& teams)
{
	std::vector<const TeamRating> updatedTeams;
	updatedTeams.reserve(teams.size());

	for (size_t i = 0; i < teams.size(); i++)
	{
		Decimal omega = 0.0f;
		Decimal delta = 0.0f;

		for (size_t q = 0; q < teams.size(); q++)
		{
			if (i == q)
				continue;

			const Decimal ciq = std::sqrt(teams[i].SigmaSquared + teams[q].SigmaSquared + 2.0f * Beta * Beta);
			const Decimal gamma = std::sqrt(teams[i].SigmaSquared) / ciq;
			const Decimal piq = 1.0f / (1.0f + std::exp((teams[q].Mu - teams[i].Mu) / ciq));

			Decimal s = 0.0f;
			if (teams[q].Rank > teams[i].Rank)
				s = 1.0f;
			else if (teams[q].Rank == teams[i].Rank)
				s = 0.5f;

			const float sigsqToCiq = teams[i].SigmaSquared / ciq;
			omega += sigsqToCiq * (s - piq);
			delta += gamma * sigsqToCiq / ciq * piq * (1.0f - piq);
		}

		std::vector<const PlayerRating> players;
		players.reserve(teams[i].Players.size());

		for (size_t j = 0; j < teams[i].Players.size(); j++)
		{
			const Decimal mu = teams[i].Players[j].Mu + teams[i].Players[j].SigmaSquared / teams[i].SigmaSquared * omega;
			const Decimal sigmaSquared = teams[i].Players[j].SigmaSquared * std::max(1.0f - teams[i].Players[j].SigmaSquared / teams[i].SigmaSquared * delta, Kappa);

			players.push_back(PlayerRating(mu, std::sqrt(sigmaSquared)));
		}

		updatedTeams.push_back(TeamRating(players, teams[i].Rank)); // TODO: Update score & rank
	}

	return updatedTeams;
}

int main(int argc, char** argv)
{
	return 0;
}