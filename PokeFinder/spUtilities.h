#pragma once
#include "json.hpp"

namespace Sparky
{
	struct pContainer
	{
		std::string pName;
		std::string pSourceName;
		nlohmann::json* pSourceData;
		
		bool operator==(const pContainer& aOther) const
		{
			bool one = pName == aOther.pName;
			bool two = pSourceName == aOther.pSourceName;
			return one && two;
		}
		bool operator==(const std::string& aStr) const
		{
			bool one = aStr == pName;
			bool two = aStr == pSourceName;
			return one || two;
		}
	};


	class spUtilities
	{
	};


}
