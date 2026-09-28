gTitlescreenStateFuncs:: @ 0x08079890
	.4byte LoadTitlescreenGraphics                @ SUBSTATE_LOAD_GRAPHICS
	.4byte TitleScreen1_WaitForStartButton        @ SUBSTATE_WAIT_FOR_START_BUTTON
	.4byte TitleScreen2_AnimatePressStartSelected @ SUBSTATE_ANIM_PRESS_START_SELECTED
	.4byte TitleScreen3_AnimateMenuSlideIn        @ SUBSTATE_ANIM_MENU_SLIDE_IN
	.4byte TitleScreen4_MenuInputNoSavedGame      @ SUBSTATE_MENU_INPUT_NO_SAVED_GAME
	.4byte TitleScreen5_MenuInputSavedGame        @ SUBSTATE_MENU_INPUT_SAVED_GAME
	.4byte TitleScreen6_AnimCloseMenu             @ SUBSTATE_ANIM_CLOSE_MENU
	.4byte TitleScreen7_ProcessMenuItemSelected_NoSavedGame @ SUBSTATE_MENU_ITEM_SELECTED_NO_SAVED_GAME
	.4byte TitleScreen8_ProcessMenuItemSelected_SavedGame   @ SUBSTATE_MENU_ITEM_SELECTED_SAVED_GAME
	.4byte TitleScreen9_DeleteSaveConfirmation              @ SUBSTATE_DELETE_SAVE_GAME_CONFIRMATION
	.4byte TitleScreen10_ExecMenuSelection        @ SUBSTATE_EXEC_MENU_SELECTION
	.4byte TitleScreen11_FadeToAction             @ SUBSTATE_FADE_TO_MENU_ACTION
