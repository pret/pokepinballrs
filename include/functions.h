#ifndef GUARD_FUNCTIONS_H
#define GUARD_FUNCTIONS_H

// Place all external function declarations in this file

// src/gbplayer.c

void InitGameBoyPlayer(void);
void sub_10C0(void);
void sub_111C(void);
int sub_1170(void);
void sub_1198(void);
void sub_11B0(int arg0);
void sub_11E4(int arg0);
void sub_11F0(int arg0);
void sub_11FC(void);
void sub_1340(void);
extern u32 sub_16A0(u8 param_1);
extern u32 sub_1748(u8 param_1);
void Sio32IDIntr(void);

// src/main.c

void AgbMain(void);
void Main_09BC(void);
void VBlankIntr(void);
void VCountIntr(void);
void SerialIntr(void);
void Timer3Intr(void);
void IntrDummy(void);
s16 Sin(u16 arg0);
s16 Cos(u16 arg0);
void sub_0D10(void);
void MainLoopIter(void);
void DefaultMainCallback(void);

// src/rom_3219C.c

void PickSpeciesForCatchEmMode(void);
void PickSpeciesForCatchEmMode(void);

// src/rom_850.c

u16 IsInVblank(void);
void SetMainCallback(void (*func)(void));
void ResetMainCallback(void);
void SetVBlankIntrFunc(void (*func)(void));
void ResetVBlankIntrFunc(void);
void SetVCountIntrFunc(void (*func)(void));
void ResetVCountIntrFunc(void);

// src/titlescreen.c

void TitlescreenMain(void);
void LoadTitlescreenGraphics(void);
void InitTitlescreenStates(void);
void TitleScreen1_WaitForStartButton(void);
void TitleScreen2_8010CF0(void);
void TitleScreen9_8010D84(void);
void TitleScreen3_8010E00(void);
void TitleScreen4_MenuInputNoSavedGame(void);
void TitleScreen7_8011020(void);
void TitleScreen5_MenuInputSavedGame(void);
void TitleScreen8_8011228(void);
void TitleScreen6_AnimCloseMenu(void);
void TitleScreen10_ExecMenuSelection(void);
void TitleScreen11_80114B4(void);

// src/util.c

void SetMainGameState(u16 mainState);
void sub_024C(void);
void sub_02B4(void);
s16 LoadSpriteSets(const struct SpriteSet *const *spriteSets, u16 numSpriteSets, struct SpriteGroup *spriteGroups);
void ResetSomeGraphicsRelatedStuff(void);
void ClearGraphicsMemory(void);
void sub_0518(void);
void ClearSprites(void);
void sub_0678(u8 *arg0, s16 arg1, s16 arg2);
u8 *sub_06CC(int arg0, u8 *arg1, int arg2, s16 arg3);
void SetMatrixScale(s16 xScale, s16 yScale, s16 matrixNum);

// src/bonus_field_select.s

extern void BonusFieldSelectMain(void);
extern void LoadBonusFieldSelectGraphics(void);
extern void sub_2710(void);
extern void sub_2768(void);
extern void sub_2990(void);
extern void sub_29C8(void);

// src/ereader.c

extern void EReaderMain(void);
extern void LoadEReaderGraphics(void);
extern void sub_2DF0(void);
extern void sub_2E40(void);
extern void sub_2FC0(void);
extern void sub_304C(void);
extern void sub_3208(void);
extern void sub_33A0(void);
extern void sub_343C(void);
extern void sub_35C8(void);
extern void sub_374C(void);
extern void sub_377C(void);
extern void sub_37B4(s8);
extern void sub_3828(s8, s8);
extern void sub_38A0(s8, u16);
extern s16 GetEReaderCardIndex(void);
extern void sub_394C(void);
extern void sub_3AB4(void);
extern void sub_3C1C(void);
extern s32 sub_3C78(void);
extern s16 sub_3CD8(void);

// src/field_select.s

extern void FieldSelectMain(void);
extern void LoadFieldSelectGraphics(void);
extern void sub_8C7C(void);
extern void sub_8F64(void);

// src/high_scores.s
extern void HighScoresMain(void);
extern void IdleHighScoresMain(void);
extern void LoadHighScoreGraphics(void);
extern void sub_CFD4(void);
extern void sub_D20C(void);
extern void sub_D308(void);
extern void sub_D4B8(void);

