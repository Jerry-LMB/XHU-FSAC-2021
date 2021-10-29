//
// File: Cont_PathFollowingControlSystem.h
//
// Code generated for Simulink model 'Controller_MPC'.
//
// Model version                  : 4.36
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Wed Jul 28 14:48:34 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_Cont_PathFollowingControlSystem_h_
#define RTW_HEADER_Cont_PathFollowingControlSystem_h_
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "Controller_MPC_types.h"
#include "rt_nonfinite.h"
#include "rt_assert.h"

// Block signals for system '<S8>/Path Following Control System'
typedef struct {
  real32_T c_Hv[21960];
  real32_T Su[21600];
  int8_T a[14400];
  real32_T fv[2440];
  real32_T Cm[1830];
  real32_T c_SuJm[1800];
  real32_T c_Sx[1800];
  real32_T c_Kr[1800];
  real32_T Bu[1220];
  real32_T Bv[1220];
  real32_T c_Kv[1220];
  real32_T fv1[1200];
  real32_T c_Kut[1200];
  real32_T a_m[1200];
  real32_T fv2[1200];
  real32_T Dv[366];
  real32_T Dvm[366];
  real32_T CA[366];
  real32_T c_Su1[360];
  real32_T Sum[360];
  real32_T eb[220];
  real32_T fv3[200];
  real32_T rseq[180];
  real32_T CovMat[169];
  real32_T vseq[122];
  real32_T rtb_useq_scale_c[122];
  real32_T cb[121];
  real32_T c_Linv[121];
  real32_T d_Linv[121];
  real32_T RLinv[121];
  real32_T b_D[121];
  real32_T b_H[121];
  real32_T U[121];
  real32_T TL[121];
  real32_T QQ[121];
  real32_T RR[121];
  real32_T c_A[121];
  real32_T b_utarget[120];
  real32_T b_A[100];
  real32_T Qk[100];
  real32_T L_tmp[100];
  real32_T L_tmp_k[100];
  real32_T L_tmp_c[100];
  real32_T b[100];
  real32_T c_Kx[100];
  real32_T b_SuJm[100];
  real32_T b_Jm[100];
  real32_T b_B[91];
  real32_T b_B_b[91];
  real32_T Az[81];
  real32_T Ai[81];
  real32_T b_p[81];
  real32_T Az_c[81];
  real32_T F[81];
  real32_T A2[81];
  real32_T A3[81];
  real32_T A4[81];
  real32_T U_f[81];
  real32_T A_g[81];
  real32_T b_A_g[81];
  real32_T f[80];
  real32_T bb[40];
  int8_T c_I[121];
  int8_T b_m[121];
  real32_T L[30];
  real32_T b_C[30];
  real32_T Nk[30];
  real32_T b_B_tmp[30];
  real32_T L_tmp_n[30];
  real32_T fv4[30];
  real32_T CA_p[30];
  real32_T CA_l[30];
  real32_T C[27];                      // '<S52>/Adaptive Model'
  real32_T Bz[27];
  real32_T h[24];
  real32_T Opt[22];
  real32_T Rhs[22];
  int8_T b_I[81];
  real32_T b_Mlim[20];
  real32_T Bc[20];
  real32_T c_Ku1[20];
  real32_T unusedU0[20];
  real32_T cTol[20];
  real32_T fv5[20];
  real32_T b_Su1[20];
  real32_T b_I1[20];
  real32_T Cs[18];
  real32_T Bl[18];
  real_T D[9];                         // '<S52>/Adaptive Model'
  real32_T Cm_j[16];
  real32_T MatrixConcatenate[16];      // '<S55>/Matrix Concatenate'
  real32_T MatrixConcatenate2[12];     // '<S55>/Matrix Concatenate2'
  real32_T e[12];
  real32_T zopt[11];
  real32_T f_d[11];
  real32_T r[11];
  real32_T z[11];
  real32_T b_Ac[11];
  real32_T tau[11];
  real32_T work[11];
  real32_T work_g[11];
  real32_T varargin_1[11];
  real32_T xk[10];
  real32_T b_xoff[10];
  real32_T rtb_xest_l[10];
  real32_T b_A_d[10];
  int16_T iAnew[20];
  int16_T iC[20];
  real32_T Bl_d[9];
  real32_T Kinv[9];
  real32_T Bl_l[9];
  real32_T MatrixConcatenate1[8];      // '<S55>/Matrix Concatenate1'
  real32_T g[8];
  real32_T fv6[6];
  real32_T Sum_o[6];
  real32_T b_C_b[6];
  boolean_T bv[20];
  real32_T y_innov[3];
  real32_T b_myoff[3];
  real32_T Cm_n[3];
  real32_T Dvm_b[3];
  int8_T c_A_l[9];
  int8_T ipiv[9];
  real32_T b_uoff[2];
  real32_T fv7[2];
  real32_T fv8[2];
  real32_T fv9[2];
  real32_T fv10[2];
  real32_T fv11[2];
  real32_T fv12[2];
  real32_T umax_incr[2];
  real32_T umin_incr[2];
  int8_T b_I_h[4];
  real32_T DataTypeConversion_vset;    // '<S15>/DataTypeConversion_vset'
  real32_T DataTypeConversion_Vx;      // '<S15>/DataTypeConversion_Vx'
  real32_T Product;                    // '<S15>/Product'
  real32_T DataTypeConversion_amin;    // '<S15>/DataTypeConversion_amin'
  real32_T DataTypeConversion_umin;    // '<S15>/DataTypeConversion_umin'
  real32_T DataTypeConversion_amax;    // '<S15>/DataTypeConversion_amax'
  real32_T DataTypeConversion_umax;    // '<S15>/DataTypeConversion_umax'
  real32_T Switch2;                    // '<S15>/Switch2'
  real32_T DataTypeConversion_e1;      // '<S15>/DataTypeConversion_e1'
  real32_T DataTypeConversion_e2;      // '<S15>/DataTypeConversion_e2'
  real32_T A[81];                      // '<S52>/Adaptive Model'
  real32_T B[27];                      // '<S52>/Adaptive Model'
  real32_T maxval;
  real32_T y;
  real32_T utau;                       // '<S57>/Divide'
  real32_T rtb_status_b;
  real32_T rtb_b2_tmp;
  real32_T Kinv_tmp;
  real32_T Kinv_tmp_d;
  real32_T Kinv_tmp_e;
  real32_T Kinv_tmp_b;
  real32_T ii;
  real32_T b_DelBound;
  real32_T b_Kx;
  real32_T b_Kr;
  real32_T b_Kv;
  real32_T b_Kut;
  real32_T rMin;
  real32_T Xnorm0;
  real32_T cMin;
  real32_T cVal;
  real32_T zTa;
  real32_T b_Linv;
  real32_T b_atmp;
  real32_T beta1;
  real32_T normA;
  real32_T b_s;
  int32_T Coef;
  int32_T r1;
  int32_T r2;
  int32_T rtemp;
  int32_T Kinv_tmp_j;
  int32_T Kinv_tmp_f;
  int32_T kidx;
  int32_T b_j1;
  int32_T j2;
  int32_T i1;
  int32_T i;
  int32_T a_tmp;
  int32_T i_a;
  int32_T f_tmp;
  int32_T b_k;
  int32_T c_k;
  int32_T ct;
  int32_T i_j;
  int32_T i_jz;
  int32_T i_o;
  int32_T b_i;
  int32_T c_i;
  int32_T e_i;
  int32_T iC_n;
  int32_T d_i;
  int32_T itau;
  int32_T iaii;
  int32_T lastv;
  int32_T lastc;
  int32_T coltop;
  int32_T ia;
  int32_T ii_i;
  int32_T knt;
  int32_T lastc_o;
  int32_T coltop_n;
  int32_T b_j;
  int32_T b_i_m;
  int32_T eint;
  int32_T i1_c;
  int32_T F_tmp;
  int32_T d;
} B_PathFollowingControlSystem__T;

