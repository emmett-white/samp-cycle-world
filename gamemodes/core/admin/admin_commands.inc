#if defined _inc_admin_commands
    #undef _inc_admin_commands
#endif
// custom include-guard to ensure we don't duplicate
#if defined _admin_commands_included
    #endinput
#endif
#define _admin_commands_included

acmd::<Admin_GetMaxLevel() && !IsPlayerAdmin(playerid)>setadmin(playerid, const string: params[])
{
    static
        targetid,
        level,
        code;
    
    if (sscanf(string: params, "rii", targetid, level, code)) {
        SendClientMessage(playerid, X11_YELLOW, "KORISTI: "WHITE"/setadmin [targetid] [level] [code]");
        return 1;
    }

    Player_SetAdminLevel(targetid, playerid, level, code);

    return 1;
}

acmd::<1>ban(playerid, const string: params[])
{
    static
        targetid,
        string: reason[MAX_REASON_LENGTH];
    
    if (sscanf(string: params, "rs["#MAX_REASON_LENGTH"]", targetid, string: reason)) {
        SendClientMessage(playerid, X11_YELLOW, "KORISTI: "WHITE"/ban [targetid] [reason]");
        return 1;
    }

    Ban_Player(targetid, playerid, string: reason);

    return 1;
}

acmd::<1>unban(playerid, const string: params[])
{
    if (isnull(string: params)) {
        SendClientMessage(playerid, X11_YELLOW, "KORISTI: "WHITE"/unban [account name]");
        return 1;
    }

    Ban_Remove(string: params, playerid);

    return 1;
}

acmd::<1>kick(playerid, const string: params[])
{
    static
        targetid,
        string: reason[MAX_REASON_LENGTH];
    
    if (sscanf(string: params, "rs["#MAX_REASON_LENGTH"]", targetid, string: reason)) {
        SendClientMessage(playerid, X11_YELLOW, "KORISTI: "WHITE"/kick [targetid] [reason]");
        return 1;
    }

    if (targetid == playerid) {
        return 0;
    }

    va_SendClientMessageToAll(X11_RED,
        "* Kick: "WHITE"%s je kikovan od strane %s zbog: %s",
        ReturnPlayerName(targetid), ReturnPlayerName(playerid), string: reason
    );

    GameTextForPlayer(targetid, "~r~KICKED!", 10000, 3);
    Kick(targetid);

    return 1;
}

static BitArray: PLAYER_FREEZED<MAX_PLAYERS>;
acmd::<1>freeze(playerid, const string: params[])
{
    if (isnull(string: params)) {
        SendClientMessage(playerid, X11_YELLOW, "KORISTI: "WHITE"/freeze [targetid]");
        return 1;
    }

    if (!IsPlayerConnected(strval(string: params))) {
        return 0;
    }

    if (strval(string: params) == playerid) {
        return 0;
    }

    if (Bit_Get(Bit: PLAYER_FREEZED, strval(string: params))) {
        SendClientMessage(playerid, -1, "Taj igrac je vec zaledjen.");
        return 1;
    }

    TogglePlayerControllable(strval(string: params), 0);
    Bit_Let(Bit: PLAYER_FREEZED, strval(string: params));

    va_SendClientMessageToAll(X11_RED,
        "* Freeze: "WHITE"Igrac %s je zaledjen od strane admina %s.",
        ReturnPlayerName(strval(string: params)), ReturnPlayerName(playerid)
    );

    return 1;
}

acmd::<1>unfreeze(playerid, const string: params[])
{
    if (isnull(string: params)) {
        SendClientMessage(playerid, X11_YELLOW, "KORISTI: "WHITE"/unfreeze [targetid]");
        return 1;
    }

    if (!IsPlayerConnected(strval(string: params))) {
        return 0;
    }

    if (strval(string: params) == playerid) {
        return 0;
    }

    if (!Bit_Get(Bit: PLAYER_FREEZED, strval(string: params))) {
        SendClientMessage(playerid, -1, "Taj igrac nije zaledjen.");
        return 1;
    }

    TogglePlayerControllable(strval(params), 1);
    Bit_Set(Bit: PLAYER_FREEZED, strval(params), false);

    va_SendClientMessageToAll(X11_RED,
        "* Un-Freeze: "WHITE"Igrac %s je odledjen od strane admina %s.",
        ReturnPlayerName(strval(params)), ReturnPlayerName(playerid)
    );

    return 1;
}

static gClearChatTimer;
acmd::<1>cc(playerid, const string: params[])
{
    if (isnull(string: params) && !isnumeric(string: params)) {
        SendClientMessage(playerid, X11_YELLOW, "KORISTI: "WHITE"/cc [lines]");
        return 1;
    }

    if (gettime() < gClearChatTimer) {
        SendClientMessage(playerid, -1, "Chat se moze cistiti svakih 5 sekundi.");
        return 1;
    }

    if (!(1 <= strval(string: params) <= 60)) {
        SendClientMessage(playerid, -1, "Ne mozete ispod 1 i iznad 60 linija.");
        return 1;
    }

    for (new i = 0; i < strval(string: params); ++i) {
        SendClientMessageToAll(-1, " ");
    }

    SendClientMessageToAll(-1, "Chat cleared.");

    // Assign current time + 5 seconds
    gClearChatTimer = (gettime() + 5);

    return 1;
}

acmd::<Admin_GetMaxLevel()>accountinfo(playerid, const string: params[])
{
    if (isnull(string: params)) {
        SendClientMessage(playerid, X11_YELLOW, "KORISTI: "WHITE"/accountinfo [targetid]");
        return 1;
    }

    if (!IsPlayerConnected(strval(string: params))) {
        return 0;
    }

    static string: ip_addr[25];
    GetPlayerIp(strval(string: params), string: ip_addr, sizeof ip_addr);

    Dialog_Show(playerid, "DIALOG_ACCOUNTINFO", DIALOG_STYLE_TABLIST_HEADERS,
        ""WHITE"Account Info",
        ""RED"Account Name\t"RED"IP Address\t"RED"Country\t"RED"City\n\
        "WHITE"%s\t%s\t%s\t%s", ">>", "",
        ReturnPlayerName(strval(string: params)),
        string: ip_addr,
        GetPlayerCountry(strval(string: params)),
        GetPlayerCity(strval(string: params))
    );

    return 1;
}

acmd::<Admin_GetMaxLevel()>givemoney(playerid, const string: params[])
{
    static
        targetid,
        value;
    
    if (sscanf(string: params, "ri", targetid, value)) {
        SendClientMessage(playerid, X11_YELLOW, "KORISTI: "WHITE"/givemoney [targetid] [value]");
        return 1;
    }

    if (!(0 <= value <= 1000000)) {
        SendClientMessage(playerid, -1, "Ne mozete ispod $0 i iznad $1.000.000.");
        return 1;
    }

    Player_SetMoney(targetid, (Player_GetMoney(targetid) + value));
    GivePlayerMoney(playerid, value);        

    va_SendClientMessage(targetid, X11_RED,
        "* Give-Money: "WHITE"Admin %s vam je dao $%d",
        ReturnPlayerName(playerid), value
    );

    return 1;
}