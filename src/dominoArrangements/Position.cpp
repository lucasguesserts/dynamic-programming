#include "dominoArrangements.hpp"

#include <string>

namespace dominoArrangements {

std::string Position::to_string() const {
    return "{" + std::to_string(this->row) + ", " + std::to_string(this->column) + "}";
}

} // namespace dominoArrangements
