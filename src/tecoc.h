/*****************************************************************************
	Tecoc.h

	This file contains most of the definitions needed by TECO-C files.
*****************************************************************************/

#define TVERSION 146		/* version number of TECO-C */

/*****************************************************************************
	Bit masks for ED mode control flag.  The ones that are commented out
are not used in TECO-C.  They are included here because they are used by
TECO-11, and may be implemented in TECO-C someday.

*****************************************************************************/

#define ED_CARET_OK	1	/* don't use "^" as control-char prefix */
#define ED_YANK_OK	2	/* let yanks clear text buffer */
/*#define ED_NO_EXP	4*/	/* don't allow arbitrary expansions */
#define ED_PRES_DOT	16	/* preserve "dot" on failing searches */
/*#define ED_IMMED_OK	32*/	/* allow immediate escape-sequence commands */
#define ED_DOT_BY_ONE	64	/* move dot by one on iter. search failure */
/*#define ED_NO_W	128*/	/* don't do automatic "^W" before prompt */
#define ED_FF           128     /* do not stop read on FF */
#if defined(unix) || defined(AMIGA)
#define ED_UNIXNL	256	/* use Unix-style newline line terminators */
#endif
#define ED_VTGR		512
#define ED_NOSCDEL	1024	/* old style delete handler */
#define ED_BTEE		2048	/* use BTEE instead of DIAMOND */
#define ED_STDOUT	4096	/* use standout for doeves pointer */
#define ED_INVCR	8192	/* don't show CR in scope - closer to TECO-11
	but really not as good in my opinion (Mark Henderson)*/

/*****************************************************************************
	Value for EH flag.
*****************************************************************************/

#define EH_COMMAND	4	/* on error,  output failing command string */

/*****************************************************************************
	Bit masks for ET mode control flag.  The ones that are commented out
are not used in TECO-C.  They are included here because they are used by
TECO-11.  The 2048 bit is listed as "reserved for TECO-8" in the TECO-11
source code.  I needed another bit, so I used it.
*****************************************************************************/

#define ET_IMAGE_MODE	1	/* output without doing conversions */
#define ET_SCOPE	2	/* use scope for delete and control-U */
#define ET_READ_LOWER	4	/* accept lowercase input */
#define ET_NO_ECHO	8	/* don't echo input on control-T */
/*#define ET_CAN_CTRL_O	16*/	/* (TECO-11) cancel control-O on output */
#define ET_NO_WAIT	32	/* read with no wait on control-T */
/*#define ET_DETACH	64*/	/* process detached flag */
#define ET_MUNG_MODE	128	/* mung mode */
/*#define ET_TRUNCATE	256*/	/* (TECO-11) truncate lines on output */
#define ET_WAT_SCOPE	512	/* "WATCH" code exists, terminal is scope */
#define ET_WAT_REFRESH	1024	/* "WATCH" code exists, terminal is refresh */
#define ET_BKSP_IS_DEL	2048	/* treat BACKSPACE like DEL on input */
#define ET_EIGHTBIT	4096	/* it's an eight-bit terminal */
#define ET_ACCENT_GRAVE	8192	/* accept ` as escape (for VT220 terminals) */
#define ET_VT200	16384	/* special VT200 mode */
#define ET_TRAP_CTRL_C	0100000	/* trap control-C */

/*****************************************************************************
	Values for EU flag.
*****************************************************************************/

#define EU_NONE		-1	/* no case flagging of any type */
#define EU_LOWER	0	/* flag lowercase characters on output */
#define EU_UPPER	1	/* flag uppercase characters on output */

/*****************************************************************************
	These identifiers are bit masks for elements of the ChrMsk array.
The ChrMsk array is used by the macros defined in the ChrMac.h file and by
the ReadCS function to make the character input code fast.  See the comment
above the definition of the ChrMsk array in file TECOC.C.
*****************************************************************************/

