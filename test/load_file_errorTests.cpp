//
// Created by Lorenzo Nuti and Paolo Valcepina on 10/07/17.
//

#include "../load_file_error.h"

#include <gtest/gtest.h>

TEST(load_file_error, Constructor) {
    load_file_error error("msg", "path", "filename");
    ASSERT_STREQ(error.what(), "msg");
    ASSERT_EQ(error.getPath(), "path");
    ASSERT_EQ(error.getFilename(), "filename");
}