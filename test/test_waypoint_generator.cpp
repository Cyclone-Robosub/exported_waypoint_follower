#include <gtest/gtest.h>
#include "../src/waypoint_follower_codegen_test.h"

class WaypointFollowerTest : public ::testing::Test {
protected:
    void SetUp() override {
        waypoint_follower.initialize();
    }

    void TearDown() override {
        waypoint_follower.terminate();
    }

    waypoint_follower_codegen_test waypoint_follower;
};

TEST_F(WaypointFollowerTest, CanBeInitialized) {
    SUCCEED(); // Initialization is done in SetUp
}

TEST_F(WaypointFollowerTest, FollowsWaypoint) {
    waypoint_follower_codegen_test::ExtU_waypoint_follower_codege_T inputs;
    inputs.In1[0] = 0.0; // x position
    inputs.In1[1] = 0.0; // y position
    inputs.In1[2] = 0.0; // z position
    inputs.In1[3] = 0.0; // roll
    inputs.In1[4] = 0.0; // pitch
    inputs.In1[5] = 0.0; // yaw
    
    waypoint_follower.setExternalInputs(&inputs);
    
    waypoint_follower.step();
    
    const waypoint_follower_codegen_test::ExtY_waypoint_follower_codege_T& outputs = 
        waypoint_follower.getExternalOutputs();
    
    for (int i = 0; i < 6; i++) {
        EXPECT_FALSE(std::isnan(outputs.Out1[i]));
        EXPECT_FALSE(std::isinf(outputs.Out1[i]));
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
                                                                                                                                                                                        
          
