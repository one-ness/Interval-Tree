//
// Created by Keegan Fisher on 11/17/18.
//

#include "IntervalTree.h"
#include <iostream>
void IntervalTree::insert(Interval &input) {
    if(this->root == nullptr) {
        root = new INode(input);
        return;
    }
    INode *insert = new INode(input);
    INode *curr = this->root;
    INode *p = nullptr;
    while(curr) {
        if(curr->max < input.high) curr->max = input.high;
        p = curr;
        if(input.low <= curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if(input.low <= p->data) {
        p->left = insert;
        p->left->p = p;
    } else {
        p->right = insert;
        p->right->p = p;
    }
}

IntervalTree::INode* IntervalTree::minValue(INode *root) {
    if(!root){
        return nullptr;
    }
    INode *curr = root;
    INode *min = curr;
    while(curr) {
        if(curr->data < min->data) {
            min = curr;
        }
        curr = curr->left;
    }
    return min;
}

bool IntervalTree::remove(Interval &input) {
    if(this->root == nullptr) return false;
    INode *curr = this->root;
    while(!(input.low == curr->interval.low && input.high == curr->interval.high)) {
        if(input.low <= curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if(curr) {
        INode* temp;
        if(!curr->left) {
            temp = curr;
            if(curr->p->left == curr) {
                curr->p->left = curr->right;
            } else {
                curr->p->right = curr->right;
            }
        }
        else if(!curr->right) {
            temp = curr;
            if(curr->p->left == curr) {
                curr->p->left = curr->left;
            } else {
                curr->p->right = curr->left;
            }
        }
        else {
            temp = minValue(curr->right);
            curr->data = temp->data;
            curr->interval = temp->interval;
        }
        INode *tracker = temp->p;
        delete(temp);
        while(tracker) {
            if(tracker->right && tracker->left) {
                tracker->max = std::max(tracker->left->max, std::max(tracker->right->max, tracker->interval.high));
            } else if(tracker->left) {
                tracker->max = std::max(tracker->left->max, tracker->interval.high);
            } else if(tracker->right){
                tracker->max = std::max(tracker->right->max, tracker->interval.high);
            } else {
                tracker->max = tracker->interval.high;
            }
            tracker = tracker->p;
        }
        return true;
    }
    return false;
}