// asm/high_scores.s

extern void sub_D664(void);
extern void sub_D9F8(void);
//extern ? sub_DB4C();
//extern ? sub_DB70();
//extern ? sub_DBF4();
//extern ? sub_DCF0();
//extern ? sub_DD4C();
//extern ? sub_DD70();
extern void sub_DEB4(void);
//extern ? sub_E0C4();
//extern ? sub_E0EC();
//extern ? sub_E230();
//extern ? sub_E390();
extern void sub_E3A8(void);
extern void sub_E464(void);
extern void sub_E860(void);
extern void sub_E908(void);
extern s16 sub_E94C(void);
extern s16 sub_E970(void);
extern s16 sub_E994();
extern s16 sub_EAC0();
extern s16 sub_EBEC(void);
extern s16 sub_ED28(void);
extern void sub_EE64(void);
extern void sub_F21C(u32, u32);
extern int CompareScores(u32, u32, u32, u32);
extern s32 GetNewHighScoreIndex(u32, u32, u32);
extern void sub_F434(u32, u32, u32, int);
extern u32 sub_F4FC(u32);
extern void sub_F670(u32, u32, s16, u32);
extern void SetDefaultHighScores(void);
extern void sub_F8B0(u32, u32, s16);
extern void sub_FAE8(u32, u32, s16);
extern s8 sub_FD20(void);
extern void sub_FD5C(void (*func)(void));
extern void sub_FE04(void (*func)(void));
extern void sub_FEB8(u8 *, u8 *, void (*func)(void));
extern void sub_FF74(void (*func)(void));
extern void sub_1001C(u16);
extern void sub_10170(u8 *, u8 *, u16, u16); // Very much subject to change
extern void sub_102A8(u8 *, u8 *, u16, u16);
extern void sub_10424(void);
extern void sub_10480(void);
extern void sub_1050C(void);
extern void sub_10528(void);
extern void sub_10544(void);
extern void PrintChar(u16 glyph, u16 color, int x, int y, int arg4, int arg5);

// src/intro.c
extern void IntroMain(void);
extern void sub_929C(void);
extern void sub_9348(void);
extern void sub_9370(void);
extern void sub_938C(void);
extern void sub_93D0(void);
extern void sub_93F8(void);
extern void sub_9498(void);
extern void sub_96A8(void);

// asm/intro.s

extern void sub_978C(void);
extern void sub_9830(void);
extern void sub_9878(void);
extern void sub_98B4(void);
extern void sub_9920(void);
extern void sub_999C(void);
extern void sub_9AB8(void);
extern void nullsub_4(void);
//extern ? sub_9C10();
//extern ? nullsub_5();
//extern ? nullsub_17();
//extern ? sub_9C9C();
extern void sub_9CB8(void);
extern void sub_9D70(void);
extern void sub_9E90(void);
//extern ? sub_A154();
//extern ? sub_A16C();
extern void sub_A2A8(void);
//extern ? nullsub_6();
//extern ? sub_A2F0();
//extern ? nullsub_7();
//extern ? sub_A39C();
//extern ? sub_A43C();
//extern ? sub_A454();
//extern ? sub_A628();
//extern ? sub_A674();
//extern ? sub_A710();
//extern ? nullsub_8();
//extern ? sub_A860();
//extern ? sub_A87C();
//extern ? sub_A950();
//extern ? sub_A968();
//extern ? sub_AAA8();
//extern ? nullsub_9();
//extern ? sub_AAF4();
//extern ? nullsub_10();
//extern ? sub_AB90();
//extern ? sub_AC20();
//extern ? sub_AC38();
//extern ? sub_ADFC();
//extern ? sub_AE74();
//extern ? sub_AF80();
//extern ? nullsub_11();
//extern ? sub_B090();
//extern ? sub_B0E8();
//extern ? sub_B2E0();
//extern ? sub_B2F8();
//extern ? sub_B4A0();
//extern ? sub_B560();
//extern ? sub_B6C4();
//extern ? sub_B7A0();
//extern ? sub_B7F8();
//extern ? sub_BA2C();
//extern ? sub_BA3C();
//extern ? sub_BBE0();
//extern ? sub_BC54();
//extern ? sub_BCE8();
//extern ? sub_BDC0();
//extern ? sub_BED0();
//extern ? sub_C018();
//extern ? sub_C0BC();
//extern ? sub_C0D8();
//extern ? sub_C210();
//extern ? sub_C228();
//extern ? sub_C2F0();
//extern ? sub_C38C();
//extern ? sub_C3D0();
//extern ? sub_C450();
//extern ? nullsub_12();
//extern ? nullsub_13();
//extern ? sub_C498();
//extern ? sub_C4F0();
//extern ? sub_C814();
//extern ? sub_C948();
//extern ? sub_CA28();
//extern ? sub_CAA0();
//extern ? sub_CB6C();
//extern ? sub_CBA4();
//extern ? nullsub_14();
//extern ? sub_CC94();
//extern ? sub_CCF8();