#define RCS_AST		'\1'	/* asterisk */
#define RCS_BS		'\2'	/* backspace */
#define RCS_CCH		'\3'	/* control char other than ^G, ^U or ^Z */
#define RCS_CR		'\4'	/* carriage return */
#define RCS_CTG		'\5'	/* control-G */
#define RCS_CTU		'\6'	/* control-U */
#define RCS_CTZ		'\7'	/* control-Z */
#define RCS_DEF		'\10'	/* char other than RCS_AST, RCS_BS, etc. */
#define RCS_DEL		'\11'	/* delete */
#define RCS_GRV		'\12'	/* accent grave */
#define RCS_LF		'\13'	/* line feed */
#define RCS_LWR		'\14'	/* lowercase character */
#define RCS_SP		'\15'	/* space */
#define RCS_VF		'\16'	/* vertical tab or form feed */
#define RCS_CTC		'\17'	/* control-C */
#define CM_DIGIT	'\20'	/* digits */
#define CM_LINE_TERM	'\40'	/* line terminators (lf, vt, ff) */
#define CM_LOWER	'\100'	/* lowercase */
#define CM_UPPER	'\200'	/* uppercase */

/*****************************************************************************
	These identifiers are set by the search commands.  They provide a way
for the search commands to all rely on common code,  even when the commands
behave slightly differently.  It's a terrible way to code,  but it was only
done in the search code.
*****************************************************************************/

#define E_SEARCH  1	/* E_ command */
#define FB_SEARCH 2	/* FB command */
#define FK_SEARCH 3	/* FK command */
#define N_SEARCH  4	/* N command */
#define S_SEARCH  5	/* S command */
#define U_SEARCH  6	/* _ command */

/*****************************************************************************
	Identifiers for indices into the IFiles and OFiles arrays.
*****************************************************************************/

#define	NOFDBS	3	/* number of output file data blocks */

#define	POUTFL	0	/* primary output stream */
#define	SOUTFL	1	/* secondary output stream */
#define	EPRCFL	2	/* output stream used by E% command */

#define	PINPFL	0	/* primary input stream */
#define	SINPFL	1	/* secondary input stream */
#define	EQFL	2	/* input stream used by EQ command */
#define EIFL	3	/* first input stream used by EI command */

/*****************************************************************************
	Identifiers for :EG special function types.
*****************************************************************************/

#define EG_INI		1	/* inititalization macro */
#define EG_LIB		2	/* default macro library directory */
#define EG_MEM		3	/* last-file-edited memory */
#define EG_VTE		4	/* filename of video macro */
#define EG_OTHER	5	/* system-specific :EG command */
#define CLEAR_VAL	1
#define GET_VAL		2
#define SET_VAL		3

/*****************************************************************************
	Function return codes.
*****************************************************************************/

#define FAILURE   (-1)	/* function return status */
#define SUCCESS   0	/* function return status */
#define FILENF    3	/* "file not found", returned by ZSWild and ZOpInp */

/*****************************************************************************
	CmdMod Bits.
*****************************************************************************/

#define ATSIGN    '\1'	/* mask of "at sign" bit in CmdMod */
#define COLON     '\2'	/* mask of "colon" bit in CmdMod */
#define DCOLON    '\4'	/* mask of "double colon" bit in CmdMod */
#define MARGIS    '\10'	/* mask of "m defined" bit in CmdMod */

/*****************************************************************************
	Arguments to ZSetTT function.
*****************************************************************************/

#define TT8BIT	 1	/* whether terminal can handle 8-bit characters */
#define TTWIDTH  2	/* number of columns of charactes */
#define TTHEIGHT 3	/* number of rows of characters */

/*****************************************************************************
	Miscellaneous identifiers.
*****************************************************************************/

#define FFLINS    5	/* number of blank lines displayed for form feed */
#define INFINITE  -1L	/* loop count value for infinite loops */

#define PRIMARY   '\0'	/* primary input or output stream specifier */
#define SECNDARY  '\1'	/* secondary input or output stream specifier */

#define OPERAND   0	/* means element is an integer */
#define OPERATOR  1	/* means element is + - * / & or | */

#define LOWER     0	/* case conversion mode specifier, for ^V, ^W */
#define NONE      1	/* case conversion mode specifier */
#define UPPER     2	/* case conversion mode specifier, for ^V, ^W */

