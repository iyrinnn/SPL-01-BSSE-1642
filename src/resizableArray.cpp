#include "resizableArray.h"
using namespace std;

ResizableArray::ResizableArray()
{
    capacity = 4;
    size = 0;
    data = new int[capacity];
}

ResizableArray::~ResizableArray()
{
    delete[] data;
}

void ResizableArray::resize()
{
    capacity *= 2;
    int *newData = new int[capacity];
    for (int i = 0; i < size; ++i)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

void ResizableArray::pushBack(int value)
{
    if (size >= capacity)
    {
        resize();
    }
    data[size++] = value;
}

int ResizableArray::get(int index) const
{
    if (index < 0 || index >= size)
    {
        return -1;
    }
    return data[index];
}

void ResizableArray::set(int index, int value)
{
    if (index >= 0 && index < size)
    {
        data[index] = value;
    }
}

int ResizableArray::getSize() const
{
    return size;
}

int ResizableArray::getCapacity() const
{
    return capacity;
}

bool ResizableArray::isEmpty() const
{
    return size == 0;
}
