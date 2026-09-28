
@ Attract-mode demos. Each IdleBoardConfig entry has 4800 ReplayInputFrame entries
@ (3 bytes of button bits per game frame).
@ Eeach GameState is one PinballGame snapshot the demo starts from.
gIdleBoardConfig0:: @ 0x081450F4
	.incbin "data/idle_board/replay_input_0.bin"

gIdleBoardConfig2:: @ 0x08148934
	.incbin "data/idle_board/replay_input_2.bin"

gIdleBoardConfig3:: @ 0x0814C174
	.incbin "data/idle_board/replay_input_3.bin"

gIdleBoardConfig1:: @ 0x0814F9B4
	.incbin "data/idle_board/replay_input_1.bin"

gIdleBoardGameState0:: @ 0x081531F4
	.incbin "data/idle_board/game_state_0.bin"

gIdleBoardGameState2:: @ 0x08154618
	.incbin "data/idle_board/game_state_2.bin"

gIdleBoardGameState3:: @ 0x08155A3C
	.incbin "data/idle_board/game_state_3.bin"

gIdleBoardGameState1:: @ 0x08156E60
	.incbin "data/idle_board/game_state_1.bin"
