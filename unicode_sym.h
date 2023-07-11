#pragma once

enum unicode_names {
    PSI_U,   // Ψ
    OMEG_U,  // Ω
    MU_U,    // μ
    BETA_U,  // β
    EURO_U,  // €
    NU_U,    // η
    LAMB_U,  // λ
    SQRT_U,  // √
    COPY_U,  // ©
    REGD_U,  // ®
    YEN_U,   // ¥
    LDAQ_U,  // «
    RDAQ_U,  // »
    SECT_U,  // §
    DEG_U,   // °
    UPSL_U,  // ϒ
    OSTR_U,  // Ø
    APLH_U,  // α
    PI_U,    // π
    IPS_U,   // ϒ
    MUL_U,   // ×
    NBSP_U,  //
    PND_U,   // £
    BRKP_U,  // ¦
    RUBLE_U, // ₽
    GT_U,
    LT_U,
    AMPE_U,
};

const uint32_t PROGMEM unicode_map[] = {
    // sym layer
    [PSI_U]   = 0x03A8, // Ψ
    [OMEG_U]  = 0x03A9, // Ω
    [MU_U]    = 0x03BC, // μ
    [BETA_U]  = 0x03B2, // β
    [EURO_U]  = 0x20AC, // €
    [NU_U]    = 0x03B7, // η
    [LAMB_U]  = 0x03BB, // λ
    [SQRT_U]  = 0x221A, // √
    [COPY_U]  = 0x00A9, // ©
    [REGD_U]  = 0x00AE, // ®
    [YEN_U]   = 0x00A5, // ¥
    [LDAQ_U]  = 0x00AB, // «
    [RDAQ_U]  = 0x00BB, // »
    [SECT_U]  = 0x00A7, // §
    [DEG_U]   = 0x00B0, // °
    [UPSL_U]  = 0x03D2, // ϒ
    [OSTR_U]  = 0x00D8, // Ø
    [APLH_U]  = 0x03B1, // α
    [PI_U]    = 0x03C0, // π
    [IPS_U]   = 0x03D2, // ϒ
    [MUL_U]   = 0x00D7, // ×
    [NBSP_U]  = 0x00A0, // Non-breaking space
    [PND_U]   = 0x00A3, // £
    [BRKP_U]  = 0x00A6, // ¦
    [LT_U]    = '<',    // <
    [GT_U]    = '>',    // >
    [AMPE_U]  = '&',    // &
    [RUBLE_U] = 0x20BD, // ₽
};

#define PSI X(PSI_U)
#define OMEG X(OMEG_U)
#define MU X(MU_U)
#define BETA X(BETA_U)
#define EURO X(EURO_U)
#define NU X(NU_U)
#define LAMB X(LAMB_U)
#define SQRT X(SQRT_U)
#define COPY X(COPY_U)
#define REGD X(REGD_U)
#define YEN X(YEN_U)
#define LDAQ X(LDAQ_U)
#define RDAQ X(RDAQ_U)
#define SECT X(SECT_U)
#define DEG X(DEG_U)
#define UPSL X(UPSL_U)
#define OSTR X(OSTR_U)
#define APLH X(APLH_U)
#define PI X(PI_U)
#define IPS X(IPS_U)
#define MUL X(MUL_U)
#define NBSP X(NBSP_U)
#define PND X(PND_U)
#define BRKP X(BRKP_U)
#define _LT X(LT_U)
#define _GT X(GT_U)
#define AMPE X(AMPE_U)
#define RUBLE X(RUBLE_U)
