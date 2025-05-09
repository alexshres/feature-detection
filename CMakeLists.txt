cmake_minimum_required(VERSION 3.10)
project(FeatureDetection)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED)

# Including directories
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${OpenCV_INCLUDE_DIRS}
	${EIGEN3_INCLUDE_DIRS}
	${Boost_INCLUDE_DIRS}
)


# Adding source files
file(GLOB SOURCES "src/*.cpp")

# Executable
add_executable(feature_detector ${SOURCES})

# Linking
target_link_libraries(feature_detector
	${OpenCV_LIBS}
	${Boost_LIBRARIES}
)
