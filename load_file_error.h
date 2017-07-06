//
// Created by Lorenzo Nuti and Paolo Valcepina on 02/07/17.
//

#ifndef CATULA_LOADFILEEXCEPTION_H
#define CATULA_LOADFILEEXCEPTION_H

#include <stdexcept>

class load_file_error : public std::runtime_error {
public:
    load_file_error(const std::string &msg, const std::string &path, const std::string &filename);

    const std::string &getFilename() const;

    const std::string &getPath() const;

private:
    std::string filename;
    std::string path;
};


#endif //CATULA_LOADFILEEXCEPTION_H
