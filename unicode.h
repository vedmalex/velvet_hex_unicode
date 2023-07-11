#pragma once

enum unicode_names {
    // russian codes
    RU_A_L,
    RU_BE_L,
    RU_VE_L,
    RU_GHE_L,
    RU_DE_L,
    RU_IE_L,
    RU_YO_L,
    RU_ZHE_L,
    RU_ZE_L,
    RU_I_L,
    RU_SHTI_L,
    RU_KA_L,
    RU_EL_L,
    RU_EM_L,
    RU_EN_L,
    RU_O_L,
    RU_PE_L,
    RU_ER_L,
    RU_ES_L,
    RU_TE_L,
    RU_U_L,
    RU_EF_L,
    RU_HA_L,
    RU_TSE_L,
    RU_CHE_L,
    RU_SHA_L,
    RU_SHCH_L,
    RU_HARD_L,
    RU_YERU_L,
    RU_SOFT_L,
    RU_E_L,
    RU_YU_L,
    RU_YA_L,

    RU_A_U,
    RU_BE_U,
    RU_VE_U,
    RU_GHE_U,
    RU_DE_U,
    RU_IE_U,
    RU_YO_U,
    RU_ZHE_U,
    RU_ZE_U,
    RU_I_U,
    RU_SHTI_U,
    RU_KA_U,
    RU_EL_U,
    RU_EM_U,
    RU_EN_U,
    RU_O_U,
    RU_PE_U,
    RU_ER_U,
    RU_ES_U,
    RU_TE_U,
    RU_U_U,
    RU_EF_U,
    RU_HA_U,
    RU_TSE_U,
    RU_CHE_U,
    RU_SHA_U,
    RU_SHCH_U,
    RU_HARD_U,
    RU_YERU_U,
    RU_SOFT_U,
    RU_E_U,
    RU_YU_U,
    RU_YA_U,
};

const uint32_t PROGMEM unicode_map[] = {
    [RU_A_L]    = 0x0430, // а
    [RU_BE_L]   = 0x0431, // б
    [RU_VE_L]   = 0x0432, // в
    [RU_GHE_L]  = 0x0433, // г
    [RU_DE_L]   = 0x0434, // д
    [RU_IE_L]   = 0x0435, // е
    [RU_YO_L]   = 0x0451, // ё
    [RU_ZHE_L]  = 0x0436, // ж
    [RU_ZE_L]   = 0x0437, // з
    [RU_I_L]    = 0x0438, // и
    [RU_SHTI_L] = 0x0439, // й
    [RU_KA_L]   = 0x043A, // к
    [RU_EL_L]   = 0x043B, // л
    [RU_EM_L]   = 0x043C, // м
    [RU_EN_L]   = 0x043D, // н
    [RU_O_L]    = 0x043E, // о
    [RU_PE_L]   = 0x043F, // п
    [RU_ER_L]   = 0x0440, // р
    [RU_ES_L]   = 0x0441, // с
    [RU_TE_L]   = 0x0442, // т
    [RU_U_L]    = 0x0443, // у
    [RU_EF_L]   = 0x0444, // ф
    [RU_HA_L]   = 0x0445, // х
    [RU_TSE_L]  = 0x0446, // ц
    [RU_CHE_L]  = 0x0447, // ч
    [RU_SHA_L]  = 0x0448, // ш
    [RU_SHCH_L] = 0x0449, // щ
    [RU_HARD_L] = 0x044A, // ъ
    [RU_YERU_L] = 0x044B, // ы
    [RU_SOFT_L] = 0x044C, // ь
    [RU_E_L]    = 0x044D, // э
    [RU_YU_L]   = 0x044E, // ю
    [RU_YA_L]   = 0x044F, // я

    // Uppercase letters
    [RU_A_U]    = 0x0410, // А
    [RU_BE_U]   = 0x0411, // Б
    [RU_VE_U]   = 0x0412, // В
    [RU_GHE_U]  = 0x0413, // Г
    [RU_DE_U]   = 0x0414, // Д
    [RU_IE_U]   = 0x0415, // Е
    [RU_YO_U]   = 0x0401, // Ё
    [RU_ZHE_U]  = 0x0416, // Ж
    [RU_ZE_U]   = 0x0417, // З
    [RU_I_U]    = 0x0418, // И
    [RU_SHTI_U] = 0x0419, // Й
    [RU_KA_U]   = 0x041A, // К
    [RU_EL_U]   = 0x041B, // Л
    [RU_EM_U]   = 0x041C, // М
    [RU_EN_U]   = 0x041D, // Н
    [RU_O_U]    = 0x041E, // О
    [RU_PE_U]   = 0x041F, // П
    [RU_ER_U]   = 0x0420, // Р
    [RU_ES_U]   = 0x0421, // С
    [RU_TE_U]   = 0x0422, // Т
    [RU_U_U]    = 0x0423, // У
    [RU_EF_U]   = 0x0424, // Ф
    [RU_HA_U]   = 0x0425, // Х
    [RU_TSE_U]  = 0x0426, // Ц
    [RU_CHE_U]  = 0x0427, // Ч
    [RU_SHA_U]  = 0x0428, // Ш
    [RU_SHCH_U] = 0x0429, // Щ
    [RU_HARD_U] = 0x042A, // Ъ
    [RU_YERU_U] = 0x042B, // Ы
    [RU_SOFT_U] = 0x042C, // Ь
    [RU_E_U]    = 0x042D, // Э
    [RU_YU_U]   = 0x042E, // Ю
    [RU_YA_U]   = 0x042F, // Я
};

