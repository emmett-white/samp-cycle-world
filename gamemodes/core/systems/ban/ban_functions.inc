#if defined _inc_ban_functions
    #undef _inc_ban_functions
#endif
// custom include-guard to ensure we don't duplicate
#if defined _ban_functions_included
    #endinput
#endif
#define _ban_functions_included

/**
  * Functions
 */
stock CheckPlayerBanStatus(const playerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM banned WHERE banned_name = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    if (!cache_num_rows()) {
        CheckPlayerAccount(playerid);
        return 1;
    }

    static
        banned_admin[MAX_PLAYER_NAME],
        banned_reason[64];
    
    cache_get_value_name(0, "banned_admin", banned_admin);
    cache_get_value_name(0, "banned_reason", banned_reason);

    Dialog_Show(playerid, "DIALOG_BANNED", DIALOG_STYLE_MSGBOX,
        "Ban", ""WHITE"%s, banovani ste sa servera zbog %s\n\t\t"RED"Admin: "WHITE"%s",
        "X", "", ReturnPlayerName(playerid), banned_reason, banned_admin
    );

    return 1;
}

timer BAN_TIMER[2000](playerid) { Ban(playerid); }
stock Ban_Player(const targetid, const adminid, const string: reason[] = "N/A")
{
    if (targetid == adminid) {
        SendClientMessage(adminid, X11_RED, "* "WHITE"Ne mozete banovati sami sebe...");
        return 1;
    }

    va_SendClientMessageToAll(X11_RED,
        "* Ban: "WHITE"%s je banovan od strane %s zbog: %s",
        ReturnPlayerName(targetid), ReturnPlayerName(adminid), string: reason
    );

    new String: str_query_update = String: str_format(
        "INSERT INTO \
        banned (`banned_name`, `banned_admin`, `banned_reason`) \
        VALUES ('%e', '%e', '%e')",
        ReturnPlayerName(targetid), ReturnPlayerName(adminid), string: reason
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    GameTextForPlayer(targetid, "~r~BANNED", 10000, 3);
    defer BAN_TIMER(targetid);

    return 1;
}

stock Ban_Remove(const string: name[], const adminid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM banned WHERE banned_name = '%e'", name
            )
        )
    );

    if (!cache_num_rows()) {
        SendClientMessage(adminid, X11_RED, "* "WHITE"Taj igrac nije banovan.");
        return 1;
    }

    va_SendClientMessageToAll(X11_RED, 
        "* Un-Ban: "WHITE"Igrac %s je unbanovan od strane %s.",
        name, ReturnPlayerName(adminid)
    );

    new String: str_query_delete = String: str_format(
        "DELETE FROM banned WHERE banned_name = '%e'", name
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_delete);

    return 1;
}