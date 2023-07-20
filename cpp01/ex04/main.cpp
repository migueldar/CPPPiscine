#include <iostream>
#include <fstream>

std::string readIstream(std::ifstream& file) {
	std::string ret = "";
	std::string aux; 

	while (!file.eof()) {
		std::getline(file, aux);
		ret.append(aux);
		if (!file.eof())
			ret.append("\n");
	}

	return ret;
}

void writeReplacedText(std::ofstream& file, std::string text, std::string s1, std::string s2) {
	size_t posFound;
	size_t counter = 0;
	size_t s1len = s1.length();

	while (true) {
		posFound = text.find(s1, counter);
		file << text.substr(counter, posFound - counter);
		if (posFound == std::string::npos) 
			break ;
		file << s2;
		counter = posFound + s1len;
	}
}

int ft_sed(char** argv) {
	std::ifstream file;
	std::ofstream fileReplace;
	std::string fileName = argv[1];

	file.open(argv[1], std::ifstream::in);
	if (!file) {
		std::cerr << "Error opening the input file" << std::endl;
		return 1;
	}

	fileReplace.open((fileName + ".replace").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!fileReplace) {
		std::cerr << "Error opening the output file" << std::endl;
		return 1;
	}

	std::string text = readIstream(file);
	file.close();

	writeReplacedText(fileReplace, text, argv[2], argv[3]);
	fileReplace.close();

	return 0;
}

int main(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Exactly three parameters are needed" << std::endl;
		return 1;
	}

	return ft_sed(argv);
}
