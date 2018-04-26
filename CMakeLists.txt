cmake_minimum_required(VERSION 2.8.12)

project(Kkmeans VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(dlib REQUIRED)

find_package(Boost)

include_directories(${Boost_INCLUDE_DIR})

add_executable(kkmeans main.cpp)

add_executable(datagen datagenerator.cpp)

target_link_libraries(kkmeans dlib::dlib)

target_link_libraries(datagen dlib::dlib)

install(TARGETS datagen RUNTIME DESTINATION bin)

install(TARGETS kkmeans RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT ivanbasurman88@yandex.ru)

include(CPack)
