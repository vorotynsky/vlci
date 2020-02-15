// Vorotynsky's lambda calculus interpreter
// Copyright (C) 2019-2020  Vorotynsky Maxim

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

/**
 * @file vlcp.h
 * @brief header file of lambda processor
 * @author Vorotynsky Maxim
 * @date 2019
 * @copyright GNU General Public License
 */

#pragma once

#include "Lexer/tokens.hpp"
#include "Lexer/lexer.hpp"

// Abstract syntax tree
#include "AST/lambda.hpp"
#include "AST/variable.hpp"
#include "AST/application.hpp"
#include "AST/abstraction.hpp"

// Parser
#include "Parser/parsedTree.hpp"
#include "Parser/ruleParser.hpp"
#include "Parser/Rules/rule.hpp"
