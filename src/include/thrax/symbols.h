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
// Builds the symbol tables needed for byte and utf8 if FLAGS_save_symbols is
// set

#ifndef THRAX_SYMBOLS_H_
#define THRAX_SYMBOLS_H_

#include <memory>
#include <string>

#include <fst/symbol-table.h>

namespace thrax {
namespace function {

const ::fst::SymbolTable* GetByteSymbolTable();
const ::fst::SymbolTable* GetUtf8SymbolTable();

void AddToByteSymbolTable(std::string symbol, int64 label);
void AddToUtf8SymbolTable(std::string symbol, int64 label);

static const char kByteSymbolTableName[] = "**Byte symbols";
static const char kUtf8SymbolTableName[] = "**UTF8 symbols";

class SymbolTableBuilder {
 public:
  SymbolTableBuilder();

  const ::fst::SymbolTable* GetByteSymbolTable();
  const ::fst::SymbolTable* GetUtf8SymbolTable();

  void AddToByteSymbolTable(std::string symbol, int64 label);

  void AddToUtf8SymbolTable(std::string symbol, int64 label);

 private:
  void GenerateByteSymbolTable();

  inline void GenerateUtf8SymbolTable();

  ::fst::Mutex map_mutex_;
  std::unique_ptr<::fst::SymbolTable> byte_symbols_;
  std::unique_ptr<::fst::SymbolTable> utf8_symbols_;
};

}  // namespace function
}  // namespace thrax

#endif  // THRAX_SYMBOLS_H_
