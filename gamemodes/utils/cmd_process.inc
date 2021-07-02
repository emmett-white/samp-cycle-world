// By: Southclaws
// Edited by Emmett (dekszy) 01/05/21

#if defined _inc_cmd_process
    #undef _inc_cmd_process
#endif
// custom include-guard to ensure we don't duplicate
#if defined _cmd_process_included
    #endinput
#endif
#define _cmd_process_included

#if defined CMD
    #undef CMD
#endif

#define cmd::%1(%2) forward cmd_%1(%2); public cmd_%1(%2)
#define acmd::<%0>%1(%2,%3) cmd::%1(%2,%3) if (Admin_GetLevel(%2) < %0) return 0; else

public OnPlayerCommandText(playerid, cmdtext[])
{
	new
		cmd[30],
		params[127],
		cmdfunction[64],
		result = 1;

	sscanf(cmdtext, "s[30]s[127]", cmd, params);

	for (new i, j = strlen(cmd); i < j; i++) {
		cmd[i] = tolower(cmd[i]);
	}

	format(cmdfunction, 64, "cmd_%s", cmd[1]);

	if(funcidx(cmdfunction) == -1) {
		new
			iLvl = Admin_GetLevel(playerid),
			iLoop = 5;

		while(iLoop > 0) {
			format(cmdfunction, 64, "acmd_%s_%d", cmd[1], iLoop);

			if(funcidx(cmdfunction) != -1) {
				break;
			}

			iLoop--;
		}

		result = (!iLoop ? (0) : (iLvl < iLoop) ? (5) : (0));
	}

	if(result == 1) {
		if(isnull(params)) {
			result = CallLocalFunction(cmdfunction, "is", playerid, "\1");
		}

		else {
			result = CallLocalFunction(cmdfunction, "is", playerid, params);
		}
	}
	
	return 1;
}