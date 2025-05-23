add_clang_unittest(ToolingTests
  ASTSelectionTest.cpp
  CastExprTest.cpp
  CommentHandlerTest.cpp
  CompilationDatabaseTest.cpp
  DiagnosticsYamlTest.cpp
  ExecutionTest.cpp
  FixItTest.cpp
  HeaderAnalysisTest.cpp
  HeaderIncludesTest.cpp
  StandardLibraryTest.cpp
  LexicallyOrderedRecursiveASTVisitorTest.cpp
  LookupTest.cpp
  QualTypeNamesTest.cpp
  RangeSelectorTest.cpp
  DependencyScanning/DependencyScannerTest.cpp
  DependencyScanning/DependencyScanningFilesystemTest.cpp
  RecursiveASTVisitorTests/Attr.cpp
  RecursiveASTVisitorTests/BitfieldInitializer.cpp
  RecursiveASTVisitorTests/CallbacksLeaf.cpp
  RecursiveASTVisitorTests/CallbacksUnaryOperator.cpp
  RecursiveASTVisitorTests/CallbacksBinaryOperator.cpp
  RecursiveASTVisitorTests/CallbacksCompoundAssignOperator.cpp
  RecursiveASTVisitorTests/CallbacksCallExpr.cpp
  RecursiveASTVisitorTests/Class.cpp
  RecursiveASTVisitorTests/Concept.cpp
  RecursiveASTVisitorTests/ConstructExpr.cpp
  RecursiveASTVisitorTests/CXXBoolLiteralExpr.cpp
  RecursiveASTVisitorTests/CXXMemberCall.cpp
  RecursiveASTVisitorTests/CXXMethodDecl.cpp
  RecursiveASTVisitorTests/CXXOperatorCallExprTraverser.cpp
  RecursiveASTVisitorTests/DeclRefExpr.cpp
  RecursiveASTVisitorTests/DeductionGuide.cpp
  RecursiveASTVisitorTests/ImplicitCtor.cpp
  RecursiveASTVisitorTests/ImplicitCtorInitializer.cpp
  RecursiveASTVisitorTests/InitListExprPostOrder.cpp
  RecursiveASTVisitorTests/InitListExprPostOrderNoQueue.cpp
  RecursiveASTVisitorTests/InitListExprPreOrder.cpp
  RecursiveASTVisitorTests/InitListExprPreOrderNoQueue.cpp
  RecursiveASTVisitorTests/IntegerLiteral.cpp
  RecursiveASTVisitorTests/LambdaDefaultCapture.cpp
  RecursiveASTVisitorTests/LambdaExpr.cpp
  RecursiveASTVisitorTests/LambdaTemplateParams.cpp
  RecursiveASTVisitorTests/MemberPointerTypeLoc.cpp
  RecursiveASTVisitorTests/NestedNameSpecifiers.cpp
  RecursiveASTVisitorTests/ParenExpr.cpp
  RecursiveASTVisitorTests/TemplateArgumentLocTraverser.cpp
  RecursiveASTVisitorTests/TraversalScope.cpp
  RecursiveASTVisitorTestDeclVisitor.cpp
  RecursiveASTVisitorTestPostOrderVisitor.cpp
  RecursiveASTVisitorTestTypeLocVisitor.cpp
  RefactoringActionRulesTest.cpp
  RefactoringCallbacksTest.cpp
  RefactoringTest.cpp
  ReplacementsYamlTest.cpp
  RewriterTest.cpp
  SourceCodeBuildersTest.cpp
  SourceCodeTest.cpp
  StencilTest.cpp
  ToolingTest.cpp
  TransformerTest.cpp

  CLANG_LIBS
  clangAST
  clangASTMatchers
  clangBasic
  clangDependencyScanning
  clangDriver
  clangFormat
  clangFrontend
  clangLex
  clangRewrite
  clangSerialization
  clangTooling
  clangToolingCore
  clangToolingInclusions
  clangToolingInclusionsStdlib
  clangToolingRefactoring
  clangTransformer

  LINK_LIBS
  LLVMTestingAnnotations
  LLVMTestingSupport
  clangTesting

  LLVM_COMPONENTS
  ${LLVM_TARGETS_TO_BUILD}
  MC
  Option
  FrontendOpenMP
  Support
  TargetParser
  )

add_subdirectory(Syntax)
