cmake_minimum_required(VERSION 3.5)
project(warehouse_robot_controller_pkg)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(gazebo_msgs REQUIRED)

set(dependencies
  rclcpp
  std_msgs
  geometry_msgs
  nav_msgs
  sensor_msgs
  gazebo_msgs
)
include_directories(
  include
)

add_executable(robot_estimator src/robot_estimator.cpp)
ament_target_dependencies(robot_estimator ${dependencies})
add_executable(robot_controller src/robot_controller.cpp)
ament_target_dependencies(robot_controller ${dependencies})

install(TARGETS
  robot_estimator
  robot_controller
  DESTINATION lib/${PROJECT_NAME}
)
install(DIRECTORY
  include/ 
  DESTINATION
  include/${PROJECT_NAME}
)
# 将launch文件夹复制到安装目录
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