/*****************************************************************************
	define structure for expression stack
*****************************************************************************/

struct EStck {
	long Elemnt;		/* integer or operand character */
	int ElType;		/* Entry's type: OPERATOR or OPERAND */
};

/*****************************************************************************
	define structure for loop stack
*****************************************************************************/

struct LStck {
	long	LIndex;		/* loop repetition count */
	charptr LAddr;		/* pointer to start of loop in command buf */
};

/*****************************************************************************
	define structure for q-registers
*****************************************************************************/

struct QReg  {
	charptr	Start;		/* start of text */
	charptr	End_P1;		/* end of text, plus one */
	long	Number;		/* numeric part of q-register */
};

/*****************************************************************************
	define structure for macro stack
*****************************************************************************/

struct MStck {
	charptr	CStBeg;		/* saves CStBeg */
	charptr	CBfPtr;		/* saves CBfPtr */
	charptr	CStEnd;		/* saves CStEnd */
	WORD	EStBot;		/* saves EStBot */
	WORD	EStTop;		/* saves EStTop */
	WORD	LStBot;		/* saves LStBot */
	WORD	LStTop;		/* saves LStTop */
	QRptr	QRgstr;		/* local q-register table */
};

/*****************************************************************************
	Debugging macros
*****************************************************************************/

#if DEBUGGING
#define DBGFEN(lv,fnm,msg) static char *DbgFNm = fnm; DbgFEn(lv, DbgFNm, msg)
#define DBGFEX(lv,fnm,msg) DbgFEx(lv, fnm, msg)
#define DBGFMS(lv,fnm,msg) DbgFMs(lv, fnm, msg)
#else
#define DBGFEN(lv,fnm,msg)
#define DBGFEX(lv,fnm,msg)
#define DBGFMS(lv,fnm,msg)
#endif

/*****************************************************************************
	function definitions
*****************************************************************************/

#if USE_PROTOTYPES

#if CHECKSUM_CODE
void	init_code_checksums(void);
void	check_code_checksums(void);
#endif

#if CONSISTENCY_CHECKING
void	init_consistency_check(void);
void	check_consistency(void);
#endif

int	BakSrc(void);		/* backwards search to match 1st character */
integer BldStr(			/* build a string */
	charptr XBfBeg,		/* beginning of build-string buffer */
	charptr XBfEnd,		/* end of build-string buffer */
	charptr (*XBfPtr));	/* pointer into build-string buffer */
void	ClenUp(void);		/* clean up for TECO-C abort */
integer	CMatch(			/* match a character */
	bool *SamChr);	/* returned match indicator */
#if DEBUGGING
integer	DbgDsp(void);		/* debugging, control debugging display (^P) */
void	DbgFEn(			/* debugging, function entry */
	int DbgFLv,             /*   function display level */
	char *DbgFNm,		/*   function name */
	char *DbgMsg);		/*   an entry message, usually parameters */
void	DbgFEx(			/* debugging, function exit */
	int DbgFLv,		/*   function display level */
	char *DbgFNm,		/*   function name */
	char *DbgMsg);		/*   an exit message, usually return value */
void	DbgFMs(			/* debugging, function message */
	int DbgFLv,		/*   function display level */
	char *DbgFNm,		/*   function name */
	char *DbgMsg);		/*   an message */
#endif
integer	DoCJR(			/* do C, J or R stuff */
	long HowFar);		/* positive or negative displacement */
void	DoEvEs(			/* do an EV or ES mode control flag function */
	WORD Flag);
integer	DoFlag(			/* handle mode control flag */
	WORD *Flag);
void	EchoIt(			/* echo a character to to terminal */
	unsigned char Charac);
void	ErrChr(			/* display error message with character arg */
	WORD ErrNum,		/* the error number */
	unsigned char EChr);	/* character to imbed in message */
void	ErrMsg(			/* display error message */
	WORD ErrNum);		/* the error number */
void	ErrPSt(			/* display error message with string arg */
	WORD ErrNum,		/* the error number */
	charptr EBeg,		/* string to imbed in message */
	charptr EPtr);		/* ptr to end-of-string, plus one */
