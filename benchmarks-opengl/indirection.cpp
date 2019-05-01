#include <benchmark/benchmark.h>

#include <algorithm>
#include <functional>
#include <memory>
#include <numeric>
#include <vector>

// std::function
// std::function (large capture)
// lambda
// lambda (large capture)
// inheiritance
// function ptr
// member function ptr

std::vector<int> init()
{
	std::vector<int> result(10000);
	std::iota(begin(result), end(result), 1);
	return result;
}

void std_function(benchmark::State &state)
{
	auto v = init();
	int i = 0;
	std::function<bool(int, int)> fs[]{
		std::function([](int x, int y) { return x > y; }),
		std::function([](int x, int y) { return x < y; }),
	};

	for (auto _ : state)
	{
		std::sort(begin(v), end(v), fs[i]);
		i = (i + 1) % 2;
	}
}

BENCHMARK(std_function);

void std_function_ref(benchmark::State &state)
{
	auto v = init();
	int i = 0;
	std::function<bool(int, int)> fs[]{
		std::function([](int x, int y) { return x > y; }),
		std::function([](int x, int y) { return x < y; }),
	};

	for (auto _ : state)
	{
		std::sort(begin(v), end(v), ref(fs[i]));
		i = (i + 1) % 2;
	}
}

BENCHMARK(std_function_ref);

void lambda(benchmark::State &state)
{
	auto v = init();
	int i = 0;
	auto gt = [](int x, int y) { return x > y; };
	auto lt = [](int x, int y) { return x < y; };

	for (auto _ : state)
	{
		if (i == 0)
			std::sort(begin(v), end(v), gt);
		else
			std::sort(begin(v), end(v), lt);

		i = (i + 1) % 2;
	}
}

BENCHMARK(lambda);


void function_ptr(benchmark::State &state)
{
	auto v = init();
	int i = 0;

	using cmp = bool(*)(int, int);

	cmp fs[]{
		[](int x, int y) { return x > y; },
		[](int x, int y) { return x < y; }
	};

	for (auto _ : state)
	{
		std::sort(begin(v), end(v), fs[i]);
		i = (i + 1) % 2;
	}
}

BENCHMARK(function_ptr);

class cmp_base
{
public:
	virtual bool operator()(int, int) = 0;
	virtual ~cmp_base() = default;
};

class lt : public cmp_base
{
public:
	bool operator()(int x, int y) override { return x < y; }
};

class gt : public cmp_base
{
public:
	bool operator()(int x, int y) override { return x > y; }
};

void inheritance(benchmark::State &state)
{
	auto v = init();
	int i = 0;

	std::unique_ptr<cmp_base> fs[]{
		std::make_unique<gt>(),
		std::make_unique<lt>(),
	};

	for (auto _ : state)
	{
		std::sort(begin(v), end(v), [&](int x, int y) { return (*fs[i])(x, y); });
		i = (i + 1) % 2;
	}
}

BENCHMARK(inheritance);
