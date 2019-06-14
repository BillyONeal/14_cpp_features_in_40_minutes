#include <ppl.h>
#include <algorithm>
#include <execution>
#include <random>
#include <vector>
#include <benchmark/benchmark.h>

using namespace std;
using namespace concurrency;

mt19937 gen{random_device{}()};
uniform_real_distribution<> dist;

void fill_with_random(vector<unsigned int>& vec) {
    for (unsigned int& i : vec) {
        i = gen();
    }
}

void fill_with_random(vector<double>& vec) {
    for (double& i : vec) {
        i = dist(gen);
    }
}

template<class T>
__declspec(noinline) void serial_sort(benchmark::State& state) {
    const size_t r0 = static_cast<size_t>(state.range(0));
    for (auto _ : state) {
        (void)_;
        state.PauseTiming();
        vector<T> data(r0);
        fill_with_random(data);
        state.ResumeTiming();
        sort(execution::seq, data.begin(), data.end(), less<>{});
    }
}

template<class T>
__declspec(noinline) void parallel_sort(benchmark::State& state) {
    const size_t r0 = static_cast<size_t>(state.range(0));
    for (auto _ : state) {
        (void)_;
        state.PauseTiming();
        vector<T> data(r0);
        fill_with_random(data);
        state.ResumeTiming();
        sort(execution::par, data.begin(), data.end(), less<>{});
    }
}

template<class T>
__declspec(noinline) void ppl_sort(benchmark::State& state) {
    const size_t r0 = static_cast<size_t>(state.range(0));
    for (auto _ : state) {
        (void)_;
        state.PauseTiming();
        vector<T> data(r0);
        fill_with_random(data);
        state.ResumeTiming();
        parallel_sort(data.begin(), data.end());
    }
}

BENCHMARK_TEMPLATE(serial_sort, unsigned int)->Range(256, 1024)->Range(2048, 1000000)->UseRealTime();
BENCHMARK_TEMPLATE(parallel_sort, unsigned int)->Range(256, 1024)->Range(2048, 1000000)->UseRealTime();
BENCHMARK_TEMPLATE(ppl_sort, unsigned int)->Range(256, 1024)->Range(2048, 1000000)->UseRealTime();
BENCHMARK_TEMPLATE(serial_sort, double)->Range(256, 1024)->Range(2048, 1000000)->UseRealTime();
BENCHMARK_TEMPLATE(parallel_sort, double)->Range(256, 1024)->Range(2048, 1000000)->UseRealTime();
BENCHMARK_TEMPLATE(ppl_sort, double)->Range(256, 1024)->Range(2048, 1000000)->UseRealTime();

BENCHMARK_MAIN();
