#if defined _inc_player_commands
    #undef _inc_player_commands
#endif
// custom include-guard to ensure we don't duplicate
#if defined _player_commands_included
    #endinput
#endif
#define _player_commands_included

cmd::changepass(playerid, const string: params[])
{
    if (isnull(string: params)) {
        SendClientMessage(playerid, X11_YELLOW, "KORISTI: "WHITE"/changepass [new password]");
        return 1;
    }

    if (!(MIN_PASSWORD_LENGTH <= strlen(string: params) <= MAX_PASSWORD_LENGTH)) {
        SendClientMessage(playerid, X11_RED, "* "WHITE"Prekratka ili predugacka lozinka!");
        return 1;
    }

    Player_SetPassword(playerid, string: params);
    va_SendClientMessage(playerid, -1, "Vasa nova lozinka: "GRAY"%s", string: params);

    return 1;
}

cmd::skin(playerid, const string: params[])
{
    if (isnull(string: params) && !isnumeric(string: params)) {
        SendClientMessage(playerid, X11_YELLOW, "KORISTI: "WHITE"/skin [skin id]");
        return 1;
    }

    if (!(1 <= strval(string: params) <= 312)) {
        SendClientMessage(playerid, -1, "Pogresan ID!");
        return 1;
    }

    Player_SetSkin(playerid, strval(string: params));

    return 1;
}

cmd::buy(playerid, const string: params[])
{
    if (!IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1391.3153, Float: -1897.4458, Float: 13.5206)) {
        SendClientMessage(playerid, -1, "Morate biti u cycle shop-u!");
        return 1;
    }

    SelectTextDraw(playerid, X11_WHITE);
    UI_CreateBuyTextDraws(playerid);
    Cycle_SetMenuPage(playerid, 0);

    return 1;
}