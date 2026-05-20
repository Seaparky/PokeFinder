#include "json.hpp"
#include <fstream>
#include <iostream>
#include <array>
#include <algorithm>
#include "spUtilities.h"
#include "PKM.h"

using namespace nlohmann;

int main()
{
	std::array<Sparky::Pokemon, 151> KantoContainer;
	json Kanto;
	std::ifstream readStream("Region/Kanto.Goob");
	Kanto = json::parse(readStream);
	readStream.close();
	int i = 1;
	for (auto element : Kanto["content"])
	{
		KantoContainer[i].myName = element["Name"].get<std::string>();
		KantoContainer[i].pSourceName = element["FileSource"].get<std::string>();
		json source;
		std::ifstream readStream(KantoContainer[i].pSourceName);
		source = json::parse(readStream);
		readStream.close();
		KantoContainer[i].type[0].SetType(source["Primary"].get<int>());
		KantoContainer[i].type[1].SetType(source["Secondary"].get<int>());
		
		i++;
	}

	auto SparkResult = std::find(KantoContainer.begin(), KantoContainer.end(), Sparky::Type::Bug);
	
	std::vector<Sparky::Pokemon> PkmOfType;

	for (int i = 0; i < KantoContainer.size();)
	{
		if (KantoContainer[i].type[0] == Sparky::Type::Fire)
		{
			PkmOfType.push_back(KantoContainer[i]);
		}

		i++;
	}

	for (int i = 0; i < PkmOfType.size();)
	{
		std::cout << PkmOfType[i].myName << " is a " << PkmOfType[i].type[0].GetTypeName() << " type" << std::endl;

		i++;
	}

}