// Block states (default storage) for system '<S8>/Path Following Control System' 
typedef struct {
  real32_T last_mv_DSTATE[2];          // '<S22>/last_mv'
  real32_T LastPcov_PreviousInput[100];// '<S22>/LastPcov'
  real32_T last_x_PreviousInput[10];   // '<S22>/last_x'
  boolean_T Memory_PreviousInput[20];  // '<S22>/Memory'
} DW_PathFollowingControlSystem_T;

// Parameters for system: '<S8>/Path Following Control System'
struct P_PathFollowingControlSystem__T_ {
  real_T Longitudinalvelocitymustbeposit;
                              // Mask Parameter: Longitudinalvelocitymustbeposit
                                 //  Referenced by: '<S16>/min_val'

  real_T Enableoptimizationconstant_Valu;// Expression: 1
                                            //  Referenced by: '<S14>/Enable optimization constant'

  real_T Externalcontrolsignalconstant_V[2];// Expression: [0;0]
                                               //  Referenced by: '<S14>/External control signal constant'

  real32_T UsePFCoutputconstant_Value;
                               // Computed Parameter: UsePFCoutputconstant_Value
                                  //  Referenced by: '<S15>/Use PFC output constant'

  real32_T NotusePFCoutputconstant_Value;
                            // Computed Parameter: NotusePFCoutputconstant_Value
                               //  Referenced by: '<S15>/Not use PFC output constant'

