//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: waypoint_follower_codegen_test.h
//
// Code generated for Simulink model 'waypoint_follower_codegen_test'.
//
// Model version                  : 1.1
// Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
// C/C++ source code generated on : Mon May 19 20:02:00 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef waypoint_follower_codegen_test_h_
#define waypoint_follower_codegen_test_h_
#include <cmath>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "waypoint_follower_codegen_test_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model waypoint_follower_codegen_test
class waypoint_follower_codegen_test final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_waypoint_follower_codegen__T {
    real_T current_index_data_store;   // '<S1>/Data Store Memory'
    real_T intermediate_waypoint[3];   // '<S1>/Data Store Memory1'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_waypoint_follower_codege_T {
    real_T In1[6];                     // '<Root>/In1'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_waypoint_follower_codege_T {
    real_T Out1[6];                    // '<Root>/Out1'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_waypoint_follower_co_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  waypoint_follower_codegen_test(waypoint_follower_codegen_test const&) = delete;

  // Assignment Operator
  waypoint_follower_codegen_test& operator= (waypoint_follower_codegen_test
    const&) & = delete;

  // Move Constructor
  waypoint_follower_codegen_test(waypoint_follower_codegen_test &&) = delete;

  // Move Assignment Operator
  waypoint_follower_codegen_test& operator= (waypoint_follower_codegen_test &&) =
    delete;

  // Real-Time Model get method
  waypoint_follower_codegen_test::RT_MODEL_waypoint_follower_co_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_waypoint_follower_codege_T
    *pExtU_waypoint_follower_codege_T)
  {
    waypoint_follower_codegen_tes_U = *pExtU_waypoint_follower_codege_T;
  }

  // Root outports get method
  const ExtY_waypoint_follower_codege_T &getExternalOutputs() const
  {
    return waypoint_follower_codegen_tes_Y;
  }

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  waypoint_follower_codegen_test();

  // Destructor
  ~waypoint_follower_codegen_test();

  // private data and function members
 private:
  // External inputs
  ExtU_waypoint_follower_codege_T waypoint_follower_codegen_tes_U;

  // External outputs
  ExtY_waypoint_follower_codege_T waypoint_follower_codegen_tes_Y;

  // Block states
  DW_waypoint_follower_codegen__T waypoint_follower_codegen_te_DW;

  // private member function(s) for subsystem '<Root>'
  real_T waypoint_follower_codegen__norm(const real_T x[3]);

  // Real-Time Model
  RT_MODEL_waypoint_follower_co_T waypoint_follower_codegen_te_M;
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'waypoint_follower_codegen_test'
//  '<S1>'   : 'waypoint_follower_codegen_test/Waypoint Follower'
//  '<S2>'   : 'waypoint_follower_codegen_test/Waypoint Follower/Desired State Generator'

#endif                                 // waypoint_follower_codegen_test_h_

//
// File trailer for generated code.
//
// [EOF]
//
