
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

// Resets the program state structure to default values, this
// could be used on a reset or begining of program execution.
void reset_default_state(core_state &c_state) {
	c_state.running = true;
	c_state.program_state = PROG_RUNNING;
	c_state.number_stack_size = 0;
	c_state.operator_stack_size = 0;
}

int main(int argc, char*argv[])
{
	std::string exp;
	struct core_state core_prog_state;

	reset_default_state(core_prog_state);

	// Display program banner

	while(true) {
		std::cout << "| ";
		getline(std::cin, exp);

		if(exp == "quit") {
			std::cout << "Goodbye!" << std::endl;	
			return EXIT_SUCCESS;
		} else {
			parse_expression(exp, core_prog_state);
		}
	}

	return EXIT_SUCCESS;
}

