//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/common/random_engine.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/common/common.hpp"
#include "duckdb/common/limits.hpp"
#include "duckdb/common/mutex.hpp"

#include <random>

namespace duckdb {
class ClientContext;
struct RandomState;

struct RandomEngine {
	explicit RandomEngine(int64_t seed = -1);
	~RandomEngine();

public:
	//! Generate a random number between min and max
	double NextRandom(double min, double max);

	//! Generate a random number between 0 and 1
	double NextRandom();
	//! Generate a random number between 0 and 1, using 32-bits as a base
	double NextRandom32();
	double NextRandom32(double min, double max);
	uint32_t NextRandomInteger();
	uint32_t NextRandomInteger(uint32_t min, uint32_t max);
	uint64_t NextRandomInteger64();

	void SetSeed(uint32_t seed);

	static RandomEngine &Get(ClientContext &context);

	mutex lock;

private:
	unique_ptr<RandomState> random_state;
};

} // namespace duckdb
