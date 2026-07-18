/*
    Signature Assignment: Binary Data Analyzer

    Group Members:
    Marcus Wiggs
    Malachi Uche
    Eduardo Uribe

    Course: CSC252
	Instructor: Professor Hong Shen
	Date: 07/18/2026
    File: BinaryReader.cpp

    Purpose:
    Creates, writes, and reads binary integer data files.
*/

#include "BinaryReader.h"

#include <cstdlib>
#include <fstream>

void writeBinary(
    const std::string& fileName,
    const int* values,
    int size
)
{
    std::ofstream outputFile(
        fileName,
        std::ios::binary
    );

    if (!outputFile)
    {
        return;
    }

    outputFile.write(
        reinterpret_cast<const char*>(&size),
        sizeof(size)
    );

    outputFile.write(
        reinterpret_cast<const char*>(values),
        sizeof(int) * size
    );
}

void createBinaryFile(
    const std::string& fileName,
    int size
)
{
    if (size <= 0)
    {
        return;
    }

    int* generatedValues = new int[size];

    for (int index = 0; index < size; index++)
    {
        generatedValues[index] = std::rand() % 1000;
    }

    writeBinary(
        fileName,
        generatedValues,
        size
    );

    delete[] generatedValues;
}

BinaryReader::BinaryReader()
    : values(nullptr), size(0)
{
}

BinaryReader::~BinaryReader()
{
    delete[] values;
}

bool BinaryReader::read(const std::string& fileName)
{
    std::ifstream inputFile(
        fileName,
        std::ios::binary
    );

    if (!inputFile)
    {
        return false;
    }

    delete[] values;
    values = nullptr;
    size = 0;

    inputFile.read(
        reinterpret_cast<char*>(&size),
        sizeof(size)
    );

    if (!inputFile || size <= 0)
    {
        size = 0;
        return false;
    }

    values = new int[size];

    inputFile.read(
        reinterpret_cast<char*>(values),
        sizeof(int) * size
    );

    if (!inputFile)
    {
        delete[] values;
        values = nullptr;
        size = 0;
        return false;
    }

    return true;
}

const int* BinaryReader::getValues() const
{
    return values;
}

int BinaryReader::getSize() const
{
    return size;
}