//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#include "load_file_error.h"

load_file_error::load_file_error(const std::string &msg, const std::string &path, const std::string &filename) :
        std::runtime_error{msg}, filename{filename}, path{path} {

}

const std::string &load_file_error::getFilename() const {
    return filename;
}

const std::string &load_file_error::getPath() const {
    return path;
}
