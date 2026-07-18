#pragma once

#include <string>

void writeBinary(
    const std::string& fileName,
    const int* values,
    int size
);

void createBinaryFile(
    const std::string& fileName,
    int size
);

class BinaryReader
{
private:
    int* values;
    int size;

public:
    BinaryReader();
    ~BinaryReader();

    bool read(const std::string& fileName);

    const int* getValues() const;
    int getSize() const;
};