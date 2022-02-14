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
#ifndef state_globals_H_
#define state_globals_H_ 1

#include <iostream>
#include <stack>
#include <list>

enum state 
{
	PROG_RUNNING,
	PROG_EXITING,
	PROG_PARSING,
    PROG_EVALUATING,
	PROG_ERROR
};

struct core_state
{
	bool   running;
	state  program_state;
	int    number_stack_size;
	int    operator_stack_size;
};

std::list<std::string> parse_expression(std::string expression, core_state &c_state);

#endif