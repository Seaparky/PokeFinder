#include "json.hpp"
#include <fstream>
#include <iostream>
#include <array>
#include "spUtilities.h"

using namespace nlohmann;

int main()
{
	std::array<Sparky::pContainer, 151> KantoContainer;
	json Kanto;
	std::ifstream readStream("Region/Kanto.Goob");
	Kanto = json::parse(readStream);
	readStream.close();
	int i = 1;
	for (auto element : Kanto["content"])
	{
		KantoContainer[i].pName = element["Name"].get<std::string>();
		KantoContainer[i].pSource = element["FileSource"].get<std::string>();
		i++;
	}

	std::cout << KantoContainer[1].pName;

}