  real32_T Lateraldeviationreferenceconsta;
                          // Computed Parameter: Lateraldeviationreferenceconsta
                             //  Referenced by: '<S15>/Lateral deviation reference constant'

  real32_T Relativeyawanglereferenceconsta;
                          // Computed Parameter: Relativeyawanglereferenceconsta
                             //  Referenced by: '<S15>/Relative yaw angle reference constant '

  real32_T ecrwt_zero_Value;           // Computed Parameter: ecrwt_zero_Value
                                          //  Referenced by: '<S21>/ecr.wt_zero'

  real32_T Sampletimeconstant_Value;
                                 // Computed Parameter: Sampletimeconstant_Value
                                    //  Referenced by: '<S14>/Sample time constant'

  real32_T Matrixconstant_Value[4];  // Computed Parameter: Matrixconstant_Value
                                        //  Referenced by: '<S55>/Matrix constant'

  real32_T Scalaroneconstant_Value;
                                  // Computed Parameter: Scalaroneconstant_Value
                                     //  Referenced by: '<S57>/Scalar one constant'

  real32_T Vehicleaccelerationtrackingtime;
                          // Computed Parameter: Vehicleaccelerationtrackingtime
                             //  Referenced by: '<S57>/Vehicle acceleration tracking time constant'

  real32_T Vectorconstant_Value[2];  // Computed Parameter: Vectorconstant_Value
                                        //  Referenced by: '<S57>/Vector constant'

  real32_T Vehiclereartirecorneringstiffne;
                          // Computed Parameter: Vehiclereartirecorneringstiffne
                             //  Referenced by: '<S56>/Vehicle rear tire cornering stiffness constant'

  real32_T Vehiclefronttirecorneringstiffn;
                          // Computed Parameter: Vehiclefronttirecorneringstiffn
                             //  Referenced by: '<S56>/Vehicle front tire cornering stiffness constant'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S56>/Gain2'

  real32_T Vehiclemassconstant_Value;
                                // Computed Parameter: Vehiclemassconstant_Value
                                   //  Referenced by: '<S56>/Vehicle mass constant'

  real32_T Vehiclelengthtorearconstant_Val;
                          // Computed Parameter: Vehiclelengthtorearconstant_Val
                             //  Referenced by: '<S56>/Vehicle length to rear constant'

  real32_T Vehiclelengthtofrontconstant_Va;
                          // Computed Parameter: Vehiclelengthtofrontconstant_Va
                             //  Referenced by: '<S56>/Vehicle length to front constant'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S56>/Gain3'

