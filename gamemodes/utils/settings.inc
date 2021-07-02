#if defined _inc_settings
    #undef _inc_settings
#endif
// custom include-guard to ensure we don't duplicate
#if defined _settings_included
    #endinput
#endif
#define _settings_included

const
    MIN_PASSWORD_LENGTH =   6,
    MAX_PASSWORD_LENGTH =   24,
    MAX_LOGIN_ATTEMPTS =    3,
    MAX_ADMIN_LEVEL =       3;
    
#define MAX_REASON_LENGTH   64