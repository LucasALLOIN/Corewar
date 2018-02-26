/*
** EPITECH PROJECT, 2017
** instruction.c
** File description:
** instructions utils functions
*/

#include "corewar.h"
#include "mem_manage.h"

/*
** check_valid: 
** check if the args is valide for the actual instructions.
**
** int *args: args given to the instructions.
** int one, two, th : args that the instructions need.
*/
int check_valid(int *args, int one, int two, int thr)
{
	return ((((!one && !args[0]) || args[0] & one) &&
	         ((!two && !args[1]) || args[1] & two) &&
	         ((!thr && !args[2]) || args[2] & thr)));
}

/*
**
** get_mem:
** get_the right mem value
** 	
**
**
*/
int get_mem(process_t *process, core_t *core, int type, int *last)
{
	int val = -1;

	if (type == T_REG && core->memory[ADRESS(*last)] > 0 && \
	    core->memory[ADRESS(*last)] <= 16) {
		val = core->memory[ADRESS(*last)] - 1;
		*last += 1;	 
	} else if (type == T_DIR) {
		val = uchar_to_int(core, *last);
		*last += 4;
	} else if (type == T_IND) {
		val = uchar_to_int(core, process->pc + \
		      uchar_to_short(core, *last) % IDX_MOD);
		*last += 2;
	}
	return (val);
}

/*
**
** lget_mem:
** get_the right mem value without IDX_MOD
** 	
**
**
*/
int lget_mem(process_t *process, core_t *core, int type, int *last)
{
	int value = -1;

	if (type == T_REG && core->memory[ADRESS(*last)] > 0 && \
	    core->memory[ADRESS(*last)] <= 16) {
		value = core->memory[ADRESS(*last)] - 1;
		*last += 1;	 
	} else if (type == T_DIR) {
		value = uchar_to_int(core, *last);
		*last += 4;
	} else if (type == T_IND) {
		value = uchar_to_int(core,
		 	process->pc + uchar_to_short(core, *last));
		*last += 2;
	}
	return (value);
}
