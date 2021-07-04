#if defined _inc_cycle_functions
    #undef _inc_cycle_functions
#endif
// custom include-guard to ensure we don't duplicate
#if defined _cycle_functions_included
    #endinput
#endif
#define _cycle_functions_included

#if defined MAX_CYCLES
    #undef MAX_CYCLES
#else
    const MAX_CYCLES = 100;
#endif

new cycle_UniqueID[MAX_CYCLES];
#define Cycle_GetUniqueID(%0) cycle_UniqueID[%0]

static
    cycle_ID[MAX_CYCLES],
    cycle_Color[MAX_CYCLES][2],
    
    string: cycle_Owner[MAX_CYCLES][MAX_PLAYER_NAME],

    Float: cycle_X[MAX_CYCLES],
    Float: cycle_Y[MAX_CYCLES],
    Float: cycle_Z[MAX_CYCLES],
    Float: cycle_A[MAX_CYCLES],
    
    Iterator: Iter_Cycles<MAX_CYCLES>,
    BitArray: SPAWNED_CYCLE<MAX_PLAYERS>;

/**
  * Functions
 */
stock Cycle_Create(const cycle_vehid, const string: cycle_owner[], Float: x, Float: y, Float: z, Float: a, const color1 = 1, const color2 = 1)
{
    new id = Iter_Alloc(Iter_Cycles);

    cycle_ID[id] = CreateVehicle(cycle_vehid,
        Float: x, Float: y, Float: z, Float: a,
        color1, color2, 0
    );

    cycle_X[cycle_ID[id]] = x, cycle_Y[cycle_ID[id]] = y, cycle_Z[cycle_ID[id]] = z, cycle_A[cycle_ID[id]] = a;
    cycle_Color[cycle_ID[id]][0] = color1, cycle_Color[cycle_ID[id]][1] = color2;

    strcopy(cycle_Owner[cycle_ID[id]], cycle_owner);

    new String: str_query_insert = String: str_format(
        "INSERT INTO \
            cycles (`cycle_owner`, `cycle_vehid`, `cycle_x`, `cycle_y`, `cycle_z`, `cycle_a`, `cycle_color1`, `cycle_color2`) \
            VALUES ('%e', '%d', '%f', '%f', '%f', '%f', '%d', '%d')",
        cycle_Owner[cycle_ID[id]], cycle_vehid, cycle_X[cycle_ID[id]], cycle_Y[cycle_ID[id]], cycle_Z[cycle_ID[id]], cycle_A[cycle_ID[id]], cycle_Color[cycle_ID[id]][0], cycle_Color[cycle_ID[id]][1]
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_insert, "InsertCycleID", "d", id);

    return 1;
}

stock Cycle_Destroy(const cycle_vehid)
{
    new String: str_query_delete = String: str_format(
        "DELETE FROM cycles WHERE cycle_vehid = '%d'", cycle_vehid
    );

    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_delete);
    Iter_Remove(Iter_Cycles, cycle_vehid);

    return 1;
}

stock Cycle_Spawn(const cycle_vehid, Float: x, Float: y, Float: z, Float: a, const color1 = 1, const color2 = 1)
{
    CreateVehicle(cycle_vehid,
        Float: x, Float: y, Float: z, Float: a,
        color1, color2, 0
    );

    return 1;
}

stock Cycle_SetPosition(const cycle_id, Float: x, Float: y, Float: z, Float: a = 0.0)
{
    cycle_X[cycle_id] = x, cycle_Y[cycle_id] = y, cycle_Z[cycle_id] = z, cycle_A[cycle_id] = a;
    return 1;
}

stock Cycle_SetColour(const cycle_id, const color1 = 1, const color_2 = 1)
{
    cycle_Color[cycle_id][0] = color1, cycle_Color[cycle_id][1] = color2;
    return 1;
}

stock Cycle_SetSpawnStatus(const playerid, bool: status = true)
{
    Bit_Set(Bit: SPAWNED_CYCLE, playerid, bool: status);
    return 1;
}

stock Cycle_GetSpawnStatus(const playerid) return Bit_Get(Bit: SPAWNED_CYCLE, playerid);
stock Cycle_GetOwner(const cycle_id) return string: cycle_Owner[cycle_id];
stock Cycle_GetColour(const cycle_id, const index) return (!index ? (cycle_Color[cycle_id][0]) : cycle_Color[cycle_id][1]);
stock Cycle_GetPosition(const cycle_id, const index)
{
    switch (index) {
        case 0: return _:cycle_X[cycle_id];
        case 1: return _:cycle_Y[cycle_id];
        case 2: return _:cycle_Z[cycle_id];
        case 3: return _:cycle_A[cycle_id];
    }

    return 1;
}