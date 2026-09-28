gHighScoresStateFuncs:: @ 0x080793E8
	.4byte LoadHighScoreGraphics
	.4byte HighScore_ShowCompletionBanner
	.4byte HighScore_FlashNewEntry
	.4byte HighScore_BrowseScores
	.4byte HighScore_NameEntry
	.4byte HighScore_InitLinkExchange
	.4byte HighScore_LinkExchangeLoop
	.4byte HighScore_LinkError
	.4byte HighScore_LinkSuccess
	.4byte HighScore_LinkRetryWait
	.4byte HighScore_ResetConfirmation
	.4byte HighScore_ExitToTitle
	.4byte HighScore_ReloadAfterLink
	.4byte HighScore_ShowMergedScores
	.4byte HighScore_ReturnToMain

gIdleHighScoresStateFuncs:: @ 0x08079424
	.4byte IdleHighScore_LoadGraphics
	.4byte IdleHighScore_AutoScroll
	.4byte IdleHighScore_Exit