void	ErrStr(			/* display error message with string arg */
	WORD ErrNum,		/* the error number */
	char *EStr);		/* string to imbed in message */
void	ErrUTC(void);		/* unterminated command or macro */
void	ErrVrb(			/* display a verbose error message */
	WORD ErrNum);		/* error message number */
integer	ExeA(void);		/* execute an A command */
integer	ExeAtS(void);		/* execute an at-sign (@) command */
integer	ExeB(void);		/* execute a B command */
integer	ExeBar(void);		/* execute a bar (|) command */
integer	ExeBSl(void);		/* execute a backslash (\) command */
integer	ExeC(void);		/* execute a C command */
integer	ExeCCC(void);		/* execute a control-^ command */
integer	ExeCln(void);		/* execute a colon (:) command */
integer	ExeCom(void);		/* execute a comma (,) command */
integer	ExeCrt(void);		/* execute a caret (^) command */
integer	ExeCSt(void);		/* execute a command string */
integer	ExeCtA(void);		/* execute a control-A command */
integer	ExeCtC(void);		/* execute a control-C command */
integer	ExeCtD(void);		/* execute a control-D command */
integer	ExeCtE(void);		/* execute a control-E command */
integer	ExeCtI(void);		/* execute a control-I (tab) command */
integer	ExeCtL(void);		/* execute a control-L (form feed) command */
integer	ExeCtN(void);		/* execute a control-N command */
integer	ExeCtO(void);		/* execute a control-O command */
integer	ExeCtP(void);		/* execute a control-P command */
integer	ExeCtQ(void);		/* execute a control-Q command */
integer	ExeCtR(void);		/* execute a control-R command */
integer	ExeCtS(void);		/* execute a control-S command */
integer	ExeCtT(void);		/* execute a control-T command */
integer	ExeCtU(void);		/* execute a control-U command */
integer	ExeCtV(void);		/* execute a control-V command */
integer	ExeCtW(void);		/* execute a control-W command */
integer	ExeCtX(void);		/* execute a control-X command */
integer	ExeCtY(void);		/* execute a control-Y command */
integer	ExeCtZ(void);		/* execute a control-Z command */
integer	ExeD(void);		/* execute a D command */
integer	ExeDgt(void);		/* execute a digit command */
integer	ExeDot(void);		/* execute a dot (.) command */
integer	ExeDQu(void);		/* execute a double-quote (") command */
integer	ExeE(void);		/* execute on of the E commands */
integer	ExeEqu(void);		/* execute an equals-sign (=) command */
integer	ExeEsc(void);		/* execute an ESCAPE command */
integer	ExeExc(void);		/* execute an exclamation-mark (!) command */
integer	ExeEY(void);		/* execute an EY command */
integer	ExeF(void);		/* execute one of the F commands */
integer	ExeFB(void);		/* execute an FB command */
integer	ExeG(void);		/* execute a G command */
integer	ExeGtr(void);		/* execute a greater-than (>) command */
integer	ExeH(void);		/* execute an H command */
integer	ExeI(void);		/* execute an I command */
integer	ExeIll(void);		/* execute an "illegal" command */
integer	ExeJ(void);		/* execute a J command */
integer	ExeK(void);		/* execute a K command */
integer	ExeK(void);		/* execute a K command */
integer	ExeL(void);		/* execute an L command */
integer	ExeLBr(void);		/* execute a left-bracket ([) command */
integer	ExeLst(void);		/* execute a less-than (<) command */
integer	ExeM(void);		/* execute an M command */
integer	ExeN(void);		/* execute a N command */
integer	ExeNul(void);		/* execute a null command */
integer	ExeNYI(void);		/* "not yet implemented" function */
integer	ExeO(void);		/* execute an O command */
integer	ExeOpr(void);		/* execute a operator (+,-,*, etc.) command */
integer	ExeP(void);		/* execute a P or PW command */
integer	ExePrc(void);		/* execute a percent {%} command */
integer	ExePW(void);		/* execute a PW command */
integer	ExeQ(void);		/* execute a Q command */
integer	ExeQes(void);		/* execute a question-mark (?) command */
integer	ExeR(void);		/* execute an R command */
integer	ExeRBr(void);		/* execute a right-bracket (]) command */
integer	ExeRtP(void);		/* execute a right-parenthesis command */
integer	ExeS(void);		/* execute an S command */
integer	ExeSCl(void);		/* execute a semi-colon (;) command */
integer	ExeT(void);		/* execute a T command */
integer	ExeU(void);		/* execute a U command */
integer	ExeUnd(void);		/* execute an underbar (_) command */
integer	ExeUsc(void);		/* execute control-_ command */
integer	ExeV(void);		/* execute a V command */
integer	ExeW(void);		/* execute a W command */
integer	ExeX(void);		/* execute a X command */
integer	ExeY(void);		/* execute a Y command */
integer	ExeZ(void);		/* execute a Z command */
integer	FindES(			/* find end of string */
	unsigned char TrmChr);	/* termination char if no @ modifier */
