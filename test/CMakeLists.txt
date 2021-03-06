cmake_minimum_required(VERSION 3.6)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES BackgroundTests.cpp BadgeDeathFixture.cpp
        BadgeDistanceFixture.cpp BadgeFlyFixture.cpp BadgeObstacleFixture.cpp
        BadgeScoreFixture.cpp BadgeSkullFixture.cpp BadgeSpeedFixture.cpp
        BadgeStarSkullFixture.cpp BadgeTests.cpp CollidableTests.cpp
        EntityTests.cpp LaserTests.cpp load_file_errorTests.cpp
        MainCharacterTests.cpp RocketTests.cpp runAllTests.cpp SkullTests.cpp
        StarTests.cpp)
add_executable(runTests ${TEST_SOURCE_FILES})
target_link_libraries(runTests gtest gtest_main core)

### Add SFML library
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(runTests ${SFML_LIBRARIES})
endif ()
