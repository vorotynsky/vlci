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

#include "lexer.hpp"

Lexer::Lexer(std::istream &is)
    : input (is), cur_token()
{ }

bool Lexer::whiteSpaces() 
{
    int c = input.peek();
    bool result = false;

    while (std::isspace(c) && c != EOF && c != '\n')
    {
        input.get();
        c = input.peek();
        result = true;
    }
    return result;
}

char Lexer::moveChar() 
{
    whiteSpaces();
    int c = input.get();
    return (c == EOF) ? '\0' : c;
}

void Lexer::readName(std::string &str)
{
    str.clear();
    whiteSpaces();
    int c = input.get();
    while (std::isalnum(c))
    {
        str.push_back(c);
        c = input.get();
    }
    input.putback(c);
}

Token Lexer::makeToken() 
{
    whiteSpaces();
    char peekc;
    
    int c = input.peek();
    peekc = (c == EOF) ? '\0' : c;

    auto it = charToken.find(peekc);
    if (it != charToken.end()) 
    {
        moveChar();
        return it->second;
    }
    
    std::string name;
    readName(name);
    return Token(name);
}

void Lexer::moveNext() 
{
    cur_token = makeToken();
}

Token Lexer::current() {
    return this->cur_token;
}