#include <numeric>
#include <iostream>
#include <array>

template <typename It>
int find_duplicate(It start, It finish)
{
	auto size = std::distance(start, finish);

	int actual_sum = std::accumulate(start, finish, 0);
	int expected_sum = size * (size - 1) / 2;

	return actual_sum - expected_sum;
}

int main()
{
	std::array<int, 7> arr = {{ 1, 2, 3, 4, 4}};

	std::cout << "The duplicate element is " <<
				find_duplicate(arr.begin(), arr.end());

	return 0;
}