integer	FindQR(void);		/* find a q-register index */
integer	FlowEC(void);		/* flow to end of conditional */
integer	FlowEE(void);		/* flow to | or ' */
integer	FlowEL(void);		/* flow to end of loop */
integer	GetAra(void);		/* get m,n area */
integer	GetNmA(void);		/* get numeric argument */
integer	IncCBP(void);		/* increment CBfPtr */
void	Init(			/* initialize TECO-C */
	int argc,
	char *argv[]);
integer	InsStr(			/* insert string into edit buffer */
	charptr string,
	ptrdiff_t length);
bool	IsRadx(			/* is the character in the radix set? */
	unsigned char Charac);
long	Ln2Chr(			/* convert line offset to character offset */
	long Value);
void	MakDBf(			/* make digit buffer */
	long Binary,		/* binary number to be converted */
	integer NRadix);	/* radix to be used: 8, 10 or 16 */
integer	MakRom(			/* make room in q-register */
	SIZE_T Amount);		/* how much room to make */
integer	PopMac(void);		/* pop variables after macro call */
integer	PshMac(			/* push variables for macro call */
	charptr Start,		/* start of new command string */
	charptr End);		/* end of new command string, plus one */
integer	PushEx(			/* push onto expression stack */
	long Item,
	integer EType);
integer	RdLine(			/* read a line */
	bool *EBfFul);	/* returned "edit buffer is full" indicator */
integer	RdPage(void);		/* read a page from a file */
void	ReadCS(void);		/* read command string */
integer	Replac(void);		/* replace a string */
integer	Search(			/* top level search */
	bool	RepCmd);	/* true if the command has two arguments */
integer	SinglP(void);		/* execute a single P function */
integer	SkpCmd(void);		/* skip a single command */
integer	SrcLop(void);		/* search loop */
integer	SSerch(void);		/* single search */
void	TAbort(			/* terminate TECO-C */
	integer tstat);
void	TypBuf(			/* type a buffer on the terminal */
	charptr YBfBeg,
	charptr YBfEnd);
void	TAbort(			/* cleanup for TECO-C abort */
	integer tstat);
void	TypESt(void);		/* type error string on terminal */
void	UMinus(void);		/* handle unary minus */
integer	WrPage(			/* write to output file */
	integer	OfIndx,		/* index into OFiles array */
	charptr OBfBeg,		/* address of output buffer beginning */
	charptr OBfEnd,		/* address of output buffer end */
	long AddFF);		/* -1 means add form feed, 0 means don't */
voidptr ZAlloc(			/* like standard malloc function */
	SIZE_T MemSiz);
void	ZBell(void);		/* ring the terminal bell */
integer ZChIn(			/* input a character from the terminal */
	bool	NoWait);	/* return immediately? */
long	ZClnEG(			/* execute special :EG command */
	integer EGWhat,		/* what to get/set/clear: MEM, LIB, etc. */
	integer EGOper,		/* operation: get, set or clear */
	charptr TxtPtr);	/* if setting,  value to set */
