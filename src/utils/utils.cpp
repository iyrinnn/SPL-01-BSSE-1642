#include "utils.h"

int absInt(int x)
{
    return x < 0 ? -x : x;
}

void swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// ----------------- Binary Search -----------------
int binarySearch(const std::vector<int> &vec, int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (vec[mid] == target)
        return mid;
    else if (vec[mid] < target)
        return binarySearch(vec, mid + 1, high, target);
    else
        return binarySearch(vec, low, mid - 1, target);
}

// ----------------- QuickSort -----------------
int partition(std::vector<int> &arr, int st, int end)
{
    int pivot = arr[end];
    int i = st - 1;

    for (int j = st; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swapInt(arr[i], arr[j]);
        }
    }
    swapInt(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(std::vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int piv = partition(arr, st, end);
        quickSort(arr, st, piv - 1);
        quickSort(arr, piv + 1, end);
    }
}

// ----------------- Split -----------------
std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> result;
    std::string temp;

    for (char c : s)
    {
        if (c == delimiter)
        {
            result.push_back(temp);
            temp.clear();
        }
        else
        {
            temp += c;
        }
    }
    result.push_back(temp);
    return result;
}

// ----------------- Stack Implementation -----------------
Stack::Stack(int capacity)
{
    arr.reserve(capacity);
}

void Stack::push(int x)
{
    arr.push_back(x);
}

void Stack::pop()
{
    if (!arr.empty())
        arr.pop_back();
}

int Stack::top()
{
    if (arr.empty())
        return -1;
    return arr.back();
}

bool Stack::isEmpty()
{
    return arr.empty();
}

bool Stack::isFull()
{
    return false; // vector expands dynamically
}

// ----------------- Queue Implementation -----------------
Queue::Queue(int cap)
{
    capacity = cap;
    arr.resize(cap);
    frontIndex = 0;
    rearIndex = -1;
}

void Queue::enqueue(int x)
{
    if (rearIndex == capacity - 1)
        return;
    arr[++rearIndex] = x;
}

void Queue::dequeue()
{
    if (frontIndex > rearIndex)
        return;
    frontIndex++;
}

int Queue::front()
{
    if (frontIndex > rearIndex)
        return -1;
    return arr[frontIndex];
}

bool Queue::isEmpty()
{
    return frontIndex > rearIndex;
}

bool Queue::isFull()
{
    return rearIndex == capacity - 1;
}
