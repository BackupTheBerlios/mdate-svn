// POLISH TRANSLATION.
// by Krzysztof "Tuvok" Borowczyk
 
// Wszelkie b��dy/niejasno�ci w t�umaczeniu zg�asza� na adres:
// tuvokhome@interia.pl
 
// version 1.5.1

// ============================= Mdate help ===============================

#ifdef STATIC_HELP
static char pl_helptext[] __attribute__ ((unused)) =
"\n"
"Mdate podaje proste daty wg. kalendarza Maj�w.\n"
"U�ycie: mdate [OPCJE]... [+FORMAT]\n"
"   -h, --help                wy�wietla pomoc i ko�czy dzia�anie\n"
"   -V, --version             wy�wietla wersj� programu i ko�czy dzia�anie\n"
"   -p, --parseable           wy�wietla dat� w formie �atwej do wczytania\n"
"				innym programem (standardowo wy��czone)\n"
"   -g, --gmt                 korelacja GMT (standardowo wy��czone)\n"
"   -L, --lang=LANGUAGE       wyb�r j�zyka\n"
"   -c, --correlation=DOUBLE  opcjonalna korelacja (standardowo brak)\n"
"   -d, --dmy=STRING          dzie� miesi�c rok (wg. kalendarza Gregoria�skiego)\n"
"   -j, --julian=DOUBLE       numer dnia wg. kalendarza Julia�skiego\n"
"   -l, --longcount=STRING    data wg. D�ugiej Rachuby Kalendarzowej Maj�w\n"
"\n"
"Proprawne identyfikatory LANGUAGE:\n"
"  en Angielski\n"
"  es Hiszpa�ski\n"
"  pl Polski\n"
"  de Niemiecki\n"
"  fr Francuski\n"
"\n"
"Poprawne identyfikatory FORMAT'u:\n"
"  @a skr�t nazwy dnia tygodnia\n"
"  @A pe�na nazwa dnia tygodnia\n"
"  @b skr�t nazwy miesi�ca\n"
"  @B pe�na nazwa miesi�ca\n"
"  @d numer dnia miesi�ca (01..31)\n"
"  @e numer dnia bez poprzedzaj�cego zera \n"
"  @F format ISO daty Gregoria�skiej (%R-%m-%d)\n"
"  @f format ISO daty Gregoria�skiej (%R%m%d)\n"
"  @h data Haab bez poprzedzaj�cej spacji i zera\n"
"  @H data Haab z poprzedzaj�c� spacj� i zerem\n"
"  @l D�uga Rachuba Kalendarzowa\n"
"  @M nazwa miesi�ca Gregoria�skiego\n"
"  @m numer miesi�ca Gregoria�skiego\n"
"  @t data Tzolkin bez poprzedzaj�cej spacji i zera\n"
"  @T data Tzolkin z poprzedzaj�c� spacj� i zerem\n"
"  @y rok jako dwie cyfry (00-99)\n"
"  @Y rok Gregoria�ski\n"
"  @n dodaje znak nowej lini\n"
"  @j dodaje dodaje znak tab\n"
"\n";
#endif

// ============================= Mdate messages ===========================

const char* PL_MSG_CERR = "Mdate: `--correlation' (`-c') opcja podana wi�cej ni� jeden raz\n";
const char* PL_MSG_DERR = "Mdate: `--dmy' (`-d') opcja podana wi�cej ni� jeden raz\n";
const char* PL_MSG_JERR = "Mdate: `--julian' (`-j') opcja podana wi�cej ni� jeden raz\n";
const char* PL_MSG_LERR = "Mdate: `--longcount' (`-l') opcja podana wi�cej ni� jeden raz\n";
const char* PL_MSG_OPTERR = "Mdate: nieznana opcja: ";
const char* PL_MSG_NONOPTERR = "Zbyt wiele argument�w nie b�d�cych opcjami!\n";
const char* PL_MSG_LONGERR = "Podana data nie jest dozwolona!\n";
const char* PL_MSG_GENERR = "b��d!\n";
const char* PL_MSG_ILC = "Nieprawid�owo podana D�uga Rachuba Kalendarzowa!\n";
const char* PL_MSG_IGD = "Nieprawid�owo podana data Gregoria�ska!\n";
const char* PL_MSG_IJDN = "Nieprawid�owo podany Julia�ski numer dnia!\n";
const char* PL_MSG_FORMATERR = "Nieznany format!\n";

// ============================= Mdate formats ============================

static char pl_pretty_format[] __attribute__ ((unused)) =
"\n"
"Data Gregoria�ska  : @d-@B-@Y (@d/@m/@Y)\n"
"Julia�ski Nr. Dnia : @J\n"
"D�. Rachuba Kal.   : @l\n"
"Data Tzolkin       : @T\n"
"Data Haab          : @h\n";


static char pl_default_format[] __attribute__ ((unused)) = "JND: @J data: @d @m @Y  @l @T @H";

// ============================= Mdate days ===============================

static const char *pl_short_days[] __attribute__ ((unused)) = {
	"Pon","Wto","�ro","Czw","Pi�","Sob","Nie"
};

static const char *pl_days[] __attribute__ ((unused)) = {
	"Poniedzia�ek","Wtorek","�roda","Czwartek","Pi�tek","Sobota","Niedziela"
};
