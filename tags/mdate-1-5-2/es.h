// Translation of mdate to Castilian (Spanish)
// This file is distributed under the same license as the mdate package.
// Copyright (C) 1998-2003 Sean Dwyer <ewe2@users.sourceforge.net>
// Quique <quique@sindominio.net>, 2003, 2004
//
// version 1.5.1

// ============================= Mdate help ===============================

#ifdef STATIC_HELP
static char es_helptext[] __attribute__ ((unused)) =
"\n"
"Mdate muestra fechas mayas simples.\n"
"Sintaxis: mdate [OPCI�N]... [+FORMATO]\n"
"   -h, --help                Muestra este mensaje de ayuda y acaba.\n"
"   -V, --version             Muestra la versi�n del programa y acaba.\n"
"   -p, --parseable           Salida analizable por un programa\n"
"                             (por omisi�n: desactivado).\n"
"   -g, --gmt                 Usa la correlaci�n Goodman-Mart�nez-Thompson.\n"
"                             (por omisi�n: desactivado).\n"
"   -L, --lang=IDIOMA         Cambia de idioma (por omisi�n: en).\n"
"   -c, --correlation=DOBLE   Correlaci�n opcional (por omisi�n: no).\n"
"   -d, --dmy=CADENA          D�a mes a�o (gregoriano).\n"
"   -j, --julian=DOBLE        N�mero de d�a juliano.\n"
"   -l, --longcount=CADENA    Cuenta larga.\n"
"\n"
"Se aceptan los siguientes identificadores de IDIOMA:\n"
"  en Ingl�s\n"
"  es Castellano\n"
"  pl Polaco\n"
"  de Alem�n\n"
"  fr Franc�s\n"
"\n"
"Se aceptan los siguientes identificadores de FORMATO:\n"
"  @a nombre del d�a de la semana abreviado\n"
"  @A nombre del d�a de la semana completo\n"
"  @b nombre del mes abreviado\n"
"  @B nombre del mes completo\n"
"  @d d�a del mes (01 - 31)\n"
"  @e d�a del mes sin cero inicial\n"
"  @F fecha gregoriana en formato ISO (%Y-%m-%d)\n"
"  @f fecha gregoriana en formato ISO (%Y%m%d)\n"
"  @h fecha Haab sin relleno\n"
"  @H fecha Haab con relleno\n"
"  @l cuenta larga\n"
"  @M nombre del mes gregoriano\n"
"  @m n�mero del mes gregoriano\n"
"  @t fecha Tzolkin con relleno\n"
"  @T fecha Tzolkin sin relleno\n"
"  @y a�o como decimal de 00 a 99\n"
"  @Y a�o gregoriano\n"
"  @n a�adir un salto de l�nea a la salida\n"
"  @j a�adir un tabulador a la salida\n"
"\n";
#endif

// ============================= Mdate messages ===========================

const char* ES_MSG_CERR = "Mdate: La opci�n `--correlation' (`-c') aparece m�s de una vez.\n";
const char* ES_MSG_DERR =  "Mdate: La opci�n `--dmy' (`-d') aparece m�s de una vez.\n";
const char* ES_MSG_JERR = "Mdate: La opci�n `--julian' (`-j') aparece m�s de una vez.\n";
const char* ES_MSG_LERR = "Mdate: La opci�n `--longcount' (`-l') aparece m�s de una vez.\n";
const char* ES_MSG_OPTERR = "Mdate: Opci�n desconocida: ";
const char* ES_MSG_NONOPTERR = "Demasiados argumentos que no eran opciones.\n";
const char* ES_MSG_LONGERR = "La cuenta larga producida por esta fecha no es v�lida.\n";
const char* ES_MSG_GENERR = "�Error!\n";
const char* ES_MSG_ILC = "La cuenta larga introducida no es v�lida.\n";
const char* ES_MSG_IGD = "La fecha gregoriana introducida no es v�lida.\n";
const char* ES_MSG_IJDN = "El n�mero de d�a juliano introducido no es v�lido.\n";
const char* ES_MSG_FORMATERR = "�Formato desconocido!\n";

// ============================= Mdate formats ============================

static char es_pretty_format[] __attribute__ ((unused)) =
"\n"
"Fecha gregoriana      : @d-@B-@Y (@d/@m/@Y)\n"
"N�mero de d�a juliano : @J\n"
"Cuenta larga          : @l\n"
"Fecha Tzolkin         : @T\n"
"Fecha Haab            : @h\n";

static char es_default_format[] __attribute__ ((unused)) = "NDJ: @J fecha: @d @m @Y  @l @T @H";

// ============================= Mdate days ===============================

static const char *es_short_days[] __attribute__ ((unused)) = {
	"lun","mar","mi�","jue","vie","s�b","dom"
};

static const char *es_days[] __attribute__ ((unused)) = {
	"lunes","martes","mi�rcoles","jueves","viernes","s�bado","domingo"
};