  real32_T Vehicleyawinertiaconstant_Value;
                          // Computed Parameter: Vehicleyawinertiaconstant_Value
                             //  Referenced by: '<S56>/Vehicle yaw inertia constant'

  real32_T Gain4_Gain;                 // Computed Parameter: Gain4_Gain
                                          //  Referenced by: '<S56>/Gain4'

  real32_T Scalarzeroconstant_Value;
                                 // Computed Parameter: Scalarzeroconstant_Value
                                    //  Referenced by: '<S57>/Scalar zero constant'

  real32_T Vectorconstant_Value_l[2];
                                   // Computed Parameter: Vectorconstant_Value_l
                                      //  Referenced by: '<S55>/Vector constant'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S56>/Gain'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S56>/Gain1'

  real32_T Cnconstant_Value[2];        // Computed Parameter: Cnconstant_Value
                                          //  Referenced by: '<S57>/Cn constant'

  real32_T Matrixconstant1_Value[4];// Computed Parameter: Matrixconstant1_Value
                                       //  Referenced by: '<S55>/Matrix constant1'

  real32_T Vectorconstant1_Value[2];// Computed Parameter: Vectorconstant1_Value
                                       //  Referenced by: '<S55>/Vector constant1'

  real32_T CmConstant_Value[4];        // Computed Parameter: CmConstant_Value
                                          //  Referenced by: '<S56>/Cm Constant'

  real32_T Transportlagconstant_Value;
                               // Computed Parameter: Transportlagconstant_Value
                                  //  Referenced by: '<S14>/Transport lag constant'

  real32_T UConstant_Value[3];         // Computed Parameter: UConstant_Value
                                          //  Referenced by: '<S52>/U Constant'

  real32_T YConstant_Value[3];         // Computed Parameter: YConstant_Value
                                          //  Referenced by: '<S52>/Y Constant'

  real32_T XConstant_Value[9];         // Computed Parameter: XConstant_Value
                                          //  Referenced by: '<S52>/X Constant'

  real32_T DXConstant_Value[9];        // Computed Parameter: DXConstant_Value
                                          //  Referenced by: '<S52>/DX Constant'

  real32_T ymin_zero_Value[3];         // Computed Parameter: ymin_zero_Value
                                          //  Referenced by: '<S21>/ymin_zero'

  real32_T ymax_zero_Value[3];         // Computed Parameter: ymax_zero_Value
                                          //  Referenced by: '<S21>/ymax_zero'

  real32_T G_zero_Value;               // Computed Parameter: G_zero_Value
                                          //  Referenced by: '<S21>/G_zero'

  real32_T LastPcov_InitialCondition[100];// Expression: lastPcov
                                             //  Referenced by: '<S22>/LastPcov'

  real32_T E_zero_Value[2];            // Computed Parameter: E_zero_Value
                                          //  Referenced by: '<S21>/E_zero'

  real32_T umin_scale4_Gain[2];    // Expression: MVscale(:,ones(1,max(nCC,1)))'
                                      //  Referenced by: '<S22>/umin_scale4'

  real32_T F_zero_Value[3];            // Computed Parameter: F_zero_Value
                                          //  Referenced by: '<S21>/F_zero'

  real32_T ymin_scale1_Gain[3];     // Expression: Yscale(:,ones(1,max(nCC,1)))'
                                       //  Referenced by: '<S22>/ymin_scale1'

  real32_T S_zero_Value;               // Computed Parameter: S_zero_Value
                                          //  Referenced by: '<S21>/S_zero'

  real32_T ymin_scale2_Gain;       // Expression: MDscale(:,ones(1,max(nCC,1)))'
                                      //  Referenced by: '<S22>/ymin_scale2'

  real32_T ywt_zero_Value[3];          // Computed Parameter: ywt_zero_Value
                                          //  Referenced by: '<S21>/y.wt_zero'

