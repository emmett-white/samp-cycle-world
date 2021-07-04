#if defined _inc_acc_functions
    #undef _inc_acc_functions
#endif
// custom include-guard to ensure we don't duplicate
#if defined _acc_functions_included
    #endinput
#endif
#define _acc_functions_included

static gPlayerLoginAttempts[MAX_PLAYERS];

/**
  * Functions
 */
stock CheckPlayerAccount(const playerid)
{
    va_SendClientMessageToAll(X11_ORANGE,
        "* Connect: "WHITE"%s se prijavio. Drzava: "ORANGE"%s"WHITE".",
        ReturnPlayerName(playerid), GetPlayerCountry(playerid)
    );

    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM accounts WHERE account_name = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    if (cache_num_rows()) {
        cache_get_value_name_int(0, "account_id", Player_GetUniqueID(playerid));
        cache_get_value_name(0, "account_password", Player_GetPassword(playerid));

        // Loading character from `characters` table
        task_await(
            Task: MySQL_QueryS(
                String: str_format(
                    "SELECT * FROM characters WHERE char_name = '%e'", ReturnPlayerName(playerid)
                )
            )
        );

        if (cache_num_rows()) {
            static tmpint;

            cache_get_value_name_int(0, "char_id", Player_GetCharUniqueID(playerid));

            cache_get_value_name_int(0, "char_score", tmpint);
            Player_SetScore(playerid, tmpint);

            cache_get_value_name_int(0, "char_money", tmpint);
            Player_SetMoney(playerid, tmpint);

            cache_get_value_name_int(0, "char_skin", tmpint);
            Player_SetSkin(playerid, tmpint);

            cache_get_value_name_int(0, "char_admin", tmpint);
            Admin_SetLevel(playerid, tmpint);

            cache_get_value_name_int(0, "char_admincode", tmpint);
            Admin_SetCode(playerid, tmpint);
        }

        gPlayerLoginAttempts[playerid] = 0;

        Dialog_Show(playerid, "DIALOG_LOGIN", DIALOG_STYLE_PASSWORD,
            "Prijavljivanje", "%s, unesite tacnu lozinku:",
            ">>", "X", ReturnPlayerName(playerid)
        );

        return 1;
    }

    Dialog_Show(playerid, "DIALOG_REGISTER", DIALOG_STYLE_INPUT,
        "Registracija", ""WHITE"%s, unesite zeljenu lozinku:",
        ">>", "X", ReturnPlayerName(playerid)
    );

    return 1;
}

stock Player_SetSpawn(const playerid, const type = 1)
{
    switch (type) {
        case 1: {
            Player_SetSkin(playerid, 26);
            SetSpawnInfo(
                playerid, 0, Player_GetSkin(playerid),
                Float: 1379.4063, Float: -1897.3647, Float: 13.5207, Float: 268.9341,
                0, 0, 0, 0, 0, 0
            );
        }

        case 2: {
            SetSpawnInfo(
                playerid, 0, Player_GetSkin(playerid),
                Float: 1379.4063, Float: -1897.3647, Float: 13.5207, Float: 268.9341,
                0, 0, 0, 0, 0, 0
            );
        }

        case 3: {
            SetSpawnInfo(
                playerid, 0, Player_GetSkin(playerid),
                Float: 1370.4475, Float: -1886.7913, Float: 13.5138, Float: 356.9191,
                0, 0, 0, 0, 0, 0
            );
        }
    }

    SpawnPlayer(playerid);

    return 1;
}

/**
  * Dialogs
 */
Dialog:DIALOG_BANNED(const playerid, response, listitem, string: inputtext[])
{
    #pragma unused listitem, inputtext

    if (!response || response) {
        Kick(playerid);
        return 1;
    }

    return 1;
}

Dialog:DIALOG_REGISTER(const playerid, response, listitem, string: inputtext[])
{
    #pragma unused listitem

    if (!response) {
        Kick(playerid);
        return 1;
    }

    if (!(MIN_PASSWORD_LENGTH <= strlen(inputtext) <= MAX_PASSWORD_LENGTH)) {
        Dialog_Show(playerid, "DIALOG_REGISTER", DIALOG_STYLE_INPUT,
            "Registracija", ""WHITE"%s, unesite zeljenu lozinku:",
            ">>", "X", ReturnPlayerName(playerid)
        );

        return 1;
    }

    strcopy(acc_Password[playerid], inputtext);
    Player_SetPassword(playerid, acc_Password[playerid]);

    new
        String: str_query_insert_acc,
        String: str_query_insert_char;

    str_query_insert_acc = String: str_format("INSERT INTO accounts (`account_name`, `account_password`) VALUES ('%e', '%e')", ReturnPlayerName(playerid), inputtext);
    str_query_insert_char = String: str_format("INSERT INTO characters (`char_name`, `char_score`, `char_money`, `char_skin`, `char_admin`) VALUES ('%e', '0', '0', '1', '0')", ReturnPlayerName(playerid));
    
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_insert_acc, "InsertAccountID", "d", playerid);
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_insert_char, "InsertCharacterID", "d", playerid);

    GameTextForPlayer(playerid, "~y~LOADING ACCOUNT...", 3000, 3);
    task_await(Task: BindToPlayer(task_ms(3000), playerid));
    Player_SetSpawn(playerid, 1);

    va_SendClientMessage(
        playerid, X11_RED, "* "WHITE"%s, uspesno ste se registrovali.",
        ReturnPlayerName(playerid)
    );

    return 1;
}

Dialog:DIALOG_LOGIN(const playerid, response, listitem, string: inputtext[])
{
    #pragma unused listitem

    if (!response) {
        Kick(playerid);
        return 1;
    }

    if (!strcmp(inputtext, acc_Password[playerid], false)) {
        va_SendClientMessage(
            playerid, X11_RED, "* "WHITE"%s, uspesno ste se prijavili.",
            ReturnPlayerName(playerid)
        );

        Player_SetMoney(playerid, Player_GetMoney(playerid));
        Player_SetScore(playerid, Player_GetScore(playerid));
        GivePlayerMoney(playerid, Player_GetMoney(playerid));

        GameTextForPlayer(playerid, "~y~LOADING ACCOUNT...", 3000, 3);
        task_await(Task: BindToPlayer(task_ms(3000), playerid));

        task_await(
            Task: MySQL_QueryS(
                String: str_format(
                    "SELECT * FROM cycles WHERE cycle_owner = '%e'", ReturnPlayerName(playerid)
                )
            )
        );

        if (!cache_num_rows()) {
            Player_SetSpawn(playerid, 2);
            return 1;
        }

        Player_SetSpawn(playerid, 3);
    }

    else {
        ++gPlayerLoginAttempts[playerid];

        if (gPlayerLoginAttempts[playerid] == MAX_LOGIN_ATTEMPTS) {
            Kick(playerid);
            return 1;
        }

        Dialog_Show(playerid, "DIALOG_LOGIN", DIALOG_STYLE_PASSWORD,
            "Prijavljivanje", "%s, unesite tacnu lozinku:",
            ">>", "X", ReturnPlayerName(playerid)
        );

        va_SendClientMessage(
            playerid, X11_RED, "* Pogresna "WHITE"lozinka, pokusaja: "RED"%d"WHITE"/3",
            gPlayerLoginAttempts[playerid]
        );
    }

    return 1;
}