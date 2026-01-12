using namespace std;
#include "../../include/utils/utils.h"

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

int binarySearch(const vector<int> &vec, int low, int high, int target)
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

int partition(vector<int> &arr, int st, int end)
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

void quickSort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int piv = partition(arr, st, end);
        quickSort(arr, st, piv - 1);
        quickSort(arr, piv + 1, end);
    }
}

int partitionD(vector<double> &arr, int st, int end)
{
    double pivot = arr[end];
    int i = st - 1;

    for (int j = st; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(vector<double> &arr, int st, int end)
{
    if (st < end)
    {
        int piv = partitionD(arr, st, end);
        quickSort(arr, st, piv - 1);
        quickSort(arr, piv + 1, end);
    }
}

int partitionPair(vector<pair<double, int>> &arr, int st, int end)
{
    double pivot = arr[end].first;
    int i = st - 1;

    for (int j = st; j < end; j++)
    {
        if (arr[j].first < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(vector<pair<double, int>> &arr, int st, int end)
{
    if (st < end)
    {
        int piv = partitionPair(arr, st, end);
        quickSort(arr, st, piv - 1);
        quickSort(arr, piv + 1, end);
    }
}

vector<string> split(const string &s, char delimiter)
{
    vector<string> result;
    string temp;

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
    return false;
}

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
