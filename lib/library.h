#ifndef _LIBRARY_H
#define _LIBRARY_H

/* Including libs to the project. */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"
#include "locale.h"
#include "unistd.h"
#include "time.h"

/* Defining some constants. */
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAIL 0
#define EQUAL 0
#define BIGGER 999
#define SMALLER -999

/* Bag Structure */
struct _bag {
	char word[50];
};

/* Federal Council of Dentistry - City Record/Structure */
struct _cfoCity {
	int line;
	char city[50];
	struct _cfoCity *right;
	struct _cfoCity *left;
};

/* Federal Council of Dentistry - Overall Records/Structure */
struct _cfoTotal {
	int line;
	int total;
	char UF[10];
	struct _cfoTotal *right;
	struct _cfoTotal *left;
};

/* Federal Council of Dentistry - Quantity of Dental Surgeons/Strucure */
struct _cfoCDs {
	int line;
	int cds;
	struct _cfoCDs *right;
	struct _cfoCDs *left;
};

/* Defining the structures types. */
typedef struct _bag BAG[11];
typedef struct _cfoCity CITY;
typedef struct _cfoCity *CFO_CITY;
typedef struct _cfoTotal TOTAL;
typedef struct _cfoTotal *CFO_TOTAL;
typedef struct _cfoCDs CDs;
typedef struct _cfoCDs *CFO_CDs;

/* Commom usage functions. */
int seekLine (FILE *infile, int lineNumber, char *line);
void removeLineBreak (char *string);
void readString (char *string);
void cleanReadBuffer ();
int interface ();
int orderMenu ();
void menu (int option, CFO_CITY *cityRoot, CFO_CDs *cdsRoot, CFO_TOTAL *totalRoot);

/* City usage functions. */
CFO_CITY *createCityBinaryTree ();
void releaseCity (CITY *vertex);
void releaseBinaryTreeCity (CFO_CITY *root);
void searchLineCity (CFO_CITY *root);
void queryCityBinaryTree (CFO_CITY *root, char *city);
void printTreeOrderedByCity (CFO_CITY *root);
int insertVertexsOrderedByCity (CFO_CITY *root, int line, char *city);
int createOrderedBinaryTreeByCity (CFO_CITY *root);

/* Total usage functions. */
CFO_TOTAL *createTotalBinaryTree ();
void releaseTotal (TOTAL *vertex);
void releaseBinaryTreeTotal (CFO_TOTAL *root);
void searchLineTotal (CFO_TOTAL *root);
int queryUFBinaryTree (CFO_TOTAL *root, char *UF);
void printTreeInOrderOfTotal (CFO_TOTAL *root);
void printTreeInDownwardOrder (CFO_TOTAL *root, char *UF);
int insertVertexsOrderedByTotal (CFO_TOTAL *root, int line, char *UF, int total);
int createOrderedBinaryTreeByTotal (CFO_TOTAL *root);

/* CDs usage functions. */
CFO_CDs *createCDsBinaryTree ();
void releaseCDs (CDs *vertex);
void releaseBinaryTreeCDs (CFO_CDs *root);
void searchLineCDs (CFO_CDs *root);
void printTreeOrderedByCDs (CFO_CDs *root);
int insertVertexsOrderedByCDs (CFO_CDs *root, int line, int cds);
int createOrderedBinaryTreeByCDs (CFO_CDs *root);

#endif