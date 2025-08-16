
	.equ	W00,	0x80		@ WAIT
	.equ	W01,	W00+1		@
	.equ	W02,	W00+2		@
	.equ	W03,	W00+3		@
	.equ	W04,	W00+4		@
	.equ	W05,	W00+5		@
	.equ	W06,	W00+6		@
	.equ	W07,	W00+7		@
	.equ	W08,	W00+8		@
	.equ	W09,	W00+9		@
	.equ	W10,	W00+10		@
	.equ	W11,	W00+11		@
	.equ	W12,	W00+12		@
	.equ	W13,	W00+13		@
	.equ	W14,	W00+14		@
	.equ	W15,	W00+15		@
	.equ	W16,	W00+16		@
	.equ	W17,	W00+17		@
	.equ	W18,	W00+18		@
	.equ	W19,	W00+19		@
	.equ	W20,	W00+20		@
	.equ	W21,	W00+21		@
	.equ	W22,	W00+22		@
	.equ	W23,	W00+23		@
	.equ	W24,	W00+24		@
	.equ	W28,	W00+25		@
	.equ	W30,	W00+26		@
	.equ	W32,	W00+27		@
	.equ	W36,	W00+28		@
	.equ	W40,	W00+29		@
	.equ	W42,	W00+30		@
	.equ	W44,	W00+31		@
	.equ	W48,	W00+32		@
	.equ	W52,	W00+33		@
	.equ	W54,	W00+34		@
	.equ	W56,	W00+35		@
	.equ	W60,	W00+36		@
	.equ	W64,	W00+37		@
	.equ	W66,	W00+38		@
	.equ	W68,	W00+39		@
	.equ	W72,	W00+40		@
	.equ	W76,	W00+41		@
	.equ	W78,	W00+42		@
	.equ	W80,	W00+43		@
	.equ	W84,	W00+44		@
	.equ	W88,	W00+45		@
	.equ	W90,	W00+46		@
	.equ	W92,	W00+47		@
	.equ	W96,	W00+48		@

	.equ	FINE,	0xb1		@ fine
	.equ	GOTO,	0xb2		@ goto
	.equ	PATT,	0xb3		@ pattern play
	.equ	PEND,	0xb4		@ pattern end
	.equ	REPT,	0xb5		@ repeat
	.equ	MEMACC,	0xb9		@ memacc op adr dat ***lib
	.equ	PRIO,	0xba		@ priority
	.equ	TEMPO,	0xbb		@ tempo (BPM/2)
	.equ	KEYSH,	0xbc		@ key shift

@***
@ MML (within running status)
@******************************************************@

	.equ	VOICE,	0xbd		@ voice #
	.equ	VOL,	0xbe		@ volume
	.equ	PAN,	0xbf		@ panpot (c_v+??)
	.equ	BEND,	0xc0		@ pitch bend (c_v+??)
	.equ	BENDR,	0xc1		@ bend range
	.equ	LFOS,	0xc2		@ LFO speed
	.equ	LFODL,	0xc3		@ LFO delay
	.equ	MOD,	0xc4		@ modulation depth
	.equ	MODT,	0xc5		@ modulation type
	.equ	TUNE,	0xc8		@ micro tuning (c_v+??)

	.equ	XCMD,	0xcd		@ extend command  ***lib
	 .equ	xIECV,	0x08		@  imi.echo vol   ***lib
	 .equ	xIECL,	0x09		@  imi.echo len   ***lib

	.equ	EOT,	0xce		@ End of Tie
	.equ	TIE,	0xcf		@
	.equ	N01,	TIE+1		@ NOTE
	.equ	N02,	N01+1		@
	.equ	N03,	N01+2		@
	.equ	N04,	N01+3		@
	.equ	N05,	N01+4		@
	.equ	N06,	N01+5		@
	.equ	N07,	N01+6		@
	.equ	N08,	N01+7		@
	.equ	N09,	N01+8		@
	.equ	N10,	N01+9		@
	.equ	N11,	N01+10		@
	.equ	N12,	N01+11		@
	.equ	N13,	N01+12		@
	.equ	N14,	N01+13		@
	.equ	N15,	N01+14		@
	.equ	N16,	N01+15		@
	.equ	N17,	N01+16		@
	.equ	N18,	N01+17		@
	.equ	N19,	N01+18		@
	.equ	N20,	N01+19		@
	.equ	N21,	N01+20		@
	.equ	N22,	N01+21		@
	.equ	N23,	N01+22		@
	.equ	N24,	N01+23		@
	.equ	N28,	N01+24		@
	.equ	N30,	N01+25		@
	.equ	N32,	N01+26		@
	.equ	N36,	N01+27		@
	.equ	N40,	N01+28		@
	.equ	N42,	N01+29		@
	.equ	N44,	N01+30		@
	.equ	N48,	N01+31		@
	.equ	N52,	N01+32		@
	.equ	N54,	N01+33		@
	.equ	N56,	N01+34		@
	.equ	N60,	N01+35		@
	.equ	N64,	N01+36		@
	.equ	N66,	N01+37		@
	.equ	N68,	N01+38		@
	.equ	N72,	N01+39		@
	.equ	N76,	N01+40		@
	.equ	N78,	N01+41		@
	.equ	N80,	N01+42		@
	.equ	N84,	N01+43		@
	.equ	N88,	N01+44		@
	.equ	N90,	N01+45		@
	.equ	N92,	N01+46		@
	.equ	N96,	N01+47		@

