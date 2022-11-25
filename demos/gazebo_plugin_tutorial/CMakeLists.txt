cmake_minimum_required(VERSION 3.5)

##
find_package(gazebo REQUIRED)
message(STATUS ">>>>>Alex: GAZEBO_INCLUDE_DIRS=${GAZEBO_INCLUDE_DIRS} GAZEBO_LIBRARY_DIRS=${GAZEBO_LIBRARY_DIRS}")
include_directories(
    ${GAZEBO_INCLUDE_DIRS}
)
link_directories(
    ${GAZEBO_LIBRARY_DIRS}
)

list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

## 官方例程
add_library(hello_world SHARED src/hello_world.cc)
target_link_libraries(hello_world ${GAZEBO_LIBRARIES})

add_library(model_push SHARED src/model_push.cc)
target_link_libraries(model_push ${GAZEBO_LIBRARIES})

add_library(world_edit SHARED src/world_edit.cc)
target_link_libraries(world_edit ${GAZEBO_LIBRARIES})

add_library(system_gui SHARED src/system_gui.cc)
target_link_libraries(system_gui ${GAZEBO_LIBRARIES})

## Alex
add_library(alex_wheel_speed SHARED src/alex_wheel_speed.cc)
target_link_libraries(alex_wheel_speed ${GAZEBO_LIBRARIES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")