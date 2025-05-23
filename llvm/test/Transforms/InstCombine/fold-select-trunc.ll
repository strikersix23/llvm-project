; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt < %s -passes=instcombine -S | FileCheck %s

define i8 @fold_select_trunc_nuw_true(i8 %x, i8 %y) {
; CHECK-LABEL: @fold_select_trunc_nuw_true(
; CHECK-NEXT:    [[TRUNC:%.*]] = trunc nuw i8 [[X:%.*]] to i1
; CHECK-NEXT:    [[RET:%.*]] = select i1 [[TRUNC]], i8 1, i8 [[Y:%.*]]
; CHECK-NEXT:    ret i8 [[RET]]
;
  %trunc = trunc nuw i8 %x to i1
  %ret = select i1 %trunc, i8 %x, i8 %y
  ret i8 %ret
}

define i8 @fold_select_trunc_nuw_false(i8 %x, i8 %y) {
; CHECK-LABEL: @fold_select_trunc_nuw_false(
; CHECK-NEXT:    [[TRUNC:%.*]] = trunc nuw i8 [[X:%.*]] to i1
; CHECK-NEXT:    [[RET:%.*]] = select i1 [[TRUNC]], i8 [[Y:%.*]], i8 0
; CHECK-NEXT:    ret i8 [[RET]]
;
  %trunc = trunc nuw i8 %x to i1
  %ret = select i1 %trunc, i8 %y, i8 %x
  ret i8 %ret
}

define i128 @fold_select_trunc_nsw_true(i128 %x, i128 %y) {
; CHECK-LABEL: @fold_select_trunc_nsw_true(
; CHECK-NEXT:    [[TRUNC:%.*]] = trunc nsw i128 [[X:%.*]] to i1
; CHECK-NEXT:    [[RET:%.*]] = select i1 [[TRUNC]], i128 -1, i128 [[Y:%.*]]
; CHECK-NEXT:    ret i128 [[RET]]
;
  %trunc = trunc nsw i128 %x to i1
  %ret = select i1 %trunc, i128 %x, i128 %y
  ret i128 %ret
}

define i8 @fold_select_trunc_nsw_false(i8 %x, i8 %y) {
; CHECK-LABEL: @fold_select_trunc_nsw_false(
; CHECK-NEXT:    [[TRUNC:%.*]] = trunc nsw i8 [[X:%.*]] to i1
; CHECK-NEXT:    [[RET:%.*]] = select i1 [[TRUNC]], i8 [[Y:%.*]], i8 0
; CHECK-NEXT:    ret i8 [[RET]]
;
  %trunc = trunc nsw i8 %x to i1
  %ret = select i1 %trunc, i8 %y, i8 %x
  ret i8 %ret
}

define i8 @fold_select_trunc_negative(i8 %x, i8 %y) {
; CHECK-LABEL: @fold_select_trunc_negative(
; CHECK-NEXT:    [[TRUNC:%.*]] = trunc i8 [[X:%.*]] to i1
; CHECK-NEXT:    [[RET:%.*]] = select i1 [[TRUNC]], i8 [[X]], i8 [[Y:%.*]]
; CHECK-NEXT:    ret i8 [[RET]]
;
  %trunc = trunc i8 %x to i1
  %ret = select i1 %trunc, i8 %x, i8 %y
  ret i8 %ret
}

define <2 x i8> @fold_select_trunc_vector(<2 x i8> %x, <2 x i8> %y) {
; CHECK-LABEL: @fold_select_trunc_vector(
; CHECK-NEXT:    [[TRUNC:%.*]] = trunc nuw <2 x i8> [[X:%.*]] to <2 x i1>
; CHECK-NEXT:    [[RET:%.*]] = select <2 x i1> [[TRUNC]], <2 x i8> splat (i8 1), <2 x i8> [[Y:%.*]]
; CHECK-NEXT:    ret <2 x i8> [[RET]]
;
  %trunc = trunc nuw <2 x i8> %x to <2 x i1>
  %ret = select <2 x i1> %trunc, <2 x i8> %x, <2 x i8> %y
  ret <2 x i8> %ret
}
