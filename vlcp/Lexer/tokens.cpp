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

#include "tokens.hpp"
#include <stdexcept>

Token::Token() 
{
	this->tname = nullptr;
	this->type = EMPTY;
}

Token::Token(Token::TokenType type)
{
	if (type == NAME || type == EMPTY)
		throw std::invalid_argument("Invalid token type for this ctor. ");

	this->tname = nullptr;
	this->type = type;
}

Token::Token(std::string &name) 
{
	this->tname = new std::string(name);
	this->type = NAME;
}

Token::~Token()
{
	if (this->tname != nullptr)
		delete tname;
}

Token::TokenType Token::getType()
{
	return this->type;
}

const std::string& Token::getName()
{
	return *(this->tname);
}

bool Token::operator==(const Token &other)
{
	if (other.type != type)
		return false;
	if (other.type != NAME)
		return false;
	return other.tname == tname;
}

bool Token::operator!=(const Token &other)
{
	return !this->operator==(other);
}
