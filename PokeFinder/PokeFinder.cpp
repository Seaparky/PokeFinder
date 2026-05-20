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

		//if (i == 4) { break; }
	}

	auto SparkResult = std::find(KantoContainer.begin(), KantoContainer.end(), Sparky::Type::Bug);
	
	std::cout << "Kanto has " << SparkResult->myName << std::endl;


}

