#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

int absInt(int x);
void swapInt(int &a, int &b);
int binarySearch(const std::vector<int> &vec, int low, int high, int target);
void quickSort(std::vector<int> &arr, int st, int end);
std::vector<std::string> split(const std::string &s, char delimiter);

class Stack
{
private:
    std::vector<int> arr;

public:
    Stack(int capacity = 100);
    void push(int x);
    void pop();
    int top();
    bool isEmpty();
    bool isFull();
};

class Queue
{
private:
    std::vector<int> arr;
    int frontIndex;
    int rearIndex;
    int capacity;

public:
    Queue(int capacity = 100);
    void enqueue(int x);
    void dequeue();
    int front();
    bool isEmpty();
    bool isFull();
};

#endif
