#pragma once

#include "mull/Filters/FunctionFilter.h"
#include "mull/Filters/InstructionFilter.h"
#include "mull/Filters/MutationFilter.h"

#include <llvm/Support/Regex.h>
#include <mutex>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>

namespace mull {
struct SourceLocation;

class FilePathFilter : public MutationFilter, public FunctionFilter, public InstructionFilter {
public:
  bool shouldSkip(MutationPoint *point) override;
  bool shouldSkip(llvm::Function *function) override;
  bool shouldSkip(llvm::Instruction *instruction) const override;
  bool shouldSkip(const std::string &sourceFilePath) const;

  std::string name() override;
  std::pair<bool, std::string> exclude(const std::string &filter);
  std::pair<bool, std::string> include(const std::string &filter);

private:
  bool shouldSkip(const mull::SourceLocation &location) const;

  mutable std::vector<llvm::Regex> includeFilters;
  mutable std::vector<llvm::Regex> excludeFilters;

  mutable std::unordered_map<std::string, bool> cache;
  mutable std::mutex cacheMutex;
};
} // namespace mull
