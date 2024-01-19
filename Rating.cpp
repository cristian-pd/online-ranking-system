#include "Rating.h"

Rating::Rating() : Mu(25.0f), Sigma(25.0f / 3.0f), SigmaSquared(625.0f / 9.0f) { }
Rating::Rating(const Decimal mu, const Decimal sigma) : Mu(mu), Sigma(sigma), SigmaSquared(sigma * sigma) { }