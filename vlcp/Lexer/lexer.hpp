// Vorotynsky's lambda calculus interpreter
// Copyright (C) 2019  Vorotynsky Maxim
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <istream>
#include <string>
#include <map>

#include "tokens.hpp"

/**
 * @brief A Lexer transforms an input to a Token sequence.
 */
class Lexer
{
private:
    std::istream &input;
    Token cur_token;
    std::size_t possition = 0;

    static const std::map<char, Token> charToken;

    void readName(std::string &str);
    Token makeToken();
    bool whiteSpaces();
    char moveChar();
public:
    /**
     * @brief Creates a new Lexer instance based on the input stream.
     * 
     * @param[in] is A input stream.
     */
    Lexer(std::istream &is);

    /**
     * @brief Read the next Token from the stream.
     */
    void moveNext();

    /**
     * @brief Returns the token that was read from the stream.
     * 
     * @note In case the function Lexer::moveNext() wasn't called, the current token has an `EMPTY` type.
     * 
     * @return Token The read token.
     */
    Token current();

    /**
     * @brief Returns the possition of the lexer.
     * 
     * @return long the possition in tokens.
     */
    std::size_t getPossition();
};
