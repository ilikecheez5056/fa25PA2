//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        data[size] = idx;
        size++;
        upheap(size - 1, weightArr);
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        int root = data[0];
        data[0] = data[size-1];
        size--;
        downheap(0, weightArr);
        return root;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                //Not totally sure if we're able to use the built in functions, but it autofilled it for me
                // so I'm just going to leave it for now.
                swap(data[parent], data[pos]);
                pos = parent;
            }
            else {
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            // formula for child nodes
            int right = (pos * 2) + 2;
            int left = (pos * 2) + 1;
            int smallest = pos;
            // if the left side is bigger than the parent then set smallest left to smallest
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }
            // if right is bigger than parent then set it as the smallest
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }
            // if it's already the smallest then end loop
            if (pos == smallest) {
                break;
            }
            // if it's still not the smallest then keep going
            swap(data[pos], data[smallest]);
            pos = smallest;
        }
    }
};

#endif