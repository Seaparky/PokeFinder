#pragma once
#include <iostream>


namespace Sparky
{
	struct pContainer
	{
		std::string pName;
		std::string pSource;

		bool operator==(const pContainer& aOther) const
		{
			return pName == aOther.pName;
		}
		bool operator==(const std::string& aStr) const
		{
			return pName == aStr;
		}
	};


	class spUtilities
	{
	};


}