void	ZClnUp(void);		/* cleanup for TECO-C abort */
#if DEBUGGING || CONSISTENCY_CHECKING
ULONG	Zcp2ul(			/* convert voidptr to unsigned long */
	voidptr cp);
#endif
void	ZDoCmd(			/* terminate and pass command string to OS */
	charptr GBfBeg,
	charptr GBfPtr);	
void	ZDspBf(			/* output a buffer to the terminal */
	charptr buffer,
	SIZE_T length);
void	ZDspCh(			/* display a character */
	char Charac);
integer	ZExCtB(void);		/* execute a ^B command */
integer	ZExCtH(void);		/* execute a ^H command */
integer	ZExeEJ(void);		/* execute an EJ command */
void	ZExit(			/* terminate TECO-C */
	integer estat);
void	ZFree(			/* like standard free() function */
	voidptr pointer);
integer	ZFrSrc(void);		/* forward search to match 1st character */
void	ZHelp(			/* display a help message */
	charptr HlpBeg,		/* first char of help request */
	charptr HlpEnd,		/* last character of help request */
	bool SysLib,		/* use default HELP library? */
	bool	Prompt);	/* enter interactive help mode? */
void	ZIClos(			/* close input file */
	integer	IfIndx);	/* index into IFiles array */
void	ZOClDe(			/* close and delete output file */
	integer	OfIndx);	/* index into OFiles array */
void	ZOClos(			/* close output file */
	integer	OfIndx);	/* index into OFiles array */
integer	ZOpInp(			/* open input file */
	integer IfIndx,		/* index into file data block array IFiles */
	bool	EIFile,		/* is it a macro file? (hunt for it) */
	bool RepFNF);	/* report "file not found" error? */
integer ZOpOut(			/* open output file */
	integer	OfIndx,		/* output file indicator */
	bool RepErr,		/* report errors? */
	bool Backup);	/* create backup? TAA MOD */
void	ZPrsCL(			/* parse the command line */
	int argc,
	char **argv);
integer	ZPWild(void);		/* preset the wildcard lookup filespec */
voidptr	ZRaloc(			/* re-allocate memory*/
	voidptr OldBlk,
	SIZE_T NewSiz);
integer ZRdLin(			/* read a line */
	charptr ibuf,		/* where to put string */
	ptrdiff_t ibuflen,	/* max length of buf */
	int IfIndx,		/* index into IFiles[] */
	integer *retlen);	/* returned length of string */
void	ZScrOp(			/* do a screen operation */
	int OpCode);		/* code for operation */
integer	ZSetTT(			/* set a terminal parameter */
	integer TTWhat,		/* what terminal parameter to set */
	integer TTVal);		/* new value for the terminal parameter */
integer	ZSWild(void);		/* search for next wildcard filename */
void	ZTrmnl(void);		/* open terminal input and output */
void	ZVrbos(			/* display verbose form of an error message */
	WORD ErrNum,		/* error number (see DEFERR.h) */
	char *ErMnem);		/* error mnemonic */
integer	ZWrBfr(			/* write a buffer */
	integer	OfIndx,		/* index into OFiles array */
	charptr BfrBeg,		/* address of output buffer beginning */
	charptr BfrEnd);	/* address of output buffer end */


#else				/* else (not USE_PROTOTYPES) */

#if CHECKSUM_CODE
void	init_code_checksums ();
void	check_code_checksums ();
#endif

#if CONSISTENCY_CHECKING
void	init_consistency_check();
void	check_consistency();
#endif

