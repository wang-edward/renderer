#pragma once

#include "device.hpp"

#include <string>
#include <vector>

namespace render {

struct PipelineConfigInfo {

};

class Pipeline {
    Device &device;
    VkPipeline graphcisPipeline;
    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;

    static std::vector<char> readFile(const std::string &filepath);
    void createGraphicsPipeline(Device &device, const std::string &vertFilePath, 
                                const std::string &fragFilePath, const PipelineConfigInfo &configInfo);
    void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);

public:
    Pipeline(Device &device, const std::string &vertFilePath, 
             const std::string &fragFilePath, const PipelineConfigInfo &configInfo);
    ~Pipeline() {}
    Pipeline(const Pipeline &other) = delete;
    Pipeline &operator=(const Pipeline &other) = delete;
    static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
};

} // namespace render
