#pragma once

class ResizableArray
{
private:
    int *data;
    int capacity;
    int size;

    void resize();

public:
    ResizableArray();
    ~ResizableArray();

    void pushBack(int value);

    int get(int index) const;
    void set(int index, int value);

    int getSize() const;
    int getCapacity() const;

    bool isEmpty() const;
};
