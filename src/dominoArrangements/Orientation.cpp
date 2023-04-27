#include "dominoArrangements.hpp"

#include <string>

namespace dominoArrangements {

std::string to_string(const Orientation & orientation) {
    return orientation == Orientation::HORIZONTAL
        ? "horizontal"
        : "vertical";
}

} // namespace dominoArrangements
