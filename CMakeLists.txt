cmake_minimum_required(VERSION 3.5)

project(UML VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
   main.cpp
   mainwindow.cpp
   mainwindow.h
   mainwindow.ui
   element.h
   element.cpp
   UML/classdiagram.h
   UML/classdiagram.cpp
   UML/umlclassifier.h
   UML/umlclassifier.cpp
   UML/umlclass.h
   UML/umlclass.cpp
   UML/umlattribute.h
   UML/umlattribute.cpp
   UML/umlmessage.h
   UML/umlmessage.cpp
   UML/umloperation.h
   UML/umloperation.cpp
   UML/umlrelation.h
   UML/umlrelation.cpp
   UML/sequencediagram.h
   UML/sequencediagram.cpp
   UML/communicationdiagram.h
   UML/communicationdiagram.cpp
   help.ui
   help.h
   help.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(UML
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET UML APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(UML SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(UML
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(UML PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(UML PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(UML)
endif()
