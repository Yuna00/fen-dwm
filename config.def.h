static const unsigned int borderpx = 4; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const int showbar = 1;           /* 0 means no bar */
static const int topbar = 1;            /* 0 means bottom bar */
static const int horizpadbar = 2;       /* horizontal padding for statusbar */
static const int vertpadbar = 5;        /* vertical padding for statusbar */
static const char *fonts[] = {"IosevkaNerdFontMono:size=20"};
static const char dmenufont[] = "IosevkaNerdFontMono:size=20";
static const char col_gray1[] = "#11111B";
static const char col_gray2[] = "#11111B";
static const char col_gray3[] = "#D9E0EE";
static const char col_gray4[] = "#D9E0EE";
static const char col_cyan[] = "#CBA6F7";
static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = {col_gray3, col_gray1, col_gray2},
    [SchemeSel] = {col_gray1, col_cyan, col_cyan},
};

static const char *const autostart[] = {
    "wmname", "LG3D",
    NULL,     "/home/zephyr/suckless/dwm/scripts/bar",
    NULL,     "/usr/local/bin/hsetroot",
    "-cover", "/home/zephyr/suckless/dwm/wallpapers/catppuccin_triangle.png",
    NULL,
    NULL /* terminate */
};

/* tagging */
static const char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

static Rule rules[] = {
    /* class      instance    title       tags mask     isfloating   monitor */
    {"note_window", NULL, NULL, 0, 0, -1},

    {"MATLAB R2024b - academic use", NULL, "Figure 1", 0, 1, -1},
    {"MATLAB R2024b - academic use", NULL, "Figure 2", 0, 1, -1},
    {"MATLAB R2024b - academic use", NULL, "Figure 3", 0, 1, -1},
    {"MATLAB R2024b - academic use", NULL, "Figure 4", 0, 1, -1},
    {"MATLAB R2024b - academic use", NULL, "Figure 5", 0, 1, -1},
    {"MATLAB R2024b - academic use", NULL, "Figure 6", 0, 1, -1},
    {"MATLAB R2024b - academic use", NULL, "Figure 7", 0, 1, -1},
    {"MATLAB R2024b - academic use", NULL, "Figure 8", 0, 1, -1},
    {"MATLAB R2024b - academic use", NULL, "Figure 9", 0, 1, -1},
};
/* layout(s) */
static const float mfact = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* key definitions */
#define MODKEY Mod1Mask
#define WINKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* CMD is for anything with no args */
#define CMD(cmd)                                                               \
  {                                                                            \
    .v = (const char *[]) { cmd, NULL }                                        \
  }
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/dash", "-c", cmd, NULL }                     \
  }
#define DWMHOME "/home/zephyr/suckless/fen-dwm"
#define SCRIPTHOME DWMHOME "/scripts/"
#define SCRIPT(script) SCRIPTHOME #script


/* commands */
static char dmenumon[2] =
    "0"; /* component  of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
    "dmenu_run", "-m",      dmenumon, "-fn",    dmenufont, "-nb",     col_gray1,
    "-nf",       col_gray3, "-sb",    col_cyan, "-sf",     col_gray4, NULL};
static const char *termcmd[] = {"st", NULL};
static const char *edcmd[] = {"emacsclient", "-c", "-n", "-a", "emacs", NULL};
static const char *browsercmd[] = {"qutebrowser", NULL};
static const char *notecmd[] = {
    "st", "-c", "note_window", "-e", "/home/zephyr/suckless/dwm/scripts/notes",
    NULL};
static const char *sscmd[] = {"dash", "-c",        "'maim",      "-s",
                              "|",    "xclip",     "-selection", "clipboard",
                              "-t",   "image/png", "-i'",        NULL};

static const Key keys[] = {
    /* modifier                     key        function        argument */
    {MODKEY, XK_p, spawn, {.v = dmenucmd}},
    {WINKEY | ShiftMask, XK_s, spawn, CMD(SCRIPT(ss))},
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_e, spawn, {.v = edcmd}},
    {MODKEY, XK_n, spawn, {.v = notecmd}},
    {MODKEY, XK_b, spawn, {.v = browsercmd}},
    //{MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | ShiftMask, XK_c, killclient, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_q, quit, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
