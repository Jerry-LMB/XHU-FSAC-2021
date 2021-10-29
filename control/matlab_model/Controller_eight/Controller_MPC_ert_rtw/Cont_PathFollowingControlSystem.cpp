//
// File: Cont_PathFollowingControlSystem.cpp
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
#include "Cont_PathFollowingControlSystem.h"

// Include model header file for global data
#include "Controller_MPC.h"
#include "Controller_MPC_private.h"

// Named constants for MATLAB Function: '<S50>/FixedHorizonOptimizer'
const real32_T Controller_MPC_RMDscale = 10.0F;
const real32_T Controller_MPC_nu = 2.0F;
const real32_T Controller_MPC_ny = 3.0F;

// Forward declaration for local functions
static void Controller_MPC_lusolve(const real32_T A[81], const real32_T B[81],
  real32_T X[81], B_PathFollowingControlSystem__T *localB);
static void Control_PadeApproximantOfDegree(const real32_T A[81], uint8_T m,
  real32_T F[81], B_PathFollowingControlSystem__T *localB);
static void Controller_MPC_expm(real32_T A[81], real32_T F[81],
  B_PathFollowingControlSystem__T *localB);
static void Controller_MPC_mpc_plantupdate(const real32_T a[81], real32_T b[27],
  const real32_T c[27], const real32_T d[9], real32_T b_A[100], real32_T b_B[80],
  real32_T b_C[30], real32_T b_D[24], const real32_T b_mvindex[2], const
  real32_T b_myindex[3], const real32_T b_Uscale[3], const real32_T b_Yscale[3],
  real32_T Bu[20], real32_T Bv[20], real32_T Cm[30], real32_T Dv[6], real32_T
  Dvm[6], real32_T QQ[100], real32_T RR[9], real32_T NN[30],
  B_PathFollowingControlSystem__T *localB);
static real32_T Controller_MPC_mod(real32_T x);
static real32_T Controller_MPC_mod_l(real32_T x);
static void Controlle_mpc_updateFromNominal(real32_T b_Mlim[20], const real32_T
  b_Mrows[20], const real32_T U0[3], const real32_T b_Uscale[3], const real32_T
  old_mvoff[2], const real32_T b_mvindex[2], real32_T b_utarget[120], const
  real32_T Y0[3], const real32_T b_Yscale[3], const real32_T old_yoff[3], const
  real32_T b_myindex[3], const real32_T X0[9], real32_T b_xoff[10], const
  real32_T DX0[9], real32_T Bv[1220], real32_T new_mvoff[2], real32_T *new_mdoff,
  real32_T new_yoff[3], real32_T new_myoff[3]);
static void Controller_M_mpc_constraintcoef(const real32_T b_A[100], const
  real32_T Bu[20], const real32_T Bv[20], const real32_T b_C[30], const real32_T
  Dv[6], const real32_T b_Jm[1200], real32_T b_SuJm[1800], real32_T b_Sx[1800],
  real32_T b_Su1[360], real32_T b_Hv[21960], B_PathFollowingControlSystem__T
  *localB);
static void Controller_MPC_WtMult(const real32_T W[2], const real32_T M[1200],
  real32_T nwt, real32_T WM[1200]);
static void Controller_mpc_calculatehessian(const real32_T b_Wy[3], const
  real32_T b_Wu[2], const real32_T b_Wdu[2], const real32_T b_SuJm[1800], const
  real32_T I2Jm[1200], const real32_T b_Jm[1200], const real32_T b_I1[240],
  const real32_T b_Su1[360], const real32_T b_Sx[1800], const real32_T b_Hv
  [21960], real32_T nmv, real32_T b_ny, real32_T b_H[100], real32_T b_Ku1[20],
  real32_T b_Kut[1200], real32_T b_Kx[100], real32_T b_Kv[1220], real32_T b_Kr
  [1800], B_PathFollowingControlSystem__T *localB);
static int32_T Controller_MPC_xpotrf(real32_T b_A[121]);
static real32_T Controller_MPC_minimum(const real32_T x[11]);
static void Controller_MPC_mpc_checkhessian(real32_T b_H[121], real32_T L[121],
  real32_T *BadH, B_PathFollowingControlSystem__T *localB);
static void Controller_MPC_trisolve(const real32_T b_A[121], real32_T b_B[121]);
static void Controller_MPC_Unconstrained(const real32_T b_Hinv[121], const
  real32_T f[11], real32_T x[11], int16_T n);
static real32_T Controller_MPC_norm(const real32_T x[11]);
static real32_T Controller_MPC_xnrm2(int32_T n, const real32_T x[121], int32_T
  ix0);
static void Controller_MPC_xgemv(int32_T b_m, int32_T n, const real32_T b_A[121],
  int32_T ia0, const real32_T x[121], int32_T ix0, real32_T y[11]);
static void Controller_MPC_xgerc(int32_T b_m, int32_T n, real32_T alpha1,
  int32_T ix0, const real32_T y[11], real32_T b_A[121], int32_T ia0);
static void Controller_MPC_xgeqrf(real32_T b_A[121], real32_T tau[11],
  B_PathFollowingControlSystem__T *localB);
static void Controller_MPC_qr(const real32_T b_A[121], real32_T Q[121], real32_T
  R[121], B_PathFollowingControlSystem__T *localB);
static real32_T Controller_MPC_KWIKfactor(const real32_T b_Ac[220], const
  int16_T iC[20], int16_T nA, const real32_T b_Linv[121], real32_T RLinv[121],
  real32_T b_D[121], real32_T b_H[121], int16_T n,
  B_PathFollowingControlSystem__T *localB);
static void Controller_MPC_abs(const real32_T x[11], real32_T y[11]);
static real32_T Controller_MPC_maximum(const real32_T x[11]);
static void Controller_MPC_abs_a(const real32_T x[20], real32_T y[20]);
static void Controller_MPC_maximum2(const real32_T x[20], real32_T y, real32_T
  ex[20]);
static real32_T Controller_MPC_mtimes(const real32_T b_A[11], const real32_T
  b_B[11]);
static void Controller_MPC_DropConstraint(int16_T kDrop, int16_T iA[20], int16_T
  *nA, int16_T iC[20]);
static void Controller_MPC_qpkwik(const real32_T b_Linv[121], const real32_T
  b_Hinv[121], const real32_T f[11], const real32_T b_Ac[220], const real32_T b
  [20], int16_T iA[20], int16_T maxiter, real32_T FeasTol, real32_T x[11],
  real32_T lambda[20], real32_T *status, B_PathFollowingControlSystem__T *localB);
static void Controller_MPC_mpc_solveQP(const real32_T xQP[10], const real32_T
  b_Kx[100], const real32_T b_Kr[1800], const real32_T rseq[180], const real32_T
  b_Ku1[20], const real32_T old_u[2], const real32_T b_Kv[1220], const real32_T
  vseq[122], const real32_T b_Kut[1200], const real32_T b_utarget[120], const
  real32_T b_Linv[121], const real32_T b_Hinv[121], const real32_T b_Ac[220],
  const real32_T Bc[20], boolean_T iA[20], real32_T zopt[11], real32_T f[11],
  real32_T *status, B_PathFollowingControlSystem__T *localB);
static void Controller_M_mpcblock_optimizer(const real32_T rseq[180], const
  real32_T vseq[122], const real32_T umin[2], const real32_T umax[2], real32_T
  switch_in, const real32_T x[10], const real32_T old_u[2], const boolean_T iA
  [20], const real32_T b_Mlim[20], real32_T b_Mx[200], real32_T b_Mu1[40],
  real32_T b_Mv[2440], const real32_T b_utarget[120], const real32_T b_uoff[2],
  real32_T b_enable_value, real32_T b_H[121], real32_T b_Ac[220], const real32_T
  b_Wy[3], const real32_T b_Wdu[2], const real32_T b_Jm[1200], const real32_T
  b_Wu[2], const real32_T b_I1[240], const real32_T b_A[100], const real32_T Bu
  [1220], const real32_T Bv[1220], const real32_T b_C[30], const real32_T Dv[366],
  const real32_T b_Mrows[20], const real32_T b_RMVscale[2], real32_T u[2],
  real32_T useq[122], real32_T *status, boolean_T iAout[20],
  B_PathFollowingControlSystem__T *localB);

