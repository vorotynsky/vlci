// Vorotynsky's lambda calculus interpreter
// Copyright (C) 2019  Vorotynsky Maxim

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

#include "tokens.hpp"

Token::Token(Token::TokenType type) 
{
	this->type = type;
}

Token Token::leftBraket()
{
	return Token(LEFT_BRAKET);
}

Token Token::rightBraket()
{
	return Token(RIGHT_BRAKET);
}

Token Token::lambda()
{
	return Token(LAMBDA);
}

Token Token::dot()
{
	return Token(DOT);
}

Token Token::name(std::string& name)
{
	Token token(NAME);
	token.tname = name;
	return token;
}

Token::TokenType Token::getType()
{
	return this->type;
}

const std::string& Token::getName()
{
	return this->tname;
}

bool Token::operator==(const Token &other)
{
	if (other.type != type)
		return false;
	if (other.type != NAME)
		return false;
	return other.name == name;
}

bool Token::operator!=(const Token &other)
{
	return !this->operator==(other);
}
