###########################################################################
# CMakeLists.txt generated for component waypoint_follower_codegen_test
# Product type: executable
###########################################################################
cmake_minimum_required(VERSION 3.12)
project(waypoint_follower_codegen_test)

# Propagate the CMAKE_EXPORT_COMPILE_COMMANDS variable from the 
# environment if it is defined as an environment variable, but not as a 
# CMake variable. This is to work around a bug in CMake 3.19 when the 
# "NMake Makefiles" generator is selected.
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


# Set directory properties.
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT waypoint_follower_codegen_test)

###########################################################################
## Path variables
###########################################################################
# Derive an absolute path to the code generation anchor folder.
get_filename_component(START_DIR .. ABSOLUTE)

# Special directories defined by using CACHE variables can be overridden 
# by setting the variable from the command line, e.g.,
# 
# 	cmake . -DMATLAB_ROOT=/path/to/another/matlab/root
set(MATLAB_ROOT C:/Program\ Files/MATLAB/R2024a CACHE PATH "")

# Additional variables that are defined conditionally.
if("${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()

###########################################################################
## System Libraries
###########################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES} ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

###########################################################################
## Target definition and commands
###########################################################################

# Definition of target "waypoint_follower_codegen_test".
add_executable(waypoint_follower_codegen_test  ${START_DIR}/waypoint_follower_codegen_test_ert_rtw/ert_main.cpp
    ${START_DIR}/waypoint_follower_codegen_test_ert_rtw/rtGetNaN.cpp
    ${START_DIR}/waypoint_follower_codegen_test_ert_rtw/rt_nonfinite.cpp
    ${START_DIR}/waypoint_follower_codegen_test_ert_rtw/waypoint_follower_codegen_test.cpp)

# Set properties for target "waypoint_follower_codegen_test".
set_target_properties(waypoint_follower_codegen_test PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    RUNTIME_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    LIBRARY_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>"
    ARCHIVE_OUTPUT_DIRECTORY "${BINARY_START_DIR}/./$<0:>")

# Specify language features required for target 
# "waypoint_follower_codegen_test".
target_compile_features(waypoint_follower_codegen_test PUBLIC cxx_std_11)

# Specify compiler preprocessor definitions for target 
# "waypoint_follower_codegen_test".
target_compile_definitions(waypoint_follower_codegen_test PRIVATE -DMODEL=waypoint_follower_codegen_test
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DTERMFCN=1
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=1
    -DINTEGER_CODE=0
    -DMT=0)

# Specify include directories for target "waypoint_follower_codegen_test".
target_include_directories(waypoint_follower_codegen_test PRIVATE ${START_DIR}
    ${START_DIR}/waypoint_follower_codegen_test_ert_rtw
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common
    ${MATLAB_ROOT}/rtw/c/ert)

# Specify library link dependencies for target 
# "waypoint_follower_codegen_test". CMake generator expressions are used 
# to create a CMakeLists.txt file that supports multiple platforms with 
# differently named system library dependencies.
target_link_libraries(waypoint_follower_codegen_test PRIVATE $<$<BOOL:${FOUND_LIBM}>:m>
    $<$<BOOL:${WIN32}>:kernel32>
    $<$<BOOL:${WIN32}>:ws2_32>
    $<$<BOOL:${WIN32}>:mswsock>
    $<$<BOOL:${WIN32}>:advapi32>)

# Extract DWARF debug symbols into a separate file when building 
# executable programs for Apple platforms.
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:waypoint_follower_codegen_test>;--flat,"
                "true"
        >)
    add_custom_command(TARGET waypoint_follower_codegen_test
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS waypoint_follower_codegen_test.dwarf)
endif()


###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET waypoint_follower_codegen_test POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:waypoint_follower_codegen_test>")

###########################################################################
## Call toolchain hook function if defined
###########################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(waypoint_follower_codegen_test)
endif()
