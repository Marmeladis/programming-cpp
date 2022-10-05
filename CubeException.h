#pragma once
#ifndef LAB4_CUBEEXCEPTION_H
#define LAB8_CUBEEXCEPTION_H
#include <exception>

class BasicException : public std::exception {
public:
    BasicException(const std::string& msg = "Exception!") {
        std::cerr << msg;
    }
};

class CentersException : BasicException {
public:
    CentersException() :BasicException("Incorrect placement of the cube centers!\n") {}
};

class ColorsException :BasicException {
public:
    ColorsException() :BasicException("Incorrect color distribution\n") {}
};

class CountColorsException :BasicException {
public:
    CountColorsException() :BasicException("Invalid number of colors!\n") {}
};
#endif
