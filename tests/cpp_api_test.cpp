#include "../build/plain_text_extractor.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	std::string file_name;
	bool verbose = false;
	if (argc == 2)
		file_name = argv[1];
	else if (argc == 3 && std::string(argv[1]) == "--verbose")
	{
		verbose = true;
		file_name = argv[2];
	}
	else
		return 1;
	PlainTextExtractor extractor;
	extractor.setVerboseLogging(verbose);
	std::string text;
	if (!extractor.processFile(file_name, text))
		return 1;
	std::cout << text << std::endl;
	return 0;
}
