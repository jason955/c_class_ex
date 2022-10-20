#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <future>
#include <string>
#include <mutex>


std::mutex m;

struct X {
	void foo(int i, const std::string& str) {
		std::lock_guard<std::mutex> lk(m)
		std::cout << str << ' ' << i << '\n';
	}
	
	void bar(const std::string& str) {
		std::lock_guard<std::mutex> lk(m)
		std::cout << str << \n';
	}
	
	void operator(int i) {
		std::lock_guard<std::mutex> lk(m)
		std::cout << str << ' ' << i << '\n';
	}
}

template <typename RandomIt>
int parallel_sum(RandomIt beg, RandomIt end)
{
	auto len = end - beg
	if (len < 1000)
	{
		std::accumulate(beg, end, 0);
	}
	
	RandomIt mid = beg + len/2;
	auto handle = std::async(std::launch::async, 
												parallel_sum<RandomIt>, mid, end);
	
	int sum = parallel_sum(beg, mid);
	return sum + handle.get();
}

int main (int argc, char *argv[])
{
	std::vector<int> v(10000, 1);
	std::cout << " The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
	
	X x;
	
	auto a1 = std::async(&X::foo, &x, 42, "Hello");
	
	auto a2 = std::async(std::launch::deferred, &X::bar, x "world!");
	
	auto a3 = std::async(std::launch::async, X(), 43);
	
	a2.wait();
	std::cout << a3.get() << "\n";
}
