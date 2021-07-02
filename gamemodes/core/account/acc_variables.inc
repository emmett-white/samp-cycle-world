#if defined _inc_acc_variables
    #undef _inc_acc_variables
#endif
// custom include-guard to ensure we don't duplicate
#if defined _acc_variables_included
    #endinput
#endif
#define _acc_variables_included

new
    acc_UniqueID[MAX_PLAYERS],
    char_UniqueID[MAX_PLAYERS],
    string: acc_Password[MAX_PLAYERS][64];

#define Player_GetUniqueID(%0) acc_UniqueID[%0]
#define Player_GetCharUniqueID(%0) char_UniqueID[%0]
#define Player_GetPassword(%0) acc_Password[%0]

static
    char_Skin[MAX_PLAYERS],
    char_Money[MAX_PLAYERS],
    char_Score[MAX_PLAYERS];

/**
  * Set functions
 */
stock Player_SetPassword(const playerid, const string: password[])
{
    strcopy(string: acc_Password[playerid], string: password);

    new String: str_query_update = String: str_format(
        "UPDATE accounts SET account_password = '%e' WHERE account_id = '%d'",
        Player_GetPassword(playerid), Player_GetUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Player_SetSkin(const playerid, const skinid)
{
    char_Skin[playerid] = skinid;

    SetPlayerSkin(playerid, skinid);

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_skin = '%d' WHERE char_id = '%d'",
        Player_GetSkin(playerid), Player_GetCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Player_SetMoney(const playerid, const value)
{
    char_Money[playerid] = value;

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_money = '%d' WHERE char_id = '%d'",
        Player_GetMoney(playerid), Player_GetCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Player_SetScore(const playerid, const score)
{
    char_Score[playerid] = score;
    SetPlayerScore(playerid, score);

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_score = '%d' WHERE char_id = '%d'",
        Player_GetScore(playerid), Player_GetCharUniqueID(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

/**
  * Get
 */
stock Player_GetSkin(const playerid) return char_Skin[playerid];
stock Player_GetMoney(const playerid) return char_Money[playerid];
stock Player_GetScore(const playerid) return char_Score[playerid];