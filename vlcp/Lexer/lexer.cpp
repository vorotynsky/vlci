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
    : input (is), cur_token(Token::dot()) // TODO: make empty token
{
    moveNext();
}

char Lexer::peekChar() 
{
    int c = input.peek();

    while (std::isspace(c) && c != EOF)  //TODO: LINE FEED
    {
        input.get();
        c = input.peek();
    }
    if (c == EOF)
        return '\0';
    return c;
}

char Lexer::moveChar() {
    return input.get();
}

void Lexer::moveNext() 
{
    if (peekChar() == '\0')
        return; // TODO: catch eof, lf

    bool movechar = true;
    switch (peekChar())
    {
    case '(':
        cur_token = Token::leftBraket();
        break;
    case ')':
        cur_token = Token::rightBraket();
        break;
    case '.':
        cur_token = Token::dot();
        break;
    case '\\':
        cur_token = Token::lambda();
        break;
    default: // identificator
        std::string str;
        input >> str; // reading word
        movechar = false;
        cur_token = Token::name(str);
    }

    if (movechar)
        moveChar();
}
