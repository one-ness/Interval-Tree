#include "Interval.h"

bool Interval::overlap(Interval &other) {
    return (this->low <= other.high && other.low <= this->high);
}