cmake_minimum_required(VERSION 3.5)

project(qtconcious LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
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

find_package(Qt5 COMPONENTS Widgets Charts Network Test REQUIRED)

set(TEST_SOURCES
    benfordtest.cpp
    benfordtest.h)

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
    utils/webimagewidget.h
    utils/webimagewidget.cpp
    utils/benfordslaw.cpp
    utils/benfordslaw.h
    utils.h
    states.scxml)

add_library(lconcious SHARED
    ${CONCIOUS_SOURCES} )
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
target_link_libraries(mytest PRIVATE lconcious Qt5::Test)
#endif()

target_link_libraries(lconcious PRIVATE Qt5::Widgets Qt5::Charts Qt5::Network)
target_link_libraries(qtconcious PRIVATE Qt5::Widgets Qt5::Charts lconcious)
