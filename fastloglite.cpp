#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: fastloglite <logfile> <output.csv>\n";
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Cannot open input file\n";
        return 1;
    }

    std::ofstream output(argv[2]);
    if (!output) {
        std::cerr << "Cannot open output file\n";
        return 1;
    }

    long long errorCount = 0;
    long long warningCount = 0;
    std::string line;

    while (std::getline(input, line)) {
        if (line.find("ERROR") != std::string::npos) errorCount++;
        if (line.find("WARNING") != std::string::npos) warningCount++;
    }

    output << "Type,Count\n";
    output << "ERROR," << errorCount << "\n";
    output << "WARNING," << warningCount << "\n";

    return 0;
}
