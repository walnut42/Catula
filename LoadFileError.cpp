//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include "LoadFileError.h"

LoadFileError::LoadFileError(const std::string &msg, const std::string &path, const std::string &filename) :
        std::runtime_error{msg}, filename{filename}, path{path} {

}

const std::string &LoadFileError::getFilename() const {
    return filename;
}

const std::string &LoadFileError::getPath() const {
    return path;
}
