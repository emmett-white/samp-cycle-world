#if defined _inc_acc_hooks
    #undef _inc_acc_hooks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _acc_hooks_included
    #endinput
#endif
#define _acc_hooks_included

#include <YSI_Coding\y_hooks>

/**
  * Hooks
 */
hook OnPlayerConnect(playerid)
{
	CheckPlayerBanStatus(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}