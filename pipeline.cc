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

void Pipeline:: createGraphicsPipeline(Device &device, const std::string &vertFilePath, 
                    const std::string &fragFilePath, const PipelineConfigInfo &configInfo) {
    auto vertCode = readFile(vertFilePath);
    auto fragCode = readFile(fragFilePath);
    cout << "Vertex shader code size: " << vertCode.size() << endl;
    cout << "Frag shader code size: " << vertCode.size() << endl;
}


// TODO const?
Pipeline:: Pipeline(Device &device, const std::string &vertFilePath, 
                    const std::string &fragFilePath, const PipelineConfigInfo &configInfo)
                    : device{device} {
    createGraphicsPipeline(device, vertFilePath, fragFilePath, configInfo);
}

void Pipeline:: createShaderModule(const vector<char> &code, VkShaderModule *shaderModule) {
    VkShaderModuleCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = code.size();
    // default allocator ensures worst case alignment requirement
    createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data()); 

    if (vkCreateShaderModule(device.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS) {
        throw runtime_error{"Couldn't create shader module"};
    }
}

PipelineConfigInfo Pipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height) {
    PipelineConfigInfo configInfo{};
    return configInfo;
}

} // namespace render
