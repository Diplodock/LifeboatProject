cmake_minimum_required(VERSION 3.15)

project(lifeboat LANGUAGES CXX)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/5.14.1/bin") # Any macOS


# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)


if (ANDROID)
  add_library(lifeboat_ui SHARED
    main.cpp
    lifeboat.cpp
    lifeboat.h
    lifeboat.ui
    board.cpp
    board.h
    board.ui
    game.cpp
    game.h
    clickablelable.cpp
    clickablelable.h
    images.qrc
  )
else()
  add_executable(lifeboat_ui
    main.cpp
    lifeboat.cpp
    lifeboat.h
    lifeboat.ui
    board.cpp
    board.h
    board.ui
    clickablelable.cpp
    clickablelable.h
    images.qrc
          )
endif()

target_link_libraries(lifeboat_ui PRIVATE Qt5::Widgets multiplayer)
