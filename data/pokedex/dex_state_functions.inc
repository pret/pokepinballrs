gPokedexStateFuncs:: @ 0x0805C880
	.4byte LoadPokedexGraphics          @ POKEDEX_STATE_LOAD_GRAPHICS
	.4byte Pokedex_HandleListInput      @ POKEDEX_STATE_HANDLE_LIST_INPUT
	.4byte Pokedex_PostScrollRefresh          @ POKEDEX_STATE_2
	.4byte Pokedex_InfoWindowSlideIn          @ POKEDEX_STATE_3
	.4byte Pokedex_InfoWindowSlideOut          @ POKEDEX_STATE_4
	.4byte Pokedex_DetailViewInput          @ POKEDEX_STATE_5
	.4byte Pokedex_LinkSetup            @ POKEDEX_STATE_LINK_SETUP
	.4byte Pokedex_LinkTransferLoop          @ POKEDEX_STATE_7
	.4byte Pokedex_LinkErrorTimeout          @ POKEDEX_STATE_8
	.4byte Pokedex_LinkSuccessSequence          @ POKEDEX_STATE_9
	.4byte Pokedex_LinkRetryDelay         @ POKEDEX_STATE_10
	.4byte Pokedex_DeleteConfirmation         @ POKEDEX_STATE_DELETE_CONFIRMATION
	.4byte Pokedex_ReturnToTitle        @ POKEDEX_STATE_RETURN_TO_TITLE
