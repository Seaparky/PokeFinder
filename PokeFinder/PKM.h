#pragma once
#include "pkmTypes.h"
#include "json.hpp"

namespace Sparky
{

	class Pokemon
	{
	public:

		std::string myName;

		std::string pSourceName;

		std::array<PKType, 2> type;

		bool operator==(const Type& aType) const
		{
			return type[0] == aType || type[1] == aType;
		}

		bool operator==(const PKType& aType) const
		{
			return type[0] == aType || type[1] == aType;
		}

	private:


	};

}