#define RU_A XP(RU_A_L, RU_A_U)
#define RU_BE XP(RU_BE_L, RU_BE_U)
#define RU_VE XP(RU_VE_L, RU_VE_U)
#define RU_GHE XP(RU_GHE_L, RU_GHE_U)
#define RU_DE XP(RU_DE_L, RU_DE_U)
#define RU_IE XP(RU_IE_L, RU_IE_U)
#define RU_YO XP(RU_YO_L, RU_YO_U)
#define RU_ZHE XP(RU_ZHE_L, RU_ZHE_U)
#define RU_ZE XP(RU_ZE_L, RU_ZE_U)
#define RU_I XP(RU_I_L, RU_I_U)
#define RU_SHTI XP(RU_SHTI_L, RU_SHTI_U)
#define RU_KA XP(RU_KA_L, RU_KA_U)
#define RU_EL XP(RU_EL_L, RU_EL_U)
#define RU_EM XP(RU_EM_L, RU_EM_U)
#define RU_EN XP(RU_EN_L, RU_EN_U)
#define RU_O XP(RU_O_L, RU_O_U)
#define RU_PE XP(RU_PE_L, RU_PE_U)
#define RU_ER XP(RU_ER_L, RU_ER_U)
#define RU_ES XP(RU_ES_L, RU_ES_U)
#define RU_TE XP(RU_TE_L, RU_TE_U)
#define RU_U XP(RU_U_L, RU_U_U)
#define RU_EF XP(RU_EF_L, RU_EF_U)
#define RU_HA XP(RU_HA_L, RU_HA_U)
#define RU_TSE XP(RU_TSE_L, RU_TSE_U)
#define RU_CHE XP(RU_CHE_L, RU_CHE_U)
#define RU_SHA XP(RU_SHA_L, RU_SHA_U)
#define RU_SHCH XP(RU_SHCH_L, RU_SHCH_U)
#define RU_HARD XP(RU_HARD_L, RU_HARD_U)
#define RU_YERU XP(RU_YERU_L, RU_YERU_U)
#define RU_SOFT XP(RU_SOFT_L, RU_SOFT_U)
#define RU_E XP(RU_E_L, RU_E_U)
#define RU_YU XP(RU_YU_L, RU_YU_U)
#define RU_YA XP(RU_YA_L, RU_YA_U)
