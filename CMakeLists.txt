cmake_minimum_required(VERSION 3.6)

project(Kkmeans VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_subdirectory(./dlib dlib_build)
# find_package(dlib)
# find_package(openblas REQUIRED)
find_package(Boost)
include_directories(${Boost_INCLUDE_DIR})

add_executable(kkmeans main.cpp)
add_executable(datagen datagenerator.cpp)

target_link_libraries(kkmeans dlib::dlib openblas)
target_link_libraries(datagen dlib::dlib openblas)

install(TARGETS datagen RUNTIME DESTINATION bin)
install(TARGETS kkmeans RUNTIME DESTINATION bin)
install(FILES kkmeans_ex.txt DESTINATION include)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT ivanbasurman88@yandex.ru)

include(CPack)