@***
@ Max value of operators
@******************************************************@

	.equ	mxv,	0x7F		@

@***
@ center value of PAN, BEND, TUNE
@******************************************************@

	.equ	c_v,	0x40		@ -64 ~ +63

@***
@ parameter of N??, TIE, EOT
@******************************************************@

	.equ	CnM2,	0		@
	.equ	CsM2,	1		@
	.equ	DnM2,	2		@
	.equ	DsM2,	3		@
	.equ	EnM2,	4		@
	.equ	FnM2,	5		@
	.equ	FsM2,	6		@
	.equ	GnM2,	7		@
	.equ	GsM2,	8		@
	.equ	AnM2,	9		@
	.equ	AsM2,	10		@
	.equ	BnM2,	11		@
	.equ	CnM1,	12		@
	.equ	CsM1,	13		@
	.equ	DnM1,	14		@
	.equ	DsM1,	15		@
	.equ	EnM1,	16		@
	.equ	FnM1,	17		@
	.equ	FsM1,	18		@
	.equ	GnM1,	19		@
	.equ	GsM1,	20		@
	.equ	AnM1,	21		@
	.equ	AsM1,	22		@
	.equ	BnM1,	23		@
	.equ	Cn0,	24		@
	.equ	Cs0,	25		@
	.equ	Dn0,	26		@
	.equ	Ds0,	27		@
	.equ	En0,	28		@
	.equ	Fn0,	29		@
	.equ	Fs0,	30		@
	.equ	Gn0,	31		@
	.equ	Gs0,	32		@
	.equ	An0,	33		@
	.equ	As0,	34		@
	.equ	Bn0,	35		@
	.equ	Cn1,	36		@
	.equ	Cs1,	37		@
	.equ	Dn1,	38		@
	.equ	Ds1,	39		@
	.equ	En1,	40		@
	.equ	Fn1,	41		@
	.equ	Fs1,	42		@
	.equ	Gn1,	43		@
	.equ	Gs1,	44		@
	.equ	An1,	45		@
	.equ	As1,	46		@
	.equ	Bn1,	47		@
	.equ	Cn2,	48		@
	.equ	Cs2,	49		@
	.equ	Dn2,	50		@
	.equ	Ds2,	51		@
	.equ	En2,	52		@
	.equ	Fn2,	53		@
	.equ	Fs2,	54		@
	.equ	Gn2,	55		@
	.equ	Gs2,	56		@
	.equ	An2,	57		@
	.equ	As2,	58		@
	.equ	Bn2,	59		@
	.equ	Cn3,	60		@
	.equ	Cs3,	61		@
	.equ	Dn3,	62		@
	.equ	Ds3,	63		@
	.equ	En3,	64		@
	.equ	Fn3,	65		@
	.equ	Fs3,	66		@
	.equ	Gn3,	67		@
	.equ	Gs3,	68		@
	.equ	An3,	69		@ 440Hz
	.equ	As3,	70		@
	.equ	Bn3,	71		@
	.equ	Cn4,	72		@
	.equ	Cs4,	73		@
	.equ	Dn4,	74		@
	.equ	Ds4,	75		@
	.equ	En4,	76		@
	.equ	Fn4,	77		@
	.equ	Fs4,	78		@
	.equ	Gn4,	79		@
	.equ	Gs4,	80		@
	.equ	An4,	81		@
	.equ	As4,	82		@
	.equ	Bn4,	83		@
	.equ	Cn5,	84		@
	.equ	Cs5,	85		@
	.equ	Dn5,	86		@
	.equ	Ds5,	87		@
	.equ	En5,	88		@
	.equ	Fn5,	89		@
	.equ	Fs5,	90		@
	.equ	Gn5,	91		@
	.equ	Gs5,	92		@
	.equ	An5,	93		@
	.equ	As5,	94		@
	.equ	Bn5,	95		@
	.equ	Cn6,	96		@
	.equ	Cs6,	97		@
	.equ	Dn6,	98		@
	.equ	Ds6,	99		@
	.equ	En6,	100		@
	.equ	Fn6,	101		@
	.equ	Fs6,	102		@
	.equ	Gn6,	103		@
	.equ	Gs6,	104		@
	.equ	An6,	105		@
	.equ	As6,	106		@
	.equ	Bn6,	107		@
	.equ	Cn7,	108		@
	.equ	Cs7,	109		@
	.equ	Dn7,	110		@
	.equ	Ds7,	111		@
	.equ	En7,	112		@
	.equ	Fn7,	113		@
	.equ	Fs7,	114		@
	.equ	Gn7,	115		@
	.equ	Gs7,	116		@
	.equ	An7,	117		@
	.equ	As7,	118		@
	.equ	Bn7,	119		@
	.equ	Cn8,	120		@
	.equ	Cs8,	121		@
	.equ	Dn8,	122		@
	.equ	Ds8,	123		@
	.equ	En8,	124		@
	.equ	Fn8,	125		@
	.equ	Fs8,	126		@
	.equ	Gn8,	127		@