// asm/libagbsyscall.s

//extern ? CpuSet();
//extern ? LZ77UnCompWram();
//extern ? RegisterRamReset();
//extern ? Sqrt();
//extern ? VBlankIntrWait();

// asm/m4a_1.s

//extern ? umul3232H32();
//extern ? SoundMain();
//extern ? SoundMainRAM();
//extern ? SoundMainBTM();
//extern ? RealClearChain();
//extern ? ply_fine();
//extern ? MPlayJumpTableCopy();
//extern ? ld_r3_tp_adr_i();
//extern ? ply_goto();
//extern ? ply_patt();
//extern ? ply_pend();
//extern ? ply_rept();
//extern ? ply_prio();
//extern ? ply_tempo();
//extern ? ply_keysh();
//extern ? ply_voice();
//extern ? ply_vol();
//extern ? ply_pan();
//extern ? ply_bend();
//extern ? ply_bendr();
//extern ? ply_lfodl();
//extern ? ply_modt();
//extern ? ply_tune();
//extern ? ply_port();
//extern ? m4aSoundVSync();
//extern ? MPlayMain();
//extern ? TrackStop();
//extern ? ChnVolSetAsm();
//extern ? ply_note();
//extern ? ply_endtie();
//extern ? clear_modM();
//extern ? ld_r3_tp_adr_i();
//extern ? ply_lfos();
//extern ? ply_mod();

// asm/m4a_3.s

//extern ? CgbSound();

// asm/options.s

//extern ? Options_Main();
//extern ? Options_LoadGraphics();
extern void Options_InitStates(void);
//extern ? Options_HandleInput();
//extern ? sub_51C3C();
//extern ? sub_51C60();
extern void sub_51C9C(void);
extern void sub_524BC(void);
extern void sub_52528(void);
extern void SetButtonConfigInputs(s8);

// asm/pokedex.s

extern void PokedexMain(void);
//extern ? LoadPokedexGraphics();
extern void sub_3FAC(void);
//extern ? Pokedex_HandleListInput();
//extern ? sub_43D4();
//extern ? sub_4428();
//extern ? sub_45A4();
//extern ? sub_4860();
//extern ? Pokedex_LinkSetup();
//extern ? sub_49D0();
//extern ? sub_4B10();
//extern ? sub_4B34();
//extern ? sub_4BB4();
//extern ? sub_4C80();
//extern ? Pokedex_ReturnToTitle();
//extern ? sub_71DC();
extern void sub_8974(s16);
extern s16 sub_8A78(s16);
extern void ResetPokedex(void);

// asm/rom_1068C.s

extern void sub_10618(int, int, int, int, int, int);
void sub_1068C(int, int, int, int, u16);
extern void sub_10708(void *volatile, void *volatile, s16, s16);
//extern ? sub_10750();
//extern ? sub_10798();
//extern ? sub_10860();
extern void ClearSomeArray(void);

// asm/rom_11B9C.s

