/*****************************************************************************
 * linrpn -- a reverse polish notation evaluator
 * (C) Copyright 2022 Travis Montoya
  *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see http://www.gnu.org/licenses/.
 *****************************************************************************/
#include "state_globals.h"

class Tokenizer {
    private:
        std::string exp;
        int cpos;
    public:
        Tokenizer(std::string exp) {
            this->exp = exp;
            this->cpos = 0;
        }
        ~Tokenizer() {}

        bool validExpression();
        bool nextToken(int *cpos, std::string exp);
        std::list<std::string> tokenizeString();
};

// Receives a list of a tokenized expression from the Tokenizer
class Evaluator {
    private:
        std::stack<int> number_stack;
        std::stack<std::string> operator_stack;

        std::list<std::string> exp;
    public:
        Evaluator(std::list<std::string> &exp) {
            this->exp = exp;
        }
        ~Evaluator() {}

        void addToStack(std::string val) {
            if (!val.empty()) {
                operator_stack.push(val);
            }
        }

        void addToStack(int val) {
            number_stack.push(val);
        }

        std::string getNextOperator() {
            std::string val = nullptr;
            if(!operator_stack.empty()) {
                val = operator_stack.top();
                operator_stack.pop();
            }
            return val;
        }

        int getNextNumber() {
            int val = (int)number_stack.top();
            number_stack.pop();
            return val;
        }
};


bool Tokenizer::validExpression() {
    return false;
}

std::list<std::string> Tokenizer::tokenizeString() {
    return std::list<std::string>();
}

std::list<std::string> parse_expression(std::string expression, core_state &c_state) {
    c_state.program_state = PROG_PARSING;

    Tokenizer tokenizer(expression);

    if(!tokenizer.validExpression()) {
        return std::list<std::string>();
    }

    std::list<std::string> exp_tokenized = tokenizer.tokenizeString();
    if(exp_tokenized.empty()) {
        return std::list<std::string>();
    }

	return exp_tokenized;
}