integer	BakSrc();	/* backwards search to match 1st character */
integer	BldStr();	/* build a string */
void	ClenUp();	/* clean up for TECO-C abort */
integer	CMatch();	/* match a character */
#if DEBUGGING
integer	DbgDsp();	/* debugging, control debugging display */
void	DbgFEn();	/* debugging, function entry */
void	DbgFEx();	/* debugging, function exit */
void	DbgFMs();	/* debugging, function message */
#endif
integer	DoCJR();	/* do C, J or R stuff */
void	DoEvEs();	/* do an EV or ES mode control flag function */
integer	DoFlag();	/* handle mode control flag */
void	EchoIt();	/* echo a character to to terminal */
void	ErrChr();	/* display error message with character argument */
void	ErrMsg();	/* display error message */
void	ErrPSt();	/* display error message with string argument */
void	ErrStr();	/* display error message with string argument */
void	ErrUTC();	/* unterminated command or macro */
void	ErrVrb();	/* display a verbose error message */
integer	ExeA();		/* execute an A command */
integer	ExeAtS();	/* execute an at-sign (@) command */
integer	ExeB();		/* execute a B command */
integer	ExeBar();	/* execute a bar (|) command */
integer	ExeBSl();	/* execute a backslash (\) command */
integer	ExeC();		/* execute a C command */
integer	ExeCCC();	/* execute a control-^ command */
integer	ExeCln();	/* execute a colon (:) command */
integer	ExeCom();	/* execute a comma (,) command */
integer	ExeCrt();	/* execute a caret (^) command */
integer	ExeCSt();	/* execute a command string */
integer	ExeCtA();	/* execute a control-A command */
integer	ExeCtC();	/* execute a control-C command */
integer	ExeCtD();	/* execute a control-D command */
integer	ExeCtE();	/* execute a control-E command */
integer	ExeCtI();	/* execute a control-I (tab) command */
integer	ExeCtL();	/* execute a control-L (form feed) command */
integer	ExeCtN();	/* execute a control-N command */
integer	ExeCtO();	/* execute a control-O command */
integer	ExeCtP();	/* execute a control-P command */
integer	ExeCtQ();	/* execute a control-Q command */
integer	ExeCtR();	/* execute a control-R command */
integer	ExeCtS();	/* execute a control-S command */
integer	ExeCtT();	/* execute a control-T command */
integer	ExeCtU();	/* execute a control-U command */
integer	ExeCtV();	/* execute a control-V command */
integer	ExeCtW();	/* execute a control-W command */
integer	ExeCtX();	/* execute a control-X command */
integer	ExeCtY();	/* execute a control-Y command */
integer	ExeCtZ();	/* execute a control-Z command */
integer	ExeD();		/* execute a D command */
integer	ExeDgt();	/* execute a digit command */
integer	ExeDot();	/* execute a dot (.) command */
integer	ExeDQu();	/* execute a double-quote (") command */
integer	ExeE();		/* execute on of the E commands */
integer	ExeEqu();	/* execute an equals-sign (=) command */
integer	ExeEsc();	/* execute an ESCAPE command */
integer	ExeExc();	/* execute an exclamation-mark (!) command */
integer	ExeEY();	/* execute an EY command */
integer	ExeF();		/* execute one of the F commands */
integer	ExeFB();	/* execute an FB command */
integer	ExeG();		/* execute a G command */
integer	ExeGtr();	/* execute a greater-than (>) command */
integer	ExeH();		/* execute an H command */
integer	ExeI();		/* execute an I command */
integer	ExeIll();	/* execute an "illegal" command */
integer	ExeJ();		/* execute a J command */
integer	ExeK();		/* execute a K command */
integer	ExeK();		/* execute a K command */
integer	ExeL();		/* execute an L command */
integer	ExeLBr();	/* execute a left-bracket ([) command */
integer	ExeLst();	/* execute a less-than (<) command */
integer	ExeM();		/* execute an M command */
integer	ExeN();		/* execute a N command */
integer	ExeNul();	/* execute a null command */
integer	ExeNYI();	/* "not yet implemented" function */
integer	ExeO();		/* execute an O command */
integer	ExeOpr();	/* execute a operator (+,-,*, etc.) command */
integer	ExeP();		/* execute a P or PW command */
integer	ExePrc();	/* execute a percent {%} command */
integer	ExePW();	/* execute a PW command */
integer	ExeQ();		/* execute a Q command */
integer	ExeQes();	/* execute a question-mark (?) command */
integer	ExeR();		/* execute an R command */
integer	ExeRBr();	/* execute a right-bracket (]) command */
integer	ExeRtP();	/* execute a right-parenthesis command */
integer	ExeS();		/* execute an S command */
integer	ExeSCl();	/* execute a semi-colon (;) command */
integer	ExeT();		/* execute a T command */
integer	ExeU();		/* execute a U command */
integer	ExeUnd();	/* execute an underbar (_) command */
integer	ExeUsc();	/* execute control-_ command */
integer	ExeV();		/* execute a V command */
integer	ExeW();		/* execute a W command */
integer	ExeX();		/* execute a X command */
integer	ExeY();		/* execute a Y command */
integer	ExeZ();		/* execute a Z command */
integer	FindES();	/* find end of string */
integer	FindQR();	/* find a q-register index */
integer	FlowEC();	/* flow to end of conditional */
integer	FlowEE();	/* flow to | or ' */
integer	FlowEL();	/* flow to end of loop */
integer	GetAra();	/* get m,n area */
integer	GetNmA();	/* get numeric argument */
integer	IncCBP();	/* increment CBfPtr */
void	Init();		/* initialize TECO-C */
integer	InsStr();	/* insert string into edit buffer */
bool	IsRadx();	/* is the character in the radix set? */
long	Ln2Chr();	/* convert line offset to character offset */
void	MakDBf();	/* make digit buffer */
integer	MakRom();	/* make room in q-register */
integer	PopMac();	/* pop variables after macro call */
integer	PshMac();	/* push variables for macro call */
integer	PushEx();	/* push onto expression stack */
integer	RdLine();	/* read a line */
integer	RdPage();	/* read a page from a file */
void	ReadCS();	/* read command string */
integer	Replac();	/* replace a string */
integer	Search();	/* top level search */
integer	SinglP();	/* execute a single P function */
integer	SkpCmd();	/* skip a single command */
integer	SrcLop();	/* search loop */
integer	SSerch();	/* single search */
void	TAbort();	/* terminate TECO-C */
void	TypBuf();	/* type a buffer on the terminal */
void	TypESt();	/* type error string on terminal */
void	UMinus();	/* handle unary minus */
integer	WrPage();	/* write to output file */
voidptr ZAlloc();	/* like standard malloc function */
void	ZBell();	/* ring the terminal bell */
integer ZChIn();	/* input a character from the terminal */
long	ZClnEG();	/* execute special :EG command */
void	ZClnUp();	/* cleanup for TECO-C abort */
#if DEBUGGING || CONSISTENCY_CHECKING
ULONG	Zcp2ul();	/* convert charptr to unsigned long */
#endif
void	ZDoCmd();	/* terminate and pass command string to OS */
void	ZDspBf();	/* output a buffer to the terminal */
void	ZDspCh();	/* display a character */
integer	ZExCtB();	/* execute a ^B command */
integer	ZExCtH();	/* execute a ^H command */
integer	ZExeEJ();	/* execute an EJ command */
void	ZExit();	/* terminate TECO-C */
void	ZFree();	/* like standard free() function */
integer	ZFrSrc();	/* forward search to match 1st character */
void	ZHelp();	/* display a help message */
void	ZIClos();	/* close input file */
void	ZOClDe();	/* close and delete output file */
void	ZOClos();	/* close output file */
integer	ZOpInp();	/* open input file */
integer ZOpOut();	/* open output file */
void	ZPrsCL();	/* parse the command line */
integer	ZPWild();	/* preset the wildcard lookup filespec */
voidptr	ZRaloc();	/* re-allocate memory*/
integer	ZRdLin();	/* read a line */
void	ZScrOp();	/* do a screen operation */
integer	ZSetTT();	/* set a terminal parameter */
integer	ZSWild();	/* search for next wildcard filename */
void	ZTrmnl();	/* open terminal input and output */
void	ZVrbos();	/* display verbose form of an error message */
integer	ZWrBfr();	/* write line to file */
#endif
#if CURSES
void Scope();
void centre();
void dolf();
void dobs();
void ccs();
void do_right();
void do_left();
void do_sf();
void do_sr();
void do_down();
void do_up();
void do_seetog();
void redraw();
void keypad_on();
void keypad_off();
#endif