//extern ? sub_11B9C();
extern void sub_11C14(s16);
//extern ? sub_11C98();
extern void sub_1332C();
extern void sub_1333C();
extern u16 sub_13824(struct Vector16*);
extern void sub_13B28(struct Vector16*, struct Vector16*, s16);
extern void sub_13D24(u16, struct Vector16*, struct Vector16*);
extern void sub_14074(u16, struct Vector32*, u16);
extern u16 sub_14488(struct Vector16*, struct Vector16);
extern u16 sub_1467C(struct Vector16*, u16*);
extern u16 sub_14740(struct Vector16*, u16*);
extern void sub_1493C(void);
extern u16 sub_14AF4(struct Vector16 r0, s16 r1, s16 *r2 /* s16 or u16 */, s16 r3);
//extern ? sub_14B84();
//extern ? sub_14E08();
//extern ? sub_15054();
//extern ? sub_153CC();
//extern ? sub_16090();
//extern ? sub_162B8();
//extern ? sub_1642C();
//extern ? sub_171C8();
//extern ? sub_173FC();
extern void sub_17634(u8);
//extern ? sub_176B0();
extern void sub_17898(struct Vector16 *, u16 *, u8 *);
extern void sub_179D0(u8, u16 *, u16 *);
//extern ? sub_17C1C();
//extern ? sub_17F28();
//extern ? sub_18180();
//extern ? sub_182B4();
//extern ? sub_18324();
//extern ? sub_1857C();
extern void sub_18784(u8);
extern s16 sub_187F4(struct Vector16*, u16*);
extern void sub_18A4C(struct Vector16*, u16*, u8*);
extern void sub_18AE0(u8, u16*, u16*);
extern s16 sub_18B50(struct Vector16*, u16*);
extern void sub_18DAC(struct Vector16*, u16*, u8*);
extern void sub_18F38(u8, u16*, u16*);
extern void IdlePinballGameMain();
extern void sub_19048(void);//gMain.subState = 0
extern void sub_19190(void);//gMain.subState = 1
extern void sub_4ABC8(void);//gMain.subState = 2
extern void sub_19288(void);//gMain.subState = 3
//extern ? sub_19304();
extern void sub_1931C(struct Vector16 arg0);
//extern ? sub_19490();
extern void sub_195C4(void);
extern void sub_19734(void);
extern void sub_19894(void);
//extern ? sub_19A20();
//extern ? sub_19B10();
extern void sub_19B64(u8);
extern void sub_19B90(void);
//extern ? sub_19C04();
//extern ? sub_19CC8();
//extern ? sub_19D04();
//extern ? sub_19E10();
//extern ? sub_19F70();
//extern ? sub_19FA0();
extern void sub_1A0F4(void);
//extern ? sub_1A2C0();
//extern ? sub_1A98C();
extern void sub_1A9E8(void);
//extern ? sub_1AA38();
extern void sub_1AAA0();
extern void sub_1AD84(void);
//extern ? sub_1ADF4();
//extern ? sub_1AF84();
//extern ? sub_1AFD4();
extern void sub_1B140(s8);
//extern ? sub_1BB68();
//extern ? sub_1C544();
extern void sub_1C560(void);
extern void sub_1C5AC(void);
//extern ? sub_1C73C();
extern void sub_1C7F4(u16, u16);
extern void sub_1D128(void);
extern void sub_1D4D0(void);
//extern ? sub_1D5D8();
//extern ? sub_1DA74();
//extern ? sub_1DAD8();
//extern ? sub_1DC7C();
//extern ? sub_1DDDC();
//extern ? sub_1EC48();
//extern ? sub_1F158();
extern void sub_1F2A4();
extern void sub_1F59C();
//extern ? sub_1F698();
//extern ? sub_1FA48();
//extern ? sub_1FBC4();
//extern ? sub_1FF0C();
//extern ? sub_201B8();
extern void sub_203CC();
//extern ? sub_20EC0();
//extern ? sub_21238();
//extern ? sub_21300();
//extern ? sub_21320();
//extern ? sub_21514();
//extern ? sub_21578();
//extern ? sub_216FC();
//extern ? sub_219A8();
//extern ? sub_219EC();
extern void sub_21B0C();
//extern ? sub_21D78();
//extern ? sub_21FBC();
extern void sub_225F0();
extern void sub_22978();
//extern ? sub_22A30();
//extern ? sub_22C6C();
//extern ? sub_22D54();
//extern ? sub_22FA4();
//extern ? sub_23070();
//extern ? sub_2310C();
//extern ? sub_2312C();
//extern ? sub_23300();
//extern ? sub_23954();
//extern ? sub_239A4();
//extern ? sub_23E18();
//extern ? sub_242B4();
//extern ? sub_24350();
//extern ? sub_24408();
//extern ? sub_2530C();
//extern ? sub_253E0();
//extern ? sub_25808();
//extern ? sub_25F64();
//extern ? sub_260B8();
//extern ? sub_26778();
//extern ? sub_26820();
//extern ? sub_268CC();
//extern ? sub_269A4();
//extern ? sub_26A10();
//extern ? sub_26EA4();
//extern ? sub_26F38();
//extern ? sub_27080();
//extern ? sub_278F4();
//extern ? sub_27D44();
//extern ? sub_27E08();
//extern ? sub_27F94();
//extern ? sub_28404();
//extern ? sub_28544();
//extern ? sub_28AE0();
//extern ? sub_28BFC();
//extern ? sub_28C90();
//extern ? sub_28E2C();
//extern ? sub_28EA0();
//extern ? sub_292A0();
//extern ? sub_29334();
//extern ? sub_293D8();
//extern ? sub_29624();
//extern ? sub_29664();
//extern ? sub_2971C();
//extern ? sub_29924();
//extern ? sub_29A6C();
//extern ? sub_29D9C();
//extern ? sub_2A054();
//extern ? sub_2A354();
//extern ? sub_2C518();
//extern ? sub_2C538();
//extern ? sub_2C9A4();
extern void sub_2CA9C();
//extern ? sub_2CD98();
extern void sub_2CE80();
extern void sub_2D104();
//extern ? sub_2D204();
//extern ? sub_2DE54();
//extern ? sub_2E094();
extern void sub_2E67C();
extern void sub_2E6AC();
extern void sub_2F140();
extern void sub_2F26C();
extern void sub_2F504();
extern void sub_2F79C();
extern void sub_2FCD0();
extern void sub_300D8();
extern void sub_30178();
extern void sub_30480();
extern void sub_304C8();
extern void sub_308DC();
extern void sub_30EB4();
extern void sub_31144();
extern void sub_313A0();
extern void sub_31498();
extern void sub_31B30();
extern void sub_31BE8(s16);
//extern ? sub_31CF8();
//extern ? BuildSpeciesWeightsForCatchEmMode();

