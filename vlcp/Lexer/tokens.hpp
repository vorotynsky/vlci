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

#include <string>

/**
 * @brief A Token is a unit what can be obtained from the input.
 * 
 * From tokens, complex constructions are built.
 */
struct Token
{
    /// @brief Specifies the type of token.
    enum TokenType 
    {
        /**
         * @brief An empty token.
         * 
         * Can be created by Token(). 
         */
        EMPTY,

        LEFT_BRACKET,  ///< @brief A left bracket.
        RIGHT_BRACKET, ///< @brief A right bracket.
        LAMBDA,        ///< @brief A lambda.
        DOT,           ///< @brief A dot (point).

        /**
         * @brief A name-token.
         * 
         * Created by Token(std::string&).
         * To get value of token use Token::getName().
         */
        NAME,

        EoF, ///< @brief An end-of-file token.
        LF   ///< @brief A line feed token
    };

private:
    TokenType type;
    std::string tname;

public:
    /**
     * @brief Initializes a new empty instance of Token.
     */
    Token();

    /**
     * @brief Initializes a new instance of Token with the specified type.
     * 
     * This constructor creates only:
     *  - left and right brackets;
     *  - dot;
     *  - lambda;
     *  - eof and lf tokens.
     * 
     * @param[in] type A type parameter that can't be `NAME` or `EMPTY`.
     * 
     * @exception std::invalid_argument  the`type` parameter isn't supported by this constructor.
     */
    Token(TokenType type);

    /**
     * @brief Construct a new name-token object.
     * 
     * The constructor creates a new instance with the `NAME` type and the specified string in it.
     * 
     * @param[in] name the value of the new name-token.
     */
    Token(std::string &name);

    /**
     * @brief Gets the type of the token.
     */
    TokenType getType();

    /**
     * @brief Gets the value of the name-token.
     * 
     * @return const std::string& The content of the name-token or empty string if the token isn't a `NAME`.
     */
    const std::string& getName();

    /**
     * @brief Determines whether two tokens instances are equal.
     * 
     * @param[in] other The tokens to compare with the current tokens.
     * @return bool `true` if the specified tokens are equal to the current tokens; otherwise, `false`.
     */
    bool operator==(const Token &other) const;

    /**
     * @brief Determines whether two tokens instances are not equal.
     * 
     * @param[in] other The tokens to compare with the current tokens.
     * @return bool `false` if the specified tokens are equal to the current tokens; otherwise, `true`.
     */
    bool operator!=(const Token &other) const;
};
