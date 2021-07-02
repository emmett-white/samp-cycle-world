#if defined _inc_admin_hooks
    #undef _inc_admin_hooks
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_hooks_included
    #endinput
#endif
#define _admin_hooks_included

#include <YSI_Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    Admin_Remove(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}