// French translation (c) 2003 by Fran�ois-Xavier Coudert
// <coudert@users.sourceforge.net>
 
// version 1.5.1

// ============================= Mdate help ===============================

#ifdef STATIC_HELP
static char fr_helptext[] __attribute__ ((unused)) =
"\n"
"Mdate retourne des dates simples au calendrier maya.\n"
"Utilisation: mdate [OPTION]... [+FORMAT]\n"
"   -h, --help                Affiche ce message d'aide et quitte\n"
"   -V, --version             Affiche le num�ro de version et quitte\n"
"   -p, --parseable           sortie � format fixe (par d�faut�: non)\n"
"   -g, --gmt                 utilise la corr�lation GTM (par d�faut�: non)\n"
"   -L, --lang=LANGUE         change la langue (par d�faut�: en)\n"
"   -c, --correlation=DOUBLE  corr�lation optionnelle (par d�faut�: non)\n"
"   -d, --dmy=CHA�NE          jour mois ann�e (calendrier gr�gorien)\n"
"   -j, --julian=DOUBLE       num�ro du jour dans le calendrier julien\n"
"   -l, --longcount=CHA�NE    compte long\n"
"\n"
"Les indicatifs de LANGUE valables sont�:\n"
"  fr  fran�ais\n"
"  en  anglais\n"
"  de  allemand\n"
"  es  espagnol\n"
"  pl  polonais\n"
"\n"
"Les indicatifs de FORMAT valables sont�:\n"
"  @a  nom du jour de la semaine en abr�g�\n"
"  @A  nom du jour de la semaine\n"
"  @b  nom du mois en abr�g�\n"
"  @B  nom du mois\n"
"  @d  jour du mois (01..31)\n"
"  @e  jour du mois, sans z�ro inutile (1..31)\n"
"  @F  Date au calendrier gr�gorien, format ISO (%Y-%m-%d)\n"
"  @f  Date au calendrier gr�gorien, format ISO (%Y%m%d)\n"
"  @h  date Haab, sans z�ro inutile\n"
"  @H  date Haab, format fixe\n"
"  @l  Compte Long\n"
"  @M  nom du mois gr�gorien\n"
"  @m  mois gr�gorien num�rique\n"
"  @t  date Tzolkin, sans z�ro inutile\n"
"  @T  date Tzolkin, format fixe\n"
"  @y  ann�e dans le si�cle (27 pour 2027)\n"
"  @Y  ann�e gr�gorienne\n"
"  @n  retour � la ligne\n"
"  @j  tabulation\n"
"\n";
#endif

// ============================= Mdate messages ===========================

const char* FR_MSG_CERR = "Mdate: `--correlation' (`-c') a �t� utilis� plus d'une fois\n";
const char* FR_MSG_DERR = "Mdate: `--dmy' (`-d') a �t� utilis� plus d'une fois\n";
const char* FR_MSG_JERR = "Mdate: `--julian' (`-j') a �t� utilis� plus d'une fois\n";
const char* FR_MSG_LERR = "Mdate: `--longcount' (`-l') a �t� utilis� plus d'une fois\n";
const char* FR_MSG_OPTERR = "Mdate: option inconnue: ";
const char* FR_MSG_NONOPTERR = "Trop d'arguments qui ne sont pas des options�!\n";
const char* FR_MSG_LONGERR = "Le compte long sp�cifi� n'est pas valable�!\n";
const char* FR_MSG_GENERR = "erreur�!\n";
const char* FR_MSG_ILC = "Ce compte long n'est pas valable�!\n";
const char* FR_MSG_IGD = "Cette date gr�gorienne n'est pas valable�!\n";
const char* FR_MSG_IJDN = "Cette date au calendrier julien n'est pas valable�!\n";
const char* FR_MSG_FORMATERR = "Format inconnu�!\n";

// ============================= Mdate formats ============================

static char fr_pretty_format[] __attribute__ ((unused)) =
"\n"
"Jour gr�gorien : @d-@B-@Y (@d/@m/@Y)\n"
"Jour julien    : @J\n"
"Compte long    : @l\n"
"Date Tzolkin   : @T\n"
"Date Haab      : @h\n";


static char fr_default_format[] __attribute__ ((unused)) = "JDN: @J date: @d @m @Y  @l @T @H";

// ============================= Mdate days ===============================

static const char *fr_short_days[] __attribute__ ((unused)) = {
	"Lun","Mar","Mer","Jeu","Ven","Sam","Dim"
};

static const char *fr_days[] __attribute__ ((unused)) = {
	"Lundi","Mardi","Mercredi","Jeudi","Vendredi","Samedi","Dimanche"
};
