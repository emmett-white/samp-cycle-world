#if defined _inc_admin_functions
    #undef _inc_admin_functions
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_functions_included
    #endinput
#endif
#define _admin_functions_included

static
    admin_Level[MAX_PLAYERS],
    admin_Code[MAX_PLAYERS],

    Iterator: Iter_Admins<MAX_PLAYERS>;

/**
  * Get/Set functions
 */
stock Player_SetAdminLevel(const targetid, const playerid, const level, const code)
{
    if (!(0 <= level <= Admin_GetMaxLevel())) {
        return 0;
    }

    if (level == Admin_GetLevel(targetid)) {
        SendClientMessage(playerid, -1, "Taj igrac je vec taj admin level.");
        return 1;
    }

    if (!level) {
        va_SendClientMessage(playerid, -1, "Skinuli ste admina igracu %s(%d).", ReturnPlayerName(targetid), targetid);
        va_SendClientMessage(targetid, -1, "Admin %s(%d) Vam je postavio admina level %d.", ReturnPlayerName(playerid), playerid, level);

        admin_Level[targetid] = 0;
        admin_Code[targetid] = 0;

        Admin_SetLevel(targetid, level);
        Admin_SetCode(targetid, code);

        new String: str_query_ins = String: str_format(
            "UPDATE characters SET char_admin = '0', char_admincode = '0' WHERE char_name = '%e'",
            ReturnPlayerName(targetid)
        );
        mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_ins);

        return 1;
    }

    Admin_SetLevel(targetid, level);
    Admin_SetCode(targetid, code);

    va_SendClientMessage(playerid, -1, "Postavili ste admina level %d igracu %s(%d).", Admin_GetLevel(targetid), ReturnPlayerName(targetid), targetid);
    va_SendClientMessage(targetid, -1, "Admin %s(%d) Vam je postavio admina level %d. Kod: %d", ReturnPlayerName(playerid), playerid, Admin_GetLevel(targetid), Admin_GetCode(targetid));

    new String: str_query_ins = String: str_format(
        "UPDATE characters SET char_admin = '%d', char_admincode = '%d' WHERE char_name = '%e'",
        Admin_GetLevel(targetid), Admin_GetCode(targetid), ReturnPlayerName(targetid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_ins);

    return 1;
}

stock Admin_SetLevel(const playerid, const level)
{
    if (!level) {
        Admin_Remove(playerid);
        return 1;
    }

    Iter_Add(Iter_Admins, playerid);
    admin_Level[playerid] = level;

    return 1;
}

stock Admin_Remove(const playerid) 
{
    if (Iter_Contains(Iter_Admins, playerid)) {
        Iter_Remove(Iter_Admins, playerid);
    }

    return 1;
}

stock Admin_GetMaxLevel() return MAX_ADMIN_LEVEL;
stock Admin_SetCode(const playerid, const code) return admin_Code[playerid] = code;
stock Admin_GetLevel(const playerid) return admin_Level[playerid];
stock Admin_GetCode(const playerid) return admin_Code[playerid];

/**
  * Messages
 */
stock Admin_SendMessage(const adminid, const colour, const string: fmt[], va_args<>)
{
    if (!Admin_GetLevel(adminid)) {
        return 0;
    }

    SendClientMessage(adminid, colour, va_return(string: fmt, va_start<3>));
    
    return 1;
}

stock Admin_SendMessageToAll(const colour, const string: fmt[], va_args<>)
{
    foreach (new i: Iter_Admins) {
        SendClientMessage(i, colour, va_return(string: fmt, va_start<2>));
        return 1;
    }

    return 0;
}