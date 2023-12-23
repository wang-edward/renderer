#pragma once

#include <string>
#include <vector>

namespace render {

class Pipeline {
    static std::vector<char> readFile(const std::string &filepath);
    void createGraphicsPipeline(const std::string &vertFilePath, const std::string &fragFilePath);
public:
    Pipeline(const std::string &vertFilePath, const std::string &fragFilePath);
};

} // namespace render