  real32_T uwt_zero_Value[2];          // Computed Parameter: uwt_zero_Value
                                          //  Referenced by: '<S21>/u.wt_zero'

  real32_T duwt_zero_Value[2];         // Computed Parameter: duwt_zero_Value
                                          //  Referenced by: '<S21>/du.wt_zero'

  real32_T extmv_zero_Value[2];        // Computed Parameter: extmv_zero_Value
                                          //  Referenced by: '<S21>/ext.mv_zero'

  real32_T extmv_scale_Gain[2];        // Expression: RMVscale
                                          //  Referenced by: '<S22>/ext.mv_scale'

  real32_T last_mv_InitialCondition[2];// Expression: lastu+uoff
                                          //  Referenced by: '<S22>/last_mv'

  real32_T last_x_InitialCondition[10];// Expression: lastx+xoff
                                          //  Referenced by: '<S22>/last_x'

  real32_T mvtarget_zero_Value[2];    // Computed Parameter: mvtarget_zero_Value
                                         //  Referenced by: '<S21>/mv.target_zero'

  real32_T uref_scale_Gain[2];         // Expression: RMVscale
                                          //  Referenced by: '<S22>/uref_scale'

  real32_T useq_scale1_Gain[183];      // Expression: Yscale(:,ones(1,p+1))'
                                          //  Referenced by: '<S22>/useq_scale1'

  real32_T useq_scale_Gain[122];       // Expression: MVscale(:,ones(1,p+1))'
                                          //  Referenced by: '<S22>/useq_scale'

  real32_T u_scale_Gain[2];            // Expression: MVscale
                                          //  Referenced by: '<S22>/u_scale'

  real32_T ym_zero_Value[3];           // Computed Parameter: ym_zero_Value
                                          //  Referenced by: '<S22>/ym_zero'

  real32_T p_zero_Value;               // Computed Parameter: p_zero_Value
                                          //  Referenced by: '<S21>/p_zero'

  real32_T m_zero_Value;               // Computed Parameter: m_zero_Value
                                          //  Referenced by: '<S21>/m_zero'

