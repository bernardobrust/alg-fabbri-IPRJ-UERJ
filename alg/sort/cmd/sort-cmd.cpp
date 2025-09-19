/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "sort.h"

int main(int argc, char* argv[]) {
    bool use_simple_sort = false;
    if (argc > 1 && strcmp(argv[1], "--simple") == 0) {
        use_simple_sort = true;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }

    std::vector<char*> c_strings;
    for(auto& s : lines) {
        c_strings.push_back(&s[0]);
    }

    if (use_simple_sort) {
        simple_sort(c_strings.data(), c_strings.size());
    } else {
        fast_sort(c_strings.data(), c_strings.size());
    }

    for (size_t i = 0; i < c_strings.size(); ++i) {
        std::cout << c_strings[i] << std::endl;
    }

    return 0;
}
