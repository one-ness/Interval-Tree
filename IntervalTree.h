//
// Created by Keegan Fisher on 11/17/18.
//

#ifndef INTERVALTREE_INTERVALTREE_H
#define INTERVALTREE_INTERVALTREE_H
#include "Interval.h"

class IntervalTree {
public:
    class INode {
    public:
        INode *left;
        INode *right;
        INode *p;
        Interval interval;
        int data;
        int max;
        INode(Interval interval) : interval(interval), data(interval.low), max(interval.high), right(nullptr), left(nullptr), p(nullptr){}
        bool operator==(const INode &rhs){
            return (rhs.interval.low == this->interval.low && rhs.interval.high == this->interval.high);
        }
    };
    INode* root;
    IntervalTree(): root(nullptr){}
    void insert(Interval &input);
    bool remove(Interval &input);
    INode* minValue(INode *root);
};


#endif //INTERVALTREE_INTERVALTREE_H
