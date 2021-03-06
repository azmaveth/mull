#include "mull/TestFrameworks/CppUTest/CppUTestFinder.h"
#include "FixturePaths.h"
#include "TestModuleFactory.h"
#include "mull/BitcodeLoader.h"
#include "mull/Config/Configuration.h"
#include "mull/Driver.h"
#include "mull/MutationsFinder.h"
#include "mull/Mutators/MutatorsFactory.h"
#include "mull/Program/Program.h"
#include "mull/TestFrameworks/NativeTestRunner.h"
#include "mull/Toolchain/JITEngine.h"
#include "mull/Toolchain/Toolchain.h"

#include <llvm/IR/CallSite.h>
#include <llvm/IR/InstrTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Support/YAMLTraits.h>

#include <gtest/gtest.h>
#include <mull/Diagnostics/Diagnostics.h>

using namespace mull;
using namespace llvm;

#pragma mark - Finding Tests

TEST(CppUTestFinder, FindTest) {
  Diagnostics diagnostics;
  LLVMContext context;
  BitcodeLoader loader;
  auto bitcodeWithTests = loader.loadBitcodeAtPath(
      fixtures::cpputest_test_cpputest_test_Test_bc_path(), context, diagnostics);

  std::vector<std::unique_ptr<Bitcode>> bitcode;
  bitcode.push_back(std::move(bitcodeWithTests));
  Program program({}, {}, std::move(bitcode));

  CppUTestFinder finder;

  auto tests = finder.findTests(program);

  ASSERT_EQ(2U, tests.size());

  ASSERT_EQ("HelloTest.testSumOfTestee", tests[0].getTestName());
  ASSERT_EQ("HelloTest.testSumOfTestee2", tests[1].getTestName());
}

