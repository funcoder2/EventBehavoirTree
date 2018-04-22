#pragma once
#include <iostream>

namespace UTIL
{
	void doLog()
	{
		std::cout << std::endl;
	}

	template <typename T> void doLog(const T& t)
	{
		std::cout << t << std::endl;
	}

	template <typename First, typename... Rest>
	void doLog(const First& first, const Rest&... rest)
	{
		std::cout << first << " ";
		doLog(rest...); // recursive call using pack expansion syntax  
	}

	template<typename E>
	constexpr auto toUType(E enumerator) noexcept
	{
		return static_cast<std::underlying_type_t<E>>(enumerator);
	}
}