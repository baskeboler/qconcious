cmake_minimum_required(VERSION 3.5)

project(qtconcious LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS -Wall)

enable_testing(true)
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

set(Boost_VERBOSE ON)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS date_time system thread filesystem atomic container chrono)
include_directories(${Boost_INCLUDE_DIRS})
find_package(Qt5 COMPONENTS Widgets Charts Network Test REQUIRED)

set(TEST_SOURCES
    benfordtest.cpp
    benfordtest.h)
set(UTILS_SOURCES
    utils/webimagewidget.cpp
    utils/benfordslaw.cpp
    utils/fibonacci.cpp
    )
set(UTILS_HEADERS
    utils/webimagewidget.h
    utils/benfordslaw.h
    utils/fibonacci.h
    utils.h)
set(CONCIOUS_SOURCES
    gameagent.cpp
    gameagent.h
    abstractgame.cpp
    abstractgame.h
    cheater.cpp
    cheater.h
    cooperator.cpp
    cooperator.h
    gameimpl.cpp
    gameimpl.h
    randomagent.cpp
    randomagent.h
    titsfortatsagent.cpp
    titsfortatsagent.h
    agentstrategy.cpp
    agentstrategy.h
    strategygameagent.cpp
    strategygameagent.h
    cheaterstrategy.cpp
    cheaterstrategy.h
    cooperatorstrategy.h
    cooperatorstrategy.cpp
    randomstrategy.h
    randomstrategy.cpp
    strategies.h
    forgivingstrategy.cpp
    forgivingstrategy.h
    ${UTILS_HEADERS}
    states.scxml)

add_library(lconcious SHARED
    ${CONCIOUS_SOURCES} )

add_library(utils SHARED ${UTILS_HEADERS} ${UTILS_SOURCES})
target_link_libraries(utils PRIVATE Qt5::Widgets Qt5::Network ${Boost_LIBRARIES} -ljpeg)
#if(ANDROID)
#    add_library(qtconcious SHARED
#        main.cpp
#        mainwindow.cpp
#        mainwindow.h
#        mainwindow.ui
#        ${CONCIOUS_SOURCES}
#        )
#else()
add_executable(qtconcious
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    #        ${CONCIOUS_SOURCES}
    )
add_executable(mytest
    #        ${CONCIOUS_SOURCES}
    ${TEST_SOURCES})
add_test(NAME mytest COMMAND mytest)
target_link_libraries(mytest PRIVATE lconcious utils Qt5::Widgets Qt5::Test -ljpeg)
#endif()

target_link_libraries(lconcious PRIVATE Qt5::Widgets Qt5::Charts utils -ljpeg)
target_link_libraries(qtconcious PRIVATE Qt5::Widgets Qt5::Charts lconcious utils -ljpeg)
