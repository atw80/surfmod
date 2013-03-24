/* modifier 0 means no modifier */
static char *useragent      = "Mozilla/5.0 (X11; U; Unix; en-US) "
	"AppleWebKit/537.15 (KHTML, like Gecko) Chrome/24.0.1295.0 "
	"Safari/537.15 Surf/"VERSION;
static char *progress       = "#0000FF";
static char *progress_untrust = "#FF0000";
static char *progress_trust = "#00FF00";
static char *progress_proxy = "#FFFF00";
static char *progress_proxy_trust = "#66FF00";
static char *progress_proxy_untrust = "#FF6600";
static char *stylefile      = "~/.surf/style.css";
static char *scriptfile     = "~/.surf/script.js";
static char *cookiefile     = "~/.surf/cookies.txt";
static char *historyfile    = "~/.surf/history.txt";
static time_t sessiontime   = 3600;
static char *cafile         = "/etc/ssl/certs/ca-certificates.crt";
static char *strictssl      = FALSE; /* Refuse untrusted SSL connections */
static int   indicator_thickness = 2;

/* Webkit default features */
static Bool enablespatialbrowsing = TRUE;
static Bool enableplugins = TRUE;
static Bool enablescripts = TRUE;
static Bool enableinspector = TRUE;
static Bool loadimages = TRUE;
static Bool hidebackground  = FALSE;
#define DOWNLOAD(d, r) { .v = (char *[]){ "surfdownload", d, useragent, r, NULL }}

#define SETPROP(scr, p) { .v = (char *[]){ "/bin/sh", "-c", \
	"prop=`$1` && xprop -id $2 -f $0 8s -set $0 \"$prop\"", \
	p, scr, winid, NULL }}

#define HOMEPAGE "localhost/tb"


/* hotkeys */
/*
 * If you use anything else but MODKEY and GDK_SHIFT_MASK, don't forget to
 * edit the CLEANMASK() macro.
 */
//Keybinds in the normal view binds
static Key normalKeys[] = {
	{'j', scroll_v, { .i = 1}, ModeNormal},
	{'k', scroll_v, { .i = -1}, ModeNormal},
	{'h', scroll_h, { .i = -1}, ModeNormal},
	{'l', scroll_h, { .i = 1}, ModeNormal},
	
	{'r', reload, { .b = FALSE}, ModeNormal},
	{'R', reload, { .b = TRUE}, ModeNormal},
	{'s', stop, { 0 }, ModeNormal},

	{'1', zoom, { .i = -1}, ModeNormal},
	{'2', zoom, { .i = 1}, ModeNormal},
	{'3', zoom, { .i = 0}, ModeNormal},

	{'m', navigate, { .i = 1}, ModeNormal},
	{'b', navigate, { .i = -1}, ModeNormal},

	{'o', spawn, SETPROP("surfnavigate", "_SURF_GO"), ModeNormal},

	{'/', spawn, SETPROP("surffind", "_SURF_FIND"), ModeNormal},
	{'n', find, { .b = TRUE } , ModeNormal},
	{'N', find, { .b = FALSE} , ModeNormal},

	{'f', eval, { .v = "follow();" }, ModeScript},
};

static Key scriptKeys[] = {
	{'f', eval, { .v = "unfollow();" }, ModeNormal},
};
