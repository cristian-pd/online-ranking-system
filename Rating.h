#pragma once

#include "Types.h"

class Rating
{
public:
	Rating();
	Rating(const Decimal mu, const Decimal sigma);

	virtual ~Rating() = default;

	const Decimal Mu;
	const Decimal Sigma;
	const Decimal SigmaSquared;
};