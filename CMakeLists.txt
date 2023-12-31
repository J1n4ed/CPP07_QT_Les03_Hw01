cmake_minimum_required(VERSION 3.5)

project(CPP07_QT_Les03_Hw01 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Gui)

set(PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/source/mainwindow.ui
    ${CMAKE_SOURCE_DIR}/source/dialog.ui
    ${CMAKE_SOURCE_DIR}/source/about.ui
    ${CMAKE_SOURCE_DIR}/headers/mainwindow.h
    ${CMAKE_SOURCE_DIR}/headers/dialog.h
    ${CMAKE_SOURCE_DIR}/headers/about.h
    ${CMAKE_SOURCE_DIR}/source/main.cpp
    ${CMAKE_SOURCE_DIR}/source/mainwindow.cpp
    ${CMAKE_SOURCE_DIR}/source/dialog.cpp
    ${CMAKE_SOURCE_DIR}/source/about.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CPP07_QT_Les03_Hw01
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CPP07_QT_Les03_Hw01 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CPP07_QT_Les03_Hw01 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CPP07_QT_Les03_Hw01
            ${PROJECT_SOURCES}
        )
    endif()
endif()

file(COPY resource DESTINATION ${CMAKE_BINARY_DIR})

target_link_libraries(CPP07_QT_Les03_Hw01 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Gui)

set_target_properties(CPP07_QT_Les03_Hw01 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CPP07_QT_Les03_Hw01)
endif()
