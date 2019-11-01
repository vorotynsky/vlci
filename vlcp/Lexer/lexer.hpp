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

#include <iostream>
#include <istream>
#include <iterator>
#include <map>

#include "tokens.hpp"

class Lexer
{
private:
    std::istream &input;
    Token cur_token;

    const std::map<char, Token> charToken = 
    {
        { '(' ,  Token(Token::LEFT_BRAKET)  },
        { ')' ,  Token(Token::RIGHT_BRAKET) },
        { '\\',  Token(Token::LAMBDA)       },
        { '.' ,  Token(Token::DOT)          },
        { '\0',  Token(Token::EoF)          },
        { '\n',  Token(Token::LF)           }
    };

    void readName(std::string &str);
    Token makeToken();
    bool whiteSpaces();
    char moveChar();
public:
    Lexer(std::istream &is);

    void moveNext();
    Token current();
};
