# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "RxBouningBox: 2 messages, 0 services")

set(MSG_I_FLAGS "-IRxBouningBox:/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(RxBouningBox_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg" NAME_WE)
add_custom_target(_RxBouningBox_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "RxBouningBox" "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg" ""
)

get_filename_component(_filename "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point_array.msg" NAME_WE)
add_custom_target(_RxBouningBox_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "RxBouningBox" "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point_array.msg" "RxBouningBox/point"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(RxBouningBox
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/RxBouningBox
)
_generate_msg_cpp(RxBouningBox
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point_array.msg"
  "${MSG_I_FLAGS}"
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/RxBouningBox
)

### Generating Services

### Generating Module File
_generate_module_cpp(RxBouningBox
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/RxBouningBox
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(RxBouningBox_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(RxBouningBox_generate_messages RxBouningBox_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg" NAME_WE)
add_dependencies(RxBouningBox_generate_messages_cpp _RxBouningBox_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point_array.msg" NAME_WE)
add_dependencies(RxBouningBox_generate_messages_cpp _RxBouningBox_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(RxBouningBox_gencpp)
add_dependencies(RxBouningBox_gencpp RxBouningBox_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS RxBouningBox_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(RxBouningBox
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/RxBouningBox
)
_generate_msg_eus(RxBouningBox
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point_array.msg"
  "${MSG_I_FLAGS}"
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/RxBouningBox
)

### Generating Services

### Generating Module File
_generate_module_eus(RxBouningBox
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/RxBouningBox
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(RxBouningBox_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(RxBouningBox_generate_messages RxBouningBox_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg" NAME_WE)
add_dependencies(RxBouningBox_generate_messages_eus _RxBouningBox_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point_array.msg" NAME_WE)
add_dependencies(RxBouningBox_generate_messages_eus _RxBouningBox_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(RxBouningBox_geneus)
add_dependencies(RxBouningBox_geneus RxBouningBox_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS RxBouningBox_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(RxBouningBox
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/RxBouningBox
)
_generate_msg_lisp(RxBouningBox
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point_array.msg"
  "${MSG_I_FLAGS}"
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/RxBouningBox
)

### Generating Services

### Generating Module File
_generate_module_lisp(RxBouningBox
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/RxBouningBox
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(RxBouningBox_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(RxBouningBox_generate_messages RxBouningBox_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg" NAME_WE)
add_dependencies(RxBouningBox_generate_messages_lisp _RxBouningBox_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point_array.msg" NAME_WE)
add_dependencies(RxBouningBox_generate_messages_lisp _RxBouningBox_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(RxBouningBox_genlisp)
add_dependencies(RxBouningBox_genlisp RxBouningBox_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS RxBouningBox_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(RxBouningBox
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/RxBouningBox
)
_generate_msg_nodejs(RxBouningBox
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point_array.msg"
  "${MSG_I_FLAGS}"
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/RxBouningBox
)

### Generating Services

### Generating Module File
_generate_module_nodejs(RxBouningBox
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/RxBouningBox
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(RxBouningBox_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(RxBouningBox_generate_messages RxBouningBox_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg" NAME_WE)
add_dependencies(RxBouningBox_generate_messages_nodejs _RxBouningBox_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point_array.msg" NAME_WE)
add_dependencies(RxBouningBox_generate_messages_nodejs _RxBouningBox_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(RxBouningBox_gennodejs)
add_dependencies(RxBouningBox_gennodejs RxBouningBox_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS RxBouningBox_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(RxBouningBox
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/RxBouningBox
)
_generate_msg_py(RxBouningBox
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point_array.msg"
  "${MSG_I_FLAGS}"
  "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/RxBouningBox
)

### Generating Services

### Generating Module File
_generate_module_py(RxBouningBox
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/RxBouningBox
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(RxBouningBox_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(RxBouningBox_generate_messages RxBouningBox_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point.msg" NAME_WE)
add_dependencies(RxBouningBox_generate_messages_py _RxBouningBox_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/xhu-fsac/xhu-v4_ws/src/RxBouningBox/msg/point_array.msg" NAME_WE)
add_dependencies(RxBouningBox_generate_messages_py _RxBouningBox_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(RxBouningBox_genpy)
add_dependencies(RxBouningBox_genpy RxBouningBox_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS RxBouningBox_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/RxBouningBox)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/RxBouningBox
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(RxBouningBox_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/RxBouningBox)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/RxBouningBox
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(RxBouningBox_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/RxBouningBox)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/RxBouningBox
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(RxBouningBox_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/RxBouningBox)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/RxBouningBox
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(RxBouningBox_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/RxBouningBox)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/RxBouningBox\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/RxBouningBox
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(RxBouningBox_generate_messages_py std_msgs_generate_messages_py)
endif()