// Function for MATLAB Function: '<S52>/Adaptive Model'
static void Controller_MPC_lusolve(const real32_T A[81], const real32_T B[81],
  real32_T X[81], B_PathFollowingControlSystem__T *localB)
{
  int32_T b_ix;
  int32_T b_j;
  int32_T c;
  int32_T c_ix;
  int32_T c_k;
  int32_T d;
  int32_T ijA;
  int32_T ix;
  real32_T smax;
  real32_T y;
  int8_T ipiv;
  memcpy(&localB->b_A_g[0], &A[0], 81U * sizeof(real32_T));
  for (c = 0; c < 9; c++) {
    localB->ipiv[c] = static_cast<int8_T>(c + 1);
  }

  for (b_j = 0; b_j < 8; b_j++) {
    c = b_j * 10;
    b_ix = 0;
    ix = c;
    smax = static_cast<real32_T>(fabs(static_cast<real_T>(localB->b_A_g[c])));
    for (c_k = 2; c_k <= 9 - b_j; c_k++) {
      ix++;
      y = static_cast<real32_T>(fabs(static_cast<real_T>(localB->b_A_g[ix])));
      if (y > smax) {
        b_ix = c_k - 1;
        smax = y;
      }
    }

    if (localB->b_A_g[c + b_ix] != 0.0F) {
      if (b_ix != 0) {
        ix = b_j + b_ix;
        localB->ipiv[b_j] = static_cast<int8_T>(ix + 1);
        b_ix = b_j;
        for (c_k = 0; c_k < 9; c_k++) {
          smax = localB->b_A_g[b_ix];
          localB->b_A_g[b_ix] = localB->b_A_g[ix];
          localB->b_A_g[ix] = smax;
          b_ix += 9;
          ix += 9;
        }
      }

      b_ix = (c - b_j) + 9;
      for (ix = c + 1; ix < b_ix; ix++) {
        localB->b_A_g[ix] /= localB->b_A_g[c];
      }
    }

    b_ix = c;
    ix = c + 9;
    for (c_k = 0; c_k <= 7 - b_j; c_k++) {
      if (localB->b_A_g[ix] != 0.0F) {
        smax = -localB->b_A_g[ix];
        c_ix = c + 1;
        d = (b_ix - b_j) + 18;
        for (ijA = b_ix + 10; ijA < d; ijA++) {
          localB->b_A_g[ijA] += localB->b_A_g[c_ix] * smax;
          c_ix++;
        }
      }

      ix += 9;
      b_ix += 9;
    }
  }

  memcpy(&X[0], &B[0], 81U * sizeof(real32_T));
  for (c = 0; c < 8; c++) {
    ipiv = localB->ipiv[c];
    if (c + 1 != ipiv) {
      for (b_ix = 0; b_ix < 9; b_ix++) {
        ix = 9 * b_ix + c;
        smax = X[ix];
        b_j = (ipiv + 9 * b_ix) - 1;
        X[ix] = X[b_j];
        X[b_j] = smax;
      }
    }
  }

  for (b_ix = 0; b_ix < 9; b_ix++) {
    ix = 9 * b_ix;
    for (c_k = 0; c_k < 9; c_k++) {
      c_ix = 9 * c_k;
      c = c_k + ix;
      if (X[c] != 0.0F) {
        for (d = c_k + 2; d < 10; d++) {
          b_j = (d + ix) - 1;
          X[b_j] -= localB->b_A_g[(d + c_ix) - 1] * X[c];
        }
      }
    }
  }

  for (b_ix = 0; b_ix < 9; b_ix++) {
    ix = 9 * b_ix;
    for (c_k = 8; c_k >= 0; c_k--) {
      c_ix = 9 * c_k;
      c = c_k + ix;
      smax = X[c];
      if (smax != 0.0F) {
        X[c] = smax / localB->b_A_g[c_k + c_ix];
        for (d = 0; d < c_k; d++) {
          b_j = d + ix;
          X[b_j] -= X[c] * localB->b_A_g[d + c_ix];
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S52>/Adaptive Model'
static void Control_PadeApproximantOfDegree(const real32_T A[81], uint8_T m,
  real32_T F[81], B_PathFollowingControlSystem__T *localB)
{
  int32_T A2_tmp;
  int32_T c_k;
  int32_T i;
  real32_T A4;
  real32_T U;
  for (localB->d = 0; localB->d < 9; localB->d++) {
    for (c_k = 0; c_k < 9; c_k++) {
      A2_tmp = c_k + 9 * localB->d;
      localB->A2[A2_tmp] = 0.0F;
      for (i = 0; i < 9; i++) {
        localB->A2[A2_tmp] += A[9 * i + c_k] * A[9 * localB->d + i];
      }
    }
  }

  if (m == 3) {
    memcpy(&localB->U_f[0], &localB->A2[0], 81U * sizeof(real32_T));
    for (c_k = 0; c_k < 9; c_k++) {
      localB->d = 9 * c_k + c_k;
      localB->U_f[localB->d] += 60.0F;
    }

    for (localB->d = 0; localB->d < 9; localB->d++) {
      for (c_k = 0; c_k < 9; c_k++) {
        A2_tmp = c_k + 9 * localB->d;
        localB->A_g[A2_tmp] = 0.0F;
        for (i = 0; i < 9; i++) {
          localB->A_g[A2_tmp] += A[9 * i + c_k] * localB->U_f[9 * localB->d + i];
        }
      }
    }

    for (localB->d = 0; localB->d < 81; localB->d++) {
      localB->U_f[localB->d] = localB->A_g[localB->d];
      localB->A4[localB->d] = 12.0F * localB->A2[localB->d];
    }

    localB->d = 120;
  } else {
    for (localB->d = 0; localB->d < 9; localB->d++) {
      for (c_k = 0; c_k < 9; c_k++) {
        A2_tmp = c_k + 9 * localB->d;
        localB->A3[A2_tmp] = 0.0F;
        for (i = 0; i < 9; i++) {
          localB->A3[A2_tmp] += localB->A2[9 * i + c_k] * localB->A2[9 *
            localB->d + i];
        }
      }
    }

    if (m == 5) {
      for (localB->d = 0; localB->d < 81; localB->d++) {
        localB->U_f[localB->d] = 420.0F * localB->A2[localB->d] + localB->
          A3[localB->d];
      }

      for (c_k = 0; c_k < 9; c_k++) {
        localB->d = 9 * c_k + c_k;
        localB->U_f[localB->d] += 15120.0F;
      }

      for (localB->d = 0; localB->d < 9; localB->d++) {
        for (c_k = 0; c_k < 9; c_k++) {
          A2_tmp = c_k + 9 * localB->d;
          localB->A_g[A2_tmp] = 0.0F;
          for (i = 0; i < 9; i++) {
            localB->A_g[A2_tmp] += A[9 * i + c_k] * localB->U_f[9 * localB->d +
              i];
          }
        }
      }

      for (localB->d = 0; localB->d < 81; localB->d++) {
        localB->U_f[localB->d] = localB->A_g[localB->d];
        localB->A4[localB->d] = 30.0F * localB->A3[localB->d] + 3360.0F *
          localB->A2[localB->d];
      }

      localB->d = 30240;
    } else {
      for (localB->d = 0; localB->d < 9; localB->d++) {
        for (c_k = 0; c_k < 9; c_k++) {
          A2_tmp = c_k + 9 * localB->d;
          localB->A4[A2_tmp] = 0.0F;
          for (i = 0; i < 9; i++) {
            localB->A4[A2_tmp] += localB->A3[9 * i + c_k] * localB->A2[9 *
              localB->d + i];
          }
        }
      }

      for (localB->d = 0; localB->d < 81; localB->d++) {
        localB->U_f[localB->d] = (1512.0F * localB->A3[localB->d] + localB->
          A4[localB->d]) + 277200.0F * localB->A2[localB->d];
      }

      for (c_k = 0; c_k < 9; c_k++) {
        localB->d = 9 * c_k + c_k;
        localB->U_f[localB->d] += 8.64864E+6F;
      }

      for (localB->d = 0; localB->d < 9; localB->d++) {
        for (c_k = 0; c_k < 9; c_k++) {
          A2_tmp = c_k + 9 * localB->d;
          localB->A_g[A2_tmp] = 0.0F;
          for (i = 0; i < 9; i++) {
            localB->A_g[A2_tmp] += A[9 * i + c_k] * localB->U_f[9 * localB->d +
              i];
          }
        }
      }

      for (localB->d = 0; localB->d < 81; localB->d++) {
        localB->U_f[localB->d] = localB->A_g[localB->d];
        localB->A4[localB->d] = (56.0F * localB->A4[localB->d] + 25200.0F *
          localB->A3[localB->d]) + 1.99584E+6F * localB->A2[localB->d];
      }

      localB->d = 17297280;
    }
  }

  for (c_k = 0; c_k < 9; c_k++) {
    A2_tmp = 9 * c_k + c_k;
    localB->A4[A2_tmp] += static_cast<real32_T>(localB->d);
  }

  for (localB->d = 0; localB->d < 81; localB->d++) {
    U = localB->U_f[localB->d];
    A4 = localB->A4[localB->d] - U;
    U *= 2.0F;
    localB->A4[localB->d] = A4;
    localB->U_f[localB->d] = U;
  }

  Controller_MPC_lusolve(localB->A4, localB->U_f, F, localB);
  for (localB->d = 0; localB->d < 9; localB->d++) {
    c_k = 9 * localB->d + localB->d;
    F[c_k]++;
  }
}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T tmp;
  real32_T tmp_0;
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else {
    tmp = static_cast<real32_T>(fabs(static_cast<real_T>(u0)));
    tmp_0 = static_cast<real32_T>(fabs(static_cast<real_T>(u1)));
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = static_cast<real32_T>(sqrt(static_cast<real_T>(u0)));
    } else if ((u0 < 0.0F) && (u1 > static_cast<real32_T>(floor
                 (static_cast<real_T>(u1))))) {
      y = (rtNaNF);
    } else {
      y = static_cast<real32_T>(pow(static_cast<real_T>(u0), static_cast<real_T>
        (u1)));
    }
  }

  return y;
}

// Function for MATLAB Function: '<S52>/Adaptive Model'
static void Controller_MPC_expm(real32_T A[81], real32_T F[81],
  B_PathFollowingControlSystem__T *localB)
{
  static const real32_T theta[3] = { 0.425873F, 1.8801527F, 3.92572474F };

  boolean_T exitg1;
  localB->normA = 0.0F;
  localB->b_j = 0;
  exitg1 = false;
  while ((!exitg1) && (localB->b_j < 9)) {
    localB->b_s = 0.0F;
    for (localB->b_i_m = 0; localB->b_i_m < 9; localB->b_i_m++) {
      localB->b_s += static_cast<real32_T>(fabs(static_cast<real_T>(A[9 *
        localB->b_j + localB->b_i_m])));
    }

    if (rtIsNaNF(localB->b_s)) {
      localB->normA = (rtNaNF);
      exitg1 = true;
    } else {
      if (localB->b_s > localB->normA) {
        localB->normA = localB->b_s;
      }

      localB->b_j++;
    }
  }

  if (localB->normA <= 3.92572474F) {
    localB->b_j = 0;
    exitg1 = false;
    while ((!exitg1) && (localB->b_j < 3)) {
      if (localB->normA <= theta[localB->b_j]) {
        Control_PadeApproximantOfDegree(A, static_cast<uint8_T>((localB->b_j <<
          1) + 3), F, localB);
        exitg1 = true;
      } else {
        localB->b_j++;
      }
    }
  } else {
    localB->b_s = localB->normA / 3.92572474F;
    if ((!rtIsInfF(localB->b_s)) && (!rtIsNaNF(localB->b_s))) {
      localB->b_s = static_cast<real32_T>(frexp(static_cast<real_T>(localB->b_s),
        &localB->eint));
      localB->normA = static_cast<real32_T>(localB->eint);
    } else {
      localB->normA = 0.0F;
    }

    if (localB->b_s == 0.5F) {
      localB->normA--;
    }

    localB->b_s = rt_powf_snf(2.0F, localB->normA);
    for (localB->b_j = 0; localB->b_j < 81; localB->b_j++) {
      A[localB->b_j] /= localB->b_s;
    }

    Control_PadeApproximantOfDegree(A, 7, F, localB);
    localB->b_i_m = 0;
    while (localB->b_i_m <= static_cast<int32_T>(localB->normA) - 1) {
      for (localB->b_j = 0; localB->b_j < 9; localB->b_j++) {
        for (localB->eint = 0; localB->eint < 9; localB->eint++) {
          localB->F_tmp = localB->b_j + 9 * localB->eint;
          localB->F[localB->F_tmp] = 0.0F;
          for (localB->i1_c = 0; localB->i1_c < 9; localB->i1_c++) {
            localB->F[localB->F_tmp] += F[9 * localB->i1_c + localB->b_j] * F[9 *
              localB->eint + localB->i1_c];
          }
        }
      }

      memcpy(&F[0], &localB->F[0], 81U * sizeof(real32_T));
      localB->b_i_m++;
    }
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_mpc_plantupdate(const real32_T a[81], real32_T b[27],
  const real32_T c[27], const real32_T d[9], real32_T b_A[100], real32_T b_B[80],
  real32_T b_C[30], real32_T b_D[24], const real32_T b_mvindex[2], const
  real32_T b_myindex[3], const real32_T b_Uscale[3], const real32_T b_Yscale[3],
  real32_T Bu[20], real32_T Bv[20], real32_T Cm[30], real32_T Dv[6], real32_T
  Dvm[6], real32_T QQ[100], real32_T RR[9], real32_T NN[30],
  B_PathFollowingControlSystem__T *localB)
{
  int32_T CovMat_tmp;
  int32_T Dv_tmp;
  int32_T b_tmp;
  int32_T i;
  int8_T UnknownIn[7];
  for (i = 0; i < 3; i++) {
    for (Dv_tmp = 0; Dv_tmp < 9; Dv_tmp++) {
      b_tmp = 9 * i + Dv_tmp;
      b[b_tmp] *= b_Uscale[i];
    }
  }

  for (i = 0; i < 9; i++) {
    b_C[3 * i] = c[3 * i] / b_Yscale[0];
    Dv_tmp = 3 * i + 1;
    b_C[Dv_tmp] = c[Dv_tmp] / b_Yscale[1];
    Dv_tmp = 3 * i + 2;
    b_C[Dv_tmp] = c[Dv_tmp] / b_Yscale[2];
    for (Dv_tmp = 0; Dv_tmp < 9; Dv_tmp++) {
      b_A[Dv_tmp + 10 * i] = a[9 * i + Dv_tmp];
    }
  }

  for (i = 0; i < 2; i++) {
    for (Dv_tmp = 0; Dv_tmp < 9; Dv_tmp++) {
      b_B[Dv_tmp + 10 * i] = b[(static_cast<int32_T>(b_mvindex[i]) - 1) * 9 +
        Dv_tmp];
    }
  }

  for (i = 0; i < 9; i++) {
    b_B[i + 20] = b[i + 18];
  }

  b_D[6] = d[6] / b_Yscale[0] * b_Uscale[2];
  b_D[7] = d[7] / b_Yscale[1] * b_Uscale[2];
  b_D[8] = d[8] / b_Yscale[2] * b_Uscale[2];
  for (i = 0; i < 2; i++) {
    for (Dv_tmp = 0; Dv_tmp < 10; Dv_tmp++) {
      b_tmp = 10 * i + Dv_tmp;
      Bu[Dv_tmp + 10 * i] = b_B[b_tmp];
      Bv[b_tmp] = b_B[(i + 2) * 10 + Dv_tmp];
    }
  }

  for (i = 0; i < 10; i++) {
    Cm[3 * i] = b_C[(3 * i + static_cast<int32_T>(b_myindex[0])) - 1];
    Cm[3 * i + 1] = b_C[(3 * i + static_cast<int32_T>(b_myindex[1])) - 1];
    Cm[3 * i + 2] = b_C[(3 * i + static_cast<int32_T>(b_myindex[2])) - 1];
  }

  for (i = 0; i < 2; i++) {
    Dv_tmp = (i + 2) * 3;
    Dv[3 * i] = b_D[Dv_tmp];
    Dvm[3 * i] = b_D[(Dv_tmp + static_cast<int32_T>(b_myindex[0])) - 1];
    b_tmp = 3 * i + 1;
    Dv[b_tmp] = b_D[Dv_tmp + 1];
    Dvm[b_tmp] = b_D[(Dv_tmp + static_cast<int32_T>(b_myindex[1])) - 1];
    b_tmp = 3 * i + 2;
    Dv[b_tmp] = b_D[Dv_tmp + 2];
    Dvm[b_tmp] = b_D[(Dv_tmp + static_cast<int32_T>(b_myindex[2])) - 1];
  }

  UnknownIn[0] = 1;
  UnknownIn[1] = 2;
  UnknownIn[2] = 3;
  UnknownIn[3] = 5;
  UnknownIn[4] = 6;
  UnknownIn[5] = 7;
  UnknownIn[6] = 8;
  for (i = 0; i < 7; i++) {
    for (Dv_tmp = 0; Dv_tmp < 10; Dv_tmp++) {
      localB->b_B[Dv_tmp + 13 * i] = b_B[(UnknownIn[i] - 1) * 10 + Dv_tmp];
    }

    Dv_tmp = (UnknownIn[i] - 1) * 3;
    localB->b_B[13 * i + 10] = b_D[(Dv_tmp + static_cast<int32_T>(b_myindex[0]))
      - 1];
    localB->b_B[13 * i + 11] = b_D[(Dv_tmp + static_cast<int32_T>(b_myindex[1]))
      - 1];
    localB->b_B[13 * i + 12] = b_D[(Dv_tmp + static_cast<int32_T>(b_myindex[2]))
      - 1];
  }

  for (i = 0; i < 10; i++) {
    for (Dv_tmp = 0; Dv_tmp < 7; Dv_tmp++) {
      localB->b_B_b[Dv_tmp + 7 * i] = b_B[(UnknownIn[Dv_tmp] - 1) * 10 + i];
    }
  }

  for (i = 0; i < 3; i++) {
    for (Dv_tmp = 0; Dv_tmp < 7; Dv_tmp++) {
      localB->b_B_b[Dv_tmp + 7 * (i + 10)] = b_D[((UnknownIn[Dv_tmp] - 1) * 3 +
        static_cast<int32_T>(b_myindex[i])) - 1];
    }
  }

  for (i = 0; i < 13; i++) {
    for (Dv_tmp = 0; Dv_tmp < 13; Dv_tmp++) {
      CovMat_tmp = Dv_tmp + 13 * i;
      localB->CovMat[CovMat_tmp] = 0.0F;
      for (b_tmp = 0; b_tmp < 7; b_tmp++) {
        localB->CovMat[CovMat_tmp] += localB->b_B[13 * b_tmp + Dv_tmp] *
          localB->b_B_b[7 * i + b_tmp];
      }
    }
  }

  for (i = 0; i < 10; i++) {
    for (Dv_tmp = 0; Dv_tmp < 10; Dv_tmp++) {
      QQ[Dv_tmp + 10 * i] = localB->CovMat[13 * i + Dv_tmp];
    }
  }

  for (i = 0; i < 3; i++) {
    b_tmp = (i + 10) * 13;
    RR[3 * i] = localB->CovMat[b_tmp + 10];
    RR[3 * i + 1] = localB->CovMat[b_tmp + 11];
    RR[3 * i + 2] = localB->CovMat[b_tmp + 12];
    for (Dv_tmp = 0; Dv_tmp < 10; Dv_tmp++) {
      NN[Dv_tmp + 10 * i] = localB->CovMat[b_tmp + Dv_tmp];
    }
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static real32_T Controller_MPC_mod(real32_T x)
{
  real32_T r;
  if (rtIsNaNF(x)) {
    r = (rtNaNF);
  } else if (rtIsInfF(x)) {
    r = (rtNaNF);
  } else if (x == 0.0F) {
    r = 0.0F;
  } else {
    r = static_cast<real32_T>(fmod(static_cast<real_T>(x), static_cast<real_T>
      (Controller_MPC_ny)));
    if (r == 0.0F) {
      r = 0.0F;
    } else {
      if (x < 0.0F) {
        r += Controller_MPC_ny;
      }
    }
  }

  return r;
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static real32_T Controller_MPC_mod_l(real32_T x)
{
  real32_T r;
  if (rtIsNaNF(x)) {
    r = (rtNaNF);
  } else if (rtIsInfF(x)) {
    r = (rtNaNF);
  } else if (x == 0.0F) {
    r = 0.0F;
  } else {
    r = static_cast<real32_T>(fmod(static_cast<real_T>(x), static_cast<real_T>
      (Controller_MPC_nu)));
    if (r == 0.0F) {
      r = 0.0F;
    } else {
      if (x < 0.0F) {
        r += Controller_MPC_nu;
      }
    }
  }

  return r;
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controlle_mpc_updateFromNominal(real32_T b_Mlim[20], const real32_T
  b_Mrows[20], const real32_T U0[3], const real32_T b_Uscale[3], const real32_T
  old_mvoff[2], const real32_T b_mvindex[2], real32_T b_utarget[120], const
  real32_T Y0[3], const real32_T b_Yscale[3], const real32_T old_yoff[3], const
  real32_T b_myindex[3], const real32_T X0[9], real32_T b_xoff[10], const
  real32_T DX0[9], real32_T Bv[1220], real32_T new_mvoff[2], real32_T *new_mdoff,
  real32_T new_yoff[3], real32_T new_myoff[3])
{
  int32_T b_utarget_tmp;
  int32_T i;
  int32_T i_0;
  real32_T U[3];
  real32_T U_0;
  real32_T k;
  U[0] = U0[0] / b_Uscale[0];
  new_yoff[0] = Y0[0] / b_Yscale[0];
  U[1] = U0[1] / b_Uscale[1];
  new_yoff[1] = Y0[1] / b_Yscale[1];
  U[2] = U0[2] / b_Uscale[2];
  new_yoff[2] = Y0[2] / b_Yscale[2];
  new_mvoff[0] = U[static_cast<int32_T>(b_mvindex[0]) - 1];
  new_mvoff[1] = U[static_cast<int32_T>(b_mvindex[1]) - 1];
  *new_mdoff = U[2];
  new_myoff[0] = new_yoff[static_cast<int32_T>(b_myindex[0]) - 1];
  new_myoff[1] = new_yoff[static_cast<int32_T>(b_myindex[1]) - 1];
  new_myoff[2] = new_yoff[static_cast<int32_T>(b_myindex[2]) - 1];
  for (i = 0; i < 20; i++) {
    k = b_Mrows[i];
    if (k <= 180.0F) {
      k = Controller_MPC_mod(k - 1.0F) + 1.0F;
      b_Mlim[i] += old_yoff[static_cast<int32_T>(k) - 1] - new_yoff[static_cast<
        int32_T>(k) - 1];
    } else if (k <= 360.0F) {
      k = Controller_MPC_mod((k - 180.0F) - 1.0F) + 1.0F;
      b_Mlim[i] -= old_yoff[static_cast<int32_T>(k) - 1] - new_yoff[static_cast<
        int32_T>(k) - 1];
    } else if (k <= 480.0F) {
      k = Controller_MPC_mod_l((k - 360.0F) - 1.0F) + 1.0F;
      b_Mlim[i] += old_mvoff[static_cast<int32_T>(k) - 1] - U
        [static_cast<int32_T>(b_mvindex[static_cast<int32_T>(k) - 1]) - 1];
    } else {
      if (k <= 600.0F) {
        k = Controller_MPC_mod_l(((k - 360.0F) - 120.0F) - 1.0F) + 1.0F;
        b_Mlim[i] -= old_mvoff[static_cast<int32_T>(k) - 1] - U[static_cast<
          int32_T>(b_mvindex[static_cast<int32_T>(k) - 1]) - 1];
      }
    }
  }

  for (i = 0; i < 2; i++) {
    k = old_mvoff[i];
    U_0 = U[static_cast<int32_T>(b_mvindex[i]) - 1];
    for (i_0 = 0; i_0 < 60; i_0++) {
      b_utarget_tmp = (i_0 << 1) + i;
      b_utarget[b_utarget_tmp] = (b_utarget[b_utarget_tmp] + k) - U_0;
    }
  }

  for (i = 0; i < 9; i++) {
    b_xoff[i] = X0[i];
    Bv[i + 10] = DX0[i];
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_M_mpc_constraintcoef(const real32_T b_A[100], const
  real32_T Bu[20], const real32_T Bv[20], const real32_T b_C[30], const real32_T
  Dv[6], const real32_T b_Jm[1200], real32_T b_SuJm[1800], real32_T b_Sx[1800],
  real32_T b_Su1[360], real32_T b_Hv[21960], B_PathFollowingControlSystem__T
  *localB)
{
  int32_T CA_tmp;
  int32_T Sum_tmp;
  int32_T b_Hv_tmp;
  int32_T b_Hv_tmp_0;
  int32_T i_0;
  real32_T b_C_0;
  real32_T b_Su1_tmp;
  real32_T b_Su1_tmp_0;
  uint8_T rows[3];
  uint8_T i;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (b_Hv_tmp_0 = 0; b_Hv_tmp_0 < 10; b_Hv_tmp_0++) {
      CA_tmp = i_0 + 3 * b_Hv_tmp_0;
      localB->CA_p[CA_tmp] = 0.0F;
      for (b_Hv_tmp = 0; b_Hv_tmp < 10; b_Hv_tmp++) {
        localB->CA_p[CA_tmp] += b_C[3 * b_Hv_tmp + i_0] * b_A[10 * b_Hv_tmp_0 +
          b_Hv_tmp];
      }
    }

    for (b_Hv_tmp_0 = 0; b_Hv_tmp_0 < 2; b_Hv_tmp_0++) {
      CA_tmp = i_0 + 3 * b_Hv_tmp_0;
      localB->Sum_o[CA_tmp] = 0.0F;
      localB->b_C_b[CA_tmp] = 0.0F;
      for (b_Hv_tmp = 0; b_Hv_tmp < 10; b_Hv_tmp++) {
        b_C_0 = b_C[3 * b_Hv_tmp + i_0];
        Sum_tmp = 10 * b_Hv_tmp_0 + b_Hv_tmp;
        localB->Sum_o[CA_tmp] += Bu[Sum_tmp] * b_C_0;
        localB->b_C_b[CA_tmp] += Bv[Sum_tmp] * b_C_0;
      }
    }
  }

  for (i_0 = 0; i_0 < 2; i_0++) {
    b_Hv[180 * i_0] = localB->b_C_b[3 * i_0];
    b_Hv_tmp_0 = 180 * (i_0 + 2);
    b_Hv[b_Hv_tmp_0] = Dv[3 * i_0];
    b_Hv_tmp = 3 * i_0 + 1;
    b_Hv[180 * i_0 + 1] = localB->b_C_b[b_Hv_tmp];
    b_Hv[b_Hv_tmp_0 + 1] = Dv[b_Hv_tmp];
    b_Hv_tmp = 3 * i_0 + 2;
    b_Hv[180 * i_0 + 2] = localB->b_C_b[b_Hv_tmp];
    b_Hv[b_Hv_tmp_0 + 2] = Dv[b_Hv_tmp];
  }

  for (i_0 = 0; i_0 < 118; i_0++) {
    b_Hv_tmp_0 = 180 * (i_0 + 4);
    b_Hv[b_Hv_tmp_0] = 0.0F;
    b_Hv[b_Hv_tmp_0 + 1] = 0.0F;
    b_Hv[b_Hv_tmp_0 + 2] = 0.0F;
  }

  for (i_0 = 0; i_0 < 122; i_0++) {
    memset(&b_Hv[i_0 * 180 + 3], 0, 177U * sizeof(real32_T));
  }

  for (i_0 = 0; i_0 < 10; i_0++) {
    b_Sx[180 * i_0] = localB->CA_p[3 * i_0];
    b_Sx[180 * i_0 + 1] = localB->CA_p[3 * i_0 + 1];
    b_Sx[180 * i_0 + 2] = localB->CA_p[3 * i_0 + 2];
    memset(&b_Sx[i_0 * 180 + 3], 0, 177U * sizeof(real32_T));
  }

  for (i_0 = 0; i_0 < 2; i_0++) {
    b_C_0 = localB->Sum_o[3 * i_0];
    b_Su1[180 * i_0] = b_C_0;
    b_Su1_tmp = localB->Sum_o[3 * i_0 + 1];
    b_Hv_tmp_0 = 180 * i_0 + 1;
    b_Su1[b_Hv_tmp_0] = b_Su1_tmp;
    b_Su1_tmp_0 = localB->Sum_o[3 * i_0 + 2];
    b_Hv_tmp = 180 * i_0 + 2;
    b_Su1[b_Hv_tmp] = b_Su1_tmp_0;
    memset(&b_Su1[i_0 * 180 + 3], 0, 177U * sizeof(real32_T));
    localB->Su[180 * i_0] = b_C_0;
    localB->Su[b_Hv_tmp_0] = b_Su1_tmp;
    localB->Su[b_Hv_tmp] = b_Su1_tmp_0;
  }

  for (i_0 = 0; i_0 < 118; i_0++) {
    b_Hv_tmp_0 = 180 * (i_0 + 2);
    localB->Su[b_Hv_tmp_0] = 0.0F;
    localB->Su[b_Hv_tmp_0 + 1] = 0.0F;
    localB->Su[b_Hv_tmp_0 + 2] = 0.0F;
  }

  for (i_0 = 0; i_0 < 120; i_0++) {
    memset(&localB->Su[i_0 * 180 + 3], 0, 177U * sizeof(real32_T));
  }

  for (Sum_tmp = 0; Sum_tmp < 59; Sum_tmp++) {
    i = static_cast<uint8_T>((Sum_tmp + 1) * 3U + 1U);
    for (i_0 = 0; i_0 < 3; i_0++) {
      rows[i_0] = static_cast<uint8_T>(static_cast<uint32_T>(i_0) + i);
      for (b_Hv_tmp_0 = 0; b_Hv_tmp_0 < 2; b_Hv_tmp_0++) {
        b_C_0 = 0.0F;
        for (b_Hv_tmp = 0; b_Hv_tmp < 10; b_Hv_tmp++) {
          b_C_0 += localB->CA_p[3 * b_Hv_tmp + i_0] * Bu[10 * b_Hv_tmp_0 +
            b_Hv_tmp];
        }

        CA_tmp = 3 * b_Hv_tmp_0 + i_0;
        localB->Sum_o[CA_tmp] += b_C_0;
      }
    }

    for (i_0 = 0; i_0 < 2; i_0++) {
      b_C_0 = localB->Sum_o[3 * i_0];
      b_Su1[(rows[0] + 180 * i_0) - 1] = b_C_0;
      localB->Sum[3 * i_0] = b_C_0;
      CA_tmp = 3 * i_0 + 1;
      b_C_0 = localB->Sum_o[CA_tmp];
      b_Su1[(rows[1] + 180 * i_0) - 1] = b_C_0;
      localB->Sum[CA_tmp] = b_C_0;
      CA_tmp = 3 * i_0 + 2;
      b_C_0 = localB->Sum_o[CA_tmp];
      b_Su1[(rows[2] + 180 * i_0) - 1] = b_C_0;
      localB->Sum[CA_tmp] = b_C_0;
    }

    for (i_0 = 0; i_0 < 118; i_0++) {
      CA_tmp = 3 * (i_0 + 2);
      localB->Sum[CA_tmp] = localB->Su[(180 * i_0 + rows[0]) - 4];
      localB->Sum[CA_tmp + 1] = localB->Su[(180 * i_0 + rows[1]) - 4];
      localB->Sum[CA_tmp + 2] = localB->Su[(180 * i_0 + rows[2]) - 4];
    }

    for (i_0 = 0; i_0 < 120; i_0++) {
      localB->Su[(rows[0] + 180 * i_0) - 1] = localB->Sum[3 * i_0];
      localB->Su[(rows[1] + 180 * i_0) - 1] = localB->Sum[3 * i_0 + 1];
      localB->Su[(rows[2] + 180 * i_0) - 1] = localB->Sum[3 * i_0 + 2];
    }

    for (i_0 = 0; i_0 < 3; i_0++) {
      for (b_Hv_tmp_0 = 0; b_Hv_tmp_0 < 2; b_Hv_tmp_0++) {
        CA_tmp = i_0 + 3 * b_Hv_tmp_0;
        localB->b_C_b[CA_tmp] = 0.0F;
        for (b_Hv_tmp = 0; b_Hv_tmp < 10; b_Hv_tmp++) {
          localB->b_C_b[CA_tmp] += localB->CA_p[3 * b_Hv_tmp + i_0] * Bv[10 *
            b_Hv_tmp_0 + b_Hv_tmp];
        }
      }
    }

    for (i_0 = 0; i_0 < 2; i_0++) {
      localB->CA[3 * i_0] = localB->b_C_b[3 * i_0];
      CA_tmp = 3 * i_0 + 1;
      localB->CA[CA_tmp] = localB->b_C_b[CA_tmp];
      CA_tmp = 3 * i_0 + 2;
      localB->CA[CA_tmp] = localB->b_C_b[CA_tmp];
    }

    for (i_0 = 0; i_0 < 120; i_0++) {
      CA_tmp = 3 * (i_0 + 2);
      localB->CA[CA_tmp] = b_Hv[(180 * i_0 + rows[0]) - 4];
      localB->CA[CA_tmp + 1] = b_Hv[(180 * i_0 + rows[1]) - 4];
      localB->CA[CA_tmp + 2] = b_Hv[(180 * i_0 + rows[2]) - 4];
    }

    for (i_0 = 0; i_0 < 122; i_0++) {
      b_Hv[(rows[0] + 180 * i_0) - 1] = localB->CA[3 * i_0];
      b_Hv[(rows[1] + 180 * i_0) - 1] = localB->CA[3 * i_0 + 1];
      b_Hv[(rows[2] + 180 * i_0) - 1] = localB->CA[3 * i_0 + 2];
    }

    for (i_0 = 0; i_0 < 3; i_0++) {
      for (b_Hv_tmp_0 = 0; b_Hv_tmp_0 < 10; b_Hv_tmp_0++) {
        CA_tmp = i_0 + 3 * b_Hv_tmp_0;
        localB->CA_l[CA_tmp] = 0.0F;
        for (b_Hv_tmp = 0; b_Hv_tmp < 10; b_Hv_tmp++) {
          localB->CA_l[CA_tmp] += localB->CA_p[3 * b_Hv_tmp + i_0] * b_A[10 *
            b_Hv_tmp_0 + b_Hv_tmp];
        }
      }
    }

    memcpy(&localB->CA_p[0], &localB->CA_l[0], 30U * sizeof(real32_T));
    for (i_0 = 0; i_0 < 10; i_0++) {
      b_Sx[(rows[0] + 180 * i_0) - 1] = localB->CA_p[3 * i_0];
      b_Sx[(rows[1] + 180 * i_0) - 1] = localB->CA_p[3 * i_0 + 1];
      b_Sx[(rows[2] + 180 * i_0) - 1] = localB->CA_p[3 * i_0 + 2];
    }
  }

  for (i_0 = 0; i_0 < 10; i_0++) {
    for (b_Hv_tmp_0 = 0; b_Hv_tmp_0 < 180; b_Hv_tmp_0++) {
      CA_tmp = b_Hv_tmp_0 + 180 * i_0;
      b_SuJm[CA_tmp] = 0.0F;
      for (b_Hv_tmp = 0; b_Hv_tmp < 120; b_Hv_tmp++) {
        b_SuJm[CA_tmp] += localB->Su[180 * b_Hv_tmp + b_Hv_tmp_0] * b_Jm[120 *
          i_0 + b_Hv_tmp];
      }
    }
  }
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if (static_cast<real32_T>(fabs(static_cast<real_T>(u))) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = static_cast<real32_T>(floor(static_cast<real_T>(u + 0.5F)));
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = static_cast<real32_T>(ceil(static_cast<real_T>(u - 0.5F)));
    }
  } else {
    y = u;
  }

  return y;
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_WtMult(const real32_T W[2], const real32_T M[1200],
  real32_T nwt, real32_T WM[1200])
{
  int32_T WM_tmp;
  int32_T i;
  int32_T i_0;
  real32_T W_0;
  int16_T ixw;
  ixw = 1;
  for (i = 0; i < 120; i++) {
    W_0 = W[ixw - 1];
    for (i_0 = 0; i_0 < 10; i_0++) {
      WM_tmp = 120 * i_0 + i;
      WM[WM_tmp] = M[WM_tmp] * W_0;
    }

    i_0 = ixw + 1;
    if (ixw + 1 > 32767) {
      i_0 = 32767;
    }

    ixw = static_cast<int16_T>(i_0);
    if (static_cast<int16_T>(i_0) > 2) {
      W_0 = rt_roundf_snf(2.0F - nwt);
      if (W_0 < 32768.0F) {
        if (W_0 >= -32768.0F) {
          ixw = static_cast<int16_T>(W_0);
        } else {
          ixw = MIN_int16_T;
        }
      } else {
        ixw = MAX_int16_T;
      }

      i_0 = ixw + 1;
      if (W_0 < 32768.0F) {
        if (W_0 >= -32768.0F) {
          ixw = static_cast<int16_T>(W_0);
        } else {
          ixw = MIN_int16_T;
        }
      } else {
        ixw = MAX_int16_T;
      }

      if (ixw + 1 > 32767) {
        i_0 = 32767;
      }

      ixw = static_cast<int16_T>(i_0);
    }
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_mpc_calculatehessian(const real32_T b_Wy[3], const
  real32_T b_Wu[2], const real32_T b_Wdu[2], const real32_T b_SuJm[1800], const
  real32_T I2Jm[1200], const real32_T b_Jm[1200], const real32_T b_I1[240],
  const real32_T b_Su1[360], const real32_T b_Sx[1800], const real32_T b_Hv
  [21960], real32_T nmv, real32_T b_ny, real32_T b_H[100], real32_T b_Ku1[20],
  real32_T b_Kut[1200], real32_T b_Kx[100], real32_T b_Kv[1220], real32_T b_Kr
  [1800], B_PathFollowingControlSystem__T *localB)
{
  int32_T b_Kr_tmp;
  int32_T b_SuJm_tmp;
  int32_T i;
  int32_T i_0;
  int32_T tmp;
  int32_T tmp_0;
  real32_T b_Wy_0;
  int16_T ixw;
  ixw = 1;
  for (i = 0; i < 180; i++) {
    b_Wy_0 = b_Wy[ixw - 1];
    for (i_0 = 0; i_0 < 10; i_0++) {
      b_Kr_tmp = 180 * i_0 + i;
      b_Kr[b_Kr_tmp] = b_SuJm[b_Kr_tmp] * b_Wy_0;
    }

    i_0 = ixw + 1;
    if (ixw + 1 > 32767) {
      i_0 = 32767;
    }

    ixw = static_cast<int16_T>(i_0);
    if (static_cast<int16_T>(i_0) > 3) {
      b_Wy_0 = rt_roundf_snf(3.0F - b_ny);
      if (b_Wy_0 < 32768.0F) {
        if (b_Wy_0 >= -32768.0F) {
          ixw = static_cast<int16_T>(b_Wy_0);
        } else {
          ixw = MIN_int16_T;
        }
      } else {
        ixw = MAX_int16_T;
      }

      i_0 = ixw + 1;
      if (b_Wy_0 < 32768.0F) {
        if (b_Wy_0 >= -32768.0F) {
          ixw = static_cast<int16_T>(b_Wy_0);
        } else {
          ixw = MIN_int16_T;
        }
      } else {
        ixw = MAX_int16_T;
      }

      if (ixw + 1 > 32767) {
        i_0 = 32767;
      }

      ixw = static_cast<int16_T>(i_0);
    }
  }

  Controller_MPC_WtMult(b_Wu, I2Jm, nmv, b_Kut);
  Controller_MPC_WtMult(b_Wdu, b_Jm, nmv, localB->fv2);
  for (i_0 = 0; i_0 < 10; i_0++) {
    for (i = 0; i < 10; i++) {
      b_SuJm_tmp = i_0 + 10 * i;
      localB->b_SuJm[b_SuJm_tmp] = 0.0F;
      for (b_Kr_tmp = 0; b_Kr_tmp < 180; b_Kr_tmp++) {
        localB->b_SuJm[b_SuJm_tmp] += b_SuJm[180 * i_0 + b_Kr_tmp] * b_Kr[180 *
          i + b_Kr_tmp];
      }

      localB->b_Jm[b_SuJm_tmp] = 0.0F;
      b_Wy_0 = 0.0F;
      for (b_Kr_tmp = 0; b_Kr_tmp < 120; b_Kr_tmp++) {
        tmp = 120 * i_0 + b_Kr_tmp;
        tmp_0 = 120 * i + b_Kr_tmp;
        b_Wy_0 += I2Jm[tmp] * b_Kut[tmp_0];
        localB->b_Jm[b_SuJm_tmp] += b_Jm[tmp] * localB->fv2[tmp_0];
      }

      b_H[b_SuJm_tmp] = (localB->b_SuJm[b_SuJm_tmp] + localB->b_Jm[b_SuJm_tmp])
        + b_Wy_0;
    }
  }

  for (i_0 = 0; i_0 < 2; i_0++) {
    for (i = 0; i < 10; i++) {
      b_SuJm_tmp = i_0 + (i << 1);
      localB->b_Su1[b_SuJm_tmp] = 0.0F;
      for (b_Kr_tmp = 0; b_Kr_tmp < 180; b_Kr_tmp++) {
        localB->b_Su1[b_SuJm_tmp] += b_Su1[180 * i_0 + b_Kr_tmp] * b_Kr[180 * i
          + b_Kr_tmp];
      }

      localB->b_I1[b_SuJm_tmp] = 0.0F;
      for (b_Kr_tmp = 0; b_Kr_tmp < 120; b_Kr_tmp++) {
        localB->b_I1[b_SuJm_tmp] += b_I1[120 * i_0 + b_Kr_tmp] * b_Kut[120 * i +
          b_Kr_tmp];
      }
    }
  }

  for (i_0 = 0; i_0 < 20; i_0++) {
    b_Ku1[i_0] = localB->b_Su1[i_0] + localB->b_I1[i_0];
  }

  for (i_0 = 0; i_0 < 1200; i_0++) {
    b_Kut[i_0] = -b_Kut[i_0];
  }

  for (i_0 = 0; i_0 < 10; i_0++) {
    for (i = 0; i < 10; i++) {
      b_SuJm_tmp = i_0 + 10 * i;
      b_Kx[b_SuJm_tmp] = 0.0F;
      for (b_Kr_tmp = 0; b_Kr_tmp < 180; b_Kr_tmp++) {
        b_Kx[b_SuJm_tmp] += b_Sx[180 * i_0 + b_Kr_tmp] * b_Kr[180 * i + b_Kr_tmp];
      }
    }
  }

  for (i_0 = 0; i_0 < 122; i_0++) {
    for (i = 0; i < 10; i++) {
      b_SuJm_tmp = i_0 + 122 * i;
      b_Kv[b_SuJm_tmp] = 0.0F;
      for (b_Kr_tmp = 0; b_Kr_tmp < 180; b_Kr_tmp++) {
        b_Kv[b_SuJm_tmp] += b_Hv[180 * i_0 + b_Kr_tmp] * b_Kr[180 * i + b_Kr_tmp];
      }
    }
  }

  for (i_0 = 0; i_0 < 1800; i_0++) {
    b_Kr[i_0] = -b_Kr[i_0];
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static int32_T Controller_MPC_xpotrf(real32_T b_A[121])
{
  int32_T b_ix;
  int32_T b_iy;
  int32_T b_k;
  int32_T d;
  int32_T ia;
  int32_T idxAjj;
  int32_T info;
  int32_T iy;
  int32_T j;
  real32_T c;
  real32_T ssq;
  boolean_T exitg1;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 11)) {
    idxAjj = j * 11 + j;
    ssq = 0.0F;
    if (j >= 1) {
      b_ix = j;
      b_iy = j;
      for (b_k = 0; b_k < j; b_k++) {
        ssq += b_A[b_ix] * b_A[b_iy];
        b_ix += 11;
        b_iy += 11;
      }
    }

    ssq = b_A[idxAjj] - ssq;
    if (ssq > 0.0F) {
      ssq = static_cast<real32_T>(sqrt(static_cast<real_T>(ssq)));
      b_A[idxAjj] = ssq;
      if (j + 1 < 11) {
        if (j != 0) {
          b_ix = j;
          b_iy = ((j - 1) * 11 + j) + 2;
          for (b_k = j + 2; b_k <= b_iy; b_k += 11) {
            c = -b_A[b_ix];
            iy = idxAjj + 1;
            d = (b_k - j) + 9;
            for (ia = b_k; ia <= d; ia++) {
              b_A[iy] += b_A[ia - 1] * c;
              iy++;
            }

            b_ix += 11;
          }
        }

        ssq = 1.0F / ssq;
        b_ix = (idxAjj - j) + 11;
        for (idxAjj++; idxAjj < b_ix; idxAjj++) {
          b_A[idxAjj] *= ssq;
        }
      }

      j++;
    } else {
      b_A[idxAjj] = ssq;
      info = j + 1;
      exitg1 = true;
    }
  }

  return info;
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static real32_T Controller_MPC_minimum(const real32_T x[11])
{
  int32_T idx;
  int32_T k;
  real32_T ex;
  boolean_T exitg1;
  if (!rtIsNaNF(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!rtIsNaNF(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 <= 11) {
      if (ex > x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_mpc_checkhessian(real32_T b_H[121], real32_T L[121],
  real32_T *BadH, B_PathFollowingControlSystem__T *localB)
{
  int32_T Tries;
  int32_T j;
  real32_T normH;
  real32_T s;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *BadH = 0.0F;
  memcpy(&L[0], &b_H[0], 121U * sizeof(real32_T));
  Tries = Controller_MPC_xpotrf(L);
  guard1 = false;
  if (Tries == 0) {
    for (Tries = 0; Tries < 11; Tries++) {
      localB->varargin_1[Tries] = L[11 * Tries + Tries];
    }

    if (Controller_MPC_minimum(localB->varargin_1) > 1.49011612E-7F) {
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    normH = 0.0F;
    Tries = 0;
    exitg2 = false;
    while ((!exitg2) && (Tries < 11)) {
      s = 0.0F;
      for (j = 0; j < 11; j++) {
        s += static_cast<real32_T>(fabs(static_cast<real_T>(b_H[11 * j + Tries])));
      }

      if (rtIsNaNF(s)) {
        normH = (rtNaNF);
        exitg2 = true;
      } else {
        if (s > normH) {
          normH = s;
        }

        Tries++;
      }
    }

    if (normH >= 1.0E+10F) {
      *BadH = 2.0F;
    } else {
      Tries = 0;
      exitg1 = false;
      while ((!exitg1) && (Tries <= 4)) {
        normH = rt_powf_snf(10.0F, static_cast<real32_T>(Tries)) *
          1.49011612E-7F;
        memset(&localB->b_m[0], 0, 121U * sizeof(int8_T));
        for (j = 0; j < 11; j++) {
          localB->b_m[j + 11 * j] = 1;
        }

        for (j = 0; j < 121; j++) {
          s = normH * static_cast<real32_T>(localB->b_m[j]) + b_H[j];
          L[j] = s;
          b_H[j] = s;
        }

        j = Controller_MPC_xpotrf(L);
        guard2 = false;
        if (j == 0) {
          for (j = 0; j < 11; j++) {
            localB->varargin_1[j] = L[11 * j + j];
          }

          if (Controller_MPC_minimum(localB->varargin_1) > 1.49011612E-7F) {
            *BadH = 1.0F;
            exitg1 = true;
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          *BadH = 3.0F;
          Tries++;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_trisolve(const real32_T b_A[121], real32_T b_B[121])
{
  int32_T i;
  int32_T j;
  int32_T jBcol;
  int32_T k;
  int32_T kAcol;
  int32_T tmp;
  int32_T tmp_1;
  real32_T tmp_0;
  for (j = 0; j < 11; j++) {
    jBcol = 11 * j;
    for (k = 0; k < 11; k++) {
      kAcol = 11 * k;
      tmp = k + jBcol;
      tmp_0 = b_B[tmp];
      if (tmp_0 != 0.0F) {
        b_B[tmp] = tmp_0 / b_A[k + kAcol];
        for (i = k + 2; i < 12; i++) {
          tmp_1 = (i + jBcol) - 1;
          b_B[tmp_1] -= b_A[(i + kAcol) - 1] * b_B[tmp];
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_Unconstrained(const real32_T b_Hinv[121], const
  real32_T f[11], real32_T x[11], int16_T n)
{
  int32_T i;
  int32_T i_0;
  real32_T b_Hinv_0;
  for (i = 1; i - 1 < n; i++) {
    b_Hinv_0 = 0.0F;
    for (i_0 = 0; i_0 < 11; i_0++) {
      b_Hinv_0 += -b_Hinv[(11 * i_0 + static_cast<int16_T>(i)) - 1] * f[i_0];
    }

    x[static_cast<int16_T>(i) - 1] = b_Hinv_0;
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static real32_T Controller_MPC_norm(const real32_T x[11])
{
  int32_T k;
  real32_T absxk;
  real32_T scale;
  real32_T t;
  real32_T y;
  y = 0.0F;
  scale = 1.29246971E-26F;
  for (k = 0; k < 11; k++) {
    absxk = static_cast<real32_T>(fabs(static_cast<real_T>(x[k])));
    if (absxk > scale) {
      t = scale / absxk;
      y = y * t * t + 1.0F;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * static_cast<real32_T>(sqrt(static_cast<real_T>(y)));
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static real32_T Controller_MPC_xnrm2(int32_T n, const real32_T x[121], int32_T
  ix0)
{
  int32_T k;
  int32_T kend;
  real32_T absxk;
  real32_T scale;
  real32_T t;
  real32_T y;
  y = 0.0F;
  if (n >= 1) {
    if (n == 1) {
      y = static_cast<real32_T>(fabs(static_cast<real_T>(x[ix0 - 1])));
    } else {
      scale = 1.29246971E-26F;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = static_cast<real32_T>(fabs(static_cast<real_T>(x[k - 1])));
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0F;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * static_cast<real32_T>(sqrt(static_cast<real_T>(y)));
    }
  }

  return y;
}

real32_T rt_hypotf_snf(real32_T u0, real32_T u1)
{
  real32_T a;
  real32_T y;
  a = static_cast<real32_T>(fabs(static_cast<real_T>(u0)));
  y = static_cast<real32_T>(fabs(static_cast<real_T>(u1)));
  if (a < y) {
    a /= y;
    y *= static_cast<real32_T>(sqrt(static_cast<real_T>(a * a + 1.0F)));
  } else if (a > y) {
    y /= a;
    y = static_cast<real32_T>(sqrt(static_cast<real_T>(y * y + 1.0F))) * a;
  } else {
    if (!rtIsNaNF(y)) {
      y = a * 1.41421354F;
    }
  }

  return y;
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_xgemv(int32_T b_m, int32_T n, const real32_T b_A[121],
  int32_T ia0, const real32_T x[121], int32_T ix0, real32_T y[11])
{
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  real32_T c;
  if ((b_m != 0) && (n != 0)) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0F;
    }

    b_iy = 0;
    b = (n - 1) * 11 + ia0;
    for (iac = ia0; iac <= b; iac += 11) {
      ix = ix0;
      c = 0.0F;
      d = (iac + b_m) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += b_A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += c;
      b_iy++;
    }
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_xgerc(int32_T b_m, int32_T n, real32_T alpha1,
  int32_T ix0, const real32_T y[11], real32_T b_A[121], int32_T ia0)
{
  int32_T b;
  int32_T ijA;
  int32_T ix;
  int32_T j;
  int32_T jA;
  int32_T jy;
  real32_T temp;
  if (!(alpha1 == 0.0F)) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0F) {
        temp = y[jy] * alpha1;
        ix = ix0;
        b = b_m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          b_A[ijA] += b_A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 11;
    }
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_xgeqrf(real32_T b_A[121], real32_T tau[11],
  B_PathFollowingControlSystem__T *localB)
{
  int32_T exitg1;
  int32_T i;
  int32_T ia;
  boolean_T exitg2;
  for (i = 0; i < 11; i++) {
    tau[i] = 0.0F;
    localB->work_g[i] = 0.0F;
  }

  for (i = 0; i < 11; i++) {
    localB->ii_i = i * 11 + i;
    if (i + 1 < 11) {
      localB->b_atmp = b_A[localB->ii_i];
      tau[i] = 0.0F;
      localB->beta1 = Controller_MPC_xnrm2(10 - i, b_A, localB->ii_i + 2);
      if (localB->beta1 != 0.0F) {
        localB->beta1 = rt_hypotf_snf(b_A[localB->ii_i], localB->beta1);
        if (b_A[localB->ii_i] >= 0.0F) {
          localB->beta1 = -localB->beta1;
        }

        if (static_cast<real32_T>(fabs(static_cast<real_T>(localB->beta1))) <
            9.86076132E-32F) {
          localB->knt = -1;
          localB->lastc_o = localB->ii_i - i;
          do {
            localB->knt++;
            localB->coltop_n = localB->ii_i + 1;
            while (localB->coltop_n + 1 <= localB->lastc_o + 11) {
              b_A[localB->coltop_n] *= 1.01412048E+31F;
              localB->coltop_n++;
            }

            localB->beta1 *= 1.01412048E+31F;
            localB->b_atmp *= 1.01412048E+31F;
          } while (!(static_cast<real32_T>(fabs(static_cast<real_T>
                      (localB->beta1))) >= 9.86076132E-32F));

          localB->beta1 = rt_hypotf_snf(localB->b_atmp, Controller_MPC_xnrm2(10
            - i, b_A, localB->ii_i + 2));
          if (localB->b_atmp >= 0.0F) {
            localB->beta1 = -localB->beta1;
          }

          tau[i] = (localB->beta1 - localB->b_atmp) / localB->beta1;
          localB->b_atmp = 1.0F / (localB->b_atmp - localB->beta1);
          localB->coltop_n = localB->ii_i + 1;
          while (localB->coltop_n + 1 <= localB->lastc_o + 11) {
            b_A[localB->coltop_n] *= localB->b_atmp;
            localB->coltop_n++;
          }

          localB->lastc_o = 0;
          while (localB->lastc_o <= localB->knt) {
            localB->beta1 *= 9.86076132E-32F;
            localB->lastc_o++;
          }

          localB->b_atmp = localB->beta1;
        } else {
          tau[i] = (localB->beta1 - b_A[localB->ii_i]) / localB->beta1;
          localB->b_atmp = 1.0F / (b_A[localB->ii_i] - localB->beta1);
          localB->knt = localB->ii_i - i;
          localB->lastc_o = localB->ii_i + 1;
          while (localB->lastc_o + 1 <= localB->knt + 11) {
            b_A[localB->lastc_o] *= localB->b_atmp;
            localB->lastc_o++;
          }

          localB->b_atmp = localB->beta1;
        }
      }

      b_A[localB->ii_i] = localB->b_atmp;
      localB->b_atmp = b_A[localB->ii_i];
      b_A[localB->ii_i] = 1.0F;
      if (tau[i] != 0.0F) {
        localB->knt = 11 - i;
        localB->lastc_o = localB->ii_i - i;
        while ((localB->knt > 0) && (b_A[localB->lastc_o + 10] == 0.0F)) {
          localB->knt--;
          localB->lastc_o--;
        }

        localB->lastc_o = 10 - i;
        exitg2 = false;
        while ((!exitg2) && (localB->lastc_o > 0)) {
          localB->coltop_n = ((localB->lastc_o - 1) * 11 + localB->ii_i) + 11;
          ia = localB->coltop_n;
          do {
            exitg1 = 0;
            if (ia + 1 <= localB->coltop_n + localB->knt) {
              if (b_A[ia] != 0.0F) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              localB->lastc_o--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        localB->knt = 0;
        localB->lastc_o = 0;
      }

      if (localB->knt > 0) {
        Controller_MPC_xgemv(localB->knt, localB->lastc_o, b_A, localB->ii_i +
                             12, b_A, localB->ii_i + 1, localB->work_g);
        Controller_MPC_xgerc(localB->knt, localB->lastc_o, -tau[i], localB->ii_i
                             + 1, localB->work_g, b_A, localB->ii_i + 12);
      }

      b_A[localB->ii_i] = localB->b_atmp;
    } else {
      tau[10] = 0.0F;
    }
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_qr(const real32_T b_A[121], real32_T Q[121], real32_T
  R[121], B_PathFollowingControlSystem__T *localB)
{
  int32_T exitg1;
  boolean_T exitg2;
  memcpy(&localB->c_A[0], &b_A[0], 121U * sizeof(real32_T));
  Controller_MPC_xgeqrf(localB->c_A, localB->tau, localB);
  localB->itau = 10;
  for (localB->d_i = 0; localB->d_i < 11; localB->d_i++) {
    localB->iaii = 0;
    while (localB->iaii <= localB->d_i) {
      R[localB->iaii + 11 * localB->d_i] = localB->c_A[11 * localB->d_i +
        localB->iaii];
      localB->iaii++;
    }

    localB->iaii = localB->d_i + 1;
    while (localB->iaii + 1 < 12) {
      R[localB->iaii + 11 * localB->d_i] = 0.0F;
      localB->iaii++;
    }

    localB->work[localB->d_i] = 0.0F;
  }

  for (localB->d_i = 10; localB->d_i >= 0; localB->d_i--) {
    localB->iaii = (localB->d_i * 11 + localB->d_i) + 12;
    if (localB->d_i + 1 < 11) {
      localB->c_A[localB->iaii - 12] = 1.0F;
      if (localB->tau[localB->itau] != 0.0F) {
        localB->lastv = 11 - localB->d_i;
        localB->lastc = localB->iaii - localB->d_i;
        while ((localB->lastv > 0) && (localB->c_A[localB->lastc - 2] == 0.0F))
        {
          localB->lastv--;
          localB->lastc--;
        }

        localB->lastc = 10 - localB->d_i;
        exitg2 = false;
        while ((!exitg2) && (localB->lastc > 0)) {
          localB->coltop = (localB->lastc - 1) * 11 + localB->iaii;
          localB->ia = localB->coltop;
          do {
            exitg1 = 0;
            if (localB->ia <= (localB->coltop + localB->lastv) - 1) {
              if (localB->c_A[localB->ia - 1] != 0.0F) {
                exitg1 = 1;
              } else {
                localB->ia++;
              }
            } else {
              localB->lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);

          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        localB->lastv = 0;
        localB->lastc = 0;
      }

      if (localB->lastv > 0) {
        Controller_MPC_xgemv(localB->lastv, localB->lastc, localB->c_A,
                             localB->iaii, localB->c_A, localB->iaii - 11,
                             localB->work);
        Controller_MPC_xgerc(localB->lastv, localB->lastc, -localB->tau
                             [localB->itau], localB->iaii - 11, localB->work,
                             localB->c_A, localB->iaii);
      }

      localB->lastv = (localB->iaii - localB->d_i) - 1;
      localB->lastc = localB->iaii - 11;
      while (localB->lastc + 1 <= localB->lastv) {
        localB->c_A[localB->lastc] *= -localB->tau[localB->itau];
        localB->lastc++;
      }
    }

    localB->c_A[localB->iaii - 12] = 1.0F - localB->tau[localB->itau];
    localB->lastv = 0;
    while (localB->lastv <= localB->d_i - 1) {
      localB->c_A[(localB->iaii - localB->lastv) - 13] = 0.0F;
      localB->lastv++;
    }

    localB->itau--;
  }

  for (localB->itau = 0; localB->itau < 11; localB->itau++) {
    for (localB->d_i = 0; localB->d_i < 11; localB->d_i++) {
      Q[localB->d_i + 11 * localB->itau] = localB->c_A[11 * localB->itau +
        localB->d_i];
    }
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static real32_T Controller_MPC_KWIKfactor(const real32_T b_Ac[220], const
  int16_T iC[20], int16_T nA, const real32_T b_Linv[121], real32_T RLinv[121],
  real32_T b_D[121], real32_T b_H[121], int16_T n,
  B_PathFollowingControlSystem__T *localB)
{
  int32_T exitg1;
  real32_T Status;
  int16_T b_j;
  int16_T c_k;
  Status = 1.0F;
  memset(&RLinv[0], 0, 121U * sizeof(real32_T));
  localB->i_o = 1;
  while (localB->i_o - 1 <= nA - 1) {
    localB->iC_n = iC[static_cast<int16_T>(localB->i_o) - 1];
    for (localB->b_i = 0; localB->b_i < 11; localB->b_i++) {
      localB->c_i = localB->b_i + 11 * (static_cast<int16_T>(localB->i_o) - 1);
      RLinv[localB->c_i] = 0.0F;
      for (localB->e_i = 0; localB->e_i < 11; localB->e_i++) {
        RLinv[localB->c_i] += b_Ac[(20 * localB->e_i + localB->iC_n) - 1] *
          b_Linv[11 * localB->e_i + localB->b_i];
      }
    }

    localB->i_o++;
  }

  Controller_MPC_qr(RLinv, localB->QQ, localB->RR, localB);
  localB->b_i = 1;
  do {
    exitg1 = 0;
    if (localB->b_i - 1 <= nA - 1) {
      if (static_cast<real32_T>(fabs(static_cast<real_T>(localB->RR[((
               static_cast<int16_T>(localB->b_i) - 1) * 11 + static_cast<int16_T>
              (localB->b_i)) - 1]))) < 1.0E-12F) {
        Status = -2.0F;
        exitg1 = 1;
      } else {
        localB->b_i++;
      }
    } else {
      localB->c_i = 1;
      while (localB->c_i - 1 <= n - 1) {
        localB->e_i = 1;
        while (localB->e_i - 1 <= n - 1) {
          localB->b_Linv = 0.0F;
          for (localB->b_i = 0; localB->b_i < 11; localB->b_i++) {
            localB->b_Linv += b_Linv[(static_cast<int16_T>(localB->c_i) - 1) *
              11 + localB->b_i] * localB->QQ[(static_cast<int16_T>(localB->e_i)
              - 1) * 11 + localB->b_i];
          }

          localB->TL[(static_cast<int16_T>(localB->c_i) + 11 *
                      (static_cast<int16_T>(localB->e_i) - 1)) - 1] =
            localB->b_Linv;
          localB->e_i++;
        }

        localB->c_i++;
      }

      memset(&RLinv[0], 0, 121U * sizeof(real32_T));
      for (b_j = nA; b_j > 0; b_j = static_cast<int16_T>(b_j - 1)) {
        localB->b_i = 11 * (b_j - 1);
        localB->c_i = (b_j + localB->b_i) - 1;
        RLinv[localB->c_i] = 1.0F;
        for (c_k = b_j; c_k <= nA; c_k = static_cast<int16_T>(c_k + 1)) {
          localB->e_i = ((c_k - 1) * 11 + b_j) - 1;
          RLinv[localB->e_i] /= localB->RR[localB->c_i];
        }

        if (b_j > 1) {
          localB->i_o = 1;
          while (localB->i_o - 1 <= b_j - 2) {
            for (c_k = b_j; c_k <= nA; c_k = static_cast<int16_T>(c_k + 1)) {
              localB->c_i = (c_k - 1) * 11;
              localB->e_i = (localB->c_i + static_cast<int16_T>(localB->i_o)) -
                1;
              RLinv[localB->e_i] -= localB->RR[(localB->b_i +
                static_cast<int16_T>(localB->i_o)) - 1] * RLinv[(localB->c_i +
                b_j) - 1];
            }

            localB->i_o++;
          }
        }
      }

      localB->e_i = 1;
      while (localB->e_i - 1 <= n - 1) {
        for (b_j = static_cast<int16_T>(localB->e_i); b_j <= n; b_j =
             static_cast<int16_T>(b_j + 1)) {
          localB->b_i = (static_cast<int16_T>(localB->e_i) + 11 * (b_j - 1)) - 1;
          b_H[localB->b_i] = 0.0F;
          localB->c_i = nA + 1;
          if (nA + 1 > 32767) {
            localB->c_i = 32767;
          }

          for (c_k = static_cast<int16_T>(localB->c_i); c_k <= n; c_k =
               static_cast<int16_T>(c_k + 1)) {
            localB->c_i = (c_k - 1) * 11;
            b_H[localB->b_i] -= localB->TL[(localB->c_i + static_cast<int16_T>
              (localB->e_i)) - 1] * localB->TL[(localB->c_i + b_j) - 1];
          }

          b_H[(b_j + 11 * (static_cast<int16_T>(localB->e_i) - 1)) - 1] =
            b_H[localB->b_i];
        }

        localB->e_i++;
      }

      localB->e_i = 1;
      while (localB->e_i - 1 <= nA - 1) {
        localB->i_o = 1;
        while (localB->i_o - 1 <= n - 1) {
          localB->b_i = (static_cast<int16_T>(localB->i_o) + 11 *
                         (static_cast<int16_T>(localB->e_i) - 1)) - 1;
          b_D[localB->b_i] = 0.0F;
          for (b_j = static_cast<int16_T>(localB->e_i); b_j <= nA; b_j =
               static_cast<int16_T>(b_j + 1)) {
            localB->c_i = (b_j - 1) * 11;
            b_D[localB->b_i] += localB->TL[(localB->c_i + static_cast<int16_T>
              (localB->i_o)) - 1] * RLinv[(localB->c_i + static_cast<int16_T>
              (localB->e_i)) - 1];
          }

          localB->i_o++;
        }

        localB->e_i++;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return Status;
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_abs(const real32_T x[11], real32_T y[11])
{
  int32_T k;
  for (k = 0; k < 11; k++) {
    y[k] = static_cast<real32_T>(fabs(static_cast<real_T>(x[k])));
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static real32_T Controller_MPC_maximum(const real32_T x[11])
{
  int32_T idx;
  int32_T k;
  real32_T ex;
  boolean_T exitg1;
  if (!rtIsNaNF(x[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 12)) {
      if (!rtIsNaNF(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    while (idx + 1 <= 11) {
      if (ex < x[idx]) {
        ex = x[idx];
      }

      idx++;
    }
  }

  return ex;
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_abs_a(const real32_T x[20], real32_T y[20])
{
  int32_T k;
  for (k = 0; k < 20; k++) {
    y[k] = static_cast<real32_T>(fabs(static_cast<real_T>(x[k])));
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_maximum2(const real32_T x[20], real32_T y, real32_T
  ex[20])
{
  int32_T k;
  real32_T u0;
  for (k = 0; k < 20; k++) {
    u0 = x[k];
    if ((u0 > y) || rtIsNaNF(y)) {
      ex[k] = u0;
    } else {
      ex[k] = y;
    }
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static real32_T Controller_MPC_mtimes(const real32_T b_A[11], const real32_T
  b_B[11])
{
  int32_T k;
  real32_T b_C;
  b_C = 0.0F;
  for (k = 0; k < 11; k++) {
    b_C += b_A[k] * b_B[k];
  }

  return b_C;
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_DropConstraint(int16_T kDrop, int16_T iA[20], int16_T
  *nA, int16_T iC[20])
{
  int32_T tmp;
  int16_T i;
  iA[iC[kDrop - 1] - 1] = 0;
  if (kDrop < *nA) {
    tmp = *nA - 1;
    if (*nA - 1 < -32768) {
      tmp = -32768;
    }

    for (i = kDrop; i <= static_cast<int16_T>(tmp); i = static_cast<int16_T>(i +
          1)) {
      iC[i - 1] = iC[i];
    }
  }

  iC[*nA - 1] = 0;
  tmp = *nA - 1;
  if (*nA - 1 < -32768) {
    tmp = -32768;
  }

  *nA = static_cast<int16_T>(tmp);
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_qpkwik(const real32_T b_Linv[121], const real32_T
  b_Hinv[121], const real32_T f[11], const real32_T b_Ac[220], const real32_T b
  [20], int16_T iA[20], int16_T maxiter, real32_T FeasTol, real32_T x[11],
  real32_T lambda[20], real32_T *status, B_PathFollowingControlSystem__T *localB)
{
  int32_T exitg1;
  int32_T exitg3;
  int16_T kDrop;
  int16_T kNext;
  int16_T nA;
  int16_T tmp;
  int16_T tmp_0;
  uint16_T b_x;
  uint16_T q;
  boolean_T ColdReset;
  boolean_T DualFeasible;
  boolean_T cTolComputed;
  boolean_T exitg2;
  boolean_T exitg4;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  *status = 1.0F;
  memset(&lambda[0], 0, 20U * sizeof(real32_T));
  for (localB->i_j = 0; localB->i_j < 11; localB->i_j++) {
    x[localB->i_j] = 0.0F;
    localB->r[localB->i_j] = 0.0F;
  }

  localB->rMin = 0.0F;
  cTolComputed = false;
  for (localB->i_j = 0; localB->i_j < 20; localB->i_j++) {
    localB->cTol[localB->i_j] = 1.0F;
    localB->iC[localB->i_j] = 0;
  }

  nA = 0;
  for (localB->i_j = 0; localB->i_j < 20; localB->i_j++) {
    if (iA[localB->i_j] == 1) {
      localB->ct = nA + 1;
      if (nA + 1 > 32767) {
        localB->ct = 32767;
      }

      nA = static_cast<int16_T>(localB->ct);
      localB->iC[static_cast<int16_T>(localB->ct) - 1] = static_cast<int16_T>
        (localB->i_j + 1);
    }
  }

  guard1 = false;
  if (nA > 0) {
    memset(&localB->Opt[0], 0, 22U * sizeof(real32_T));
    for (localB->i_j = 0; localB->i_j < 11; localB->i_j++) {
      localB->Rhs[localB->i_j] = f[localB->i_j];
      localB->Rhs[localB->i_j + 11] = 0.0F;
    }

    DualFeasible = false;
    localB->ct = 3 * nA;
    if (localB->ct > 32767) {
      localB->ct = 32767;
    }

    if (static_cast<int16_T>(localB->ct) > 50) {
      kNext = static_cast<int16_T>(localB->ct);
    } else {
      kNext = 50;
    }

    q = static_cast<uint16_T>(kNext / 10U);
    b_x = static_cast<uint16_T>(static_cast<uint32_T>(kNext) - q * 10);
    if ((b_x > 0) && (b_x >= 5)) {
      q = static_cast<uint16_T>(q + 1);
    }

    ColdReset = false;
    do {
      exitg3 = 0;
      if ((!DualFeasible) && (nA > 0) && (static_cast<int32_T>(*status) <=
           maxiter)) {
        localB->Xnorm0 = Controller_MPC_KWIKfactor(b_Ac, localB->iC, nA, b_Linv,
          localB->RLinv, localB->b_D, localB->b_H, 11, localB);
        if (localB->Xnorm0 < 0.0F) {
          if (ColdReset) {
            *status = -2.0F;
            exitg3 = 2;
          } else {
            nA = 0;
            for (localB->i_j = 0; localB->i_j < 20; localB->i_j++) {
              iA[localB->i_j] = 0;
              localB->iC[localB->i_j] = 0;
            }

            ColdReset = true;
          }
        } else {
          localB->i_j = 1;
          while (localB->i_j - 1 <= nA - 1) {
            localB->ct = static_cast<int16_T>(localB->i_j) + 11;
            if (static_cast<int16_T>(localB->i_j) + 11 > 32767) {
              localB->ct = 32767;
            }

            localB->Rhs[localB->ct - 1] = b[localB->iC[static_cast<int16_T>
              (localB->i_j) - 1] - 1];
            for (kNext = static_cast<int16_T>(localB->i_j); kNext <= nA; kNext =
                 static_cast<int16_T>(kNext + 1)) {
              localB->ct = (kNext + 11 * (static_cast<int16_T>(localB->i_j) - 1))
                - 1;
              localB->U[localB->ct] = 0.0F;
              localB->b_k = 1;
              while (localB->b_k - 1 <= nA - 1) {
                localB->c_k = (static_cast<int16_T>(localB->b_k) - 1) * 11;
                localB->U[localB->ct] += localB->RLinv[(localB->c_k + kNext) - 1]
                  * localB->RLinv[(localB->c_k + static_cast<int16_T>
                                   (localB->i_j)) - 1];
                localB->b_k++;
              }

              localB->U[(static_cast<int16_T>(localB->i_j) + 11 * (kNext - 1)) -
                1] = localB->U[localB->ct];
            }

            localB->i_j++;
          }

          for (localB->i_j = 0; localB->i_j < 11; localB->i_j++) {
            localB->Xnorm0 = 0.0F;
            for (localB->ct = 0; localB->ct < 11; localB->ct++) {
              localB->Xnorm0 += localB->b_H[localB->i_j + 11 * localB->ct] *
                localB->Rhs[localB->ct];
            }

            localB->Opt[localB->i_j] = localB->Xnorm0;
            localB->b_k = 1;
            while (localB->b_k - 1 <= nA - 1) {
              localB->ct = static_cast<int16_T>(localB->b_k) + 11;
              if (static_cast<int16_T>(localB->b_k) + 11 > 32767) {
                localB->ct = 32767;
              }

              localB->Opt[localB->i_j] += localB->b_D[(static_cast<int16_T>
                (localB->b_k) - 1) * 11 + localB->i_j] * localB->Rhs[localB->ct
                - 1];
              localB->b_k++;
            }
          }

          localB->b_k = 1;
          while (localB->b_k - 1 <= nA - 1) {
            localB->Xnorm0 = 0.0F;
            for (localB->ct = 0; localB->ct < 11; localB->ct++) {
              localB->Xnorm0 += localB->b_D[(static_cast<int16_T>(localB->b_k) -
                1) * 11 + localB->ct] * localB->Rhs[localB->ct];
            }

            localB->ct = static_cast<int16_T>(localB->b_k) + 11;
            if (static_cast<int16_T>(localB->b_k) + 11 > 32767) {
              localB->ct = 32767;
            }

            localB->Opt[localB->ct - 1] = localB->Xnorm0;
            localB->c_k = 1;
            while (localB->c_k - 1 <= nA - 1) {
              localB->ct = static_cast<int16_T>(localB->b_k) + 11;
              if (static_cast<int16_T>(localB->b_k) + 11 > 32767) {
                localB->ct = 32767;
              }

              localB->i_j = static_cast<int16_T>(localB->b_k) + 11;
              if (static_cast<int16_T>(localB->b_k) + 11 > 32767) {
                localB->i_j = 32767;
              }

              localB->i_jz = static_cast<int16_T>(localB->c_k) + 11;
              if (static_cast<int16_T>(localB->c_k) + 11 > 32767) {
                localB->i_jz = 32767;
              }

              localB->Opt[localB->ct - 1] = localB->U[((static_cast<int16_T>
                (localB->c_k) - 1) * 11 + static_cast<int16_T>(localB->b_k)) - 1]
                * localB->Rhs[localB->i_jz - 1] + localB->Opt[localB->i_j - 1];
              localB->c_k++;
            }

            localB->b_k++;
          }

          localB->Xnorm0 = -1.0E-12F;
          kDrop = 0;
          localB->i_j = 1;
          while (localB->i_j - 1 <= nA - 1) {
            localB->ct = static_cast<int16_T>(localB->i_j) + 11;
            if (static_cast<int16_T>(localB->i_j) + 11 > 32767) {
              localB->ct = 32767;
            }

            lambda[localB->iC[static_cast<int16_T>(localB->i_j) - 1] - 1] =
              localB->Opt[localB->ct - 1];
            localB->ct = static_cast<int16_T>(localB->i_j) + 11;
            if (static_cast<int16_T>(localB->i_j) + 11 > 32767) {
              localB->ct = 32767;
            }

            if ((localB->Opt[localB->ct - 1] < localB->Xnorm0) &&
                (static_cast<int16_T>(localB->i_j) <= nA)) {
              kDrop = static_cast<int16_T>(localB->i_j);
              localB->ct = static_cast<int16_T>(localB->i_j) + 11;
              if (static_cast<int16_T>(localB->i_j) + 11 > 32767) {
                localB->ct = 32767;
              }

              localB->Xnorm0 = localB->Opt[localB->ct - 1];
            }

            localB->i_j++;
          }

          if (kDrop <= 0) {
            DualFeasible = true;
            for (localB->i_j = 0; localB->i_j < 11; localB->i_j++) {
              x[localB->i_j] = localB->Opt[localB->i_j];
            }
          } else {
            (*status)++;
            if (static_cast<int32_T>(*status) > q) {
              nA = 0;
              for (localB->i_j = 0; localB->i_j < 20; localB->i_j++) {
                iA[localB->i_j] = 0;
                localB->iC[localB->i_j] = 0;
              }

              ColdReset = true;
            } else {
              lambda[localB->iC[kDrop - 1] - 1] = 0.0F;
              Controller_MPC_DropConstraint(kDrop, iA, &nA, localB->iC);
            }
          }
        }
      } else {
        if (nA <= 0) {
          memset(&lambda[0], 0, 20U * sizeof(real32_T));
          Controller_MPC_Unconstrained(b_Hinv, f, x, 11);
        }

        exitg3 = 1;
      }
    } while (exitg3 == 0);

    if (exitg3 == 1) {
      guard1 = true;
    }
  } else {
    Controller_MPC_Unconstrained(b_Hinv, f, x, 11);
    guard1 = true;
  }

  if (guard1) {
    localB->Xnorm0 = Controller_MPC_norm(x);
    exitg2 = false;
    while ((!exitg2) && (static_cast<int32_T>(*status) <= maxiter)) {
      localB->cMin = -FeasTol;
      kNext = 0;
      for (localB->i_j = 0; localB->i_j < 20; localB->i_j++) {
        localB->zTa = localB->cTol[localB->i_j];
        if (!cTolComputed) {
          for (localB->ct = 0; localB->ct < 11; localB->ct++) {
            localB->b_Ac[localB->ct] = b_Ac[localB->i_j + 20 * localB->ct] *
              x[localB->ct];
          }

          Controller_MPC_abs(localB->b_Ac, localB->z);
          localB->cVal = Controller_MPC_maximum(localB->z);
          if ((!(localB->zTa > localB->cVal)) && (!rtIsNaNF(localB->cVal))) {
            localB->zTa = localB->cVal;
          }
        }

        if (iA[localB->i_j] == 0) {
          localB->cVal = 0.0F;
          for (localB->ct = 0; localB->ct < 11; localB->ct++) {
            localB->cVal += b_Ac[localB->i_j + 20 * localB->ct] * x[localB->ct];
          }

          localB->cVal = (localB->cVal - b[localB->i_j]) / localB->zTa;
          if (localB->cVal < localB->cMin) {
            localB->cMin = localB->cVal;
            kNext = static_cast<int16_T>(localB->i_j + 1);
          }
        }

        localB->cTol[localB->i_j] = localB->zTa;
      }

      cTolComputed = true;
      if (kNext <= 0) {
        exitg2 = true;
      } else if (static_cast<int32_T>(*status) == maxiter) {
        *status = 0.0F;
        exitg2 = true;
      } else {
        do {
          exitg1 = 0;
          if ((kNext > 0) && (static_cast<int32_T>(*status) <= maxiter)) {
            guard2 = false;
            if (nA == 0) {
              for (localB->ct = 0; localB->ct < 11; localB->ct++) {
                localB->z[localB->ct] = 0.0F;
                for (localB->i_j = 0; localB->i_j < 11; localB->i_j++) {
                  localB->z[localB->ct] += b_Ac[(20 * localB->i_j + kNext) - 1] *
                    b_Hinv[11 * localB->i_j + localB->ct];
                }
              }

              guard2 = true;
            } else {
              localB->cMin = Controller_MPC_KWIKfactor(b_Ac, localB->iC, nA,
                b_Linv, localB->RLinv, localB->b_D, localB->b_H, 11, localB);
              if (localB->cMin <= 0.0F) {
                *status = -2.0F;
                exitg1 = 1;
              } else {
                for (localB->ct = 0; localB->ct < 121; localB->ct++) {
                  localB->U[localB->ct] = -localB->b_H[localB->ct];
                }

                for (localB->ct = 0; localB->ct < 11; localB->ct++) {
                  localB->z[localB->ct] = 0.0F;
                  for (localB->i_j = 0; localB->i_j < 11; localB->i_j++) {
                    localB->z[localB->ct] += b_Ac[(20 * localB->i_j + kNext) - 1]
                      * localB->U[11 * localB->i_j + localB->ct];
                  }
                }

                localB->i_j = 1;
                while (localB->i_j - 1 <= nA - 1) {
                  localB->cVal = 0.0F;
                  for (localB->ct = 0; localB->ct < 11; localB->ct++) {
                    localB->cVal += b_Ac[(20 * localB->ct + kNext) - 1] *
                      localB->b_D[(static_cast<int16_T>(localB->i_j) - 1) * 11 +
                      localB->ct];
                  }

                  localB->r[static_cast<int16_T>(localB->i_j) - 1] =
                    localB->cVal;
                  localB->i_j++;
                }

                guard2 = true;
              }
            }

            if (guard2) {
              kDrop = 0;
              localB->cMin = 0.0F;
              DualFeasible = true;
              ColdReset = true;
              if (nA > 0) {
                localB->ct = 0;
                exitg4 = false;
                while ((!exitg4) && (localB->ct <= nA - 1)) {
                  if (localB->r[localB->ct] >= 1.0E-12F) {
                    ColdReset = false;
                    exitg4 = true;
                  } else {
                    localB->ct++;
                  }
                }
              }

              if ((nA != 0) && (!ColdReset)) {
                localB->ct = 1;
                while (localB->ct - 1 <= nA - 1) {
                  localB->zTa = localB->r[static_cast<int16_T>(localB->ct) - 1];
                  if (localB->zTa > 1.0E-12F) {
                    localB->zTa = lambda[localB->iC[static_cast<int16_T>
                      (localB->ct) - 1] - 1] / localB->zTa;
                    if ((kDrop == 0) || (localB->zTa < localB->rMin)) {
                      localB->rMin = localB->zTa;
                      kDrop = static_cast<int16_T>(localB->ct);
                    }
                  }

                  localB->ct++;
                }

                if (kDrop > 0) {
                  localB->cMin = localB->rMin;
                  DualFeasible = false;
                }
              }

              for (localB->ct = 0; localB->ct < 11; localB->ct++) {
                localB->b_Ac[localB->ct] = b_Ac[(20 * localB->ct + kNext) - 1];
              }

              localB->zTa = Controller_MPC_mtimes(localB->z, localB->b_Ac);
              if (localB->zTa <= 0.0F) {
                localB->zTa = 0.0F;
                ColdReset = true;
              } else {
                localB->cVal = 0.0F;
                for (localB->ct = 0; localB->ct < 11; localB->ct++) {
                  localB->cVal += b_Ac[(20 * localB->ct + kNext) - 1] * x
                    [localB->ct];
                }

                localB->zTa = (b[kNext - 1] - localB->cVal) / localB->zTa;
                ColdReset = false;
              }

              if (DualFeasible && ColdReset) {
                *status = -1.0F;
                exitg1 = 1;
              } else {
                if (ColdReset) {
                  localB->cVal = localB->cMin;
                } else if (DualFeasible) {
                  localB->cVal = localB->zTa;
                } else if ((localB->cMin < localB->zTa) || rtIsNaNF(localB->zTa))
                {
                  localB->cVal = localB->cMin;
                } else {
                  localB->cVal = localB->zTa;
                }

                localB->ct = 1;
                while (localB->ct - 1 <= nA - 1) {
                  localB->i_j = localB->iC[static_cast<int16_T>(localB->ct) - 1];
                  lambda[localB->i_j - 1] -= localB->r[static_cast<int16_T>
                    (localB->ct) - 1] * localB->cVal;
                  if ((localB->i_j <= 20) && (lambda[localB->i_j - 1] < 0.0F)) {
                    lambda[localB->i_j - 1] = 0.0F;
                  }

                  localB->ct++;
                }

                lambda[kNext - 1] += localB->cVal;
                if (localB->cVal == localB->cMin) {
                  Controller_MPC_DropConstraint(kDrop, iA, &nA, localB->iC);
                }

                if (!ColdReset) {
                  for (localB->ct = 0; localB->ct < 11; localB->ct++) {
                    x[localB->ct] += localB->cVal * localB->z[localB->ct];
                  }

                  if (localB->cVal == localB->zTa) {
                    if (nA == 11) {
                      *status = -1.0F;
                      exitg1 = 1;
                    } else {
                      localB->ct = nA + 1;
                      if (nA + 1 > 32767) {
                        localB->ct = 32767;
                      }

                      nA = static_cast<int16_T>(localB->ct);
                      localB->iC[static_cast<int16_T>(localB->ct) - 1] = kNext;
                      kDrop = static_cast<int16_T>(localB->ct);
                      exitg4 = false;
                      while ((!exitg4) && (kDrop > 1)) {
                        tmp = localB->iC[kDrop - 1];
                        tmp_0 = localB->iC[kDrop - 2];
                        if (tmp > tmp_0) {
                          exitg4 = true;
                        } else {
                          localB->iC[kDrop - 1] = tmp_0;
                          localB->iC[kDrop - 2] = tmp;
                          kDrop = static_cast<int16_T>(kDrop - 1);
                        }
                      }

                      iA[kNext - 1] = 1;
                      kNext = 0;
                      (*status)++;
                    }
                  } else {
                    (*status)++;
                  }
                } else {
                  (*status)++;
                }
              }
            }
          } else {
            localB->cMin = Controller_MPC_norm(x);
            if (static_cast<real32_T>(fabs(static_cast<real_T>(localB->cMin -
                   localB->Xnorm0))) > 0.001F) {
              localB->Xnorm0 = localB->cMin;
              Controller_MPC_abs_a(b, localB->fv5);
              Controller_MPC_maximum2(localB->fv5, 1.0F, localB->cTol);
              cTolComputed = false;
            }

            exitg1 = 2;
          }
        } while (exitg1 == 0);

        if (exitg1 == 1) {
          exitg2 = true;
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_MPC_mpc_solveQP(const real32_T xQP[10], const real32_T
  b_Kx[100], const real32_T b_Kr[1800], const real32_T rseq[180], const real32_T
  b_Ku1[20], const real32_T old_u[2], const real32_T b_Kv[1220], const real32_T
  vseq[122], const real32_T b_Kut[1200], const real32_T b_utarget[120], const
  real32_T b_Linv[121], const real32_T b_Hinv[121], const real32_T b_Ac[220],
  const real32_T Bc[20], boolean_T iA[20], real32_T zopt[11], real32_T f[11],
  real32_T *status, B_PathFollowingControlSystem__T *localB)
{
  for (localB->i_a = 0; localB->i_a < 11; localB->i_a++) {
    f[localB->i_a] = 0.0F;
  }

  for (localB->i_a = 0; localB->i_a < 10; localB->i_a++) {
    localB->b_Kx = 0.0F;
    for (localB->f_tmp = 0; localB->f_tmp < 10; localB->f_tmp++) {
      localB->b_Kx += b_Kx[10 * localB->i_a + localB->f_tmp] * xQP[localB->f_tmp];
    }

    localB->b_Kr = 0.0F;
    for (localB->f_tmp = 0; localB->f_tmp < 180; localB->f_tmp++) {
      localB->b_Kr += b_Kr[180 * localB->i_a + localB->f_tmp] * rseq
        [localB->f_tmp];
    }

    localB->b_Kv = 0.0F;
    for (localB->f_tmp = 0; localB->f_tmp < 122; localB->f_tmp++) {
      localB->b_Kv += b_Kv[122 * localB->i_a + localB->f_tmp] * vseq
        [localB->f_tmp];
    }

    localB->b_Kut = 0.0F;
    for (localB->f_tmp = 0; localB->f_tmp < 120; localB->f_tmp++) {
      localB->b_Kut += b_Kut[120 * localB->i_a + localB->f_tmp] *
        b_utarget[localB->f_tmp];
    }

    localB->f_tmp = localB->i_a << 1;
    f[localB->i_a] = (((b_Ku1[localB->f_tmp + 1] * old_u[1] + b_Ku1
                        [localB->f_tmp] * old_u[0]) + (localB->b_Kx +
      localB->b_Kr)) + localB->b_Kv) + localB->b_Kut;
  }

  for (localB->i_a = 0; localB->i_a < 20; localB->i_a++) {
    localB->iAnew[localB->i_a] = iA[localB->i_a];
  }

  Controller_MPC_qpkwik(b_Linv, b_Hinv, f, b_Ac, Bc, localB->iAnew, 124, 1.0E-6F,
                        zopt, localB->unusedU0, status, localB);
  for (localB->i_a = 0; localB->i_a < 20; localB->i_a++) {
    iA[localB->i_a] = (localB->iAnew[localB->i_a] != 0);
  }

  if ((*status < 0.0F) || (*status == 0.0F)) {
    for (localB->i_a = 0; localB->i_a < 11; localB->i_a++) {
      zopt[localB->i_a] = 0.0F;
    }
  }
}

// Function for MATLAB Function: '<S50>/FixedHorizonOptimizer'
static void Controller_M_mpcblock_optimizer(const real32_T rseq[180], const
  real32_T vseq[122], const real32_T umin[2], const real32_T umax[2], real32_T
  switch_in, const real32_T x[10], const real32_T old_u[2], const boolean_T iA
  [20], const real32_T b_Mlim[20], real32_T b_Mx[200], real32_T b_Mu1[40],
  real32_T b_Mv[2440], const real32_T b_utarget[120], const real32_T b_uoff[2],
  real32_T b_enable_value, real32_T b_H[121], real32_T b_Ac[220], const real32_T
  b_Wy[3], const real32_T b_Wdu[2], const real32_T b_Jm[1200], const real32_T
  b_Wu[2], const real32_T b_I1[240], const real32_T b_A[100], const real32_T Bu
  [1220], const real32_T Bv[1220], const real32_T b_C[30], const real32_T Dv[366],
  const real32_T b_Mrows[20], const real32_T b_RMVscale[2], real32_T u[2],
  real32_T useq[122], real32_T *status, boolean_T iAout[20],
  B_PathFollowingControlSystem__T *localB)
{
  static const int8_T c_A[3600] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  boolean_T umax_incr_flag[2];
  boolean_T umin_incr_flag[2];
  boolean_T b_Del_Save_Flag0_tmp;
  boolean_T exitg1;
  memset(&useq[0], 0, 122U * sizeof(real32_T));
  *status = 1.0F;
  for (localB->i = 0; localB->i < 20; localB->i++) {
    iAout[localB->i] = false;
  }

  if (switch_in != b_enable_value) {
    for (localB->i = 0; localB->i < 2; localB->i++) {
      u[localB->i] = old_u[localB->i] + b_uoff[localB->i];
      for (localB->kidx = 0; localB->kidx < 61; localB->kidx++) {
        useq[localB->kidx + 61 * localB->i] = u[localB->i];
      }
    }
  } else {
    Controller_M_mpc_constraintcoef(b_A, &Bu[0], &Bv[0], b_C, &Dv[0], b_Jm,
      localB->c_SuJm, localB->c_Sx, localB->c_Su1, localB->c_Hv, localB);
    if (b_Mrows[0] > 0.0F) {
      localB->i = 0;
      exitg1 = false;
      while ((!exitg1) && (localB->i < 20)) {
        if (b_Mrows[localB->i] <= 180.0F) {
          localB->b_j1 = static_cast<int32_T>(b_Mrows[localB->i]);
          for (localB->kidx = 0; localB->kidx < 10; localB->kidx++) {
            localB->j2 = localB->i + 20 * localB->kidx;
            b_Ac[localB->j2] = -localB->c_SuJm[(180 * localB->kidx +
              localB->b_j1) - 1];
            b_Mx[localB->j2] = -localB->c_Sx[(180 * localB->kidx + localB->b_j1)
              - 1];
          }

          b_Mu1[localB->i] = -localB->c_Su1[localB->b_j1 - 1];
          b_Mu1[localB->i + 20] = -localB->c_Su1[localB->b_j1 + 179];
          for (localB->kidx = 0; localB->kidx < 122; localB->kidx++) {
            b_Mv[localB->i + 20 * localB->kidx] = -localB->c_Hv[(180 *
              localB->kidx + localB->b_j1) - 1];
          }

          localB->i++;
        } else if (b_Mrows[localB->i] <= 360.0F) {
          localB->b_j1 = static_cast<int32_T>(b_Mrows[localB->i] - 180.0F);
          for (localB->kidx = 0; localB->kidx < 10; localB->kidx++) {
            localB->j2 = localB->i + 20 * localB->kidx;
            b_Ac[localB->j2] = localB->c_SuJm[(180 * localB->kidx + localB->b_j1)
              - 1];
            b_Mx[localB->j2] = localB->c_Sx[(180 * localB->kidx + localB->b_j1)
              - 1];
          }

          b_Mu1[localB->i] = localB->c_Su1[localB->b_j1 - 1];
          b_Mu1[localB->i + 20] = localB->c_Su1[localB->b_j1 + 179];
          for (localB->kidx = 0; localB->kidx < 122; localB->kidx++) {
            b_Mv[localB->i + 20 * localB->kidx] = localB->c_Hv[(180 *
              localB->kidx + localB->b_j1) - 1];
          }

          localB->i++;
        } else {
          exitg1 = true;
        }
      }
    }

    localB->b_I_h[1] = 0;
    localB->b_I_h[2] = 0;
    localB->b_I_h[0] = 1;
    localB->b_I_h[3] = 1;
    localB->kidx = -1;
    for (localB->b_j1 = 0; localB->b_j1 < 60; localB->b_j1++) {
      for (localB->j2 = 0; localB->j2 < 2; localB->j2++) {
        for (localB->i1 = 0; localB->i1 < 60; localB->i1++) {
          localB->kidx++;
          localB->i = localB->j2 << 1;
          localB->a_tmp = c_A[60 * localB->b_j1 + localB->i1];
          localB->a[localB->kidx] = static_cast<int8_T>(localB->a_tmp *
            localB->b_I_h[localB->i]);
          localB->kidx++;
          localB->a[localB->kidx] = static_cast<int8_T>(localB->a_tmp *
            localB->b_I_h[localB->i + 1]);
        }
      }
    }

    for (localB->kidx = 0; localB->kidx < 10; localB->kidx++) {
      for (localB->b_j1 = 0; localB->b_j1 < 120; localB->b_j1++) {
        localB->i = localB->b_j1 + 120 * localB->kidx;
        localB->a_m[localB->i] = 0.0F;
        for (localB->j2 = 0; localB->j2 < 120; localB->j2++) {
          localB->a_m[localB->i] += static_cast<real32_T>(localB->a[120 *
            localB->j2 + localB->b_j1]) * b_Jm[120 * localB->kidx + localB->j2];
        }
      }
    }

    Controller_mpc_calculatehessian(b_Wy, b_Wu, b_Wdu, localB->c_SuJm,
      localB->a_m, b_Jm, b_I1, localB->c_Su1, localB->c_Sx, localB->c_Hv,
      Controller_MPC_nu, Controller_MPC_ny, localB->b, localB->c_Ku1,
      localB->c_Kut, localB->c_Kx, localB->c_Kv, localB->c_Kr, localB);
    for (localB->kidx = 0; localB->kidx < 10; localB->kidx++) {
      for (localB->b_j1 = 0; localB->b_j1 < 10; localB->b_j1++) {
        b_H[localB->b_j1 + 11 * localB->kidx] = localB->b[10 * localB->kidx +
          localB->b_j1];
      }
    }

    memcpy(&localB->c_Linv[0], &b_H[0], 121U * sizeof(real32_T));
    Controller_MPC_mpc_checkhessian(localB->c_Linv, localB->d_Linv, &localB->ii,
      localB);
    if (localB->ii > 1.0F) {
      for (localB->i = 0; localB->i < 2; localB->i++) {
        u[localB->i] = old_u[localB->i] + b_uoff[localB->i];
        for (localB->kidx = 0; localB->kidx < 61; localB->kidx++) {
          useq[localB->kidx + 61 * localB->i] = u[localB->i];
        }
      }

      *status = -2.0F;
    } else {
      memset(&localB->c_I[0], 0, 121U * sizeof(int8_T));
      for (localB->kidx = 0; localB->kidx < 11; localB->kidx++) {
        localB->c_I[localB->kidx + 11 * localB->kidx] = 1;
      }

      for (localB->kidx = 0; localB->kidx < 11; localB->kidx++) {
        for (localB->b_j1 = 0; localB->b_j1 < 11; localB->b_j1++) {
          localB->i = 11 * localB->kidx + localB->b_j1;
          localB->c_Linv[localB->i] = localB->c_I[localB->i];
        }
      }

      Controller_MPC_trisolve(localB->d_Linv, localB->c_Linv);
      for (localB->kidx = 0; localB->kidx < 20; localB->kidx++) {
        localB->ii = 0.0F;
        for (localB->b_j1 = 0; localB->b_j1 < 10; localB->b_j1++) {
          localB->ii += b_Mx[20 * localB->b_j1 + localB->kidx] * x[localB->b_j1];
        }

        localB->b_DelBound = 0.0F;
        for (localB->b_j1 = 0; localB->b_j1 < 122; localB->b_j1++) {
          localB->b_DelBound += b_Mv[20 * localB->b_j1 + localB->kidx] *
            vseq[localB->b_j1];
        }

        localB->Bc[localB->kidx] = -(((b_Mlim[localB->kidx] + localB->ii) +
          (b_Mu1[localB->kidx + 20] * old_u[1] + b_Mu1[localB->kidx] * old_u[0]))
          + localB->b_DelBound);
      }

      umax_incr_flag[0] = false;
      localB->umax_incr[0] = 0.0F;
      umin_incr_flag[0] = false;
      localB->umin_incr[0] = 0.0F;
      umax_incr_flag[1] = false;
      localB->umax_incr[1] = 0.0F;
      umin_incr_flag[1] = false;
      localB->umin_incr[1] = 0.0F;
      if (b_Mrows[0] > 0.0F) {
        localB->kidx = 0;
        exitg1 = false;
        while ((!exitg1) && (localB->kidx < 20)) {
          if ((b_Mrows[localB->kidx] <= 180.0F) || (b_Mrows[localB->kidx] <=
               360.0F)) {
            localB->kidx++;
          } else if (b_Mrows[localB->kidx] <= 480.0F) {
            localB->ii = Controller_MPC_mod_l((b_Mrows[localB->kidx] - 360.0F) -
              1.0F) + 1.0F;
            b_Del_Save_Flag0_tmp = umax_incr_flag[static_cast<int32_T>
              (localB->ii) - 1];
            if (!b_Del_Save_Flag0_tmp) {
              localB->b_DelBound = -(b_RMVscale[static_cast<int32_T>(localB->ii)
                - 1] * umax[static_cast<int32_T>(localB->ii) - 1] - b_uoff[
                static_cast<int32_T>(localB->ii) - 1]) - (-b_Mlim[localB->kidx]);
              b_Del_Save_Flag0_tmp = true;
            } else {
              localB->b_DelBound = localB->umax_incr[static_cast<int32_T>
                (localB->ii) - 1];
            }

            localB->umax_incr[static_cast<int32_T>(localB->ii) - 1] =
              localB->b_DelBound;
            umax_incr_flag[static_cast<int32_T>(localB->ii) - 1] =
              b_Del_Save_Flag0_tmp;
            localB->Bc[localB->kidx] += localB->b_DelBound;
            localB->kidx++;
          } else if (b_Mrows[localB->kidx] <= 600.0F) {
            localB->ii = Controller_MPC_mod_l(((b_Mrows[localB->kidx] - 360.0F)
              - 120.0F) - 1.0F) + 1.0F;
            b_Del_Save_Flag0_tmp = umin_incr_flag[static_cast<int32_T>
              (localB->ii) - 1];
            if (!b_Del_Save_Flag0_tmp) {
              localB->b_DelBound = (b_RMVscale[static_cast<int32_T>(localB->ii)
                                    - 1] * umin[static_cast<int32_T>(localB->ii)
                                    - 1] - b_uoff[static_cast<int32_T>
                                    (localB->ii) - 1]) - (-b_Mlim[localB->kidx]);
              b_Del_Save_Flag0_tmp = true;
            } else {
              localB->b_DelBound = localB->umin_incr[static_cast<int32_T>
                (localB->ii) - 1];
            }

            localB->umin_incr[static_cast<int32_T>(localB->ii) - 1] =
              localB->b_DelBound;
            umin_incr_flag[static_cast<int32_T>(localB->ii) - 1] =
              b_Del_Save_Flag0_tmp;
            localB->Bc[localB->kidx] += localB->b_DelBound;
            localB->kidx++;
          } else {
            exitg1 = true;
          }
        }
      }

      for (localB->i = 0; localB->i < 20; localB->i++) {
        iAout[localB->i] = iA[localB->i];
      }

      for (localB->kidx = 0; localB->kidx < 11; localB->kidx++) {
        for (localB->b_j1 = 0; localB->b_j1 < 11; localB->b_j1++) {
          localB->i = localB->kidx + 11 * localB->b_j1;
          localB->d_Linv[localB->i] = 0.0F;
          for (localB->j2 = 0; localB->j2 < 11; localB->j2++) {
            localB->d_Linv[localB->i] += localB->c_Linv[11 * localB->kidx +
              localB->j2] * localB->c_Linv[11 * localB->b_j1 + localB->j2];
          }
        }
      }

      Controller_MPC_mpc_solveQP(x, localB->c_Kx, localB->c_Kr, rseq,
        localB->c_Ku1, old_u, localB->c_Kv, vseq, localB->c_Kut, b_utarget,
        localB->c_Linv, localB->d_Linv, b_Ac, localB->Bc, iAout, localB->zopt,
        localB->f_d, status, localB);
      u[0] = (old_u[0] + localB->zopt[0]) + b_uoff[0];
      u[1] = (old_u[1] + localB->zopt[1]) + b_uoff[1];
    }
  }
}

// System initialize for atomic system: '<S8>/Path Following Control System'
void PathFollowingControlSystem_Init(DW_PathFollowingControlSystem_T *localDW,
  P_PathFollowingControlSystem__T *localP)
{
  int32_T i;

  // InitializeConditions for Memory: '<S22>/LastPcov'
  memcpy(&localDW->LastPcov_PreviousInput[0], &localP->
         LastPcov_InitialCondition[0], 100U * sizeof(real32_T));

  // InitializeConditions for Memory: '<S22>/Memory'
  for (i = 0; i < 20; i++) {
    localDW->Memory_PreviousInput[i] = localP->Memory_InitialCondition[i];
  }

  // End of InitializeConditions for Memory: '<S22>/Memory'

  // InitializeConditions for UnitDelay: '<S22>/last_mv'
  localDW->last_mv_DSTATE[0] = localP->last_mv_InitialCondition[0];
  localDW->last_mv_DSTATE[1] = localP->last_mv_InitialCondition[1];

  // InitializeConditions for Memory: '<S22>/last_x'
  for (i = 0; i < 10; i++) {
    localDW->last_x_PreviousInput[i] = localP->last_x_InitialCondition[i];
  }

  // End of InitializeConditions for Memory: '<S22>/last_x'
}

// Output and update for atomic system: '<S8>/Path Following Control System'
void Cont_PathFollowingControlSystem(real32_T rtu_Setvelocity, real32_T
  rtu_Longitudinalvelocity, real32_T rtu_Curvature, real32_T
  rtu_Lateraldeviation, real32_T rtu_Relativeyawangle, real32_T
  rtyy_LongitudinalaccelerationSt[2], B_PathFollowingControlSystem__T *localB,
  DW_PathFollowingControlSystem_T *localDW, P_PathFollowingControlSystem__T
  *localP, real_T rtp_MinAcceleration, real_T rtp_MinSteering, real_T
  rtp_MaxAcceleration, real_T rtp_MaxSteering)
{
  static const real32_T gb[1200] = { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

  static const real32_T lb[240] = { 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F,
    0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F,
    1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F,
    0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F,
    1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F,
    0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F,
    1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F,
    0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F,
    1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F,
    0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 1.0F,
    0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F,
    1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F,
    0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F,
    1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F,
    0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F,
    1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F,
    0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F,
    1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F,
    0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F };

  static const real32_T eb[220] = { -1.0F, -0.0F, -1.0F, -0.0F, -1.0F, -0.0F,
    -1.0F, -0.0F, -1.0F, -0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F,
    1.0F, 0.0F, -0.0F, -1.0F, -0.0F, -1.0F, -0.0F, -1.0F, -0.0F, -1.0F, -0.0F,
    -1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, -0.0F,
    -0.0F, -1.0F, -0.0F, -1.0F, -0.0F, -1.0F, -0.0F, -1.0F, -0.0F, 0.0F, 0.0F,
    1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, -0.0F, -0.0F, -0.0F, -1.0F,
    -0.0F, -1.0F, -0.0F, -1.0F, -0.0F, -1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 1.0F,
    0.0F, 1.0F, 0.0F, 1.0F, -0.0F, -0.0F, -0.0F, -0.0F, -1.0F, -0.0F, -1.0F,
    -0.0F, -1.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F,
    0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -1.0F, -0.0F, -1.0F, -0.0F, -1.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, -0.0F, -0.0F,
    -0.0F, -0.0F, -0.0F, -0.0F, -1.0F, -0.0F, -1.0F, -0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F,
    -0.0F, -0.0F, -1.0F, -0.0F, -1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    1.0F, 0.0F, 1.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F,
    -1.0F, -0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F,
    -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -0.0F, -1.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F };

  static const real32_T cb[121] = { 3.86337115E-6F, 0.0F, 2.77838149E-6F, 0.0F,
    2.69376665E-6F, 0.0F, 2.60956494E-6F, 0.0F, 2.52581685E-6F, 0.0F, 0.0F, 0.0F,
    900.0F, 0.0F, 2.60343029E-7F, 0.0F, 2.53614928E-7F, 0.0F, 2.46894757E-7F,
    0.0F, 2.40186182E-7F, 0.0F, 2.77838149E-6F, 0.0F, 3.69644772E-6F, 0.0F,
    2.61485275E-6F, 0.0F, 2.53363169E-6F, 0.0F, 2.45282263E-6F, 0.0F, 0.0F, 0.0F,
    2.60343029E-7F, 0.0F, 900.0F, 0.0F, 2.47324522E-7F, 0.0F, 2.40820953E-7F,
    0.0F, 2.34325299E-7F, 0.0F, 2.69376665E-6F, 0.0F, 2.61485275E-6F, 0.0F,
    3.53624478E-6F, 0.0F, 2.45797446E-6F, 0.0F, 2.38007715E-6F, 0.0F, 0.0F, 0.0F,
    2.53614928E-7F, 0.0F, 2.47324522E-7F, 0.0F, 900.0F, 0.0F, 2.34747446E-7F,
    0.0F, 2.28464572E-7F, 0.0F, 2.60956494E-6F, 0.0F, 2.53363169E-6F, 0.0F,
    2.45797446E-6F, 0.0F, 3.38262225E-6F, 0.0F, 2.30760679E-6F, 0.0F, 0.0F, 0.0F,
    2.46894757E-7F, 0.0F, 2.40820953E-7F, 0.0F, 2.34747446E-7F, 0.0F, 900.0F,
    0.0F, 2.22604157E-7F, 0.0F, 2.52581685E-6F, 0.0F, 2.45282263E-6F, 0.0F,
    2.38007715E-6F, 0.0F, 2.30760679E-6F, 0.0F, 3.23544E-6F, 0.0F, 0.0F, 0.0F,
    2.40186182E-7F, 0.0F, 2.34325299E-7F, 0.0F, 2.28464572E-7F, 0.0F,
    2.22604157E-7F, 0.0F, 900.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 100000.0F };

  static const real32_T e[100] = { 0.90483743F, 0.0475812927F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.017750293F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.63212055F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.2789333E-7F,
    -3.76157416E-8F, 0.0F, 8.08439182E-8F, -2.37775879E-8F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, -4.34016911E-8F, 2.17013891E-7F, 0.0F, -2.74352789E-8F,
    1.37178588E-7F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.63212055F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 5.0E-6F, 1.0F, 0.0F, 1.83939721E-6F,
    0.63212055F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.36787945F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.36787945F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.36787945F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F };

  static const real32_T f_0[80] = { 0.475812912F, 0.0120935449F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.00321877655F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.8F, 1.56F,
    1.78750815E-6F, 2.97916677E-6F, 0.0F, 7.17339333E-7F, 1.19555705E-6F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, -1.25E-8F, -0.005F, 0.0F, -3.30335448E-9F,
    -0.00183932914F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.05F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F };

  static const real32_T bb[40] = { -1.0F, -0.0F, -1.0F, -0.0F, -1.0F, -0.0F,
    -1.0F, -0.0F, -1.0F, -0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F,
    1.0F, 0.0F, -0.0F, -1.0F, -0.0F, -1.0F, -0.0F, -1.0F, -0.0F, -1.0F, -0.0F,
    -1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F, 0.0F, 1.0F };

  static const real32_T g[30] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0333333351F,
    0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 5.0F, 0.0F, 0.0F, 1.0F };

  static const real32_T h[24] = { 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F,
    0.0F, 0.0F, 1.0F };

  static const real32_T o[20] = { 0.4F, 0.5F, 0.4F, 0.5F, 0.4F, 0.5F, 0.4F, 0.5F,
    0.4F, 0.5F, 0.6F, 0.5F, 0.6F, 0.5F, 0.6F, 0.5F, 0.6F, 0.5F, 0.6F, 0.5F };

  static const real32_T q[20] = { 361.0F, 362.0F, 363.0F, 364.0F, 365.0F, 366.0F,
    367.0F, 368.0F, 369.0F, 370.0F, 481.0F, 482.0F, 483.0F, 484.0F, 485.0F,
    486.0F, 487.0F, 488.0F, 489.0F, 490.0F };

  static const real32_T fb[3] = { 1.0E-6F, 1.0F, 0.0F };

  static const real32_T l[3] = { 5.0F, 1.04F, 0.1F };

  static const real32_T n[3] = { 30.0F, 1.0F, 0.2F };

  static const real32_T r[3] = { 3.33333332E-6F, 0.0F, 0.0F };

  static const int8_T e_0[12] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  static const int8_T d[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  static const int8_T g_0[8] = { 0, 0, 1, 0, 0, 1, 0, -1 };

  static const int8_T c[6] = { 0, 1, 0, 0, 0, 1 };

  static const int8_T f[6] = { 0, 0, 0, 0, 0, -1 };

  // DataTypeConversion: '<S15>/DataTypeConversion_vset'
  localB->DataTypeConversion_vset = rtu_Setvelocity;

  // DataTypeConversion: '<S15>/DataTypeConversion_Vx'
  localB->DataTypeConversion_Vx = rtu_Longitudinalvelocity;

  // Product: '<S57>/Divide' incorporates:
  //   Constant: '<S57>/Scalar one constant'
  //   Constant: '<S57>/Vehicle acceleration tracking time constant'

  localB->utau = localP->Scalaroneconstant_Value /
    localP->Vehicleaccelerationtrackingtime;

  // Concatenate: '<S55>/Matrix Concatenate3' incorporates:
  //   Constant: '<S55>/Matrix constant'
  //   Constant: '<S57>/Scalar one constant'
  //   Constant: '<S57>/Vector constant'
  //   UnaryMinus: '<S57>/Unary Minus'

  localB->MatrixConcatenate1[0] = -localB->utau;
  localB->MatrixConcatenate1[2] = localP->Matrixconstant_Value[0];
  localB->MatrixConcatenate1[1] = localP->Scalaroneconstant_Value;
  localB->MatrixConcatenate1[3] = localP->Matrixconstant_Value[1];
  localB->MatrixConcatenate1[4] = localP->Vectorconstant_Value[0];
  localB->MatrixConcatenate1[6] = localP->Matrixconstant_Value[2];
  localB->MatrixConcatenate1[5] = localP->Vectorconstant_Value[1];
  localB->MatrixConcatenate1[7] = localP->Matrixconstant_Value[3];
  for (localB->r1 = 0; localB->r1 < 8; localB->r1++) {
    localB->MatrixConcatenate[localB->r1] = localB->MatrixConcatenate1
      [localB->r1];
  }

  // End of Concatenate: '<S55>/Matrix Concatenate3'

  // Product: '<S56>/Product1' incorporates:
  //   Constant: '<S56>/Vehicle front tire cornering stiffness constant'
  //   Constant: '<S56>/Vehicle length to front constant'
  //   Product: '<S56>/Divide1'

  localB->rtb_b2_tmp = localP->Vehiclelengthtofrontconstant_Va *
    localP->Vehiclefronttirecorneringstiffn;

  // Concatenate: '<S55>/Matrix Concatenate4' incorporates:
  //   Constant: '<S55>/Matrix constant'
  //   Constant: '<S56>/Vehicle front tire cornering stiffness constant'
  //   Constant: '<S56>/Vehicle mass constant'
  //   Constant: '<S56>/Vehicle rear tire cornering stiffness constant'
  //   Gain: '<S56>/Gain2'
  //   Product: '<S56>/Divide2'
  //   Sum: '<S56>/Sum'

  localB->MatrixConcatenate1[0] = localP->Matrixconstant_Value[0];
  localB->MatrixConcatenate1[2] = (localP->Vehiclereartirecorneringstiffne +
    localP->Vehiclefronttirecorneringstiffn) * localP->Gain2_Gain /
    localP->Vehiclemassconstant_Value / localB->DataTypeConversion_Vx;
  localB->MatrixConcatenate1[1] = localP->Matrixconstant_Value[1];

  // Product: '<S56>/Divide4' incorporates:
  //   Constant: '<S56>/Vehicle length to rear constant'
  //   Constant: '<S56>/Vehicle rear tire cornering stiffness constant'
  //   Gain: '<S56>/Gain3'
  //   Product: '<S56>/Divide3'
  //   Product: '<S56>/Product'
  //   Product: '<S56>/Product1'
  //   Sum: '<S56>/Sum1'

  localB->maxval = (localB->rtb_b2_tmp - localP->Vehiclelengthtorearconstant_Val
                    * localP->Vehiclereartirecorneringstiffne) *
    localP->Gain3_Gain / localB->DataTypeConversion_Vx;

  // Concatenate: '<S55>/Matrix Concatenate4' incorporates:
  //   Constant: '<S55>/Matrix constant'
  //   Constant: '<S56>/Vehicle front tire cornering stiffness constant'
  //   Constant: '<S56>/Vehicle length to front constant'
  //   Constant: '<S56>/Vehicle length to rear constant'
  //   Constant: '<S56>/Vehicle mass constant'
  //   Constant: '<S56>/Vehicle rear tire cornering stiffness constant'
  //   Constant: '<S56>/Vehicle yaw inertia constant'
  //   Gain: '<S56>/Gain4'
  //   Product: '<S56>/Divide3'
  //   Product: '<S56>/Divide4'
  //   Product: '<S56>/Divide5'
  //   Product: '<S56>/Divide6'
  //   Product: '<S56>/Divide7'
  //   Sum: '<S56>/Sum2'
  //   Sum: '<S56>/Sum3'

  localB->MatrixConcatenate1[3] = localB->maxval /
    localP->Vehicleyawinertiaconstant_Value;
  localB->MatrixConcatenate1[4] = localP->Matrixconstant_Value[2];
  localB->MatrixConcatenate1[6] = localB->maxval /
    localP->Vehiclemassconstant_Value - localB->DataTypeConversion_Vx;
  localB->MatrixConcatenate1[5] = localP->Matrixconstant_Value[3];
  localB->MatrixConcatenate1[7] = (localP->Vehiclelengthtorearconstant_Val *
    localP->Vehiclelengthtorearconstant_Val *
    localP->Vehiclereartirecorneringstiffne +
    localP->Vehiclelengthtofrontconstant_Va *
    localP->Vehiclelengthtofrontconstant_Va *
    localP->Vehiclefronttirecorneringstiffn) * localP->Gain4_Gain /
    localB->DataTypeConversion_Vx / localP->Vehicleyawinertiaconstant_Value;
  for (localB->r1 = 0; localB->r1 < 8; localB->r1++) {
    localB->MatrixConcatenate[localB->r1 + 8] = localB->
      MatrixConcatenate1[localB->r1];
  }

  // SignalConversion generated from: '<S55>/Matrix Concatenate5' incorporates:
  //   Constant: '<S57>/Scalar zero constant'

  localB->MatrixConcatenate1[0] = localB->utau;
  localB->MatrixConcatenate1[1] = localP->Scalarzeroconstant_Value;

  // SignalConversion generated from: '<S55>/Matrix Concatenate6' incorporates:
  //   Constant: '<S56>/Vehicle front tire cornering stiffness constant'
  //   Constant: '<S56>/Vehicle mass constant'
  //   Constant: '<S56>/Vehicle yaw inertia constant'
  //   Gain: '<S56>/Gain'
  //   Gain: '<S56>/Gain1'
  //   Product: '<S56>/Divide'
  //   Product: '<S56>/Divide1'

  localB->MatrixConcatenate1[6] = localP->Vehiclefronttirecorneringstiffn /
    localP->Vehiclemassconstant_Value * localP->Gain_Gain;
  localB->MatrixConcatenate1[7] = localB->rtb_b2_tmp /
    localP->Vehicleyawinertiaconstant_Value * localP->Gain1_Gain;

  // SignalConversion generated from: '<S55>/Matrix Concatenate5' incorporates:
  //   Constant: '<S55>/Vector constant'

  localB->MatrixConcatenate1[2] = localP->Vectorconstant_Value_l[0];

  // SignalConversion generated from: '<S55>/Matrix Concatenate6' incorporates:
  //   Constant: '<S55>/Vector constant'

  localB->MatrixConcatenate1[4] = localP->Vectorconstant_Value_l[0];

  // Concatenate: '<S55>/Matrix Concatenate7' incorporates:
  //   Constant: '<S55>/Matrix constant1'
  //   Constant: '<S57>/Cn constant'

  localB->fv6[0] = localP->Cnconstant_Value[0];
  localB->fv6[1] = localP->Matrixconstant1_Value[0];
  localB->fv6[2] = localP->Matrixconstant1_Value[1];

  // SignalConversion generated from: '<S55>/Matrix Concatenate5' incorporates:
  //   Constant: '<S55>/Vector constant'

  localB->MatrixConcatenate1[3] = localP->Vectorconstant_Value_l[1];

  // SignalConversion generated from: '<S55>/Matrix Concatenate6' incorporates:
  //   Constant: '<S55>/Vector constant'

  localB->MatrixConcatenate1[5] = localP->Vectorconstant_Value_l[1];

  // Concatenate: '<S55>/Matrix Concatenate7' incorporates:
  //   Constant: '<S55>/Matrix constant1'
  //   Constant: '<S57>/Cn constant'

  localB->fv6[3] = localP->Cnconstant_Value[1];
  localB->fv6[4] = localP->Matrixconstant1_Value[2];
  localB->fv6[5] = localP->Matrixconstant1_Value[3];
  for (localB->r1 = 0; localB->r1 < 6; localB->r1++) {
    localB->MatrixConcatenate2[localB->r1] = localB->fv6[localB->r1];
  }

  // Concatenate: '<S55>/Matrix Concatenate8' incorporates:
  //   Constant: '<S55>/Vector constant1'
  //   Constant: '<S56>/Cm Constant'

  localB->fv6[0] = localP->Vectorconstant1_Value[0];
  localB->fv6[1] = localP->CmConstant_Value[0];
  localB->fv6[2] = localP->CmConstant_Value[1];
  localB->fv6[3] = localP->Vectorconstant1_Value[1];
  localB->fv6[4] = localP->CmConstant_Value[2];
  localB->fv6[5] = localP->CmConstant_Value[3];
  for (localB->r1 = 0; localB->r1 < 6; localB->r1++) {
    localB->MatrixConcatenate2[localB->r1 + 6] = localB->fv6[localB->r1];
  }

  // End of Concatenate: '<S55>/Matrix Concatenate8'

  // MATLAB Function: '<S52>/Adaptive Model' incorporates:
  //   Concatenate: '<S55>/Matrix Concatenate'
  //   Concatenate: '<S55>/Matrix Concatenate1'
  //   Concatenate: '<S55>/Matrix Concatenate2'
  //   Constant: '<S14>/Sample time constant'
  //   Constant: '<S14>/Transport lag constant'

  for (localB->r1 = 0; localB->r1 < 4; localB->r1++) {
    localB->Coef = localB->r1 << 2;
    localB->Cm_j[localB->Coef] = localB->MatrixConcatenate2[3 * localB->r1];
    localB->Cm_j[localB->Coef + 1] = localB->MatrixConcatenate2[3 * localB->r1 +
      1];
    localB->Cm_j[localB->Coef + 2] = localB->MatrixConcatenate2[3 * localB->r1 +
      2];
    localB->Cm_j[localB->Coef + 3] = 0.0F;
    for (localB->r2 = 0; localB->r2 < 3; localB->r2++) {
      localB->rtemp = localB->r2 + 3 * localB->r1;
      localB->e[localB->rtemp] = 0.0F;
      localB->e[localB->rtemp] += localB->Cm_j[localB->Coef] *
        static_cast<real32_T>(e_0[localB->r2]);
      localB->e[localB->rtemp] += localB->Cm_j[localB->Coef + 1] *
        static_cast<real32_T>(e_0[localB->r2 + 3]);
      localB->e[localB->rtemp] += localB->Cm_j[localB->Coef + 2] *
        static_cast<real32_T>(e_0[localB->r2 + 6]);
      localB->e[localB->rtemp] += localB->Cm_j[localB->Coef + 3] *
        static_cast<real32_T>(e_0[localB->r2 + 9]);
    }
  }

  for (localB->r1 = 0; localB->r1 < 12; localB->r1++) {
    localB->Cs[localB->r1] = localB->e[localB->r1];
  }

  for (localB->r1 = 0; localB->r1 < 6; localB->r1++) {
    localB->Cs[localB->r1 + 12] = c[localB->r1];
  }

  localB->utau = -1.0F / localP->Transportlagconstant_Value;
  localB->rtb_b2_tmp = 1.0F / localP->Transportlagconstant_Value;
  for (localB->r1 = 0; localB->r1 < 9; localB->r1++) {
    localB->r2 = d[localB->r1];
    localB->Bl_d[localB->r1] = localB->rtb_b2_tmp * static_cast<real32_T>
      (localB->r2);
    localB->Kinv[localB->r1] = static_cast<real32_T>(localB->r2);
  }

  for (localB->r1 = 0; localB->r1 < 4; localB->r1++) {
    for (localB->r2 = 0; localB->r2 < 2; localB->r2++) {
      localB->Coef = localB->r2 + (localB->r1 << 1);
      localB->g[localB->Coef] = 0.0F;
      localB->rtemp = localB->r1 << 2;
      localB->g[localB->Coef] += localB->Cm_j[localB->rtemp] * 0.0F;
      localB->g[localB->Coef] += localB->Cm_j[localB->rtemp + 1] *
        static_cast<real32_T>(g_0[localB->r2 + 2]);
      localB->g[localB->Coef] += localB->Cm_j[localB->rtemp + 2] *
        static_cast<real32_T>(g_0[localB->r2 + 4]);
      localB->g[localB->Coef] += localB->Cm_j[localB->rtemp + 3] *
        static_cast<real32_T>(g_0[localB->r2 + 6]);
    }
  }

  for (localB->r1 = 0; localB->r1 < 6; localB->r1++) {
    for (localB->r2 = 0; localB->r2 < 3; localB->r2++) {
      localB->Coef = localB->r2 + 3 * localB->r1;
      localB->Bl[localB->Coef] = 0.0F;
      localB->Bl[localB->Coef] += localB->Cs[3 * localB->r1] * localB->
        Bl_d[localB->r2];
      localB->Bl[localB->Coef] += localB->Cs[3 * localB->r1 + 1] * localB->
        Bl_d[localB->r2 + 3];
      localB->Bl[localB->Coef] += localB->Cs[3 * localB->r1 + 2] * localB->
        Bl_d[localB->r2 + 6];
    }
  }

  for (localB->r1 = 0; localB->r1 < 4; localB->r1++) {
    localB->r2 = localB->r1 << 2;
    localB->Az[9 * localB->r1] = localB->MatrixConcatenate[localB->r2];
    localB->Az[9 * localB->r1 + 1] = localB->MatrixConcatenate[localB->r2 + 1];
    localB->Az[9 * localB->r1 + 2] = localB->MatrixConcatenate[localB->r2 + 2];
    localB->Az[9 * localB->r1 + 3] = localB->MatrixConcatenate[localB->r2 + 3];
  }

  for (localB->r1 = 0; localB->r1 < 2; localB->r1++) {
    localB->r2 = 9 * (localB->r1 + 4);
    localB->Az[localB->r2] = 0.0F;
    localB->Az[localB->r2 + 1] = 0.0F;
    localB->Az[localB->r2 + 2] = 0.0F;
    localB->Az[localB->r2 + 3] = 0.0F;
  }

  for (localB->r1 = 0; localB->r1 < 4; localB->r1++) {
    localB->r2 = localB->r1 << 1;
    localB->Az[9 * localB->r1 + 4] = localB->g[localB->r2];
    localB->Az[9 * localB->r1 + 5] = localB->g[localB->r2 + 1];
  }

  localB->Az[40] = 0.0F;
  localB->Az[41] = 0.0F;
  localB->Az[49] = localB->DataTypeConversion_Vx;
  localB->Az[50] = 0.0F;
  for (localB->r1 = 0; localB->r1 < 3; localB->r1++) {
    for (localB->r2 = 0; localB->r2 < 6; localB->r2++) {
      localB->Az[localB->r2 + 9 * (localB->r1 + 6)] = 0.0F;
    }
  }

  for (localB->r1 = 0; localB->r1 < 6; localB->r1++) {
    localB->Az[9 * localB->r1 + 6] = localB->Bl[3 * localB->r1];
    localB->Az[9 * localB->r1 + 7] = localB->Bl[3 * localB->r1 + 1];
    localB->Az[9 * localB->r1 + 8] = localB->Bl[3 * localB->r1 + 2];
  }

  for (localB->r1 = 0; localB->r1 < 3; localB->r1++) {
    for (localB->r2 = 0; localB->r2 < 3; localB->r2++) {
      localB->Az[(localB->r2 + 9 * (localB->r1 + 6)) + 6] = localB->Kinv[3 *
        localB->r1 + localB->r2] * localB->utau;
      localB->Coef = localB->r1 + 3 * localB->r2;
      localB->Bl_l[localB->Coef] = 0.0F;
      localB->Bl_l[localB->Coef] += localB->Bl_d[localB->r1] * 0.0F;
      localB->Bl_l[localB->Coef] += localB->Bl_d[localB->r1 + 3] * 0.0F;
      localB->Bl_l[localB->Coef] += localB->Bl_d[localB->r1 + 6] * 0.0F;
    }
  }

  for (localB->r1 = 0; localB->r1 < 2; localB->r1++) {
    localB->r2 = localB->r1 << 2;
    localB->Bz[9 * localB->r1] = localB->MatrixConcatenate1[localB->r2];
    localB->Bz[9 * localB->r1 + 1] = localB->MatrixConcatenate1[localB->r2 + 1];
    localB->Bz[9 * localB->r1 + 2] = localB->MatrixConcatenate1[localB->r2 + 2];
    localB->Bz[9 * localB->r1 + 3] = localB->MatrixConcatenate1[localB->r2 + 3];
  }

  localB->Bz[18] = 0.0F;
  localB->Bz[19] = 0.0F;
  localB->Bz[20] = 0.0F;
  localB->Bz[21] = 0.0F;
  for (localB->r1 = 0; localB->r1 < 3; localB->r1++) {
    localB->Bz[9 * localB->r1 + 4] = 0.0F;
    localB->Bz[9 * localB->r1 + 5] = f[(localB->r1 << 1) + 1];
    localB->Bz[9 * localB->r1 + 6] = localB->Bl_l[3 * localB->r1];
    localB->Bz[9 * localB->r1 + 7] = localB->Bl_l[3 * localB->r1 + 1];
    localB->Bz[9 * localB->r1 + 8] = localB->Bl_l[3 * localB->r1 + 2];
  }

  if (localP->Sampletimeconstant_Value > 0.0F) {
    for (localB->r1 = 0; localB->r1 < 81; localB->r1++) {
      localB->Az_c[localB->r1] = localB->Az[localB->r1] *
        localP->Sampletimeconstant_Value;
    }

    Controller_MPC_expm(localB->Az_c, localB->A, localB);
    localB->utau = localP->Sampletimeconstant_Value / 4.0F;
    memset(&localB->b_I[0], 0, 81U * sizeof(int8_T));
    for (localB->Coef = 0; localB->Coef < 9; localB->Coef++) {
      localB->b_I[localB->Coef + 9 * localB->Coef] = 1;
    }

    for (localB->r1 = 0; localB->r1 < 81; localB->r1++) {
      localB->Ai[localB->r1] = static_cast<real32_T>(localB->b_I[localB->r1]) +
        localB->A[localB->r1];
    }

    localB->Coef = 2;
    for (localB->r2 = 0; localB->r2 < 3; localB->r2++) {
      if (localB->Coef == 2) {
        localB->Coef = 4;
      } else {
        localB->Coef = 2;
      }

      for (localB->r1 = 0; localB->r1 < 81; localB->r1++) {
        localB->Az_c[localB->r1] = static_cast<real32_T>(localB->r2 + 1) *
          localB->Az[localB->r1] * localB->utau;
      }

      Controller_MPC_expm(localB->Az_c, localB->b_p, localB);
      for (localB->r1 = 0; localB->r1 < 81; localB->r1++) {
        localB->Ai[localB->r1] += static_cast<real32_T>(localB->Coef) *
          localB->b_p[localB->r1];
      }
    }

    localB->utau /= 3.0F;
    for (localB->r1 = 0; localB->r1 < 9; localB->r1++) {
      for (localB->r2 = 0; localB->r2 < 3; localB->r2++) {
        localB->rtemp = localB->r1 + 9 * localB->r2;
        localB->B[localB->rtemp] = 0.0F;
        for (localB->Coef = 0; localB->Coef < 9; localB->Coef++) {
          localB->B[localB->rtemp] += localB->Ai[9 * localB->Coef + localB->r1] *
            localB->utau * localB->Bz[9 * localB->r2 + localB->Coef];
        }
      }
    }
  } else {
    memcpy(&localB->A[0], &localB->Az[0], 81U * sizeof(real32_T));
    memcpy(&localB->B[0], &localB->Bz[0], 27U * sizeof(real32_T));
  }

  for (localB->r1 = 0; localB->r1 < 6; localB->r1++) {
    for (localB->r2 = 0; localB->r2 < 3; localB->r2++) {
      localB->Coef = localB->r2 + 3 * localB->r1;
      localB->Bl[localB->Coef] = 0.0F;
      localB->Bl[localB->Coef] += localB->Cs[3 * localB->r1] * 0.0F;
      localB->Bl[localB->Coef] += localB->Cs[3 * localB->r1 + 1] * 0.0F;
      localB->Bl[localB->Coef] += localB->Cs[3 * localB->r1 + 2] * 0.0F;
    }
  }

  memcpy(&localB->C[0], &localB->Bl[0], 18U * sizeof(real32_T));
  for (localB->r1 = 0; localB->r1 < 9; localB->r1++) {
    localB->C[localB->r1 + 18] = localB->Kinv[localB->r1];
  }

  memset(&localB->D[0], 0, 9U * sizeof(real_T));

  // End of MATLAB Function: '<S52>/Adaptive Model'

  // Product: '<S15>/Product' incorporates:
  //   DataTypeConversion: '<S15>/DataTypeConversion_curvature'

  localB->Product = rtu_Curvature * localB->DataTypeConversion_Vx;

  // DataTypeConversion: '<S15>/DataTypeConversion_amin' incorporates:
  //   Constant: '<S14>/Minimum longitudinal acceleration constant'

  localB->DataTypeConversion_amin = static_cast<real32_T>(rtp_MinAcceleration);

  // DataTypeConversion: '<S15>/DataTypeConversion_umin' incorporates:
  //   Constant: '<S14>/Minimum steering angle constant'

  localB->DataTypeConversion_umin = static_cast<real32_T>(rtp_MinSteering);

  // DataTypeConversion: '<S15>/DataTypeConversion_amax' incorporates:
  //   Constant: '<S14>/Maximum longitudinal acceleration constant'

  localB->DataTypeConversion_amax = static_cast<real32_T>(rtp_MaxAcceleration);

  // DataTypeConversion: '<S15>/DataTypeConversion_umax' incorporates:
  //   Constant: '<S14>/Maximum steering angle constant'

  localB->DataTypeConversion_umax = static_cast<real32_T>(rtp_MaxSteering);

  // Switch: '<S15>/Switch2' incorporates:
  //   Constant: '<S14>/Enable optimization constant'
  //   DataTypeConversion: '<S15>/DataTypeConversion_optsgn'

  if (static_cast<real32_T>(localP->Enableoptimizationconstant_Valu) != 0.0F) {
    // Switch: '<S15>/Switch2' incorporates:
    //   Constant: '<S15>/Use PFC output constant'

    localB->Switch2 = localP->UsePFCoutputconstant_Value;
  } else {
    // Switch: '<S15>/Switch2' incorporates:
    //   Constant: '<S15>/Not use PFC output constant'

    localB->Switch2 = localP->NotusePFCoutputconstant_Value;
  }

  // End of Switch: '<S15>/Switch2'

  // DataTypeConversion: '<S15>/DataTypeConversion_e1'
  localB->DataTypeConversion_e1 = rtu_Lateraldeviation;

  // DataTypeConversion: '<S15>/DataTypeConversion_e2'
  localB->DataTypeConversion_e2 = rtu_Relativeyawangle;

  // MATLAB Function: '<S50>/FixedHorizonOptimizer'
  memset(&localB->Bu[0], 0, 1220U * sizeof(real32_T));
  memset(&localB->Bv[0], 0, 1220U * sizeof(real32_T));
  memset(&localB->Dv[0], 0, 366U * sizeof(real32_T));
  memset(&localB->Dvm[0], 0, 366U * sizeof(real32_T));
  memset(&localB->Cm[0], 0, 1830U * sizeof(real32_T));
  memcpy(&localB->b_A[0], &e[0], 100U * sizeof(real32_T));
  memcpy(&localB->b_C[0], &g[0], 30U * sizeof(real32_T));

  // DataTypeConversion: '<S22>/Data Type Conversion17'
  for (localB->r1 = 0; localB->r1 < 9; localB->r1++) {
    localB->Bl_d[localB->r1] = static_cast<real32_T>(localB->D[localB->r1]);
  }

  // End of DataTypeConversion: '<S22>/Data Type Conversion17'

  // MATLAB Function: '<S50>/FixedHorizonOptimizer'
  localB->fv7[0] = 1.0F;
  localB->fv7[1] = 2.0F;
  localB->Cm_n[0] = 1.0F;
  localB->Cm_n[1] = 2.0F;
  localB->Cm_n[2] = 3.0F;

  // DataTypeConversion: '<S22>/Data Type Conversion15'
  memcpy(&localB->Bz[0], &localB->B[0], 27U * sizeof(real32_T));

  // MATLAB Function: '<S50>/FixedHorizonOptimizer' incorporates:
  //   Constant: '<S15>/Lateral deviation reference constant'
  //   Constant: '<S15>/Relative yaw angle reference constant '
  //   Constant: '<S52>/DX Constant'
  //   Constant: '<S52>/U Constant'
  //   Constant: '<S52>/X Constant'
  //   Constant: '<S52>/Y Constant'
  //   DataTypeConversion: '<S22>/Data Type Conversion1'
  //   DataTypeConversion: '<S22>/Data Type Conversion14'
  //   DataTypeConversion: '<S22>/Data Type Conversion16'
  //   DataTypeConversion: '<S22>/Data Type Conversion2'
  //   DataTypeConversion: '<S22>/mo or x Conversion'
  //   Memory: '<S22>/LastPcov'
  //   Memory: '<S22>/last_x'

  memcpy(&localB->f[0], &f_0[0], 80U * sizeof(real32_T));
  memcpy(&localB->h[0], &h[0], 24U * sizeof(real32_T));
  Controller_MPC_mpc_plantupdate(localB->A, localB->Bz, localB->C, localB->Bl_d,
    localB->b_A, localB->f, localB->b_C, localB->h, localB->fv7, localB->Cm_n, l,
    n, localB->b_Mlim, &localB->Bv[0], localB->L, &localB->Dv[0], &localB->Dvm[0],
    localB->Qk, localB->Kinv, localB->Nk, localB);
  for (localB->r1 = 0; localB->r1 < 2; localB->r1++) {
    for (localB->r2 = 0; localB->r2 < 10; localB->r2++) {
      localB->Bu[localB->r2 + 10 * localB->r1] = localB->b_Mlim[10 * localB->r1
        + localB->r2];
    }
  }

  for (localB->r1 = 0; localB->r1 < 10; localB->r1++) {
    localB->Cm[3 * localB->r1] = localB->L[3 * localB->r1];
    localB->Coef = 3 * localB->r1 + 1;
    localB->Cm[localB->Coef] = localB->L[localB->Coef];
    localB->Coef = 3 * localB->r1 + 2;
    localB->Cm[localB->Coef] = localB->L[localB->Coef];
  }

  memcpy(&localB->b_Mlim[0], &o[0], 20U * sizeof(real32_T));
  memset(&localB->b_utarget[0], 0, 120U * sizeof(real32_T));
  for (localB->r2 = 0; localB->r2 < 10; localB->r2++) {
    localB->b_xoff[localB->r2] = 0.0F;
  }

  localB->fv7[0] = 0.0F;
  localB->fv8[0] = 1.0F;
  localB->fv7[1] = 0.0F;
  localB->fv8[1] = 2.0F;
  localB->Cm_n[0] = 1.0F;
  localB->Cm_n[1] = 2.0F;
  localB->Cm_n[2] = 3.0F;
  Controlle_mpc_updateFromNominal(localB->b_Mlim, q, localP->UConstant_Value, l,
    localB->fv7, localB->fv8, localB->b_utarget, localP->YConstant_Value, n, r,
    localB->Cm_n, localP->XConstant_Value, localB->b_xoff,
    localP->DXConstant_Value, localB->Bv, localB->b_uoff, &localB->utau,
    localB->y_innov, localB->b_myoff);
  memset(&localB->vseq[0], 0, 122U * sizeof(real32_T));
  for (localB->r2 = 0; localB->r2 < 61; localB->r2++) {
    localB->vseq[(localB->r2 << 1) + 1] = 1.0F;
  }

  for (localB->r1 = 0; localB->r1 < 60; localB->r1++) {
    localB->rseq[localB->r1 * 3] = localB->DataTypeConversion_vset *
      0.0333333351F - localB->y_innov[0];
    localB->rseq[localB->r1 * 3 + 1] = localP->Lateraldeviationreferenceconsta -
      localB->y_innov[1];
    localB->rseq[localB->r1 * 3 + 2] = localP->Relativeyawanglereferenceconsta *
      5.0F - localB->y_innov[2];
  }

  for (localB->r1 = 0; localB->r1 < 61; localB->r1++) {
    localB->vseq[localB->r1 << 1] = Controller_MPC_RMDscale * localB->Product -
      localB->utau;
  }

  localB->utau = localB->vseq[0];
  localB->rtb_b2_tmp = localB->vseq[1];
  for (localB->r1 = 0; localB->r1 < 9; localB->r1++) {
    localB->c_A_l[localB->r1] = 0;
  }

  for (localB->Coef = 0; localB->Coef < 3; localB->Coef++) {
    localB->c_A_l[localB->Coef + 3 * localB->Coef] = 1;
    for (localB->r1 = 0; localB->r1 < 10; localB->r1++) {
      localB->rtemp = 3 * localB->r1 + localB->Coef;
      localB->b_B_tmp[localB->r1 + 10 * localB->Coef] = localB->Cm[localB->rtemp];
      localB->L[localB->rtemp] = 0.0F;
      for (localB->r2 = 0; localB->r2 < 10; localB->r2++) {
        localB->L[localB->rtemp] += localB->Cm[3 * localB->r2 + localB->Coef] *
          localDW->LastPcov_PreviousInput[10 * localB->r1 + localB->r2];
      }
    }
  }

  for (localB->r1 = 0; localB->r1 < 3; localB->r1++) {
    for (localB->r2 = 0; localB->r2 < 3; localB->r2++) {
      localB->maxval = 0.0F;
      for (localB->Coef = 0; localB->Coef < 10; localB->Coef++) {
        localB->maxval += localB->L[3 * localB->Coef + localB->r1] *
          localB->b_B_tmp[10 * localB->r2 + localB->Coef];
      }

      localB->Coef = 3 * localB->r2 + localB->r1;
      localB->Bl_d[localB->Coef] = localB->Kinv[localB->Coef] + localB->maxval;
    }
  }

  localB->r1 = 0;
  localB->r2 = 1;
  localB->Coef = 2;
  localB->maxval = static_cast<real32_T>(fabs(static_cast<real_T>(localB->Bl_d[0])));
  localB->y = static_cast<real32_T>(fabs(static_cast<real_T>(localB->Bl_d[1])));
  if (localB->y > localB->maxval) {
    localB->maxval = localB->y;
    localB->r1 = 1;
    localB->r2 = 0;
  }

  if (static_cast<real32_T>(fabs(static_cast<real_T>(localB->Bl_d[2]))) >
      localB->maxval) {
    localB->r1 = 2;
    localB->r2 = 1;
    localB->Coef = 0;
  }

  localB->Bl_d[localB->r2] /= localB->Bl_d[localB->r1];
  localB->Bl_d[localB->Coef] /= localB->Bl_d[localB->r1];
  localB->Bl_d[localB->r2 + 3] -= localB->Bl_d[localB->r1 + 3] * localB->
    Bl_d[localB->r2];
  localB->Bl_d[localB->Coef + 3] -= localB->Bl_d[localB->r1 + 3] * localB->
    Bl_d[localB->Coef];
  localB->Bl_d[localB->r2 + 6] -= localB->Bl_d[localB->r1 + 6] * localB->
    Bl_d[localB->r2];
  localB->Bl_d[localB->Coef + 6] -= localB->Bl_d[localB->r1 + 6] * localB->
    Bl_d[localB->Coef];
  if (static_cast<real32_T>(fabs(static_cast<real_T>(localB->Bl_d[localB->Coef +
         3]))) > static_cast<real32_T>(fabs(static_cast<real_T>(localB->
         Bl_d[localB->r2 + 3])))) {
    localB->rtemp = localB->r2;
    localB->r2 = localB->Coef;
    localB->Coef = localB->rtemp;
  }

  localB->Bl_d[localB->Coef + 3] /= localB->Bl_d[localB->r2 + 3];
  localB->Bl_d[localB->Coef + 6] -= localB->Bl_d[localB->Coef + 3] *
    localB->Bl_d[localB->r2 + 6];
  localB->Kinv[3 * localB->r1] = static_cast<real32_T>(localB->c_A_l[0]) /
    localB->Bl_d[localB->r1];
  localB->maxval = localB->Bl_d[localB->r1 + 3];
  localB->Kinv[3 * localB->r2] = static_cast<real32_T>(localB->c_A_l[3]) -
    localB->Kinv[3 * localB->r1] * localB->maxval;
  localB->y = localB->Bl_d[localB->r1 + 6];
  localB->Kinv[3 * localB->Coef] = static_cast<real32_T>(localB->c_A_l[6]) -
    localB->Kinv[3 * localB->r1] * localB->y;
  localB->Kinv_tmp = localB->Bl_d[localB->r2 + 3];
  localB->Kinv[3 * localB->r2] /= localB->Kinv_tmp;
  localB->Kinv_tmp_d = localB->Bl_d[localB->r2 + 6];
  localB->Kinv[3 * localB->Coef] -= localB->Kinv[3 * localB->r2] *
    localB->Kinv_tmp_d;
  localB->Kinv_tmp_e = localB->Bl_d[localB->Coef + 6];
  localB->Kinv[3 * localB->Coef] /= localB->Kinv_tmp_e;
  localB->Kinv_tmp_b = localB->Bl_d[localB->Coef + 3];
  localB->Kinv[3 * localB->r2] -= localB->Kinv[3 * localB->Coef] *
    localB->Kinv_tmp_b;
  localB->Kinv[3 * localB->r1] -= localB->Kinv[3 * localB->Coef] * localB->
    Bl_d[localB->Coef];
  localB->Kinv[3 * localB->r1] -= localB->Kinv[3 * localB->r2] * localB->
    Bl_d[localB->r2];
  localB->rtemp = 3 * localB->r1 + 1;
  localB->Kinv[localB->rtemp] = static_cast<real32_T>(localB->c_A_l[1]) /
    localB->Bl_d[localB->r1];
  localB->Kinv_tmp_j = 3 * localB->r2 + 1;
  localB->Kinv[localB->Kinv_tmp_j] = static_cast<real32_T>(localB->c_A_l[4]) -
    localB->Kinv[localB->rtemp] * localB->maxval;
  localB->Kinv_tmp_f = 3 * localB->Coef + 1;
  localB->Kinv[localB->Kinv_tmp_f] = static_cast<real32_T>(localB->c_A_l[7]) -
    localB->Kinv[localB->rtemp] * localB->y;
  localB->Kinv[localB->Kinv_tmp_j] /= localB->Kinv_tmp;
  localB->Kinv[localB->Kinv_tmp_f] -= localB->Kinv[localB->Kinv_tmp_j] *
    localB->Kinv_tmp_d;
  localB->Kinv[localB->Kinv_tmp_f] /= localB->Kinv_tmp_e;
  localB->Kinv[localB->Kinv_tmp_j] -= localB->Kinv[localB->Kinv_tmp_f] *
    localB->Kinv_tmp_b;
  localB->Kinv[localB->rtemp] -= localB->Kinv[localB->Kinv_tmp_f] * localB->
    Bl_d[localB->Coef];
  localB->Kinv[localB->rtemp] -= localB->Kinv[localB->Kinv_tmp_j] * localB->
    Bl_d[localB->r2];
  localB->rtemp = 3 * localB->r1 + 2;
  localB->Kinv[localB->rtemp] = static_cast<real32_T>(localB->c_A_l[2]) /
    localB->Bl_d[localB->r1];
  localB->Kinv_tmp_j = 3 * localB->r2 + 2;
  localB->Kinv[localB->Kinv_tmp_j] = static_cast<real32_T>(localB->c_A_l[5]) -
    localB->Kinv[localB->rtemp] * localB->maxval;
  localB->Kinv_tmp_f = 3 * localB->Coef + 2;
  localB->Kinv[localB->Kinv_tmp_f] = static_cast<real32_T>(localB->c_A_l[8]) -
    localB->Kinv[localB->rtemp] * localB->y;
  localB->Kinv[localB->Kinv_tmp_j] /= localB->Kinv_tmp;
  localB->Kinv[localB->Kinv_tmp_f] -= localB->Kinv[localB->Kinv_tmp_j] *
    localB->Kinv_tmp_d;
  localB->Kinv[localB->Kinv_tmp_f] /= localB->Kinv_tmp_e;
  localB->Kinv[localB->Kinv_tmp_j] -= localB->Kinv[localB->Kinv_tmp_f] *
    localB->Kinv_tmp_b;
  localB->Kinv[localB->rtemp] -= localB->Kinv[localB->Kinv_tmp_f] * localB->
    Bl_d[localB->Coef];
  localB->Kinv[localB->rtemp] -= localB->Kinv[localB->Kinv_tmp_j] * localB->
    Bl_d[localB->r2];
  for (localB->r1 = 0; localB->r1 < 10; localB->r1++) {
    for (localB->r2 = 0; localB->r2 < 10; localB->r2++) {
      localB->rtemp = localB->r1 + 10 * localB->r2;
      localB->L_tmp[localB->rtemp] = 0.0F;
      for (localB->Coef = 0; localB->Coef < 10; localB->Coef++) {
        localB->L_tmp[localB->rtemp] += localB->b_A[10 * localB->Coef +
          localB->r1] * localDW->LastPcov_PreviousInput[10 * localB->r2 +
          localB->Coef];
      }
    }

    for (localB->r2 = 0; localB->r2 < 3; localB->r2++) {
      localB->maxval = 0.0F;
      for (localB->Coef = 0; localB->Coef < 10; localB->Coef++) {
        localB->maxval += localB->L_tmp[10 * localB->Coef + localB->r1] *
          localB->b_B_tmp[10 * localB->r2 + localB->Coef];
      }

      localB->rtemp = 10 * localB->r2 + localB->r1;
      localB->L_tmp_n[localB->rtemp] = localB->Nk[localB->rtemp] +
        localB->maxval;
    }

    for (localB->r2 = 0; localB->r2 < 3; localB->r2++) {
      localB->Coef = localB->r1 + 10 * localB->r2;
      localB->L[localB->Coef] = 0.0F;
      localB->L[localB->Coef] += localB->Kinv[3 * localB->r2] * localB->
        L_tmp_n[localB->r1];
      localB->L[localB->Coef] += localB->Kinv[3 * localB->r2 + 1] *
        localB->L_tmp_n[localB->r1 + 10];
      localB->L[localB->Coef] += localB->Kinv[3 * localB->r2 + 2] *
        localB->L_tmp_n[localB->r1 + 20];
    }

    localB->xk[localB->r1] = (localB->Bu[localB->r1 + 10] * 0.0F + localB->
      Bu[localB->r1] * 0.0F) + (localDW->last_x_PreviousInput[localB->r1] -
      localB->b_xoff[localB->r1]);
  }

  for (localB->r1 = 0; localB->r1 < 3; localB->r1++) {
    localB->Cm_n[localB->r1] = 0.0F;
    for (localB->r2 = 0; localB->r2 < 10; localB->r2++) {
      localB->Cm_n[localB->r1] += localB->Cm[3 * localB->r2 + localB->r1] *
        localB->xk[localB->r2];
    }

    localB->Dvm_b[localB->r1] = localB->Dvm[localB->r1 + 3] * localB->rtb_b2_tmp
      + localB->Dvm[localB->r1] * localB->utau;
  }

  localB->y_innov[0] = (localB->DataTypeConversion_Vx * 0.0333333351F -
                        localB->b_myoff[0]) - (localB->Cm_n[0] + localB->Dvm_b[0]);
  localB->y_innov[1] = (localB->DataTypeConversion_e1 - localB->b_myoff[1]) -
    (localB->Cm_n[1] + localB->Dvm_b[1]);
  localB->y_innov[2] = (localB->DataTypeConversion_e2 * 5.0F - localB->b_myoff[2])
    - (localB->Cm_n[2] + localB->Dvm_b[2]);
  for (localB->r1 = 0; localB->r1 < 10; localB->r1++) {
    for (localB->r2 = 0; localB->r2 < 3; localB->r2++) {
      localB->Coef = localB->r1 + 10 * localB->r2;
      localB->Nk[localB->Coef] = 0.0F;
      for (localB->rtemp = 0; localB->rtemp < 10; localB->rtemp++) {
        localB->Nk[localB->Coef] += localDW->LastPcov_PreviousInput[10 *
          localB->rtemp + localB->r1] * localB->b_B_tmp[10 * localB->r2 +
          localB->rtemp];
      }
    }

    localB->maxval = 0.0F;
    for (localB->r2 = 0; localB->r2 < 3; localB->r2++) {
      localB->Coef = localB->r1 + 10 * localB->r2;
      localB->fv4[localB->Coef] = 0.0F;
      localB->fv4[localB->Coef] += localB->Kinv[3 * localB->r2] * localB->
        Nk[localB->r1];
      localB->fv4[localB->Coef] += localB->Kinv[3 * localB->r2 + 1] * localB->
        Nk[localB->r1 + 10];
      localB->fv4[localB->Coef] += localB->Kinv[3 * localB->r2 + 2] * localB->
        Nk[localB->r1 + 20];
      localB->maxval += localB->fv4[localB->Coef] * localB->y_innov[localB->r2];
    }

    localB->rtb_xest_l[localB->r1] = localB->xk[localB->r1] + localB->maxval;
  }

  // DataTypeConversion: '<S22>/Data Type Conversion4'
  localB->fv7[0] = localB->DataTypeConversion_amin;
  localB->fv7[1] = localB->DataTypeConversion_umin;

  // DataTypeConversion: '<S22>/Data Type Conversion5'
  localB->fv8[0] = localB->DataTypeConversion_amax;
  localB->fv8[1] = localB->DataTypeConversion_umax;

  // MATLAB Function: '<S50>/FixedHorizonOptimizer' incorporates:
  //   UnitDelay: '<S22>/last_mv'

  localB->fv9[0] = localDW->last_mv_DSTATE[0] - localB->b_uoff[0];
  localB->fv9[1] = localDW->last_mv_DSTATE[1] - localB->b_uoff[1];
  memset(&localB->fv1[0], 0, 1200U * sizeof(real32_T));
  memset(&localB->fv3[0], 0, 200U * sizeof(real32_T));
  memset(&localB->fv[0], 0, 2440U * sizeof(real32_T));
  localB->fv10[0] = 1.0E-6F;
  localB->fv11[0] = 0.0F;
  localB->fv12[0] = 0.2F;
  localB->fv10[1] = 900.0F;
  localB->fv11[1] = 0.0F;
  localB->fv12[1] = 0.961538434F;

  // Memory: '<S22>/Memory'
  for (localB->r1 = 0; localB->r1 < 20; localB->r1++) {
    localB->bv[localB->r1] = localDW->Memory_PreviousInput[localB->r1];
  }

  // End of Memory: '<S22>/Memory'

  // MATLAB Function: '<S50>/FixedHorizonOptimizer'
  memcpy(&localB->bb[0], &bb[0], 40U * sizeof(real32_T));
  memcpy(&localB->cb[0], &cb[0], 121U * sizeof(real32_T));
  memcpy(&localB->eb[0], &eb[0], 220U * sizeof(real32_T));

  // Update for Memory: '<S22>/Memory' incorporates:
  //   DataTypeConversion: '<S22>/Data Type Conversion8'
  //   MATLAB Function: '<S50>/FixedHorizonOptimizer'

  Controller_M_mpcblock_optimizer(localB->rseq, localB->vseq, localB->fv7,
    localB->fv8, localB->Switch2, localB->rtb_xest_l, localB->fv9, localB->bv,
    localB->b_Mlim, localB->fv3, localB->bb, localB->fv, localB->b_utarget,
    localB->b_uoff, 0.0F, localB->cb, localB->eb, fb, localB->fv10, gb,
    localB->fv11, lb, localB->b_A, localB->Bu, localB->Bv, localB->b_C,
    localB->Dv, q, localB->fv12, localDW->last_mv_DSTATE,
    localB->rtb_useq_scale_c, &localB->rtb_status_b,
    localDW->Memory_PreviousInput, localB);

  // MATLAB Function: '<S50>/FixedHorizonOptimizer'
  for (localB->r1 = 0; localB->r1 < 10; localB->r1++) {
    for (localB->r2 = 0; localB->r2 < 10; localB->r2++) {
      localB->rtemp = localB->r1 + 10 * localB->r2;
      localB->L_tmp_k[localB->rtemp] = 0.0F;
      for (localB->Coef = 0; localB->Coef < 10; localB->Coef++) {
        localB->L_tmp_k[localB->rtemp] += localB->L_tmp[10 * localB->Coef +
          localB->r1] * localB->b_A[10 * localB->Coef + localB->r2];
      }

      localB->L_tmp_c[localB->rtemp] = 0.0F;
      localB->L_tmp_c[localB->rtemp] += localB->L_tmp_n[localB->r1] * localB->
        L[localB->r2];
      localB->L_tmp_c[localB->rtemp] += localB->L_tmp_n[localB->r1 + 10] *
        localB->L[localB->r2 + 10];
      localB->L_tmp_c[localB->rtemp] += localB->L_tmp_n[localB->r1 + 20] *
        localB->L[localB->r2 + 20];
    }
  }

  for (localB->r1 = 0; localB->r1 < 100; localB->r1++) {
    localB->L_tmp[localB->r1] = (localB->L_tmp_k[localB->r1] - localB->
      L_tmp_c[localB->r1]) + localB->Qk[localB->r1];
  }

  // Gain: '<S22>/u_scale'
  rtyy_LongitudinalaccelerationSt[0] = localP->u_scale_Gain[0] *
    localDW->last_mv_DSTATE[0];
  rtyy_LongitudinalaccelerationSt[1] = localP->u_scale_Gain[1] *
    localDW->last_mv_DSTATE[1];

  // Assertion: '<S16>/Assertion' incorporates:
  //   Constant: '<S16>/min_val'
  //   RelationalOperator: '<S16>/min_relop'

  utAssert(localP->Longitudinalvelocitymustbeposit < rtu_Longitudinalvelocity);

  // MATLAB Function: '<S50>/FixedHorizonOptimizer'
  localB->maxval = localDW->last_mv_DSTATE[0] - localB->b_uoff[0];
  localB->y = localDW->last_mv_DSTATE[1] - localB->b_uoff[1];
  for (localB->r1 = 0; localB->r1 < 10; localB->r1++) {
    // MATLAB Function: '<S50>/FixedHorizonOptimizer'
    localB->b_A_d[localB->r1] = 0.0F;
    for (localB->r2 = 0; localB->r2 < 10; localB->r2++) {
      // MATLAB Function: '<S50>/FixedHorizonOptimizer'
      localB->Coef = 10 * localB->r1 + localB->r2;
      localB->rtemp = 10 * localB->r2 + localB->r1;

      // Update for Memory: '<S22>/LastPcov' incorporates:
      //   MATLAB Function: '<S50>/FixedHorizonOptimizer'

      localDW->LastPcov_PreviousInput[localB->Coef] = (localB->L_tmp
        [localB->Coef] + localB->L_tmp[localB->rtemp]) * 0.5F;

      // MATLAB Function: '<S50>/FixedHorizonOptimizer'
      localB->b_A_d[localB->r1] += localB->b_A[localB->rtemp] * localB->
        xk[localB->r2];
    }

    // Update for Memory: '<S22>/last_x' incorporates:
    //   MATLAB Function: '<S50>/FixedHorizonOptimizer'

    localDW->last_x_PreviousInput[localB->r1] = (((localB->Bv[localB->r1 + 10] *
      localB->rtb_b2_tmp + localB->Bv[localB->r1] * localB->utau) +
      (localB->b_A_d[localB->r1] + (localB->Bu[localB->r1 + 10] * localB->y +
      localB->Bu[localB->r1] * localB->maxval))) + (localB->L[localB->r1 + 20] *
      localB->y_innov[2] + (localB->L[localB->r1 + 10] * localB->y_innov[1] +
      localB->L[localB->r1] * localB->y_innov[0]))) + localB->b_xoff[localB->r1];
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