@***
@ parameter of velocity
@******************************************************@

	.equ	v000,	0		@
	.equ	v001,	1		@
	.equ	v002,	2		@
	.equ	v003,	3		@
	.equ	v004,	4		@
	.equ	v005,	5		@
	.equ	v006,	6		@
	.equ	v007,	7		@
	.equ	v008,	8		@
	.equ	v009,	9		@
	.equ	v010,	10		@
	.equ	v011,	11		@
	.equ	v012,	12		@
	.equ	v013,	13		@
	.equ	v014,	14		@
	.equ	v015,	15		@
	.equ	v016,	16		@
	.equ	v017,	17		@
	.equ	v018,	18		@
	.equ	v019,	19		@
	.equ	v020,	20		@
	.equ	v021,	21		@
	.equ	v022,	22		@
	.equ	v023,	23		@
	.equ	v024,	24		@
	.equ	v025,	25		@
	.equ	v026,	26		@
	.equ	v027,	27		@
	.equ	v028,	28		@
	.equ	v029,	29		@
	.equ	v030,	30		@
	.equ	v031,	31		@
	.equ	v032,	32		@
	.equ	v033,	33		@
	.equ	v034,	34		@
	.equ	v035,	35		@
	.equ	v036,	36		@
	.equ	v037,	37		@
	.equ	v038,	38		@
	.equ	v039,	39		@
	.equ	v040,	40		@
	.equ	v041,	41		@
	.equ	v042,	42		@
	.equ	v043,	43		@
	.equ	v044,	44		@
	.equ	v045,	45		@
	.equ	v046,	46		@
	.equ	v047,	47		@
	.equ	v048,	48		@
	.equ	v049,	49		@
	.equ	v050,	50		@
	.equ	v051,	51		@
	.equ	v052,	52		@
	.equ	v053,	53		@
	.equ	v054,	54		@
	.equ	v055,	55		@
	.equ	v056,	56		@
	.equ	v057,	57		@
	.equ	v058,	58		@
	.equ	v059,	59		@
	.equ	v060,	60		@
	.equ	v061,	61		@
	.equ	v062,	62		@
	.equ	v063,	63		@
	.equ	v064,	64		@
	.equ	v065,	65		@
	.equ	v066,	66		@
	.equ	v067,	67		@
	.equ	v068,	68		@
	.equ	v069,	79		@
	.equ	v070,	70		@
	.equ	v071,	71		@
	.equ	v072,	72		@
	.equ	v073,	73		@
	.equ	v074,	74		@
	.equ	v075,	75		@
	.equ	v076,	76		@
	.equ	v077,	77		@
	.equ	v078,	78		@
	.equ	v079,	79		@
	.equ	v080,	80		@
	.equ	v081,	81		@
	.equ	v082,	82		@
	.equ	v083,	83		@
	.equ	v084,	84		@
	.equ	v085,	85		@
	.equ	v086,	86		@
	.equ	v087,	87		@
	.equ	v088,	88		@
	.equ	v089,	89		@
	.equ	v090,	90		@
	.equ	v091,	91		@
	.equ	v092,	92		@
	.equ	v093,	93		@
	.equ	v094,	94		@
	.equ	v095,	95		@
	.equ	v096,	96		@
	.equ	v097,	97		@
	.equ	v098,	98		@
	.equ	v099,	99		@
	.equ	v100,	100		@
	.equ	v101,	101		@
	.equ	v102,	102		@
	.equ	v103,	103		@
	.equ	v104,	104		@
	.equ	v105,	105		@
	.equ	v106,	106		@
	.equ	v107,	107		@
	.equ	v108,	108		@
	.equ	v109,	109		@
	.equ	v110,	110		@
	.equ	v111,	111		@
	.equ	v112,	112		@
	.equ	v113,	113		@
	.equ	v114,	114		@
	.equ	v115,	115		@
	.equ	v116,	116		@
	.equ	v117,	117		@
	.equ	v118,	118		@
	.equ	v119,	119		@
	.equ	v120,	120		@
	.equ	v121,	121		@
	.equ	v122,	122		@
	.equ	v123,	123		@
	.equ	v124,	124		@
	.equ	v125,	125		@
	.equ	v126,	126		@
	.equ	v127,	127		@

