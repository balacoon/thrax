// Copyright 2005-2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// A function is a repeatable set of assignments and commands used to build a
// new FST from inputs. This node contains the name of the function along with
// the bound argument names and the body statements.

#ifndef THRAX_FUNCTION_NODE_H_
#define THRAX_FUNCTION_NODE_H_

#include <fst/compat.h>
#include <thrax/compat/compat.h>
#include <thrax/node.h>

namespace thrax {

class AstWalker;
class CollectionNode;
class IdentifierNode;

class FunctionNode : public Node {
 public:
  FunctionNode(IdentifierNode* name,
               CollectionNode* arguments,
               CollectionNode* body);

  ~FunctionNode() override;

  IdentifierNode* GetName() const;

  CollectionNode* GetArguments() const;

  CollectionNode* GetBody() const;

  void Accept(AstWalker* walker) override;

 private:
  IdentifierNode* name_;
  CollectionNode* arguments_;
  CollectionNode* body_;

  FunctionNode(const FunctionNode&) = delete;
  FunctionNode& operator=(const FunctionNode&) = delete;
};

}  // namespace thrax

#endif  // THRAX_FUNCTION_NODE_H_
