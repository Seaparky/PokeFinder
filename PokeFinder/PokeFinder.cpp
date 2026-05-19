#include "json.hpp"
#include <fstream>
#include <iostream>
#include <array>
#include <algorithm>
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
		KantoContainer[i].pSourceName = element["FileSource"].get<std::string>();
		json source;
		std::ifstream readStream(KantoContainer[i].pSourceName);
		source = json::parse(readStream);
		readStream.close();
		KantoContainer[i].pSourceData = &source;
		
		i++;
	}

	std::string Search = "Caterpie";

	const auto SparkResult = std::find(KantoContainer.begin(), KantoContainer.end(), Search);

	std::cout << "Kanto has " << SparkResult->pName << std::endl;

	std::cout << KantoContainer[1].pName;

}