// asm/rom_3219C.s

//extern ? BuildSpeciesWeightsForEggMode();
//extern ? PickSpeciesForEggMode();
//extern ? sub_326F4();
//extern ? sub_3276C();
extern void sub_327C0();
extern void sub_328C8();
//extern ? sub_32914();
extern void sub_32968();
extern void sub_329B0();
extern void sub_329F4();
extern void sub_32B74();
extern void sub_32BE4();
//extern ? DuskullBonus_Setup();
//extern ? sub_33130();
extern void sub_3342C(s16 index1, s16 index2);
extern void sub_336E0();
extern void sub_340EC();
extern void sub_34450();
extern void sub_350F0();
extern void sub_351A8();
extern void sub_356A0();
//extern ? sub_357B8();
//extern ? sub_35860();
//extern ? sub_35AA4();
//extern ? sub_35D54();
//extern ? sub_372B4();
//extern ? sub_3751C();
//extern ? sub_37850();
//extern ? sub_38218();
//extern ? sub_383E4();
//extern ? sub_3869C();
//extern ? sub_38A20();
//extern ? sub_395D8();
//extern ? sub_39A40();
//extern ? sub_3A150();
extern void sub_3ADA0(void);
//extern ? sub_3AE14();
//extern ? sub_3B120();
//extern ? sub_3B49C();
//extern ? sub_3B7C4();
//extern ? sub_3C6E0();
//extern ? sub_3CBC4();
extern void sub_3E5D0(void);
//extern ? sub_3E644();
//extern ? sub_3E79C();
//extern ? sub_3EB2C();
//extern ? sub_3EDF0();
//extern ? sub_3FAE0();
//extern ? sub_40288();
//extern ? sub_41580();
//extern ? sub_417F8();
//extern ? sub_423D8();
//extern ? sub_42E48();
//extern ? sub_43228();
//extern ? sub_43500();
//extern ? sub_4387C();
//extern ? sub_44D58();
//extern ? sub_44F3C();
//extern ? sub_45164();
//extern ? sub_455D0();
//extern ? sub_45E08();
//extern ? sub_45E90();
extern void sub_467F4(void);
extern void sub_46FD4(s16);
extern void sub_47030(void);
//extern ? sub_47100();
//extern ? sub_47160();
extern void sub_472E4();
extern void sub_47344(void);
extern void sub_474F4(void);
extern void sub_47670(void);
extern void sub_478D8(void);
extern void sub_47FBC(void);
extern void sub_47FF8(void);
extern void sub_48124(void);
extern void sub_48190(void);
extern void sub_495A0(void);
extern void sub_497BC(void);
extern void sub_49850(void);
extern void sub_49A34(void);
extern void sub_4ACF0();
extern void sub_4B000();
extern void sub_4B408(s16);
//extern ? sub_4CEA8();
//extern ? sub_4CEB4();
extern void sub_49ED4(void);
//extern ? sub_4D3D0();
//extern ? sub_4D648();
//extern ? sub_4D6C4();
//extern ? sub_4D960();
//extern ? sub_4DBFC();
//extern ? sub_4DFA0();
//extern ? sub_4E2F8();
//extern ? sub_4E468();
extern void sub_4E598(void);
extern void sub_4E814(void);
//extern ? sub_4E920();
extern void sub_4E9F0(s8);
//extern ? sub_4EA44();
//extern ? sub_4EAB0();
//extern ? sub_4EAF8();
//extern ? sub_4EBD0();
//extern ? sub_4ECDC();
//extern ? sub_4EDC0();
//extern ? sub_4EE74();
//extern ? sub_4EF38();
//extern ? sub_4F028();
//extern ? sub_4F0F0();
//extern ? sub_4F258();
//extern ? sub_4F2B8();
//extern ? sub_4F30C();
//extern ? sub_4F4B4();
//extern ? sub_4F660();
extern void sub_4F814();
//extern ? sub_4F95C();
//extern ? sub_4F9F0();
//extern ? sub_4FAC0();
//extern ? sub_4FB08();
//extern ? sub_4FBA4();
//extern ? sub_4FC7C();
//extern ? sub_4FD88();
//extern ? sub_4FE6C();
//extern ? sub_50000();
//extern ? sub_500B4();
//extern ? sub_50154();
//extern ? sub_5030C();
//extern ? sub_504C0();
//extern ? sub_505A4();
//extern ? sub_506B0();
//extern ? sub_50710();
//extern ? sub_507D4();
extern void sub_50848(void);
//extern ? sub_50918();
extern void sub_50AD4(void);
//extern ? sub_50B80();
extern void sub_50D48(void);
//extern ? sub_50DB8();
extern void sub_50DE0(void);
//extern ? nullsub_20();
extern void sub_50F04(void);
//extern ? sub_50FAC();
extern void sub_50FD4(void);
//extern ? sub_51068();
extern void sub_51090(void);
//extern ? sub_51128();
extern void sub_51150(void);
//extern ? sub_511F8();