  uint16_T MatrixDimensionCheck_P1[125];
                                  // Computed Parameter: MatrixDimensionCheck_P1
                                     //  Referenced by: '<S23>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2[18];
                                  // Computed Parameter: MatrixDimensionCheck_P2
                                     //  Referenced by: '<S23>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3;    // Expression: nrow
                                          //  Referenced by: '<S23>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4;    // Expression: ncol
                                          //  Referenced by: '<S23>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P5;    // Expression: nsteps
                                          //  Referenced by: '<S23>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P6;    // Expression: isltv
                                          //  Referenced by: '<S23>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_b[125];
                                // Computed Parameter: MatrixDimensionCheck_P1_b
                                   //  Referenced by: '<S24>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_i[7];
                                // Computed Parameter: MatrixDimensionCheck_P2_i
                                   //  Referenced by: '<S24>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_h;  // Expression: nrow
                                          //  Referenced by: '<S24>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_a;  // Expression: ncol
                                          //  Referenced by: '<S24>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P5_e;  // Expression: nsteps
                                          //  Referenced by: '<S24>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P6_d;  // Expression: isltv
                                          //  Referenced by: '<S24>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_o[125];
                                // Computed Parameter: MatrixDimensionCheck_P1_o
                                   //  Referenced by: '<S25>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_e[7];
                                // Computed Parameter: MatrixDimensionCheck_P2_e
                                   //  Referenced by: '<S25>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_n;  // Expression: nrow
                                          //  Referenced by: '<S25>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_p;  // Expression: ncol
                                          //  Referenced by: '<S25>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P5_i;  // Expression: nsteps
                                          //  Referenced by: '<S25>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P6_f;  // Expression: isltv
                                          //  Referenced by: '<S25>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_ol[125];
                               // Computed Parameter: MatrixDimensionCheck_P1_ol
                                  //  Referenced by: '<S26>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_l[7];
                                // Computed Parameter: MatrixDimensionCheck_P2_l
                                   //  Referenced by: '<S26>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_o;  // Expression: nrow
                                          //  Referenced by: '<S26>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_h;  // Expression: ncol
                                          //  Referenced by: '<S26>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P5_f;  // Expression: nsteps
                                          //  Referenced by: '<S26>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P6_j;  // Expression: isltv
                                          //  Referenced by: '<S26>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_n[125];
                                // Computed Parameter: MatrixDimensionCheck_P1_n
                                   //  Referenced by: '<S27>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_n[7];
                                // Computed Parameter: MatrixDimensionCheck_P2_n
                                   //  Referenced by: '<S27>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_l;  // Expression: nrow
                                          //  Referenced by: '<S27>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_a1; // Expression: ncol
                                          //  Referenced by: '<S27>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P5_a;  // Expression: nsteps
                                          //  Referenced by: '<S27>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P6_k;  // Expression: isltv
                                          //  Referenced by: '<S27>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_k[125];
                                // Computed Parameter: MatrixDimensionCheck_P1_k
                                   //  Referenced by: '<S28>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_b[8];
                                // Computed Parameter: MatrixDimensionCheck_P2_b
                                   //  Referenced by: '<S28>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_c;  // Expression: nrow
                                          //  Referenced by: '<S28>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_d;  // Expression: ncol
                                          //  Referenced by: '<S28>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P5_p;  // Expression: nsteps
                                          //  Referenced by: '<S28>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P6_fo; // Expression: isltv
                                          //  Referenced by: '<S28>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_e[125];
                                // Computed Parameter: MatrixDimensionCheck_P1_e
                                   //  Referenced by: '<S29>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_bx[7];
                               // Computed Parameter: MatrixDimensionCheck_P2_bx
                                  //  Referenced by: '<S29>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_b;  // Expression: nrow
                                          //  Referenced by: '<S29>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_c;  // Expression: ncol
                                          //  Referenced by: '<S29>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P5_ic; // Expression: nsteps
                                          //  Referenced by: '<S29>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P6_b;  // Expression: isltv
                                          //  Referenced by: '<S29>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_f[125];
                                // Computed Parameter: MatrixDimensionCheck_P1_f
                                   //  Referenced by: '<S30>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_a[7];
                                // Computed Parameter: MatrixDimensionCheck_P2_a
                                   //  Referenced by: '<S30>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_j;  // Expression: nrow
                                          //  Referenced by: '<S30>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_o;  // Expression: ncol
                                          //  Referenced by: '<S30>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P5_n;  // Expression: nsteps
                                          //  Referenced by: '<S30>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P6_jd; // Expression: isltv
                                          //  Referenced by: '<S30>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_a[125];
                                // Computed Parameter: MatrixDimensionCheck_P1_a
                                   //  Referenced by: '<S31>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_o[7];
                                // Computed Parameter: MatrixDimensionCheck_P2_o
                                   //  Referenced by: '<S31>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_on; // Expression: nrow
                                          //  Referenced by: '<S31>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_n;  // Expression: ncol
                                          //  Referenced by: '<S31>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P5_fc; // Expression: nsteps
                                          //  Referenced by: '<S31>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P6_j3; // Expression: isltv
                                          //  Referenced by: '<S31>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_l[125];
                                // Computed Parameter: MatrixDimensionCheck_P1_l
                                   //  Referenced by: '<S32>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_p[18];
                                // Computed Parameter: MatrixDimensionCheck_P2_p
                                   //  Referenced by: '<S32>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_jz; // Expression: nrow
                                          //  Referenced by: '<S32>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_dt; // Expression: ncol
                                          //  Referenced by: '<S32>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P5_m;  // Expression: nsteps
                                          //  Referenced by: '<S32>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P6_jl; // Expression: isltv
                                          //  Referenced by: '<S32>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_fk[125];
                               // Computed Parameter: MatrixDimensionCheck_P1_fk
                                  //  Referenced by: '<S33>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_et[18];
                               // Computed Parameter: MatrixDimensionCheck_P2_et
                                  //  Referenced by: '<S33>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_hl; // Expression: nrow
                                          //  Referenced by: '<S33>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_i;  // Expression: ncol
                                          //  Referenced by: '<S33>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P5_g;  // Expression: nsteps
                                          //  Referenced by: '<S33>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P6_ky; // Expression: isltv
                                          //  Referenced by: '<S33>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_g[125];
                                // Computed Parameter: MatrixDimensionCheck_P1_g
                                   //  Referenced by: '<S34>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_ly[3];
                               // Computed Parameter: MatrixDimensionCheck_P2_ly
                                  //  Referenced by: '<S34>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_bf; // Expression: nrow
                                          //  Referenced by: '<S34>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_o5; // Expression: ncol
                                          //  Referenced by: '<S34>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_p[125];
                                // Computed Parameter: MatrixDimensionCheck_P1_p
                                   //  Referenced by: '<S35>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_bj[2];
                               // Computed Parameter: MatrixDimensionCheck_P2_bj
                                  //  Referenced by: '<S35>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_hi; // Expression: nrow
                                          //  Referenced by: '<S35>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_f;  // Expression: ncol
                                          //  Referenced by: '<S35>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_gw[125];
                               // Computed Parameter: MatrixDimensionCheck_P1_gw
                                  //  Referenced by: '<S36>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_g[4];
                                // Computed Parameter: MatrixDimensionCheck_P2_g
                                   //  Referenced by: '<S36>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_oj; // Expression: nrow
                                          //  Referenced by: '<S36>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_i5; // Expression: ncol
                                          //  Referenced by: '<S36>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_af[125];
                               // Computed Parameter: MatrixDimensionCheck_P1_af
                                  //  Referenced by: '<S37>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_h[4];
                                // Computed Parameter: MatrixDimensionCheck_P2_h
                                   //  Referenced by: '<S37>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_a;  // Expression: nrow
                                          //  Referenced by: '<S37>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_ir; // Expression: ncol
                                          //  Referenced by: '<S37>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_ah[125];
                               // Computed Parameter: MatrixDimensionCheck_P1_ah
                                  //  Referenced by: '<S38>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_hd[5];
                               // Computed Parameter: MatrixDimensionCheck_P2_hd
                                  //  Referenced by: '<S38>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_i;  // Expression: nrow
                                          //  Referenced by: '<S38>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_pk; // Expression: ncol
                                          //  Referenced by: '<S38>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_kq[125];
                               // Computed Parameter: MatrixDimensionCheck_P1_kq
                                  //  Referenced by: '<S39>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_am[4];
                               // Computed Parameter: MatrixDimensionCheck_P2_am
                                  //  Referenced by: '<S39>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_h3; // Expression: nrow
                                          //  Referenced by: '<S39>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_g;  // Expression: ncol
                                          //  Referenced by: '<S39>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_ab[125];
                               // Computed Parameter: MatrixDimensionCheck_P1_ab
                                  //  Referenced by: '<S40>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_f[4];
                                // Computed Parameter: MatrixDimensionCheck_P2_f
                                   //  Referenced by: '<S40>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_g;  // Expression: nrow
                                          //  Referenced by: '<S40>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_k;  // Expression: ncol
                                          //  Referenced by: '<S40>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_j[125];
                                // Computed Parameter: MatrixDimensionCheck_P1_j
                                   //  Referenced by: '<S41>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_br[4];
                               // Computed Parameter: MatrixDimensionCheck_P2_br
                                  //  Referenced by: '<S41>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_e;  // Expression: nrow
                                          //  Referenced by: '<S41>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_dv; // Expression: ncol
                                          //  Referenced by: '<S41>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P1_e1[125];
                               // Computed Parameter: MatrixDimensionCheck_P1_e1
                                  //  Referenced by: '<S42>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P2_m[4];
                                // Computed Parameter: MatrixDimensionCheck_P2_m
                                   //  Referenced by: '<S42>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P3_is; // Expression: nrow
                                          //  Referenced by: '<S42>/Matrix Dimension Check'

