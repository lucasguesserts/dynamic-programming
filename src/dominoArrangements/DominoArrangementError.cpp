#include "dominoArrangements.hpp"

#include <stdexcept>

namespace dominoArrangements {

DominoArrangementError::DominoArrangementError(std::string s)
: std::runtime_error(s)
{}

}
