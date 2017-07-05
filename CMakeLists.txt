cmake_minimum_required(VERSION 3.6)
project(Catula)

set(CMAKE_CXX_STANDARD 14)

### Add subdirectory for Google Test
add_subdirectory(test)

set(SOURCE_FILES Background.cpp Background.h Entity.cpp Entity.h
        MainCharacter.cpp MainCharacter.h Star.cpp Star.h Vehicle.cpp Vehicle.h
        Controller.cpp Controller.h Collidable.cpp Collidable.h Debug.h Window.cpp Window.h ModelBase.h Debug.cpp CollidableFactory.cpp CollidableFactory.h Laser.cpp Laser.h GameInfo.cpp GameInfo.h Rocket.cpp Rocket.h ModelMenu.cpp ModelMenu.h ModelGame.cpp ModelGame.h ModelPause.cpp ModelPause.h Audio.cpp Audio.h ModelGameOver.cpp ModelGameOver.h Images.cpp Images.h Fonts.cpp Fonts.h Skull.cpp Skull.h LoadFileError.cpp LoadFileError.h MessageBox.cpp MessageBox.h)
add_executable(Catula main.cpp)

### Add Google Test library
add_library(core ${SOURCE_FILES})
target_link_libraries(Catula core)

### Add SFML library
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Catula ${SFML_LIBRARIES})
endif ()