  uint16_T MatrixDimensionCheck_P4_pc; // Expression: ncol
                                          //  Referenced by: '<S42>/Matrix Dimension Check'

  uint16_T VectorDimensionCheck_P1[125];
                                  // Computed Parameter: VectorDimensionCheck_P1
                                     //  Referenced by: '<S43>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P2[6];
                                  // Computed Parameter: VectorDimensionCheck_P2
                                     //  Referenced by: '<S43>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P1_n[125];
                                // Computed Parameter: VectorDimensionCheck_P1_n
                                   //  Referenced by: '<S44>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P2_g[6];
                                // Computed Parameter: VectorDimensionCheck_P2_g
                                   //  Referenced by: '<S44>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P1_no[125];
                               // Computed Parameter: VectorDimensionCheck_P1_no
                                  //  Referenced by: '<S45>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P2_c;
                                // Computed Parameter: VectorDimensionCheck_P2_c
                                   //  Referenced by: '<S45>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P1_l[125];
                                // Computed Parameter: VectorDimensionCheck_P1_l
                                   //  Referenced by: '<S46>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P2_ck[6];
                               // Computed Parameter: VectorDimensionCheck_P2_ck
                                  //  Referenced by: '<S46>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P3;    // Expression: n
                                          //  Referenced by: '<S46>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P4;    // Expression: option
                                          //  Referenced by: '<S46>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P1_c[125];
                                // Computed Parameter: VectorDimensionCheck_P1_c
                                   //  Referenced by: '<S47>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P2_n[18];
                                // Computed Parameter: VectorDimensionCheck_P2_n
                                   //  Referenced by: '<S47>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P3_n;  // Expression: n
                                          //  Referenced by: '<S47>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P4_n;  // Expression: option
                                          //  Referenced by: '<S47>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P1_a[125];
                                // Computed Parameter: VectorDimensionCheck_P1_a
                                   //  Referenced by: '<S48>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P2_nj[2];
                               // Computed Parameter: VectorDimensionCheck_P2_nj
                                  //  Referenced by: '<S48>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P3_a;  // Expression: n
                                          //  Referenced by: '<S48>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P4_e;  // Expression: option
                                          //  Referenced by: '<S48>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P1_g[125];
                                // Computed Parameter: VectorDimensionCheck_P1_g
                                   //  Referenced by: '<S49>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P2_h[9];
                                // Computed Parameter: VectorDimensionCheck_P2_h
                                   //  Referenced by: '<S49>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P3_d;  // Expression: n
                                          //  Referenced by: '<S49>/Vector Dimension Check'

  uint16_T VectorDimensionCheck_P4_o;  // Expression: option
                                          //  Referenced by: '<S49>/Vector Dimension Check'

  boolean_T Memory_InitialCondition[20];// Expression: iA
                                           //  Referenced by: '<S22>/Memory'

};

extern void PathFollowingControlSystem_Init(DW_PathFollowingControlSystem_T
  *localDW, P_PathFollowingControlSystem__T *localP);
extern void Cont_PathFollowingControlSystem(real32_T rtu_Setvelocity, real32_T
  rtu_Longitudinalvelocity, real32_T rtu_Curvature, real32_T
  rtu_Lateraldeviation, real32_T rtu_Relativeyawangle, real32_T
  rtyy_LongitudinalaccelerationSt[2], B_PathFollowingControlSystem__T *localB,
  DW_PathFollowingControlSystem_T *localDW, P_PathFollowingControlSystem__T
  *localP, real_T rtp_MinAcceleration, real_T rtp_MinSteering, real_T
  rtp_MaxAcceleration, real_T rtp_MaxSteering);

#endif                         // RTW_HEADER_Cont_PathFollowingControlSystem_h_

//
// File trailer for generated code.
//
// [EOF]
//
