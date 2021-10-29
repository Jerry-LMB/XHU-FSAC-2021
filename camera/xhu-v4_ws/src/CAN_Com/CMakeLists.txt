cmake_minimum_required(VERSION 2.8.3)
project(CAN_com)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  tf
  geometry_msgs	
  )

include_directories(
  include
	${catkin_INCLUDE_DIRS} 
  )

catkin_package(
  CATKIN_DEPENDS 
  roscpp rospy 
  std_msgs 
  INCLUDE_DIRS include
  )

# add_executable
add_executable(canalystii_ros_node 
  src/canalystii_ros_node.cpp 
  src/canalystii_ros.cpp
  ) 

 
#add_executable(canalystii_ros_node src/canalystii_ros_node.cpp  src/canalystii_ros.cpp) 
add_dependencies(canalystii_ros_node 
${catkin_EXPORTED_TARGETS}

  )
target_link_libraries(canalystii_ros_node  
  ${PROJECT_SOURCE_DIR}/lib/libcanalystii_std_msgs_74e.so 
  ${PROJECT_SOURCE_DIR}/lib/libcontrolcan.so  
  ${catkin_LIBRARIES}
  )

#################
##   Install   ##
#################

## Mark executables and/or libraries for installation
install(TARGETS    canalystii_ros_node  
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# Install headers
install(DIRECTORY include/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)

# Install launch files
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
)
# Install lib files
install(DIRECTORY lib/
  DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

