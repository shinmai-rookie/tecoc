/*****************************************************************************
	DefExt.h

	This header file declares as extern all the variables declared as
GLOBAL in Tecoc.c for use by everyone else.
*****************************************************************************/

extern	charptr	AraBeg;		/* beginning of text m,n area */
extern	charptr	AraEnd;		/* end of text m,n area */
extern	charptr	ArgPtr;		/* beginning of text argument */
extern	charptr	CBfBeg;		/* command buffer beginning */
extern	charptr	CBfEnd;		/* command buffer end */
extern	charptr	CBfPtr;		/* pointer into command string */
extern	char	CmdMod;		/* command modifiers flags for @, ;, etc. */
extern	integer	CrType;		/* value of 0:W (terminal type) */
extern	charptr	CStBeg;		/* command string beginning */
extern	charptr	CStEnd;		/* pointer to last char of command string */
extern	integer	CurInp;		/* index of current input stream in IFiles */
extern	integer	CurOut;		/* index of current output stream in OFiles */
extern	charptr	DBfBeg;		/* digit buffer beginning */
extern	charptr	DBfPtr;		/* digit buffer pointer */
#if DEBUGGING
extern  char	DbgSBf[];	/* debug message sprintf() buffer */
#endif
extern	charptr	EBfBeg;		/* edit buffer beginning */
extern	charptr	EBfEnd;		/* edit buffer end */
extern	charptr	EBPtr1;		/* pointer to start of found string */
extern	charptr	EBPtr2;		/* pointer to end of found string */
extern	WORD	EdFlag;		/* ED mode control flag */
extern	WORD	EhFlag;		/* EH mode control flag */
extern	charptr	EndSAr;		/* end of search area */
extern	char	ErrTxt[];	/* holds part of error message */
extern	WORD	EsFlag;		/* ES mode control flag */
extern	WORD	EStBot;		/* expression stack bottom */
extern	struct	EStck EStack[]; /* expression stack */
extern	WORD	EStTop;		/* expression stack top */
extern	WORD	EtFlag;		/* ET mode control flag */
extern	WORD	EuFlag;		/* EU mode control flag */
extern	WORD	EvFlag;		/* EV mode control flag */
extern	WORD	EzFlag;		/* EZ mode control flag */
extern	charptr	FBfBeg;		/* beginning of filename buffer */
extern	charptr	FBfEnd;		/* end of filename buffer */
extern	charptr	FBfPtr;		/* pointer into filename buffer */
extern	LONG	FFPage;		/* form feed flag (returned by ^E command) */
extern	charptr	GapBeg;		/* edit buffer gap beginning */
extern	charptr	GapEnd;		/* end of edit buffer gap */
extern volatile	bool GotCtC;	/* true if the user just hit a control-C */
extern	charptr	IBfEnd;		/* end of input buffer */
extern	charptr	IBfEnd;		/* input buffer end */
extern	int	IniSrM;		/* initial search mode */
extern	bool	IsEofI[];	/* input file has reached end of file */
extern	bool	IsOpnI[];	/* input file is opened indicators */
extern	bool	IsOpnO[];	/* output file is opened indicators */
extern	WORD	LStBot;		/* loop stack bottom */
extern	struct	LStck LStack[];	/* loop stack */
extern	struct	LStck LStack[]; /* loop stack */
extern	WORD	LstErr;		/* number of last error message */
extern	WORD	LStTop;		/* loop stack top */
extern	LONG	MArgmt;		/* m part of m,n numeric argument pair */
extern	bool	Matchd;		/* indicates successful search */
extern	struct	MStck MStack[]; /* macro stack */
extern	WORD	MStTop;		/* macro stack top */
extern	LONG	NArgmt;		/* numeric argument */
extern	QRptr	QR;		/* pointer to q-register structure */
extern	struct	QReg QRgstr[];	/* global q-registers */
extern	struct	QReg QStack[];	/* q-register stack */
extern	WORD	QStTop;		/* top of q-register stack */
extern	integer	Radix;		/* TECO-C's current radix, 2-36 */
extern	LONG	RefLen;		/* value returned by ^S command */
extern	charptr	RhtSid;		/* right-hand side of area to be searched */
extern	charptr	SBfBeg;		/* search string buffer beginning */
extern	charptr	SBfEnd;		/* search string buffer end */
extern	charptr	SBfPtr;		/* end of search string, plus one */
extern	LONG	SIncrm;		/* search increment, 1 (forward), -1 (back) */
extern	WORD	SMFlag;		/* search mode flag */
extern	WORD	SrcTyp;		/* type of search (E_SEARCH, N_SEARCH, etc) */
extern	charptr	SStPtr;		/* pointer into search string */
extern	bool	TraceM;		/* trace mode flag */
#if VIDEO
extern integer	HldFlg;		/* value of 5:W (hold mode flag) */
extern integer	HtSize;		/* value of 1:W (screen width) */
extern integer	MrkFlg;		/* value of 4:W */
extern integer	ScroLn;		/* value of 7:W */
extern integer	SeeAll;		/* value of 3:W */
extern integer	TopDot;		/* value of 6:W */
extern integer	VtSize;		/* value of 2:W (screen height) */
#  if CURSES
extern integer	SpcMrk;		/* value of 8:W */
extern integer	KeyPad;		/* value of 9:W */
#  endif
#endif