// asm/rom_528AC.s

//extern ? SpeciesRSToCryId();
//extern ? PlayCry_Normal();
extern void PlayCry_NormalNoDucking(u16, s8, s8, u8);
//extern ? PlayCryInternal();
extern void SaveFile_LoadGameData(void);
//extern ? LoadSaveDataFromSram();
extern void SaveFile_WriteToSram(void);
extern void SaveFile_SetPokedexFlags(s16, u8);
extern void SaveFile_ReadSavedGamePresent(void);
extern void ResetSaveFile(void);

// asm/rom_9BC.s

extern void sub_13FC(void);
//extern ? sub_1668();
//extern ? sub_16A0();
//extern ? sub_170C();
//extern ? sub_1748();
//extern ? sub_17D8();
extern void sub_1828(void);
extern s16 sub_2414(const struct SpriteSet *const *spriteSets, u16 numSpriteSets, struct SpriteGroup *spriteGroups);
//extern ? nullsub_16();
extern void sub_24DC(void);
extern void sub_250C(void);
extern void sub_2538(void);
extern void sub_2568(void);

// asm/start.s


// asm/titlescreen.s

//extern ? sub_11640();
extern void sub_1175C(void);
extern void sub_11968(void);
extern void sub_11B74(void);

#endif  // GUARD_FUNCTIONS_H
