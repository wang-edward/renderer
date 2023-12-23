#include "first_app.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>


using namespace std;

int main() {
    render::FirstApp app{};

    try {
        app.run();
    } catch (const exception &e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
