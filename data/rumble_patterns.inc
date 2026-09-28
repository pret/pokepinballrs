
gRumblePattern0:: @ 0x086A4B08
	.4byte 2, 1, -1

gRumblePattern1:: @ 0x086A4B14
	.4byte 2, 0, -1

gRumblePattern2:: @ 0x086A4B20
	.4byte 2, 2, 1, -1

gRumblePattern3:: @ 0x086A4B30
	.4byte 2, 2, 0, -1

gRumblePattern4:: @ 0x086A4B40
	.4byte 2, 1, -21, 2, -1

gRumblePattern5:: @ 0x086A4B54
	.4byte 2, 2, 1, 0, -11, 4, -1

gRumblePattern6:: @ 0x086A4B70
	.4byte 2, 2, 1, -1

gRumblePattern7:: @ 0x086A4B80
	.4byte 2, 2, 2, 1, -1

gRumblePattern8:: @ 0x086A4B94
	.4byte 2, 2, 2, 2, 1, -1

gRumblePattern9:: @ 0x086A4BAC
	.4byte 2, 2, 2, 2, 2, 1, -1

gRumblePattern10:: @ 0x086A4BC8
	.4byte 1, 1, 2, 2, 2, 2, 1, -1

gRumblePattern11:: @ 0x086A4BE8
	.4byte 2, 2, -10, 2, -1

gRumblePattern12:: @ 0x086A4BFC
	.4byte 2, 2, 1, 1, -3, 4, -1

gRumblePattern13:: @ 0x086A4C18
	.4byte 2, 2, -5, 2, -1

gRumblePattern14:: @ 0x086A4C2C
	.4byte 2, 2, 1, -11, 3, -1

gRumblePatterns:: @ 0x086A4C44
	.4byte gRumblePattern0
	.4byte gRumblePattern1
	.4byte gRumblePattern2
	.4byte gRumblePattern3
	.4byte gRumblePattern4
	.4byte gRumblePattern5
	.4byte gRumblePattern6
	.4byte gRumblePattern7
	.4byte gRumblePattern8
	.4byte gRumblePattern9
	.4byte gRumblePattern10
	.4byte gRumblePattern11
	.4byte gRumblePattern12
	.4byte gRumblePattern13
	.4byte gRumblePattern14

	.align 2, 0
