// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py UTC_ARGS: --version 2
// REQUIRES: riscv-registered-target
// RUN: %clang_cc1 -triple riscv64 -target-feature +v -target-feature +zfh \
// RUN:   -target-feature +zvfhmin -disable-O0-optnone  \
// RUN:   -emit-llvm %s -o - | opt -S -passes=mem2reg | \
// RUN:   FileCheck --check-prefix=CHECK-RV64 %s

#include <riscv_vector.h>

// CHECK-RV64-LABEL: define dso_local <vscale x 4 x i64> @test_vget_v_u64m4x2_u64m4
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[SRC:%.*]]) #[[ATTR0:[0-9]+]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call <vscale x 4 x i64> @llvm.riscv.tuple.extract.nxv4i64.triscv.vector.tuple_nxv32i8_2t(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[SRC]], i32 1)
// CHECK-RV64-NEXT:    ret <vscale x 4 x i64> [[TMP0]]
//
vuint64m4_t test_vget_v_u64m4x2_u64m4(vuint64m4x2_t src) {
  return __riscv_vget_v_u64m4x2_u64m4(src, 1);
}

// CHECK-RV64-LABEL: define dso_local target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @test_vset_v_u64m4_u64m4x2
// CHECK-RV64-SAME: (target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[DEST:%.*]], <vscale x 4 x i64> [[VAL:%.*]]) #[[ATTR0]] {
// CHECK-RV64-NEXT:  entry:
// CHECK-RV64-NEXT:    [[TMP0:%.*]] = call target("riscv.vector.tuple", <vscale x 32 x i8>, 2) @llvm.riscv.tuple.insert.triscv.vector.tuple_nxv32i8_2t.nxv4i64(target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[DEST]], <vscale x 4 x i64> [[VAL]], i32 1)
// CHECK-RV64-NEXT:    ret target("riscv.vector.tuple", <vscale x 32 x i8>, 2) [[TMP0]]
//
vuint64m4x2_t test_vset_v_u64m4_u64m4x2(vuint64m4x2_t dest, vuint64m4_t val) {
  return __riscv_vset_v_u64m4_u64m4x2(dest, 1, val);
}
