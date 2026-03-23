#include "json.hpp"
#include <fstream>
#include <iostream>
#include <array>
#include <algorithm>
#include <cassert>
#include <complex>
#include <initializer_list>
#include <vector>
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

	std::string Search = "Ivysaur";


	const auto Result = std::find(Kanto["content"].begin(), Kanto["content"].end(), Search);
	const auto result = Kanto["content"].find(Search);	
	const auto SparkResult = std::find(KantoContainer.begin(), KantoContainer.end(), Search);




	std::cout << "Kanto has " << &Result << std::endl;
	std::cout << "Kanto has " << &result << std::endl;
	std::cout << "Kanto has " << SparkResult->pName << std::endl;

	//result.key().c_str();

	std::cout << KantoContainer[1].pName;

}

