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

    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cycles WHERE cycle_owner = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    if (cache_num_rows()) {
        SendClientMessage(playerid, -1, "Vec imate bicikl/motor.");
        return 1;
    }

    // SelectTextDraw(playerid, X11_WHITE);
    UI_CreateBuyTextDraws(playerid);

    return 1;
}

cmd::spawncycle(playerid, const string: params[])
{
    if (Cycle_GetSpawnStatus(playerid)) {
        SendClientMessage(playerid, -1, "Vec ste spawnovali svoj bicikl/motor.");
        return 1;
    }

    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cycles WHERE cycle_owner = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    if (!cache_num_rows()) {
        SendClientMessage(playerid, -1, "Nemate bicikl/motor.");
        return 1;
    }

    static
        x, y, z, a,
        tmpvehid;

    GetPlayerPos(playerid, Float: x, Float: y, Float: z);
    GetPlayerFacingAngle(playerid, Float: a);

    for (new i; i < cache_num_rows(); ++i) {
        cache_get_value_name_int(i, "cycle_vehid", tmpvehid);
    }

    Player_SpawnedCycle(playerid) = Cycle_Spawn(tmpvehid, Float: x, Float: y, Float: z, Float: a);
    PutPlayerInVehicle(playerid, Player_SpawnedCycle(playerid), 0);

    Cycle_SetSpawnStatus(playerid);

    return 1;
}

cmd::sellcycle(playerid, const string: params[])
{
    if (!IsPlayerInRangeOfPoint(playerid, Float: 2.0, Float: 1219.2585, Float: -1812.3386, Float: 16.5938)) {
        SendClientMessage(playerid, -1, "Niste na mestu gde se prodaju bicikli/motori.");
        return 1;
    }

    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cycles WHERE cycle_owner = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    if (!cache_num_rows()) {
        SendClientMessage(playerid, -1, "Nemate bicikl/motor.");
        return 1;
    }

    static tmpvehid;

    for (new i; i < cache_num_rows(); ++i) {
        cache_get_value_name_int(i, "cycle_vehid", tmpvehid);
    }

    switch (tmpvehid) {
        case 481: {
            Player_SetMoney(playerid, (Player_GetMoney(playerid) + 70));
            GivePlayerMoney(playerid, 70);
        }
        
        case 510: {
            Player_SetMoney(playerid, (Player_GetMoney(playerid) + 130));
            GivePlayerMoney(playerid, 130);
        }
        
        case 509: {
            Player_SetMoney(playerid, (Player_GetMoney(playerid) + 40));
            GivePlayerMoney(playerid, 40);
        }
        
        case 462: {
            Player_SetMoney(playerid, (Player_GetMoney(playerid) + 300));
            GivePlayerMoney(playerid, 300);
        }
        
        case 586: {
            Player_SetMoney(playerid, (Player_GetMoney(playerid) + 750));
            GivePlayerMoney(playerid, 750);
        }
        
        case 463: {
            Player_SetMoney(playerid, (Player_GetMoney(playerid) + 3700));
            GivePlayerMoney(playerid, 3700);
        }
        
        case 468: {
            Player_SetMoney(playerid, (Player_GetMoney(playerid) + 1900));
            GivePlayerMoney(playerid, 1900);
        }
        
        case 461: {
            Player_SetMoney(playerid, (Player_GetMoney(playerid) + 2300));
            GivePlayerMoney(playerid, 2300);
        }
        
        case 521: {
            Player_SetMoney(playerid, (Player_GetMoney(playerid) + 3250));
            GivePlayerMoney(playerid, 3250);
        }
        
        case 581: {
            Player_SetMoney(playerid, (Player_GetMoney(playerid) + 3800));
            GivePlayerMoney(playerid, 3800);
        }
        
        case 522: {
            Player_SetMoney(playerid, (Player_GetMoney(playerid) + 7000));
            GivePlayerMoney(playerid, 7000);
        }
    }

    Cycle_Destroy(tmpvehid);
    DestroyVehicle(Player_SpawnedCycle(playerid));
    Cycle_SetSpawnStatus(playerid, false);

    return 1;
}