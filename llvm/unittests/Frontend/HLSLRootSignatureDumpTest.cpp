//===-------- HLSLRootSignatureDumpTest.cpp - RootSignature dump tests ----===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "llvm/Frontend/HLSL/HLSLRootSignatureUtils.h"
#include "gtest/gtest.h"

using namespace llvm::hlsl::rootsig;

namespace {

TEST(HLSLRootSignatureTest, DescriptorCBVClauseDump) {
  DescriptorTableClause Clause;
  Clause.Type = ClauseType::CBuffer;
  Clause.Reg = {RegisterType::BReg, 0};
  Clause.setDefaultFlags();

  std::string Out;
  llvm::raw_string_ostream OS(Out);
  OS << Clause;
  OS.flush();

  std::string Expected = "CBV(b0, numDescriptors = 1, space = 0, "
                         "offset = DescriptorTableOffsetAppend, "
                         "flags = DataStaticWhileSetAtExecute)";
  EXPECT_EQ(Out, Expected);
}

TEST(HLSLRootSignatureTest, DescriptorSRVClauseDump) {
  DescriptorTableClause Clause;
  Clause.Type = ClauseType::SRV;
  Clause.Reg = {RegisterType::TReg, 0};
  Clause.NumDescriptors = 2;
  Clause.Space = 42;
  Clause.Offset = 3;
  Clause.Flags = DescriptorRangeFlags::None;

  std::string Out;
  llvm::raw_string_ostream OS(Out);
  OS << Clause;
  OS.flush();

  std::string Expected =
      "SRV(t0, numDescriptors = 2, space = 42, offset = 3, flags = None)";
  EXPECT_EQ(Out, Expected);
}

TEST(HLSLRootSignatureTest, DescriptorUAVClauseDump) {
  DescriptorTableClause Clause;
  Clause.Type = ClauseType::UAV;
  Clause.Reg = {RegisterType::UReg, 92374};
  Clause.NumDescriptors = 3298;
  Clause.Space = 932847;
  Clause.Offset = 1;
  Clause.Flags = DescriptorRangeFlags::ValidFlags;

  std::string Out;
  llvm::raw_string_ostream OS(Out);
  OS << Clause;
  OS.flush();

  std::string Expected =
      "UAV(u92374, numDescriptors = 3298, space = 932847, offset = 1, flags = "
      "DescriptorsVolatile | "
      "DataVolatile | "
      "DataStaticWhileSetAtExecute | "
      "DataStatic | "
      "DescriptorsStaticKeepingBufferBoundsChecks)";
  EXPECT_EQ(Out, Expected);
}

TEST(HLSLRootSignatureTest, DescriptorSamplerClauseDump) {
  DescriptorTableClause Clause;
  Clause.Type = ClauseType::Sampler;
  Clause.Reg = {RegisterType::SReg, 0};
  Clause.NumDescriptors = 2;
  Clause.Space = 42;
  Clause.Offset = DescriptorTableOffsetAppend;
  Clause.Flags = DescriptorRangeFlags::ValidSamplerFlags;

  std::string Out;
  llvm::raw_string_ostream OS(Out);
  OS << Clause;
  OS.flush();

  std::string Expected = "Sampler(s0, numDescriptors = 2, space = 42, offset = "
                         "DescriptorTableOffsetAppend, "
                         "flags = DescriptorsVolatile)";
  EXPECT_EQ(Out, Expected);
}

TEST(HLSLRootSignatureTest, DescriptorTableDump) {
  DescriptorTable Table;
  Table.NumClauses = 4;
  Table.Visibility = ShaderVisibility::Geometry;

  std::string Out;
  llvm::raw_string_ostream OS(Out);
  OS << Table;
  OS.flush();

  std::string Expected =
      "DescriptorTable(numClauses = 4, visibility = Geometry)";
  EXPECT_EQ(Out, Expected);
}

TEST(HLSLRootSignatureTest, DefaultRootConstantsDump) {
  RootConstants Constants;
  Constants.Num32BitConstants = 1;
  Constants.Reg = {RegisterType::BReg, 3};

  std::string Out;
  llvm::raw_string_ostream OS(Out);
  OS << Constants;
  OS.flush();

  std::string Expected = "RootConstants(num32BitConstants = 1, b3, space = 0, "
                         "visibility = All)";
  EXPECT_EQ(Out, Expected);
}

TEST(HLSLRootSignatureTest, SetRootConstantsDump) {
  RootConstants Constants;
  Constants.Num32BitConstants = 983;
  Constants.Reg = {RegisterType::BReg, 34593};
  Constants.Space = 7;
  Constants.Visibility = ShaderVisibility::Pixel;

  std::string Out;
  llvm::raw_string_ostream OS(Out);
  OS << Constants;
  OS.flush();

  std::string Expected = "RootConstants(num32BitConstants = 983, b34593, "
                         "space = 7, visibility = Pixel)";
  EXPECT_EQ(Out, Expected);
}

TEST(HLSLRootSignatureTest, NoneRootFlagsDump) {
  RootFlags Flags = RootFlags::None;

  std::string Out;
  llvm::raw_string_ostream OS(Out);
  OS << Flags;
  OS.flush();

  std::string Expected = "RootFlags(None)";
  EXPECT_EQ(Out, Expected);
}

TEST(HLSLRootSignatureTest, AllRootFlagsDump) {
  RootFlags Flags = RootFlags::ValidFlags;

  std::string Out;
  llvm::raw_string_ostream OS(Out);
  OS << Flags;
  OS.flush();

  std::string Expected = "RootFlags("
                         "AllowInputAssemblerInputLayout | "
                         "DenyVertexShaderRootAccess | "
                         "DenyHullShaderRootAccess | "
                         "DenyDomainShaderRootAccess | "
                         "DenyGeometryShaderRootAccess | "
                         "DenyPixelShaderRootAccess | "
                         "AllowStreamOutput | "
                         "LocalRootSignature | "
                         "DenyAmplificationShaderRootAccess | "
                         "DenyMeshShaderRootAccess | "
                         "CBVSRVUAVHeapDirectlyIndexed | "
                         "SamplerHeapDirectlyIndexed)";

  EXPECT_EQ(Out, Expected);
}

} // namespace
