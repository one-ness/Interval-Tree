#include <iostream>
#include "Interval.h"
#include "IntervalTree.h"

int main() {
    Interval a(10,20);
    Interval b(20,30);
    Interval c(12,22);
    Interval d(8,12);
    IntervalTree IT;
    IT.insert(a);
    IT.insert(b);
    IT.insert(c);
    IT.insert(d);
    std::cout << IT.remove(c) << std::endl;
    std::cout << IT.root->data << std::endl;
    return 0;
}