@***
@ parameter of gate+
@******************************************************@

	.equ	gtp1,	1		@
	.equ	gtp2,	2		@
	.equ	gtp3,	3		@

@***
@ parameter of MODT, BRET
@******************************************************@

	.equ	mod_vib,0		@ vibrate
	.equ	mod_tre,1		@ tremolo
	.equ	mod_pan,2		@ auto-panpot

@***
@ parameter of MEMACC
@******************************************************@

	.equ	mem_set,0		@
	.equ	mem_add,1		@
	.equ	mem_sub,2		@
	.equ	mem_mem_set,3		@
	.equ	mem_mem_add,4		@
	.equ	mem_mem_sub,5		@
	.equ	mem_beq,6		@
	.equ	mem_bne,7		@
	.equ	mem_bhi,8		@
	.equ	mem_bhs,9		@
	.equ	mem_bls,10		@
	.equ	mem_blo,11		@
	.equ	mem_mem_beq,12		@
	.equ	mem_mem_bne,13		@
	.equ	mem_mem_bhi,14		@
	.equ	mem_mem_bhs,15		@
	.equ	mem_mem_bls,16		@
	.equ	mem_mem_blo,17		@

@***
@ etc.
@******************************************************@

	.equ	reverb_set,0x80		@ SOUND_MODE_REVERB_SET
	.equ	PAM, PAN		@ 

	.equ	Voicegroup_HGSS, 0x915CA70


	.equ	trainer_battle_grp, voicegroup000
	.equ	trainer_battle_pri, 0
	.equ	trainer_battle_rev, 0
	.equ	trainer_battle_mvl, 127
	.equ	trainer_battle_key, 0
	.equ	trainer_battle_tbs, 1
	.equ	trainer_battle_exg, 0
	.equ	trainer_battle_cmp, 1

	.section .rodata
	.global	trainer_battle
	.align	2

@**************** Track 1 (Midi-Chn.2) ****************@

trainer_battle_1:
	.byte	KEYSH , trainer_battle_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 85*trainer_battle_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 127*trainer_battle_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte		N12   , An2 , v100
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte		        An2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
@ 003   ----------------------------------------
	.byte	W84
	.byte		N12   , En3 
	.byte	W12
@ 004   ----------------------------------------
trainer_battle_1_004:
	.byte		N12   , An2 , v100
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
trainer_battle_1_006:
	.byte		N12   , An2 , v100
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W48
	.byte	PEND
@ 007   ----------------------------------------
	.byte	W96
trainer_battle_1_B1:
@ 008   ----------------------------------------
	.byte		N12   , An2 , v100
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte		        An2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
@ 011   ----------------------------------------
	.byte	W84
	.byte		N12   , En3 
	.byte	W12
@ 012   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_1_004
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_1_006
@ 015   ----------------------------------------
	.byte	W96
	.byte	GOTO
	 .word	trainer_battle_1_B1
trainer_battle_1_B2:
@ 016   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 2 (Midi-Chn.3) ****************@

trainer_battle_2:
	.byte	KEYSH , trainer_battle_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 127*trainer_battle_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte		N12   , An1 , v100
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte		        An1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W24
@ 003   ----------------------------------------
	.byte	W84
	.byte		N12   , En2 
	.byte	W12
@ 004   ----------------------------------------
trainer_battle_2_004:
	.byte		N12   , An1 , v100
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N24   , Gs2 
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
trainer_battle_2_006:
	.byte		N12   , An1 , v100
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W48
	.byte	PEND
@ 007   ----------------------------------------
	.byte	W96
trainer_battle_2_B1:
@ 008   ----------------------------------------
	.byte		N12   , An1 , v100
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte		        An1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W24
@ 011   ----------------------------------------
	.byte	W84
	.byte		N12   , En2 
	.byte	W12
