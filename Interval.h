#ifndef INTERVALTREE_INTERVAL_H
#define INTERVALTREE_INTERVAL_H

class Interval {
public:
    int low;
    int high;
    Interval(int x, int y) {
        this->low = x;
        this->high = y;
    }
    bool overlap(Interval &other);
};


#endif //INTERVALTREE_INTERVAL_H
