#include "pipeline.hpp"

#include <fstream>
#include <iostream>

using namespace std;

namespace render {

vector<char> Pipeline:: readFile(const string &filepath) {
    ifstream file{filepath, std::ios::ate | std::ios::binary};
    if (!file.is_open()) {
        throw runtime_error{"failed to open file: " + filepath};
    }
    size_t fileSize = static_cast<size_t>(file.tellg());
    vector<char> buffer(fileSize);
    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();
    return buffer;
}

void Pipeline:: createGraphicsPipeline(const string &vertFilePath, const string &fragFilePath) {
    auto vertCode = readFile(vertFilePath);
    auto fragCode = readFile(fragFilePath);
    cout << "Vertex shader code size: " << vertCode.size() << endl;
    cout << "Frag shader code size: " << vertCode.size() << endl;
}


Pipeline:: Pipeline(const string &vertFilePath, const string &fragFilePath) {
    createGraphicsPipeline(vertFilePath, fragFilePath);
}
} // namespace render
