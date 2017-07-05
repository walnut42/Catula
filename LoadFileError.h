//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#ifndef CATULA_LOADFILEEXCEPTION_H
#define CATULA_LOADFILEEXCEPTION_H

#include <stdexcept>

class LoadFileError : public std::runtime_error {
public:
    LoadFileError(const std::string &msg, const std::string &path, const std::string &filename);

    const std::string &getFilename() const;

    const std::string &getPath() const;

private:
    std::string filename;
    std::string path;
};


#endif //CATULA_LOADFILEEXCEPTION_H
