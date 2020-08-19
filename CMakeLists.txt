cmake_minimum_required(VERSION 2.8) 

project(cheatSheetCpp CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Find OpenCV
# set(OpenCV_STATIC OFF)
# find_package(OpenCV REQUIRED)
# message(STATUS "OpenCV version: ${OpenCV_VERSION}")

## Find Boost
# set(Boost_USE_STATIC_LIBS ON)
# set(Boost_USE_MULTITHREADED ON)
# set(Boost_USE_STATIC_RUNTIME OFF)
# find_package(Boost 1.50 REQUIRED COMPONENTS filesystem program_options)
# message(STATUS "Boost version: ${Boost_VERSION_STRING}")

# if(NOT TARGET Boost::filesystem)
    # add_library(Boost::filesystem IMPORTED INTERFACE)
    # set_property(TARGET Boost::filesystem PROPERTY
        # INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})
    # set_property(TARGET Boost::filesystem PROPERTY
        # INTERFACE_LINK_LIBRARIES ${Boost_LIBRARIES})
# endif()

# if(NOT TARGET Boost::program_options)
    # add_library(Boost::program_options IMPORTED INTERFACE)
    # set_property(TARGET Boost::program_options PROPERTY
        # INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})
    # set_property(TARGET Boost::program_options PROPERTY
        # INTERFACE_LINK_LIBRARIES ${Boost_LIBRARIES})
# endif()

## Project declaration

file(GLOB SOURCES
	"src/include/*.h"
	"src/*.cpp"
)
add_executable(${PROJECT_NAME}
  ${SOURCES})


# target_link_libraries(${PROJECT_NAME}
  # PUBLIC
  # ${OpenCV_LIBS}
  # Boost::filesystem
  # Boost::program_options)

install(TARGETS ${PROJECT_NAME}
  DESTINATION bin)