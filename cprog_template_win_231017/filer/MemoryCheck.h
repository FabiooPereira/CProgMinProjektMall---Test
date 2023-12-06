#ifndef MEMORYCHECK_H
#define MEMORYCHECK_H

#include <memory>

class MemoryCheck
{
public:
    static uint32_t totalFreed;
    static uint32_t totalAllocated;
    static uint32_t CurrentUsage() { return totalAllocated - totalFreed; }
};

void *operator new(size_t size)
{
	totalAllocated += size;
	std::cout << "memory allocated: " << size << std::endl;

	return malloc(size);
}

void operator delete(void *memory)
{
    totalFreed += size;
    std::cout << "memory freed: " << size << std::endl;

    free(memory);
}
#endif