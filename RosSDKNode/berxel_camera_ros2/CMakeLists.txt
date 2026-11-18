cmake_minimum_required(VERSION 3.5)
project(berxel_camera_ros2)

option(INSTALL_UDEV_RULES "Install udev rule for Berxel cameras" ON)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  set(CMAKE_CXX_FLAGS "-O2 -fPIE -fPIC -D_FORTIFY_SOURCE=2 -fstack-protector -Wformat -Wformat-security -Wall ${CMAKE_CXX_FLAGS}")
else()
  set(CMAKE_CXX_FLAGS "-O2 -fPIE -fPIC -D_FORTIFY_SOURCE=2 -fstack-protector -Wall ${CMAKE_CXX_FLAGS}")
endif()

find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(image_transport REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2 REQUIRED)

include_directories(
  include
)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  if(DEFINED ENV{BERXEL_SDK_LIBRARY})
    set(BERXEL_SDK_INCLUDE "$ENV{BERXEL_SDK_LIBRARY}/Include")
    set(BERXEL_SDK_LIB "$ENV{BERXEL_SDK_LIBRARY}/libs")
  elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../../Include")
    # workspace layout: the SDK tree lives next to RosSDKNode/
    set(BERXEL_SDK_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/../../Include")
    set(BERXEL_SDK_LIB "${CMAKE_CURRENT_SOURCE_DIR}/../../libs")
  else()
    # debianized source tree: bloom packs only this ROS package dir, so the SDK
    # is vendored into <pkg>/sdk (tools/scripts/vendor.d/berxel_camera_ros2.sh)
    set(BERXEL_SDK_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/sdk/Include")
    set(BERXEL_SDK_LIB "${CMAKE_CURRENT_SOURCE_DIR}/sdk/libs")
  endif()
else()
  set(BERXEL_SDK_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")
  set(BERXEL_SDK_LIB "${CMAKE_CURRENT_SOURCE_DIR}/libs")
endif()

include_directories(${BERXEL_SDK_INCLUDE})

add_executable(${PROJECT_NAME}
  include/berxel_camera_ros2_driver.h
  src/berxel_camera_ros2_driver.cpp
  src/berxel_camera_ros2_node.cpp
)

# libBerxelHawk.so needs libBerxelInterface.so; relative LINK_DIRECTORIES fails in cross-build
target_link_directories(${PROJECT_NAME} PRIVATE "${BERXEL_SDK_LIB}")
target_link_options(${PROJECT_NAME} PRIVATE "-Wl,-rpath-link,${BERXEL_SDK_LIB}")
target_link_libraries(${PROJECT_NAME}
  BerxelHawk
  BerxelInterface
  pthread
  dl
)
set_target_properties(${PROJECT_NAME} PROPERTIES
  BUILD_RPATH "${BERXEL_SDK_LIB}"
  INSTALL_RPATH "$ORIGIN/.."
)

ament_target_dependencies(${PROJECT_NAME}
  image_transport
  rclcpp
  std_msgs
  sensor_msgs
  tf2
  tf2_ros
)

install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include
)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  if(DEFINED ENV{BERXEL_SDK_LIBRARY})
      file(GLOB_RECURSE BERXEL_SHARED_LIBS ${BERXEL_SDK_LIB}/*)
      file(GLOB_RECURSE BERXEL_INCLUDE ${BERXEL_SDK_INCLUDE}/*.h)
      install(FILES ${BERXEL_SHARED_LIBS} DESTINATION lib)
      install(FILES ${BERXEL_INCLUDE} DESTINATION include)
  else()
      file(GLOB_RECURSE BERXEL_SHARED_LIBS ${BERXEL_SDK_LIB}/*)
      file(GLOB_RECURSE BERXEL_INCLUDE ${BERXEL_SDK_INCLUDE}/*.h)
      install(FILES ${BERXEL_SHARED_LIBS} DESTINATION lib)
      install(FILES ${BERXEL_INCLUDE} DESTINATION include)
  endif()
else()
  file(GLOB_RECURSE BERXEL_SHARED_LIBS libs/*)
  # file(GLOB_RECURSE BERXEL_INCLUDE Include/*.h)
  install(FILES ${BERXEL_SHARED_LIBS} DESTINATION lib/${PROJECT_NAME})
  # install(FILES ${BERXEL_INCLUDE} DESTINATION include)
endif()

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}/
)

install(DIRECTORY
  rviz
  DESTINATION share/${PROJECT_NAME}/
)

if(INSTALL_UDEV_RULES)
  # Install into package share so users can manually copy with sudo if desired
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/99-berxel-camera.rules
          DESTINATION share/${PROJECT_NAME}/udev)
endif()
if(DEFINED ENV{BUILDING_PACKAGE})
  # Install udev rules
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/scripts/99-berxel-camera.rules
          DESTINATION /etc/udev/rules.d)
endif()

ament_package()


