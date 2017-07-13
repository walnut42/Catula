cmake_minimum_required(VERSION 3.6)
project(Catula)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

### Add subdirectory for Google Test
add_subdirectory(test)

set(SOURCE_FILES Audio.cpp Audio.h Background.cpp Background.h Badge.cpp
        Badge.h BadgeDeath.cpp BadgeDeath.cpp BadgeDeath.h BadgeDeath.h
        BadgeDistance.cpp BadgeDistance.h BadgeFly.cpp BadgeFly.h BadgeInfo.cpp
        BadgeInfo.h BadgeObstacle.cpp BadgeObstacle.h BadgeScore.cpp
        BadgeScore.h BadgeSkull.cpp BadgeSkull.h BadgesManager.cpp
        BadgesManager.h BadgeSpeed.cpp BadgeSpeed.h BadgeStarSkull.cpp
        BadgeStarSkull.h Collidable.cpp CollidableFactory.cpp
        CollidableFactory.h Collidable.h Controller.cpp Controller.h Entity.cpp
        Entity.h Fonts.cpp Fonts.h GameInfo.cpp GameInfo.h Images.cpp Images.h
        Laser.cpp Laser.h load_file_error.cpp load_file_error.h
        MainCharacter.cpp MainCharacter.h main.cpp MessageBox.cpp MessageBox.h
        ModelBadge.cpp ModelBadge.h ModelBase.h ModelGame.cpp ModelGame.h
        ModelGameOver.cpp ModelGameOver.h ModelMenu.cpp ModelMenu.h
        ModelPause.cpp ModelPause.h Rocket.cpp Rocket.h Skull.cpp Skull.h
        Star.cpp Star.h Tools.h Window.cpp Window.h)

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
