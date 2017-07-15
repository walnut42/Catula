//
// Created by Lorenzo Nuti and Paolo Valcepina on 12/07/17.
//

#ifndef CATULA_TOOLS_H
#define CATULA_TOOLS_H

#include <iomanip>
#include <fstream>


template<typename T>
void readBinary(std::fstream &stream, T &value) {
    stream.read(reinterpret_cast<char *>(&value), sizeof value);
}

template<typename T>
void writeBinary(std::fstream &stream, const T &value) {
    stream.write(reinterpret_cast<const char *>(&value), sizeof value);
}

template<typename T>
std::string toString(const T &value, int precision = 0) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(precision) << value;
    return stream.str();
}


#endif //CATULA_TOOLS_H
