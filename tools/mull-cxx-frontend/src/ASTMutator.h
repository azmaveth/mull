#pragma once

#include <clang/AST/Expr.h>

class BinaryMutator;
class RemoveVoidMutator;
class UnaryNotToNoopMutator;
class ASTMutation;

class ASTMutator {
public:
  virtual void performBinaryMutation(ASTMutation &mutation, BinaryMutator &binaryMutator) = 0;
  virtual void performRemoveVoidMutation(ASTMutation &mutation,
                                         RemoveVoidMutator &removeVoidMutator) = 0;
  virtual void performUnaryNotToNoopMutator(ASTMutation &mutation,
                                            UnaryNotToNoopMutator &unaryNotToNoopMutator) = 0;
  virtual ~ASTMutator() {}
};

class Mutator {
public:
  virtual void performMutation(ASTMutation &mutation, ASTMutator &mutator) = 0;
  virtual ~Mutator() {}
};

class BinaryMutator : public Mutator {
public:
  clang::BinaryOperator::Opcode replacementOpCode;

  BinaryMutator(clang::BinaryOperator::Opcode replacementOpCode)
      : replacementOpCode(replacementOpCode) {}
  void performMutation(ASTMutation &mutation, ASTMutator &mutator) {
    mutator.performBinaryMutation(mutation, *this);
  }
  ~BinaryMutator() {}
};

class RemoveVoidMutator : public Mutator {
public:
  void performMutation(ASTMutation &mutation, ASTMutator &mutator) {
    mutator.performRemoveVoidMutation(mutation, *this);
  }
  ~RemoveVoidMutator() {}
};

class UnaryNotToNoopMutator : public Mutator {
public:
  clang::UnaryOperator *unaryOperator;

  UnaryNotToNoopMutator(clang::UnaryOperator *unaryOperator) : unaryOperator(unaryOperator) {}
  void performMutation(ASTMutation &mutation, ASTMutator &mutator) {
    mutator.performUnaryNotToNoopMutator(mutation, *this);
  }
  ~UnaryNotToNoopMutator() {}
};
