find_package(GTest REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${GTEST_INCLUDE_DIRS}
)

add_library(waypoint_follower_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/waypoint_follower_codegen_test.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/rt_nonfinite.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/rtGetNaN.cpp
)

target_compile_definitions(waypoint_follower_lib PRIVATE 
    -DMODEL=waypoint_follower_codegen_test
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DTERMFCN=0
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=1
    -DINTEGER_CODE=0
    -DMT=0
)

add_executable(waypoint_test test_waypoint_generator.cpp)

target_link_libraries(waypoint_test
    waypoint_follower_lib
    ${GTEST_LIBRARIES}
    pthread
)

add_test(NAME waypoint_test COMMAND waypoint_test)

                                                                                                                 
                                                                                                                 
                                                                                                                 
                                                                      
