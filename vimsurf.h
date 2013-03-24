#define LENGTH(x)               (sizeof x / sizeof x[0])
#define CLEANMASK(mask)		(mask & (MODKEY|GDK_SHIFT_MASK))
#define COOKIEJAR_TYPE          (cookiejar_get_type ())
#define COOKIEJAR(obj)          (G_TYPE_CHECK_INSTANCE_CAST ((obj), COOKIEJAR_TYPE, CookieJar))

enum { AtomFind, AtomGo, AtomUri, AtomLast };

typedef struct Key Key;
typedef struct Client Client;
typedef struct Item Item;
typedef struct CookieJar CookieJar;
typedef struct CookieJarClass CookieJarClass;

typedef union Arg Arg;
union Arg {
	gboolean b;
	gint i;
	const void *v;
};

enum {ModeNormal, ModeScript, ModeInsert};

struct Key {
	const char letter;
	void (*func)(Client *c, const Arg *arg);
	const Arg arg; 	
	guint mode; //The mode that is changed to
};

struct Client {
	GtkWidget *win, *scroll, *vbox, *indicator, *pane, *console;
	WebKitWebView *view;
	WebKitWebInspector *inspector;
	char *title, *linkhover;
	char *str;
	const char *uri, *needle;
	gint progress;
	struct Client *next;
	gboolean zoomed, fullscreen, isinspecting, sslfailed;
	gint id; //The Id of the keypress event
};

struct Item {
	char *label;
	void (*func)(Client *c, const Arg *arg);
	const Arg arg;
};


struct CookieJar {
	SoupCookieJarText parent_instance;
	int lock;
};

struct CookieJarClass{
	SoupCookieJarTextClass parent_class;
};

G_DEFINE_TYPE(CookieJar, cookiejar, SOUP_TYPE_COOKIE_JAR_TEXT)



