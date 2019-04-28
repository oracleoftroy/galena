#include <benchmark/benchmark.h>

#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>

std::string fopen_seek(const std::filesystem::path &filepath)
{
	std::string result;

	FILE *file = fopen(filepath.u8string().c_str(), "rb");
	if (!file)
		throw false;

	fseek(file, 0, SEEK_END);
	result.resize(ftell(file));
	rewind(file);
	std::fread(result.data(), 1, result.size(), file);
	std::fclose(file);

	return result;
}

std::string fstream_seek(const std::filesystem::path &filepath)
{
	std::string result;
	std::ifstream file(filepath, std::ios::binary);
	if (!file)
		throw false;

	file.seekg(0, std::ios::end);
	result.resize(file.tellg());
	file.seekg(0, std::ios::beg);

	file.read(result.data(), result.size());
	return result;
}

std::string fstream_seek_ate(const std::filesystem::path &filepath)
{
	std::string result;
	std::ifstream file(filepath, std::ios::ate | std::ios::binary);
	if (!file)
		throw false;

	result.resize(file.tellg());
	file.seekg(0, std::ios::beg);

	file.read(result.data(), result.size());
	return result;
}

std::string istream_iterator(const std::filesystem::path &filepath)
{
	std::ifstream file(filepath, std::ios::binary);
	if (!file)
		throw false;

	return std::string(std::istreambuf_iterator(file), std::istreambuf_iterator<char>());
}

std::string istream_iterator_reserve_assign(const std::filesystem::path &filepath)
{
	std::ifstream file(filepath, std::ios::binary);
	if (!file)
		throw false;

	std::string result;
	file.seekg(0, std::ios::end);
	result.reserve(file.tellg());
	file.seekg(0, std::ios::beg);

	return result.assign(std::istreambuf_iterator(file), std::istreambuf_iterator<char>());
}

std::string istream_iterator_reserve_insert(const std::filesystem::path &filepath)
{
	std::ifstream file(filepath, std::ios::binary);
	if (!file)
		throw false;

	std::string result;
	file.seekg(0, std::ios::end);
	result.reserve(file.tellg());
	file.seekg(0, std::ios::beg);

	result.insert(end(result), std::istreambuf_iterator(file), std::istreambuf_iterator<char>());
	return result;
}

std::string istream_iterator_reserve_copy(const std::filesystem::path &filepath)
{
	std::ifstream file(filepath, std::ios::binary);
	if (!file)
		throw false;

	std::string result;
	file.seekg(0, std::ios::end);
	result.reserve(file.tellg());
	file.seekg(0, std::ios::beg);

	std::copy(std::istreambuf_iterator(file), std::istreambuf_iterator<char>(), std::back_inserter(result));
	return result;
}

std::string istream_iterator_resize_copy(const std::filesystem::path &filepath)
{
	std::ifstream file(filepath, std::ios::binary);
	if (!file)
		throw false;

	std::string result;
	file.seekg(0, std::ios::end);
	result.resize(file.tellg());
	file.seekg(0, std::ios::beg);

	std::copy(std::istreambuf_iterator(file), std::istreambuf_iterator<char>(), result.data());
	return result;
}

std::string stringstream(const std::filesystem::path &filepath)
{
	std::ifstream file(filepath, std::ios::binary);
	if (!file)
		throw false;

	std::ostringstream stream;
	stream << file.rdbuf();
	return stream.str();
}

static void fopen_seek(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::string s = fopen_seek(__FILE__);
	}
}
BENCHMARK(fopen_seek);

static void fstream_seek(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::string s = fstream_seek(__FILE__);
	}
}
BENCHMARK(fstream_seek);

static void fstream_seek_ate(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::string s = fstream_seek_ate(__FILE__);
	}
}
BENCHMARK(fstream_seek_ate);

static void istream_iterator(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::string s = istream_iterator(__FILE__);
	}
}
BENCHMARK(istream_iterator);

static void istream_iterator_reserve_assign(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::string s = istream_iterator_reserve_assign(__FILE__);
	}
}
BENCHMARK(istream_iterator_reserve_assign);

static void istream_iterator_reserve_insert(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::string s = istream_iterator_reserve_insert(__FILE__);
	}
}
BENCHMARK(istream_iterator_reserve_insert);

static void istream_iterator_reserve_copy(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::string s = istream_iterator_reserve_copy(__FILE__);
	}
}
BENCHMARK(istream_iterator_reserve_copy);

static void istream_iterator_resize_copy(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::string s = istream_iterator_resize_copy(__FILE__);
	}
}
BENCHMARK(istream_iterator_resize_copy);

static void stringstream(benchmark::State &state)
{
	for (auto _ : state)
	{
		std::string s = stringstream(__FILE__);
	}
}
BENCHMARK(stringstream);

#include <iostream>

struct ensure
{
	ensure()
	{
		std::clog << "fopen_seek size: " << fopen_seek(__FILE__).length() << "\n";
		std::clog << "fstream_seek size: " << fstream_seek(__FILE__).length() << "\n";
		std::clog << "fstream_seek_ate size: " << fstream_seek_ate(__FILE__).length() << "\n";
		std::clog << "istream_iterator size: " << istream_iterator(__FILE__).length() << "\n";
		std::clog << "istream_iterator_reserve_assign size: " << istream_iterator_reserve_assign(__FILE__).length() << "\n";
		std::clog << "istream_iterator_reserve_insert size: " << istream_iterator_reserve_insert(__FILE__).length() << "\n";
		std::clog << "istream_iterator_reserve_copy size: " << istream_iterator_reserve_copy(__FILE__).length() << "\n";
		std::clog << "istream_iterator_resize_copy size: " << istream_iterator_resize_copy(__FILE__).length() << "\n";
		std::clog << "stringstream size: " << stringstream(__FILE__).length() << "\n";
	}
};

static ensure ensure_all_read_same_content;