@ 012   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_2_004
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_2_006
@ 015   ----------------------------------------
	.byte	W96
	.byte	GOTO
	 .word	trainer_battle_2_B1
trainer_battle_2_B2:
@ 016   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 3 (Midi-Chn.4) ****************@

trainer_battle_3:
	.byte	KEYSH , trainer_battle_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 46
	.byte		VOL   , 115*trainer_battle_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte		N12   , Bn2 , v100
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		N18   , Bn2 
	.byte	W18
@ 001   ----------------------------------------
trainer_battle_3_001:
	.byte		N06   , An2 , v100
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
trainer_battle_3_002:
	.byte		N06   , An2 , v100
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
trainer_battle_3_003:
	.byte		N06   , An3 , v100
	.byte	W06
	.byte		N18   , Bn2 
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		N18   , En3 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte	PEND
@ 004   ----------------------------------------
trainer_battle_3_004:
	.byte		N06   , An3 , v100
	.byte	W06
	.byte		N18   , En3 
	.byte	W18
	.byte		N06   , An3 
	.byte	W06
	.byte		N18   , Bn2 
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
trainer_battle_3_005:
	.byte		N06   , An3 , v100
	.byte	W06
	.byte		N18   , En3 
	.byte	W18
	.byte		N06   , An3 
	.byte	W06
	.byte		N18   , En3 
	.byte	W18
	.byte		N06   , An3 
	.byte	W06
	.byte		N18   , Bn2 
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
trainer_battle_3_006:
	.byte		N06   , En3 , v100
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		N18   , En3 
	.byte	W18
	.byte		N06   , An2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
	.byte		N06   , An3 
	.byte	W06
	.byte		N18   , En3 
	.byte	W18
	.byte		N06   , An3 
	.byte	W06
	.byte		N18   , Bn2 
	.byte	W18
	.byte		N06   , An2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		N18   , En3 
	.byte	W18
trainer_battle_3_B1:
@ 008   ----------------------------------------
	.byte		N12   , Bn2 , v100
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		N18   , Bn2 
	.byte	W18
@ 009   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_3_001
@ 010   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_3_002
@ 011   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_3_003
@ 012   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_3_004
@ 013   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_3_005
@ 014   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_3_006
@ 015   ----------------------------------------
	.byte		N06   , An3 , v100
	.byte	W06
	.byte		N18   , En3 
	.byte	W18
	.byte		N06   , An3 
	.byte	W06
	.byte		N18   , Bn2 
	.byte	W18
	.byte		N06   , An2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		N17   , En3 
	.byte	W18
	.byte	GOTO
	 .word	trainer_battle_3_B1
trainer_battle_3_B2:
@ 016   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 4 (Midi-Chn.5) ****************@

trainer_battle_4:
	.byte	KEYSH , trainer_battle_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 127
	.byte		VOL   , 25*trainer_battle_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , Gn3 , v100
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
@ 001   ----------------------------------------
trainer_battle_4_001:
	.byte		N06   , Gn3 , v100
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
@ 003   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
@ 004   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
@ 005   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
@ 006   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
@ 007   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
trainer_battle_4_B1:
@ 008   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
@ 009   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
@ 010   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
@ 011   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
@ 012   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
@ 013   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
@ 014   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
@ 015   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_4_001
	.byte	GOTO
	 .word	trainer_battle_4_B1
trainer_battle_4_B2:
@ 016   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte	FINE

@**************** Track 5 (Midi-Chn.6) ****************@

trainer_battle_5:
	.byte	KEYSH , trainer_battle_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 47
	.byte		VOL   , 115*trainer_battle_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte		N06   , An0 , v100
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W48
@ 001   ----------------------------------------
trainer_battle_5_001:
	.byte		N06   , An0 , v100
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W48
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
@ 003   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
@ 004   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
@ 005   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
@ 006   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
@ 007   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
trainer_battle_5_B1:
@ 008   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
@ 009   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
@ 010   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
@ 011   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
@ 012   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
@ 013   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
@ 014   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
@ 015   ----------------------------------------
	.byte	PATT
	 .word	trainer_battle_5_001
	.byte	GOTO
	 .word	trainer_battle_5_B1
trainer_battle_5_B2:
@ 016   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte	FINE

@******************************************************@
	.align	2

trainer_battle:
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	trainer_battle_pri	@ Priority
	.byte	trainer_battle_rev	@ Reverb.

	.word	trainer_battle_grp

	.word	trainer_battle_1
	.word	trainer_battle_2
	.word	trainer_battle_3
	.word	trainer_battle_4
	.word	trainer_battle_5

	.end
