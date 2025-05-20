//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: waypoint_follower_codegen_test.cpp
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
#include "waypoint_follower_codegen_test.h"
#include "rtwtypes.h"
#include <emmintrin.h>
#include <cmath>
#include "waypoint_follower_codegen_test_private.h"
#include "cmath"
#include "rt_defines.h"

// Function for MATLAB Function: '<S1>/Desired State Generator'
real_T waypoint_follower_codegen_test::waypoint_follower_codegen__norm(const
  real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = std::abs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = std::abs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = std::abs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * std::sqrt(y);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = std::atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

// Model step function
void waypoint_follower_codegen_test::step()
{
  __m128d tmp;
  __m128d tmp_0;
  __m128d tmp_1;
  real_T a[9];
  real_T r_b2iwp_e[3];
  real_T r_b2wp_e[3];
  real_T tmp_2[2];
  real_T R_int_wp;
  real_T R_wp;
  real_T a_tmp;
  real_T a_tmp_0;
  real_T r_b2wp_e_0;
  real_T r_b2wp_e_1;
  real_T rtb_current_waypoint_0;
  real_T rtb_current_waypoint_1;
  int32_T i;

  // MATLAB Function: '<S1>/Desired State Generator' incorporates:
  //   Constant: '<S1>/List of Waypoints'
  //   DataStoreWrite: '<S1>/Data Store Write'
  //   DataStoreWrite: '<S1>/Data Store Write1'
  //   Inport: '<Root>/In1'

  _mm_storeu_pd(&tmp_2[0], _mm_sub_pd(_mm_set_pd
    (waypoint_follower_codegen_te_DW.intermediate_waypoint[0], 0.0), _mm_set1_pd
    (waypoint_follower_codegen_tes_U.In1[0])));
  r_b2wp_e[0] = tmp_2[0];
  r_b2iwp_e[0] = tmp_2[1];
  _mm_storeu_pd(&tmp_2[0], _mm_sub_pd(_mm_set_pd
    (waypoint_follower_codegen_te_DW.intermediate_waypoint[1], 0.0), _mm_set1_pd
    (waypoint_follower_codegen_tes_U.In1[1])));
  r_b2wp_e[1] = tmp_2[0];
  r_b2iwp_e[1] = tmp_2[1];
  _mm_storeu_pd(&tmp_2[0], _mm_sub_pd(_mm_set_pd
    (waypoint_follower_codegen_te_DW.intermediate_waypoint[2], 0.0), _mm_set1_pd
    (waypoint_follower_codegen_tes_U.In1[2])));
  r_b2wp_e[2] = tmp_2[0];
  r_b2iwp_e[2] = tmp_2[1];
  R_wp = waypoint_follower_codegen__norm(r_b2wp_e);
  R_int_wp = waypoint_follower_codegen__norm(r_b2iwp_e);
  if (R_wp <= 0.1) {
    if (waypoint_follower_codegen_te_DW.current_index_data_store < 1.0) {
      waypoint_follower_codegen_te_DW.current_index_data_store++;
    } else {
      waypoint_follower_codegen_te_DW.current_index_data_store = 1.0;
    }

    _mm_storeu_pd(&r_b2wp_e[0], _mm_sub_pd(_mm_set1_pd(0.0), _mm_loadu_pd
      (&waypoint_follower_codegen_tes_U.In1[0])));
    r_b2wp_e[2] = 0.0 - waypoint_follower_codegen_tes_U.In1[2];
    R_wp = waypoint_follower_codegen__norm(r_b2wp_e);
  }

  if ((R_wp > 1.0) && (R_int_wp > 1.0)) {
    R_int_wp = r_b2wp_e[0] / R_wp + waypoint_follower_codegen_tes_U.In1[0];
    waypoint_follower_codegen_te_DW.intermediate_waypoint[0] = R_int_wp;
    r_b2iwp_e[0] = R_int_wp - waypoint_follower_codegen_tes_U.In1[0];
    R_int_wp = r_b2wp_e[1] / R_wp + waypoint_follower_codegen_tes_U.In1[1];
    waypoint_follower_codegen_te_DW.intermediate_waypoint[1] = R_int_wp;
    r_b2iwp_e[1] = R_int_wp - waypoint_follower_codegen_tes_U.In1[1];
    R_int_wp = r_b2wp_e[2] / R_wp + waypoint_follower_codegen_tes_U.In1[2];
    waypoint_follower_codegen_te_DW.intermediate_waypoint[2] = R_int_wp;
    r_b2iwp_e[2] = R_int_wp - waypoint_follower_codegen_tes_U.In1[2];
  } else if ((!(R_wp > 1.0)) || (!(R_int_wp <= 1.0)) || (!(R_int_wp > 0.1))) {
    if ((R_wp > 1.0) && (R_int_wp <= 0.1)) {
      tmp_1 = _mm_add_pd(_mm_div_pd(_mm_loadu_pd(&r_b2wp_e[0]), _mm_set1_pd(R_wp)),
                         _mm_loadu_pd(&waypoint_follower_codegen_tes_U.In1[0]));
      _mm_storeu_pd(&waypoint_follower_codegen_te_DW.intermediate_waypoint[0],
                    tmp_1);
      waypoint_follower_codegen_te_DW.intermediate_waypoint[2] = r_b2wp_e[2] /
        R_wp + waypoint_follower_codegen_tes_U.In1[2];
    } else {
      waypoint_follower_codegen_te_DW.intermediate_waypoint[0] = 0.0;
      waypoint_follower_codegen_te_DW.intermediate_waypoint[1] = 0.0;
      waypoint_follower_codegen_te_DW.intermediate_waypoint[2] = 0.0;
    }
  }

  R_wp = std::cos(waypoint_follower_codegen_tes_U.In1[3]);
  R_int_wp = std::sin(waypoint_follower_codegen_tes_U.In1[3]);
  r_b2wp_e_0 = std::cos(waypoint_follower_codegen_tes_U.In1[4]);
  rtb_current_waypoint_0 = std::sin(waypoint_follower_codegen_tes_U.In1[4]);
  r_b2wp_e_1 = std::cos(waypoint_follower_codegen_tes_U.In1[5]);
  rtb_current_waypoint_1 = std::sin(waypoint_follower_codegen_tes_U.In1[5]);
  a[0] = R_wp * r_b2wp_e_0;
  a_tmp = rtb_current_waypoint_0 * rtb_current_waypoint_1;
  a[3] = a_tmp * R_wp - R_int_wp * r_b2wp_e_1;
  a_tmp_0 = rtb_current_waypoint_0 * r_b2wp_e_1;
  a[6] = a_tmp_0 * R_wp + R_int_wp * rtb_current_waypoint_1;
  a[1] = R_int_wp * r_b2wp_e_0;
  a[4] = a_tmp * R_int_wp + R_wp * r_b2wp_e_1;
  a[7] = a_tmp_0 * R_int_wp - R_wp * rtb_current_waypoint_1;
  a[2] = -rtb_current_waypoint_0;
  a[5] = r_b2wp_e_0 * rtb_current_waypoint_1;
  a[8] = r_b2wp_e_0 * r_b2wp_e_1;
  R_wp = r_b2iwp_e[1];
  R_int_wp = r_b2iwp_e[0];
  r_b2wp_e_0 = r_b2iwp_e[2];
  for (i = 0; i <= 0; i += 2) {
    tmp_1 = _mm_loadu_pd(&a[i + 3]);
    tmp = _mm_loadu_pd(&a[i]);
    tmp_0 = _mm_loadu_pd(&a[i + 6]);
    _mm_storeu_pd(&r_b2wp_e[i], _mm_add_pd(_mm_add_pd(_mm_mul_pd(tmp_1,
      _mm_set1_pd(R_wp)), _mm_mul_pd(tmp, _mm_set1_pd(R_int_wp))), _mm_mul_pd
      (tmp_0, _mm_set1_pd(r_b2wp_e_0))));
  }

  for (i = 2; i < 3; i++) {
    r_b2wp_e[i] = (a[i + 3] * R_wp + a[i] * R_int_wp) + a[i + 6] * r_b2wp_e_0;
  }

  R_wp = rt_atan2d_snf(r_b2wp_e[0], r_b2wp_e[1]);
  if (R_wp > 3.1415926535897931) {
    R_wp -= 6.2831853071795862;
  }

  // Outport: '<Root>/Out1' incorporates:
  //   DataStoreWrite: '<S1>/Data Store Write1'
  //   MATLAB Function: '<S1>/Desired State Generator'

  waypoint_follower_codegen_tes_Y.Out1[0] =
    waypoint_follower_codegen_te_DW.intermediate_waypoint[0];
  waypoint_follower_codegen_tes_Y.Out1[1] =
    waypoint_follower_codegen_te_DW.intermediate_waypoint[1];
  waypoint_follower_codegen_tes_Y.Out1[2] =
    waypoint_follower_codegen_te_DW.intermediate_waypoint[2];
  waypoint_follower_codegen_tes_Y.Out1[3] = 0.0;
  waypoint_follower_codegen_tes_Y.Out1[4] = 0.0;
  waypoint_follower_codegen_tes_Y.Out1[5] = R_wp;
}

// Model initialize function
void waypoint_follower_codegen_test::initialize()
{
  // Start for DataStoreMemory: '<S1>/Data Store Memory'
  waypoint_follower_codegen_te_DW.current_index_data_store = 1.0;

  // Start for DataStoreMemory: '<S1>/Data Store Memory1'
  waypoint_follower_codegen_te_DW.intermediate_waypoint[0] = 9999.0;
  waypoint_follower_codegen_te_DW.intermediate_waypoint[1] = 9999.0;
  waypoint_follower_codegen_te_DW.intermediate_waypoint[2] = 9999.0;
}

// Model terminate function
void waypoint_follower_codegen_test::terminate()
{
  // (no terminate code required)
}

// Constructor
waypoint_follower_codegen_test::waypoint_follower_codegen_test() :
  waypoint_follower_codegen_tes_U(),
  waypoint_follower_codegen_tes_Y(),
  waypoint_follower_codegen_te_DW(),
  waypoint_follower_codegen_te_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
waypoint_follower_codegen_test::~waypoint_follower_codegen_test() = default;

// Real-Time Model get method
waypoint_follower_codegen_test::RT_MODEL_waypoint_follower_co_T
  * waypoint_follower_codegen_test::getRTM()
{
  return (&waypoint_follower_codegen_te_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
