cmake_minimum_required(VERSION 3.5)

project(CpuManager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/mainwindow.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Cpu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Core.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Cpu.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Core.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/mainwindow.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Sys.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/IReader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/signalmanager.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/timer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/comboboxhelper.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/signalmanager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/sliderreader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/IReader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/IReader.cpp
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CpuManager
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CpuManager APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CpuManager SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CpuManager
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(CpuManager PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(CpuManager PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.CpuManager)
endif()
set_target_properties(CpuManager PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS CpuManager
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CpuManager)
endif()
