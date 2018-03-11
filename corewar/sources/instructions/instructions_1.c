/*
** EPITECH PROJECT, 2017
** instructions_1.c
** File description:
** instructions with 1 parameter
*/

#include "corewar.h"
#include "instructions.h"
#include "my_printf.h"
#include "mem_manage.h"
#include "utils.h"
#include "unistd.h"

/*
**
** [1]  [2]  [3]
** ---  ---  ---
**
** Say who's is alive
*/
int instruction_live(core_t *core, process_t *process, UNUSED int *args)
{
	int adress = ADRESS(process->pc + 1);

	for (int i = 0; i < core->nb_progs; i++)
		if (core->program_tab[i].number == uchar_to_int(core, adress)) {
			core->program_tab[i].last_live_cycle = core->nbr_cycle;
			my_printf("The player %d(%s) is alive.\n"
				, core->program_tab[i].number, \
				core->program_tab[i].header.prog_name);
		}
	core->nb_live += 1;
	process->pc += 5;
	return (1);
}

/*
**
** [1]  [2]  [3]
** I    ---  ---
**
** PC += [ [ 1 ] % IDX_MOD ]
*/
int instruction_zjmp(core_t *core, process_t *process, UNUSED int *args)
{
	int adress = ADRESS(process->pc + 1);

	if (!process->carry)
		return (0);
	process->pc += (uchar_to_short(core, adress) % IDX_MOD);
	return (1);
}

/*
**
** [1]  [2]  [3]
**  D   ---  ---
**
** Create new process and set pc at [PC + [ 1 ]] % IDX_MOD
*/
int instruction_fork(core_t *core, process_t *process, UNUSED int *args)
{
	int newpc;
	int newid = get_next_process_id(core);

	newpc = process->pc + \
	(uchar_to_short(core, ADRESS(process->pc + 1)) % IDX_MOD);
	dup_process(process, newpc, newid);
	process->pc += 3;
	return (1);
}

/*
**
** [1]  [2]  [3]
**  D   ---  ---
**
** Create new process and set pc at [PC + [ 1 ]]
*/
int instruction_lfork(core_t *core, process_t *process, UNUSED int *args)
{
	int newpc;
	int newid = get_next_process_id(core);

	newpc = process->pc + \
	(uchar_to_short(core, ADRESS(process->pc + 1)));
	dup_process(process, newpc, newid);
	process->pc += 3;
	return (1);
}

/*
**
** [1]  [2]  [3]
**  R   ---  ---
**
** Dispay [registers[1] % 256]
*/
int instruction_aff(core_t *core, process_t *process, UNUSED int *args)
{
	int reg = 0;
	int c;
	int character;

	if (!check_valid(args, T_REG, 0, 0)) {
		process->pc += 3;
		return (0);
	}
	reg = uchar_to_int(core, ADRESS(process->pc + 2));
	c = reg_to_int(process->registers[reg]) % 256;
	character = (char) c;
	write(1, &character, 1);
	process->pc += 3;
	return (1);
}
