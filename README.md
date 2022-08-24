# mini-generador-lexico
![image](https://user-images.githubusercontent.com/74196278/186326166-613955e7-bd31-432b-8c0e-5d2a0b638b7c.png)
![image](https://user-images.githubusercontent.com/74196278/186326262-ad33a193-f23c-469f-bfc5-f672cba93bda.png)

¿Qué es un analizador léxico?
Un analizador léxico es un programa informático que divide un flujo de texto en fichas y marca sus tipos. Toma la entrada como una secuencia de caracteres arbitrariamente larga, denominada cadena de entrada, y la salida como una secuencia de uno o más caracteres, denominada secuencia de token.
El resultado puede ser una secuencia de tokens o suficiente información para identificarlos de forma única.
Además, un analizador léxico generalmente se implementa como dos programas separados: uno que lee caracteres del flujo de entrada y el otro que genera tokens para cada palabra que encuentra.
Los analizadores léxicos se utilizan principalmente para identificar errores en archivos de texto, como errores ortográficos o errores gramaticales. También se utiliza para detectar ciertos patrones en el lenguaje natural que podrían considerarse dañinos o peligrosos si ocurrieran en la vida real.

El propósito del analizador léxico es:
1.	Identifique tokens en el flujo de texto de entrada y agrúpelos en categorías significativas.
2.	Proporciona información sobre cada token, como su tipo y valor, lo que ayuda a comprender el significado del texto de entrada.
3.	Analiza el texto de entrada dividiéndolo en unidades de significado más pequeñas para facilitar el análisis.
Categorías léxicas
Palabras clave Palabras con un significado concreto en el lenguaje. Ejemplos de palabras clave en C son while, if, return. . . Cada palabra clave suele corresponder a una categoría léxica. Habitualmente, las palabras clave son reservadas. Si no lo son, el analizador léxico necesitara información del sintético para resolver la ambigüedad. ¨
Identificadores Nombres de variables, nombres de función, nombres de tipos definidos por el usuario, etc. Ejemplos de identificadores en C son i, x10, valor leído. . .
Operadores Símbolos que especifican operaciones aritméticas, lógicas, de cadena, etc. Ejemplos de operadores en C son +, *, /, %, ==, !=, &&. . .
Constantes numéricas Literales que especifican valores numéricos enteros (en base decimal, octal, hexadecimal. . . ), en coma flotante, etc. Ejemplos de constantes numéricas en C son 928, 0xF6A5, 83.3E+2. . .
Constantes de carácter o de cadena Literales que especifican caracteres o cadenas de caracteres. Un ejemplo de literal de cadena en C es "una cadena"; ejemplos de literal de carácter son ’x’, ’\0’. . . Símbolos especiales Separadores, delimitadores, terminadores, etc. Ejemplos de estos símbolos en C son {, }, ;. . . Suelen pertenecer cada uno a una categoría léxica separada.
Hay tres categorías léxicas que son especiales:
Comentarios Información destinada al lector del programa. El analizador léxico los elimina.
Blancos En los denominados “lenguajes de formato libre” (C, Pascal, Lisp, etc.) los espacios en blanco, tabuladores y saltos de línea solo sirven para separar componentes léxicos. En ese caso, el analizador léxico se limita a suprimirlos. En otros lenguajes, como Python, no se pueden eliminar totalmente.
Fin de entrada Se trata de una categoría ficticia emitida por el analizador léxico para indicar que no queda ningún componente pendiente en la entrada.


A continuación, se listan los símbolos que deberá reconocer el analizador léxico de tu proyecto:
Identificadores= letra (letra|digito)*
Entero= digito+
Real= entero.entero
Operador de adición: + | -
Operador de multiplicación: * | /
Operador de asignación: =
Operador relacional: < | > | <= | >= | != | ==
Operador And: &&
Operador Or: ||
Operador Not: !
Parentesis: ( , )
Llave: { , }
Punto y coma: ;

Además de las siguientes palabras reservadas: if, while, return, else, int, float
Los valores de tipo que deberá regresar tu analizador para cada símbolo son los siguientes:
Símbolo	Tipo	
identificador	0	Id
entero	1	Int
real	2	Float
cadena	3	Char
Tipo	4	int,float,void
opSuma	5	+,-
opMul	6	*,/
opRelac	7	<,<=,>,>=
opOr	8	||
opAnd	9	&&
opNot	10	!
opigualdad	11	==, !=
;	12	;
,	13	,
(	14	(
)	15	)
{	16	{
}	17	}
=	18	=
if	19	If
while	20	While
return	21	Ret
else	22	Else
$	23	$

Los valores del tipo deben coincidir con la columna donde se encuentre cada símbolo en la tabla
LR(1). Consultar los archivos compilador09b.xlsx y compilador09b.inf que se encuentran en los
archivos de la gramática del compilador.
