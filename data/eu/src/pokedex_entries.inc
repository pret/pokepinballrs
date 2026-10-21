@ Pokedex entries of the European version (gPokedexEntries), one struct PokedexEntry each
@ (src/pokedex.c): number, height and weight digits (imperial, metric; 10 = blank), names
@ (English, also used in Italian and Spanish; French; German), category and description in
@ English, French, German, Italian and Spanish.
@ .dexLang selects the European glyph encoding of each language (tools/preproc/asm_file.cpp);
@ {XXXX} is a raw glyph code, for the few characters drawn with a different width.
@ English categories are right-aligned, the others left-aligned.
@ eu_range 0x08063910 0x080EC4CC

	.align 2, 0
dexEntryEu1:: @ 001 TREECKO
	.2byte 0, 0, 1
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 1, 1, 0, 10, 10, 10, 5, 0  @ weight
	.dexLang EN
	.dexName "TREECKO"
	.dexLang FR
	.dexName "ARCKO"
	.dexLang DE
	.dexName "GECKARBOR"
	.dexLang EN
	.dexCategory "WOOD GECKO"
	.dexLang FR
	.dexCategoryLeftAligned "BOIS GECKO"
	.dexLang DE
	.dexCategoryLeftAligned "WALDGECKO"
	.dexLang IT
	.dexCategoryLeftAligned "LEGNOGECO"
	.dexLang ES
	.dexCategoryLeftAligned "GECO BOSQUE"
	.dexLang EN
	.dexText "TREECKO has small hooks on the bottom"
	.dexText "of its feet that enable it to scale"
	.dexText "vertical walls."
	.dexText "This POKéMON attacks by slamming foes"
	.dexText "with its thick tail."
	.dexText ""
	.dexLang FR
	.dexText "ARCKO est doté de petits"
	.dexText "crochets sous les pattes, ce qui lui"
	.dexText "permet de grimper aux murs."
	.dexText "Ce POKéMON attaque en frappant ses"
	.dexText "ennemis avec son épaisse queue."
	.dexText ""
	.dexLang DE
	.dexText "Mit den kleinen Haken unter seinen"
	.dexText "Füßen kann GECKARBOR an Wänden"
	.dexText "hochklettern. Dieses POKéMON greift"
	.dexText "Feinde an, indem es mit seinem"
	.dexText "mächtigen Schweif zuschlägt."
	.dexText ""
	.dexLang IT
	.dexText "TREECKO è dotato di piccoli uncini"
	.dexText "sulla pianta delle zampe inferiori, che"
	.dexText "gli consentono di camminare su pareti"
	.dexText "verticali. Attacca frustando i suoi"
	.dexText "nemici con la coda grossa e forte."
	.dexText ""
	.dexLang ES
	.dexText "TREECKO tiene unos ganchos pequeños"
	.dexText "en las plantas de los pies con los que"
	.dexText "puede escalar superficies verticales."
	.dexText "Este POKéMON ataca dando un golpetazo"
	.dexText "con la cola."
	.dexText ""

	.align 2, 0
dexEntryEu2:: @ 002 GROVYLE
	.2byte 0, 0, 2
	.2byte 10, 2, 1, 1, 10, 10, 0, 9  @ height
	.2byte 10, 10, 4, 7, 6, 10, 10, 2, 1, 6  @ weight
	.dexLang EN
	.dexName "GROVYLE"
	.dexLang FR
	.dexName "MASSKO"
	.dexLang DE
	.dexName "REPTAIN"
	.dexLang EN
	.dexCategory "WOOD GECKO"
	.dexLang FR
	.dexCategoryLeftAligned "BOIS GECKO"
	.dexLang DE
	.dexCategoryLeftAligned "WALDGECKO"
	.dexLang IT
	.dexCategoryLeftAligned "LEGNOGECO"
	.dexLang ES
	.dexCategoryLeftAligned "GECO BOSQUE"
	.dexLang EN
	.dexText "The leaves growing out of GROVYLE`s"
	.dexText "body are convenient for camouflaging"
	.dexText "it from enemies in the forest."
	.dexText "This POKéMON is a master at climbing"
	.dexText "trees in jungles."
	.dexText ""
	.dexLang FR
	.dexText "Les feuilles qui poussent sur le corps"
	.dexText "de MASSKO sont bien pratiques"
	.dexText "lorsqu`il veut se camoufler"
	.dexText "dans la forêt. Ce POKéMON est passé"
	.dexText "maître dans l`art de grimper aux arbres."
	.dexText ""
	.dexLang DE
	.dexText "REPTAIN kann sich mit den Blättern, die"
	.dexText "aus seinem Körper herauswachsen, im"
	.dexText "Wald hervorragend tarnen."
	.dexText "Dieses POKéMON ist ein wahrer Meister"
	.dexText "darin, auf die Bäume des Dschungels zu"
	.dexText "klettern."
	.dexLang IT
	.dexText "Le foglie che crescono sul corpo di"
	.dexText "GROVYLE sono utili per mimetizzarsi"
	.dexText "contro i nemici nella foresta."
	.dexText "Questo POKéMON sa arrampicarsi"
	.dexText "sugli alberi della giungla con"
	.dexText "una maestria senza pari."
	.dexLang ES
	.dexText "Las hojas que GROVYLE tiene por el"
	.dexText "cuerpo le resultan muy útiles para"
	.dexText "camuflarse en el bosque y esconderse"
	.dexText "de los enemigos."
	.dexText "A este POKéMON no hay quien lo supere"
	.dexText "subiendo a los árboles del bosque."

	.align 2, 0
dexEntryEu3:: @ 003 SCEPTILE
	.2byte 0, 0, 3
	.2byte 10, 5, 0, 7, 10, 10, 1, 7  @ height
	.2byte 10, 1, 1, 5, 1, 10, 10, 5, 2, 2  @ weight
	.dexLang EN
	.dexName "SCEPTILE"
	.dexLang FR
	.dexName "JUNGKO"
	.dexLang DE
	.dexName "GEWALDRO"
	.dexLang EN
	.dexCategory "FOREST"
	.dexLang FR
	.dexCategoryLeftAligned "FORET"
	.dexLang DE
	.dexCategoryLeftAligned "DSCHUNGEL"
	.dexLang IT
	.dexCategoryLeftAligned "FORESTA"
	.dexLang ES
	.dexCategoryLeftAligned "MONTE"
	.dexLang EN
	.dexText "The leaves growing on SCEPTILE`s body"
	.dexText "are very sharp edged. This POKéMON is"
	.dexText "very agile - it leaps all over the"
	.dexText "branches of trees and jumps on its foe"
	.dexText "from above or behind."
	.dexText ""
	.dexLang FR
	.dexText "Les feuilles qui poussent sur le corps"
	.dexText "de JUNGKO sont extrêmement"
	.dexText "tranchantes. Ce POKéMON est très agile."
	.dexText "Il bondit de branche en branche avant"
	.dexText "de sauter sur son ennemi."
	.dexText ""
	.dexLang DE
	.dexText "Die Blätter, die auf GEWALDROs Körper"
	.dexText "wachsen, sind sehr scharfkantig. Dieses"
	.dexText "POKéMON ist sehr agil. Es hüpft von"
	.dexText "Ast zu Ast und springt seine Feinde"
	.dexText "von oben oder hinten an."
	.dexText ""
	.dexLang IT
	.dexText "Le foglie che crescono sul corpo di"
	.dexText "SCEPTILE hanno margini taglienti."
	.dexText "Questo POKéMON è agilissimo,"
	.dexText "infatti salta da un ramo all`altro e"
	.dexText "piomba sui nemici sorprendendoli"
	.dexText "dall`alto."
	.dexLang ES
	.dexText "Las hojas que le salen a SCEPTILE del"
	.dexText "cuerpo tienen unos bordes muy afilados."
	.dexText "Este POKéMON es muy ágil, va saltando"
	.dexText "de rama en rama y se lanza sobre"
	.dexText "el enemigo por la espalda."
	.dexText ""

	.align 2, 0
dexEntryEu4:: @ 004 TORCHIC
	.2byte 0, 0, 4
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 10, 5, 5, 10, 10, 10, 2, 5  @ weight
	.dexLang EN
	.dexName "TORCHIC"
	.dexLang FR
	.dexName "POUSSIFEU"
	.dexLang DE
	.dexName "FLEMMLI"
	.dexLang EN
	.dexCategory "CHICK"
	.dexLang FR
	.dexCategoryLeftAligned "POUSSIN"
	.dexLang DE
	.dexCategoryLeftAligned "KÜKEN"
	.dexLang IT
	.dexCategoryLeftAligned "PULCINO"
	.dexLang ES
	.dexCategoryLeftAligned "POLLUELO"
	.dexLang EN
	.dexText "TORCHIC sticks with its TRAINER,"
	.dexText "following behind with unsteady"
	.dexText "steps."
	.dexText "This POKéMON breathes fire of over"
	.dexText "1,800 degrees F, including fireballs"
	.dexText "that leave the foe scorched black."
	.dexLang FR
	.dexText "POUSSIFEU ne lâche pas son DRESSEUR"
	.dexText "d`une semelle, marchant maladroitement"
	.dexText "derrière lui."
	.dexText "Ce POKéMON crache des flammes pouvant"
	.dexText "atteindre 1 000 degrés et des boules"
	.dexText "de feu qui carbonisent l`ennemi."
	.dexLang DE
	.dexText "FLEMMLI hängt an seinem Trainer wie"
	.dexText "eine Klette. Es schlurft immer hinter ihm"
	.dexText "her. Dieses POKéMON spuckt 1000 Grad"
	.dexText "heißes Feuer, das seinen Feinden"
	.dexText "ordentlich einheizt."
	.dexText ""
	.dexLang IT
	.dexText "TORCHIC segue il proprio ALLENATORE"
	.dexText "ovunque, saltellandogli dietro"
	.dexText "con passo incerto."
	.dexText "Questo POKéMON sputa fiammate roventi"
	.dexText "a 1000 gradi C, con sfere infuocate"
	.dexText "capaci di carbonizzare il nemico."
	.dexLang ES
	.dexText "TORCHIC no se separa de su ENTRENADOR."
	.dexText "Siempre va detrás de él con sus pasitos"
	.dexText "inseguros."
	.dexText "Este POKéMON echa fuego en forma"
	.dexText "de bola, que llega a subir la temperatura"
	.dexText "hasta 1.000 grados centígrados."

	.align 2, 0
dexEntryEu5:: @ 005 COMBUSKEN
	.2byte 0, 0, 5
	.2byte 10, 2, 1, 1, 10, 10, 0, 9  @ height
	.2byte 10, 10, 4, 3, 0, 10, 10, 1, 9, 5  @ weight
	.dexLang EN
	.dexName "COMBUSKEN"
	.dexLang FR
	.dexName "GALIFEU"
	.dexLang DE
	.dexName "JUNGGLUT"
	.dexLang EN
	.dexCategory "YOUNG FOWL"
	.dexLang FR
	.dexCategoryLeftAligned "POULET"
	.dexLang DE
	.dexCategoryLeftAligned "KLEINHAHN"
	.dexLang IT
	.dexCategoryLeftAligned "RAMPOLLO"
	.dexLang ES
	.dexCategoryLeftAligned "AVE CORRAL"
	.dexLang EN
	.dexText "COMBUSKEN toughens up its legs and"
	.dexText "thighs by running through fields and"
	.dexText "mountains."
	.dexText "This POKéMON`s legs possess both speed"
	.dexText "and power, enabling it to dole out ten"
	.dexText "kicks in one second."
	.dexLang FR
	.dexText "GALIFEU muscle ses cuisses et ses"
	.dexText "mollets en courant dans les champs"
	.dexText "ou dans les montagnes."
	.dexText "Les jambes de ce POKéMON sont très"
	.dexText "puissantes et rapides, capables de"
	.dexText "donner 10 coups de pied en 1 seconde."
	.dexLang DE
	.dexText "JUNGGLUT trainiert seine Beine und"
	.dexText "Oberschenkel, indem es über Felder und"
	.dexText "Berge läuft. Die Beine dieses POKéMON"
	.dexText "sind sowohl schnell als auch kräftig,"
	.dexText "so dass es 10 Tritte pro Sekunde"
	.dexText "ausführen kann."
	.dexLang IT
	.dexText "COMBUSKEN allena gli arti superiori e"
	.dexText "inferiori correndo in campagna e in"
	.dexText "montagna."
	.dexText "Le zampe inferiori sono rapide"
	.dexText "e potenti e riescono a sferrare"
	.dexText "dieci calci al secondo."
	.dexLang ES
	.dexText "COMBUSKEN fortalece las piernas"
	.dexText "corriendo por llanos y montañas."
	.dexText "Este POKéMON tiene en las extremidades"
	.dexText "inferiores tanto fuerza como velocidad."
	.dexText "Puede dar hasta diez patadas"
	.dexText "por segundo."

	.align 2, 0
dexEntryEu6:: @ 006 BLAZIKEN
	.2byte 0, 0, 6
	.2byte 10, 6, 0, 3, 10, 10, 1, 9  @ height
	.2byte 10, 1, 1, 4, 6, 10, 10, 5, 2, 0  @ weight
	.dexLang EN
	.dexName "BLAZIKEN"
	.dexLang FR
	.dexName "BRASEGALI"
	.dexLang DE
	.dexName "LOHGOCK"
	.dexLang EN
	.dexCategory "BLAZE"
	.dexLang FR
	.dexCategoryLeftAligned "ARDENT"
	.dexLang DE
	.dexCategoryLeftAligned "GROSSBRAND"
	.dexLang IT
	.dexCategoryLeftAligned "VAMPE"
	.dexLang ES
	.dexCategoryLeftAligned "LLAMEANTE"
	.dexLang EN
	.dexText "In battle, BLAZIKEN blows out intense"
	.dexText "flames from its wrists and attacks foes"
	.dexText "courageously."
	.dexText "The stronger the foe, the more"
	.dexText "intensely this POKéMON`s wrists burn."
	.dexText ""
	.dexLang FR
	.dexText "Au combat, BRASEGALI envoie des"
	.dexText "flammes ardentes de ses poignets. Il"
	.dexText "fait preuve d`un courage exceptionnel."
	.dexText "Plus l`ennemi est puissant, plus les"
	.dexText "poignets de ce POKéMON sont ardents."
	.dexText ""
	.dexLang DE
	.dexText "LOHGOCK stößt heftige Flammen aus"
	.dexText "seinen Handgelenken aus und greift"
	.dexText "seine Feinde mutig an. Je stärker ein"
	.dexText "Feind ist, desto stärker lodern die"
	.dexText "Handgelenke dieses POKéMON."
	.dexText ""
	.dexLang IT
	.dexText "In lotta BLAZIKEN emette fiamme"
	.dexText "micidiali coi suoi pugni, attaccando"
	.dexText "coraggiosamente il nemico."
	.dexText "Più forte è il nemico, tanto più intenso"
	.dexText "è il fuoco proveniente dai pugni."
	.dexText ""
	.dexLang ES
	.dexText "En combate, BLAZIKEN expulsa vivas"
	.dexText "llamas por las muñecas y ataca"
	.dexText "al enemigo con fiereza."
	.dexText "Cuanto más fuerte sea el enemigo,"
	.dexText "más intensas serán las llamas."
	.dexText ""

	.align 2, 0
dexEntryEu7:: @ 007 MUDKIP
	.2byte 0, 0, 7
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 1, 6, 8, 10, 10, 10, 7, 6  @ weight
	.dexLang EN
	.dexName "MUDKIP"
	.dexLang FR
	.dexName "GOBOU"
	.dexLang DE
	.dexName "HYDROPI"
	.dexLang EN
	.dexCategory "MUD FISH"
	.dexLang FR
	.dexCategoryLeftAligned "POISSONBOUE"
	.dexLang DE
	.dexCategoryLeftAligned "LEHMHÜPFER"
	.dexLang IT
	.dexCategoryLeftAligned "FANGO PESCE"
	.dexLang ES
	.dexCategoryLeftAligned "PEZ LODO"
	.dexLang EN
	.dexText "In water, MUDKIP breathes using the"
	.dexText "gills on its cheeks."
	.dexText "If it is faced with a tight situation in"
	.dexText "battle, this POKéMON will unleash its"
	.dexText "amazing power - it can crush rocks"
	.dexText "bigger than itself."
	.dexLang FR
	.dexText "Sous l`eau, GOBOU peut respirer"
	.dexText "grâce aux branchies sur ses joues."
	.dexText "S`il se retrouve en difficulté pendant"
	.dexText "un combat, ce POKéMON déchaîne ses"
	.dexText "pouvoirs incroyables. Il peut détruire"
	.dexText "des rochers plus gros que lui."
	.dexLang DE
	.dexText "Im Wasser atmet HYDROPI durch die"
	.dexText "Kiemen an seinen Wangen. Wenn es im"
	.dexText "Kampf in eine brenzlige Situation gerät,"
	.dexText "setzt es seine verblüffende Kraft ein,"
	.dexText "mit der es Felsbrocken zerquetschen"
	.dexText "kann, die größer sind als es selbst."
	.dexLang IT
	.dexText "In acqua MUDKIP respira usando"
	.dexText "le branchie sulle mascelle."
	.dexText "In caso di situazioni critiche in lotta"
	.dexText "scatena la sua forza strabiliante,"
	.dexText "riuscendo a frantumare rocce"
	.dexText "più grandi di lui."
	.dexLang ES
	.dexText "En el agua, MUDKIP usa las branquias que"
	.dexText "tiene en los mofletes para respirar."
	.dexText "Cuando tiene que enfrentarse a una"
	.dexText "situación delicada en combate, desata"
	.dexText "una fuerza asombrosa con la que puede"
	.dexText "destruir rocas incluso mayores que él."

	.align 2, 0
dexEntryEu8:: @ 008 MARSHTOMP
	.2byte 0, 0, 8
	.2byte 10, 2, 0, 4, 10, 10, 0, 7  @ height
	.2byte 10, 10, 6, 1, 7, 10, 10, 2, 8, 0  @ weight
	.dexLang EN
	.dexName "MARSHTOMP"
	.dexLang FR
	.dexName "FLOBIO"
	.dexLang DE
	.dexName "MOORABBEL"
	.dexLang EN
	.dexCategory "MUD FISH"
	.dexLang FR
	.dexCategoryLeftAligned "POISSONBOUE"
	.dexLang DE
	.dexCategoryLeftAligned "LEHMHÜPFER"
	.dexLang IT
	.dexCategoryLeftAligned "FANGO PESCE"
	.dexLang ES
	.dexCategoryLeftAligned "PEZ LODO"
	.dexLang EN
	.dexText "MARSHTOMP is much faster at traveling"
	.dexText "through mud than it is at swimming."
	.dexText "This POKéMON`s hindquarters exhibit"
	.dexText "obvious development, giving it the"
	.dexText "ability to walk on just its hind legs."
	.dexText ""
	.dexLang FR
	.dexText "FLOBIO est bien plus rapide dans"
	.dexText "la boue que dans l`eau. L`arrière-train"
	.dexText "de ce POKéMON est particulièrement"
	.dexText "développé, ce qui lui donne la"
	.dexText "capacité de marcher sur ses pattes"
	.dexText "arrière."
	.dexLang DE
	.dexText "MOORABBEL kommt im Schlamm besser"
	.dexText "voran als im Wasser. Das Hinterteil"
	.dexText "dieses POKéMON ist gut entwickelt,"
	.dexText "so dass es auf seinen Hinterbeinen"
	.dexText "laufen kann."
	.dexText ""
	.dexLang IT
	.dexText "MARSHTOMP è molto più a suo agio nel"
	.dexText "fango che non in acqua e sa muoversi"
	.dexText "con estrema rapidità."
	.dexText "La parte inferiore del suo corpo mostra"
	.dexText "un chiaro sviluppo, consentendogli di"
	.dexText "camminare solo sugli arti inferiori."
	.dexLang ES
	.dexText "MARSHTOMP se desplaza más rápido por"
	.dexText "el lodo que por el agua. Los cuartos"
	.dexText "traseros de este POKéMON muestran"
	.dexText "un desarrollo más que evidente, que le"
	.dexText "han proporcionado la habilidad de andar"
	.dexText "sólo sobre las patas traseras."

	.align 2, 0
dexEntryEu9:: @ 009 SWAMPERT
	.2byte 0, 0, 9
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 1, 8, 0, 6, 10, 10, 8, 1, 9  @ weight
	.dexLang EN
	.dexName "SWAMPERT"
	.dexLang FR
	.dexName "LAGGRON"
	.dexLang DE
	.dexName "SUMPEX"
	.dexLang EN
	.dexCategory "MUD FISH"
	.dexLang FR
	.dexCategoryLeftAligned "POISSONBOUE"
	.dexLang DE
	.dexCategoryLeftAligned "LEHMHÜPFER"
	.dexLang IT
	.dexCategoryLeftAligned "FANGO PESCE"
	.dexLang ES
	.dexCategoryLeftAligned "PEZ LODO"
	.dexLang EN
	.dexText "SWAMPERT predicts storms by sensing"
	.dexText "subtle differences in the sounds of"
	.dexText "waves and tidal winds with its fins."
	.dexText "If a storm is approaching, it piles up"
	.dexText "boulders to protect itself."
	.dexText ""
	.dexLang FR
	.dexText "LAGGRON peut prédire l`arrivée des"
	.dexText "tempêtes en utilisant ses nageoires"
	.dexText "pour sentir les variations dans les"
	.dexText "vagues et les marées. Si une tempête"
	.dexText "s`approche, il empile des rochers pour"
	.dexText "protéger son habitat."
	.dexLang DE
	.dexText "SUMPEX kann Stürme voraussagen,"
	.dexText "indem es feine Veränderungen der"
	.dexText "Geräusche von Wellen und Wind mit"
	.dexText "seinen Finnen wahrnimmt. Wenn eine"
	.dexText "Sturmfront aufzieht, häuft es"
	.dexText "Felsbrocken an, um sich zu schützen."
	.dexLang IT
	.dexText "SWAMPERT prevede le tempeste poiché"
	.dexText "grazie alle pinne percepisce le sottili"
	.dexText "differenze nel suono delle onde e dei"
	.dexText "venti dovuti alle maree. In caso di"
	.dexText "burrasca imminente, crea delle pile"
	.dexText "di massi per proteggere il nido."
	.dexLang ES
	.dexText "SWAMPERT puede predecir tormentas"
	.dexText "al percibir con las aletas los sutiles"
	.dexText "cambios que producen las olas"
	.dexText "y las corrientes. Si está a punto"
	.dexText "de estallar una tormenta, empezará"
	.dexText "a apilar piedras para resguardarse."

	.align 2, 0
dexEntryEu10:: @ 010 POOCHYENA
	.2byte 0, 1, 0
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 3, 0, 0, 10, 10, 1, 3, 6  @ weight
	.dexLang EN
	.dexName "POOCHYENA"
	.dexLang FR
	.dexName "MEDHYENA"
	.dexLang DE
	.dexName "FIFFYEN"
	.dexLang EN
	.dexCategory "BITE"
	.dexLang FR
	.dexCategoryLeftAligned "MORSURE"
	.dexLang DE
	.dexCategoryLeftAligned "BISS"
	.dexLang IT
	.dexCategoryLeftAligned "MORSO"
	.dexLang ES
	.dexCategoryLeftAligned "MORDISCO"
	.dexLang EN
	.dexText "At first sight, POOCHYENA takes a bite"
	.dexText "at anything that moves."
	.dexText "This POKéMON chases after prey until"
	.dexText "the victim becomes exhausted."
	.dexText "However, it may turn tail if the prey"
	.dexText "strikes back."
	.dexLang FR
	.dexText "Sans se poser de questions, MEDHYENA"
	.dexText "essaye de mordre tout ce qui bouge."
	.dexText "Ce POKéMON pourchasse sa proie"
	.dexText "jusqu`à ce qu`elle s`épuise. Cependant,"
	.dexText "il se peut qu`il prenne peur et s`enfuie"
	.dexText "si la proie riposte."
	.dexLang DE
	.dexText "Sobald FIFFYEN eine Bewegung wahr-"
	.dexText "nimmt, schnappt es zu. Es jagt seine"
	.dexText "Beute so lange, bis sie vollkommen"
	.dexText "erschöpft ist. Wenn sich die Beute"
	.dexText "allerdings wehrt, kann es passieren,"
	.dexText "dass FIFFYEN klein beigibt und flieht."
	.dexLang IT
	.dexText "POOCHYENA azzanna al minimo"
	.dexText "movimento anche senza sapere cos`è."
	.dexText "Caccia la sua preda finché questa"
	.dexText "non è tanto stanca da cedere."
	.dexText "Tuttavia, se il nemico contrattacca,"
	.dexText "POOCHYENA talvolta scappa."
	.dexLang ES
	.dexText "La primera reacción que POOCHYENA"
	.dexText "tiene al ver algo moverse es darle un"
	.dexText "mordisco. Este POKéMON persigue a su"
	.dexText "presa hasta que cae agotada. Aunque,"
	.dexText "a veces, sale huyendo si su presa le"
	.dexText "responde con un ataque."

	.align 2, 0
dexEntryEu11:: @ 011 MIGHTYENA
	.2byte 0, 1, 1
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 10, 8, 1, 6, 10, 10, 3, 7, 0  @ weight
	.dexLang EN
	.dexName "MIGHTYENA"
	.dexLang FR
	.dexName "GRAHYENA"
	.dexLang DE
	.dexName "MAGNAYEN"
	.dexLang EN
	.dexCategory "BITE"
	.dexLang FR
	.dexCategoryLeftAligned "MORSURE"
	.dexLang DE
	.dexCategoryLeftAligned "BISS"
	.dexLang IT
	.dexCategoryLeftAligned "MORSO"
	.dexLang ES
	.dexCategoryLeftAligned "MORDISCO"
	.dexLang EN
	.dexText "MIGHTYENA gives obvious signals when"
	.dexText "it is preparing to attack. It starts to"
	.dexText "growl deeply and then flattens its body."
	.dexText "This POKéMON will bite savagely with its"
	.dexText "sharply pointed fangs."
	.dexText ""
	.dexLang FR
	.dexText "On peut facilement deviner quand"
	.dexText "GRAHYENA se prépare à attaquer. Il"
	.dexText "grogne et se met à plat ventre."
	.dexText "Ce POKéMON mord sauvagement ses"
	.dexText "ennemis avec ses crocs acérés."
	.dexText ""
	.dexLang DE
	.dexText "MAGNAYEN sendet deutliche Signale"
	.dexText "aus, wenn es sich auf einen Angriff"
	.dexText "vorbereitet. Es knurrt heftig und macht"
	.dexText "sich flach. Dieses POKéMON kann mit"
	.dexText "seinen spitzen Zähnen brutal zubeißen."
	.dexText ""
	.dexLang IT
	.dexText "MIGHTYENA invia chiari segnali quando"
	.dexText "sta preparando un attacco. Inizia a"
	.dexText "ringhiare cupo e a lisciarsi il pelo."
	.dexText "Morde selvaggiamente con le zanne"
	.dexText "appuntite ed affilate."
	.dexText ""
	.dexLang ES
	.dexText "Es muy fácil prever cuándo va a atacar"
	.dexText "MIGHTYENA; se pone a gruñir con fuerza"
	.dexText "y se estira."
	.dexText "Este POKéMON da unos mordiscos"
	.dexText "tremendos con los afilados colmillos"
	.dexText "que tiene."

	.align 2, 0
dexEntryEu12:: @ 012 ZIGZAGOON
	.2byte 0, 1, 2
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 3, 8, 6, 10, 10, 1, 7, 5  @ weight
	.dexLang EN
	.dexName "ZIGZAGOON"
	.dexLang FR
	.dexName "ZIGZATON"
	.dexLang DE
	.dexName "ZIGZACHS"
	.dexLang EN
	.dexCategory "TINYRACCOON"
	.dexLang FR
	.dexCategoryLeftAligned "PETIT RATON"
	.dexLang DE
	.dexCategoryLeftAligned "KLEINDACHS"
	.dexLang IT
	.dexCategoryLeftAligned "PROCIONE"
	.dexLang ES
	.dexCategoryLeftAligned "MAPACHITO"
	.dexLang EN
	.dexText "ZIGZAGOON restlessly wanders"
	.dexText "everywhere at all times. This POKéMON"
	.dexText "does so because it is very curious."
	.dexText "It becomes interested in anything"
	.dexText "that it happens to see."
	.dexText ""
	.dexLang FR
	.dexText "ZIGZATON se promène nerveusement"
	.dexText "un peu partout. En effet, ce POKéMON"
	.dexText "est très curieux."
	.dexText "Tout ce qu`il voit l`intéresse."
	.dexText ""
	.dexText ""
	.dexLang DE
	.dexText "ZIGZACHS ist ein rastloser Wanderer."
	.dexText "Dieses POKéMON ist nämlich sehr"
	.dexText "neugierig und es inspiziert alles,"
	.dexText "was ihm zufällig begegnet."
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "ZIGZAGOON scorrazza a destra e a manca"
	.dexText "senza sosta, a causa della sua indole"
	.dexText "molto curiosa."
	.dexText "Qualunque cosa veda riesce"
	.dexText "ad attirare la sua attenzione."
	.dexText ""
	.dexLang ES
	.dexText "ZIGZAGOON está todo el día dando"
	.dexText "vueltas de aquí para allá."
	.dexText "Es un POKéMON muy inquieto."
	.dexText "Se interesa por todo lo que se"
	.dexText "encuentra en su camino."
	.dexText ""

	.align 2, 0
dexEntryEu13:: @ 013 LINOONE
	.2byte 0, 1, 3
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 7, 1, 6, 10, 10, 3, 2, 5  @ weight
	.dexLang EN
	.dexName "LINOONE"
	.dexLang FR
	.dexName "LINEON"
	.dexLang DE
	.dexName "GERADAKS"
	.dexLang EN
	.dexCategory "RUSHING"
	.dexLang FR
	.dexCategoryLeftAligned "FONCEUR"
	.dexLang DE
	.dexCategoryLeftAligned "SPRINTER"
	.dexLang IT
	.dexCategoryLeftAligned "SFRECCIANTE"
	.dexLang ES
	.dexCategoryLeftAligned "LANZADO"
	.dexLang EN
	.dexText "LINOONE always runs full speed and only"
	.dexText "in straight lines. If facing an obstacle,"
	.dexText "it makes a right-angle turn to evade it."
	.dexText "This POKéMON is very challenged by"
	.dexText "gently curving roads."
	.dexText ""
	.dexLang FR
	.dexText "LINEON court très vite et toujours"
	.dexText "en ligne droite. Si un obstacle survient,"
	.dexText "il l`évite en prenant un angle droit."
	.dexText "Ce POKéMON a beaucoup de mal à suivre"
	.dexText "les routes légèrement courbées."
	.dexText ""
	.dexLang DE
	.dexText "GERADAKS rennt immer mit vollem Tempo"
	.dexText "und nie im Zickzack, sondern nur gerade."
	.dexText "Wenn ihm ein Hindernis im Weg ist,"
	.dexText "läuft es rechtwinklig daran vorbei. Für"
	.dexText "dieses POKéMON stellen leichte Kurven"
	.dexText "eine große Herausforderung dar."
	.dexLang IT
	.dexText "LINOONE è solito correre a tutta"
	.dexText "velocità e sempre in linea retta."
	.dexText "Davanti ad un ostacolo fa una curva"
	.dexText "ad angolo retto per evitarlo. Questo"
	.dexText "POKéMON si trova in difficoltà su"
	.dexText "percorsi con curve poco accentuate."
	.dexLang ES
	.dexText "LINOONE siempre corre todo lo rápido"
	.dexText "que puede y sólo en línea recta."
	.dexText "Si encuentra un obstáculo en el camino,"
	.dexText "se moverá hacia la derecha para"
	.dexText "esquivarlo. Correr bien por caminos"
	.dexText "tortuosos es todo un reto para él."

	.align 2, 0
dexEntryEu14:: @ 014 WURMPLE
	.2byte 0, 1, 4
	.2byte 10, 1, 0, 0, 10, 10, 0, 3  @ height
	.2byte 10, 10, 10, 7, 9, 10, 10, 10, 3, 6  @ weight
	.dexLang EN
	.dexName "WURMPLE"
	.dexLang FR
	.dexName "CHENIPOTTE"
	.dexLang DE
	.dexName "WAUMPEL"
	.dexLang EN
	.dexCategory "WORM"
	.dexLang FR
	.dexCategoryLeftAligned "VER"
	.dexLang DE
	.dexCategoryLeftAligned "WURM"
	.dexLang IT
	.dexCategoryLeftAligned "BACO"
	.dexLang ES
	.dexCategoryLeftAligned "GUSANO"
	.dexLang EN
	.dexText "WURMPLE is targeted by SWELLOW as"
	.dexText "prey. This POKéMON will try to resist by"
	.dexText "pointing the spikes on its rear at the"
	.dexText "attacking predator."
	.dexText "It will weaken the foe by leaking poison"
	.dexText "from the spikes."
	.dexLang FR
	.dexText "CHENIPOTTE est la proie de HELEDELLE."
	.dexText "Ce POKéMON essaye de résister en"
	.dexText "dirigeant les pointes de son dos vers"
	.dexText "le prédateur."
	.dexText "Il affaiblit son ennemi en lui injectant"
	.dexText "du poison."
	.dexLang DE
	.dexText "WAUMPEL wird von SCHWALBOSS als Beute"
	.dexText "angesehen. Dieses POKéMON wehrt sich"
	.dexText "gegen angreifende Räuber, indem es die"
	.dexText "Stacheln an seinem Hinterteil auf sie"
	.dexText "richtet. Es schwächt seine Gegner mit"
	.dexText "dem Gift, das aus den Stacheln austritt."
	.dexLang IT
	.dexText "WURMPLE è la preda favorita di SWELLOW."
	.dexText "Questo POKéMON cerca di resistere"
	.dexText "puntando gli aculei irti sulla schiena"
	.dexText "contro il predatore che attacca."
	.dexText "Poi indebolisce il nemico emettendo"
	.dexText "veleno da questi aculei."
	.dexLang ES
	.dexText "WURMPLE es la presa preferida de"
	.dexText "SWELLOW. La forma que tiene de intentar"
	.dexText "defenderse es apuntar con las púas"
	.dexText "del lomo al amenazante enemigo"
	.dexText "y debilitarlo inyectándole veneno."
	.dexText ""

	.align 2, 0
dexEntryEu15:: @ 015 SILCOON
	.2byte 0, 1, 5
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 2, 2, 0, 10, 10, 1, 0, 0  @ weight
	.dexLang EN
	.dexName "SILCOON"
	.dexLang FR
	.dexName "ARMULYS"
	.dexLang DE
	.dexName "SCHALOKO"
	.dexLang EN
	.dexCategory "COCOON"
	.dexLang FR
	.dexCategoryLeftAligned "COCON"
	.dexLang DE
	.dexCategoryLeftAligned "KOKON"
	.dexLang IT
	.dexCategoryLeftAligned "BOZZOLO"
	.dexLang ES
	.dexCategoryLeftAligned "CAPULLO"
	.dexLang EN
	.dexText "SILCOON was thought to endure hunger"
	.dexText "and not consume anything before its"
	.dexText "evolution. However, it is now thought"
	.dexText "that this POKéMON slakes its thirst by"
	.dexText "drinking rainwater that collects on its"
	.dexText "silk."
	.dexLang FR
	.dexText "On pensait qu`ARMULYS pouvait"
	.dexText "résister à la faim et ne consommait rien"
	.dexText "avant son évolution. On sait maintenant"
	.dexText "que ce POKéMON étanche sa soif en"
	.dexText "récupérant l`eau de pluie déposée"
	.dexText "sur sa soie."
	.dexLang DE
	.dexText "Bisher nahm man an, dass SCHALOKO vor"
	.dexText "seiner Entwicklung hungert und"
	.dexText "überhaupt nichts zu sich nimmt. Nun"
	.dexText "aber wird behauptet, dass es seinen"
	.dexText "Durst mit Regenwasser löscht, das sich"
	.dexText "auf seinem seidigen Fell sammelt."
	.dexLang IT
	.dexText "In passato si pensava che SILCOON"
	.dexText "resistesse alla fame senza ingerire"
	.dexText "nulla fino all`evoluzione. Tuttavia,"
	.dexText "ora si presume che il POKéMON plachi"
	.dexText "la sua sete bevendo l`acqua piovana"
	.dexText "che si posa sul suo bozzolo."
	.dexLang ES
	.dexText "Se pensaba que SILCOON podía aguantar"
	.dexText "el hambre y no consumir nada antes de"
	.dexText "evolucionar. Sin embargo, ahora se cree"
	.dexText "que sacia su necesidad bebiendo el agua"
	.dexText "de la lluvia que se le queda sobre la"
	.dexText "piel."

	.align 2, 0
dexEntryEu16:: @ 016 BEAUTIFLY
	.2byte 0, 1, 6
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 10, 6, 2, 6, 10, 10, 2, 8, 4  @ weight
	.dexLang EN
	.dexName "BEAUTIFLY"
	.dexLang FR
	.dexName "CHARMILLON"
	.dexLang DE
	.dexName "PAPINELLA"
	.dexLang EN
	.dexCategory "BUTTERFLY"
	.dexLang FR
	.dexCategoryLeftAligned "PAPILLON"
	.dexLang DE
	.dexCategoryLeftAligned "FALTER"
	.dexLang IT
	.dexCategoryLeftAligned "FARFALLA"
	.dexLang ES
	.dexCategoryLeftAligned "MARIPOSA"
	.dexLang EN
	.dexText "BEAUTIFLY has a long mouth like a coiled"
	.dexText "needle, which is very convenient for"
	.dexText "collecting pollen from flowers."
	.dexText "This POKéMON rides the spring winds as"
	.dexText "it flits around gathering pollen."
	.dexText ""
	.dexLang FR
	.dexText "CHARMILLON a une longue trompe en"
	.dexText "spirale, particulièrement pratique pour"
	.dexText "récupérer le pollen des fleurs."
	.dexText "Ce POKéMON se laisse porter par les"
	.dexText "vents printaniers pendant qu`il butine."
	.dexText ""
	.dexLang DE
	.dexText "PAPINELLA hat einen langen Rüssel, der"
	.dexText "hervorragend zum Sammeln von Blüten-"
	.dexText "pollen geeignet ist. Dieses POKéMON"
	.dexText "flattert im Frühlingswind herum"
	.dexText "und sammelt Blütenstaub."
	.dexText ""
	.dexLang IT
	.dexText "La bocca di BEAUTIFLY è costituita"
	.dexText "da un ago spiraliforme, molto utile"
	.dexText "per succhiare il polline dai fiori."
	.dexText "Questo POKéMON si fa trasportare"
	.dexText "dal vento nei suoi viaggi alla ricerca"
	.dexText "del polline."
	.dexLang ES
	.dexText "BEAUTIFLY tiene una boca enorme"
	.dexText "en espiral que parece una aguja y le"
	.dexText "resulta muy útil para recolectar polen."
	.dexText "Este POKéMON va revoloteando de flor"
	.dexText "en flor para recogerlo."
	.dexText ""

	.align 2, 0
dexEntryEu17:: @ 017 CASCOON
	.2byte 0, 1, 7
	.2byte 10, 2, 0, 4, 10, 10, 0, 7  @ height
	.2byte 10, 10, 2, 5, 4, 10, 10, 1, 1, 5  @ weight
	.dexLang EN
	.dexName "CASCOON"
	.dexLang FR
	.dexName "BLINDALYS"
	.dexLang DE
	.dexName "PANEKON"
	.dexLang EN
	.dexCategory "COCOON"
	.dexLang FR
	.dexCategoryLeftAligned "COCON"
	.dexLang DE
	.dexCategoryLeftAligned "KOKON"
	.dexLang IT
	.dexCategoryLeftAligned "BOZZOLO"
	.dexLang ES
	.dexCategoryLeftAligned "CAPULLO"
	.dexLang EN
	.dexText "If it is attacked, CASCOON remains"
	.dexText "motionless however badly it may be"
	.dexText "hurt. It does so because if it were to"
	.dexText "move, its body would be weak upon"
	.dexText "evolution. This POKéMON will also not"
	.dexText "forget the pain it endured."
	.dexLang FR
	.dexText "Lorsqu`il est attaqué, BLINDALYS"
	.dexText "reste immobile, même s`il a très mal."
	.dexText "En effet, s`il bougeait, son corps serait"
	.dexText "affaibli lors de son évolution. En"
	.dexText "revanche, ce POKéMON n`oubliera pas"
	.dexText "la douleur endurée."
	.dexLang DE
	.dexText "Wenn es angegriffen wird, bewegt sich"
	.dexText "PANEKON in keiner Weise, egal, wie"
	.dexText "schwer es dabei verletzt wird. Wenn es"
	.dexText "sich bewegen würde, wäre sein Körper zu"
	.dexText "schwach für seine Entwicklung. Die"
	.dexText "Schmerzen allerdings vergisst es nie."
	.dexLang IT
	.dexText "In caso di aggressione CASCOON rimane"
	.dexText "immobile indipendentemente dalla"
	.dexText "violenza dell`attacco subito."
	.dexText "Questo lo aiuta a rafforzare il suo"
	.dexText "corpo in vista dell`evoluzione. Non"
	.dexText "dimentica mai il dolore provato."
	.dexLang ES
	.dexText "Si atacan a CASCOON, se queda inmóvil"
	.dexText "aunque le hayan hecho mucho daño. Y es"
	.dexText "que, si se moviera, perdería fuerzas"
	.dexText "para evolucionar. Aunque nunca"
	.dexText "olvida el daño que le han hecho."
	.dexText ""

	.align 2, 0
dexEntryEu18:: @ 018 DUSTOX
	.2byte 0, 1, 8
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 10, 6, 9, 7, 10, 10, 3, 1, 6  @ weight
	.dexLang EN
	.dexName "DUSTOX"
	.dexLang FR
	.dexName "PAPINOX"
	.dexLang DE
	.dexName "PUDOX"
	.dexLang EN
	.dexCategory "POISON MOTH"
	.dexLang FR
	.dexCategoryLeftAligned "PAPIPOISON"
	.dexLang DE
	.dexCategoryLeftAligned "GIFTMOTTE"
	.dexLang IT
	.dexCategoryLeftAligned "VELENTARMA"
	.dexLang ES
	.dexCategoryLeftAligned "POLILLA V."
	.dexLang EN
	.dexText "When DUSTOX flaps its wings, a fine"
	.dexText "dust is scattered all over. This dust is"
	.dexText "actually a powerful poison that will"
	.dexText "even make a pro wrestler sick."
	.dexText "This POKéMON searches for food using"
	.dexText "its antennae like radar."
	.dexLang FR
	.dexText "Lorsque PAPINOX bat des ailes,"
	.dexText "une légère poussière se répand. Cette"
	.dexText "poussière est en fait un puissant"
	.dexText "poison capable de rendre un cheval"
	.dexText "malade. Ce POKéMON cherche sa nourri-"
	.dexText "ture avec ses antennes, comme un radar."
	.dexLang DE
	.dexText "Wenn PUDOX mit den Flügeln schlägt,"
	.dexText "verteilt es einen feinen Puder. Es"
	.dexText "handelt sich um ein starkes Gift, das"
	.dexText "sogar einen Profiboxer umhauen würde."
	.dexText "Bei der Futtersuche benutzt dieses"
	.dexText "POKéMON seine Antennen als Radar."
	.dexLang IT
	.dexText "Quando agita le ali, DUSTOX sparge"
	.dexText "una polvere sottile tutt`intorno. In"
	.dexText "realtà si tratta di un potente veleno"
	.dexText "capace di mettere al tappeto anche"
	.dexText "un campione di lotta libera. Per cercare"
	.dexText "il cibo usa le antenne come un radar."
	.dexLang ES
	.dexText "Cuando DUSTOX bate las alas, libera"
	.dexText "un polvillo fino que en realidad es un"
	.dexText "peligroso veneno que puede resultar"
	.dexText "dañino hasta al más fuerte de los"
	.dexText "fuertes. Las antenas le sirven"
	.dexText "de radar para buscar comida."

	.align 2, 0
dexEntryEu19:: @ 019 LOTAD
	.2byte 0, 1, 9
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 10, 5, 7, 10, 10, 10, 2, 6  @ weight
	.dexLang EN
	.dexName "LOTAD"
	.dexLang FR
	.dexName "NENUPIOT"
	.dexLang DE
	.dexName "LOTURZEL"
	.dexLang EN
	.dexCategory "WATER WEED"
	.dexLang FR
	.dexCategoryLeftAligned "AQUAPLANTE"
	.dexLang DE
	.dexCategoryLeftAligned "WASSERLINSE"
	.dexLang IT
	.dexCategoryLeftAligned "ALGA"
	.dexLang ES
	.dexCategoryLeftAligned "ALGA"
	.dexLang EN
	.dexText "LOTAD is said to have dwelled on land"
	.dexText "before. However, this POKéMON is"
	.dexText "thought to have returned to water"
	.dexText "because the leaf on its head grew large"
	.dexText "and heavy. It now lives by floating"
	.dexText "atop the water."
	.dexLang FR
	.dexText "On raconte que jadis, NENUPIOT vivait"
	.dexText "sur terre. Mais on pense que ce POKéMON"
	.dexText "est retourné dans l`eau car la feuille"
	.dexText "sur sa tête était devenue trop grande"
	.dexText "et trop lourde. Maintenant, il vit en"
	.dexText "flottant à la surface de l`eau."
	.dexLang DE
	.dexText "LOTURZEL soll einige Zeit an Land"
	.dexText "verbracht haben, aber ins Wasser"
	.dexText "zurückgekehrt sein, weil das Blatt"
	.dexText "auf seinem Kopf zu groß und zu schwer"
	.dexText "geworden ist. Nun lässt es sich auf dem"
	.dexText "Wasser treiben."
	.dexLang IT
	.dexText "Si dice che prima LOTAD vivesse sulla"
	.dexText "terraferma. Tuttavia, si dice che sia"
	.dexText "tornato all`acqua perché le foglie che"
	.dexText "ha sulla testa erano diventate"
	.dexText "troppo grandi e pesanti. Ora vive"
	.dexText "galleggiando a pelo d`acqua."
	.dexLang ES
	.dexText "A LOTAD se le atribuye el haber vivido"
	.dexText "antes en tierra. En cualquier caso, se"
	.dexText "cree que volvió al agua porque la hoja"
	.dexText "de la cabeza le creció mucho y le empezó"
	.dexText "a pesar. Ahora vive flotando en el agua."
	.dexText ""

	.align 2, 0
dexEntryEu20:: @ 020 LOMBRE
	.2byte 0, 2, 0
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 10, 7, 1, 6, 10, 10, 3, 2, 5  @ weight
	.dexLang EN
	.dexName "LOMBRE"
	.dexLang FR
	.dexName "LOMBRE"
	.dexLang DE
	.dexName "LOMBRERO"
	.dexLang EN
	.dexCategory "JOLLY"
	.dexLang FR
	.dexCategoryLeftAligned "JOVIAL"
	.dexLang DE
	.dexCategoryLeftAligned "FROHMUT"
	.dexLang IT
	.dexCategoryLeftAligned "GIOCOSO"
	.dexLang ES
	.dexCategoryLeftAligned "ALEGRE"
	.dexLang EN
	.dexText "LOMBRE`s entire body is covered by a"
	.dexText "slippery, slimy film. It feels horribly"
	.dexText "unpleasant to be touched by this"
	.dexText "POKéMON`s hands."
	.dexText "LOMBRE is often mistaken for a human"
	.dexText "child."
	.dexLang FR
	.dexText "Le corps de LOMBRE tout entier"
	.dexText "est recouvert d`un voile visqueux et"
	.dexText "glissant. Toucher ce POKéMON est"
	.dexText "extrêmement déplaisant. On croit"
	.dexText "souvent à tort que LOMBRE"
	.dexText "est un enfant."
	.dexLang DE
	.dexText "LOMBREROs Körper ist mit einem"
	.dexText "glitschigen Film bedeckt. Es fühlt sich"
	.dexText "widerlich an, wenn einen dieses POKéMON"
	.dexText "mit seinen Händen berührt. LOMBRERO"
	.dexText "wird häufig für ein Kind gehalten."
	.dexText ""
	.dexLang IT
	.dexText "L`intero corpo di LOMBRE è ricoperto"
	.dexText "di una pellicola viscida e scivolosa."
	.dexText "Il contatto con le sue zampe dà una"
	.dexText "sensazione orribile. Spesso LOMBRE"
	.dexText "è confuso con un bambino piccolo."
	.dexText ""
	.dexLang ES
	.dexText "LOMBRE está completamente recubierto"
	.dexText "por una película viscosa y resbaladiza."
	.dexText "La sensación que te produce al rozarte"
	.dexText "con las manos es muy desagradable."
	.dexText "A veces se confunde a este POKéMON"
	.dexText "con un niño pequeño."

	.align 2, 0
dexEntryEu21:: @ 021 LUDICOLO
	.2byte 0, 2, 1
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 1, 2, 1, 3, 10, 10, 5, 5, 0  @ weight
	.dexLang EN
	.dexName "LUDICOLO"
	.dexLang FR
	.dexName "LUDICOLO"
	.dexLang DE
	.dexName "KAPPALORES"
	.dexLang EN
	.dexCategory "CAREFREE"
	.dexLang FR
	.dexCategoryLeftAligned "INSOUCIANT"
	.dexLang DE
	.dexCategoryLeftAligned "SORGLOS"
	.dexLang IT
	.dexCategoryLeftAligned "SPENSIERATO"
	.dexLang ES
	.dexCategoryLeftAligned "OPTIMISTA"
	.dexLang EN
	.dexText "Upon hearing an upbeat and cheerful"
	.dexText "rhythm, the cells in LUDICOLO`s body"
	.dexText "become very energetic and active."
	.dexText "Even in battle, this POKéMON will"
	.dexText "exhibit an amazing amount of power."
	.dexText ""
	.dexLang FR
	.dexText "Lorsque LUDICOLO entend un rythme"
	.dexText "entraînant et joyeux, les cellules de"
	.dexText "son corps s`activent énergiquement."
	.dexText "Même pendant les combats, ce POKéMON"
	.dexText "montre énormément d`énergie."
	.dexText ""
	.dexLang DE
	.dexText "Wenn KAPPALORES einen fröhlichen"
	.dexText "Rhythmus hört, werden die Zellen in"
	.dexText "seinem Körper aktiviert. Auch im Kampf"
	.dexText "zeigt dieses POKéMON seine"
	.dexText "verblüffende Stärke."
	.dexText ""
	.dexLang IT
	.dexText "Quando sente un motivetto allegro e"
	.dexText "vivace, le cellule corporee di LUDICOLO"
	.dexText "diventano attive e piene di energia."
	.dexText "Anche in lotta il POKéMON dimostra"
	.dexText "una potenza incredibile."
	.dexText ""
	.dexLang ES
	.dexText "Las células de LUDICOLO se revolucionan"
	.dexText "y llenan de energía cuando oye sonidos"
	.dexText "rítmicos y alegres."
	.dexText "En combate hace gala también"
	.dexText "de esta cantidad desmesurada"
	.dexText "de energía."

	.align 2, 0
dexEntryEu22:: @ 022 SEEDOT
	.2byte 0, 2, 2
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 10, 8, 8, 10, 10, 10, 4, 0  @ weight
	.dexLang EN
	.dexName "SEEDOT"
	.dexLang FR
	.dexName "GRAINIPIOT"
	.dexLang DE
	.dexName "SAMURZEL"
	.dexLang EN
	.dexCategory "ACORN"
	.dexLang FR
	.dexCategoryLeftAligned "GLAND"
	.dexLang DE
	.dexCategoryLeftAligned "EICHELNUSS"
	.dexLang IT
	.dexCategoryLeftAligned "GHIANDA"
	.dexLang ES
	.dexCategoryLeftAligned "BELLOTA"
	.dexLang EN
	.dexText "SEEDOT attaches itself to a tree"
	.dexText "branch using the top of its head."
	.dexText "It sucks moisture from the tree while"
	.dexText "hanging off the branch."
	.dexText "The more water it drinks, the glossier"
	.dexText "this POKéMON`s body becomes."
	.dexLang FR
	.dexText "GRAINIPIOT s`accroche par la tête aux"
	.dexText "branches d`arbre. Il en profite alors"
	.dexText "pour absorber l`humidité de l`arbre."
	.dexText "Plus ce POKéMON boit d`eau,"
	.dexText "plus son corps devient brillant."
	.dexText ""
	.dexLang DE
	.dexText "SAMURZEL hängt sich mit dem Kopf an"
	.dexText "einen Ast. Dabei entzieht es dem Baum"
	.dexText "Feuchtigkeit. Je mehr Wasser es trinkt,"
	.dexText "desto glänzender wird der Körper dieses"
	.dexText "POKéMON."
	.dexText ""
	.dexLang IT
	.dexText "SEEDOT si attacca ai rami degli alberi"
	.dexText "usando il picciolo che ha sul capo."
	.dexText "In questa posizione succhia la linfa"
	.dexText "dell`albero per nutrirsi."
	.dexText "Più acqua assume, più lucido"
	.dexText "appare il suo corpo."
	.dexLang ES
	.dexText "SEEDOT se queda enganchado a las ramas"
	.dexText "de los árboles por el extremo que tiene"
	.dexText "en la cabeza. Mientras está ahí colgado,"
	.dexText "aprovecha para tomar la humedad"
	.dexText "del árbol. Cuanta más agua bebe,"
	.dexText "más lustroso se le ve."

	.align 2, 0
dexEntryEu23:: @ 023 NUZLEAF
	.2byte 0, 2, 3
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 10, 6, 1, 7, 10, 10, 2, 8, 0  @ weight
	.dexLang EN
	.dexName "NUZLEAF"
	.dexLang FR
	.dexName "PIFEUIL"
	.dexLang DE
	.dexName "BLANAS"
	.dexLang EN
	.dexCategory "WILY"
	.dexLang FR
	.dexCategoryLeftAligned "MALIN"
	.dexLang DE
	.dexCategoryLeftAligned "HINTERLIST"
	.dexLang IT
	.dexCategoryLeftAligned "SCALTRO"
	.dexLang ES
	.dexCategoryLeftAligned "ASTUTO"
	.dexLang EN
	.dexText "NUZLEAF live in densely overgrown"
	.dexText "forests. They occasionally venture out"
	.dexText "of the forest to startle people."
	.dexText "This POKéMON dislikes having its long"
	.dexText "nose pinched."
	.dexText ""
	.dexLang FR
	.dexText "Les PIFEUIL vivent dans des forêts"
	.dexText "très densément boisées. Il leur arrive"
	.dexText "de sortir de la forêt pour faire"
	.dexText "peur aux gens. Ce POKéMON déteste"
	.dexText "qu`on lui pince son grand nez."
	.dexText ""
	.dexLang DE
	.dexText "BLANAS lebt in dichten Wäldern."
	.dexText "Manchmal wagt es sich aus dem Wald"
	.dexText "heraus, um Menschen zu erschrecken."
	.dexText "Dieses POKéMON mag es überhaupt nicht,"
	.dexText "wenn man seine lange Nase zwickt."
	.dexText ""
	.dexLang IT
	.dexText "NUZLEAF vive in foreste molto fitte."
	.dexText "A volte si avventura fuori dalla foresta"
	.dexText "per spaventare le persone."
	.dexText "Questo POKéMON si irrita molto,"
	.dexText "se qualcuno tenta di pizzicargli"
	.dexText "il lungo naso."
	.dexLang ES
	.dexText "NUZLEAF habita bosques muy poblados."
	.dexText "Y, en ocasiones, se atreve a salir para"
	.dexText "asustar a la gente."
	.dexText "A este POKéMON no le gusta nada"
	.dexText "que le pellizquen la nariz."
	.dexText ""

	.align 2, 0
dexEntryEu24:: @ 024 SHIFTRY
	.2byte 0, 2, 4
	.2byte 10, 4, 0, 3, 10, 10, 1, 3  @ height
	.2byte 10, 1, 3, 1, 4, 10, 10, 5, 9, 6  @ weight
	.dexLang EN
	.dexName "SHIFTRY"
	.dexLang FR
	.dexName "TENGALICE"
	.dexLang DE
	.dexName "TENGULIST"
	.dexLang EN
	.dexCategory "WICKED"
	.dexLang FR
	.dexCategoryLeftAligned "MALVEILLANT"
	.dexLang DE
	.dexCategoryLeftAligned "VERSCHLAGEN"
	.dexLang IT
	.dexCategoryLeftAligned "BURBERO"
	.dexLang ES
	.dexCategoryLeftAligned "MALVADO"
	.dexLang EN
	.dexText "SHIFTRY is a mysterious POKéMON that"
	.dexText "is said to live atop towering trees"
	.dexText "dating back over a thousand years."
	.dexText "It creates terrific windstorms with"
	.dexText "the fans it holds."
	.dexText ""
	.dexLang FR
	.dexText "TENGALICE est un mystérieux POKéMON"
	.dexText "vivant dans les cimes d`immenses arbres,"
	.dexText "vieux de plus de mille ans."
	.dexText "Il peut créer de formidables tempêtes"
	.dexText "grâce à ses éventails."
	.dexText ""
	.dexLang DE
	.dexText "TENGULIST ist ein geheimnisvolles"
	.dexText "POKéMON, das angeblich auf hohen"
	.dexText "Bäumen lebt, die tausende von Jahren"
	.dexText "alt sind. Mit den Blätterventilatoren an"
	.dexText "seinen Händen kann es heftige Stürme"
	.dexText "erzeugen."
	.dexLang IT
	.dexText "SHIFTRY è un POKéMON misterioso"
	.dexText "che vive sulla cima degli alberi più alti,"
	.dexText "di solito plurisecolari."
	.dexText "Usa le foglie degli arti superiori"
	.dexText "come ventole per generare"
	.dexText "terribili raffiche di vento."
	.dexLang ES
	.dexText "SHIFTRY es un enigmático POKéMON"
	.dexText "que vive, dicen, en las copas"
	.dexText "de los árboles milenarios."
	.dexText "Este POKéMON genera fuertes"
	.dexText "corrientes de aire con los abanicos"
	.dexText "que lleva en las manos."

	.align 2, 0
dexEntryEu25:: @ 025 TAILLOW
	.2byte 0, 2, 5
	.2byte 10, 1, 0, 0, 10, 10, 0, 3  @ height
	.2byte 10, 10, 10, 5, 1, 10, 10, 10, 2, 3  @ weight
	.dexLang EN
	.dexName "TAILLOW"
	.dexLang FR
	.dexName "NIRONDELLE"
	.dexLang DE
	.dexName "SCHWALBINI"
	.dexLang EN
	.dexCategory "TINYSWALLOW"
	.dexLang FR
	.dexCategoryLeftAligned "MINIRONDEL"
	.dexLang DE
	.dexCategoryLeftAligned "SCHWÄLBLEIN"
	.dexLang IT
	.dexCategoryLeftAligned "RONDINELLA"
	.dexLang ES
	.dexCategoryLeftAligned "PEQUEBUCHE"
	.dexLang EN
	.dexText "TAILLOW courageously stands its"
	.dexText "ground against foes, however strong"
	.dexText "they may be."
	.dexText "This gutsy POKéMON will remain defiant"
	.dexText "even after a loss. On the other hand,"
	.dexText "it cries loudly if it becomes hungry."
	.dexLang FR
	.dexText "NIRONDELLE défend courageusement"
	.dexText "son territoire contre ses ennemis, même"
	.dexText "les plus puissants."
	.dexText "Ce vaillant POKéMON est toujours prêt à"
	.dexText "relever un défi, mais s`il a faim, il"
	.dexText "se met à pleurer à chaudes larmes."
	.dexLang DE
	.dexText "Mutig behauptet SCHWALBINI sein"
	.dexText "Territorium gegen Eindringlinge, so"
	.dexText "stark diese auch sein mögen."
	.dexText "Dieses unerschrockene POKéMON bleibt"
	.dexText "trotz einer Niederlage angriffslustig,"
	.dexText "heult aber laut, wenn es Hunger hat."
	.dexLang IT
	.dexText "TAILLOW affronta coraggiosamente"
	.dexText "persino i nemici più forti."
	.dexText ""
	.dexText "Anche in caso di sconfitta rimane fiero"
	.dexText "e spavaldo. D`altra parte, quando ha"
	.dexText "fame, si lamenta rumorosamente."
	.dexLang ES
	.dexText "TAILLOW se mantiene firme ante sus"
	.dexText "rivales, sean lo fuertes que sean."
	.dexText "Este valiente POKéMON seguirá"
	.dexText "mostrándose desafiante, aunque pierda"
	.dexText "en combate. Además, si se enfada,"
	.dexText "se pondrá a gritar con energía."

	.align 2, 0
dexEntryEu26:: @ 026 SWELLOW
	.2byte 0, 2, 6
	.2byte 10, 2, 0, 4, 10, 10, 0, 7  @ height
	.2byte 10, 10, 4, 3, 7, 10, 10, 1, 9, 8  @ weight
	.dexLang EN
	.dexName "SWELLOW"
	.dexLang FR
	.dexName "HELEDELLE"
	.dexLang DE
	.dexName "SCHWALBOSS"
	.dexLang EN
	.dexCategory "SWALLOW"
	.dexLang FR
	.dexCategoryLeftAligned "HIRONDELLE"
	.dexLang DE
	.dexCategoryLeftAligned "SCHWALBE"
	.dexLang IT
	.dexCategoryLeftAligned "RONDINE"
	.dexLang ES
	.dexCategoryLeftAligned "BUCHE"
	.dexLang EN
	.dexText "SWELLOW flies high above our heads,"
	.dexText "making graceful arcs in the sky."
	.dexText "This POKéMON dives at a steep angle as"
	.dexText "soon as it spots its prey. The hapless"
	.dexText "prey is tightly grasped by SWELLOW`s"
	.dexText "clawed feet, preventing escape."
	.dexLang FR
	.dexText "HELEDELLE vole dans les cieux en"
	.dexText "dessinant de grands arcs."
	.dexText "Ce POKéMON plonge en piqué dès"
	.dexText "qu`il repère sa proie. Il attrape"
	.dexText "fermement la malheureuse cible dans"
	.dexText "ses serres, empêchant toute fuite."
	.dexLang DE
	.dexText "Dieses POKéMON taucht in einem steilen"
	.dexText "Winkel ab, sobald es Beute wahrgenommen"
	.dexText "hat. Es packt seine Beute mit"
	.dexText "seinen Krallen und lässt sie"
	.dexText "nicht mehr entkommen."
	.dexText ""
	.dexLang IT
	.dexText "SWELLOW vola alto sopra le nostre teste"
	.dexText "disegnando armoniosi archi in cielo."
	.dexText "Appena scova una preda si lancia su"
	.dexText "di essa in picchiata. SWELLOW cattura"
	.dexText "poi la sventurata preda con le sue"
	.dexText "zampe artigliate impedendole la fuga."
	.dexLang ES
	.dexText "SWELLOW vuela muy alto dibujando"
	.dexText "elegantes arcos en el cielo."
	.dexText "Este POKéMON se sumerge en el agua con"
	.dexText "rapidez y eficacia en cuanto detecta"
	.dexText "una presa. Con las garras, atrapa a la"
	.dexText "desdichada víctima y no la deja huir."

	.align 2, 0
dexEntryEu27:: @ 027 WINGULL
	.2byte 0, 2, 7
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 2, 0, 9, 10, 10, 10, 9, 5  @ weight
	.dexLang EN
	.dexName "WINGULL"
	.dexLang FR
	.dexName "GOELISE"
	.dexLang DE
	.dexName "WINGULL"
	.dexLang EN
	.dexCategory "SEAGULL"
	.dexLang FR
	.dexCategoryLeftAligned "MOUETTE"
	.dexLang DE
	.dexCategoryLeftAligned "SEEMÖWE"
	.dexLang IT
	.dexCategoryLeftAligned "GABBIANO"
	.dexLang ES
	.dexCategoryLeftAligned "GAVIOTA"
	.dexLang EN
	.dexText "WINGULL has the habit of carrying prey"
	.dexText "and valuables in its beak and hiding"
	.dexText "them in all sorts of locations."
	.dexText "This POKéMON rides the winds and flies"
	.dexText "as if it were skating across the sky."
	.dexText ""
	.dexLang FR
	.dexText "GOELISE a l`habitude de transporter"
	.dexText "ses proies et ses objets de valeur dans"
	.dexText "son bec avant de les cacher."
	.dexText "Ce POKéMON se laisse porter par le"
	.dexText "vent et vole comme s`il surfait"
	.dexText "dans les cieux."
	.dexLang DE
	.dexText "Man sieht WINGULL oft mit seiner"
	.dexText "Beute oder seinen Besitztümern im"
	.dexText "Schnabel herumfliegen auf der Suche"
	.dexText "nach geeigneten Verstecken. Dieses"
	.dexText "POKéMON fliegt durch die Lüfte, als"
	.dexText "würde es gleiten."
	.dexLang IT
	.dexText "WINGULL ha l`abitudine di trasportare"
	.dexText "prede e oggetti preziosi nel becco"
	.dexText "per poi nasconderli dappertutto."
	.dexText "Questo POKéMON vola a cavallo dei venti"
	.dexText "planando in cielo."
	.dexText ""
	.dexLang ES
	.dexText "WINGULL tiene la costumbre de llevar a"
	.dexText "su presa y objetos de valor en el pico,"
	.dexText "y esconderlos en distintos sitios."
	.dexText "Este POKéMON vuela dejándose llevar"
	.dexText "por las corrientes de aire como si fuera"
	.dexText "patinando por el cielo."

	.align 2, 0
dexEntryEu28:: @ 028 PELIPPER
	.2byte 0, 2, 8
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 10, 6, 1, 7, 10, 10, 2, 8, 0  @ weight
	.dexLang EN
	.dexName "PELIPPER"
	.dexLang FR
	.dexName "BEKIPAN"
	.dexLang DE
	.dexName "PELIPPER"
	.dexLang EN
	.dexCategory "WATER BIRD"
	.dexLang FR
	.dexCategoryLeftAligned "OISEAUDO"
	.dexLang DE
	.dexCategoryLeftAligned "WASSERVOGEL"
	.dexLang IT
	.dexCategoryLeftAligned "ALACQUATICO"
	.dexLang ES
	.dexCategoryLeftAligned "AVE AGUA"
	.dexLang EN
	.dexText "PELIPPER is a flying transporter that"
	.dexText "carries small POKéMON and eggs inside"
	.dexText "its massive bill."
	.dexText "This POKéMON builds its nest on steep"
	.dexText "cliffs facing the sea."
	.dexText ""
	.dexLang FR
	.dexText "BEKIPAN est un transporteur volant"
	.dexText "chargeant des petits POKéMON et des"
	.dexText "œufs dans son énorme bec."
	.dexText "Ce POKéMON construit son nid sur"
	.dexText "les falaises, face à la mer."
	.dexText ""
	.dexLang DE
	.dexText "PELIPPER transportiert kleine POKéMON"
	.dexText "und Eier in seinem riesigen Schnabel"
	.dexText "durch die Lüfte. Dieses POKéMON baut"
	.dexText "sein Nest auf steilen Klippen am Meer."
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "PELIPPER fa le veci di un aereo cargo"
	.dexText "poiché trasporta piccoli POKéMON e"
	.dexText "uova all`interno del suo becco enorme."
	.dexText "Questo POKéMON crea il proprio nido"
	.dexText "sulle scogliere a picco sul mare."
	.dexText ""
	.dexLang ES
	.dexText "PELIPPER vuela transportando pequeños"
	.dexText "huevos y POKéMON dentro del descomunal"
	.dexText "pico que tiene."
	.dexText "Este POKéMON construye su nido en"
	.dexText "escarpados acantilados frente al mar."
	.dexText ""

	.align 2, 0
dexEntryEu29:: @ 029 RALTS
	.2byte 0, 2, 9
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 1, 4, 6, 10, 10, 10, 6, 6  @ weight
	.dexLang EN
	.dexName "RALTS"
	.dexLang FR
	.dexName "TARSAL"
	.dexLang DE
	.dexName "TRASLA"
	.dexLang EN
	.dexCategory "FEELING"
	.dexLang FR
	.dexCategoryLeftAligned "SENTIMENT"
	.dexLang DE
	.dexCategoryLeftAligned "GEFÜHL"
	.dexLang IT
	.dexCategoryLeftAligned "SENSAZIONE"
	.dexLang ES
	.dexCategoryLeftAligned "SENSIBLE"
	.dexLang EN
	.dexText "RALTS senses the emotions of"
	.dexText "people using the horns on its head."
	.dexText "This POKéMON rarely appears before"
	.dexText "people. But when it does, it draws"
	.dexText "closer if it senses that the person has"
	.dexText "a positive disposition."
	.dexLang FR
	.dexText "TARSAL ressent les émotions des"
	.dexText "gens grâce à ses cornes. Ce POKéMON se"
	.dexText "montre rarement, mais il arrive qu`il"
	.dexText "s`approche d`une personne s`il la sent"
	.dexText "dans un état d`esprit positif."
	.dexText ""
	.dexLang DE
	.dexText "TRASLA nimmt mit den Hörnern an seinem"
	.dexText "Kopf die Gefühle von Menschen wahr."
	.dexText "Menschen bekommen dieses POKéMON"
	.dexText "nur selten zu Gesicht. Wenn es bemerkt,"
	.dexText "dass eine Person gut gelaunt ist, traut"
	.dexText "es sich näher an sie heran."
	.dexLang IT
	.dexText "RALTS percepisce le emozioni delle"
	.dexText "persone usando le corna poste sul capo."
	.dexText "Raramente si fa vedere dagli esseri"
	.dexText "umani, ma se percepisce un`energia"
	.dexText "positiva provenire da qualcuno è"
	.dexText "possibile che si avvicini."
	.dexLang ES
	.dexText "RALTS percibe las sensaciones de"
	.dexText "la gente por los colmillos que tiene"
	.dexText "encima y detrás de la cabeza. No es"
	.dexText "común que este POKéMON aparezca en"
	.dexText "público, pero cuando lo hace, se acerca"
	.dexText "si ve buena disposición en la gente."

	.align 2, 0
dexEntryEu30:: @ 030 KIRLIA
	.2byte 0, 3, 0
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 4, 4, 5, 10, 10, 2, 0, 2  @ weight
	.dexLang EN
	.dexName "KIRLIA"
	.dexLang FR
	.dexName "KIRLIA"
	.dexLang DE
	.dexName "KIRLIA"
	.dexLang EN
	.dexCategory "EMOTION"
	.dexLang FR
	.dexCategoryLeftAligned "EMOTION"
	.dexLang DE
	.dexCategoryLeftAligned "EMOTION"
	.dexLang IT
	.dexCategoryLeftAligned "EMOZIONE"
	.dexLang ES
	.dexCategoryLeftAligned "SENSORIO"
	.dexLang EN
	.dexText "It is said that a KIRLIA that is"
	.dexText "exposed to the positive emotions of"
	.dexText "its TRAINER grows beautiful."
	.dexText "This POKéMON controls psychokinetic"
	.dexText "powers with its highly developed brain."
	.dexText ""
	.dexLang FR
	.dexText "On dit qu`un KIRLIA exposé aux"
	.dexText "émotions positives de son DRESSEUR"
	.dexText "devient très beau."
	.dexText "Le cerveau surdéveloppé de ce POKéMON"
	.dexText "lui permet de contrôler les forces"
	.dexText "télékinésiques."
	.dexLang DE
	.dexText "Man sagt, dass ein KIRLIA, das häufig"
	.dexText "positive Emotionen seines TRAINERs"
	.dexText "wahrnimmt, sehr schön wird."
	.dexText "Dieses POKéMON kontrolliert"
	.dexText "psychokinetische Energie mit seinem"
	.dexText "hochentwickelten Gehirn."
	.dexLang IT
	.dexText "Si dice che KIRLIA cresca molto bene"
	.dexText "se viene esposto alle emozioni positive"
	.dexText "del suo ALLENATORE."
	.dexText "Questo POKéMON è dotato di poteri"
	.dexText "psicocinetici grazie al suo cervello"
	.dexText "altamente sviluppato."
	.dexLang ES
	.dexText "Dicen que al recibir los sentimientos"
	.dexText "positivos de su ENTRENADOR, KIRLIA"
	.dexText "crece con gran belleza."
	.dexText "Este POKéMON controla poderes"
	.dexText "psicoquinéticos gracias al desarrollado"
	.dexText "cerebro que tiene."

	.align 2, 0
dexEntryEu31:: @ 031 GARDEVOIR
	.2byte 0, 3, 1
	.2byte 10, 5, 0, 3, 10, 10, 1, 6  @ height
	.2byte 10, 1, 0, 6, 7, 10, 10, 4, 8, 4  @ weight
	.dexLang EN
	.dexName "GARDEVOIR"
	.dexLang FR
	.dexName "GARDEVOIR"
	.dexLang DE
	.dexName "GUARDEVOIR"
	.dexLang EN
	.dexCategory "EMBRACE"
	.dexLang FR
	.dexCategoryLeftAligned "ETREINTE"
	.dexLang DE
	.dexCategoryLeftAligned "UMARMUNG"
	.dexLang IT
	.dexCategoryLeftAligned "ABBRACCIO"
	.dexLang ES
	.dexCategoryLeftAligned "ENVOLVENTE"
	.dexLang EN
	.dexText "GARDEVOIR has the ability to read the"
	.dexText "future. If it senses impending danger"
	.dexText "to its TRAINER, this POKéMON is said to"
	.dexText "unleash its psychokinetic energy at"
	.dexText "full power."
	.dexText ""
	.dexLang FR
	.dexText "GARDEVOIR a le pouvoir de prédire"
	.dexText "l`avenir. On raconte que lorsqu`il sent"
	.dexText "que son DRESSEUR est en danger,"
	.dexText "il libère une puissante décharge"
	.dexText "d`énergie télékinésique."
	.dexText ""
	.dexLang DE
	.dexText "GUARDEVOIR kann in die Zukunft"
	.dexText "schauen. Wenn es eine Gefahr für seinen"
	.dexText "TRAINER voraussieht, entlädt es seine"
	.dexText "psychokinetische Energie mit voller"
	.dexText "Kraft."
	.dexText ""
	.dexLang IT
	.dexText "GARDEVOIR ha l`abilità di prevedere"
	.dexText "il futuro. Se percepisce un pericolo"
	.dexText "imminente per il proprio ALLENATORE,"
	.dexText "pare che scateni tutta l`energia"
	.dexText "psicocinetica di cui è capace."
	.dexText ""
	.dexLang ES
	.dexText "GARDEVOIR es capaz de leer el futuro."
	.dexText "Si siente que su ENTRENADOR está"
	.dexText "en peligro inminente, dicen que libera"
	.dexText "automáticamente toda su energía"
	.dexText "psicoquinética."
	.dexText ""

	.align 2, 0
dexEntryEu32:: @ 032 SURSKIT
	.2byte 0, 3, 2
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 10, 3, 7, 10, 10, 10, 1, 7  @ weight
	.dexLang EN
	.dexName "SURSKIT"
	.dexLang FR
	.dexName "ARAKDO"
	.dexLang DE
	.dexName "GEHWEIHER"
	.dexLang EN
	.dexCategory "POND SKATER"
	.dexLang FR
	.dexCategoryLeftAligned "MARESURFEUR"
	.dexLang DE
	.dexCategoryLeftAligned "WASSERGEHER"
	.dexLang IT
	.dexCategoryLeftAligned "SFIORAPOZZE"
	.dexLang ES
	.dexCategoryLeftAligned "ZAPATERO"
	.dexLang EN
	.dexText "If SURSKIT senses danger, it secretes"
	.dexText "a thick, sugary syrup from the tip of"
	.dexText "its head."
	.dexText "There are some POKéMON that love"
	.dexText "eating this syrup."
	.dexText ""
	.dexLang FR
	.dexText "Lorsqu`ARAKDO se sent en danger,"
	.dexText "le haut de sa tête sécrète un sirop"
	.dexText "épais et sucré."
	.dexText "Certains POKéMON adorent boire de"
	.dexText "ce sirop."
	.dexText ""
	.dexLang DE
	.dexText "Wenn GEHWEIHER Gefahr wittert,"
	.dexText "scheidet es einen dickflüssigen Sirup"
	.dexText "aus seinem Kopf aus. Es gibt einige"
	.dexText "POKéMON, die ganz wild auf diesen"
	.dexText "Sirup sind."
	.dexText ""
	.dexLang IT
	.dexText "In caso di pericolo SURSKIT secerne"
	.dexText "un fluido denso e zuccheroso dall`aculeo"
	.dexText "posto sulla sommità del capo."
	.dexText "Esistono POKéMON che adorano"
	.dexText "cibarsi di questo fluido."
	.dexText ""
	.dexLang ES
	.dexText "Cuando SURSKIT siente que hay peligro,"
	.dexText "segrega un néctar espeso y dulce por la"
	.dexText "cabeza."
	.dexText "Hay POKéMON a los que les encanta"
	.dexText "bebérselo."
	.dexText ""

	.align 2, 0
dexEntryEu33:: @ 033 MASQUERAIN
	.2byte 0, 3, 3
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 10, 7, 9, 10, 10, 10, 3, 6  @ weight
	.dexLang EN
	.dexName "MASQUERAIN"
	.dexLang FR
	.dexName "MASKADRA"
	.dexLang DE
	.dexName "MASKEREGEN"
	.dexLang EN
	.dexCategory "EYEBALL"
	.dexLang FR
	.dexCategoryLeftAligned "BOULE OEIL"
	.dexLang DE
	.dexCategoryLeftAligned "AUGE"
	.dexLang IT
	.dexCategoryLeftAligned "OCCHI"
	.dexLang ES
	.dexCategoryLeftAligned "GLOBOCULAR"
	.dexLang EN
	.dexText "MASQUERAIN`s antennas have eyelike"
	.dexText "patterns that usually give it an angry"
	.dexText "look. If the “eyes” are droopy and"
	.dexText "appear sad, it is said to be a sign"
	.dexText "that a heavy rainfall is on its way."
	.dexText ""
	.dexLang FR
	.dexText "Les antennes de MASKADRA ont la"
	.dexText "forme de grands yeux qui lancent un"
	.dexText "regard noir. Si ces «yeux» sont tristes,"
	.dexText "cela signifie qu`un déluge se prépare."
	.dexText ""
	.dexText ""
	.dexLang DE
	.dexText "MASKEREGENs Antennen haben ein"
	.dexText "augenähnliches Muster, das ihm ein"
	.dexText "Furcht erregendes äußeres verleiht."
	.dexText "Wenn seine „Augen“ traurig"
	.dexText "aussehen, ist ein heftiger Regenguss"
	.dexText "im Anzug."
	.dexLang IT
	.dexText "Le antenne di MASQUERAIN presentano"
	.dexText "un motivo a forma d`occhio che gli"
	.dexText "conferisce un aspetto aggressivo."
	.dexText "Quando questa specie di occhi ha"
	.dexText "l`aspetto triste e depresso significa"
	.dexText "che si sta avvicinando un acquazzone."
	.dexLang ES
	.dexText "MASQUERAIN tiene unas antenas"
	.dexText "con ojos dibujados que le dan aspecto"
	.dexText "de estar enfadado. Si tiene los {3926}ojos”"
	.dexText "medio cerrados y con aspecto triste,"
	.dexText "es probable que esté a punto de caer"
	.dexText "un buen aguacero."

	.align 2, 0
dexEntryEu34:: @ 034 SHROOMISH
	.2byte 0, 3, 4
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 10, 9, 9, 10, 10, 10, 4, 5  @ weight
	.dexLang EN
	.dexName "SHROOMISH"
	.dexLang FR
	.dexName "BALIGNON"
	.dexLang DE
	.dexName "KNILZ"
	.dexLang EN
	.dexCategory "MUSHROOM"
	.dexLang FR
	.dexCategoryLeftAligned "CHAMPIGNON"
	.dexLang DE
	.dexCategoryLeftAligned "PILZ"
	.dexLang IT
	.dexCategoryLeftAligned "FUNGO"
	.dexLang ES
	.dexCategoryLeftAligned "HONGO"
	.dexLang EN
	.dexText "SHROOMISH live in damp soil in the dark"
	.dexText "depths of forests. They are often"
	.dexText "found keeping still under fallen leaves."
	.dexText "This POKéMON feeds on compost that"
	.dexText "is made up of fallen, rotted leaves."
	.dexText ""
	.dexLang FR
	.dexText "Les BALIGNON vivent dans les sols"
	.dexText "humides et les recoins sombres des"
	.dexText "grandes forêts. On les trouve souvent"
	.dexText "immobiles sous les feuilles mortes. Ce"
	.dexText "POKéMON se nourrit d`un compost fait"
	.dexText "de feuilles mortes pourries."
	.dexLang DE
	.dexText "KNILZ lebt im feuchten Erdboden"
	.dexText "finsterer Wälder. Es wird oft reglos"
	.dexText "unter herabgefallenen Blättern"
	.dexText "gefunden. Dieses POKéMON ernährt sich"
	.dexText "von Kompost aus verrotteten Blättern."
	.dexText ""
	.dexLang IT
	.dexText "SHROOMISH vive nel suolo umido"
	.dexText "nel cuore della foresta buia. Spesso"
	.dexText "si nasconde sotto le foglie cadute."
	.dexText "Si ciba dell`humus creato dal letto"
	.dexText "di foglie decomposte sul terreno."
	.dexText ""
	.dexLang ES
	.dexText "Los SHROOMISH viven en zonas"
	.dexText "húmedas en la profunda oscuridad del"
	.dexText "bosque. Suelen quedarse tranquilamente"
	.dexText "bajo las hojas caídas. Se alimentan"
	.dexText "del abono que éstas generan al empezar"
	.dexText "a pudrirse."

	.align 2, 0
dexEntryEu35:: @ 035 BRELOOM
	.2byte 0, 3, 5
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 10, 8, 6, 4, 10, 10, 3, 9, 2  @ weight
	.dexLang EN
	.dexName "BRELOOM"
	.dexLang FR
	.dexName "CHAPIGNON"
	.dexLang DE
	.dexName "KAPILZ"
	.dexLang EN
	.dexCategory "MUSHROOM"
	.dexLang FR
	.dexCategoryLeftAligned "CHAMPIGNON"
	.dexLang DE
	.dexCategoryLeftAligned "PILZ"
	.dexLang IT
	.dexCategoryLeftAligned "FUNGO"
	.dexLang ES
	.dexCategoryLeftAligned "HONGO"
	.dexLang EN
	.dexText "BRELOOM closes in on its foe with light"
	.dexText "and sprightly footwork, then throws"
	.dexText "punches with its stretchy arms."
	.dexText "This POKéMON`s fighting technique puts"
	.dexText "boxers to shame."
	.dexText ""
	.dexLang FR
	.dexText "CHAPIGNON se rapproche de son ennemi"
	.dexText "en se servant de son jeu de jambes, puis"
	.dexText "donne des coups de poing avec ses"
	.dexText "grands bras. La technique de combat de"
	.dexText "ce POKéMON est digne des meilleurs"
	.dexText "boxeurs."
	.dexLang DE
	.dexText "Mit leichtfüßiger Beinarbeit nähert"
	.dexText "sich KAPILZ seinen Feinden und"
	.dexText "schlägt dann mit seinen dehnbaren"
	.dexText "Armen um sich. Die Kampftechnik dieses"
	.dexText "POKéMON treibt Profiboxern die"
	.dexText "Schamesröte ins Gesicht."
	.dexLang IT
	.dexText "BRELOOM si avvicina al nemico con"
	.dexText "passettini leggeri e veloci, poi sferra"
	.dexText "scariche di pugni con gli elastici arti"
	.dexText "superiori. Le sue tecniche di lotta"
	.dexText "superano quelle dei pugili più esperti."
	.dexText ""
	.dexLang ES
	.dexText "BRELOOM se acerca al enemigo realizando"
	.dexText "un juego de piernas ágil y enérgico. Y, a"
	.dexText "continuación, le da unos puñetazos con"
	.dexText "los brazos elásticos que tiene. Las"
	.dexText "técnicas de lucha que usa dejan"
	.dexText "en ridículo al boxeador más profesional."

	.align 2, 0
dexEntryEu36:: @ 036 SLAKOTH
	.2byte 0, 3, 6
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 5, 2, 9, 10, 10, 2, 4, 0  @ weight
	.dexLang EN
	.dexName "SLAKOTH"
	.dexLang FR
	.dexName "PARECOOL"
	.dexLang DE
	.dexName "BUMMELZ"
	.dexLang EN
	.dexCategory "SLACKER"
	.dexLang FR
	.dexCategoryLeftAligned "FLANEUR"
	.dexLang DE
	.dexCategoryLeftAligned "FAULPELZ"
	.dexLang IT
	.dexCategoryLeftAligned "OZIOSO"
	.dexLang ES
	.dexCategoryLeftAligned "GANDUL"
	.dexLang EN
	.dexText "SLAKOTH`s heart beats just once a"
	.dexText "minute. Whatever happens, it is"
	.dexText "content to loaf around motionless."
	.dexText "It is rare to see this POKéMON in"
	.dexText "motion."
	.dexText ""
	.dexLang FR
	.dexText "Le cœur de PARECOOL ne bat qu`une"
	.dexText "fois par minute. Quoi qu`il arrive, il se"
	.dexText "contente de s`avachir, immobile."
	.dexText "Il est très rare de voir ce POKéMON"
	.dexText "se déplacer."
	.dexText ""
	.dexLang DE
	.dexText "BUMMELZ` Herz schlägt nur ein Mal pro"
	.dexText "Minute. Dieses POKéMON ist damit"
	.dexText "zufrieden, bewegungslos"
	.dexText "herumzulungern. Nur ganz selten sieht"
	.dexText "man dieses POKéMON sich bewegen."
	.dexText ""
	.dexLang IT
	.dexText "Il cuore di SLAKOTH batte con una"
	.dexText "frequenza di appena un battito al"
	.dexText "minuto. Qualsiasi cosa accada,"
	.dexText "non si muove mai. Infatti adora"
	.dexText "poltrire, riducendo al minimo"
	.dexText "i suoi movimenti."
	.dexLang ES
	.dexText "A SLAKOTH le late el corazón una vez"
	.dexText "por minuto. Ya puede pasar lo que pase,"
	.dexText "que este POKéMON no mueve un dedo."
	.dexText "Está todo el día holgazaneando."
	.dexText "Es muy raro verlo en movimiento."
	.dexText ""

	.align 2, 0
dexEntryEu37:: @ 037 VIGOROTH
	.2byte 0, 3, 7
	.2byte 10, 4, 0, 7, 10, 10, 1, 4  @ height
	.2byte 10, 1, 0, 2, 5, 10, 10, 4, 6, 5  @ weight
	.dexLang EN
	.dexName "VIGOROTH"
	.dexLang FR
	.dexName "VIGOROTH"
	.dexLang DE
	.dexName "MUNTIER"
	.dexLang EN
	.dexCategory "WILD MONKEY"
	.dexLang FR
	.dexCategoryLeftAligned "TURBUSINGE"
	.dexLang DE
	.dexCategoryLeftAligned "WILDAFFE"
	.dexLang IT
	.dexCategoryLeftAligned "INDOCILE"
	.dexLang ES
	.dexCategoryLeftAligned "MONO FEROZ"
	.dexLang EN
	.dexText "VIGOROTH is simply incapable of"
	.dexText "remaining still. Even when it tries to"
	.dexText "sleep, the blood in its veins grows"
	.dexText "agitated, compelling this POKéMON to"
	.dexText "run wild throughout the jungle before"
	.dexText "it can settle down."
	.dexLang FR
	.dexText "VIGOROTH ne tient pas en place."
	.dexText "Même quand il essaye de dormir, le"
	.dexText "sang dans ses veines s`agite,"
	.dexText "obligeant ce POKéMON à courir comme"
	.dexText "un fou dans la forêt pour s`épuiser afin"
	.dexText "de pouvoir se reposer."
	.dexLang DE
	.dexText "MUNTIER findet einfach keine Ruhe."
	.dexText "Wenn es versucht zu schlafen, beginnt"
	.dexText "das Blut in seinen Adern zu pulsieren."
	.dexText "Dann muss es wie wild durch den"
	.dexText "Dschungel rennen, um überhaupt Ruhe zu"
	.dexText "finden."
	.dexLang IT
	.dexText "VIGOROTH è incapace di stare fermo"
	.dexText "e tranquillo. Anche quando cerca di"
	.dexText "dormire, il sangue gli ribolle nelle vene,"
	.dexText "costringendolo a correre"
	.dexText "selvaggiamente in lungo e in largo nella"
	.dexText "foresta prima di riuscire a calmarsi."
	.dexLang ES
	.dexText "A VIGOROTH le resulta totalmente"
	.dexText "imposible estarse quieto. Cuando"
	.dexText "intenta dormir, la sangre le fluye"
	.dexText "a velocidad de vértigo y se pone"
	.dexText "a correr por el bosque de un lado"
	.dexText "a otro hasta que se calma."

	.align 2, 0
dexEntryEu38:: @ 038 SLAKING
	.2byte 0, 3, 8
	.2byte 10, 6, 0, 7, 10, 10, 2, 0  @ height
	.2byte 10, 2, 8, 7, 7, 10, 1, 3, 0, 5  @ weight
	.dexLang EN
	.dexName "SLAKING"
	.dexLang FR
	.dexName "MONAFLEMIT"
	.dexLang DE
	.dexName "LETARKING"
	.dexLang EN
	.dexCategory "LAZY"
	.dexLang FR
	.dexCategoryLeftAligned "FAINEANT"
	.dexLang DE
	.dexCategoryLeftAligned "MÜSSIG"
	.dexLang IT
	.dexCategoryLeftAligned "PIGRIZIA"
	.dexLang ES
	.dexCategoryLeftAligned "HOLGAZÁN"
	.dexLang EN
	.dexText "Wherever SLAKING live, rings of over"
	.dexText "a yard in diameter appear in grassy"
	.dexText "fields. They are made by the POKéMON"
	.dexText "as it eats all the grass within reach"
	.dexText "while lying prone on the ground."
	.dexText ""
	.dexLang FR
	.dexText "On trouve parfois des cercles de plus"
	.dexText "d`un mètre de rayon totalement"
	.dexText "désherbés dans les plaines. Ils sont"
	.dexText "faits par les MONAFLEMIT qui"
	.dexText "passent leurs journées allongés à"
	.dexText "manger toute l`herbe à portée de main."
	.dexLang DE
	.dexText "Wo dieses LETARKING lebt, hinterlässt"
	.dexText "es Kreise von 1 m Radius auf den"
	.dexText "Wiesen. Es frisst nämlich all das Gras,"
	.dexText "das in seiner Reichweite wächst. Dabei"
	.dexText "liegt es bäuchlings auf dem Boden."
	.dexText ""
	.dexLang IT
	.dexText "Dove vive SLAKING, si formano anelli"
	.dexText "del raggio di un metro nei prati"
	.dexText "erbosi. Infatti, quando questo POKéMON"
	.dexText "si stende prono al suolo, mangia"
	.dexText "tutta l`erba che riesce a raggiungere."
	.dexText ""
	.dexLang ES
	.dexText "Cuando SLAKING se instala a vivir"
	.dexText "en una zona, aparecen círculos"
	.dexText "de un metro de radio de terreno"
	.dexText "baldío, pues se come todo el césped"
	.dexText "que pilla mientras está tumbado boca"
	.dexText "abajo."

	.align 2, 0
dexEntryEu39:: @ 039 ABRA
	.2byte 0, 3, 9
	.2byte 10, 2, 1, 1, 10, 10, 0, 9  @ height
	.2byte 10, 10, 4, 3, 0, 10, 10, 1, 9, 5  @ weight
	.dexLang EN
	.dexName "ABRA"
	.dexLang FR
	.dexName "ABRA"
	.dexLang DE
	.dexName "ABRA"
	.dexLang EN
	.dexCategory "PSI"
	.dexLang FR
	.dexCategoryLeftAligned "PSY"
	.dexLang DE
	.dexCategoryLeftAligned "PSI"
	.dexLang IT
	.dexCategoryLeftAligned "PSICO"
	.dexLang ES
	.dexCategoryLeftAligned "PSI"
	.dexLang EN
	.dexText "ABRA needs to sleep for eighteen hours"
	.dexText "a day. If it doesn`t, this POKéMON loses"
	.dexText "its ability to use telekinetic powers."
	.dexText "If it is attacked, ABRA escapes using"
	.dexText "TELEPORT while it is still sleeping."
	.dexText ""
	.dexLang FR
	.dexText "ABRA doit dormir dix-huit heures par"
	.dexText "jour. S`il dort moins, ce POKéMON ne peut"
	.dexText "plus utiliser ses pouvoirs"
	.dexText "télékinésiques. Lorsqu`il est attaqué,"
	.dexText "ABRA s`enfuit en utilisant TELEPORT,"
	.dexText "sans même se réveiller."
	.dexLang DE
	.dexText "ABRA braucht achtzehn Stunden Schlaf"
	.dexText "pro Tag, sonst verliert es die Fähigkeit,"
	.dexText "seine telekinetischen Kräfte zu"
	.dexText "nutzen. ABRA flüchtet mit Hilfe des"
	.dexText "TELEPORT, schläft dabei aber weiter."
	.dexText ""
	.dexLang IT
	.dexText "ABRA ha bisogno di 18 ore di sonno"
	.dexText "al giorno. In caso contrario perde"
	.dexText "le sue abilità telecinetiche."
	.dexText "Se attaccato, ABRA fugge usando"
	.dexText "TELETRASPORTO mentre dorme."
	.dexText ""
	.dexLang ES
	.dexText "ABRA necesita dormir 18 horas al día."
	.dexText "Si no, pierde la habilidad que tiene de"
	.dexText "usar poderes de telequinesia."
	.dexText "Si le atacan, ABRA puede escapar usando"
	.dexText "TELETRANSPORTE mientras duerme."
	.dexText ""

	.align 2, 0
dexEntryEu40:: @ 040 KADABRA
	.2byte 0, 4, 0
	.2byte 10, 4, 0, 3, 10, 10, 1, 3  @ height
	.2byte 10, 1, 2, 4, 6, 10, 10, 5, 6, 5  @ weight
	.dexLang EN
	.dexName "KADABRA"
	.dexLang FR
	.dexName "KADABRA"
	.dexLang DE
	.dexName "KADABRA"
	.dexLang EN
	.dexCategory "PSI"
	.dexLang FR
	.dexCategoryLeftAligned "PSY"
	.dexLang DE
	.dexCategoryLeftAligned "PSI"
	.dexLang IT
	.dexCategoryLeftAligned "PSICO"
	.dexLang ES
	.dexCategoryLeftAligned "PSI"
	.dexLang EN
	.dexText "KADABRA holds a silver spoon in its"
	.dexText "hand. The spoon is used to amplify the"
	.dexText "alpha waves in its brain."
	.dexText "Without the spoon, the POKéMON is said"
	.dexText "to be limited to half the usual amount"
	.dexText "of its telekinetic powers."
	.dexLang FR
	.dexText "KADABRA tient une cuillère en argent"
	.dexText "dans la main. Elle est utilisée pour"
	.dexText "amplifier les ondes alpha de son"
	.dexText "cerveau. Sans elle, on raconte que ce"
	.dexText "POKéMON ne peut utiliser que la moitié"
	.dexText "de ses pouvoirs télékinésiques."
	.dexLang DE
	.dexText "KADABRA hält einen silbernen Löffel in"
	.dexText "der Hand. Es verstärkt damit die"
	.dexText "Alphawellen in seinem Gehirn. Ohne den"
	.dexText "Löffel könnte dieses POKéMON nur die"
	.dexText "Hälfte seiner telekinetischen Kräfte"
	.dexText "nutzen."
	.dexLang IT
	.dexText "KADABRA tiene in mano un cucchiaio"
	.dexText "d`argento per amplificare le onde alfa"
	.dexText "nel suo cervello."
	.dexText "Si dice che senza cucchiaio"
	.dexText "i suoi abituali poteri telecinetici"
	.dexText "siano dimezzati."
	.dexLang ES
	.dexText "KADABRA lleva siempre una cuchara de"
	.dexText "plata en la mano, que usa para amplificar"
	.dexText "las ondas alfa de su cerebro."
	.dexText "Dicen que sin la cuchara, sus poderes de"
	.dexText "telequinesia se reducen a la mitad."
	.dexText ""

	.align 2, 0
dexEntryEu41:: @ 041 ALAKAZAM
	.2byte 0, 4, 1
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 1, 0, 5, 8, 10, 10, 4, 8, 0  @ weight
	.dexLang EN
	.dexName "ALAKAZAM"
	.dexLang FR
	.dexName "ALAKAZAM"
	.dexLang DE
	.dexName "SIMSALA"
	.dexLang EN
	.dexCategory "PSI"
	.dexLang FR
	.dexCategoryLeftAligned "PSY"
	.dexLang DE
	.dexCategoryLeftAligned "PSI"
	.dexLang IT
	.dexCategoryLeftAligned "PSICO"
	.dexLang ES
	.dexCategoryLeftAligned "PSI"
	.dexLang EN
	.dexText "ALAKAZAM`s brain continually grows,"
	.dexText "infinitely multiplying brain cells."
	.dexText "This amazing brain gives this POKéMON"
	.dexText "an astoundingly high IQ of 5,000."
	.dexText "It has a thorough memory of everything"
	.dexText "that has occurred in the world."
	.dexLang FR
	.dexText "Le cerveau d`ALAKAZAM grossit sans"
	.dexText "arrêt, multipliant sans cesse ses"
	.dexText "cellules. Ce POKéMON a un QI"
	.dexText "incroyablement élevé, de 5 000."
	.dexText "Il peut garder en mémoire tout ce qui"
	.dexText "s`est passé dans le monde."
	.dexLang DE
	.dexText "SIMSALAs Hirn wächst stetig weiter und"
	.dexText "seine Gehirnzellen werden unendlich"
	.dexText "vervielfacht. Durch sein verblüffendes"
	.dexText "Gehirn erreicht dieses POKéMON einen IQ"
	.dexText "von 5.000. Es erinnert sich an alles, was"
	.dexText "in der Welt passiert ist."
	.dexLang IT
	.dexText "Il cervello di ALAKAZAM cresce in"
	.dexText "continuazione, moltiplicando all`infinito"
	.dexText "le cellule cerebrali. Questo gli assegna"
	.dexText "un sorprendente QI di 5.000."
	.dexText "Ricorda nei minimi dettagli ogni"
	.dexText "evento accaduto nel mondo."
	.dexLang ES
	.dexText "El cerebro de ALAKAZAM siempre está"
	.dexText "creciendo y el número de neuronas no"
	.dexText "deja de aumentar. Este POKéMON tiene"
	.dexText "un coeficiente intelectual de 5.000."
	.dexText "Tiene archivado en su memoria todo"
	.dexText "lo que ha ocurrido en el mundo."

	.align 2, 0
dexEntryEu42:: @ 042 NINCADA
	.2byte 0, 4, 2
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 1, 2, 1, 10, 10, 10, 5, 5  @ weight
	.dexLang EN
	.dexName "NINCADA"
	.dexLang FR
	.dexName "NINGALE"
	.dexLang DE
	.dexName "NINCADA"
	.dexLang EN
	.dexCategory "TRAINEE"
	.dexLang FR
	.dexCategoryLeftAligned "APPRENTI"
	.dexLang DE
	.dexCategoryLeftAligned "VORBEREITER"
	.dexLang IT
	.dexCategoryLeftAligned "NOVIZIO"
	.dexLang ES
	.dexCategoryLeftAligned "APRENDIZ"
	.dexLang EN
	.dexText "NINCADA lives underground for many"
	.dexText "years in complete darkness."
	.dexText "This POKéMON absorbs nutrients from"
	.dexText "the roots of trees. It stays motionless"
	.dexText "as it waits for evolution."
	.dexText ""
	.dexLang FR
	.dexText "NINGALE vit depuis des années sous"
	.dexText "terre, dans l`obscurité la plus totale."
	.dexText "Ce POKéMON absorbe les nutriments"
	.dexText "des racines des arbres. Il reste"
	.dexText "immobile, attendant patiemment"
	.dexText "son évolution."
	.dexLang DE
	.dexText "NINCADA lebt viele Jahre in absoluter"
	.dexText "Dunkelheit unter der Erde. Dieses"
	.dexText "POKéMON nimmt Nährstoffe aus"
	.dexText "Baumwurzeln auf. Es rührt sich nicht,"
	.dexText "da es auf seine Entwicklung wartet."
	.dexText ""
	.dexLang IT
	.dexText "NINCADA vive sottoterra per molti anni"
	.dexText "nell`oscurità più assoluta. Questo"
	.dexText "POKéMON assume le sostanze nutritive"
	.dexText "dalle radici degli alberi. Rimane immobile"
	.dexText "in attesa dell`evoluzione."
	.dexText ""
	.dexLang ES
	.dexText "NINCADA vive bajo tierra en la"
	.dexText "más absoluta oscuridad durante años."
	.dexText "Este POKéMON absorbe nutrientes de"
	.dexText "las raíces de los árboles y permanece"
	.dexText "inmóvil a la espera de la evolución."
	.dexText ""

	.align 2, 0
dexEntryEu43:: @ 043 NINJASK
	.2byte 0, 4, 3
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 2, 6, 5, 10, 10, 1, 2, 0  @ weight
	.dexLang EN
	.dexName "NINJASK"
	.dexLang FR
	.dexName "NINJASK"
	.dexLang DE
	.dexName "NINJASK"
	.dexLang EN
	.dexCategory "NINJA"
	.dexLang FR
	.dexCategoryLeftAligned "NINJA"
	.dexLang DE
	.dexCategoryLeftAligned "NINJA"
	.dexLang IT
	.dexCategoryLeftAligned "NINJA"
	.dexLang ES
	.dexCategoryLeftAligned "NINJA"
	.dexLang EN
	.dexText "NINJASK moves around at such a high"
	.dexText "speed that it cannot be seen, even"
	.dexText "while its crying can be clearly heard."
	.dexText "For that reason, this POKéMON was long"
	.dexText "believed to be invisible."
	.dexText ""
	.dexLang FR
	.dexText "NINJASK se déplace tellement vite"
	.dexText "qu`il est impossible de le voir. En"
	.dexText "revanche, on entend clairement son cri."
	.dexText "On a pendant très longtemps cru que"
	.dexText "ce POKéMON était invisible."
	.dexText ""
	.dexLang DE
	.dexText "NINJASK bewegt sich so schnell, dass"
	.dexText "man es nicht sehen kann. Seine Schreie"
	.dexText "sind aber laut und deutlich zu hören."
	.dexText "Deshalb hielt man dieses POKéMON lange"
	.dexText "für unsichtbar."
	.dexText ""
	.dexLang IT
	.dexText "NINJASK si muove ad una velocità tale"
	.dexText "da rendersi praticamente invisibile,"
	.dexText "nonostante il suo verso si possa udire"
	.dexText "chiaramente. Per questo motivo, per"
	.dexText "molto tempo si è pensato che fosse"
	.dexText "effettivamente invisibile."
	.dexLang ES
	.dexText "NINJASK se mueve de un lado a otro a tal"
	.dexText "velocidad que es imposible verlo. Sin"
	.dexText "embargo, como su zumbido no deja de"
	.dexText "oírse, se pensó durante mucho tiempo"
	.dexText "que este POKéMON era invisible."
	.dexText ""

	.align 2, 0
dexEntryEu44:: @ 044 SHEDINJA
	.2byte 0, 4, 4
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 10, 2, 6, 10, 10, 10, 1, 2  @ weight
	.dexLang EN
	.dexName "SHEDINJA"
	.dexLang FR
	.dexName "MUNJA"
	.dexLang DE
	.dexName "NINJATOM"
	.dexLang EN
	.dexCategory "SHED"
	.dexLang FR
	.dexCategoryLeftAligned "EXUVIE"
	.dexLang DE
	.dexCategoryLeftAligned "HÄUTUNG"
	.dexLang IT
	.dexCategoryLeftAligned "CAMBIAPELLE"
	.dexLang ES
	.dexCategoryLeftAligned "MUDA"
	.dexLang EN
	.dexText "SHEDINJA`s hard body doesn`t move -"
	.dexText "not even a twitch. In fact, its body"
	.dexText "appears to be merely a hollow shell."
	.dexText "It is believed that this POKéMON will"
	.dexText "steal the spirit of anyone peering into"
	.dexText "its hollow body from its back."
	.dexLang FR
	.dexText "Le corps robuste de MUNJA ne"
	.dexText "bouge pas d`un pouce. En fait, son corps"
	.dexText "semble être une coquille vide."
	.dexText "Certains croient que ce POKéMON peut"
	.dexText "voler l`âme de quiconque regarderait à"
	.dexText "l`intérieur de son corps creux."
	.dexLang DE
	.dexText "NINJATOMs harter Körper bewegt sich"
	.dexText "überhaupt nicht. Er scheint bloß eine"
	.dexText "hohle Schale zu sein. Dieses POKéMON"
	.dexText "soll angeblich die Seele eines jeden"
	.dexText "stehlen, der hinterrücks einen Blick in"
	.dexText "seinen hohlen Körper riskiert."
	.dexLang IT
	.dexText "Il corpo coriaceo di SHEDINJA non"
	.dexText "si muove neanche di un millimetro."
	.dexText "In realtà sembra quasi un guscio"
	.dexText "vuoto. Si dice che questo POKéMON"
	.dexText "rubi lo spirito di chiunque osi"
	.dexText "spiare dentro il suo guscio."
	.dexLang ES
	.dexText "SHEDINJA  tiene un cuerpo robusto que"
	.dexText "no mueve en absoluto. De hecho, parece"
	.dexText "una especie de caparazón hueco."
	.dexText "Se cree que si alguien se atreviera a"
	.dexText "mirarle por la espalda lo que tiene en su"
	.dexText "interior, SHEDINJA le robaría el alma."

	.align 2, 0
dexEntryEu45:: @ 045 WHISMUR
	.2byte 0, 4, 5
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 3, 5, 9, 10, 10, 1, 6, 3  @ weight
	.dexLang EN
	.dexName "WHISMUR"
	.dexLang FR
	.dexName "CHUCHMUR"
	.dexLang DE
	.dexName "FLURMEL"
	.dexLang EN
	.dexCategory "WHISPER"
	.dexLang FR
	.dexCategoryLeftAligned "CHUCHOTEUR"
	.dexLang DE
	.dexCategoryLeftAligned "FLÜSTER"
	.dexLang IT
	.dexCategoryLeftAligned "SUSSURRO"
	.dexLang ES
	.dexCategoryLeftAligned "SUSURRO"
	.dexLang EN
	.dexText "WHISMUR is very timid. If it starts to"
	.dexText "cry loudly, it becomes startled by its"
	.dexText "own crying and cries even harder."
	.dexText "When it finally stops crying, the"
	.dexText "POKéMON goes to sleep, all tired out."
	.dexText ""
	.dexLang FR
	.dexText "CHUCHMUR est très timide. S`il"
	.dexText "commence à pleurer, il s`effraie"
	.dexText "tout seul et pleure de plus belle."
	.dexText "Quand ce POKéMON finit enfin de pleurer,"
	.dexText "il s`endort, épuisé."
	.dexText ""
	.dexLang DE
	.dexText "FLURMEL ist sehr scheu. Wenn es laut"
	.dexText "brüllt, erschrickt es und brüllt dadurch"
	.dexText "noch lauter. Wenn es schließlich damit"
	.dexText "aufhört, ist es völlig ausgepumpt und"
	.dexText "legt sich schlafen."
	.dexText ""
	.dexLang IT
	.dexText "WHISMUR è estremamente timido."
	.dexText "Se gli capita di emettere suoni forti, è"
	.dexText "atterrito nell`udire la sua stessa voce,"
	.dexText "quindi urla ancora più fragorosamente."
	.dexText "Quando finalmente si placa,"
	.dexText "va a dormire, spossato."
	.dexLang ES
	.dexText "WHISMUR es muy tímido. Si empieza"
	.dexText "a gritar fuerte, se asusta a sí mismo"
	.dexText "y chilla más alto todavía."
	.dexText "Cuando para por fin, se va a dormir"
	.dexText "completamente agotado."
	.dexText ""

	.align 2, 0
dexEntryEu46:: @ 046 LOUDRED
	.2byte 0, 4, 6
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 10, 8, 9, 3, 10, 10, 4, 0, 5  @ weight
	.dexLang EN
	.dexName "LOUDRED"
	.dexLang FR
	.dexName "RAMBOUM"
	.dexLang DE
	.dexName "KRAKEELO"
	.dexLang EN
	.dexCategory "BIG VOICE"
	.dexLang FR
	.dexCategoryLeftAligned "GROSSE VOIX"
	.dexLang DE
	.dexCategoryLeftAligned "LAUTHALS"
	.dexLang IT
	.dexCategoryLeftAligned "VOCIONE"
	.dexLang ES
	.dexCategoryLeftAligned "CHILLÓN"
	.dexLang EN
	.dexText "LOUDRED shouts while stamping its feet."
	.dexText "After it finishes shouting, this"
	.dexText "POKéMON becomes incapable of hearing"
	.dexText "anything for a while. This is considered"
	.dexText "to be a weak point."
	.dexText ""
	.dexLang FR
	.dexText "RAMBOUM hurle en trépignant."
	.dexText "Quand il a fini de hurler, ce POKéMON"
	.dexText "reste incapable d`entendre le moindre"
	.dexText "son pendant un long moment. Il semble"
	.dexText "que ce soit son point faible."
	.dexText ""
	.dexLang DE
	.dexText "KRAKEELO schreit und stampft mit"
	.dexText "seinen Füßen auf den Boden. Danach"
	.dexText "kann es für eine Weile nichts hören."
	.dexText "Dies scheint die Schwachstelle dieses"
	.dexText "POKéMON zu sein."
	.dexText ""
	.dexLang IT
	.dexText "LOUDRED urla pestando i piedi."
	.dexText "Alla fine dei suoi strepiti è tempora-"
	.dexText "neamente incapace di udire qualsiasi"
	.dexText "rumore. Questo è considerato"
	.dexText "il suo tallone d`Achille."
	.dexText ""
	.dexLang ES
	.dexText "LOUDRED grita a la vez que da pisotones."
	.dexText "Una vez que deja de chillar, se queda"
	.dexText "ensordecido durante un buen rato;"
	.dexText "lo que se considera su punto débil."
	.dexText ""
	.dexText ""

	.align 2, 0
dexEntryEu47:: @ 047 EXPLOUD
	.2byte 0, 4, 7
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 1, 8, 5, 2, 10, 10, 8, 4, 0  @ weight
	.dexLang EN
	.dexName "EXPLOUD"
	.dexLang FR
	.dexName "BROUHABAM"
	.dexLang DE
	.dexName "KRAWUMMS"
	.dexLang EN
	.dexCategory "LOUD NOISE"
	.dexLang FR
	.dexCategoryLeftAligned "BRUIT SOURD"
	.dexLang DE
	.dexCategoryLeftAligned "KRACH"
	.dexLang IT
	.dexCategoryLeftAligned "FRAGORE"
	.dexLang ES
	.dexCategoryLeftAligned "ESCANDALOSO"
	.dexLang EN
	.dexText "EXPLOUD communicates its feelings to"
	.dexText "the others by emitting whistle-like"
	.dexText "sounds from the tubes on its body."
	.dexText "This POKéMON only raises its voice when"
	.dexText "it is in battle."
	.dexText ""
	.dexLang FR
	.dexText "BROUHABAM communique avec les autres"
	.dexText "en émettant un sifflement qui provient"
	.dexText "des tubes de son corps."
	.dexText "Ce POKéMON n`élève la voix que"
	.dexText "pendant les combats."
	.dexText ""
	.dexLang DE
	.dexText "KRAWUMMS vermittelt seinen Artge-"
	.dexText "nossen seine Gefühle, indem es eine Art"
	.dexText "Pfeifen durch die Röhren an seinem"
	.dexText "Körper von sich gibt. Dieses POKéMON"
	.dexText "erhebt nur im Kampf seine"
	.dexText "Stimme."
	.dexLang IT
	.dexText "EXPLOUD comunica le sue sensazioni"
	.dexText "emettendo una sorta di fischi dai"
	.dexText "canali tubolari del suo corpo."
	.dexText "Questo POKéMON alza la voce"
	.dexText "soltanto in lotta."
	.dexText ""
	.dexLang ES
	.dexText "EXPLOUD expresa sus sentimientos a los"
	.dexText "otros emitiendo una especie de silbidos"
	.dexText "a través de los tubos que tiene."
	.dexText "Este POKéMON sólo levanta la voz cuando"
	.dexText "está en combate."
	.dexText ""

	.align 2, 0
dexEntryEu48:: @ 048 MAKUHITA
	.2byte 0, 4, 8
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 1, 9, 0, 5, 10, 10, 8, 6, 4  @ weight
	.dexLang EN
	.dexName "MAKUHITA"
	.dexLang FR
	.dexName "MAKUHITA"
	.dexLang DE
	.dexName "MAKUHITA"
	.dexLang EN
	.dexCategory "GUTS"
	.dexLang FR
	.dexCategoryLeftAligned "TENACE"
	.dexLang DE
	.dexCategoryLeftAligned "COURAGE"
	.dexLang IT
	.dexCategoryLeftAligned "CORAGGIO"
	.dexLang ES
	.dexCategoryLeftAligned "VALIENTE"
	.dexLang EN
	.dexText "MAKUHITA has a tireless spirit -"
	.dexText "it will never give up hope. It eats a lot"
	.dexText "of food, gets plenty of sleep, and it"
	.dexText "trains very rigorously. By living that"
	.dexText "way, this POKéMON packs its body with"
	.dexText "energy."
	.dexLang FR
	.dexText "MAKUHITA a un moral infatigable. Il ne"
	.dexText "désespère jamais. Il mange beaucoup,"
	.dexText "dort beaucoup et s`entraîne avec"
	.dexText "rigueur. Son hygiène de vie"
	.dexText "permet à ce POKéMON d`accumuler"
	.dexText "un maximum d`énergie."
	.dexLang DE
	.dexText "MAKUHITAs Geist ist unbezwingbar. Es"
	.dexText "gibt die Hoffnung niemals auf. Es frisst"
	.dexText "eine Menge, bekommt viel Schlaf und"
	.dexText "trainiert unermüdlich. Dadurch füllt es"
	.dexText "seinen Körper mit Energie auf."
	.dexText ""
	.dexLang IT
	.dexText "MAKUHITA è infaticabile, perseverante"
	.dexText "e non perde mai la speranza. Mangia"
	.dexText "molto, dorme molto e si allena con"
	.dexText "rigore. Questo tenore di vita gli"
	.dexText "consente di essere sempre carico"
	.dexText "di energia."
	.dexLang ES
	.dexText "MAKUHITA tiene un ánimo inagotable."
	.dexText "Nunca pierde la esperanza. Come mucho,"
	.dexText "duerme bastante y se entrena de forma"
	.dexText "metódica. Siguiendo estos hábitos de"
	.dexText "vida, este POKéMON tiene siempre"
	.dexText "mucha energía."

	.align 2, 0
dexEntryEu49:: @ 049 HARIYAMA
	.2byte 0, 4, 9
	.2byte 10, 7, 0, 7, 10, 10, 2, 3  @ height
	.2byte 10, 5, 5, 9, 5, 10, 2, 5, 3, 8  @ weight
	.dexLang EN
	.dexName "HARIYAMA"
	.dexLang FR
	.dexName "HARIYAMA"
	.dexLang DE
	.dexName "HARIYAMA"
	.dexLang EN
	.dexCategory "ARM THRUST"
	.dexLang FR
	.dexCategoryLeftAligned "COGNEUR"
	.dexLang DE
	.dexCategoryLeftAligned "ARMWURF"
	.dexLang IT
	.dexCategoryLeftAligned "SBERLETESE"
	.dexLang ES
	.dexCategoryLeftAligned "EMPUJE"
	.dexLang EN
	.dexText "HARIYAMA`s thick body may appear fat,"
	.dexText "but it is actually a hunk of solid muscle."
	.dexText "If this POKéMON bears down and"
	.dexText "tightens all its muscles, its body"
	.dexText "becomes as hard as a rock."
	.dexText ""
	.dexLang FR
	.dexText "HARIYAMA a l`air un peu enrobé, mais"
	.dexText "c`est en fait une montagne de muscles."
	.dexText "Si ce POKéMON se raidit et contracte"
	.dexText "ses muscles, son corps devient dur"
	.dexText "comme de la pierre."
	.dexText ""
	.dexLang DE
	.dexText "HARIYAMAs Körper mag vielleicht fett"
	.dexText "aussehen, er besteht aber aus festen"
	.dexText "Muskeln. Wenn dieses POKéMON all"
	.dexText "seine Muskeln anspannt, wird sein"
	.dexText "Körper steinhart."
	.dexText ""
	.dexLang IT
	.dexText "Il robusto corpo di HARIYAMA può"
	.dexText "apparire grasso, ma in realtà è formato"
	.dexText "da una muscolatura tonica. Se contrae"
	.dexText "e tende ogni singolo muscolo,"
	.dexText "il suo corpo diventa duro come"
	.dexText "la roccia."
	.dexLang ES
	.dexText "Puede que parezca que HARIYAMA está"
	.dexText "grueso, pero en realidad es una mole de"
	.dexText "puro músculo."
	.dexText "Si este POKéMON hace fuerza y tensa"
	.dexText "la musculatura, se pone sólido como"
	.dexText "una roca."

	.align 2, 0
dexEntryEu50:: @ 050 GOLDEEN
	.2byte 0, 5, 0
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 3, 3, 1, 10, 10, 1, 5, 0  @ weight
	.dexLang EN
	.dexName "GOLDEEN"
	.dexLang FR
	.dexName "POISSIRENE"
	.dexLang DE
	.dexName "GOLDINI"
	.dexLang EN
	.dexCategory "GOLDFISH"
	.dexLang FR
	.dexCategoryLeftAligned "POISSON"
	.dexLang DE
	.dexCategoryLeftAligned "GOLDFISCH"
	.dexLang IT
	.dexCategoryLeftAligned "PESCEROSSO"
	.dexLang ES
	.dexCategoryLeftAligned "PEZ COLOR"
	.dexLang EN
	.dexText "GOLDEEN loves swimming wild and free"
	.dexText "in rivers and ponds."
	.dexText "If one of these POKéMON is placed in an"
	.dexText "aquarium, it will shatter even the"
	.dexText "thickest glass with one ram of its horn"
	.dexText "and make its escape."
	.dexLang FR
	.dexText "POISSIRENE adore nager librement dans"
	.dexText "les rivières et les étangs. Si l`un de ces"
	.dexText "POKéMON est mis dans un aquarium,"
	.dexText "il n`hésitera pas à casser la vitre avec"
	.dexText "sa puissante corne pour s`enfuir."
	.dexText ""
	.dexLang DE
	.dexText "GOLDINI liebt es, in Teichen und Flüssen"
	.dexText "zu schwimmen. Wenn ein solches"
	.dexText "POKéMON in ein Aquarium gebracht wird,"
	.dexText "wird es selbst das dickste Glas mit"
	.dexText "einem Stoß seines Horns zum Zerbersten"
	.dexText "bringen und die Flucht ergreifen."
	.dexLang IT
	.dexText "GOLDEEN ama nuotare libero in fiumi"
	.dexText "e laghetti. Se messo in acquario, questo"
	.dexText "POKéMON riesce a fuggire spaccando"
	.dexText "anche il vetro più spesso con un"
	.dexText "colpo secco del suo corno."
	.dexText ""
	.dexLang ES
	.dexText "A GOLDEEN le encanta nadar libremente"
	.dexText "y a su aire en ríos y estanques."
	.dexText "Si pones a uno de estos POKéMON en un"
	.dexText "acuario, usará el cuerno que tiene para"
	.dexText "romper las paredes, independientemente"
	.dexText "del grosor del cristal, y escapar."

	.align 2, 0
dexEntryEu51:: @ 051 SEAKING
	.2byte 0, 5, 1
	.2byte 10, 4, 0, 3, 10, 10, 1, 3  @ height
	.2byte 10, 10, 8, 6, 0, 10, 10, 3, 9, 0  @ weight
	.dexLang EN
	.dexName "SEAKING"
	.dexLang FR
	.dexName "POISSOROY"
	.dexLang DE
	.dexName "GOLKING"
	.dexLang EN
	.dexCategory "GOLDFISH"
	.dexLang FR
	.dexCategoryLeftAligned "POISSON"
	.dexLang DE
	.dexCategoryLeftAligned "GOLDFISCH"
	.dexLang IT
	.dexCategoryLeftAligned "PESCEROSSO"
	.dexLang ES
	.dexCategoryLeftAligned "PEZ COLOR"
	.dexLang EN
	.dexText "SEAKING is very protective of its eggs."
	.dexText "The male and female will take turns"
	.dexText "patrolling around their nest and eggs."
	.dexText "The guarding of eggs by these POKéMON"
	.dexText "goes on for over a month."
	.dexText ""
	.dexLang FR
	.dexText "Les POISSOROY font tout pour protéger"
	.dexText "leurs œufs. Les mâles et les femelles"
	.dexText "patrouillent pour surveiller le nid"
	.dexText "et les œufs. La garde de ces œufs"
	.dexText "dure un peu plus d`un mois."
	.dexText ""
	.dexLang DE
	.dexText "GOLKING gibt sehr viel Acht auf seine"
	.dexText "Brut. Es patrouilliert um sein Nest und"
	.dexText "die Eier herum, wobei sich das männliche"
	.dexText "und das weibliche Exemplar abwechseln."
	.dexText "Das Bewachen der Eier beschäftigt"
	.dexText "dieses POKéMON für über einen Monat."
	.dexLang IT
	.dexText "SEAKING protegge gelosamente le sue"
	.dexText "uova. Il maschio e la femmina si danno"
	.dexText "il cambio attorno al nido e alle uova."
	.dexText "Le uova vengono sorvegliate"
	.dexText "per oltre un mese."
	.dexText ""
	.dexLang ES
	.dexText "SEAKING protege sus huevos con uñas"
	.dexText "y dientes. Macho y hembra se turnan"
	.dexText "para vigilar el nido y los huevos."
	.dexText "Este periodo de protección dura más de"
	.dexText "un mes en el caso de estos POKéMON."
	.dexText ""

	.align 2, 0
dexEntryEu52:: @ 052 MAGIKARP
	.2byte 0, 5, 2
	.2byte 10, 2, 1, 1, 10, 10, 0, 9  @ height
	.2byte 10, 10, 2, 2, 0, 10, 10, 1, 0, 0  @ weight
	.dexLang EN
	.dexName "MAGIKARP"
	.dexLang FR
	.dexName "MAGICARPE"
	.dexLang DE
	.dexName "KARPADOR"
	.dexLang EN
	.dexCategory "FISH"
	.dexLang FR
	.dexCategoryLeftAligned "POISSON"
	.dexLang DE
	.dexCategoryLeftAligned "FISCH"
	.dexLang IT
	.dexCategoryLeftAligned "PESCE"
	.dexLang ES
	.dexCategoryLeftAligned "PEZ"
	.dexLang EN
	.dexText "MAGIKARP is virtually useless in battle"
	.dexText "as it can only splash around."
	.dexText "As a result, it is considered to be weak."
	.dexText "However, it is actually a very hardy"
	.dexText "POKéMON that can survive in any body of"
	.dexText "water no matter how polluted it is."
	.dexLang FR
	.dexText "MAGICARPE est virtuellement inutile"
	.dexText "en combat. Il se contente de faire des"
	.dexText "ronds dans l`eau. On le considère plutôt"
	.dexText "faible. Pourtant, ce POKéMON est très"
	.dexText "robuste et peut survivre dans n`importe"
	.dexText "quel environnement, même très pollué."
	.dexLang DE
	.dexText "KARPADOR ist im Kampf praktisch nutz-"
	.dexText "los, da es nur platschen kann."
	.dexText "Daher wird es als schwach eingeschätzt."
	.dexText "Es ist aber tatsächlich sehr robust und"
	.dexText "kann in jedem Gewässer überleben, egal,"
	.dexText "wie verseucht dieses ist."
	.dexLang IT
	.dexText "Nella lotta MAGIKARP è inutile,"
	.dexText "poiché può solo sguazzare."
	.dexText "Infatti è considerato debole."
	.dexText "In realtà si tratta di un POKéMON"
	.dexText "molto robusto che sopravvive in tutte"
	.dexText "le acque, anche le più inquinate."
	.dexLang ES
	.dexText "MAGIKARP es prácticamente inútil"
	.dexText "en combate; sólo sirve para salpicar,"
	.dexText "y se le considera muy débil."
	.dexText "Con todo, en realidad es un POKéMON muy"
	.dexText "práctico. Sobrevive en cualquier medio"
	.dexText "acuático, aunque esté contaminado."

	.align 2, 0
dexEntryEu53:: @ 053 GYARADOS
	.2byte 0, 5, 3
	.2byte 2, 1, 0, 4, 10, 10, 6, 5  @ height
	.2byte 10, 5, 1, 8, 1, 10, 2, 3, 5, 0  @ weight
	.dexLang EN
	.dexName "GYARADOS"
	.dexLang FR
	.dexName "LEVIATOR"
	.dexLang DE
	.dexName "GARADOS"
	.dexLang EN
	.dexCategory "ATROCIOUS"
	.dexLang FR
	.dexCategoryLeftAligned "TERRIFIANT"
	.dexLang DE
	.dexCategoryLeftAligned "GRAUSAM"
	.dexLang IT
	.dexCategoryLeftAligned "ATROCE"
	.dexLang ES
	.dexCategoryLeftAligned "ATROCIDAD"
	.dexLang EN
	.dexText "Once GYARADOS goes on a rampage, its"
	.dexText "ferociously violent blood doesn`t calm"
	.dexText "until it has burned everything down."
	.dexText "There are records of this POKéMON`s"
	.dexText "rampages lasting a whole month."
	.dexText ""
	.dexLang FR
	.dexText "Lorsque LEVIATOR commence à"
	.dexText "s`énerver, sa nature violente ne se"
	.dexText "calme qu`une fois qu`il a tout réduit"
	.dexText "en cendres. La fureur de ce POKéMON"
	.dexText "peut durer pendant un mois."
	.dexText ""
	.dexLang DE
	.dexText "Wenn GARADOS in Rage gerät, ist sein"
	.dexText "wildes Blut kaum zu beruhigen, bis es"
	.dexText "alles niedergebrannt hat."
	.dexText "Aufzeichnungen belegen, dass die"
	.dexText "Zerstörungswut dieses POKéMON einen"
	.dexText "ganzen Monat anhalten kann."
	.dexLang IT
	.dexText "Quando GYARADOS s`infuria, la sua"
	.dexText "indole feroce e violenta non si placa"
	.dexText "finché non ha incendiato ogni cosa."
	.dexText "Ci sono testimonianze di sfuriate di"
	.dexText "questo POKéMON durate anche"
	.dexText "un mese intero."
	.dexLang ES
	.dexText "Una vez que GYARADOS se desmanda,"
	.dexText "la presión incontrolable y enrabiada de"
	.dexText "la sangre no se le calmará hasta que no"
	.dexText "haya quemado todo lo que le rodea."
	.dexText "Según parece, a este POKéMON le duran"
	.dexText "los arranques de cólera hasta un mes."

	.align 2, 0
dexEntryEu54:: @ 054 AZURILL
	.2byte 0, 5, 4
	.2byte 10, 0, 0, 8, 10, 10, 0, 2  @ height
	.2byte 10, 10, 10, 4, 4, 10, 10, 10, 2, 0  @ weight
	.dexLang EN
	.dexName "AZURILL"
	.dexLang FR
	.dexName "AZURILL"
	.dexLang DE
	.dexName "AZURILL"
	.dexLang EN
	.dexCategory "POLKA DOT"
	.dexLang FR
	.dexCategoryLeftAligned "POINT POLKA"
	.dexLang DE
	.dexCategoryLeftAligned "GEPUNKTET"
	.dexLang IT
	.dexCategoryLeftAligned "POIS"
	.dexLang ES
	.dexCategoryLeftAligned "A TOPOS"
	.dexLang EN
	.dexText "AZURILL`s tail is large and bouncy."
	.dexText "It is packed full of the nutrients this"
	.dexText "POKéMON needs to grow."
	.dexText "AZURILL can be seen bouncing and"
	.dexText "playing on its big, rubbery tail."
	.dexText ""
	.dexLang FR
	.dexText "La grande queue d`AZURILL est"
	.dexText "élastique. Elle lui permet de stocker les"
	.dexText "nutriments nécessaires à sa"
	.dexText "croissance. Parfois, on voit AZURILL"
	.dexText "s`amuser à rebondir sur sa"
	.dexText "queue élastique."
	.dexLang DE
	.dexText "AZURILLs Schweif ist lang und federnd."
	.dexText "Er ist vollgepackt mit Nährstoffen, die"
	.dexText "dieses POKéMON zum Wachsen braucht."
	.dexText "Man kann es häufig dabei beobachten,"
	.dexText "wie es auf seinem gummiartigen Schweif"
	.dexText "umherhüpft und spielt."
	.dexLang IT
	.dexText "AZURILL è dotato di una coda lunga"
	.dexText "ed elastica. Inoltre, è ricca di sostanze"
	.dexText "nutritive indispensabili per la sua"
	.dexText "sopravvivenza. Spesso lo si vede"
	.dexText "saltellare e giocare sulla coda"
	.dexText "gommosa e molleggiata."
	.dexLang ES
	.dexText "AZURILL tiene una especie de pelota"
	.dexText "en la cola, que contiene los nutrientes"
	.dexText "necesarios para crecer."
	.dexText "Es fácil ver a este POKéMON saltando"
	.dexText "y jugueteando sentado encima de la"
	.dexText "misma."

	.align 2, 0
dexEntryEu55:: @ 055 MARILL
	.2byte 0, 5, 5
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 1, 8, 7, 10, 10, 10, 8, 5  @ weight
	.dexLang EN
	.dexName "MARILL"
	.dexLang FR
	.dexName "MARILL"
	.dexLang DE
	.dexName "MARILL"
	.dexLang EN
	.dexCategory "AQUA MOUSE"
	.dexLang FR
	.dexCategoryLeftAligned "AQUASOURIS"
	.dexLang DE
	.dexCategoryLeftAligned "AQUAMAUS"
	.dexLang IT
	.dexCategoryLeftAligned "ACQUATOPO"
	.dexLang ES
	.dexCategoryLeftAligned "RATÓN AGUA"
	.dexLang EN
	.dexText "When fishing for food at the edge of a"
	.dexText "fast-running stream, MARILL wraps its"
	.dexText "tail around the trunk of a tree."
	.dexText "This POKéMON`s tail is flexible and"
	.dexText "configured to stretch."
	.dexText ""
	.dexLang FR
	.dexText "Lorsqu`il pêche pour se nourrir sur les"
	.dexText "rives d`un fleuve rapide, MARILL"
	.dexText "accroche sa queue autour d`un"
	.dexText "tronc d`arbre pour ne pas être emporté."
	.dexText "La queue de ce POKéMON est flexible"
	.dexText "et résiste à l`étirement."
	.dexLang DE
	.dexText "Wenn es am Ufer eines reißenden Flusses"
	.dexText "fischt, wickelt MARILL seinen Schweif"
	.dexText "um einen Baumstamm. Der Schweif dieses"
	.dexText "POKéMON ist flexibel und elastisch, so"
	.dexText "dass es ihn ausdehnen kann."
	.dexText ""
	.dexLang IT
	.dexText "Per nutrirsi MARILL pesca il cibo in riva"
	.dexText "a torrenti impetuosi, avvinghiando"
	.dexText "la coda attorno ai tronchi degli alberi."
	.dexText "La coda di questo POKéMON è flessibile"
	.dexText "e dalla costituzione elastica."
	.dexText ""
	.dexLang ES
	.dexText "Este POKéMON tiene la cola muy flexible"
	.dexText "y elástica. A la hora de pescar"
	.dexText "a su presa en una rápida corriente,"
	.dexText "MARILL enrosca la cola en un árbol."
	.dexText ""
	.dexText ""

	.align 2, 0
dexEntryEu56:: @ 056 AZUMARILL
	.2byte 0, 5, 6
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 6, 2, 8, 10, 10, 2, 8, 5  @ weight
	.dexLang EN
	.dexName "AZUMARILL"
	.dexLang FR
	.dexName "AZUMARILL"
	.dexLang DE
	.dexName "AZUMARILL"
	.dexLang EN
	.dexCategory "AQUA RABBIT"
	.dexLang FR
	.dexCategoryLeftAligned "AQUALAPIN"
	.dexLang DE
	.dexCategoryLeftAligned "AQUAHASE"
	.dexLang IT
	.dexCategoryLeftAligned "ACQUNIGLIO"
	.dexLang ES
	.dexCategoryLeftAligned "CONEJOAGUA"
	.dexLang EN
	.dexText "AZUMARILL can make balloons out of"
	.dexText "air. It makes these air balloons if it"
	.dexText "spots a drowning POKéMON."
	.dexText "The air balloons enable the POKéMON in"
	.dexText "trouble to breathe."
	.dexText ""
	.dexLang FR
	.dexText "AZUMARILL peut faire des bulles d`air."
	.dexText "Il fabrique ces bulles lorsqu`il voit"
	.dexText "un POKéMON en train de se noyer."
	.dexText "Les bulles d`air permettent au POKéMON"
	.dexText "en difficulté de respirer."
	.dexText ""
	.dexLang DE
	.dexText "AZUMARILL kann aus Luft Ballons"
	.dexText "machen. Diese Luft-Ballons erzeugt es,"
	.dexText "wenn es ein ertrinkendes POKéMON"
	.dexText "erspäht. Durch die Ballons kann das"
	.dexText "POKéMON, das in Schwierigkeiten"
	.dexText "geraten ist, atmen."
	.dexLang IT
	.dexText "AZUMARILL riesce a creare bolle d`aria"
	.dexText "in grado di aiutare un POKéMON che"
	.dexText "sta per affogare. Quando ne vede uno,"
	.dexText "AZUMARILL gli manda una bolla"
	.dexText "per aiutarlo a respirare."
	.dexText ""
	.dexLang ES
	.dexText "AZUMARILL puede hacer burbujas de aire"
	.dexText "si ve a algún POKéMON que esté a punto"
	.dexText "de ahogarse."
	.dexText "Estas burbujas de aire son básicas"
	.dexText "para que los POKéMON puedan seguir"
	.dexText "respirando."

	.align 2, 0
dexEntryEu57:: @ 057 GEODUDE
	.2byte 0, 5, 7
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 4, 4, 1, 10, 10, 2, 0, 0  @ weight
	.dexLang EN
	.dexName "GEODUDE"
	.dexLang FR
	.dexName "RACAILLOU"
	.dexLang DE
	.dexName "KLEINSTEIN"
	.dexLang EN
	.dexCategory "ROCK"
	.dexLang FR
	.dexCategoryLeftAligned "ROCHE"
	.dexLang DE
	.dexCategoryLeftAligned "GESTEIN"
	.dexLang IT
	.dexCategoryLeftAligned "ROCCIA"
	.dexLang ES
	.dexCategoryLeftAligned "ROCA"
	.dexLang EN
	.dexText "When GEODUDE sleeps deeply, it buries"
	.dexText "itself halfway into the ground."
	.dexText "It will not awaken even if hikers step"
	.dexText "on it unwittingly."
	.dexText "In the morning, this POKéMON rolls"
	.dexText "downhill in search of food."
	.dexLang FR
	.dexText "Pour dormir profondément, RACAILLOU"
	.dexText "s`enterre à moitié dans le sol. Il ne se"
	.dexText "réveille pas, même si des randonneurs"
	.dexText "lui marchent dessus. Au petit matin,"
	.dexText "ce POKéMON roule en contrebas"
	.dexText "en quête de nourriture."
	.dexLang DE
	.dexText "Wenn KLEINSTEIN tief und fest schläft,"
	.dexText "gräbt es sich selbst zur Hälfte im Boden"
	.dexText "ein. Selbst wenn Wanderer versehentlich"
	.dexText "auf KLEINSTEIN treten, wacht es nicht"
	.dexText "auf. Am Morgen rollt es auf der Suche"
	.dexText "nach Nahrung den Berg herunter."
	.dexLang IT
	.dexText "Quando GEODUDE dorme profondamente"
	.dexText "si nasconde parzialmente nel terreno."
	.dexText "Non si sveglia neanche se i passanti"
	.dexText "lo calpestano involontariamente."
	.dexText "La mattina questo POKéMON rotola"
	.dexText "a valle in cerca di cibo."
	.dexLang ES
	.dexText "Cuando GEODUDE duerme profundamente,"
	.dexText "se entierra a medias en el suelo y no se"
	.dexText "despierta ni aunque lo pisen sin querer."
	.dexText "Por la mañana, se dedica a buscar comida"
	.dexText "rodando ladera abajo."
	.dexText ""

	.align 2, 0
dexEntryEu58:: @ 058 GRAVELER
	.2byte 0, 5, 8
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 2, 3, 1, 5, 10, 1, 0, 5, 0  @ weight
	.dexLang EN
	.dexName "GRAVELER"
	.dexLang FR
	.dexName "GRAVALANCH"
	.dexLang DE
	.dexName "GEOROK"
	.dexLang EN
	.dexCategory "ROCK"
	.dexLang FR
	.dexCategoryLeftAligned "ROCHE"
	.dexLang DE
	.dexCategoryLeftAligned "GESTEIN"
	.dexLang IT
	.dexCategoryLeftAligned "ROCCIA"
	.dexLang ES
	.dexCategoryLeftAligned "ROCA"
	.dexLang EN
	.dexText "Rocks are GRAVELER`s favorite food."
	.dexText "This POKéMON will climb a mountain from"
	.dexText "the base to the summit, crunchingly"
	.dexText "feasting on rocks all the while."
	.dexText "Upon reaching the peak, it rolls back"
	.dexText "down to the bottom."
	.dexLang FR
	.dexText "La nourriture préférée de GRAVALANCH"
	.dexText "est la roche. Ce POKéMON escalade"
	.dexText "parfois les montagnes, dévorant les"
	.dexText "rochers sur son passage."
	.dexText "Une fois au sommet, il se laisse rouler"
	.dexText "jusqu`en bas."
	.dexLang DE
	.dexText "Steine sind GEOROKs Lieblingsspeise."
	.dexText "Dieses POKéMON klettert vom Fuße"
	.dexText "eines Berges zu seinem Gipfel empor"
	.dexText "und zermalmt dabei das Gestein. Wenn es"
	.dexText "den Gipfel erreicht hat, rollt es wieder"
	.dexText "herunter."
	.dexLang IT
	.dexText "Il cibo preferito da GRAVELER sono"
	.dexText "le rocce. Infatti è capace di risalire"
	.dexText "un monte dalla base alla cima,"
	.dexText "sgranocchiando rocce tutto il tempo."
	.dexText "Una volta raggiunta la cima, si lancia"
	.dexText "in discesa rotolando."
	.dexLang ES
	.dexText "Las piedras son la comida preferida de"
	.dexText "GRAVELER. Este POKéMON sube a la cima"
	.dexText "de las montañas devorando todas"
	.dexText "las rocas que va encontrando a su paso."
	.dexText "Una vez que alcanza la cumbre, se baja"
	.dexText "rodando hasta la falda."

	.align 2, 0
dexEntryEu59:: @ 059 GOLEM
	.2byte 0, 5, 9
	.2byte 10, 4, 0, 7, 10, 10, 1, 4  @ height
	.2byte 10, 6, 6, 1, 4, 10, 3, 0, 0, 0  @ weight
	.dexLang EN
	.dexName "GOLEM"
	.dexLang FR
	.dexName "GROLEM"
	.dexLang DE
	.dexName "GEOWAZ"
	.dexLang EN
	.dexCategory "MEGATON"
	.dexLang FR
	.dexCategoryLeftAligned "TITANESQUE"
	.dexLang DE
	.dexCategoryLeftAligned "URGESTEIN"
	.dexLang IT
	.dexCategoryLeftAligned "MEGATONE"
	.dexLang ES
	.dexCategoryLeftAligned "MEGATÓN"
	.dexLang EN
	.dexText "GOLEM is known for rolling down from"
	.dexText "mountains. To prevent them from rolling"
	.dexText "into the homes of people downhill,"
	.dexText "grooves have been dug into the sides of"
	.dexText "mountains to serve as guideways for"
	.dexText "diverting this POKéMON`s course."
	.dexLang FR
	.dexText "On sait que les GROLEM se laissent"
	.dexText "rouler en bas des montagnes. Afin"
	.dexText "d`éviter qu`ils roulent sur les maisons"
	.dexText "des gens, des tranchées ont été"
	.dexText "creusées le long des montagnes pour les"
	.dexText "guider dans leurs descentes infernales."
	.dexLang DE
	.dexText "GEOWAZ ist dafür bekannt, dass es"
	.dexText "Berghänge herunterrollt. Damit es nicht"
	.dexText "in die Häuser der Menschen hineinrollt,"
	.dexText "wurden Gräben so an den Bergen"
	.dexText "angelegt, dass der Weg dieses POKéMON"
	.dexText "umgeleitet wird."
	.dexLang IT
	.dexText "GOLEM è noto per rotolare in discesa"
	.dexText "lungo il pendio dei monti. Per evitare"
	.dexText "che finisca dentro le case a valle,"
	.dexText "sono stati creati dei canaloni sui"
	.dexText "pendii dei monti per guidarne"
	.dexText "il percorso durante la discesa."
	.dexLang ES
	.dexText "GOLEM es conocido por su afición a"
	.dexText "bajar de las montañas rodando. La gente"
	.dexText "que vive en la falda de las mismas"
	.dexText "ha cavado surcos para conducirlo"
	.dexText "en su descenso por las laderas"
	.dexText "y evitar que se cuele en sus casas."

	.align 2, 0
dexEntryEu60:: @ 060 NOSEPASS
	.2byte 0, 6, 0
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 2, 1, 3, 8, 10, 10, 9, 7, 0  @ weight
	.dexLang EN
	.dexName "NOSEPASS"
	.dexLang FR
	.dexName "TARINOR"
	.dexLang DE
	.dexName "NASGNET"
	.dexLang EN
	.dexCategory "COMPASS"
	.dexLang FR
	.dexCategoryLeftAligned "BOUSSOLE"
	.dexLang DE
	.dexCategoryLeftAligned "KOMPASS"
	.dexLang IT
	.dexCategoryLeftAligned "BUSSOLA"
	.dexLang ES
	.dexCategoryLeftAligned "BRÚJULA"
	.dexLang EN
	.dexText "NOSEPASS`s magnetic nose is always"
	.dexText "pointed to the north. If two of these"
	.dexText "POKéMON meet, they cannot turn"
	.dexText "their faces to each other when they"
	.dexText "are close because their magnetic noses"
	.dexText "repel one another."
	.dexLang FR
	.dexText "Le nez magnétique de TARINOR"
	.dexText "pointe toujours vers le nord. Si deux de"
	.dexText "ces POKéMON se rencontrent, ils ne"
	.dexText "peuvent pas se faire face car leurs"
	.dexText "nez magnétiques se repoussent."
	.dexText ""
	.dexLang DE
	.dexText "NASGNET besitzt eine magnetische"
	.dexText "Nase, die immer nach Norden zeigt. Wenn"
	.dexText "sich zwei NASGNET treffen, können sie"
	.dexText "sich einander nicht zuwenden, da ihre"
	.dexText "magnetischen Nasen sich gegenseitig"
	.dexText "abstoßen."
	.dexLang IT
	.dexText "Il naso magnetico di NOSEPASS è"
	.dexText "sempre puntato verso nord. Quando"
	.dexText "incontra un suo simile, non riesce a"
	.dexText "guardarlo in volto da vicino perché"
	.dexText "i nasi magnetici si respingono l`un"
	.dexText "l`altro."
	.dexLang ES
	.dexText "NOSEPASS siempre está con el pico"
	.dexText "magnético que tiene orientado hacia"
	.dexText "el norte."
	.dexText "Si se encuentra con otro ejemplar de"
	.dexText "su especie, no puede mirarle de frente"
	.dexText "porque sus polos magnéticos se repelen."

	.align 2, 0
dexEntryEu61:: @ 061 SKITTY
	.2byte 0, 6, 1
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 2, 4, 3, 10, 10, 1, 1, 0  @ weight
	.dexLang EN
	.dexName "SKITTY"
	.dexLang FR
	.dexName "SKITTY"
	.dexLang DE
	.dexName "ENECO"
	.dexLang EN
	.dexCategory "KITTEN"
	.dexLang FR
	.dexCategoryLeftAligned "CHATON"
	.dexLang DE
	.dexCategoryLeftAligned "KÄTZCHEN"
	.dexLang IT
	.dexCategoryLeftAligned "MICIO"
	.dexLang ES
	.dexCategoryLeftAligned "GATITO"
	.dexLang EN
	.dexText "SKITTY has the habit of becoming"
	.dexText "fascinated by moving objects and"
	.dexText "chasing them around."
	.dexText "This POKéMON is known to chase after"
	.dexText "its own tail and become dizzy."
	.dexText ""
	.dexLang FR
	.dexText "SKITTY a pris l`habitude de"
	.dexText "pourchasser les objets mobiles qui"
	.dexText "le fascinent."
	.dexText "On sait que ce POKéMON court souvent"
	.dexText "après sa queue, jusqu`à ce qu`il ait"
	.dexText "la tête qui tourne."
	.dexLang DE
	.dexText "ENECO ist davon fasziniert,"
	.dexText "Gegenstände zu bewegen und sie zu"
	.dexText "jagen. Dieses POKéMON jagt häufig"
	.dexText "seinen eigenen Schweif, so dass ihm"
	.dexText "schwindlig wird."
	.dexText ""
	.dexLang IT
	.dexText "SKITTY ha l`abitudine di lasciarsi"
	.dexText "ammaliare dagli oggetti in movimento"
	.dexText "e seguirli dando loro la caccia."
	.dexText "Questo POKéMON è noto anche per"
	.dexText "rincorrere la sua stessa coda fino"
	.dexText "a rimanere stordito."
	.dexLang ES
	.dexText "A SKITTY le encanta mover cosas e ir"
	.dexText "detrás de ellas. Es de todos sabido que"
	.dexText "se dedica a ir detrás de su propia cola"
	.dexText "y que, al final, acaba mareándose."
	.dexText ""
	.dexText ""

	.align 2, 0
dexEntryEu62:: @ 062 DELCATTY
	.2byte 0, 6, 2
	.2byte 10, 3, 0, 7, 10, 10, 1, 1  @ height
	.2byte 10, 10, 7, 1, 9, 10, 10, 3, 2, 6  @ weight
	.dexLang EN
	.dexName "DELCATTY"
	.dexLang FR
	.dexName "DELCATTY"
	.dexLang DE
	.dexName "ENEKORO"
	.dexLang EN
	.dexCategory "PRIM"
	.dexLang FR
	.dexCategoryLeftAligned "GUINDE"
	.dexLang DE
	.dexCategoryLeftAligned "EINGEBILDET"
	.dexLang IT
	.dexCategoryLeftAligned "FINEZZA"
	.dexLang ES
	.dexCategoryLeftAligned "CURSI"
	.dexLang EN
	.dexText "DELCATTY prefers to live an unfettered"
	.dexText "existence in which it can do as it"
	.dexText "pleases at its own pace."
	.dexText "Because this POKéMON eats and sleeps"
	.dexText "whenever it decides, its daily routines"
	.dexText "are completely random."
	.dexLang FR
	.dexText "DELCATTY préfère vivre une"
	.dexText "existence sans contraintes, au cours"
	.dexText "de laquelle chacun pourrait faire ce"
	.dexText "qu`il veut. Comme ce POKéMON mange"
	.dexText "et dort quand il le décide, son rythme"
	.dexText "de vie est totalement aléatoire."
	.dexLang DE
	.dexText "ENEKORO liebt seine Eigenständigkeit."
	.dexText "So kann es das tun, was es möchte, und"
	.dexText "kann selbst das Tempo bestimmen."
	.dexText "Da dieses POKéMON schläft und isst,"
	.dexText "wenn es Lust dazu hat, ist sein"
	.dexText "Tagesablauf eher zufälliger Natur."
	.dexLang IT
	.dexText "DELCATTY preferisce vivere una vita in"
	.dexText "libertà, in cui poter fare ciò che più gli"
	.dexText "aggrada in base alle proprie esigenze."
	.dexText "Poiché anche gli orari dei pasti e del"
	.dexText "sonno sono completamente liberi,"
	.dexText "la sua vita quotidiana è casuale."
	.dexLang ES
	.dexText "DELCATTY prefiere llevar una vida"
	.dexText "independiente y hacer lo que se le"
	.dexText "antoje. Como este POKéMON come"
	.dexText "y duerme según vea en cada momento,"
	.dexText "no se puede decir que tenga unos"
	.dexText "hábitos regulares en el día a día."

	.align 2, 0
dexEntryEu63:: @ 063 ZUBAT
	.2byte 0, 6, 3
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 1, 6, 5, 10, 10, 10, 7, 5  @ weight
	.dexLang EN
	.dexName "ZUBAT"
	.dexLang FR
	.dexName "NOSFERAPTI"
	.dexLang DE
	.dexName "ZUBAT"
	.dexLang EN
	.dexCategory "BAT"
	.dexLang FR
	.dexCategoryLeftAligned "CHOVSOURIS"
	.dexLang DE
	.dexCategoryLeftAligned "FLEDERMAUS"
	.dexLang IT
	.dexCategoryLeftAligned "PIPISTREL"
	.dexLang ES
	.dexCategoryLeftAligned "MURCIÉLAGO"
	.dexLang EN
	.dexText "ZUBAT avoids sunlight because exposure"
	.dexText "causes it to become unhealthy."
	.dexText "During the daytime, it stays in caves or"
	.dexText "under the eaves of old houses, sleeping"
	.dexText "while hanging upside down."
	.dexText ""
	.dexLang FR
	.dexText "NOSFERAPTI évite la lumière du soleil,"
	.dexText "car ça le rend malade. Pendant la"
	.dexText "journée, il reste dans les cavernes ou à"
	.dexText "l`ombre des vieilles maisons, où il dort,"
	.dexText "la tête à l`envers."
	.dexText ""
	.dexLang DE
	.dexText "ZUBAT meidet Sonnenlicht, da es dadurch"
	.dexText "krank würde. Am Tage hält es sich in"
	.dexText "Höhlen oder unter den Dachrinnen alter"
	.dexText "Häuser auf. Dort schläft es mit dem"
	.dexText "Kopf nach unten."
	.dexText ""
	.dexLang IT
	.dexText "ZUBAT evita la luce del sole perché"
	.dexText "nociva per la sua salute. Durante il"
	.dexText "giorno sta rintanato in grotte o sotto"
	.dexText "i cornicioni di vecchie case,"
	.dexText "dormendo appeso a testa in giù."
	.dexText ""
	.dexLang ES
	.dexText "ZUBAT evita la luz del día porque le"
	.dexText "resulta perjudicial para la salud."
	.dexText "Durante el día, permanece en cuevas"
	.dexText "o bajo los aleros de las casas viejas"
	.dexText "durmiendo colgado de las patas, cabeza"
	.dexText "abajo."

	.align 2, 0
dexEntryEu64:: @ 064 GOLBAT
	.2byte 0, 6, 4
	.2byte 10, 5, 0, 3, 10, 10, 1, 6  @ height
	.2byte 10, 1, 2, 1, 3, 10, 10, 5, 5, 0  @ weight
	.dexLang EN
	.dexName "GOLBAT"
	.dexLang FR
	.dexName "NOSFERALTO"
	.dexLang DE
	.dexName "GOLBAT"
	.dexLang EN
	.dexCategory "BAT"
	.dexLang FR
	.dexCategoryLeftAligned "CHOVSOURIS"
	.dexLang DE
	.dexCategoryLeftAligned "FLEDERMAUS"
	.dexLang IT
	.dexCategoryLeftAligned "PIPISTREL"
	.dexLang ES
	.dexCategoryLeftAligned "MURCIÉLAGO"
	.dexLang EN
	.dexText "GOLBAT bites down on prey with its four"
	.dexText "fangs and drinks the victim`s blood."
	.dexText "It becomes active on inky dark"
	.dexText "moonless nights, flying around to"
	.dexText "attack people and POKéMON."
	.dexText ""
	.dexLang FR
	.dexText "NOSFERALTO mord sa proie grâce à ses"
	.dexText "quatre crocs pour boire son sang."
	.dexText "Il ne sort que lorsque la nuit est noire"
	.dexText "et sans lune, pour voleter en quête de"
	.dexText "gens et de POKéMON à mordre."
	.dexText ""
	.dexLang DE
	.dexText "GOLBAT beißt seine Beute mit seinen"
	.dexText "vier Reißzähnen und trinkt das Blut"
	.dexText "seiner Opfer. Es wird in Nächten aktiv,"
	.dexText "in denen nicht einmal der Mond scheint."
	.dexText "Es fliegt dann durch die Dunkelheit und"
	.dexText "greift Menschen und POKéMON an."
	.dexLang IT
	.dexText "GOLBAT azzanna i nemici con i suoi"
	.dexText "quattro canini e ne beve il sangue."
	.dexText "È particolarmente attivo"
	.dexText "nel buio pesto delle notti senza luna"
	.dexText "e vola attaccando le persone e"
	.dexText "gli altri POKéMON."
	.dexLang ES
	.dexText "GOLBAT derriba a sus víctimas"
	.dexText "mordiéndoles con los cuatro colmillos"
	.dexText "que tiene y chupándoles la sangre."
	.dexText "Sólo entra en acción en las noches"
	.dexText "sin luna. Revolotea en la oscuridad"
	.dexText "para atacar a POKéMON y personas."

	.align 2, 0
dexEntryEu65:: @ 065 CROBAT
	.2byte 0, 6, 5
	.2byte 10, 5, 1, 1, 10, 10, 1, 8  @ height
	.2byte 10, 1, 6, 5, 3, 10, 10, 7, 5, 0  @ weight
	.dexLang EN
	.dexName "CROBAT"
	.dexLang FR
	.dexName "NOSTENFER"
	.dexLang DE
	.dexName "IKSBAT"
	.dexLang EN
	.dexCategory "BAT"
	.dexLang FR
	.dexCategoryLeftAligned "CHOVSOURIS"
	.dexLang DE
	.dexCategoryLeftAligned "FLEDERMAUS"
	.dexLang IT
	.dexCategoryLeftAligned "PIPISTREL"
	.dexLang ES
	.dexCategoryLeftAligned "MURCIÉLAGO"
	.dexLang EN
	.dexText "CROBAT sneaks up on its intended prey"
	.dexText "using wings that barely make a sound."
	.dexText "This POKéMON rests by hanging on a"
	.dexText "tree branch with its rear legs that"
	.dexText "serve as wings."
	.dexText ""
	.dexLang FR
	.dexText "NOSTENFER s`approche discrètement de"
	.dexText "sa proie grâce à ses ailes silencieuses."
	.dexText "Ce POKéMON se repose en s`accrochant"
	.dexText "à une branche avec ses pattes arrière,"
	.dexText "qui peuvent aussi lui servir d`ailes."
	.dexText ""
	.dexLang DE
	.dexText "IKSBATs Flügelschlag ist so leise, dass"
	.dexText "die Beute lautlos überrascht wird."
	.dexText "Dieses POKéMON ruht sich"
	.dexText "aus, indem es sich mit seinen"
	.dexText "Hinterbeinen, die ihm als Flügel"
	.dexText "dienen, an einen Ast hängt."
	.dexLang IT
	.dexText "CROBAT si avvicina furtivo alla preda"
	.dexText "con le sue ali silenziosissime."
	.dexText "Questo POKéMON si riposa aggrappato"
	.dexText "ai rami degli alberi con le zampe"
	.dexText "posteriori, che servono anche da ali."
	.dexText ""
	.dexLang ES
	.dexText "CROBAT se acerca hasta su posible"
	.dexText "presa usando las alas casi sin hacer"
	.dexText "ruido."
	.dexText "La forma de descansar que tiene es"
	.dexText "colgarse de la rama de un árbol por las"
	.dexText "patas traseras, que también son alas."

	.align 2, 0
dexEntryEu66:: @ 066 TENTACOOL
	.2byte 0, 6, 6
	.2byte 10, 2, 1, 1, 10, 10, 0, 9  @ height
	.2byte 10, 1, 0, 0, 3, 10, 10, 4, 5, 5  @ weight
	.dexLang EN
	.dexName "TENTACOOL"
	.dexLang FR
	.dexName "TENTACOOL"
	.dexLang DE
	.dexName "TENTACHA"
	.dexLang EN
	.dexCategory "JELLYFISH"
	.dexLang FR
	.dexCategoryLeftAligned "MOLLUSQUE"
	.dexLang DE
	.dexCategoryLeftAligned "QUALLE"
	.dexLang IT
	.dexCategoryLeftAligned "MEDUSA"
	.dexLang ES
	.dexCategoryLeftAligned "MEDUSA"
	.dexLang EN
	.dexText "TENTACOOL`s body is largely composed"
	.dexText "of water. If it is removed from the"
	.dexText "sea, it dries up like parchment."
	.dexText "If this POKéMON happens to become"
	.dexText "dehydrated, put it back into the sea."
	.dexText ""
	.dexLang FR
	.dexText "Le corps de TENTACOOL est princi-"
	.dexText "palement aqueux. Si on le retire"
	.dexText "de l`eau, il se déshydrate complètement."
	.dexText "Si cela arrive, il suffit de le replonger"
	.dexText "dans un liquide pour qu`il reprenne sa"
	.dexText "forme normale."
	.dexLang DE
	.dexText "TENTACHAs Körper setzt sich zum größ-"
	.dexText "ten Teil aus Wasser zusammen. Wenn es"
	.dexText "das Meer verlässt, vertrocknet es."
	.dexText "Wenn dieses POKéMON auszutrocknen be-"
	.dexText "ginnt, sollte man es schnell wieder ins"
	.dexText "Wasser zurückbringen."
	.dexLang IT
	.dexText "Il corpo di TENTACOOL è costituito"
	.dexText "quasi solo d`acqua. Se pescato ed"
	.dexText "esposto all`aria, si secca totalmente."
	.dexText "In caso di disidratazione, dunque,"
	.dexText "si consiglia di rimetterlo in mare."
	.dexText ""
	.dexLang ES
	.dexText "TENTACOOL está compuesto en su mayor"
	.dexText "parte por agua. Si lo sacas del mar,"
	.dexText "se secará y se quedará acartonado."
	.dexText "Si este POKéMON se deshidrata,"
	.dexText "hay que ponerlo inmediatamente"
	.dexText "de vuelta en el mar."

	.align 2, 0
dexEntryEu67:: @ 067 TENTACRUEL
	.2byte 0, 6, 7
	.2byte 10, 5, 0, 3, 10, 10, 1, 6  @ height
	.2byte 10, 1, 2, 1, 3, 10, 10, 5, 5, 0  @ weight
	.dexLang EN
	.dexName "TENTACRUEL"
	.dexLang FR
	.dexName "TENTACRUEL"
	.dexLang DE
	.dexName "TENTOXA"
	.dexLang EN
	.dexCategory "JELLYFISH"
	.dexLang FR
	.dexCategoryLeftAligned "MOLLUSQUE"
	.dexLang DE
	.dexCategoryLeftAligned "QUALLE"
	.dexLang IT
	.dexCategoryLeftAligned "MEDUSA"
	.dexLang ES
	.dexCategoryLeftAligned "MEDUSA"
	.dexLang EN
	.dexText "TENTACRUEL has large red orbs on its"
	.dexText "head. The orbs glow before lashing the"
	.dexText "vicinity with a harsh ultrasonic blast."
	.dexText "This POKéMON`s outburst creates rough"
	.dexText "waves around it."
	.dexText ""
	.dexLang FR
	.dexText "TENTACRUEL a deux gros globes sur la"
	.dexText "tête. Les globes s`illuminent lorsqu`il va"
	.dexText "envoyer un violent rayon d`ultrasons."
	.dexText "Lorsque ce POKéMON se déchaîne, il"
	.dexText "crée d`énormes vagues autour de lui."
	.dexText ""
	.dexLang DE
	.dexText "TENTOXA hat große, rote Kugeln auf"
	.dexText "seinem Kopf. Sie glühen auf, bevor sie"
	.dexText "seine Gegner mit Ultraschall"
	.dexText "erschüttern. Ein Ausbruch dieses"
	.dexText "POKéMON erzeugt starke Wellen"
	.dexText "in seiner Umgebung."
	.dexLang IT
	.dexText "Gli occhi di TENTACRUEL sono due"
	.dexText "grandi sfere rosse. Le sfere brillano"
	.dexText "prima di emettere potenti ultrasuoni."
	.dexText "Gli attacchi di questo POKéMON"
	.dexText "creano onde impetuose nei dintorni."
	.dexText ""
	.dexLang ES
	.dexText "TENTACRUEL tiene unas enormes"
	.dexText "esferas rojas en la cabeza, que brillan"
	.dexText "antes de lanzar una descarga"
	.dexText "ultrasónica a lo que le rodea."
	.dexText "Este estallido crea unas"
	.dexText "olas tremendas a su alrededor."

	.align 2, 0
dexEntryEu68:: @ 068 SABLEYE
	.2byte 0, 6, 8
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 2, 4, 3, 10, 10, 1, 1, 0  @ weight
	.dexLang EN
	.dexName "SABLEYE"
	.dexLang FR
	.dexName "TENEFIX"
	.dexLang DE
	.dexName "ZOBIRIS"
	.dexLang EN
	.dexCategory "DARKNESS"
	.dexLang FR
	.dexCategoryLeftAligned "OBSCURITE"
	.dexLang DE
	.dexCategoryLeftAligned "FINSTERNIS"
	.dexLang IT
	.dexCategoryLeftAligned "OSCURITÀ"
	.dexLang ES
	.dexCategoryLeftAligned "OSCURO"
	.dexLang EN
	.dexText "SABLEYE digs the ground with sharpened"
	.dexText "claws to find rocks that it eats."
	.dexText "Substances in the eaten rocks"
	.dexText "crystallize and rise up to the POKéMON`s"
	.dexText "body surface."
	.dexText ""
	.dexLang FR
	.dexText "TENEFIX creuse le sol avec ses"
	.dexText "griffes acérées pour trouver des"
	.dexText "rochers à manger. Les substances"
	.dexText "des rochers avalés se cristallisent"
	.dexText "et remontent sur la peau de"
	.dexText "ce POKéMON."
	.dexLang DE
	.dexText "ZOBIRIS durchwühlt mit seinen scharfen"
	.dexText "Krallen den Erdboden auf der Suche nach"
	.dexText "Steinen, von denen es sich ernährt."
	.dexText "Die Substanzen in den Steinen nehmen"
	.dexText "schließlich eine feste Form an und"
	.dexText "gelangen auf seine Körperoberfläche."
	.dexLang IT
	.dexText "SABLEYE scava il terreno con i suoi"
	.dexText "artigli affilati per trovare le pietre"
	.dexText "di cui si nutre."
	.dexText "Le sostanze ingerite si cristallizzano"
	.dexText "ed emergono a livello epidermico."
	.dexText ""
	.dexLang ES
	.dexText "SABLEYE cava en el suelo para buscar,"
	.dexText "con las afiladas garras que tiene, rocas"
	.dexText "para comer."
	.dexText "Las sustancias que hay en las rocas que"
	.dexText "ingiere se solidifican y se le quedan"
	.dexText "en la piel."

	.align 2, 0
dexEntryEu69:: @ 069 MAWILE
	.2byte 0, 6, 9
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 2, 5, 4, 10, 10, 1, 1, 5  @ weight
	.dexLang EN
	.dexName "MAWILE"
	.dexLang FR
	.dexName "MYSDIBULE"
	.dexLang DE
	.dexName "FLUNKIFER"
	.dexLang EN
	.dexCategory "DECEIVER"
	.dexLang FR
	.dexCategoryLeftAligned "TROMPEUR"
	.dexLang DE
	.dexCategoryLeftAligned "SCHWINDLER"
	.dexLang IT
	.dexCategoryLeftAligned "INGANNO"
	.dexLang ES
	.dexCategoryLeftAligned "TRAMPOSO"
	.dexLang EN
	.dexText "MAWILE`s huge jaws are actually steel"
	.dexText "horns that have been transformed."
	.dexText "Its docile-looking face serves to lull"
	.dexText "its foe into letting down its guard."
	.dexText "When the foe least expects it, MAWILE"
	.dexText "chomps it with its gaping jaws."
	.dexLang FR
	.dexText "Les énormes mâchoires de MYSDIBULE"
	.dexText "sont en réalité des cornes en métal"
	.dexText "transformées. Son visage doux et gentil"
	.dexText "est un leurre pour tromper l`ennemi."
	.dexText "Quand l`ennemi s`y attend le moins,"
	.dexText "il le croque d`un coup de mâchoire."
	.dexLang DE
	.dexText "FLUNKIFERs sagenhafte Kiefer sind"
	.dexText "eigentlich umgewandelte Stahlhörner."
	.dexText "Sein unterwürfiger Gesichtsausdruck"
	.dexText "dient dazu, seinen Gegner in Sicherheit"
	.dexText "zu wiegen, so dass er unaufmerksam"
	.dexText "wird. Dann schnappt es zu!"
	.dexLang IT
	.dexText "Le enormi mascelle di MAWILE sono"
	.dexText "in realtà corna d`acciaio trasformate."
	.dexText "Il volto dallo sguardo tanto mansueto"
	.dexText "serve a indurre i nemici ad abbassare"
	.dexText "la guardia. Infatti MAWILE attacca"
	.dexText "quando l`avversario meno se l`aspetta."
	.dexLang ES
	.dexText "Las descomunales fauces de acero de"
	.dexText "MAWILE son la evolución de unos cuernos"
	.dexText "que tuvo en su día."
	.dexText "Con su expresión dócil puede engañar al"
	.dexText "enemigo y hacer que baje la guardia para"
	.dexText "sorprenderle con las fauces."

	.align 2, 0
dexEntryEu70:: @ 070 ARON
	.2byte 0, 7, 0
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 1, 3, 2, 3, 10, 10, 6, 0, 0  @ weight
	.dexLang EN
	.dexName "ARON"
	.dexLang FR
	.dexName "GALEKID"
	.dexLang DE
	.dexName "STOLLUNIOR"
	.dexLang EN
	.dexCategory "IRON ARMOR"
	.dexLang FR
	.dexCategoryLeftAligned "ARMURFER"
	.dexLang DE
	.dexCategoryLeftAligned "EISENPANZER"
	.dexLang IT
	.dexCategoryLeftAligned "CORAZZA"
	.dexLang ES
	.dexCategoryLeftAligned "COR{39E6}FÉRREA"
	.dexLang EN
	.dexText "ARON has a body of steel."
	.dexText "With one all-out charge, this POKéMON"
	.dexText "can demolish even a heavy dump truck."
	.dexText "The destroyed dump truck then becomes"
	.dexText "a handy meal for the POKéMON."
	.dexText ""
	.dexLang FR
	.dexText "GALEKID a un corps d`acier."
	.dexText "En une seule charge, ce POKéMON"
	.dexText "peut démolir un camion poids lourd."
	.dexText "Le camion détruit devient ensuite le"
	.dexText "repas de ce POKéMON."
	.dexText ""
	.dexLang DE
	.dexText "STOLLUNIORs Körper besteht aus Stahl."
	.dexText "Mit 1 Schlag kann dieses POKéMON einen"
	.dexText "Schwerlasttransporter demolieren."
	.dexText "Der Lastwagen stellt danach eine"
	.dexText "handliche Mahlzeit für dieses POKéMON"
	.dexText "dar."
	.dexLang IT
	.dexText "ARON è dotato di un corpo d`acciaio."
	.dexText "Con una sola potente carica riesce a"
	.dexText "demolire anche un camion a rimorchio."
	.dexText "Questo costituisce poi un sano e ricco"
	.dexText "pasto per il POKéMON."
	.dexText ""
	.dexLang ES
	.dexText "ARON tiene el cuerpo de acero. Con una"
	.dexText "carga hecha con toda la fuerza es capaz"
	.dexText "de demoler hasta un camión de basura."
	.dexText "Y, a continuación, comérselo."
	.dexText ""
	.dexText ""

	.align 2, 0
dexEntryEu71:: @ 071 LAIRON
	.2byte 0, 7, 1
	.2byte 10, 2, 1, 1, 10, 10, 0, 9  @ height
	.2byte 10, 2, 6, 4, 6, 10, 1, 2, 0, 0  @ weight
	.dexLang EN
	.dexName "LAIRON"
	.dexLang FR
	.dexName "GALEGON"
	.dexLang DE
	.dexName "STOLLRAK"
	.dexLang EN
	.dexCategory "IRON ARMOR"
	.dexLang FR
	.dexCategoryLeftAligned "ARMURFER"
	.dexLang DE
	.dexCategoryLeftAligned "EISENPANZER"
	.dexLang IT
	.dexCategoryLeftAligned "CORAZZA"
	.dexLang ES
	.dexCategoryLeftAligned "COR{39E6}FÉRREA"
	.dexLang EN
	.dexText "LAIRON feeds on iron contained in"
	.dexText "rocks and water. It makes its nest on"
	.dexText "mountains where iron ore is buried."
	.dexText "As a result, the POKéMON often clashes"
	.dexText "with humans mining the iron ore."
	.dexText ""
	.dexLang FR
	.dexText "GALEGON se nourrit du fer contenu"
	.dexText "dans les rochers et dans l`eau. Il fait"
	.dexText "son nid sur les montagnes renfermant"
	.dexText "du minerai de fer. Du coup, il se"
	.dexText "confronte souvent aux humains"
	.dexText "travaillant dans les mines."
	.dexLang DE
	.dexText "STOLLRAK ernährt sich von Eisen, das in"
	.dexText "Steinen und Wasser enthalten ist. Es"
	.dexText "baut sein Nest in Bergen, in denen"
	.dexText "Eisenerz abgebaut wird. Es gerät dabei"
	.dexText "häufig mit Bergarbeitern in Konflikt."
	.dexText ""
	.dexLang IT
	.dexText "LAIRON si nutre del ferro contenuto"
	.dexText "nelle rocce e nell`acqua. Crea la propria"
	.dexText "dimora in montagna vicino a giacimenti"
	.dexText "ferrosi. Per questo motivo il POKéMON"
	.dexText "si scontra spesso con minatori alla"
	.dexText "ricerca di pepite di ferro."
	.dexLang ES
	.dexText "LAIRON se alimenta del hierro que hay en"
	.dexText "las rocas y el agua. Hace su nido en las"
	.dexText "montañas, de donde se saca el hierro."
	.dexText "Por eso, se encuentra muchas veces"
	.dexText "con las personas que están trabajando"
	.dexText "en las minas extrayéndolo."

	.align 2, 0
dexEntryEu72:: @ 072 AGGRON
	.2byte 0, 7, 2
	.2byte 10, 6, 1, 1, 10, 10, 2, 1  @ height
	.2byte 10, 7, 9, 3, 7, 10, 3, 6, 0, 0  @ weight
	.dexLang EN
	.dexName "AGGRON"
	.dexLang FR
	.dexName "GALEKING"
	.dexLang DE
	.dexName "STOLLOSS"
	.dexLang EN
	.dexCategory "IRON ARMOR"
	.dexLang FR
	.dexCategoryLeftAligned "ARMURFER"
	.dexLang DE
	.dexCategoryLeftAligned "EISENPANZER"
	.dexLang IT
	.dexCategoryLeftAligned "CORAZZA"
	.dexLang ES
	.dexCategoryLeftAligned "COR{39E6}FÉRREA"
	.dexLang EN
	.dexText "AGGRON is surprisingly protective"
	.dexText "of its environment. If its mountain"
	.dexText "is ravaged by a landslide or a fire, this"
	.dexText "POKéMON will haul topsoil to the area,"
	.dexText "plant trees, and beautifully restore its"
	.dexText "own territory."
	.dexLang FR
	.dexText "GALEKING est étonnamment"
	.dexText "attentif à son environnement."
	.dexText "Si sa montagne est ravagée par un"
	.dexText "glissement de terrain ou un incendie,"
	.dexText "ce POKéMON laboure la terre, plante"
	.dexText "des arbres et restaure le paysage."
	.dexLang DE
	.dexText "STOLLOSS geht erstaunlicherweise sehr"
	.dexText "behutsam mit der Umwelt um. Wenn sein"
	.dexText "Berg von einem Erdrutsch oder einem"
	.dexText "Feuer verwüstet wurde, schleppt es"
	.dexText "Erde in das Gebiet, pflanzt Bäume an und"
	.dexText "richtet sein Territorium wieder her."
	.dexLang IT
	.dexText "AGGRON difende strenuamente il"
	.dexText "proprio territorio. In caso di frana o"
	.dexText "incendio, questo POKéMON é in grado"
	.dexText "di risistemare il terreno, ripiantare"
	.dexText "gli alberi e ristabilire al meglio"
	.dexText "il proprio ambiente naturale."
	.dexLang ES
	.dexText "AGGRON es increíblemente cuidadoso con"
	.dexText "su hábitat. Si su montaña sufre algún"
	.dexText "corrimiento de tierras o algún incendio,"
	.dexText "cargará con tierra nueva, plantará"
	.dexText "árboles y restaurará con cuidado"
	.dexText "el terreno."

	.align 2, 0
dexEntryEu73:: @ 073 MACHOP
	.2byte 0, 7, 3
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 4, 3, 0, 10, 10, 1, 9, 5  @ weight
	.dexLang EN
	.dexName "MACHOP"
	.dexLang FR
	.dexName "MACHOC"
	.dexLang DE
	.dexName "MACHOLLO"
	.dexLang EN
	.dexCategory "SUPERPOWER"
	.dexLang FR
	.dexCategoryLeftAligned "COLOSSE"
	.dexLang DE
	.dexCategoryLeftAligned "KRAFTPROTZ"
	.dexLang IT
	.dexCategoryLeftAligned "MEGAFORZA"
	.dexLang ES
	.dexCategoryLeftAligned "SUPERPODER"
	.dexLang EN
	.dexText "MACHOP`s muscles are special - they"
	.dexText "never get sore no matter how much they"
	.dexText "are used in exercise."
	.dexText "This POKéMON has sufficient power to"
	.dexText "hurl a hundred adult humans."
	.dexText ""
	.dexLang FR
	.dexText "Les muscles de MACHOC sont spéciaux."
	.dexText "Quels que soient les efforts qu`il"
	.dexText "produit, il n`a jamais de courbature."
	.dexText "Ce POKéMON est assez puissant pour"
	.dexText "lancer une centaine d`hommes adultes."
	.dexText ""
	.dexLang DE
	.dexText "MACHOLLOs Muskeln sind etwas Beson-"
	.dexText "deres. Sie schmerzen nie, egal, wie sehr"
	.dexText "sie beansprucht werden."
	.dexText "Dieses POKéMON hat genug Kraft, um 100"
	.dexText "Erwachsene umherzuwerfen."
	.dexText ""
	.dexLang IT
	.dexText "I particolari muscoli di MACHOP non"
	.dexText "si infiammano mai, nemmeno in caso"
	.dexText "di esercizio eccessivo."
	.dexText "Questo POKéMON ha forza"
	.dexText "sufficiente per scagliare lontano"
	.dexText "un centinaio di uomini."
	.dexLang ES
	.dexText "MACHOP tiene una musculatura"
	.dexText "especial que nunca se agota"
	.dexText "por mucho que la use."
	.dexText "Este POKéMON es tan fuerte que"
	.dexText "puede derrotar a cien personas"
	.dexText "adultas de una sola vez."

	.align 2, 0
dexEntryEu74:: @ 074 MACHOKE
	.2byte 0, 7, 4
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 1, 5, 5, 4, 10, 10, 7, 0, 5  @ weight
	.dexLang EN
	.dexName "MACHOKE"
	.dexLang FR
	.dexName "MACHOPEUR"
	.dexLang DE
	.dexName "MASCHOCK"
	.dexLang EN
	.dexCategory "SUPERPOWER"
	.dexLang FR
	.dexCategoryLeftAligned "COLOSSE"
	.dexLang DE
	.dexCategoryLeftAligned "KRAFTPROTZ"
	.dexLang IT
	.dexCategoryLeftAligned "MEGAFORZA"
	.dexLang ES
	.dexCategoryLeftAligned "SUPERPODER"
	.dexLang EN
	.dexText "MACHOKE`s thoroughly toned muscles"
	.dexText "possess the hardness of steel."
	.dexText "This POKéMON has so much strength,"
	.dexText "it can easily hold aloft a sumo wrestler"
	.dexText "on just one finger."
	.dexText ""
	.dexLang FR
	.dexText "Les muscles toniques de MACHOPEUR"
	.dexText "sont durs comme de l`acier."
	.dexText "Ce POKéMON est si fort qu`il"
	.dexText "peut facilement soulever un sumo"
	.dexText "avec un seul doigt."
	.dexText ""
	.dexLang DE
	.dexText "MASCHOCKs starke Muskeln sind so hart"
	.dexText "wie Stahl. Dieses POKéMON hat so viel"
	.dexText "Kraft, dass es mit nur einem Finger"
	.dexText "einen Sumo-Ringer in der Luft halten"
	.dexText "kann."
	.dexText ""
	.dexLang IT
	.dexText "I muscoli perfettamente tonici di"
	.dexText "MACHOKE possiedono la durezza"
	.dexText "dell`acciaio. Questo POKéMON è"
	.dexText "così forte, da riuscire a sollevare"
	.dexText "un lottatore di sumo con un dito."
	.dexText ""
	.dexLang ES
	.dexText "Los entrenados músculos de MACHOKE"
	.dexText "son tan fuertes como el acero. Este"
	.dexText "POKéMON es tan fuerte que puede"
	.dexText "levantar con un solo dedo a un luchador"
	.dexText "de sumo."
	.dexText ""

	.align 2, 0
dexEntryEu75:: @ 075 MACHAMP
	.2byte 0, 7, 5
	.2byte 10, 5, 0, 3, 10, 10, 1, 6  @ height
	.2byte 10, 2, 8, 6, 6, 10, 1, 3, 0, 0  @ weight
	.dexLang EN
	.dexName "MACHAMP"
	.dexLang FR
	.dexName "MACKOGNEUR"
	.dexLang DE
	.dexName "MACHOMEI"
	.dexLang EN
	.dexCategory "SUPERPOWER"
	.dexLang FR
	.dexCategoryLeftAligned "COLOSSE"
	.dexLang DE
	.dexCategoryLeftAligned "KRAFTPROTZ"
	.dexLang IT
	.dexCategoryLeftAligned "MEGAFORZA"
	.dexLang ES
	.dexCategoryLeftAligned "SUPERPODER"
	.dexLang EN
	.dexText "MACHAMP has the power to hurl anything"
	.dexText "aside. However, trying to do any work"
	.dexText "requiring care and dexterity causes"
	.dexText "its arms to get tangled."
	.dexText "This POKéMON tends to leap into action"
	.dexText "before it thinks."
	.dexLang FR
	.dexText "MACKOGNEUR est capable de déplacer"
	.dexText "n`importe quelle masse. Cependant, ses"
	.dexText "bras s`emmêlent dès qu`il essaye de"
	.dexText "réaliser un travail délicat ou minutieux."
	.dexText "Ce POKéMON a tendance à cogner"
	.dexText "d`abord et à réfléchir ensuite."
	.dexLang DE
	.dexText "MACHOMEI hat genug Kraft, um alles"
	.dexText "Mögliche zu stemmen. Bei Tätigkeiten,"
	.dexText "die Geschick und Sorgfalt erfordern,"
	.dexText "machen es ihm seine Arme jedoch nicht"
	.dexText "leicht. Dieses POKéMON neigt dazu,"
	.dexText "zuerst zu handeln und dann zu denken."
	.dexLang IT
	.dexText "MACHAMP è dotato di una forza tale da"
	.dexText "riuscire a scagliare lontano ogni cosa."
	.dexText "Le sue braccia sono troppo possenti"
	.dexText "per riuscire a eseguire qualsiasi lavoro"
	.dexText "che richieda attenzione e destrezza."
	.dexText "Tende ad agire prima di pensare."
	.dexLang ES
	.dexText "MACHAMP es tan fuerte que puede"
	.dexText "derribar lo que quiera. Sin embargo,"
	.dexText "cuando tiene que realizar una tarea"
	.dexText "que requiere delicadeza y destreza, se"
	.dexText "le enredan los brazos. Este POKéMON"
	.dexText "pasa a la acción sin pensar."

	.align 2, 0
dexEntryEu76:: @ 076 MEDITITE
	.2byte 0, 7, 6
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 2, 4, 7, 10, 10, 1, 1, 2  @ weight
	.dexLang EN
	.dexName "MEDITITE"
	.dexLang FR
	.dexName "MEDITIKKA"
	.dexLang DE
	.dexName "MEDITIE"
	.dexLang EN
	.dexCategory "MEDITATE"
	.dexLang FR
	.dexCategoryLeftAligned "MEDITATION"
	.dexLang DE
	.dexCategoryLeftAligned "MEDITATION"
	.dexLang IT
	.dexCategoryLeftAligned "MEDITAZIONE"
	.dexLang ES
	.dexCategoryLeftAligned "MEDITADOR"
	.dexLang EN
	.dexText "MEDITITE heightens its inner energy"
	.dexText "through meditation. It survives on"
	.dexText "just one berry a day."
	.dexText "Minimal eating is another aspect of"
	.dexText "this POKéMON`s training."
	.dexText ""
	.dexLang FR
	.dexText "MEDITIKKA intensifie son énergie"
	.dexText "intérieure grâce à la méditation. Il lui"
	.dexText "suffit d`une BAIE par jour pour"
	.dexText "survivre. La diète fait partie"
	.dexText "de l`entraînement de ce POKéMON."
	.dexText ""
	.dexLang DE
	.dexText "MEDITIE erhöht seine Energie durch"
	.dexText "Meditation. Es lebt von nur einer Beere"
	.dexText "am Tag. Diese absolut reduzierte"
	.dexText "Ernährung ist Bestandteil seines"
	.dexText "Trainings."
	.dexText ""
	.dexLang IT
	.dexText "MEDITITE incrementa la sua energia"
	.dexText "interiore grazie alla meditazione."
	.dexText "La sua alimentazione minima - si"
	.dexText "nutre di una bacca al giorno - è"
	.dexText "un`altra peculiarità dell`esercizio"
	.dexText "di questo POKéMON."
	.dexLang ES
	.dexText "MEDITITE aumenta su energía interior"
	.dexText "mediante meditación. Para subsistir"
	.dexText "le basta con una BAYA al día."
	.dexText "El comer poco entra dentro de su"
	.dexText "entrenamiento."
	.dexText ""

	.align 2, 0
dexEntryEu77:: @ 077 MEDICHAM
	.2byte 0, 7, 7
	.2byte 10, 4, 0, 3, 10, 10, 1, 3  @ height
	.2byte 10, 10, 6, 9, 4, 10, 10, 3, 1, 5  @ weight
	.dexLang EN
	.dexName "MEDICHAM"
	.dexLang FR
	.dexName "CHARMINA"
	.dexLang DE
	.dexName "MEDITALIS"
	.dexLang EN
	.dexCategory "MEDITATE"
	.dexLang FR
	.dexCategoryLeftAligned "MEDITATION"
	.dexLang DE
	.dexCategoryLeftAligned "MEDITATION"
	.dexLang IT
	.dexCategoryLeftAligned "MEDITAZIONE"
	.dexLang ES
	.dexCategoryLeftAligned "MEDITADOR"
	.dexLang EN
	.dexText "Through the power of meditation,"
	.dexText "MEDICHAM developed its sixth sense."
	.dexText "It gained the ability to use"
	.dexText "psychokinetic powers. This POKéMON is"
	.dexText "known to meditate for a whole month"
	.dexText "without eating."
	.dexLang FR
	.dexText "Grâce au pouvoir de la méditation,"
	.dexText "CHARMINA a développé son sixième"
	.dexText "sens. Il peut utiliser des pouvoirs"
	.dexText "télékinésiques. On sait que ce POKéMON"
	.dexText "peut méditer pendant un mois sans"
	.dexText "manger."
	.dexLang DE
	.dexText "Mittels Meditation hat MEDITALIS"
	.dexText "seinen sechsten Sinn entwickelt. So"
	.dexText "kann es seine psychokinetischen"
	.dexText "Kräfte nutzen. Dieses POKéMON"
	.dexText "meditiert einen ganzen Monat ohne"
	.dexText "etwas zu essen."
	.dexLang IT
	.dexText "Grazie alla propria abilità meditativa"
	.dexText "MEDICHAM ha sviluppato il sesto senso."
	.dexText "Ha acquisito anche la capacità di usare"
	.dexText "i poteri psicocinetici. È noto per"
	.dexText "rimanere fermo in meditazione"
	.dexText "un mese intero senza mangiare."
	.dexLang ES
	.dexText "A través de la meditación, MEDICHAM"
	.dexText "desarrolló su sexto sentido y aprendió"
	.dexText "a usar poderes psicoquinéticos."
	.dexText "Se sabe que este POKéMON puede"
	.dexText "pasarse un mes meditando y sin comer."
	.dexText ""

	.align 2, 0
dexEntryEu78:: @ 078 ELECTRIKE
	.2byte 0, 7, 8
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 3, 3, 5, 10, 10, 1, 5, 2  @ weight
	.dexLang EN
	.dexName "ELECTRIKE"
	.dexLang FR
	.dexName "DYNAVOLT"
	.dexLang DE
	.dexName "FRIZELBLIZ"
	.dexLang EN
	.dexCategory "LIGHTNING"
	.dexLang FR
	.dexCategoryLeftAligned "ORAGE"
	.dexLang DE
	.dexCategoryLeftAligned "GEWITTER"
	.dexLang IT
	.dexCategoryLeftAligned "LAMPO"
	.dexLang ES
	.dexCategoryLeftAligned "CALAMBRE"
	.dexLang EN
	.dexText "ELECTRIKE stores electricity in its"
	.dexText "long body hair. This POKéMON stimulates"
	.dexText "its leg muscles with electric charges."
	.dexText "These jolts of power give its legs"
	.dexText "explosive acceleration performance."
	.dexText ""
	.dexLang FR
	.dexText "DYNAVOLT stocke de l`électricité dans"
	.dexText "les poils de son corps allongé. Ce"
	.dexText "POKéMON stimule les muscles de ses"
	.dexText "jambes avec des charges électriques, ce"
	.dexText "qui le rend capable d`accélérations"
	.dexText "fulgurantes."
	.dexLang DE
	.dexText "FRIZELBLIZ speichert Elektrizität in"
	.dexText "seiner langen Körperbehaarung. Dieses"
	.dexText "POKéMON stimuliert seine"
	.dexText "Beinmuskulatur durch Stromstöße."
	.dexText "Dadurch ist es in der Lage, explosiv"
	.dexText "zu beschleunigen."
	.dexLang IT
	.dexText "ELECTRIKE accumula l`elettricità nella"
	.dexText "sua folta pelliccia. Stimola i muscoli"
	.dexText "degli arti inferiori con cariche"
	.dexText "elettriche, grazie alle quali ottiene"
	.dexText "prestazioni e accelerazioni esplosive."
	.dexText ""
	.dexLang ES
	.dexText "ELECTRIKE acumula electricidad en el"
	.dexText "largo pelaje que tiene. Este POKéMON"
	.dexText "estimula los músculos de las patas"
	.dexText "mediante descargas eléctricas."
	.dexText "Estas explosiones de energía le"
	.dexText "permiten acelerar de forma increíble."

	.align 2, 0
dexEntryEu79:: @ 079 MANECTRIC
	.2byte 0, 7, 9
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 10, 8, 8, 6, 10, 10, 4, 0, 2  @ weight
	.dexLang EN
	.dexName "MANECTRIC"
	.dexLang FR
	.dexName "ELECSPRINT"
	.dexLang DE
	.dexName "VOLTENSO"
	.dexLang EN
	.dexCategory "DISCHARGE"
	.dexLang FR
	.dexCategoryLeftAligned "DECHARGE"
	.dexLang DE
	.dexCategoryLeftAligned "ENTLADUNG"
	.dexLang IT
	.dexCategoryLeftAligned "SCOSSA"
	.dexLang ES
	.dexCategoryLeftAligned "DESCARGA"
	.dexLang EN
	.dexText "MANECTRIC is constantly discharging"
	.dexText "electricity from its mane. The sparks"
	.dexText "sometimes ignite forest fires."
	.dexText "When it enters a battle, this POKéMON"
	.dexText "creates thunderclouds."
	.dexText ""
	.dexLang FR
	.dexText "La crinière d`ELECSPRINT libère"
	.dexText "constamment de l`électricité. Les"
	.dexText "étincelles déclenchent parfois des feux"
	.dexText "de forêt. Au début de ses combats, ce"
	.dexText "POKéMON crée des nuages orageux."
	.dexText ""
	.dexLang DE
	.dexText "VOLTENSO entlädt ständig Elektrizität"
	.dexText "aus seiner Mähne. Es fliegen dabei"
	.dexText "Funken, die zuweilen zu Waldbränden"
	.dexText "führen. In einem Kampf erzeugt dieses"
	.dexText "POKéMON Gewitterwolken."
	.dexText ""
	.dexLang IT
	.dexText "MANECTRIC scarica costantemente"
	.dexText "l`elettricità dalla propria criniera."
	.dexText "Spesso le scintille scatenano incendi"
	.dexText "nei boschi. In lotta questo POKéMON"
	.dexText "crea nubi temporalesche."
	.dexText ""
	.dexLang ES
	.dexText "MANECTRIC está continuamente"
	.dexText "descargando electricidad por las"
	.dexText "melenas, y a veces causa incendios"
	.dexText "en el bosque con las chispas que suelta."
	.dexText "Cuando entra en combate, este POKéMON"
	.dexText "crea nubarrones."

	.align 2, 0
dexEntryEu80:: @ 080 PLUSLE
	.2byte 0, 8, 0
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 10, 9, 3, 10, 10, 10, 4, 2  @ weight
	.dexLang EN
	.dexName "PLUSLE"
	.dexLang FR
	.dexName "POSIPI"
	.dexLang DE
	.dexName "PLUSLE"
	.dexLang EN
	.dexCategory "CHEERING"
	.dexLang FR
	.dexCategoryLeftAligned "ACCLAMEUR"
	.dexLang DE
	.dexCategoryLeftAligned "JUBEL"
	.dexLang IT
	.dexCategoryLeftAligned "INCITAMENTO"
	.dexLang ES
	.dexCategoryLeftAligned "ÁNIMO"
	.dexLang EN
	.dexText "PLUSLE always acts as a cheerleader"
	.dexText "for its partners. Whenever a teammate"
	.dexText "puts out a good effort in battle, this"
	.dexText "POKéMON shorts out its body to create"
	.dexText "the crackling noises of sparks to show"
	.dexText "its joy."
	.dexLang FR
	.dexText "POSIPI sert de supporter à ses"
	.dexText "partenaires. Chaque fois qu`un membre"
	.dexText "de son équipe fait une belle action dans"
	.dexText "un combat, ce POKéMON court-circuite"
	.dexText "son corps et libère des étincelles"
	.dexText "pour montrer sa joie."
	.dexLang DE
	.dexText "PLUSLE dient seinen Artgenossen als"
	.dexText "Cheerleader. Wenn ein Teamkamerad"
	.dexText "im Kampf erfolgreich ist, erzeugt es"
	.dexText "das prasselnde Geräusch von Funken, um"
	.dexText "so seine Freude zu zeigen."
	.dexText ""
	.dexLang IT
	.dexText "PLUSLE agisce sempre da mascotte"
	.dexText "del gruppo. Ogni volta che un suo"
	.dexText "compagno ottiene buoni risultati in"
	.dexText "lotta, PLUSLE crea un cortocircuito"
	.dexText "per provocare l`allegro scoppiettio"
	.dexText "delle scintille e dimostrare la sua gioia."
	.dexLang ES
	.dexText "PLUSLE siempre hace las veces de líder"
	.dexText "con sus compañeros. Cuando algún"
	.dexText "miembro de su grupo hace un gran"
	.dexText "esfuerzo en combate, causa un"
	.dexText "cortocircuito en su interior para"
	.dexText "mostrar con el chisporroteo su alegría."

	.align 2, 0
dexEntryEu81:: @ 081 MINUN
	.2byte 0, 8, 1
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 10, 9, 3, 10, 10, 10, 4, 2  @ weight
	.dexLang EN
	.dexName "MINUN"
	.dexLang FR
	.dexName "NEGAPI"
	.dexLang DE
	.dexName "MINUN"
	.dexLang EN
	.dexCategory "CHEERING"
	.dexLang FR
	.dexCategoryLeftAligned "ACCLAMEUR"
	.dexLang DE
	.dexCategoryLeftAligned "JUBEL"
	.dexLang IT
	.dexCategoryLeftAligned "INCITAMENTO"
	.dexLang ES
	.dexCategoryLeftAligned "ÁNIMO"
	.dexLang EN
	.dexText "MINUN is more concerned about cheering"
	.dexText "on its partners than its own safety."
	.dexText "It shorts out the electricity in its"
	.dexText "body to create brilliant showers of"
	.dexText "sparks to cheer on its teammates."
	.dexText ""
	.dexLang FR
	.dexText "NEGAPI n`hésite pas à se mettre en"
	.dexText "danger pour soutenir ses partenaires."
	.dexText "Il court-circuite son corps pour faire"
	.dexText "jaillir des gerbes d`étincelles et donner"
	.dexText "du cœur à l`ouvrage à ses équipiers."
	.dexText ""
	.dexLang DE
	.dexText "MINUN kümmert sich mehr um das"
	.dexText "Anfeuern seiner Partner als um seine"
	.dexText "eigene Sicherheit. Es nutzt die"
	.dexText "Elektrizität in seinem Körper dazu,"
	.dexText "einen Funkenregen zu erzeugen und"
	.dexText "seine Teamkameraden anzufeuern."
	.dexLang IT
	.dexText "MINUN si impegna a tenere alto il morale"
	.dexText "dei suoi compagni di squadra, anche a"
	.dexText "rischio della sua stessa sicurezza."
	.dexText "Crea vivaci cortocircuiti con"
	.dexText "la sua elettricità fisica per"
	.dexText "rallegrare tutta la squadra."
	.dexLang ES
	.dexText "MINUN está más preocupado de animar"
	.dexText "a sus compañeros de equipo"
	.dexText "que de su propia seguridad."
	.dexText "Para animar a los miembros de su grupo,"
	.dexText "crea un cortocircuito en su interior"
	.dexText "y libera un chisporroteo espectacular."

	.align 2, 0
dexEntryEu82:: @ 082 MAGNEMITE
	.2byte 0, 8, 2
	.2byte 10, 1, 0, 0, 10, 10, 0, 3  @ height
	.2byte 10, 10, 1, 3, 2, 10, 10, 10, 6, 0  @ weight
	.dexLang EN
	.dexName "MAGNEMITE"
	.dexLang FR
	.dexName "MAGNETI"
	.dexLang DE
	.dexName "MAGNETILO"
	.dexLang EN
	.dexCategory "MAGNET"
	.dexLang FR
	.dexCategoryLeftAligned "MAGNETIQUE"
	.dexLang DE
	.dexCategoryLeftAligned "MAGNET"
	.dexLang IT
	.dexCategoryLeftAligned "CALAMITA"
	.dexLang ES
	.dexCategoryLeftAligned "IMÁN"
	.dexLang EN
	.dexText "MAGNEMITE floats in the air by emitting"
	.dexText "electromagnetic waves from the units"
	.dexText "at its sides. These waves block gravity."
	.dexText "This POKéMON becomes incapable of"
	.dexText "flight if its internal electrical supply"
	.dexText "is depleted."
	.dexLang FR
	.dexText "MAGNETI flotte dans les airs en"
	.dexText "émettant des ondes électromagnétiques"
	.dexText "par les aimants sur ses côtés. Ces"
	.dexText "ondes annulent les effets de la gravité."
	.dexText "Ce POKéMON ne peut plus voler"
	.dexText "si son stock d`électricité est épuisé."
	.dexLang DE
	.dexText "MAGNETILO segelt durch die Luft und"
	.dexText "sendet dabei elektromagnetische Wellen"
	.dexText "an beiden Seiten seines Körpers aus."
	.dexText "Dieses POKéMON wird flugunfähig, wenn"
	.dexText "die Stromquelle in seinem Inneren"
	.dexText "erschöpft ist."
	.dexLang IT
	.dexText "MAGNEMITE fluttua a mezz`aria emanando"
	.dexText "onde elettromagnetiche dai suoi"
	.dexText "elementi laterali. Queste onde bloccano"
	.dexText "la forza di gravità. Il POKéMON non"
	.dexText "riesce a rimanere sospeso dopo aver"
	.dexText "esaurito la carica elettrica."
	.dexLang ES
	.dexText "MAGNEMITE flota en el aire emitiendo"
	.dexText "ondas electromagnéticas a través"
	.dexText "de las unidades de las extremidades,"
	.dexText "que bloquean la gravedad. Si se agota"
	.dexText "su suministro de electricidad interno,"
	.dexText "es incapaz de mantenerse flotando."

	.align 2, 0
dexEntryEu83:: @ 083 MAGNETON
	.2byte 0, 8, 3
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 1, 3, 2, 3, 10, 10, 6, 0, 0  @ weight
	.dexLang EN
	.dexName "MAGNETON"
	.dexLang FR
	.dexName "MAGNETON"
	.dexLang DE
	.dexName "MAGNETON"
	.dexLang EN
	.dexCategory "MAGNET"
	.dexLang FR
	.dexCategoryLeftAligned "MAGNETIQUE"
	.dexLang DE
	.dexCategoryLeftAligned "MAGNET"
	.dexLang IT
	.dexCategoryLeftAligned "CALAMITA"
	.dexLang ES
	.dexCategoryLeftAligned "IMÁN"
	.dexLang EN
	.dexText "MAGNETON emits a powerful magnetic"
	.dexText "force that is fatal to electronics and"
	.dexText "precision instruments. Because of"
	.dexText "this, it is said that some towns warn"
	.dexText "people to keep this POKéMON inside"
	.dexText "a POKé BALL."
	.dexLang FR
	.dexText "MAGNETON émet un puissant champ"
	.dexText "magnétique qui neutralise les appareils"
	.dexText "électroniques. Certaines villes"
	.dexText "demandent aux propriétaires de ces"
	.dexText "POKéMON de les garder dans leurs"
	.dexText "POKé BALLS."
	.dexLang DE
	.dexText "MAGNETON strahlt eine starke magne-"
	.dexText "tische Energie ab, die für elektronische"
	.dexText "Geräte und Präzisionsinstrumente sehr"
	.dexText "schädlich ist. In einigen Städten"
	.dexText "werden die Bewohner gebeten, dieses"
	.dexText "POKéMON in einem POKéBALL zu halten."
	.dexLang IT
	.dexText "MAGNETON emette una potente"
	.dexText "carica magnetica fatale per gli"
	.dexText "strumenti elettronici e di precisione."
	.dexText "Per questo motivo molte città"
	.dexText "impongono ai cittadini di tenere"
	.dexText "questi POKéMON nelle POKé BALL."
	.dexLang ES
	.dexText "MAGNETON emite una fuerte energía"
	.dexText "magnética, fatal para los instrumentos"
	.dexText "electrónicos y de precisión."
	.dexText "Éste es el motivo por el que, dicen,"
	.dexText "mucha gente mantiene a este POKéMON"
	.dexText "en POKé BALL."

	.align 2, 0
dexEntryEu84:: @ 084 VOLTORB
	.2byte 0, 8, 4
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 2, 2, 9, 10, 10, 1, 0, 4  @ weight
	.dexLang EN
	.dexName "VOLTORB"
	.dexLang FR
	.dexName "VOLTORBE"
	.dexLang DE
	.dexName "VOLTOBAL"
	.dexLang EN
	.dexCategory "BALL"
	.dexLang FR
	.dexCategoryLeftAligned "BALLE"
	.dexLang DE
	.dexCategoryLeftAligned "BALL"
	.dexLang IT
	.dexCategoryLeftAligned "BALL"
	.dexLang ES
	.dexCategoryLeftAligned "BOLA"
	.dexLang EN
	.dexText "VOLTORB was first sighted at a company"
	.dexText "that manufactures POKé BALLS."
	.dexText "The link between that sighting and"
	.dexText "the fact that this POKéMON looks very"
	.dexText "similar to a POKé BALL remains a"
	.dexText "mystery."
	.dexLang FR
	.dexText "La première fois qu`on a vu VOLTORBE,"
	.dexText "c`était dans une usine qui fabrique"
	.dexText "des POKé BALLS. Personne n`a"
	.dexText "jamais pu expliquer le lien entre cet"
	.dexText "événement et la ressemblance frappante"
	.dexText "de ce POKéMON avec une POKé BALL."
	.dexLang DE
	.dexText "VOLTOBAL wurde zuerst bei einer Firma"
	.dexText "beobachtet, die POKéBäLLE herstellt."
	.dexText "Der Zusammenhang zwischen dieser"
	.dexText "Beobachtung und der Tatsache, dass"
	.dexText "dieses POKéMON wie ein POKéBALL"
	.dexText "aussieht, ist noch ungeklärt."
	.dexLang IT
	.dexText "VOLTORB è stato avvistato per la"
	.dexText "prima volta in un`azienda produttrice"
	.dexText "di POKé BALL."
	.dexText "Il nesso tra la sua presenza in questa"
	.dexText "fabbrica e l`estrema somiglianza ad"
	.dexText "una POKé BALL rimane un mistero."
	.dexLang ES
	.dexText "VOLTORB fue visto por primera vez en"
	.dexText "una empresa encargada de comercializar"
	.dexText "POKé BALLS. La conexión que existe"
	.dexText "entre aquella primera vez que se le vio"
	.dexText "y el hecho de que se parece mucho a una"
	.dexText "POKé BALL sigue siendo un misterio."

	.align 2, 0
dexEntryEu85:: @ 085 ELECTRODE
	.2byte 0, 8, 5
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 1, 4, 6, 8, 10, 10, 6, 6, 6  @ weight
	.dexLang EN
	.dexName "ELECTRODE"
	.dexLang FR
	.dexName "ELECTRODE"
	.dexLang DE
	.dexName "LEKTROBAL"
	.dexLang EN
	.dexCategory "BALL"
	.dexLang FR
	.dexCategoryLeftAligned "BALLE"
	.dexLang DE
	.dexCategoryLeftAligned "BALL"
	.dexLang IT
	.dexCategoryLeftAligned "BALL"
	.dexLang ES
	.dexCategoryLeftAligned "BOLA"
	.dexLang EN
	.dexText "ELECTRODE eats electricity in the"
	.dexText "atmosphere. On days when lightning"
	.dexText "strikes, you can see this POKéMON"
	.dexText "exploding all over the place from"
	.dexText "eating too much electricity."
	.dexText ""
	.dexLang FR
	.dexText "ELECTRODE mange l`électricité qui se"
	.dexText "trouve dans l`atmosphère. Les jours"
	.dexText "d`orage, on peut voir ce POKéMON"
	.dexText "exploser sans arrêt parce qu`il a"
	.dexText "avalé trop d`électricité."
	.dexText ""
	.dexLang DE
	.dexText "LEKTROBAL ernährt sich von"
	.dexText "Elektrizität aus der Atmosphäre. An"
	.dexText "Tagen, an denen es blitzt, explodiert"
	.dexText "dieses POKéMON dauernd, da es zu viel"
	.dexText "Elektrizität zu sich nimmt."
	.dexText ""
	.dexLang IT
	.dexText "ELECTRODE si nutre dell`elettricità"
	.dexText "presente nell`atmosfera. Quando i"
	.dexText "fulmini solcano il cielo, è possibile"
	.dexText "scorgere molti di questi POKéMON"
	.dexText "esplodere per aver ingerito"
	.dexText "un`eccessiva dose di elettricità."
	.dexLang ES
	.dexText "Los ELECTRODE se alimentan de la"
	.dexText "electricidad de la atmósfera. En días"
	.dexText "de tormenta con rayos, es fácil verlos"
	.dexText "explotando por todos lados tras haber"
	.dexText "consumido demasiada electricidad."
	.dexText ""

	.align 2, 0
dexEntryEu86:: @ 086 VOLBEAT
	.2byte 0, 8, 6
	.2byte 10, 2, 0, 4, 10, 10, 0, 7  @ height
	.2byte 10, 10, 3, 9, 0, 10, 10, 1, 7, 7  @ weight
	.dexLang EN
	.dexName "VOLBEAT"
	.dexLang FR
	.dexName "MUCIOLE"
	.dexLang DE
	.dexName "VOLBEAT"
	.dexLang EN
	.dexCategory "FIREFLY"
	.dexLang FR
	.dexCategoryLeftAligned "LUCIOLE"
	.dexLang DE
	.dexCategoryLeftAligned "LIBELLE"
	.dexLang IT
	.dexCategoryLeftAligned "LUCCIOLA"
	.dexLang ES
	.dexCategoryLeftAligned "LUCIÉRNAGA"
	.dexLang EN
	.dexText "VOLBEAT`s tail glows like a lightbulb."
	.dexText "With other VOLBEAT, it uses its tail to"
	.dexText "draw geometric shapes in the night sky."
	.dexText "This POKéMON loves the sweet aroma"
	.dexText "given off by ILLUMISE."
	.dexText ""
	.dexLang FR
	.dexText "La queue de MUCIOLE éclaire comme"
	.dexText "une ampoule. Ensemble, les MUCIOLE"
	.dexText "dessinent des figures géométriques"
	.dexText "dans la nuit étoilée. Ce POKéMON adore"
	.dexText "le parfum dégagé par LUMIVOLE."
	.dexText ""
	.dexLang DE
	.dexText "VOLBEATs Schweif leuchtet wie eine"
	.dexText "Glühbirne. Zusammen mit anderen"
	.dexText "VOLBEAT malt es mit seinem Schweif"
	.dexText "geometrische Figuren an den Nacht-"
	.dexText "himmel. Dieses POKéMON liebt den von"
	.dexText "ILLUMISE verströmten Duft."
	.dexLang IT
	.dexText "La coda di VOLBEAT si illumina come"
	.dexText "una lampadina. Assieme ai suoi simili"
	.dexText "usa la coda per tracciare figure"
	.dexText "geometriche nel cielo notturno."
	.dexText "Questo POKéMON ama il dolce"
	.dexText "aroma emanato da ILLUMISE."
	.dexLang ES
	.dexText "La cola de VOLBEAT brilla como una"
	.dexText "bombilla. Ante otro de su grupo, la usa"
	.dexText "para dibujar formas geométricas"
	.dexText "en la oscuridad del cielo por la noche."
	.dexText "Este POKéMON adora el dulce aroma"
	.dexText "que desprende ILLUMISE."

	.align 2, 0
dexEntryEu87:: @ 087 ILLUMISE
	.2byte 0, 8, 7
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 3, 9, 0, 10, 10, 1, 7, 7  @ weight
	.dexLang EN
	.dexName "ILLUMISE"
	.dexLang FR
	.dexName "LUMIVOLE"
	.dexLang DE
	.dexName "ILLUMISE"
	.dexLang EN
	.dexCategory "FIREFLY"
	.dexLang FR
	.dexCategoryLeftAligned "LUCIOLE"
	.dexLang DE
	.dexCategoryLeftAligned "LIBELLE"
	.dexLang IT
	.dexCategoryLeftAligned "LUCCIOLA"
	.dexLang ES
	.dexCategoryLeftAligned "LUCIÉRNAGA"
	.dexLang EN
	.dexText "ILLUMISE attracts a swarm of VOLBEAT"
	.dexText "using a sweet fragrance. Once the"
	.dexText "VOLBEAT have gathered, this POKéMON"
	.dexText "leads the lit-up swarm in drawing"
	.dexText "geometric designs on the canvas of"
	.dexText "the night sky."
	.dexLang FR
	.dexText "LUMIVOLE peut attirer un essaim de"
	.dexText "MUCIOLE grâce à son doux parfum."
	.dexText "Une fois les MUCIOLE rassemblés, ce"
	.dexText "POKéMON dirige cette nuée lumineuse et"
	.dexText "lui fait dessiner des figures"
	.dexText "géométriques dans la nuit étoilée."
	.dexLang DE
	.dexText "ILLUMISE zieht ganze VOLBEAT-Scharen"
	.dexText "mit seinem süßlichen Duft an. Dann"
	.dexText "führt es diesen hell leuchtenden"
	.dexText "Schwarm an, indem es geometrische"
	.dexText "Figuren an den Nachthimmel malt."
	.dexText ""
	.dexLang IT
	.dexText "ILLUMISE attrae uno sciame di VOLBEAT"
	.dexText "con la sua fragranza dolce. Una volta"
	.dexText "radunato un gruppo di VOLBEAT,"
	.dexText "ILLUMISE dirige lo sciame luminoso,"
	.dexText "che disegna così figure geometriche"
	.dexText "nel setoso cielo notturno."
	.dexLang ES
	.dexText "ILLUMISE atrae mediante su dulce aroma"
	.dexText "a enjambres de VOLBEAT. Una vez los ha"
	.dexText "agrupado, les guía en el vuelo para que"
	.dexText "dibujen formas geométricas en el lienzo"
	.dexText "del oscuro cielo."
	.dexText ""

	.align 2, 0
dexEntryEu88:: @ 088 ODDISH
	.2byte 0, 8, 8
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 1, 1, 9, 10, 10, 10, 5, 4  @ weight
	.dexLang EN
	.dexName "ODDISH"
	.dexLang FR
	.dexName "MYSTHERBE"
	.dexLang DE
	.dexName "MYRAPLA"
	.dexLang EN
	.dexCategory "WEED"
	.dexLang FR
	.dexCategoryLeftAligned "RACINE"
	.dexLang DE
	.dexCategoryLeftAligned "UNKRAUT"
	.dexLang IT
	.dexCategoryLeftAligned "MALERBA"
	.dexLang ES
	.dexCategoryLeftAligned "HIERBAJO"
	.dexLang EN
	.dexText "ODDISH searches for fertile, nutrient-"
	.dexText "rich soil, then plants itself."
	.dexText "During the daytime, while it is planted,"
	.dexText "this POKéMON`s feet are thought to"
	.dexText "change shape and become similar to"
	.dexText "the roots of trees."
	.dexLang FR
	.dexText "MYSTHERBE cherche un sol fertile et"
	.dexText "riche en nutriments, pour s`y planter."
	.dexText "Pendant la journée, quand il est planté,"
	.dexText "les pieds de ce POKéMON changent de"
	.dexText "forme et deviennent similaires à"
	.dexText "des racines."
	.dexLang DE
	.dexText "MYRAPLA sucht nach fruchtbarem,"
	.dexText "nahrhaftem Boden und pflanzt sich"
	.dexText "selbst darin ein. Solange es"
	.dexText "eingepflanzt ist, nehmen seine Füße"
	.dexText "tagsüber die Gestalt von Baumwurzeln"
	.dexText "an."
	.dexLang IT
	.dexText "ODDISH cerca suolo fertile e ricco di"
	.dexText "sostanze nutritive per piantarvi le"
	.dexText "radici. Durante il giorno quando è fisso"
	.dexText "nel terreno, si dice che le sue zampe"
	.dexText "si trasformino prendendo la forma"
	.dexText "delle radici degli alberi."
	.dexLang ES
	.dexText "ODDISH busca los suelos fértiles"
	.dexText "y ricos en nutrientes para plantarse"
	.dexText "en la tierra. Durante el día,"
	.dexText "se cree que le cambia la forma de los"
	.dexText "pies y se le empiezan a parecer a las"
	.dexText "raíces de los árboles."

	.align 2, 0
dexEntryEu89:: @ 089 GLOOM
	.2byte 0, 8, 9
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 1, 9, 0, 10, 10, 10, 8, 6  @ weight
	.dexLang EN
	.dexName "GLOOM"
	.dexLang FR
	.dexName "ORTIDE"
	.dexLang DE
	.dexName "DUFLOR"
	.dexLang EN
	.dexCategory "WEED"
	.dexLang FR
	.dexCategoryLeftAligned "RACINE"
	.dexLang DE
	.dexCategoryLeftAligned "UNKRAUT"
	.dexLang IT
	.dexCategoryLeftAligned "MALERBA"
	.dexLang ES
	.dexCategoryLeftAligned "HIERBAJO"
	.dexLang EN
	.dexText "From its mouth GLOOM drips honey that"
	.dexText "smells absolutely horrible."
	.dexText "Apparently, it loves the horrid stench."
	.dexText "It sniffs the noxious fumes and then"
	.dexText "drools even more of its honey."
	.dexText ""
	.dexLang FR
	.dexText "ORTIDE bave un miel qui sent"
	.dexText "horriblement mauvais. Apparemment, il"
	.dexText "adore cette odeur nauséabonde."
	.dexText "Il en renifle les fumées toxiques et se"
	.dexText "met à baver du miel de plus belle."
	.dexText ""
	.dexLang DE
	.dexText "Aus DUFLORs Mund tropft übelst"
	.dexText "riechender Honig. Diesen Gestank"
	.dexText "scheint es zu lieben, denn es"
	.dexText "schnieft die giftigen Dämpfe ein und"
	.dexText "sabbert danach noch mehr Honig."
	.dexText ""
	.dexLang IT
	.dexText "Dalla bocca di GLOOM fuoriesce una"
	.dexText "resina maleodorante e disgustosa."
	.dexText "Evidentemente adora questo fetido"
	.dexText "olezzo, poiché lo annusa avidamente"
	.dexText "producendo poi altra resina."
	.dexText ""
	.dexLang ES
	.dexText "GLOOM babea una miel que tiene un olor"
	.dexText "realmente horrible, aunque parece ser"
	.dexText "que a él le gusta."
	.dexText "De hecho, aspira los gases nocivos"
	.dexText "y libera más miel aún."
	.dexText ""

	.align 2, 0
dexEntryEu90:: @ 090 VILEPLUME
	.2byte 0, 9, 0
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 10, 4, 1, 0, 10, 10, 1, 8, 6  @ weight
	.dexLang EN
	.dexName "VILEPLUME"
	.dexLang FR
	.dexName "RAFFLESIA"
	.dexLang DE
	.dexName "GIFLOR"
	.dexLang EN
	.dexCategory "FLOWER"
	.dexLang FR
	.dexCategoryLeftAligned "FLEUR"
	.dexLang DE
	.dexCategoryLeftAligned "BLUME"
	.dexLang IT
	.dexCategoryLeftAligned "FIORE"
	.dexLang ES
	.dexCategoryLeftAligned "FLOR"
	.dexLang EN
	.dexText "VILEPLUME has the world`s largest"
	.dexText "petals. They are used to attract prey"
	.dexText "that are then doused with toxic spores."
	.dexText "Once the prey are immobilized, this"
	.dexText "POKéMON catches and devours them."
	.dexText ""
	.dexLang FR
	.dexText "RAFFLESIA dispose des plus grands"
	.dexText "pétales du monde. Il s`en sert pour"
	.dexText "attirer ses proies avant de les endormir"
	.dexText "avec ses spores toxiques. Ce POKéMON"
	.dexText "n`a plus alors qu`à attraper sa"
	.dexText "proie et à la manger."
	.dexLang DE
	.dexText "GIFLOR hat die größten Blätter der Welt."
	.dexText "Sie ziehen Beute an und bestäuben sie"
	.dexText "mit giftigen Sporen. Wenn die Beute"
	.dexText "sich nicht mehr rührt, fängt dieses"
	.dexText "POKéMON sie und frisst sie auf."
	.dexText ""
	.dexLang IT
	.dexText "VILEPLUME ha i petali più grandi al"
	.dexText "mondo. Li usa per attirare la preda"
	.dexText "per poi ricoprirla di spore velenose."
	.dexText "Una volta immobilizzata la preda,"
	.dexText "il POKéMON la cattura e la divora."
	.dexText ""
	.dexLang ES
	.dexText "VILEPLUME tiene los mayores pétalos"
	.dexText "del mundo. Los usa para atraer a sus"
	.dexText "presas y llenarlas de esporas tóxicas."
	.dexText "Una vez ha inmovilizado a las víctimas,"
	.dexText "las atrapa y las devora."
	.dexText ""

	.align 2, 0
dexEntryEu91:: @ 091 BELLOSSOM
	.2byte 0, 9, 1
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 1, 2, 8, 10, 10, 10, 5, 8  @ weight
	.dexLang EN
	.dexName "BELLOSSOM"
	.dexLang FR
	.dexName "JOLIFLOR"
	.dexLang DE
	.dexName "BLUBELLA"
	.dexLang EN
	.dexCategory "FLOWER"
	.dexLang FR
	.dexCategoryLeftAligned "FLEUR"
	.dexLang DE
	.dexCategoryLeftAligned "BLUME"
	.dexLang IT
	.dexCategoryLeftAligned "FIORE"
	.dexLang ES
	.dexCategoryLeftAligned "FLOR"
	.dexLang EN
	.dexText "A BELLOSSOM grows flowers more"
	.dexText "beautifully if it has evolved from a"
	.dexText "smelly GLOOM - the stinkier the better."
	.dexText "At night, this POKéMON closes its"
	.dexText "petals and goes to sleep."
	.dexText ""
	.dexLang FR
	.dexText "Les fleurs de JOLIFLOR sont encore plus"
	.dexText "jolies s`il s`agit d`une évolution d`un"
	.dexText "ORTIDE qui sentait vraiment"
	.dexText "très mauvais. La nuit, ce POKéMON"
	.dexText "ferme ses pétales pour dormir."
	.dexText ""
	.dexLang DE
	.dexText "BLUBELLA wachsen schönere Blumen,"
	.dexText "wenn es sich aus einem übel riechenden"
	.dexText "DUFLOR entwickelt hat - je stinkender,"
	.dexText "desto besser. Nachts schließt dieses"
	.dexText "POKéMON seine Blätter und schläft."
	.dexText ""
	.dexLang IT
	.dexText "I fiori di BELLOSSOM sono tanto più"
	.dexText "belli se si è evoluto da un fetido"
	.dexText "GLOOM: più puzza meglio è!"
	.dexText "Quando la sera chiude i petali"
	.dexText "significa che se ne va a dormire."
	.dexText ""
	.dexLang ES
	.dexText "La belleza de las flores que le crecen"
	.dexText "a BELLOSSOM depende de lo mal que"
	.dexText "oliera el GLOOM a partir del cual"
	.dexText "evolucionó. A mayor hedor, mayor belleza."
	.dexText "Por la noche, este POKéMON cierra"
	.dexText "los pétalos y se echa a dormir."

	.align 2, 0
dexEntryEu92:: @ 092 DODUO
	.2byte 0, 9, 2
	.2byte 10, 4, 0, 7, 10, 10, 1, 4  @ height
	.2byte 10, 10, 8, 6, 4, 10, 10, 3, 9, 2  @ weight
	.dexLang EN
	.dexName "DODUO"
	.dexLang FR
	.dexName "DODUO"
	.dexLang DE
	.dexName "DODU"
	.dexLang EN
	.dexCategory "TWIN BIRD"
	.dexLang FR
	.dexCategoryLeftAligned "DUOISEAU"
	.dexLang DE
	.dexCategoryLeftAligned "DUOVOGEL"
	.dexLang IT
	.dexCategoryLeftAligned "BIUCCELLO"
	.dexLang ES
	.dexCategoryLeftAligned "AVE GEMELA"
	.dexLang EN
	.dexText "DODUO`s two heads never sleep at the"
	.dexText "same time."
	.dexText "Its two heads take turns sleeping,"
	.dexText "so one head can always keep watch for"
	.dexText "enemies while the other one sleeps."
	.dexText ""
	.dexLang FR
	.dexText "Les deux têtes de DODUO ne dorment"
	.dexText "jamais en même temps. Elles dorment à"
	.dexText "tour de rôle pour que l`une puisse"
	.dexText "monter la garde pendant que"
	.dexText "l`autre dort."
	.dexText ""
	.dexLang DE
	.dexText "DODU hat zwei Köpfe, die nie zur"
	.dexText "selben Zeit, sondern abwechselnd"
	.dexText "schlafen. Während ein Kopf schläft,"
	.dexText "hält der andere Ausschau nach Feinden."
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "Le due teste di DODUO non dormono"
	.dexText "mai nello stesso momento, in modo"
	.dexText "che una sia sempre vigile per difendersi"
	.dexText "dai nemici, mentre l`altra può riposare"
	.dexText "tranquilla."
	.dexText ""
	.dexLang ES
	.dexText "Las dos cabezas de DODUO duermen"
	.dexText "de forma independiente, siempre por"
	.dexText "turnos. Así que mientras una duerme,"
	.dexText "la otra hace de centinela por si"
	.dexText "aparecen enemigos."
	.dexText ""

	.align 2, 0
dexEntryEu93:: @ 093 DODRIO
	.2byte 0, 9, 3
	.2byte 10, 5, 1, 1, 10, 10, 1, 8  @ height
	.2byte 10, 1, 8, 7, 8, 10, 10, 8, 5, 2  @ weight
	.dexLang EN
	.dexName "DODRIO"
	.dexLang FR
	.dexName "DODRIO"
	.dexLang DE
	.dexName "DODRI"
	.dexLang EN
	.dexCategory "TRIPLE BIRD"
	.dexLang FR
	.dexCategoryLeftAligned "TRIOISEAU"
	.dexLang DE
	.dexCategoryLeftAligned "TRIVOGEL"
	.dexLang IT
	.dexCategoryLeftAligned "TRIUCCELLO"
	.dexLang ES
	.dexCategoryLeftAligned "AVE TRIPLE"
	.dexLang EN
	.dexText "Watch out if DODRIO`s three heads are"
	.dexText "looking in three separate directions."
	.dexText "It`s a sure sign that it is on its guard."
	.dexText "Don`t go near this POKéMON if it`s being"
	.dexText "wary - it may decide to peck you."
	.dexText ""
	.dexLang FR
	.dexText "Il faut se méfier lorsque les trois"
	.dexText "têtes de DODRIO regardent dans des"
	.dexText "directions différentes. Cela signifie"
	.dexText "qu`il est sur ses gardes. Si c`est le cas,"
	.dexText "il vaut mieux ne pas s`approcher de ce"
	.dexText "POKéMON, il pourrait décider d`attaquer."
	.dexLang DE
	.dexText "DODRIs drei Köpfe blicken in drei ver-"
	.dexText "schiedene Richtungen. Es ist immer auf"
	.dexText "der Hut."
	.dexText "Du solltest dich diesem POKéMON nicht"
	.dexText "nähern, wenn es bereits misstrauisch"
	.dexText "ist. Es könnte nach dir hacken."
	.dexLang IT
	.dexText "Se le tre teste di DODRIO guardano"
	.dexText "in tre direzioni diverse, significa che"
	.dexText "il POKéMON è vigile."
	.dexText "In questo stato il POKéMON non va"
	.dexText "avvicinato, poiché potrebbe decidere"
	.dexText "di attaccare."
	.dexLang ES
	.dexText "Hay que tener cuidado cuando las tres"
	.dexText "cabezas de DODRIO miran cada una para"
	.dexText "un lado, pues están en guardia."
	.dexText "No te acerques a este POKéMON cuando"
	.dexText "está vigilando porque puede darte un"
	.dexText "picotazo."

	.align 2, 0
dexEntryEu94:: @ 094 ROSELIA
	.2byte 0, 9, 4
	.2byte 10, 1, 0, 0, 10, 10, 0, 3  @ height
	.2byte 10, 10, 10, 4, 4, 10, 10, 10, 2, 0  @ weight
	.dexLang EN
	.dexName "ROSELIA"
	.dexLang FR
	.dexName "ROSELIA"
	.dexLang DE
	.dexName "ROSELIA"
	.dexLang EN
	.dexCategory "THORN"
	.dexLang FR
	.dexCategoryLeftAligned "EPINE"
	.dexLang DE
	.dexCategoryLeftAligned "DORN"
	.dexLang IT
	.dexCategoryLeftAligned "SPINA"
	.dexLang ES
	.dexCategoryLeftAligned "ESPINA"
	.dexLang EN
	.dexText "On extremely rare occasions, a ROSELIA"
	.dexText "is said to appear with its flowers in"
	.dexText "unusual colors."
	.dexText "The thorns on this POKéMON`s head"
	.dexText "contain a vicious poison."
	.dexText ""
	.dexLang FR
	.dexText "En de très rares occasions, on dit qu`un"
	.dexText "ROSELIA peut apparaître en arborant"
	.dexText "des fleurs aux couleurs inhabituelles."
	.dexText "Les épines sur la tête de ce POKéMON"
	.dexText "contiennent un dangereux poison."
	.dexText ""
	.dexLang DE
	.dexText "Nur sehr selten bekommt man ROSELIA"
	.dexText "mit seinen ungewöhnlich farbigen Blumen"
	.dexText "zu Gesicht. Die Dornen am Kopf dieses"
	.dexText "POKéMON enthalten ein grausames Gift."
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "In qualche rarissima occasione,"
	.dexText "ROSELIA è stata vista con fiori"
	.dexText "dai colori inconsueti."
	.dexText "Le spine sulla testa di questo POKéMON"
	.dexText "contengono un veleno micidiale."
	.dexText ""
	.dexLang ES
	.dexText "Dicen que, en muy raras ocasiones,"
	.dexText "aparece un ejemplar de ROSELIA con las"
	.dexText "flores de colores muy poco comunes."
	.dexText "Las espinas que este POKéMON tiene"
	.dexText "en la cabeza contienen un veneno"
	.dexText "extremadamente peligroso."

	.align 2, 0
dexEntryEu95:: @ 095 GULPIN
	.2byte 0, 9, 5
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 2, 2, 7, 10, 10, 1, 0, 3  @ weight
	.dexLang EN
	.dexName "GULPIN"
	.dexLang FR
	.dexName "GLOUPTI"
	.dexLang DE
	.dexName "SCHLUPPUCK"
	.dexLang EN
	.dexCategory "STOMACH"
	.dexLang FR
	.dexCategoryLeftAligned "ESTOMAC"
	.dexLang DE
	.dexCategoryLeftAligned "MAGEN"
	.dexLang IT
	.dexCategoryLeftAligned "STOMACO"
	.dexLang ES
	.dexCategoryLeftAligned "ESTÓMAGO"
	.dexLang EN
	.dexText "Most of GULPIN`s body is made up of its"
	.dexText "stomach - its heart and brain are very"
	.dexText "small in comparison."
	.dexText "This POKéMON`s stomach contains"
	.dexText "special enzymes that dissolve anything."
	.dexText ""
	.dexLang FR
	.dexText "Le corps de GLOUPTI n`est"
	.dexText "pratiquement qu`un gros estomac. En"
	.dexText "comparaison, son cœur et son cerveau"
	.dexText "sont tout petits. L`estomac de ce"
	.dexText "POKéMON contient des en{3845}ymes"
	.dexText "spéciales capables de tout dissoudre."
	.dexLang DE
	.dexText "SCHLUPPUCKs Körper besteht zum"
	.dexText "größten Teil aus seinem Magen. Sein Herz"
	.dexText "und sein Gehirn sind im Vergleich dazu"
	.dexText "sehr klein. Der Magen dieses POKéMON"
	.dexText "enthält Enzyme, die alles zersetzen"
	.dexText "können."
	.dexLang IT
	.dexText "La maggior parte del corpo di GULPIN"
	.dexText "è formato dallo stomaco di dimensioni"
	.dexText "enormi rispetto al cuore e al cervello."
	.dexText "Lo stomaco di questo POKéMON"
	.dexText "contiene enzimi speciali che"
	.dexText "sciolgono qualsiasi cosa."
	.dexLang ES
	.dexText "La mayor parte del cuerpo de GULPIN"
	.dexText "está ocupado por su estómago."
	.dexText "En comparación, el corazón y el cerebro"
	.dexText "son muy pequeños. Este POKéMON"
	.dexText "tiene enzimas especiales en el estómago"
	.dexText "capaces de corroerlo todo."

	.align 2, 0
dexEntryEu96:: @ 096 SWALOT
	.2byte 0, 9, 6
	.2byte 10, 5, 0, 7, 10, 10, 1, 7  @ height
	.2byte 10, 1, 7, 6, 4, 10, 10, 8, 0, 0  @ weight
	.dexLang EN
	.dexName "SWALOT"
	.dexLang FR
	.dexName "AVALTOUT"
	.dexLang DE
	.dexName "SCHLUKWECH"
	.dexLang EN
	.dexCategory "POISON BAG"
	.dexLang FR
	.dexCategoryLeftAligned "SAC POISON"
	.dexLang DE
	.dexCategoryLeftAligned "GIFTBEUTEL"
	.dexLang IT
	.dexCategoryLeftAligned "VELENOSACCO"
	.dexLang ES
	.dexCategoryLeftAligned "BOLSA VEN."
	.dexLang EN
	.dexText "SWALOT has no teeth, so what it"
	.dexText "eats, it swallows whole, no matter what."
	.dexText "Its cavernous mouth yawns widely."
	.dexText "An automobile tire could easily fit"
	.dexText "inside this POKéMON`s mouth."
	.dexText ""
	.dexLang FR
	.dexText "AVALTOUT n`a pas de dents, ce qui"
	.dexText "le force à tout avaler en une bouchée."
	.dexText "Quand il bâille, sa bouche prend une"
	.dexText "taille impressionnante, et on pourrait y"
	.dexText "placer une roue de voiture."
	.dexText ""
	.dexLang DE
	.dexText "SCHLUKWECH hat keine Zähne. Alles was"
	.dexText "es isst, schluckt es im Ganzen herunter."
	.dexText "Sein Maul ist so riesig, dass mit"
	.dexText "Leichtigkeit ein Autoreifen hinein-"
	.dexText "passen würde."
	.dexText ""
	.dexLang IT
	.dexText "SWALOT non ha denti, così quando"
	.dexText "mangia ingoia ogni cosa intera, senza"
	.dexText "masticare. Quando sbadiglia, la sua"
	.dexText "bocca enorme si apre a mo` di"
	.dexText "voragine. È così grande che potrebbe"
	.dexText "contenere persino un pneumatico."
	.dexLang ES
	.dexText "SWALOT no tiene dientes, así que lo que"
	.dexText "come se lo traga de una vez; da igual"
	.dexText "lo que sea."
	.dexText "A este POKéMON le cabría un neumático"
	.dexText "en la boca sin problema."
	.dexText ""

	.align 2, 0
dexEntryEu97:: @ 097 CARVANHA
	.2byte 0, 9, 7
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 4, 5, 9, 10, 10, 2, 0, 8  @ weight
	.dexLang EN
	.dexName "CARVANHA"
	.dexLang FR
	.dexName "CARVANHA"
	.dexLang DE
	.dexName "KANIVANHA"
	.dexLang EN
	.dexCategory "SAVAGE"
	.dexLang FR
	.dexCategoryLeftAligned "FEROCE"
	.dexLang DE
	.dexCategoryLeftAligned "GNADENLOS"
	.dexLang IT
	.dexCategoryLeftAligned "FEROCE"
	.dexLang ES
	.dexCategoryLeftAligned "FEROZ"
	.dexLang EN
	.dexText "CARVANHA`s strongly developed jaws"
	.dexText "and its sharply pointed fangs pack the"
	.dexText "destructive power to rip out boat hulls."
	.dexText "Many boats have been attacked and"
	.dexText "sunk by this POKéMON."
	.dexText ""
	.dexLang FR
	.dexText "Les mâchoires surdéveloppées de"
	.dexText "CARVANHA et ses crocs acérés sont"
	.dexText "si puissants qu`ils peuvent déchirer la"
	.dexText "coque des bateaux. De nombreux navires"
	.dexText "ont été attaqués et coulés"
	.dexText "par ce POKéMON."
	.dexLang DE
	.dexText "KANIVANHAs starke Kiefer und seine"
	.dexText "spitzen Zähne verfügen über die"
	.dexText "zerstörerische Kraft, Bootsrümpfe"
	.dexText "verschlingen zu können. Dieses POKéMON"
	.dexText "hat schon viele Boote versenkt."
	.dexText ""
	.dexLang IT
	.dexText "Le sviluppate mascelle di CARVANHA e i"
	.dexText "denti estremamente appuntiti e affilati"
	.dexText "hanno una potenza distruttiva tale da"
	.dexText "sventrare la carena di una nave."
	.dexText "Già molte navi sono state attaccate"
	.dexText "e affondate da questo POKéMON."
	.dexLang ES
	.dexText "CARVANHA, gracias a las descomunales"
	.dexText "fauces de afilados colmillos que tiene,"
	.dexText "es capaz de hacer trizas un barco."
	.dexText "Son muchas las naves que han sufrido"
	.dexText "el ataque de este POKéMON y han"
	.dexText "acabado naufragando."

	.align 2, 0
dexEntryEu98:: @ 098 SHARPEDO
	.2byte 0, 9, 8
	.2byte 10, 5, 1, 1, 10, 10, 1, 8  @ height
	.2byte 10, 1, 9, 5, 8, 10, 10, 8, 8, 8  @ weight
	.dexLang EN
	.dexName "SHARPEDO"
	.dexLang FR
	.dexName "SHARPEDO"
	.dexLang DE
	.dexName "TOHAIDO"
	.dexLang EN
	.dexCategory "BRUTAL"
	.dexLang FR
	.dexCategoryLeftAligned "BRUTAL"
	.dexLang DE
	.dexCategoryLeftAligned "BRUTAL"
	.dexLang IT
	.dexCategoryLeftAligned "BRUTALE"
	.dexLang ES
	.dexCategoryLeftAligned "VORAZ"
	.dexLang EN
	.dexText "Nicknamed “the bully of the sea,”"
	.dexText "SHARPEDO is widely feared."
	.dexText "Its cruel fangs grow back immediately"
	.dexText "if they snap off."
	.dexText "Just one of these POKéMON can"
	.dexText "thoroughly tear apart a supertanker."
	.dexLang FR
	.dexText "Surnommé le «tyran des mers»,"
	.dexText "SHARPEDO est craint de par le"
	.dexText "monde. Ses crocs menaçants"
	.dexText "repoussent lorsqu`ils se brisent."
	.dexText "Un seul de ces POKéMON peut détruire"
	.dexText "un pétrolier gros porteur."
	.dexLang DE
	.dexText "TOHAIDO trägt den Spitznamen"
	.dexText "„Tyrann des Meeres“ und ist sehr"
	.dexText "gefürchtet. Seine grausamen Zähne"
	.dexText "wachsen sofort nach, wenn sie"
	.dexText "ausgebrochen sind. Es kann sogar einen"
	.dexText "Öltanker zerreißen."
	.dexLang IT
	.dexText "Soprannominato “Tiranno del mare”,"
	.dexText "SHARPEDO è molto temuto. Se perde"
	.dexText "qualcuno dei suoi temibili denti, questo"
	.dexText "ricresce all`istante. Uno di questi"
	.dexText "POKéMON da solo riesce ad"
	.dexText "affondare una superpetroliera."
	.dexLang ES
	.dexText "Conocido como “el terror de los mares”,"
	.dexText "SHARPEDO es temido por todos. Si este"
	.dexText "POKéMON pierde las escalofriantes"
	.dexText "mandíbulas que tiene, las recupera en"
	.dexText "breve. Basta con un SHARPEDO para"
	.dexText "destrozar un buque-cisterna."

	.align 2, 0
dexEntryEu99:: @ 099 WAILMER
	.2byte 0, 9, 9
	.2byte 10, 6, 0, 7, 10, 10, 2, 0  @ height
	.2byte 10, 2, 8, 6, 6, 10, 1, 3, 0, 0  @ weight
	.dexLang EN
	.dexName "WAILMER"
	.dexLang FR
	.dexName "WAILMER"
	.dexLang DE
	.dexName "WAILMER"
	.dexLang EN
	.dexCategory "BALL WHALE"
	.dexLang FR
	.dexCategoryLeftAligned "BALEINBOULE"
	.dexLang DE
	.dexCategoryLeftAligned "KUGELWAL"
	.dexLang IT
	.dexCategoryLeftAligned "BALENOTTERO"
	.dexLang ES
	.dexCategoryLeftAligned "BALLENABOLA"
	.dexLang EN
	.dexText "WAILMER`s nostrils are located above"
	.dexText "its eyes. This playful POKéMON loves"
	.dexText "to startle people by forcefully snorting"
	.dexText "out seawater it stores inside its body"
	.dexText "out of its nostrils."
	.dexText ""
	.dexLang FR
	.dexText "Les narines de WAILMER sont situées"
	.dexText "au-dessus de ses yeux. Ce joyeux"
	.dexText "POKéMON adore effrayer les gens en"
	.dexText "expulsant de l`eau de mer"
	.dexText "par les narines."
	.dexText ""
	.dexLang DE
	.dexText "WAILMERs Nasenlöcher liegen über"
	.dexText "seinen Augen. Dieses verspielte"
	.dexText "POKéMON erschreckt gern Menschen,"
	.dexText "indem es das Meerwasser, das es in"
	.dexText "seinem Körper speichert, mit aller Kraft"
	.dexText "herausprustet."
	.dexLang IT
	.dexText "Le narici di WAILMER sono posizionate"
	.dexText "sopra gli occhi. È un giocherellone e ama"
	.dexText "spaventare le persone sparando dalle"
	.dexText "narici l`acqua del mare, che accumula"
	.dexText "all`interno del proprio corpo."
	.dexText ""
	.dexLang ES
	.dexText "WAILMER tiene los espiráculos encima de"
	.dexText "la cabeza. A este juguetón POKéMON le"
	.dexText "encanta asustar a la gente expulsando"
	.dexText "el agua que acumula a través de estos"
	.dexText "orificios."
	.dexText ""

	.align 2, 0
dexEntryEu100:: @ 100 WAILORD
	.2byte 1, 0, 0
	.2byte 4, 7, 0, 7, 10, 1, 4, 5  @ height
	.2byte 10, 8, 7, 7, 4, 10, 3, 9, 8, 0  @ weight
	.dexLang EN
	.dexName "WAILORD"
	.dexLang FR
	.dexName "WAILORD"
	.dexLang DE
	.dexName "WAILORD"
	.dexLang EN
	.dexCategory "FLOAT WHALE"
	.dexLang FR
	.dexCategoryLeftAligned "CACHABOUEE"
	.dexLang DE
	.dexCategoryLeftAligned "FLUTWAL"
	.dexLang IT
	.dexCategoryLeftAligned "MEGABALENA"
	.dexLang ES
	.dexCategoryLeftAligned "BALLENAFLOT"
	.dexLang EN
	.dexText "WAILORD is the largest of all identified"
	.dexText "POKéMON up to now."
	.dexText "This giant POKéMON swims languorously"
	.dexText "in the vast open sea, eating massive"
	.dexText "amounts of food at once with its"
	.dexText "enormous mouth."
	.dexLang FR
	.dexText "WAILORD est le plus grand POKéMON"
	.dexText "découvert à ce jour. Ce POKéMON géant"
	.dexText "nage lascivement dans les grandes"
	.dexText "étendues maritimes, avalant d`énormes"
	.dexText "quantités de nourriture en une seule"
	.dexText "de ses monstrueuses bouchées."
	.dexLang DE
	.dexText "WAILORD ist bisher das größte aller"
	.dexText "identifizierten POKéMON. Es schwimmt"
	.dexText "reglos auf dem offenen Meer und nimmt"
	.dexText "mit seinem enormen Maul riesige Mengen"
	.dexText "an Nahrung auf."
	.dexText ""
	.dexLang IT
	.dexText "WAILORD è il più grande tra tutti i"
	.dexText "POKéMON finora identificati."
	.dexText "Con la sua gigante mole nuota"
	.dexText "dolcemente nella vastità del mare"
	.dexText "aperto, ingoiando enormi quantità"
	.dexText "di cibo con la bocca enorme."
	.dexLang ES
	.dexText "WAILORD es el mayor POKéMON registrado"
	.dexText "hasta la fecha. Este coloso va nadando"
	.dexText "lánguidamente por el ancho mar"
	.dexText "con la boca abierta para que penetre"
	.dexText "la mayor cantidad posible de alimento."
	.dexText ""

	.align 2, 0
dexEntryEu101:: @ 101 NUMEL
	.2byte 1, 0, 1
	.2byte 10, 2, 0, 4, 10, 10, 0, 7  @ height
	.2byte 10, 10, 5, 2, 9, 10, 10, 2, 4, 0  @ weight
	.dexLang EN
	.dexName "NUMEL"
	.dexLang FR
	.dexName "CHAMALLOT"
	.dexLang DE
	.dexName "CAMAUB"
	.dexLang EN
	.dexCategory "NUMB"
	.dexLang FR
	.dexCategoryLeftAligned "ENGOURDI"
	.dexLang DE
	.dexCategoryLeftAligned "TAUBHEIT"
	.dexLang IT
	.dexCategoryLeftAligned "TORPORE"
	.dexLang ES
	.dexCategoryLeftAligned "TORPE"
	.dexLang EN
	.dexText "NUMEL is extremely dull witted - it"
	.dexText "doesn`t notice being hit. However, it"
	.dexText "can`t stand hunger for even a second."
	.dexText "This POKéMON`s body is a seething"
	.dexText "cauldron of boiling magma."
	.dexText ""
	.dexLang FR
	.dexText "CHAMALLOT est terriblement lent"
	.dexText "d`esprit. Il ne remarque même pas quand"
	.dexText "il est touché. Il ne supporte pas d`avoir"
	.dexText "faim, même une seconde. Le corps de ce"
	.dexText "POKéMON est comparable à un chaudron"
	.dexText "de magma bouillonnant."
	.dexLang DE
	.dexText "CAMAUB ist nicht besonders helle. Es"
	.dexText "nimmt nicht einmal wahr, wenn es"
	.dexText "getroffen wurde. Ein Hungergefühl"
	.dexText "allerdings kann es nicht einmal eine"
	.dexText "Sekunde lang aushalten. In seinem"
	.dexText "Körper brodelt glühend heißes Magma."
	.dexLang IT
	.dexText "NUMEL è estremamente tardo, tanto"
	.dexText "da non notare di essere attaccato."
	.dexText "Tuttavia, non sa resistere alla fame"
	.dexText "per più di un secondo. Il suo corpo"
	.dexText "è un calderone bollente di magma"
	.dexText "liquido."
	.dexLang ES
	.dexText "NUMEL tarda en percibir las cosas (no se"
	.dexText "entera ni cuando lo golpean). Pero se"
	.dexText "da cuenta enseguida de si tiene hambre."
	.dexText "El cuerpo de este POKéMON es un caldero"
	.dexText "de magma hirviendo."
	.dexText ""

	.align 2, 0
dexEntryEu102:: @ 102 CAMERUPT
	.2byte 1, 0, 2
	.2byte 10, 6, 0, 3, 10, 10, 1, 9  @ height
	.2byte 10, 4, 8, 5, 0, 10, 2, 2, 0, 0  @ weight
	.dexLang EN
	.dexName "CAMERUPT"
	.dexLang FR
	.dexName "CAMERUPT"
	.dexLang DE
	.dexName "CAMERUPT"
	.dexLang EN
	.dexCategory "ERUPTION"
	.dexLang FR
	.dexCategoryLeftAligned "ERUPTION"
	.dexLang DE
	.dexCategoryLeftAligned "AUSBRUCH"
	.dexLang IT
	.dexCategoryLeftAligned "ERUZIONE"
	.dexLang ES
	.dexCategoryLeftAligned "ERUPCIÓN"
	.dexLang EN
	.dexText "CAMERUPT has a volcano inside its body."
	.dexText "Magma of 18,000 degrees F courses"
	.dexText "through its body."
	.dexText "Occasionally, the humps on this"
	.dexText "POKéMON`s back erupt, spewing the"
	.dexText "superheated magma."
	.dexLang FR
	.dexText "Le corps de CAMERUPT renferme un"
	.dexText "volcan. Du magma à 10 000 degrés coule"
	.dexText "dans ses veines."
	.dexText "De temps en temps, les bosses sur le dos"
	.dexText "de ce POKéMON entrent en éruption et"
	.dexText "crachent le magma surchauffé."
	.dexLang DE
	.dexText "CAMERUPT trägt einen Vulkan in seinem"
	.dexText "Körper. 10.000 Grad heißes Magma fließt"
	.dexText "in ihm. Manchmal brechen die Höcker auf"
	.dexText "seinem Rücken aus und verspucken"
	.dexText "glühend heißes Magma."
	.dexText ""
	.dexLang IT
	.dexText "CAMERUPT ha un vulcano all`interno"
	.dexText "del proprio corpo. Nelle sue vene scorre"
	.dexText "magma liquido a 10.000 gradi centigradi."
	.dexText "Talvolta le gobbe che ha sulla schiena"
	.dexText "eruttano, espellendo magma rovente."
	.dexText ""
	.dexLang ES
	.dexText "CAMERUPT encierra un volcán"
	.dexText "en su interior y un magma de 10.000"
	.dexText "grados centígrados que le recorre"
	.dexText "el cuerpo. A veces, las jorobas de la"
	.dexText "espalda entran en erupción y escupen"
	.dexText "el abrasivo magma."

	.align 2, 0
dexEntryEu103:: @ 103 SLUGMA
	.2byte 1, 0, 3
	.2byte 10, 2, 0, 4, 10, 10, 0, 7  @ height
	.2byte 10, 10, 7, 7, 2, 10, 10, 3, 5, 0  @ weight
	.dexLang EN
	.dexName "SLUGMA"
	.dexLang FR
	.dexName "LIMAGMA"
	.dexLang DE
	.dexName "SCHNECKMAG"
	.dexLang EN
	.dexCategory "LAVA"
	.dexLang FR
	.dexCategoryLeftAligned "LAVE"
	.dexLang DE
	.dexCategoryLeftAligned "LAVA"
	.dexLang IT
	.dexCategoryLeftAligned "LAVA"
	.dexLang ES
	.dexCategoryLeftAligned "LAVA"
	.dexLang EN
	.dexText "Molten magma courses throughout"
	.dexText "SLUGMA`s circulatory system."
	.dexText "If this POKéMON is chilled, the magma"
	.dexText "cools and hardens. Its body turns"
	.dexText "brittle and chunks fall off, reducing"
	.dexText "its size."
	.dexLang FR
	.dexText "Du magma en fusion coule dans les"
	.dexText "veines de LIMAGMA. Si ce POKéMON"
	.dexText "est refroidi, le magma se solidifie."
	.dexText "Son corps devient alors cassant et des"
	.dexText "morceaux s`en détachent,"
	.dexText "diminuant ainsi sa taille."
	.dexLang DE
	.dexText "Durch SCHNECKMAGs Kreislaufsystem"
	.dexText "fließt Magma. Wenn dieses POKéMON"
	.dexText "erkältet ist, kühlt das Magma"
	.dexText "aus und erhärtet. Sein Körper wird"
	.dexText "spröde und es brechen Stücke heraus,"
	.dexText "so dass es kleiner wird."
	.dexLang IT
	.dexText "Nel corpo di SLUGMA scorre magma"
	.dexText "liquido. In caso di congelamento, il"
	.dexText "magma si raffredda e si solidifica."
	.dexText "Il corpo diventa fragile e cade a pezzi"
	.dexText "consumandosi progressivamente."
	.dexText ""
	.dexLang ES
	.dexText "Por el sistema circulatorio de SLUGMA"
	.dexText "corre magma líquido. Si este POKéMON"
	.dexText "se enfriara, el magma perdería el calor"
	.dexText "y se solidificaría, con lo que se"
	.dexText "resquebrajaría entero, perdería trozos"
	.dexText "y reduciría su tamaño."

	.align 2, 0
dexEntryEu104:: @ 104 MAGCARGO
	.2byte 1, 0, 4
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 1, 2, 1, 3, 10, 10, 5, 5, 0  @ weight
	.dexLang EN
	.dexName "MAGCARGO"
	.dexLang FR
	.dexName "VOLCAROPOD"
	.dexLang DE
	.dexName "MAGCARGO"
	.dexLang EN
	.dexCategory "LAVA"
	.dexLang FR
	.dexCategoryLeftAligned "LAVE"
	.dexLang DE
	.dexCategoryLeftAligned "LAVA"
	.dexLang IT
	.dexCategoryLeftAligned "LAVA"
	.dexLang ES
	.dexCategoryLeftAligned "LAVA"
	.dexLang EN
	.dexText "MAGCARGO`s shell is actually its skin"
	.dexText "that hardened as a result of cooling."
	.dexText "Its shell is very brittle and fragile -"
	.dexText "just touching it causes it to crumble"
	.dexText "apart. This POKéMON returns to its"
	.dexText "original size by dipping itself in magma."
	.dexLang FR
	.dexText "La carapace de VOLCAROPOD est en fait"
	.dexText "constituée de sa peau, qui s`est durcie"
	.dexText "après un refroidissement. Elle est très"
	.dexText "cassante et fragile. Il suffit de la"
	.dexText "toucher pour qu`elle casse. Il reprend"
	.dexText "sa forme en plongeant dans le magma."
	.dexLang DE
	.dexText "MAGCARGOs Schale ist eigentlich seine"
	.dexText "Haut, die erhärtet ist, als es auskühlte."
	.dexText "Seine Schale ist sehr spröde und"
	.dexText "zerbrechlich. Schon bei einer leichten"
	.dexText "Berührung bricht sie auseinander. Dann"
	.dexText "muss es ein Bad in Magma nehmen."
	.dexLang IT
	.dexText "La corazza di MAGCARGO è formata"
	.dexText "dalla sua pelle induritasi per effetto"
	.dexText "del raffreddamento. La corazza è"
	.dexText "fragile e friabile: cade a pezzi al minimo"
	.dexText "contatto. Riacquista le sue dimensioni"
	.dexText "normali immergendosi nel magma."
	.dexLang ES
	.dexText "La coraza de MAGCARGO es en realidad"
	.dexText "su propia piel que quedó endurecida al"
	.dexText "enfriarse. Está muy resquebrajada y es"
	.dexText "muy frágil; se desharía solo con"
	.dexText "tocarla. Este POKéMON debe sumergirse"
	.dexText "en magma para recuperar su forma."

	.align 2, 0
dexEntryEu105:: @ 105 TORKOAL
	.2byte 1, 0, 5
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 1, 7, 7, 2, 10, 10, 8, 0, 4  @ weight
	.dexLang EN
	.dexName "TORKOAL"
	.dexLang FR
	.dexName "CHARTOR"
	.dexLang DE
	.dexName "QURTEL"
	.dexLang EN
	.dexCategory "COAL"
	.dexLang FR
	.dexCategoryLeftAligned "CHARBON"
	.dexLang DE
	.dexCategoryLeftAligned "KOHLE"
	.dexLang IT
	.dexCategoryLeftAligned "CARBONE"
	.dexLang ES
	.dexCategoryLeftAligned "CARBÓN"
	.dexLang EN
	.dexText "TORKOAL digs through mountains in"
	.dexText "search of coal. If it finds some, it fills"
	.dexText "hollow spaces on its shell with the coal"
	.dexText "and burns it."
	.dexText "If it is attacked, this POKéMON spouts"
	.dexText "thick black smoke to beat a retreat."
	.dexLang FR
	.dexText "CHARTOR fore les montagnes à la"
	.dexText "recherche de charbon. Lorsqu`il en"
	.dexText "trouve, il le met dans les emplacements"
	.dexText "creux de sa carapace pour le brûler."
	.dexText "Quand il est attaqué, ce POKéMON crache"
	.dexText "une épaisse fumée noire pour s`enfuir."
	.dexLang DE
	.dexText "QURTEL schaufelt sich auf der Suche"
	.dexText "nach Kohle durch die Berge. Wenn es"
	.dexText "welche findet, füllt es die Hohlräume"
	.dexText "seines Panzers mit Kohle und verbrennt"
	.dexText "diese. Wenn es angegriffen wird, stößt"
	.dexText "es dicken schwarzen Rauch aus."
	.dexLang IT
	.dexText "TORKOAL scava in montagna in cerca"
	.dexText "di carbone. Quando lo trova, lo usa per"
	.dexText "riempire la cavità della propria corazza"
	.dexText "e poi lo brucia. In caso di aggressione,"
	.dexText "emette nubi di fumo nero per poi"
	.dexText "battere in ritirata."
	.dexLang ES
	.dexText "TORKOAL va cavando por las montañas en"
	.dexText "busca de carbón. Cuando lo encuentra,"
	.dexText "rellena los huecos que tiene dentro del"
	.dexText "caparazón y lo quema."
	.dexText "Si le atacan, este POKéMON echa un humo"
	.dexText "negro que le permite la retirada."

	.align 2, 0
dexEntryEu106:: @ 106 GRIMER
	.2byte 1, 0, 6
	.2byte 10, 2, 1, 1, 10, 10, 0, 9  @ height
	.2byte 10, 10, 6, 6, 1, 10, 10, 3, 0, 0  @ weight
	.dexLang EN
	.dexName "GRIMER"
	.dexLang FR
	.dexName "TADMORV"
	.dexLang DE
	.dexName "SLEIMA"
	.dexLang EN
	.dexCategory "SLUDGE"
	.dexLang FR
	.dexCategoryLeftAligned "DEGUEU"
	.dexLang DE
	.dexCategoryLeftAligned "SCHLAMM"
	.dexLang IT
	.dexCategoryLeftAligned "MELMA"
	.dexLang ES
	.dexCategoryLeftAligned "LODO"
	.dexLang EN
	.dexText "GRIMER emerged from the sludge that"
	.dexText "settled on a polluted seabed."
	.dexText "This POKéMON loves anything filthy."
	.dexText "It constantly leaks a horribly germ-"
	.dexText "infested fluid from all over its body."
	.dexText ""
	.dexLang FR
	.dexText "TADMORV est apparu dans la vase"
	.dexText "accumulée sur un bord de mer pollué."
	.dexText "Ce POKéMON aime tout ce qui est"
	.dexText "dégoûtant. Une substance pleine de"
	.dexText "germes suinte constamment de tout"
	.dexText "son corps."
	.dexLang DE
	.dexText "SLEIMA ist aus dem Schlamm eines"
	.dexText "verseuchten Flussbetts entstanden."
	.dexText "Dieses POKéMON liebt verschmutzte"
	.dexText "Dinge. Es scheidet ständig eine mit"
	.dexText "Bakterien verseuchte Flüssigkeit aus"
	.dexText "seinem ganzen Körper aus."
	.dexLang IT
	.dexText "GRIMER proviene dal fango depositato"
	.dexText "sui fondali inquinati. Infatti ama tutto"
	.dexText "ciò che è sudicio e tossico."
	.dexText "Emana continuamente un fluido"
	.dexText "batterico velenoso da ogni"
	.dexText "parte del corpo."
	.dexLang ES
	.dexText "GRIMER emergió del lodo que se formó"
	.dexText "en una zona contaminada en el fondo del"
	.dexText "mar. A este POKéMON le encanta todo lo"
	.dexText "que sea suciedad. Emana continuamente"
	.dexText "y por todo el cuerpo un horrible fluido"
	.dexText "contaminado de bacterias."

	.align 2, 0
dexEntryEu107:: @ 107 MUK
	.2byte 1, 0, 7
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 10, 6, 6, 1, 10, 10, 3, 0, 0  @ weight
	.dexLang EN
	.dexName "MUK"
	.dexLang FR
	.dexName "GROTADMORV"
	.dexLang DE
	.dexName "SLEIMOK"
	.dexLang EN
	.dexCategory "SLUDGE"
	.dexLang FR
	.dexCategoryLeftAligned "DEGUEU"
	.dexLang DE
	.dexCategoryLeftAligned "SCHLAMM"
	.dexLang IT
	.dexCategoryLeftAligned "MELMA"
	.dexLang ES
	.dexCategoryLeftAligned "LODO"
	.dexLang EN
	.dexText "This POKéMON`s favorite food is"
	.dexText "anything that is repugnantly filthy."
	.dexText "In dirty towns where people think"
	.dexText "nothing of throwing away litter on the"
	.dexText "streets, MUK are certain to gather."
	.dexText ""
	.dexLang FR
	.dexText "Ce POKéMON ne mange que ce qui est"
	.dexText "répugnant et abject."
	.dexText "Les GROTADMORV se rassemblent dans"
	.dexText "les villes où les gens jettent tout"
	.dexText "par terre, dans la rue."
	.dexText ""
	.dexLang DE
	.dexText "SLEIMOKs Lieblingsspeise ist alles, was"
	.dexText "widerlich verschmutzt ist. In dreckigen"
	.dexText "Städten, in denen sich Menschen nichts"
	.dexText "dabei denken, wenn sie Müll auf die"
	.dexText "Straße werfen, lassen sich diese"
	.dexText "POKéMON mit Vorliebe in Scharen nieder."
	.dexLang IT
	.dexText "Questo POKéMON si ciba di qualunque"
	.dexText "cosa sia sudicia e ripugnante. Le"
	.dexText "città più inquinate, dove la popolazione"
	.dexText "getta i rifiuti in strada, sono un luogo"
	.dexText "di ritrovo frequente per i MUK."
	.dexText ""
	.dexLang ES
	.dexText "A este POKéMON le encanta comer cosas"
	.dexText "repulsivas. En ciudades sucias en las"
	.dexText "que la gente tira la basura por la calle,"
	.dexText "los MUK tienen sin duda su punto"
	.dexText "de encuentro."
	.dexText ""

	.align 2, 0
dexEntryEu108:: @ 108 KOFFING
	.2byte 1, 0, 8
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 10, 2, 2, 10, 10, 10, 1, 0  @ weight
	.dexLang EN
	.dexName "KOFFING"
	.dexLang FR
	.dexName "SMOGO"
	.dexLang DE
	.dexName "SMOGON"
	.dexLang EN
	.dexCategory "POISON GAS"
	.dexLang FR
	.dexCategoryLeftAligned "GAZ MORTEL"
	.dexLang DE
	.dexCategoryLeftAligned "GIFTWOLKE"
	.dexLang IT
	.dexCategoryLeftAligned "VELENUVOLA"
	.dexLang ES
	.dexCategoryLeftAligned "GAS VENENO"
	.dexLang EN
	.dexText "If KOFFING becomes agitated, it raises"
	.dexText "the toxicity of its internal gases and"
	.dexText "jets them out from all over its body."
	.dexText "This POKéMON may also overinflate its"
	.dexText "round body, then explode."
	.dexText ""
	.dexLang FR
	.dexText "Lorsque SMOGO s`agite, ça augmente la"
	.dexText "toxicité de ses gaz internes. Il les"
	.dexText "projette ensuite par les nombreux"
	.dexText "orifices de son corps. Ce POKéMON peut"
	.dexText "aussi gonfler son corps et le"
	.dexText "faire exploser."
	.dexLang DE
	.dexText "Wenn SMOGON sich aufregt, lässt es"
	.dexText "das giftige Gas in seinem Inneren"
	.dexText "entweichen. Wenn es sich zu sehr"
	.dexText "aufbläht, explodiert dieses POKéMON."
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "Se KOFFING si agita, aumenta la"
	.dexText "tossicità dei suoi gas interni e li"
	.dexText "espelle violentemente da tutto il corpo."
	.dexText "Questo POKéMON riesce anche a"
	.dexText "gonfiarsi fino al punto di esplodere."
	.dexText ""
	.dexLang ES
	.dexText "Si KOFFING se pone nervioso, aumenta"
	.dexText "el nivel de toxicidad de los gases que"
	.dexText "tiene y los expulsa por todo el cuerpo."
	.dexText "También suele hincharse mucho hasta"
	.dexText "llegar a explotar."
	.dexText ""

	.align 2, 0
dexEntryEu109:: @ 109 WEEZING
	.2byte 1, 0, 9
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 10, 2, 0, 9, 10, 10, 10, 9, 5  @ weight
	.dexLang EN
	.dexName "WEEZING"
	.dexLang FR
	.dexName "SMOGOGO"
	.dexLang DE
	.dexName "SMOGMOG"
	.dexLang EN
	.dexCategory "POISON GAS"
	.dexLang FR
	.dexCategoryLeftAligned "GAZ MORTEL"
	.dexLang DE
	.dexCategoryLeftAligned "GIFTWOLKE"
	.dexLang IT
	.dexCategoryLeftAligned "VELENUVOLA"
	.dexLang ES
	.dexCategoryLeftAligned "GAS VENENO"
	.dexLang EN
	.dexText "WEEZING loves the gases given off by"
	.dexText "rotted kitchen garbage. This POKéMON"
	.dexText "will find a dirty, unkempt house and"
	.dexText "make it its home. At night, when the"
	.dexText "people in the house are asleep, it will"
	.dexText "go through the trash."
	.dexLang FR
	.dexText "SMOGOGO adore les gaz qui se dégagent"
	.dexText "des aliments pourris dans les poubelles."
	.dexText "Ce POKéMON cherche généralement"
	.dexText "les maisons sales et mal tenues pour y"
	.dexText "habiter. La nuit, quand tout le monde"
	.dexText "est endormi, il fouille les détritus."
	.dexLang DE
	.dexText "SMOGMOG liebt die Gase verrottender,"
	.dexText "fauler Küchenabfälle. Dieses POKéMON"
	.dexText "sucht sich ein vernachlässigtes,"
	.dexText "schmutziges Gebäude und richtet sich"
	.dexText "dort häuslich ein. Nachts, wenn die"
	.dexText "Menschen schlafen, wühlt es im Müll."
	.dexLang IT
	.dexText "WEEZING adora i gas emanati dai"
	.dexText "resti alimentari in decomposizione."
	.dexText "Si sente a suo agio in case sudicie"
	.dexText "e maltenute. La notte, mentre dormono"
	.dexText "tutti, lui si aggira furtivo tra i rifiuti"
	.dexText "domestici."
	.dexLang ES
	.dexText "A WEEZING le encantan los gases que"
	.dexText "emanan de los desperdicios que quedan"
	.dexText "en la cocina. Este POKéMON busca casas"
	.dexText "sucias y abandonadas para crear su"
	.dexText "hogar. De noche, cuando los habitantes"
	.dexText "de la casa duermen, va a por la basura."

	.align 2, 0
dexEntryEu110:: @ 110 SPOINK
	.2byte 1, 1, 0
	.2byte 10, 2, 0, 4, 10, 10, 0, 7  @ height
	.2byte 10, 10, 6, 7, 5, 10, 10, 3, 0, 6  @ weight
	.dexLang EN
	.dexName "SPOINK"
	.dexLang FR
	.dexName "SPOINK"
	.dexLang DE
	.dexName "SPOINK"
	.dexLang EN
	.dexCategory "BOUNCE"
	.dexLang FR
	.dexCategoryLeftAligned "REBOND"
	.dexLang DE
	.dexCategoryLeftAligned "SPRUNGFEDER"
	.dexLang IT
	.dexCategoryLeftAligned "MOLLA"
	.dexLang ES
	.dexCategoryLeftAligned "SALTARÍN"
	.dexLang EN
	.dexText "SPOINK bounces around on its tail."
	.dexText "The shock of its bouncing makes its"
	.dexText "heart pump. As a result, this POKéMON"
	.dexText "cannot afford to stop bouncing - if it"
	.dexText "stops, its heart will stop."
	.dexText ""
	.dexLang FR
	.dexText "SPOINK rebondit sur sa queue."
	.dexText "Le choc du rebond fait battre son cœur."
	.dexText "Du coup, ce POKéMON ne peut pas"
	.dexText "s`arrêter de rebondir, sinon,"
	.dexText "son cœur s`arrête."
	.dexText ""
	.dexLang DE
	.dexText "SPOINK hüpft auf seinem Schweif durch"
	.dexText "die Gegend. Die Erschütterung des"
	.dexText "Hüpfens bringt sein Herz zum Schlagen."
	.dexText "Deshalb kann dieses POKéMON das Hüpfen"
	.dexText "nicht sein lassen, ansonsten würde sein"
	.dexText "Herz aufhören zu schlagen."
	.dexLang IT
	.dexText "SPOINK rimbalza come una molla sulla"
	.dexText "coda. Il colpo ricevuto dal rimbalzo gli"
	.dexText "fa battere il cuore. Di conseguenza,"
	.dexText "non può mai smettere di saltellare,"
	.dexText "altrimenti il suo cuore smette"
	.dexText "di battere."
	.dexLang ES
	.dexText "SPOINK se pasa todo el día saltando"
	.dexText "sobre la cola. Con cada salto, hace latir"
	.dexText "el corazón. Por eso no puede permitirse"
	.dexText "dejar de saltar. Si lo hace, se le parará"
	.dexText "el corazón."
	.dexText ""

	.align 2, 0
dexEntryEu111:: @ 111 GRUMPIG
	.2byte 1, 1, 1
	.2byte 10, 2, 1, 1, 10, 10, 0, 9  @ height
	.2byte 10, 1, 5, 7, 6, 10, 10, 7, 1, 5  @ weight
	.dexLang EN
	.dexName "GRUMPIG"
	.dexLang FR
	.dexName "GRORET"
	.dexLang DE
	.dexName "GROINK"
	.dexLang EN
	.dexCategory "MANIPULATE"
	.dexLang FR
	.dexCategoryLeftAligned "MAGOUILLEUR"
	.dexLang DE
	.dexCategoryLeftAligned "MANIPULATOR"
	.dexLang IT
	.dexCategoryLeftAligned "RAGGIRO"
	.dexLang ES
	.dexCategoryLeftAligned "MANIPULADOR"
	.dexLang EN
	.dexText "GRUMPIG uses the black pearls on its"
	.dexText "body to amplify its psychic power waves"
	.dexText "for gaining total control over its foe."
	.dexText "When this POKéMON uses its special"
	.dexText "power, its snorting breath grows"
	.dexText "labored."
	.dexLang FR
	.dexText "GRORET utilise les perles noires"
	.dexText "situées sur son corps pour amplifier la"
	.dexText "puissance de ses ondes psychiques et"
	.dexText "prendre le contrôle de son ennemi. Quand"
	.dexText "il utilise son pouvoir spécial, ce"
	.dexText "POKéMON a du mal à respirer."
	.dexLang DE
	.dexText "GROINK benutzt die schwarzen Perlen"
	.dexText "an seinem Körper dazu, die"
	.dexText "psychischen Kraftwellen zu verstärken."
	.dexText "Wenn es diese spezielle Fähigkeit nutzt,"
	.dexText "wird sein schnaubender Atem"
	.dexText "schwerfällig."
	.dexLang IT
	.dexText "GRUMPIG usa le perle nere del suo corpo"
	.dexText "per amplificare le onde psichiche e"
	.dexText "acquisire il pieno controllo del nemico."
	.dexText "Quando usa i suoi speciali poteri,"
	.dexText "il suo respiro diventa affannoso."
	.dexText ""
	.dexLang ES
	.dexText "GRUMPIG usa las perlas negras que tiene"
	.dexText "para amplificar las ondas de su poder"
	.dexText "psíquico y controlar del todo al rival."
	.dexText "Cuando usa su poder especial,"
	.dexText "se le cansa la respiración y resopla"
	.dexText "con pesadez."

	.align 2, 0
dexEntryEu112:: @ 112 SANDSHREW
	.2byte 1, 1, 2
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 2, 6, 5, 10, 10, 1, 2, 0  @ weight
	.dexLang EN
	.dexName "SANDSHREW"
	.dexLang FR
	.dexName "SABELETTE"
	.dexLang DE
	.dexName "SANDAN"
	.dexLang EN
	.dexCategory "MOUSE"
	.dexLang FR
	.dexCategoryLeftAligned "SOURIS"
	.dexLang DE
	.dexCategoryLeftAligned "MAUS"
	.dexLang IT
	.dexCategoryLeftAligned "TOPO"
	.dexLang ES
	.dexCategoryLeftAligned "RATÓN"
	.dexLang EN
	.dexText "SANDSHREW has a very dry hide that is"
	.dexText "extremely tough. The POKéMON can roll"
	.dexText "into a ball that repels any attack."
	.dexText "At night, it burrows into the desert"
	.dexText "sand to sleep."
	.dexText ""
	.dexLang FR
	.dexText "SABELETTE a une peau très sèche et"
	.dexText "extrêmement dure. Ce POKéMON peut"
	.dexText "s`enrouler sur lui-même pour repousser"
	.dexText "les attaques. La nuit, il s`enterre dans"
	.dexText "le sable du désert pour dormir."
	.dexText ""
	.dexLang DE
	.dexText "SANDAN hat eine sehr trockene und"
	.dexText "extrem robuste Haut. Dieses POKéMON"
	.dexText "kann sich zu einem Ball zusammenrollen,"
	.dexText "von dem jegliche Angriffe abprallen."
	.dexText "Nachts gräbt es sich im Wüstensand ein"
	.dexText "und schläft dort."
	.dexLang IT
	.dexText "SANDSHREW ha una corazza estremamente"
	.dexText "secca e dura. Può chiudersi a sfera e"
	.dexText "rotolare per difendersi dagli attacchi."
	.dexText "Quando cala la notte, si nasconde"
	.dexText "nella sabbia del deserto per dormire."
	.dexText ""
	.dexLang ES
	.dexText "SANDSHREW tiene una piel muy seca y"
	.dexText "tremendamente dura. Tiene la habilidad"
	.dexText "de hacerse una bola y evitar cualquier"
	.dexText "ataque. Por las noches, escarba en la"
	.dexText "arena del desierto y se echa a dormir."
	.dexText ""

	.align 2, 0
dexEntryEu113:: @ 113 SANDSLASH
	.2byte 1, 1, 3
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 10, 6, 5, 0, 10, 10, 2, 9, 5  @ weight
	.dexLang EN
	.dexName "SANDSLASH"
	.dexLang FR
	.dexName "SABLAIREAU"
	.dexLang DE
	.dexName "SANDAMER"
	.dexLang EN
	.dexCategory "MOUSE"
	.dexLang FR
	.dexCategoryLeftAligned "SOURIS"
	.dexLang DE
	.dexCategoryLeftAligned "MAUS"
	.dexLang IT
	.dexCategoryLeftAligned "TOPO"
	.dexLang ES
	.dexCategoryLeftAligned "RATÓN"
	.dexLang EN
	.dexText "SANDSLASH can roll up its body as if it"
	.dexText "were a ball covered with large spikes."
	.dexText "In battle, this POKéMON will try to make"
	.dexText "the foe flinch by jabbing it with its"
	.dexText "spines. It then leaps at the stunned"
	.dexText "foe to tear wildly with its sharp claws."
	.dexLang FR
	.dexText "SABLAIREAU peut enrouler son corps"
	.dexText "pour prendre la forme d`une balle"
	.dexText "hérissée de pointes. Ce POKéMON"
	.dexText "essaie de faire peur à son ennemi en le"
	.dexText "frappant avec ses pointes. Puis, il se"
	.dexText "rue sur lui avec ses griffes acérées."
	.dexLang DE
	.dexText "SANDAMER kann sich zu einem Ball mit"
	.dexText "langen Stacheln zusammenrollen. Im"
	.dexText "Kampf schlägt es seine Gegner in die"
	.dexText "Flucht, indem es sie mit seinen Stacheln"
	.dexText "sticht. Dann springt es sie an und"
	.dexText "schlägt mit seinen scharfen Klauen zu."
	.dexLang IT
	.dexText "SANDSLASH arrotola il proprio corpo"
	.dexText "come fosse una sfera ricoperta di"
	.dexText "grandi aculei, che usa in lotta per far"
	.dexText "tentennare il nemico. Poi gli si scaglia"
	.dexText "contro per colpirlo selvaggiamente"
	.dexText "con gli artigli affilati."
	.dexLang ES
	.dexText "SANDSLASH se puede enroscar y"
	.dexText "convertirse en una bola de largas"
	.dexText "púas. En combate, este POKéMON"
	.dexText "hará lo posible por debilitar a su rival:"
	.dexText "le clavará las púas, se le acercará y"
	.dexText "le atacará con las afiladas garras."

	.align 2, 0
dexEntryEu114:: @ 114 SPINDA
	.2byte 1, 1, 4
	.2byte 10, 3, 0, 7, 10, 10, 1, 1  @ height
	.2byte 10, 10, 1, 1, 0, 10, 10, 10, 5, 0  @ weight
	.dexLang EN
	.dexName "SPINDA"
	.dexLang FR
	.dexName "SPINDA"
	.dexLang DE
	.dexName "PANDIR"
	.dexLang EN
	.dexCategory "SPOT PANDA"
	.dexLang FR
	.dexCategoryLeftAligned "PANDA TACHE"
	.dexLang DE
	.dexCategoryLeftAligned "PUNKT-PANDA"
	.dexLang IT
	.dexCategoryLeftAligned "MACCHIPANDA"
	.dexLang ES
	.dexCategoryLeftAligned "PANDA TOPOS"
	.dexLang EN
	.dexText "All the SPINDA that exist in the"
	.dexText "world are said to have utterly unique"
	.dexText "spot patterns."
	.dexText "The shaky, tottering steps of this"
	.dexText "POKéMON give it the appearance of"
	.dexText "dancing."
	.dexLang FR
	.dexText "On raconte que chaque SPINDA"
	.dexText "dispose d`un agencement de taches"
	.dexText "tout à fait unique."
	.dexText "La démarche chancelante et titubante"
	.dexText "de ce POKéMON donne l`impression"
	.dexText "qu`il danse."
	.dexLang DE
	.dexText "Jedes PANDIR auf der Welt soll ein"
	.dexText "einzigartiges Fleckenmuster haben. Der"
	.dexText "schwankende Gang dieses POKéMON"
	.dexText "erweckt den Eindruck, es würde tanzen."
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "Pare che ogni SPINDA esistente"
	.dexText "abbia un motivo maculato unico"
	.dexText "rispetto agli altri."
	.dexText "Il suo passo barcollante e malsicuro"
	.dexText "dà l`impressione che stia ballando."
	.dexText ""
	.dexLang ES
	.dexText "Dicen que no hay dos SPINDA que tengan"
	.dexText "los mismos dibujos en el pelaje."
	.dexText "Este POKéMON tiene una forma de andar"
	.dexText "inestable, va tambaleándose."
	.dexText "Da la sensación de ir bailando."
	.dexText ""

	.align 2, 0
dexEntryEu115:: @ 115 SKARMORY
	.2byte 1, 1, 5
	.2byte 10, 5, 0, 7, 10, 10, 1, 7  @ height
	.2byte 10, 1, 1, 1, 3, 10, 10, 5, 0, 5  @ weight
	.dexLang EN
	.dexName "SKARMORY"
	.dexLang FR
	.dexName "AIRMURE"
	.dexLang DE
	.dexName "PANZAERON"
	.dexLang EN
	.dexCategory "ARMOR BIRD"
	.dexLang FR
	.dexCategoryLeftAligned "ARMOISEAU"
	.dexLang DE
	.dexCategoryLeftAligned "FLUGSTAHL"
	.dexLang IT
	.dexCategoryLeftAligned "ARMUCCELLO"
	.dexLang ES
	.dexCategoryLeftAligned "CORAZA AVE"
	.dexLang EN
	.dexText "SKARMORY is entirely encased in hard,"
	.dexText "protective armor. This POKéMON flies at"
	.dexText "close to 190 mph."
	.dexText "It slashes foes with its wings that"
	.dexText "possess swordlike cutting edges."
	.dexText ""
	.dexLang FR
	.dexText "AIRMURE est entièrement recouvert"
	.dexText "d`une armure très dure. Ce POKéMON"
	.dexText "peut voler à plus de 300 km{4AC0}h."
	.dexText "Il peut mettre ses ennemis en pièces"
	.dexText "grâce à ses ailes tranchantes"
	.dexText "comme des sabres."
	.dexLang DE
	.dexText "PANZAERON ist komplett in einen harten,"
	.dexText "schützenden Panzer eingehüllt. Dieses"
	.dexText "POKéMON fliegt 300 km/h."
	.dexText "Es greift seine Feinde mit seinen"
	.dexText "messerscharfen Flügeln an."
	.dexText ""
	.dexLang IT
	.dexText "SKARMORY è interamente corazzato"
	.dexText "all`interno di una dura armatura di"
	.dexText "protezione."
	.dexText "Vola alla velocità di 300 km/h."
	.dexText "Lacera il nemico con le sue ali"
	.dexText "taglienti come la lama di una spada."
	.dexLang ES
	.dexText "SKARMORY está totalmente encerrado"
	.dexText "en el interior de una fuerte coraza"
	.dexText "protectora."
	.dexText "En vuelo, puede llegar a alcanzar los"
	.dexText "300 km por hora y usa las afiladas"
	.dexText "alas que tiene para azotar al rival."

	.align 2, 0
dexEntryEu116:: @ 116 TRAPINCH
	.2byte 1, 1, 6
	.2byte 10, 2, 0, 4, 10, 10, 0, 7  @ height
	.2byte 10, 10, 3, 3, 1, 10, 10, 1, 5, 0  @ weight
	.dexLang EN
	.dexName "TRAPINCH"
	.dexLang FR
	.dexName "KRAKNOIX"
	.dexLang DE
	.dexName "KNACKLION"
	.dexLang EN
	.dexCategory "ANT PIT"
	.dexLang FR
	.dexCategoryLeftAligned "PIEGEUR"
	.dexLang DE
	.dexCategoryLeftAligned "AMEISENLÖWE"
	.dexLang IT
	.dexCategoryLeftAligned "TRAPPOLA"
	.dexLang ES
	.dexCategoryLeftAligned "HORMIGALEÓN"
	.dexLang EN
	.dexText "TRAPINCH is a patient hunter. It digs"
	.dexText "an inescapable pit in a desert and waits"
	.dexText "for its prey to come tumbling down."
	.dexText "This POKéMON can go a whole week"
	.dexText "without access to any water."
	.dexText ""
	.dexLang FR
	.dexText "KRAKNOIX est un chasseur patient."
	.dexText "Dans le désert, il creuse un trou dont"
	.dexText "on ne peut pas s`échapper et attend"
	.dexText "que sa proie tombe dedans. Ce"
	.dexText "POKéMON peut se passer d`eau"
	.dexText "une semaine entière."
	.dexLang DE
	.dexText "KNACKLION ist ein geduldiger Jäger. Es"
	.dexText "gräbt in einer Wüste eine tiefe Grube"
	.dexText "und wartet auf Beute, die hineinfällt."
	.dexText "Dieses POKéMON kommt eine ganze Woche"
	.dexText "ohne Wasser aus."
	.dexText ""
	.dexLang IT
	.dexText "TRAPINCH è un paziente cacciatore. Nel"
	.dexText "deserto scava fosse micidiali e attende"
	.dexText "che la preda cada in trappola."
	.dexText "Questo POKéMON può vivere senz`acqua"
	.dexText "anche per una settimana."
	.dexText ""
	.dexLang ES
	.dexText "TRAPINCH es un cazador paciente."
	.dexText "Suele cavar una fosa profunda en el"
	.dexText "desierto y esperar a que su presa caiga"
	.dexText "en ella."
	.dexText "Este POKéMON puede aguantar toda"
	.dexText "una semana sin beber nada de agua."

	.align 2, 0
dexEntryEu117:: @ 117 VIBRAVA
	.2byte 1, 1, 7
	.2byte 10, 3, 0, 7, 10, 10, 1, 1  @ height
	.2byte 10, 10, 3, 3, 7, 10, 10, 1, 5, 3  @ weight
	.dexLang EN
	.dexName "VIBRAVA"
	.dexLang FR
	.dexName "VIBRANINF"
	.dexLang DE
	.dexName "VIBRAVA"
	.dexLang EN
	.dexCategory "VIBRATION"
	.dexLang FR
	.dexCategoryLeftAligned "VIBRATION"
	.dexLang DE
	.dexCategoryLeftAligned "VIBRATION"
	.dexLang IT
	.dexCategoryLeftAligned "VIBRAZIONE"
	.dexLang ES
	.dexCategoryLeftAligned "VIBRANTE"
	.dexLang EN
	.dexText "VIBRAVA`s wings have not yet"
	.dexText "completed the process of growing."
	.dexText "Rather than flying long distances,"
	.dexText "they are more useful for generating"
	.dexText "ultrasonic waves by vibrating."
	.dexText ""
	.dexLang FR
	.dexText "Les ailes de VIBRANINF n`ont pas"
	.dexText "complètement fini de pousser."
	.dexText "Elles ne lui servent pas à voler sur de"
	.dexText "longues distances, mais plutôt à"
	.dexText "générer des ultrasons en vibrant."
	.dexText ""
	.dexLang DE
	.dexText "VIBRAVAs Flügel sind noch nicht ganz"
	.dexText "ausgewachsen. Für lange Strecken sind"
	.dexText "seine Flügel weniger geeignet."
	.dexText "Aber es kann mit ihnen Ultraschallwellen"
	.dexText "erzeugen, wenn es sie vibrieren lässt."
	.dexText ""
	.dexLang IT
	.dexText "Le ali di VIBRAVA non hanno ancora"
	.dexText "completato il loro sviluppo. Più che"
	.dexText "per affrontare lunghe distanze,"
	.dexText "le utilizza per generare onde"
	.dexText "ultrasoniche facendole vibrare."
	.dexText ""
	.dexLang ES
	.dexText "VIBRAVA no ha desarrollado las alas"
	.dexText "del todo. Más que para volar y recorrer"
	.dexText "largas distancias, le resultan útiles"
	.dexText "para generar ondas ultrasónicas"
	.dexText "al hacer que vibren."
	.dexText ""

	.align 2, 0
dexEntryEu118:: @ 118 FLYGON
	.2byte 1, 1, 8
	.2byte 10, 6, 0, 7, 10, 10, 2, 0  @ height
	.2byte 10, 1, 8, 0, 8, 10, 10, 8, 2, 0  @ weight
	.dexLang EN
	.dexName "FLYGON"
	.dexLang FR
	.dexName "LIBEGON"
	.dexLang DE
	.dexName "LIBELLDRA"
	.dexLang EN
	.dexCategory "MYSTIC"
	.dexLang FR
	.dexCategoryLeftAligned "MYSTIQUE"
	.dexLang DE
	.dexCategoryLeftAligned "MYSTIK"
	.dexLang IT
	.dexCategoryLeftAligned "MAGICO"
	.dexLang ES
	.dexCategoryLeftAligned "MÍSTICO"
	.dexLang EN
	.dexText "FLYGON whips up a sandstorm by"
	.dexText "flapping its wings. The wings create a"
	.dexText "series of notes that sound like singing."
	.dexText "Because the “singing” is the only thing"
	.dexText "that can be heard in a sandstorm, this"
	.dexText "POKéMON is said to be the desert spirit."
	.dexLang FR
	.dexText "LIBEGON peut déclencher une"
	.dexText "tempête de sable en battant des ailes."
	.dexText "Les ailes créent une suite de notes"
	.dexText "ressemblant à une mélodie. Comme cette"
	.dexText "«mélodie» est le seul son audible, on"
	.dexText "appelle ce POKéMON l`esprit du désert."
	.dexLang DE
	.dexText "LIBELLDRA wirbelt einen Sandsturm auf,"
	.dexText "wenn es mit den Flügeln schlägt. Seine"
	.dexText "Flügel erzeugen dabei Töne, die wie"
	.dexText "Gesang klingen. Da dieser „Gesang“ das"
	.dexText "Einzige ist, was man in einem Sandsturm"
	.dexText "hört, wird es auch Wüstengeist genannt."
	.dexLang IT
	.dexText "FLYGON crea tempeste di sabbia"
	.dexText "agitando le ali, che emettono note"
	.dexText "musicali creando una sorta di canto."
	.dexText "Poiché questo “canto” è l`unica cosa"
	.dexText "udibile durante la tempesta, FLYGON"
	.dexText "è considerato lo spirito del deserto."
	.dexLang ES
	.dexText "FLYGON puede provocar una tormenta"
	.dexText "de arena batiendo las alas. Éstas,"
	.dexText "al ser agitadas, crean una melodía."
	.dexText "Y como las “melodías” pueden"
	.dexText "oírse cuando hay tormenta,"
	.dexText "dicen que es el espíritu del desierto."

	.align 2, 0
dexEntryEu119:: @ 119 CACNEA
	.2byte 1, 1, 9
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 1, 1, 3, 1, 10, 10, 5, 1, 3  @ weight
	.dexLang EN
	.dexName "CACNEA"
	.dexLang FR
	.dexName "CACNEA"
	.dexLang DE
	.dexName "TUSKA"
	.dexLang EN
	.dexCategory "CACTUS"
	.dexLang FR
	.dexCategoryLeftAligned "CACTUS"
	.dexLang DE
	.dexCategoryLeftAligned "KAKTUS"
	.dexLang IT
	.dexCategoryLeftAligned "CACTUS"
	.dexLang ES
	.dexCategoryLeftAligned "CACTUS"
	.dexLang EN
	.dexText "The more arid and harsh the"
	.dexText "environment, the more pretty and"
	.dexText "fragrant a flower CACNEA grows."
	.dexText "This POKéMON battles by wildly swinging"
	.dexText "its thorny arms."
	.dexText ""
	.dexLang FR
	.dexText "Si son environnement est aride et"
	.dexText "difficile, la fleur de CACNEA"
	.dexText "devient plus jolie et dégage un parfum"
	.dexText "délicat. Ce POKéMON se bat en"
	.dexText "agitant ses bras épineux."
	.dexText ""
	.dexLang DE
	.dexText "Je trockener und trostloser seine"
	.dexText "Umgebung ist, desto schöner und"
	.dexText "duftender wird TUSKAs Blume."
	.dexText "Dieses POKéMON schwingt im Kampf wild"
	.dexText "mit seinen dornigen Armen."
	.dexText ""
	.dexLang IT
	.dexText "Quanto più arido e aspro è"
	.dexText "l`ambiente, tanto più rigoglioso"
	.dexText "cresce il fiore di CACNEA."
	.dexText "Il POKéMON lotta agitando furiosamente"
	.dexText "gli spinosi arti superiori."
	.dexText ""
	.dexLang ES
	.dexText "Cuanto más árido y hostil sea el hábitat"
	.dexText "de CACNEA, más bonita y aromática será"
	.dexText "la flor que le crece."
	.dexText "Este POKéMON lucha agitando"
	.dexText "violentamente los brazos cargados"
	.dexText "de pinchos que tiene."

	.align 2, 0
dexEntryEu120:: @ 120 CACTURNE
	.2byte 1, 2, 0
	.2byte 10, 4, 0, 3, 10, 10, 1, 3  @ height
	.2byte 10, 1, 7, 0, 6, 10, 10, 7, 7, 4  @ weight
	.dexLang EN
	.dexName "CACTURNE"
	.dexLang FR
	.dexName "CACTURNE"
	.dexLang DE
	.dexName "NOKTUSKA"
	.dexLang EN
	.dexCategory "SCARECROW"
	.dexLang FR
	.dexCategoryLeftAligned "EPOUVANTAIL"
	.dexLang DE
	.dexCategoryLeftAligned "VOGELSCHOCK"
	.dexLang IT
	.dexCategoryLeftAligned "SPAVENTO"
	.dexLang ES
	.dexCategoryLeftAligned "ESPANTAJO"
	.dexLang EN
	.dexText "If a traveler is going through a desert"
	.dexText "in the thick of night, CACTURNE"
	.dexText "will follow in a ragtag group."
	.dexText "The POKéMON are biding their time,"
	.dexText "waiting for the traveler to tire and"
	.dexText "become incapable of moving."
	.dexLang FR
	.dexText "Lorsqu`un voyageur traverse le désert"
	.dexText "au milieu de la nuit, les CACTURNE le"
	.dexText "suivent en groupe."
	.dexText "Ces POKéMON attendent le bon moment,"
	.dexText "quand le voyageur est fatigué et qu`il"
	.dexText "n`est plus capable de bouger."
	.dexLang DE
	.dexText "Wenn ein Reisender mitten in der Nacht"
	.dexText "durch eine Wüste wandert, folgt"
	.dexText "NOKTUSKA ihm und spielt ihm Streiche."
	.dexText "Dann wartet dieses POKéMON darauf,"
	.dexText "dass der Reisende müde wird und sich"
	.dexText "nicht mehr bewegen kann."
	.dexLang IT
	.dexText "Se un viaggiatore passa attraverso"
	.dexText "il deserto nella notte tenebrosa, un"
	.dexText "gruppo scomposto di CACTURNE lo segue."
	.dexText "Poi attende pazientemente che il"
	.dexText "malcapitato sia esausto e incapace"
	.dexText "di muoversi."
	.dexLang ES
	.dexText "Si te adentras en un desierto por la"
	.dexText "noche, CACTURNE te seguirá junto"
	.dexText "con varios de los suyos."
	.dexText "Este POKéMON espera pacientemente"
	.dexText "a que el viajero se canse y no pueda"
	.dexText "continuar más, vencido por el cansancio."

	.align 2, 0
dexEntryEu121:: @ 121 SWABLU
	.2byte 1, 2, 1
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 10, 2, 6, 10, 10, 10, 1, 2  @ weight
	.dexLang EN
	.dexName "SWABLU"
	.dexLang FR
	.dexName "TYLTON"
	.dexLang DE
	.dexName "WABLU"
	.dexLang EN
	.dexCategory "COTTON BIRD"
	.dexLang FR
	.dexCategoryLeftAligned "OISEAUCOTON"
	.dexLang DE
	.dexCategoryLeftAligned "WOLLVOGEL"
	.dexLang IT
	.dexCategoryLeftAligned "ALIDICOTONE"
	.dexLang ES
	.dexCategoryLeftAligned "AVE ALGODÓN"
	.dexLang EN
	.dexText "SWABLU loves to make things clean."
	.dexText "If it spots something dirty, it will wipe"
	.dexText "and polish it with its cottony wings."
	.dexText "If its wings become dirty, this POKéMON"
	.dexText "finds a stream and showers itself."
	.dexText ""
	.dexLang FR
	.dexText "TYLTON adore nettoyer. S`il"
	.dexText "repère quelque chose de sale, il l`essuie"
	.dexText "et le polit avec ses ailes cotonneuses."
	.dexText "Lorsque ses ailes se salissent, ce"
	.dexText "POKéMON trouve un cours d`eau"
	.dexText "et se lave."
	.dexLang DE
	.dexText "WABLU liebt es, Dinge zu putzen. Wenn"
	.dexText "es etwas Schmutziges bemerkt, fängt"
	.dexText "es an, dieses mit seinen weichen"
	.dexText "Flügeln zu putzen. Wenn seine Flügel"
	.dexText "dreckig werden, sucht sich dieses"
	.dexText "POKéMON einen Fluss und duscht sich ab."
	.dexLang IT
	.dexText "SWABLU ama la pulizia. Se vede"
	.dexText "qualcosa di sporco, inizia a pulire"
	.dexText "meticolosamente con le sue ali"
	.dexText "di cotone. Se poi le ali si sporcano,"
	.dexText "il POKéMON cerca un corso d`acqua"
	.dexText "per lavarsi."
	.dexLang ES
	.dexText "A SWABLU le encanta limpiarlo todo."
	.dexText "Si ve algo sucio, lo dejará como nuevo"
	.dexText "y reluciente con las alas de algodón"
	.dexText "que tiene. Cuando se le ensucian,"
	.dexText "busca un manantial y las limpia."
	.dexText ""

	.align 2, 0
dexEntryEu122:: @ 122 ALTARIA
	.2byte 1, 2, 2
	.2byte 10, 3, 0, 7, 10, 10, 1, 1  @ height
	.2byte 10, 10, 4, 5, 4, 10, 10, 2, 0, 6  @ weight
	.dexLang EN
	.dexName "ALTARIA"
	.dexLang FR
	.dexName "ALTARIA"
	.dexLang DE
	.dexName "ALTARIA"
	.dexLang EN
	.dexCategory "HUMMING"
	.dexLang FR
	.dexCategoryLeftAligned "VIREVOLTEUR"
	.dexLang DE
	.dexCategoryLeftAligned "SUMMSEL"
	.dexLang IT
	.dexCategoryLeftAligned "CANTERINO"
	.dexLang ES
	.dexCategoryLeftAligned "CANTOR"
	.dexLang EN
	.dexText "ALTARIA sings in a gorgeous soprano."
	.dexText "Its wings are like cotton clouds."
	.dexText "This POKéMON catches updrafts with its"
	.dexText "buoyant wings and soars way up into"
	.dexText "the wild blue yonder."
	.dexText ""
	.dexLang FR
	.dexText "ALTARIA chante avec une"
	.dexText "magnifique voix de soprano. Ses ailes"
	.dexText "ressemblent à des nuages cotonneux."
	.dexText "Ce POKéMON se laisse porter par les"
	.dexText "courants d`air ascendants et disparaît"
	.dexText "dans le bleu du ciel."
	.dexLang DE
	.dexText "ALTARIA hat eine tolle Sopran-Stimme."
	.dexText "Seine Flügel sehen aus wie Schäfchen-"
	.dexText "wolken. Dieses POKéMON stürzt sich"
	.dexText "in einen Aufwind und steigt in den"
	.dexText "Himmel empor."
	.dexText ""
	.dexLang IT
	.dexText "ALTARIA canta con una sublime voce"
	.dexText "di soprano. Le sue ali spumeggianti,"
	.dexText "che sembrano nubi di cotone, gli"
	.dexText "consentono di sfruttare le correnti"
	.dexText "ascensionali e di risalire verso"
	.dexText "l`infinito cielo blu."
	.dexLang ES
	.dexText "ALTARIA es una excelente soprano."
	.dexText "Tiene unas alas que parecen nubes de"
	.dexText "algodón. Este POKéMON aprovecha las"
	.dexText "corrientes ascendentes y remonta el"
	.dexText "vuelo con sus flamantes alas hacia la"
	.dexText "inmensidad del cielo azul."

	.align 2, 0
dexEntryEu123:: @ 123 ZANGOOSE
	.2byte 1, 2, 3
	.2byte 10, 4, 0, 3, 10, 10, 1, 3  @ height
	.2byte 10, 10, 8, 8, 8, 10, 10, 4, 0, 3  @ weight
	.dexLang EN
	.dexName "ZANGOOSE"
	.dexLang FR
	.dexName "MANGRIFF"
	.dexLang DE
	.dexName "SENGO"
	.dexLang EN
	.dexCategory "CAT FERRET"
	.dexLang FR
	.dexCategoryLeftAligned "CHAT FURET"
	.dexLang DE
	.dexCategoryLeftAligned "FRETTKATZ"
	.dexLang IT
	.dexCategoryLeftAligned "FUROGATTO"
	.dexLang ES
	.dexCategoryLeftAligned "GATO HURÓN"
	.dexLang EN
	.dexText "Memories of battling its arch-rival"
	.dexText "SEVIPER are etched into every cell of"
	.dexText "ZANGOOSE`s body."
	.dexText "This POKéMON adroitly dodges attacks"
	.dexText "with incredible agility."
	.dexText ""
	.dexLang FR
	.dexText "Chaque cellule du corps de MANGRIFF"
	.dexText "porte les stigmates de sa rivalité avec"
	.dexText "SEVIPER."
	.dexText "Ce POKéMON est capable d`esquiver les"
	.dexText "attaques avec une agilité incroyable."
	.dexText ""
	.dexLang DE
	.dexText "Die Erinnerungen an den Kampf mit"
	.dexText "seinem Erzrivalen VIPITIS haben sich in"
	.dexText "jede Zelle von SENGOs Körper"
	.dexText "eingebrannt. Dieses POKéMON weicht"
	.dexText "feindlichen Angriffen unheimlich"
	.dexText "raffiniert und geschickt aus."
	.dexLang IT
	.dexText "I ricordi delle lotte contro il suo"
	.dexText "acerrimo nemico SEVIPER sono insiti"
	.dexText "in ogni cellula del corpo di ZANGOOSE."
	.dexText "Questo POKéMON riesce a schivare"
	.dexText "gli attacchi con incredibile maestria."
	.dexText ""
	.dexLang ES
	.dexText "Los ecos del combate mantenido con su"
	.dexText "rival más feroz, SEVIPER, resuenan aún"
	.dexText "en cada célula de ZANGOOSE."
	.dexText "Este POKéMON esquiva los ataques"
	.dexText "con auténtica destreza."
	.dexText ""

	.align 2, 0
dexEntryEu124:: @ 124 SEVIPER
	.2byte 1, 2, 4
	.2byte 10, 8, 1, 0, 10, 10, 2, 7  @ height
	.2byte 10, 1, 1, 5, 7, 10, 10, 5, 2, 5  @ weight
	.dexLang EN
	.dexName "SEVIPER"
	.dexLang FR
	.dexName "SEVIPER"
	.dexLang DE
	.dexName "VIPITIS"
	.dexLang EN
	.dexCategory "FANG SNAKE"
	.dexLang FR
	.dexCategoryLeftAligned "SERPACROC"
	.dexLang DE
	.dexCategoryLeftAligned "REISSZAHN"
	.dexLang IT
	.dexCategoryLeftAligned "ZANNASERPE"
	.dexLang ES
	.dexCategoryLeftAligned "COLMILLOS"
	.dexLang EN
	.dexText "SEVIPER`s swordlike tail serves two"
	.dexText "purposes - it slashes foes and douses"
	.dexText "them with secreted poison."
	.dexText "This POKéMON will not give up its long-"
	.dexText "running blood feud with ZANGOOSE."
	.dexText ""
	.dexLang FR
	.dexText "La queue tranchante comme un sabre de"
	.dexText "SEVIPER a deux fonctions : elle peut"
	.dexText "frapper l`ennemi et lui injecter un"
	.dexText "poison qu`il sécrète. Ce POKéMON"
	.dexText "n`oublie jamais sa vieille rancune"
	.dexText "envers MANGRIFF."
	.dexLang DE
	.dexText "VIPITIS kann mit seinem Schweif"
	.dexText "Feinden einen Hieb versetzen und sie"
	.dexText "mit einem abgesonderten Gift"
	.dexText "bespritzen. Dieses POKéMON wird in der"
	.dexText "langwährenden Blutsfehde mit SENGO"
	.dexText "nicht nachgeben."
	.dexLang IT
	.dexText "La coda a forma di spada di SEVIPER"
	.dexText "ha una duplice funzione: lacera il nemico"
	.dexText "e gli inietta un potente veleno."
	.dexText "Il POKéMON non dimentica mai"
	.dexText "le lotte con il suo secolare"
	.dexText "nemico, ZANGOOSE."
	.dexLang ES
	.dexText "SEVIPER tiene una cola que parece"
	.dexText "una espada y le sirve para dar un"
	.dexText "sablazo al enemigo y para envenenarlo."
	.dexText "Este POKéMON se mantiene firme en la"
	.dexText "enemistad que siente hacia ZANGOOSE."
	.dexText ""

	.align 2, 0
dexEntryEu125:: @ 125 LUNATONE
	.2byte 1, 2, 5
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 3, 7, 0, 4, 10, 1, 6, 8, 0  @ weight
	.dexLang EN
	.dexName "LUNATONE"
	.dexLang FR
	.dexName "SELEROC"
	.dexLang DE
	.dexName "LUNASTEIN"
	.dexLang EN
	.dexCategory "METEORITE"
	.dexLang FR
	.dexCategoryLeftAligned "METEORITE"
	.dexLang DE
	.dexCategoryLeftAligned "METEORIT"
	.dexLang IT
	.dexCategoryLeftAligned "METEORITE"
	.dexLang ES
	.dexCategoryLeftAligned "METEORITO"
	.dexLang EN
	.dexText "LUNATONE becomes active around the"
	.dexText "time of the full moon. Instead of"
	.dexText "walking, it moves by floating in midair."
	.dexText "The POKéMON`s intimidating red eyes"
	.dexText "cause all those who see it to become"
	.dexText "transfixed with fear."
	.dexLang FR
	.dexText "SELEROC ne s`active que pendant la"
	.dexText "période de pleine lune. Il ne marche"
	.dexText "pas, mais se déplace en lévitant."
	.dexText "Les yeux rouges et intimidants de ce"
	.dexText "POKéMON pétrifient ses ennemis"
	.dexText "de terreur."
	.dexLang DE
	.dexText "LUNASTEIN wird bei Vollmond aktiv."
	.dexText "Es läuft nicht, sondern schwebt"
	.dexText "durch die Luft."
	.dexText "Die bedrohlichen roten Augen dieses"
	.dexText "POKéMON lassen alle, die es sehen,"
	.dexText "vor Angst erstarren."
	.dexLang IT
	.dexText "LUNATONE si desta quando domina"
	.dexText "la luna piena. Invece di camminare,"
	.dexText "fluttua a mezz`aria."
	.dexText "I suoi occhi rossi così minacciosi"
	.dexText "terrorizzano chiunque li guardi."
	.dexText ""
	.dexLang ES
	.dexText "LUNATONE entra en actividad en épocas"
	.dexText "de luna llena más o menos. No camina,"
	.dexText "se desplaza flotando por el aire."
	.dexText "Tiene unos ojos rojos sobrecogedores"
	.dexText "que cortan la respiración a todo aquel"
	.dexText "que los ve."

	.align 2, 0
dexEntryEu126:: @ 126 SOLROCK
	.2byte 1, 2, 6
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 3, 3, 9, 5, 10, 1, 5, 4, 0  @ weight
	.dexLang EN
	.dexName "SOLROCK"
	.dexLang FR
	.dexName "SOLAROC"
	.dexLang DE
	.dexName "SONNFEL"
	.dexLang EN
	.dexCategory "METEORITE"
	.dexLang FR
	.dexCategoryLeftAligned "METEORITE"
	.dexLang DE
	.dexCategoryLeftAligned "METEORIT"
	.dexLang IT
	.dexCategoryLeftAligned "METEORITE"
	.dexLang ES
	.dexCategoryLeftAligned "METEORITO"
	.dexLang EN
	.dexText "SOLROCK is a new species of POKéMON"
	.dexText "that is said to have fallen from space."
	.dexText "It floats in air and moves silently."
	.dexText "In battle, this POKéMON releases"
	.dexText "intensely bright light."
	.dexText ""
	.dexLang FR
	.dexText "SOLAROC est une nouvelle espèce"
	.dexText "de POKéMON. On raconte qu`il serait"
	.dexText "tombé de l`espace. Il flotte dans les"
	.dexText "airs et se déplace silencieusement. Au"
	.dexText "combat, ce POKéMON libère une lumière"
	.dexText "intense."
	.dexLang DE
	.dexText "SONNFEL ist eine neue POKéMON-Spezies,"
	.dexText "die angeblich aus dem Weltall"
	.dexText "kam. Es gleitet durch die"
	.dexText "Luft und bewegt sich leise. Im Kampf"
	.dexText "setzt dieses POKéMON sehr helles Licht"
	.dexText "ein."
	.dexLang IT
	.dexText "SOLROCK è una nuova specie di POKéMON"
	.dexText "che pare sia precipitata dallo spazio."
	.dexText "Fluttua a mezz`aria spostandosi"
	.dexText "silenziosamente. In lotta emana"
	.dexText "una luce estremamente intensa."
	.dexText ""
	.dexLang ES
	.dexText "SOLROCK pertenece a una nueva especie"
	.dexText "de POKéMON a la que se le atribuye una"
	.dexText "procedencia extraterrestre."
	.dexText "Este POKéMON permanece flotando en el"
	.dexText "aire y se mueve muy despacio. Al luchar,"
	.dexText "desprende una luz viva e intensa."

	.align 2, 0
dexEntryEu127:: @ 127 BARBOACH
	.2byte 1, 2, 7
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 10, 4, 2, 10, 10, 10, 1, 9  @ weight
	.dexLang EN
	.dexName "BARBOACH"
	.dexLang FR
	.dexName "BARLOCHE"
	.dexLang DE
	.dexName "SCHMERBE"
	.dexLang EN
	.dexCategory "WHISKERS"
	.dexLang FR
	.dexCategoryLeftAligned "BARBILLON"
	.dexLang DE
	.dexCategoryLeftAligned "BARTHAAR"
	.dexLang IT
	.dexCategoryLeftAligned "BAFFETTI"
	.dexLang ES
	.dexCategoryLeftAligned "BIGOTUDO"
	.dexLang EN
	.dexText "BARBOACH`s body is covered with a"
	.dexText "slimy film. If a foe grabs it, this"
	.dexText "POKéMON just slips out of the enemy`s"
	.dexText "grip."
	.dexText "This POKéMON grows weak if the slimy"
	.dexText "coating dries up."
	.dexLang FR
	.dexText "Le corps de BARLOCHE est couvert"
	.dexText "d`un voile visqueux. Lorsqu`un ennemi"
	.dexText "l`attrape, ce POKéMON peut se glisser"
	.dexText "hors de son étreinte. Il s`affaiblit"
	.dexText "quand la pellicule visqueuse"
	.dexText "de son corps s`assèche."
	.dexLang DE
	.dexText "SCHMERBEs Körper ist mit einem"
	.dexText "schleimigen Film bedeckt. Wenn ein"
	.dexText "Gegner es packen will, entgeht es"
	.dexText "seinem Griff. Dieses POKéMON wird"
	.dexText "geschwächt, wenn sein schleimiger"
	.dexText "Überzug austrocknet."
	.dexLang IT
	.dexText "Il corpo di BARBOACH è coperto da"
	.dexText "una pellicola viscida. Se un nemico"
	.dexText "cerca di afferrarlo, il POKéMON"
	.dexText "gli scivola via dalle grinfie."
	.dexText "Se la pellicola viscida si secca,"
	.dexText "BARBOACH si indebolisce."
	.dexLang ES
	.dexText "BARBOACH está completamente"
	.dexText "recubierto por una película viscosa. Si"
	.dexText "lo atrapan, puede escurrirse fácilmente."
	.dexText "Si se le seca la capa viscosa,"
	.dexText "este POKéMON se debilitará."
	.dexText ""

	.align 2, 0
dexEntryEu128:: @ 128 WHISCASH
	.2byte 1, 2, 8
	.2byte 10, 2, 1, 1, 10, 10, 0, 9  @ height
	.2byte 10, 10, 5, 2, 0, 10, 10, 2, 3, 6  @ weight
	.dexLang EN
	.dexName "WHISCASH"
	.dexLang FR
	.dexName "BARBICHA"
	.dexLang DE
	.dexName "WELSAR"
	.dexLang EN
	.dexCategory "WHISKERS"
	.dexLang FR
	.dexCategoryLeftAligned "BARBILLON"
	.dexLang DE
	.dexCategoryLeftAligned "BARTHAAR"
	.dexLang IT
	.dexCategoryLeftAligned "BAFFETTI"
	.dexLang ES
	.dexCategoryLeftAligned "BIGOTUDO"
	.dexLang EN
	.dexText "If WHISCASH goes on a wild rampage,"
	.dexText "it sets off a quake-like tremor with a"
	.dexText "radius of over three miles."
	.dexText "This POKéMON has the ability to predict"
	.dexText "real earthquakes."
	.dexText ""
	.dexLang FR
	.dexText "Lorsque BARBICHA se déchaîne, il"
	.dexText "déclenche des secousses sismiques"
	.dexText "dans un rayon de plus de 5 km"
	.dexText "autour de lui."
	.dexText "Ce POKéMON a le pouvoir de prédire"
	.dexText "les véritables tremblements de terre."
	.dexLang DE
	.dexText "Wenn WELSAR auf einen wilden Beute-"
	.dexText "zug geht, erzeugt es ein Beben mit"
	.dexText "einem Radius von 5 Kilometern."
	.dexText "Dieses POKéMON kann wirkliche Erdbeben"
	.dexText "voraussehen."
	.dexText ""
	.dexLang IT
	.dexText "Se WHISCASH si infuria, è in grado"
	.dexText "di scatenare una specie di terremoto"
	.dexText "del raggio di 5 km."
	.dexText "Inoltre ha la capacità di"
	.dexText "prevedere i terremoti reali."
	.dexText ""
	.dexLang ES
	.dexText "Si WHISCASH entra en estado de cólera"
	.dexText "salvaje, provoca un temblor sísmico"
	.dexText "de un radio de cinco kilómetros."
	.dexText "Este POKéMON tiene la habilidad de"
	.dexText "predecir terremotos de verdad."
	.dexText ""

	.align 2, 0
dexEntryEu129:: @ 129 CORPHISH
	.2byte 1, 2, 9
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 2, 5, 4, 10, 10, 1, 1, 5  @ weight
	.dexLang EN
	.dexName "CORPHISH"
	.dexLang FR
	.dexName "ECRAPINCE"
	.dexLang DE
	.dexName "KREBSCORPS"
	.dexLang EN
	.dexCategory "RUFFIAN"
	.dexLang FR
	.dexCategoryLeftAligned "BRUTE"
	.dexLang DE
	.dexCategoryLeftAligned "GROBIAN"
	.dexLang IT
	.dexCategoryLeftAligned "BIRBONE"
	.dexLang ES
	.dexCategoryLeftAligned "RUFIÁN"
	.dexLang EN
	.dexText "CORPHISH catches prey with its sharp"
	.dexText "claws. It has no likes or dislikes when it"
	.dexText "comes to food - it will eat anything."
	.dexText "This POKéMON has no trouble living in"
	.dexText "filthy water."
	.dexText ""
	.dexLang FR
	.dexText "ECRAPINCE attrape ses proies avec"
	.dexText "ses puissantes pinces. Pour la"
	.dexText "nourriture, il n`est pas difficile."
	.dexText "Il mange de tout. Vivre dans de l`eau"
	.dexText "sale ne dérange pas ce POKéMON."
	.dexText ""
	.dexLang DE
	.dexText "KREBSCORPS fängt seine Beute mit"
	.dexText "seinen scharfen Krallen. Es hat keine"
	.dexText "besonderen Ansprüche an seine"
	.dexText "Nahrung, es frisst einfach alles."
	.dexText "Dieses POKéMON lebt gern in"
	.dexText "schmutzigem Wasser."
	.dexLang IT
	.dexText "CORPHISH cattura la preda con"
	.dexText "i suoi artigli affilati. Non ha esigenze"
	.dexText "particolari riguardo al cibo, infatti"
	.dexText "mangia di tutto. Riesce a vivere"
	.dexText "anche in acque molto inquinate."
	.dexText ""
	.dexLang ES
	.dexText "CORPHISH atrapa a su presa con finas"
	.dexText "pinzas. En lo referente a comida no es"
	.dexText "delicado; se come lo que sea."
	.dexText "Tampoco tiene ningún problema en vivir"
	.dexText "en aguas sucias."
	.dexText ""

	.align 2, 0
dexEntryEu130:: @ 130 CRAWDAUNT
	.2byte 1, 3, 0
	.2byte 10, 3, 0, 7, 10, 10, 1, 1  @ height
	.2byte 10, 10, 7, 2, 3, 10, 10, 3, 2, 8  @ weight
	.dexLang EN
	.dexName "CRAWDAUNT"
	.dexLang FR
	.dexName "COLHOMARD"
	.dexLang DE
	.dexName "KREBUTACK"
	.dexLang EN
	.dexCategory "ROGUE"
	.dexLang FR
	.dexCategoryLeftAligned "CRAPULE"
	.dexLang DE
	.dexCategoryLeftAligned "SCHLINGEL"
	.dexLang IT
	.dexCategoryLeftAligned "CANAGLIA"
	.dexLang ES
	.dexCategoryLeftAligned "GRANUJA"
	.dexLang EN
	.dexText "CRAWDAUNT molts (sheds) its shell"
	.dexText "regularly. Immediately after molting,"
	.dexText "its shell is soft and tender."
	.dexText "Until the shell hardens, this POKéMON"
	.dexText "hides in its streambed burrow to avoid"
	.dexText "attack from its foes."
	.dexLang FR
	.dexText "COLHOMARD mue et perd sa carapace"
	.dexText "régulièrement. Immédiatement après sa"
	.dexText "mue, sa nouvelle carapace est tendre"
	.dexText "et molle. Il s`enterre au fond des cours"
	.dexText "d`eau pour ne pas être attaqué avant"
	.dexText "que sa carapace ne soit assez dure."
	.dexLang DE
	.dexText "KREBUTACK legt seine Schale regelmäßig"
	.dexText "ab. Direkt danach ist seine Schale weich"
	.dexText "und empfindlich. Bis sie gehärtet"
	.dexText "ist, sucht es sich ein Versteck in einem"
	.dexText "Flussbett, damit es nicht von Gegnern"
	.dexText "angegriffen wird."
	.dexLang IT
	.dexText "CRAWDAUNT muta regolarmente la"
	.dexText "corazza. Subito dopo la muta, la"
	.dexText "nuova corazza è tenera e delicata."
	.dexText "Finché non si è indurita totalmente,"
	.dexText "il POKéMON vive nascosto nella sua"
	.dexText "tana sott`acqua per evitare attacchi."
	.dexLang ES
	.dexText "CRAWDAUNT muda el caparazón"
	.dexText "regularmente y, en cuanto lo hace,"
	.dexText "se le queda la piel tersa y suave."
	.dexText "Mientras el nuevo caparazón se"
	.dexText "endurece, permanece escondido en"
	.dexText "su madriguera para que no le ataquen."

	.align 2, 0
dexEntryEu131:: @ 131 BALTOY
	.2byte 1, 3, 1
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 4, 7, 4, 10, 10, 2, 1, 5  @ weight
	.dexLang EN
	.dexName "BALTOY"
	.dexLang FR
	.dexName "BALBUTO"
	.dexLang DE
	.dexName "PUPPANCE"
	.dexLang EN
	.dexCategory "CLAY DOLL"
	.dexLang FR
	.dexCategoryLeftAligned "POUPARGILE"
	.dexLang DE
	.dexCategoryLeftAligned "LEHMPUPPE"
	.dexLang IT
	.dexCategoryLeftAligned "ARGILLA"
	.dexLang ES
	.dexCategoryLeftAligned "MUÑ{39E6}BARRO"
	.dexLang EN
	.dexText "As soon as it spots others of its kind,"
	.dexText "BALTOY congregates with them and"
	.dexText "then begins crying noisily in unison."
	.dexText "This POKéMON sleeps while cleverly"
	.dexText "balancing itself on its one foot."
	.dexText ""
	.dexLang FR
	.dexText "Dès qu`il repère ses congénères,"
	.dexText "BALBUTO les rejoint et ils se"
	.dexText "mettent tous à crier en choeur."
	.dexText "Ce POKéMON arrive à dormir en"
	.dexText "restant adroitement en équilibre."
	.dexText ""
	.dexLang DE
	.dexText "Sobald es Artgenossen bemerkt, tut"
	.dexText "sich PUPPANCE mit ihnen zusammen und"
	.dexText "sie brüllen gemeinsam. Dieses POKéMON"
	.dexText "schläft, während es geschickt auf"
	.dexText "seinem Fuß balanciert."
	.dexText ""
	.dexLang IT
	.dexText "Appena incontra i propri simili,"
	.dexText "BALTOY forma un gruppo molto"
	.dexText "rumoroso."
	.dexText "Questo POKéMON dorme bilanciandosi"
	.dexText "con maestria sull`unica estremità"
	.dexText "inferiore del proprio corpo."
	.dexLang ES
	.dexText "Al ver a más de los suyos, BALTOY"
	.dexText "se une al grupo y todos se ponen a"
	.dexText "chillar escandalosamente y al unísono."
	.dexText "Este POKéMON duerme manteniendo"
	.dexText "hábilmente el equilibrio sobre"
	.dexText "la extremidad inferior que tiene."

	.align 2, 0
dexEntryEu132:: @ 132 CLAYDOL
	.2byte 1, 3, 2
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 2, 3, 8, 1, 10, 1, 0, 8, 0  @ weight
	.dexLang EN
	.dexName "CLAYDOL"
	.dexLang FR
	.dexName "KAORINE"
	.dexLang DE
	.dexName "LEPUMENTAS"
	.dexLang EN
	.dexCategory "CLAY DOLL"
	.dexLang FR
	.dexCategoryLeftAligned "POUPARGILE"
	.dexLang DE
	.dexCategoryLeftAligned "LEHMPUPPE"
	.dexLang IT
	.dexCategoryLeftAligned "ARGILLA"
	.dexLang ES
	.dexCategoryLeftAligned "MUÑ{39E6}BARRO"
	.dexLang EN
	.dexText "CLAYDOL is an enigma that appeared"
	.dexText "from a clay statue made by an ancient"
	.dexText "civilization dating back 20,000 years."
	.dexText "This POKéMON shoots beams from both"
	.dexText "its hands."
	.dexText ""
	.dexLang FR
	.dexText "KAORINE est un mystérieux POKéMON"
	.dexText "apparu sous la forme d`une statue en"
	.dexText "argile fabriquée par une civilisation"
	.dexText "vieille de plus de 20 000 ans. Ce POKéMON"
	.dexText "envoie des rayons avec ses mains."
	.dexText ""
	.dexLang DE
	.dexText "LEPUMENTAS ist ein Rätsel um eine Ton-"
	.dexText "statue, die vor 20.000 Jahren von einer"
	.dexText "antiken Zivilisation geschaffen wurde."
	.dexText "Dieses POKéMON verschießt Strahlen aus"
	.dexText "beiden Händen."
	.dexText ""
	.dexLang IT
	.dexText "CLAYDOL rimane ancora un mistero:"
	.dexText "comparve da una statua d`argilla creata"
	.dexText "da un popolo antico 20.000 anni fa."
	.dexText "Questo POKéMON emette radiazioni"
	.dexText "dai propri arti superiori."
	.dexText ""
	.dexLang ES
	.dexText "CLAYDOL es un enigma, una figura de"
	.dexText "barro procedente de una civilización"
	.dexText "antigua de hace más de 20.000 años."
	.dexText "Este POKéMON dispara rayos por las"
	.dexText "manos."
	.dexText ""

	.align 2, 0
dexEntryEu133:: @ 133 LILEEP
	.2byte 1, 3, 3
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 10, 5, 2, 5, 10, 10, 2, 3, 8  @ weight
	.dexLang EN
	.dexName "LILEEP"
	.dexLang FR
	.dexName "LILIA"
	.dexLang DE
	.dexName "LILIEP"
	.dexLang EN
	.dexCategory "SEA LILY"
	.dexLang FR
	.dexCategoryLeftAligned "LIS D`EAU"
	.dexLang DE
	.dexCategoryLeftAligned "SEEANEMONE"
	.dexLang IT
	.dexCategoryLeftAligned "FIORDIMARE"
	.dexLang ES
	.dexCategoryLeftAligned "LILA MAR"
	.dexLang EN
	.dexText "LILEEP became extinct approximately"
	.dexText "a hundred million years ago."
	.dexText "This ancient POKéMON attaches itself"
	.dexText "to a rock on the seafloor and catches"
	.dexText "approaching prey using tentacles"
	.dexText "shaped like flower petals."
	.dexLang FR
	.dexText "L`espèce des LILIA s`est éteinte"
	.dexText "il y a environ cent millions d`années."
	.dexText "Cet ancien POKéMON s`accroche à"
	.dexText "un rocher, sous l`eau, et attrape ses"
	.dexText "proies à l`aide de ses tentacules en"
	.dexText "forme de pétales de fleur."
	.dexLang DE
	.dexText "Von LILIEP nahm man an, es sei seit"
	.dexText "etwa hundert Millionen Jahren"
	.dexText "ausgestorben. Mit seinen wie"
	.dexText "Blütenblätter geformten Tentakeln"
	.dexText "heftet es sich an einen Felsen auf dem"
	.dexText "Meeresboden und fängt Beute."
	.dexLang IT
	.dexText "LILEEP si è estinto circa cento"
	.dexText "milioni di anni or sono. Questo"
	.dexText "POKéMON antico si aggrappa"
	.dexText "alle rocce sui fondali marini e cattura"
	.dexText "le prede che si avvicinano con i propri"
	.dexText "tentacoli a forma di petali di fiori."
	.dexLang ES
	.dexText "Los LILEEP se extinguieron hace unos"
	.dexText "cien millones de años aproximadamente."
	.dexText "Este POKéMON se ancla a una roca en el"
	.dexText "fondo del mar y atrapa a las presas"
	.dexText "que se le acercan con los tentáculos"
	.dexText "que tiene en forma de pétalos de flor."

	.align 2, 0
dexEntryEu134:: @ 134 CRADILY
	.2byte 1, 3, 4
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 1, 3, 3, 2, 10, 10, 6, 0, 4  @ weight
	.dexLang EN
	.dexName "CRADILY"
	.dexLang FR
	.dexName "VACILYS"
	.dexLang DE
	.dexName "WIELIE"
	.dexLang EN
	.dexCategory "BARNACLE"
	.dexLang FR
	.dexCategoryLeftAligned "BERNACLE"
	.dexLang DE
	.dexCategoryLeftAligned "RANKFÜSSER"
	.dexLang IT
	.dexCategoryLeftAligned "LEPADE"
	.dexLang ES
	.dexCategoryLeftAligned "PERCEBE"
	.dexLang EN
	.dexText "CRADILY roams around the ocean floor"
	.dexText "in search of food. This POKéMON freely"
	.dexText "extends its tree trunk-like neck and"
	.dexText "captures unwary prey using its eight"
	.dexText "tentacles."
	.dexText ""
	.dexLang FR
	.dexText "VACILYS erre dans les profondeurs"
	.dexText "de l`océan pour chercher de la"
	.dexText "nourriture. Ce POKéMON peut allonger"
	.dexText "son cou à volonté et capturer ses"
	.dexText "proies à l`aide de ses huit tentacules."
	.dexText ""
	.dexLang DE
	.dexText "WIELIE durchforstet den Meeresboden"
	.dexText "nach Beute. Dieses POKéMON fährt"
	.dexText "seinen baumstammartigen Nacken aus"
	.dexText "und fängt mit seinen acht Tentakeln"
	.dexText "Beute."
	.dexText ""
	.dexLang IT
	.dexText "CRADILY scandaglia i fondali oceanici"
	.dexText "in cerca di nutrimento. Riesce ad"
	.dexText "estendere il collo, simile al tronco"
	.dexText "di un albero, per catturare ignare"
	.dexText "prede con i propri otto tentacoli."
	.dexText ""
	.dexLang ES
	.dexText "CRADILY va por el fondo oceánico sin"
	.dexText "rumbo fijo en busca de comida. El cuello"
	.dexText "de este POKéMON se parece al tronco"
	.dexText "de un árbol. Cuando quiere atrapar"
	.dexText "a su presa desprevenida, lo estira"
	.dexText "y usa los ocho tentáculos que tiene."

	.align 2, 0
dexEntryEu135:: @ 135 ANORITH
	.2byte 1, 3, 5
	.2byte 10, 2, 0, 4, 10, 10, 0, 7  @ height
	.2byte 10, 10, 2, 7, 6, 10, 10, 1, 2, 5  @ weight
	.dexLang EN
	.dexName "ANORITH"
	.dexLang FR
	.dexName "ANORITH"
	.dexLang DE
	.dexName "ANORITH"
	.dexLang EN
	.dexCategory "OLD SHRIMP"
	.dexLang FR
	.dexCategoryLeftAligned "CRUSTAGE"
	.dexLang DE
	.dexCategoryLeftAligned "KREBSSENIOR"
	.dexLang IT
	.dexCategoryLeftAligned "PRIMACEO"
	.dexLang ES
	.dexCategoryLeftAligned "CAMARÓN"
	.dexLang EN
	.dexText "ANORITH is said to be a type of"
	.dexText "POKéMON predecessor, with eight wings"
	.dexText "at the sides of its body."
	.dexText "This POKéMON swam in the primordial sea"
	.dexText "by undulating these eight wings."
	.dexText ""
	.dexLang FR
	.dexText "On raconte qu`avec ses huit ailes sur"
	.dexText "les côtés de son corps, ANORITH est"
	.dexText "un peu l`ancêtre des POKéMON."
	.dexText "Ce POKéMON nageait dans la mer"
	.dexText "originelle en ondulant ses huit ailes."
	.dexText ""
	.dexLang DE
	.dexText "ANORITH soll ein POKéMON-Vorgänger"
	.dexText "sein, es hat acht Flügel an seinem"
	.dexText "Körper. Dieses POKéMON schwamm im"
	.dexText "Urmeer, indem es seine acht Flügel"
	.dexText "schwang."
	.dexText ""
	.dexLang IT
	.dexText "Si dice che ANORITH sia un POKéMON"
	.dexText "antenato, con otto ali sui fianchi."
	.dexText ""
	.dexText "Il POKéMON nuotava nei mari"
	.dexText "primordiali remando con le otto ali."
	.dexText ""
	.dexLang ES
	.dexText "De ANORITH dicen que es una especie"
	.dexText "de POKéMON predecesor. Tiene ocho"
	.dexText "alas a ambos lados del cuerpo."
	.dexText "Gracias a ellas, pudo nadar por las"
	.dexText "primeras aguas que hubo."
	.dexText ""

	.align 2, 0
dexEntryEu136:: @ 136 ARMALDO
	.2byte 1, 3, 6
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 1, 5, 0, 4, 10, 10, 6, 8, 2  @ weight
	.dexLang EN
	.dexName "ARMALDO"
	.dexLang FR
	.dexName "ARMALDO"
	.dexLang DE
	.dexName "ARMALDO"
	.dexLang EN
	.dexCategory "PLATE"
	.dexLang FR
	.dexCategoryLeftAligned "BLINDAGE"
	.dexLang DE
	.dexCategoryLeftAligned "SCHILD"
	.dexLang IT
	.dexCategoryLeftAligned "PIASTRE"
	.dexLang ES
	.dexCategoryLeftAligned "ARMADURA"
	.dexLang EN
	.dexText "ARMALDO is a POKéMON species that"
	.dexText "became extinct in prehistoric times."
	.dexText "This POKéMON is said to have walked on"
	.dexText "its hind legs, which would have been"
	.dexText "more convenient for life on land."
	.dexText ""
	.dexLang FR
	.dexText "ARMALDO fait partie d`une espèce de"
	.dexText "POKéMON qui s`est éteinte à l`époque"
	.dexText "préhistorique. On raconte que ce"
	.dexText "POKéMON marchait sur ses pattes"
	.dexText "arrière, ce qui facilitait sa vie sur"
	.dexText "la terre ferme."
	.dexLang DE
	.dexText "ARMALDO ist eine POKéMON-Spezies, die"
	.dexText "vor vielen Jahren ausgestorben ist."
	.dexText "Dieses POKéMON soll sich auf seinen"
	.dexText "Hinterbeinen fortbewegt haben, da dies"
	.dexText "für das Leben an Land bequemer war."
	.dexText ""
	.dexLang IT
	.dexText "ARMALDO è una specie di POKéMON"
	.dexText "estinta già in tempi antichi."
	.dexText "Si dice che camminasse sugli arti"
	.dexText "inferiori per affrontare meglio"
	.dexText "il tipo di vita che conduceva"
	.dexText "sulla terra ferma."
	.dexLang ES
	.dexText "ARMALDO es una de las especies de"
	.dexText "POKéMON que se extinguieron en la era"
	.dexText "prehistórica. Se cree que caminaban"
	.dexText "sobre las patas traseras; lo más"
	.dexText "apropiado para la vida en tierra firme."
	.dexText ""

	.align 2, 0
dexEntryEu137:: @ 137 IGGLYBUFF
	.2byte 1, 3, 7
	.2byte 10, 1, 0, 0, 10, 10, 0, 3  @ height
	.2byte 10, 10, 10, 2, 2, 10, 10, 10, 1, 0  @ weight
	.dexLang EN
	.dexName "IGGLYBUFF"
	.dexLang FR
	.dexName "TOUDOUDOU"
	.dexLang DE
	.dexName "FLUFFELUFF"
	.dexLang EN
	.dexCategory "BALLOON"
	.dexLang FR
	.dexCategoryLeftAligned "BOUBOULE"
	.dexLang DE
	.dexCategoryLeftAligned "BALLON"
	.dexLang IT
	.dexCategoryLeftAligned "PALLONE"
	.dexLang ES
	.dexCategoryLeftAligned "GLOBO"
	.dexLang EN
	.dexText "IGGLYBUFF has a soft and plushy body"
	.dexText "that feels very much like a marshmallow."
	.dexText "From this body wafts a gently sweet"
	.dexText "fragrance that soothes and calms the"
	.dexText "emotions of its foes."
	.dexText ""
	.dexLang FR
	.dexText "TOUDOUDOU a un corps mou et pelucheux,"
	.dexText "semblable à de la guimauve. Un parfum"
	.dexText "doux et sucré s`échappe de son corps,"
	.dexText "ce qui lui permet d`apaiser et de"
	.dexText "calmer ses ennemis."
	.dexText ""
	.dexLang DE
	.dexText "FLUFFELUFF hat einen weichen Körper,"
	.dexText "der sich anfühlt wie ein Marshmallow. Es"
	.dexText "verströmt einen süßlichen Duft, der"
	.dexText "die Emotionen seiner Gegner beruhigt."
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "IGGLYBUFF, così morbido e soffice,"
	.dexText "sembra fatto di gommapiuma rosa."
	.dexText "Il suo corpo emana un lieve aroma"
	.dexText "che placa le emozioni e"
	.dexText "l`aggressività del nemico."
	.dexText ""
	.dexLang ES
	.dexText "IGGLYBUFF es suave y tierno, parece un"
	.dexText "merengue. Emana un aroma dulce y"
	.dexText "agradable que le sirve para calmar los"
	.dexText "ánimos de sus oponentes en combate."
	.dexText ""
	.dexText ""

	.align 2, 0
dexEntryEu138:: @ 138 JIGGLYPUFF
	.2byte 1, 3, 8
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 1, 2, 1, 10, 10, 10, 5, 5  @ weight
	.dexLang EN
	.dexName "JIGGLYPUFF"
	.dexLang FR
	.dexName "RONDOUDOU"
	.dexLang DE
	.dexName "PUMMELUFF"
	.dexLang EN
	.dexCategory "BALLOON"
	.dexLang FR
	.dexCategoryLeftAligned "BOUBOULE"
	.dexLang DE
	.dexCategoryLeftAligned "BALLON"
	.dexLang IT
	.dexCategoryLeftAligned "PALLONE"
	.dexLang ES
	.dexCategoryLeftAligned "GLOBO"
	.dexLang EN
	.dexText "When this POKéMON sings, it never"
	.dexText "pauses to breathe. If it is in a battle"
	.dexText "against an opponent that does not"
	.dexText "easily fall asleep, JIGGLYPUFF cannot"
	.dexText "breathe, endangering its life."
	.dexText ""
	.dexLang FR
	.dexText "Lorsque ce POKéMON chante, il ne"
	.dexText "s`arrête pas pour respirer. Quand il se"
	.dexText "bat contre un adversaire qu`il ne peut"
	.dexText "pas facilement endormir, RONDOUDOU"
	.dexText "reste donc sans respirer, mettant sa"
	.dexText "vie en danger."
	.dexLang DE
	.dexText "Wenn dieses POKéMON singt, hört es"
	.dexText "nicht auf zu atmen. Im Kampf gegen"
	.dexText "einen Gegner, der nicht so leicht"
	.dexText "in Schlaf zu versetzen ist, kann"
	.dexText "PUMMELUFF nicht atmen. Leider"
	.dexText "gefährdet es sich dadurch selbst."
	.dexLang IT
	.dexText "Quando canta, JIGGLYPUFF non si ferma"
	.dexText "a prendere fiato. Se lotta contro un"
	.dexText "nemico che non si addormenta"
	.dexText "facilmente, non respira rischiando così"
	.dexText "di esaurire tutte le sue energie."
	.dexText ""
	.dexLang ES
	.dexText "Cuando este POKéMON canta, no para"
	.dexText "nunca para respirar. Si en combate"
	.dexText "el enemigo no se queda dormido"
	.dexText "con facilidad, JIGGLYPUFF no podrá"
	.dexText "respirar y su vida correrá peligro."
	.dexText ""

	.align 2, 0
dexEntryEu139:: @ 139 WIGGLYTUFF
	.2byte 1, 3, 9
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 10, 2, 6, 5, 10, 10, 1, 2, 0  @ weight
	.dexLang EN
	.dexName "WIGGLYTUFF"
	.dexLang FR
	.dexName "GRODOUDOU"
	.dexLang DE
	.dexName "KNUDDELUFF"
	.dexLang EN
	.dexCategory "BALLOON"
	.dexLang FR
	.dexCategoryLeftAligned "BOUBOULE"
	.dexLang DE
	.dexCategoryLeftAligned "BALLON"
	.dexLang IT
	.dexCategoryLeftAligned "PALLONE"
	.dexLang ES
	.dexCategoryLeftAligned "GLOBO"
	.dexLang EN
	.dexText "WIGGLYTUFF`s body is very flexible."
	.dexText "By inhaling deeply, this POKéMON can"
	.dexText "inflate itself seemingly without end."
	.dexText "Once inflated, WIGGLYTUFF bounces"
	.dexText "along lightly like a balloon."
	.dexText ""
	.dexLang FR
	.dexText "Le corps de GRODOUDOU est très"
	.dexText "élastique. S`il inspire profondément, ce"
	.dexText "POKéMON peut se gonfler à volonté."
	.dexText "Une fois gonflé, GRODOUDOU peut"
	.dexText "rebondir comme un ballon."
	.dexText ""
	.dexLang DE
	.dexText "KNUDDELUFFs Körper ist sehr dehnbar."
	.dexText "Indem es tief einatmet, kann sich"
	.dexText "dieses POKéMON selbst aufblasen."
	.dexText "Wenn es aufgepumpt ist, hüpft es"
	.dexText "wie ein Luftballon umher."
	.dexText ""
	.dexLang IT
	.dexText "WIGGLYTUFF è molto elastico. Se respira"
	.dexText "profondamente, questo POKéMON riesce"
	.dexText "a gonfiarsi praticamente all`infinito."
	.dexText "Una volta gonfio, WIGGLYTUFF"
	.dexText "rimbalza leggero come un pallone."
	.dexText ""
	.dexLang ES
	.dexText "El cuerpo de WIGGLYTUFF es muy"
	.dexText "flexible. Dicen que, al aspirar aire,"
	.dexText "puede hincharse sin límites."
	.dexText "Y, una vez hinchado, se pone a botar"
	.dexText "como si fuera un globo."
	.dexText ""

	.align 2, 0
dexEntryEu140:: @ 140 FEEBAS
	.2byte 1, 4, 0
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 1, 6, 3, 10, 10, 10, 7, 4  @ weight
	.dexLang EN
	.dexName "FEEBAS"
	.dexLang FR
	.dexName "BARPAU"
	.dexLang DE
	.dexName "BARSCHWA"
	.dexLang EN
	.dexCategory "FISH"
	.dexLang FR
	.dexCategoryLeftAligned "POISSON"
	.dexLang DE
	.dexCategoryLeftAligned "FISCH"
	.dexLang IT
	.dexCategoryLeftAligned "PESCE"
	.dexLang ES
	.dexCategoryLeftAligned "PEZ"
	.dexLang EN
	.dexText "While FEEBAS`s body is in tatters,"
	.dexText "it has a hardy and tenacious life force"
	.dexText "that enables it to live anywhere."
	.dexText "However, this POKéMON is also slow and"
	.dexText "dimwitted, making it an easy catch."
	.dexText ""
	.dexLang FR
	.dexText "Même si le corps de BARPAU est en"
	.dexText "lambeaux, il reste tenace et"
	.dexText "obstiné, ce qui lui permet de survivre"
	.dexText "partout. Cependant, ce POKéMON est"
	.dexText "très lent et un peu bête, ce qui en fait"
	.dexText "une proie facile."
	.dexLang DE
	.dexText "Obwohl BARSCHWAs Körper zerfetzt ist,"
	.dexText "besitzt es eine harte und zähe Lebens-"
	.dexText "kraft, so dass es überall leben kann."
	.dexText "Aber dieses POKéMON ist langsam und"
	.dexText "dusselig. Daher ist es leicht zu fangen."
	.dexText ""
	.dexLang IT
	.dexText "Sebbene abbia il corpo logoro,"
	.dexText "FEEBAS è molto tenace e resistente,"
	.dexText "potendo così vivere in ogni luogo."
	.dexText "Tuttavia, questo POKéMON è anche"
	.dexText "lento e poco sveglio, il che lo rende"
	.dexText "una preda facile."
	.dexLang ES
	.dexText "Aunque FEEBAS tenga un cuerpo poco"
	.dexText "compacto, posee una tremenda y"
	.dexText "constante fuerza vital que le permite"
	.dexText "vivir en cualquier lugar. Con todo,"
	.dexText "es un POKéMON lento y simplón;"
	.dexText "es fácil de atrapar."

	.align 2, 0
dexEntryEu141:: @ 141 MILOTIC
	.2byte 1, 4, 1
	.2byte 2, 0, 0, 4, 10, 10, 6, 2  @ height
	.2byte 10, 3, 5, 7, 1, 10, 1, 6, 2, 0  @ weight
	.dexLang EN
	.dexName "MILOTIC"
	.dexLang FR
	.dexName "MILOBELLUS"
	.dexLang DE
	.dexName "MILOTIC"
	.dexLang EN
	.dexCategory "TENDER"
	.dexLang FR
	.dexCategoryLeftAligned "TENDRE"
	.dexLang DE
	.dexCategoryLeftAligned "ZARTHEIT"
	.dexLang IT
	.dexCategoryLeftAligned "TENEREZZA"
	.dexLang ES
	.dexCategoryLeftAligned "TIERNO"
	.dexLang EN
	.dexText "MILOTIC live at the bottom of large"
	.dexText "lakes. When this POKéMON`s body glows a"
	.dexText "vivid pink, it releases a pulsing wave of"
	.dexText "energy that brings soothing calm to"
	.dexText "restless spirits."
	.dexText ""
	.dexLang FR
	.dexText "MILOBELLUS vit au fond des grands lacs."
	.dexText "Lorsque le corps de ce POKéMON devient"
	.dexText "rose vif, il libère une pulsation"
	.dexText "d`énergie, capable d`apaiser les esprits"
	.dexText "agités."
	.dexText ""
	.dexLang DE
	.dexText "MILOTIC lebt auf dem Grund großer Seen."
	.dexText "Wenn dieses POKéMON rosa leuchtet,"
	.dexText "gibt es eine Energiewelle ab, die einem"
	.dexText "rastlosen Geist wohltuende Ruhe"
	.dexText "verschaffen kann."
	.dexText ""
	.dexLang IT
	.dexText "MILOTIC vive sui fondali dei grandi"
	.dexText "laghi. Quando il suo corpo riluce di un"
	.dexText "rosa intenso, rilascia una forte onda"
	.dexText "energetica, in grado di placare"
	.dexText "gli spiriti instabili."
	.dexText ""
	.dexLang ES
	.dexText "MILOTIC vive en lo más profundo de"
	.dexText "los lagos. Cuando intensifica el color"
	.dexText "rosa de la piel, libera una fuerte onda"
	.dexText "de energía que tranquiliza a todo el que"
	.dexText "tenga el ánimo alterado."
	.dexText ""

	.align 2, 0
dexEntryEu142:: @ 142 CASTFORM
	.2byte 1, 4, 2
	.2byte 10, 1, 0, 0, 10, 10, 0, 3  @ height
	.2byte 10, 10, 10, 1, 8, 10, 10, 10, 0, 8  @ weight
	.dexLang EN
	.dexName "CASTFORM"
	.dexLang FR
	.dexName "MORPHEO"
	.dexLang DE
	.dexName "FORMEO"
	.dexLang EN
	.dexCategory "WEATHER"
	.dexLang FR
	.dexCategoryLeftAligned "CLIMAT"
	.dexLang DE
	.dexCategoryLeftAligned "WETTER"
	.dexLang IT
	.dexCategoryLeftAligned "METEO"
	.dexLang ES
	.dexCategoryLeftAligned "CLIMA"
	.dexLang EN
	.dexText "CASTFORM borrows the power of nature"
	.dexText "to transform itself into the guises of"
	.dexText "the sun, rain clouds, and snow clouds."
	.dexText "This POKéMON`s feelings change with the"
	.dexText "weather."
	.dexText ""
	.dexLang FR
	.dexText "MORPHEO emprunte le pouvoir de"
	.dexText "la nature pour prendre l`apparence du"
	.dexText "soleil, de la pluie ou de la neige."
	.dexText "Le type de ce POKéMON change"
	.dexText "en fonction du temps."
	.dexText ""
	.dexLang DE
	.dexText "FORMEO bedient sich der Kraft der"
	.dexText "Natur, um die Gestalt der Sonne, von"
	.dexText "Regen- oder Schneewolken anzunehmen."
	.dexText "Die Gefühlslage dieses POKéMON"
	.dexText "verändert sich mit dem Wetter."
	.dexText ""
	.dexLang IT
	.dexText "CASTFORM usa il potere della natura"
	.dexText "per trasformarsi in sole, gocce di"
	.dexText "pioggia e nubi nevose."
	.dexText "Il tipo di questo POKéMON"
	.dexText "varia con i mutamenti"
	.dexText "meteorologici."
	.dexLang ES
	.dexText "CASTFORM se vale del poder de la"
	.dexText "Naturaleza para transformarse en el"
	.dexText "sol y en nubarrones cargados de lluvia"
	.dexText "o nieve. El tipo de este POKéMON"
	.dexText "varía según el clima."
	.dexText ""

	.align 2, 0
dexEntryEu143:: @ 143 STARYU
	.2byte 1, 4, 3
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 7, 6, 1, 10, 10, 3, 4, 5  @ weight
	.dexLang EN
	.dexName "STARYU"
	.dexLang FR
	.dexName "STARI"
	.dexLang DE
	.dexName "STERNDU"
	.dexLang EN
	.dexCategory "STAR SHAPE"
	.dexLang FR
	.dexCategoryLeftAligned "ETOILE"
	.dexLang DE
	.dexCategoryLeftAligned "STERNFORM"
	.dexLang IT
	.dexCategoryLeftAligned "STELLA"
	.dexLang ES
	.dexCategoryLeftAligned "ESTRELLADA"
	.dexLang EN
	.dexText "STARYU`s center section has an organ"
	.dexText "called the core that shines bright red."
	.dexText "If you go to a beach toward the"
	.dexText "end of summer, the glowing cores of"
	.dexText "these POKéMON look like the stars"
	.dexText "in the sky."
	.dexLang FR
	.dexText "Au centre de STARI se trouve un organe"
	.dexText "rouge et brillant appelé le cœur. A la"
	.dexText "fin de l`été, sur les plages, les cœurs"
	.dexText "de ces POKéMON brillent comme les"
	.dexText "étoiles dans le ciel."
	.dexText ""
	.dexLang DE
	.dexText "In STERNDUs Körpermitte befindet sich"
	.dexText "ein hellrot leuchtendes Organ -"
	.dexText "sein Kern. Wenn du im Spätsommer"
	.dexText "an einen Strand gehst, sehen die"
	.dexText "leuchtenden Kerne dieser POKéMON aus"
	.dexText "wie Sterne."
	.dexLang IT
	.dexText "Al centro del corpo di STARYU è"
	.dexText "presente un nucleo che brilla di un"
	.dexText "rosso intenso. In spiaggia, a fine"
	.dexText "estate, il nucleo di questi POKéMON"
	.dexText "ha l`aspetto delle stelle nel firmamento."
	.dexText ""
	.dexLang ES
	.dexText "STARYU posee un órgano central"
	.dexText "conocido como su núcleo, que brilla"
	.dexText "con una luz roja."
	.dexText "Si vas a la playa a finales de verano,"
	.dexText "podrás ver los núcleos de estos POKéMON"
	.dexText "brillando como las estrellas del cielo."

	.align 2, 0
dexEntryEu144:: @ 144 STARMIE
	.2byte 1, 4, 4
	.2byte 10, 3, 0, 7, 10, 10, 1, 1  @ height
	.2byte 10, 1, 7, 6, 4, 10, 10, 8, 0, 0  @ weight
	.dexLang EN
	.dexName "STARMIE"
	.dexLang FR
	.dexName "STAROSS"
	.dexLang DE
	.dexName "STARMIE"
	.dexLang EN
	.dexCategory "MYSTERIOUS"
	.dexLang FR
	.dexCategoryLeftAligned "MYSTERIEUX"
	.dexLang DE
	.dexCategoryLeftAligned "MYSTERIÖS"
	.dexLang IT
	.dexCategoryLeftAligned "MISTERIOSO"
	.dexLang ES
	.dexCategoryLeftAligned "MISTERIOSO"
	.dexLang EN
	.dexText "STARMIE`s center section - the core -"
	.dexText "glows brightly in seven colors."
	.dexText "Because of its luminous nature, this"
	.dexText "POKéMON has been given the nickname"
	.dexText "“the gem of the sea.”"
	.dexText ""
	.dexLang FR
	.dexText "Le centre de STAROSS, son cœur,"
	.dexText "resplendit de sept différentes"
	.dexText "couleurs. A cause de sa brillance"
	.dexText "naturelle, on appelle ce POKéMON le"
	.dexText "«joyau des mers»."
	.dexText ""
	.dexLang DE
	.dexText "STARMIEs Mittelteil, sein Kern, leuchtet"
	.dexText "in sieben Farben. Aufgrund dieser"
	.dexText "Eigenschaft wird es auch"
	.dexText "„Juwel des Meeres“ genannt."
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "Il centro del corpo di STARMIE,"
	.dexText "il suo nucleo, brilla in sette colori."
	.dexText ""
	.dexText "Per la sua luminosità è chiamato"
	.dexText "“Gemma del mare”."
	.dexText ""
	.dexLang ES
	.dexText "La parte central de STARMIE (el núcleo"
	.dexText "brillante) resplandece con siete colores"
	.dexText "distintos. Debido a su naturaleza"
	.dexText "luminosa, a este POKéMON se le ha"
	.dexText "dado el apelativo de “la gema del mar”."
	.dexText ""

	.align 2, 0
dexEntryEu145:: @ 145 KECLEON
	.2byte 1, 4, 5
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 10, 4, 8, 5, 10, 10, 2, 2, 0  @ weight
	.dexLang EN
	.dexName "KECLEON"
	.dexLang FR
	.dexName "KECLEON"
	.dexLang DE
	.dexName "KECLEON"
	.dexLang EN
	.dexCategory "COLOR SWAP"
	.dexLang FR
	.dexCategoryLeftAligned "MULTICOLOR"
	.dexLang DE
	.dexCategoryLeftAligned "FARBENSPIEL"
	.dexLang IT
	.dexCategoryLeftAligned "MUTACOLORE"
	.dexLang ES
	.dexCategoryLeftAligned "CAMALEÓNICO"
	.dexLang EN
	.dexText "KECLEON alters its body coloration to"
	.dexText "blend in with its surroundings, allowing"
	.dexText "it to sneak up on its prey unnoticed."
	.dexText "Then it lashes out with its long,"
	.dexText "stretchy tongue to instantly ensnare"
	.dexText "the unsuspecting target."
	.dexLang FR
	.dexText "KECLEON change la couleur de son"
	.dexText "corps pour se fondre dans son environ-"
	.dexText "nement, ce qui lui permet de s`approcher"
	.dexText "de sa proie sans être repéré. Il envoie"
	.dexText "ensuite sa grande langue élastique pour"
	.dexText "piéger sa proie qui ne se doute de rien."
	.dexLang DE
	.dexText "KECLEON verändert seine Körper-"
	.dexText "färbung, um sich seiner Umgebung"
	.dexText "anzupassen. Dadurch kann es sich"
	.dexText "prima an seine ahnungslose Beute an-"
	.dexText "schleichen. Es schlägt mit seiner dehn-"
	.dexText "baren, langen Zunge aus und fängt sie."
	.dexLang IT
	.dexText "KECLEON varia la colorazione del proprio"
	.dexText "corpo per mimetizzarsi con l`ambiente"
	.dexText "circostante, consentendogli di tendere"
	.dexText "un agguato alla preda senza farsi"
	.dexText "notare. Poi l`attacca con la sua lingua"
	.dexText "elastica sopraffacendola."
	.dexLang ES
	.dexText "KECLEON modifica la coloración de la piel"
	.dexText "para camuflarse en el medio en el que"
	.dexText "esté. Así, puede acercarse a hurtadillas"
	.dexText "a su enemigo sin que se dé cuenta"
	.dexText "y lanzarle la larga y elástica lengua"
	.dexText "que tiene para atraparlo por sorpresa."

	.align 2, 0
dexEntryEu146:: @ 146 SHUPPET
	.2byte 1, 4, 6
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 10, 5, 1, 10, 10, 10, 2, 3  @ weight
	.dexLang EN
	.dexName "SHUPPET"
	.dexLang FR
	.dexName "POLICHOMBR"
	.dexLang DE
	.dexName "SHUPPET"
	.dexLang EN
	.dexCategory "PUPPET"
	.dexLang FR
	.dexCategoryLeftAligned "POUPEE"
	.dexLang DE
	.dexCategoryLeftAligned "PUPPE"
	.dexLang IT
	.dexCategoryLeftAligned "PUPAZZO"
	.dexLang ES
	.dexCategoryLeftAligned "TÍTERE"
	.dexLang EN
	.dexText "SHUPPET is attracted by feelings"
	.dexText "of jealousy and vindictiveness."
	.dexText "If someone develops strong feelings of"
	.dexText "vengeance, this POKéMON will appear"
	.dexText "in a swarm and line up beneath the eaves"
	.dexText "of that person`s home."
	.dexLang FR
	.dexText "Les POLICHOMBR sont attirés par les"
	.dexText "sentiments de jalousie et les esprits"
	.dexText "revanchards. Si quelqu`un veut"
	.dexText "se venger, ces POKéMON"
	.dexText "apparaissent en nuée et s`alignent"
	.dexText "devant la porte des gens concernés."
	.dexLang DE
	.dexText "SHUPPET wird durch Gefühle wie Neid und"
	.dexText "Rachsucht angezogen. Wenn jemand"
	.dexText "starke Rachegelüste entwickelt,"
	.dexText "erscheint dieses POKéMON in Scharen"
	.dexText "und reiht sich unter der Dachrinne der"
	.dexText "Person auf."
	.dexLang IT
	.dexText "SHUPPET è attratto dai sentimenti"
	.dexText "turpi di gelosia e vendetta. Se qualcuno"
	.dexText "serba un forte rancore, questi POKéMON"
	.dexText "arrivano a frotte per annidarsi sotto"
	.dexText "i cornicioni di casa sua."
	.dexText ""
	.dexLang ES
	.dexText "A SHUPPET le atraen los sentimientos"
	.dexText "de celos y rencor. Si alguien desarrolla"
	.dexText "fuertes sentimientos de venganza,"
	.dexText "aparecerá una multitud de SHUPPET"
	.dexText "que se quedará bajo los aleros"
	.dexText "de su casa."

	.align 2, 0
dexEntryEu147:: @ 147 BANETTE
	.2byte 1, 4, 7
	.2byte 10, 3, 0, 7, 10, 10, 1, 1  @ height
	.2byte 10, 10, 2, 7, 6, 10, 10, 1, 2, 5  @ weight
	.dexLang EN
	.dexName "BANETTE"
	.dexLang FR
	.dexName "BRANETTE"
	.dexLang DE
	.dexName "BANETTE"
	.dexLang EN
	.dexCategory "MARIONETTE"
	.dexLang FR
	.dexCategoryLeftAligned "MARIONETTE"
	.dexLang DE
	.dexCategoryLeftAligned "MARIONETTE"
	.dexLang IT
	.dexCategoryLeftAligned "MARIONETTA"
	.dexLang ES
	.dexCategoryLeftAligned "MARIONETA"
	.dexLang EN
	.dexText "BANETTE generates energy for laying"
	.dexText "strong curses by sticking pins into its"
	.dexText "own body."
	.dexText "This POKéMON was originally a pitiful"
	.dexText "plush doll that was thrown away."
	.dexText ""
	.dexLang FR
	.dexText "En plantant des aiguilles dans son"
	.dexText "propre corps, BRANETTE génère de"
	.dexText "l`énergie permettant de lancer de"
	.dexText "puissantes malédictions. Au départ, ce"
	.dexText "POKéMON n`était qu`une malheureuse"
	.dexText "peluche jetée à la poubelle."
	.dexLang DE
	.dexText "BANETTE belegt andere mit Flüchen,"
	.dexText "indem es Nadeln in seinen eigenen"
	.dexText "Körper sticht. Dieses POKéMON war"
	.dexText "ursprünglich eine Mitleid erregende"
	.dexText "Plüschpuppe, die weggeworfen wurde."
	.dexText ""
	.dexLang IT
	.dexText "BANETTE genera energia per lanciare"
	.dexText "terribili maledizioni, conficcandosi"
	.dexText "alcuni spilli nel corpo."
	.dexText "Originariamente questo POKéMON era"
	.dexText "un dolce peluche, successivamente"
	.dexText "gettato via."
	.dexLang ES
	.dexText "BANETTE genera energía para echar"
	.dexText "un infalible hechizo clavándose púas"
	.dexText "a sí mismo."
	.dexText "Los orígenes de este POKéMON son algo"
	.dexText "tristes: era un muñeco de felpa al que"
	.dexText "tiraron a la basura."

	.align 2, 0
dexEntryEu148:: @ 148 DUSKULL
	.2byte 1, 4, 8
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 3, 3, 1, 10, 10, 1, 5, 0  @ weight
	.dexLang EN
	.dexName "DUSKULL"
	.dexLang FR
	.dexName "SKELENOX"
	.dexLang DE
	.dexName "ZWIRRLICHT"
	.dexLang EN
	.dexCategory "REQUIEM"
	.dexLang FR
	.dexCategoryLeftAligned "REQUIEM"
	.dexLang DE
	.dexCategoryLeftAligned "REQUIEM"
	.dexLang IT
	.dexCategoryLeftAligned "REQUIEM"
	.dexLang ES
	.dexCategoryLeftAligned "RÉQUIEM"
	.dexLang EN
	.dexText "DUSKULL wanders lost among the deep"
	.dexText "darkness of midnight. There is an oft-"
	.dexText "told admonishment given to misbehaving"
	.dexText "children that this POKéMON will spirit"
	.dexText "away bad children who earn scoldings"
	.dexText "from their mothers."
	.dexLang FR
	.dexText "SKELENOX erre seul dans l`obscurité"
	.dexText "de la nuit. On fait souvent"
	.dexText "peur aux enfants en leur disant"
	.dexText "que ce POKéMON viendra les chercher"
	.dexText "s`ils n`obéissent pas à leur maman."
	.dexText ""
	.dexLang DE
	.dexText "ZWIRRLICHT wandert verloren durch die"
	.dexText "tiefe Dunkelheit der Nacht. Kinder"
	.dexText "werden oft ermahnt, dass dieses"
	.dexText "POKéMON böse Kinder wegzaubert, die"
	.dexText "von ihren Müttern ausgeschimpft"
	.dexText "worden sind."
	.dexLang IT
	.dexText "DUSKULL vaga come un`anima persa"
	.dexText "nella tetra oscurità notturna. Spesso"
	.dexText "ai bimbi capricciosi si dice che"
	.dexText "questo POKéMON si porti via i bambini"
	.dexText "che fanno arrabbiare la mamma."
	.dexText ""
	.dexLang ES
	.dexText "DUSKULL vaga perdido por la oscuridad"
	.dexText "de la noche. Cuando los niños se portan"
	.dexText "mal y desobedecen a sus padres,"
	.dexText "se les dice que este POKéMON"
	.dexText "aparecerá y se los llevará con él."
	.dexText ""

	.align 2, 0
dexEntryEu149:: @ 149 DUSCLOPS
	.2byte 1, 4, 9
	.2byte 10, 5, 0, 3, 10, 10, 1, 6  @ height
	.2byte 10, 10, 6, 7, 5, 10, 10, 3, 0, 6  @ weight
	.dexLang EN
	.dexName "DUSCLOPS"
	.dexLang FR
	.dexName "TERACLOPE"
	.dexLang DE
	.dexName "ZWIRRKLOP"
	.dexLang EN
	.dexCategory "BECKON"
	.dexLang FR
	.dexCategoryLeftAligned "APPEL"
	.dexLang DE
	.dexCategoryLeftAligned "WINK"
	.dexLang IT
	.dexCategoryLeftAligned "IPNOSGUARDO"
	.dexLang ES
	.dexCategoryLeftAligned "ATRAYENTE"
	.dexLang EN
	.dexText "DUSCLOPS absorbs anything, however"
	.dexText "large the object may be. This POKéMON"
	.dexText "hypnotizes its foe by waving its hands"
	.dexText "in a macabre manner and by bringing its"
	.dexText "single eye to bear. The hypnotized foe"
	.dexText "is made to do DUSCLOPS`s bidding."
	.dexLang FR
	.dexText "TERACLOPE peut absorber des objets"
	.dexText "de toute taille. Ce POKéMON hypnotise"
	.dexText "son ennemi en faisant des gestes"
	.dexText "macabres et en attirant l`attention sur"
	.dexText "son unique œil. L`ennemi hypnotisé obéit"
	.dexText "ensuite aux ordres de TERACLOPE."
	.dexLang DE
	.dexText "ZWIRRKLOP absorbiert alles, egal, wie"
	.dexText "groß es auch sein mag. Dieses POKéMON"
	.dexText "hypnotisiert seinen Gegner, indem es"
	.dexText "auf makabre Weise winkt und sein"
	.dexText "einziges Auge zeigt. Der hypnotisierte"
	.dexText "Gegner führt dann seine Befehle aus."
	.dexLang IT
	.dexText "DUSCLOPS assorbe qualsiasi cosa"
	.dexText "indipendentemente dalle sue dimensioni."
	.dexText "Questo POKéMON ipnotizza il nemico"
	.dexText "con un macabro movimento delle mani"
	.dexText "e con il suo unico occhio, costringen-"
	.dexText "dolo ad eseguire i suoi ordini."
	.dexLang ES
	.dexText "DUSCLOPS absorbe todo lo que pilla,"
	.dexText "al margen del tamaño que tenga."
	.dexText "Este POKéMON hipnotiza a su rival"
	.dexText "moviendo las manos de forma macabra y"
	.dexText "usando el ojo de manera implacable. Una"
	.dexText "vez hipnotizado, el enemigo obedecerá."

	.align 2, 0
dexEntryEu150:: @ 150 TROPIUS
	.2byte 1, 5, 0
	.2byte 10, 6, 0, 7, 10, 10, 2, 0  @ height
	.2byte 10, 2, 2, 0, 5, 10, 1, 0, 0, 0  @ weight
	.dexLang EN
	.dexName "TROPIUS"
	.dexLang FR
	.dexName "TROPIUS"
	.dexLang DE
	.dexName "TROPIUS"
	.dexLang EN
	.dexCategory "FRUIT"
	.dexLang FR
	.dexCategoryLeftAligned "FRUIT"
	.dexLang DE
	.dexCategoryLeftAligned "OBST"
	.dexLang IT
	.dexCategoryLeftAligned "FRUTTO"
	.dexLang ES
	.dexCategoryLeftAligned "FRUTO"
	.dexLang EN
	.dexText "Children of the southern tropics eat"
	.dexText "as snacks the fruit that grows in"
	.dexText "bunches around the neck of TROPIUS."
	.dexText "This POKéMON flies by flapping the"
	.dexText "leaves on its back as if they were"
	.dexText "wings."
	.dexLang FR
	.dexText "Les enfants des tropiques mangent les"
	.dexText "fruits qui poussent autour du cou de"
	.dexText "TROPIUS pour leur goûter."
	.dexText "Ce POKéMON peut voler en agitant les"
	.dexText "feuilles situées sur son dos, comme"
	.dexText "s`il s`agissait d`ailes."
	.dexLang DE
	.dexText "Kinder aus den südlichen Tropen essen"
	.dexText "die Früchte, die am Nacken von TROPIUS"
	.dexText "hängen, als Zwischenmahlzeit."
	.dexText "Dieses POKéMON kann fliegen, indem es"
	.dexText "mit den Blättern auf seinem Rücken"
	.dexText "schlägt, als ob es Flügel wären."
	.dexLang IT
	.dexText "I bambini dei tropici meridionali fanno"
	.dexText "merenda coi frutti che crescono a"
	.dexText "grappoli attorno al collo di TROPIUS."
	.dexText "Questo POKéMON vola agitando le"
	.dexText "foglie sulla schiena come se fossero"
	.dexText "ali."
	.dexLang ES
	.dexText "Los niños de la zona sur de los trópicos"
	.dexText "se comen los racimos de fruta que le"
	.dexText "crecen a TROPIUS alrededor del cuello."
	.dexText "Este POKéMON vuela batiendo las hojas"
	.dexText "que tiene en el lomo como si fueran alas."
	.dexText ""

	.align 2, 0
dexEntryEu151:: @ 151 CHIMECHO
	.2byte 1, 5, 1
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 10, 2, 2, 10, 10, 10, 1, 0  @ weight
	.dexLang EN
	.dexName "CHIMECHO"
	.dexLang FR
	.dexName "EOKO"
	.dexLang DE
	.dexName "PALIMPALIM"
	.dexLang EN
	.dexCategory "WIND CHIME"
	.dexLang FR
	.dexCategoryLeftAligned "CARILLON"
	.dexLang DE
	.dexCategoryLeftAligned "WINDSPIEL"
	.dexLang IT
	.dexCategoryLeftAligned "VENCAMPANA"
	.dexLang ES
	.dexCategoryLeftAligned "SONIDO AIRE"
	.dexLang EN
	.dexText "In high winds, CHIMECHO cries as it"
	.dexText "hangs from a tree branch or the eaves"
	.dexText "of a building using a suction cup on its"
	.dexText "head."
	.dexText "This POKéMON plucks berries with its"
	.dexText "long tail and eats them."
	.dexLang FR
	.dexText "Lorsqu`il y a beaucoup de vent, EOKO"
	.dexText "pousse des cris, accroché à une"
	.dexText "branche ou à un auvent"
	.dexText "par une ventouse placée sur sa tête."
	.dexText "Ce POKéMON attrape des BAIES avec"
	.dexText "sa longue queue pour les manger."
	.dexLang DE
	.dexText "Bei starkem Wind hängt sich"
	.dexText "PALIMPALIM an einen Ast oder an die"
	.dexText "Dachrinne eines Gebäudes, wobei es eine"
	.dexText "Saugkappe auf seinem Kopf benutzt."
	.dexText "Das POKéMON pflückt mit seinem langen"
	.dexText "Schweif Beeren und verspeist sie."
	.dexLang IT
	.dexText "Quando soffia il vento forte, CHIMECHO"
	.dexText "emette il suo verso penzolando dai rami"
	.dexText "degli alberi o dai cornicioni, a cui"
	.dexText "si attacca con la ventosa che ha sul"
	.dexText "capo. Con la sua lunga coda scova"
	.dexText "le bacche dal terreno e se ne ciba."
	.dexLang ES
	.dexText "Cuando hay viento fuerte, CHIMECHO"
	.dexText "chilla colgado de la rama de un árbol o de"
	.dexText "los aleros de un edificio por la ventosa"
	.dexText "que tiene en la cabeza."
	.dexText "Este POKéMON usa la larga cola que tiene"
	.dexText "para agarrar BAYAS y comérselas."

	.align 2, 0
dexEntryEu152:: @ 152 ABSOL
	.2byte 1, 5, 2
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 1, 0, 3, 6, 10, 10, 4, 7, 0  @ weight
	.dexLang EN
	.dexName "ABSOL"
	.dexLang FR
	.dexName "ABSOL"
	.dexLang DE
	.dexName "ABSOL"
	.dexLang EN
	.dexCategory "DISASTER"
	.dexLang FR
	.dexCategoryLeftAligned "DESASTRE"
	.dexLang DE
	.dexCategoryLeftAligned "DESASTER"
	.dexLang IT
	.dexCategoryLeftAligned "CATASTROFE"
	.dexLang ES
	.dexCategoryLeftAligned "CATÁSTROFE"
	.dexLang EN
	.dexText "ABSOL has the ability to foretell the"
	.dexText "coming of natural disasters."
	.dexText "It lives in a harsh, rugged mountain"
	.dexText "environment. This POKéMON very rarely"
	.dexText "ventures down from the mountains."
	.dexText ""
	.dexLang FR
	.dexText "ABSOL a le pouvoir de prédire les"
	.dexText "catastrophes naturelles. Il vit dans un"
	.dexText "milieu montagneux aride et accidenté."
	.dexText "Ce POKéMON s`éloigne très rarement"
	.dexText "des montagnes."
	.dexText ""
	.dexLang DE
	.dexText "ABSOL kann bevorstehende Natur-"
	.dexText "katastrophen voraussagen. Es lebt auf"
	.dexText "einem kargen, zerklüfteten Berg."
	.dexText "Dieses POKéMON wagt sich nur sehr"
	.dexText "selten ins Tal herunter."
	.dexText ""
	.dexLang IT
	.dexText "ABSOL ha l`abilità di predire le"
	.dexText "catastrofi naturali. Vive negli ambienti"
	.dexText "montani più aspri e inospitali."
	.dexText "Soltanto raramente si allontana dalle"
	.dexText "montagne per avventurarsi a valle."
	.dexText ""
	.dexLang ES
	.dexText "ABSOL tiene la habilidad de predecir"
	.dexText "las catástrofes naturales."
	.dexText "Este POKéMON vive en hábitats"
	.dexText "montañosos, hostiles y accidentados"
	.dexText "de los que rara vez se aleja."
	.dexText ""

	.align 2, 0
dexEntryEu153:: @ 153 VULPIX
	.2byte 1, 5, 3
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 2, 1, 8, 10, 10, 10, 9, 9  @ weight
	.dexLang EN
	.dexName "VULPIX"
	.dexLang FR
	.dexName "GOUPIX"
	.dexLang DE
	.dexName "VULPIX"
	.dexLang EN
	.dexCategory "FOX"
	.dexLang FR
	.dexCategoryLeftAligned "RENARD"
	.dexLang DE
	.dexCategoryLeftAligned "FUCHS"
	.dexLang IT
	.dexCategoryLeftAligned "VOLPE"
	.dexLang ES
	.dexCategoryLeftAligned "ZORRO"
	.dexLang EN
	.dexText "At the time of its birth, VULPIX has one"
	.dexText "white tail. The tail separates into six"
	.dexText "if this POKéMON receives plenty of love"
	.dexText "from its TRAINER."
	.dexText "The six tails become magnificently"
	.dexText "curled."
	.dexLang FR
	.dexText "A sa naissance, GOUPIX a une queue"
	.dexText "blanche. Cette queue se divise en six"
	.dexText "si le POKéMON reçoit de l`amitié de la"
	.dexText "part de son DRESSEUR."
	.dexText "Les six queues sont courbées et"
	.dexText "magnifiques."
	.dexLang DE
	.dexText "VULPIX kommt mit einem weißen Schweif"
	.dexText "zur Welt. Dieser teilt sich sechsfach,"
	.dexText "wenn das POKéMON von seinem TRAINER"
	.dexText "viel Zuneigung bekommt."
	.dexText "Seine sechs Schweife kräuseln sich"
	.dexText "schließlich."
	.dexLang IT
	.dexText "Al momento della nascita VULPIX ha una"
	.dexText "sola coda bianca. Se il POKéMON riceve"
	.dexText "molto amore dal proprio ALLENATORE"
	.dexText "la coda si divide in sei diramazioni"
	.dexText "che poi si arricciano elegantemente."
	.dexText ""
	.dexLang ES
	.dexText "Al nacer, VULPIX tiene una cola blanca"
	.dexText "que se divide en seis si recibe cariño"
	.dexText "por parte de su ENTRENADOR."
	.dexText "Las seis colas se le rizan de forma"
	.dexText "majestuosa."
	.dexText ""

	.align 2, 0
dexEntryEu154:: @ 154 NINETALES
	.2byte 1, 5, 4
	.2byte 10, 3, 0, 7, 10, 10, 1, 1  @ height
	.2byte 10, 10, 4, 3, 9, 10, 10, 1, 9, 9  @ weight
	.dexLang EN
	.dexName "NINETALES"
	.dexLang FR
	.dexName "FEUNARD"
	.dexLang DE
	.dexName "VULNONA"
	.dexLang EN
	.dexCategory "FOX"
	.dexLang FR
	.dexCategoryLeftAligned "RENARD"
	.dexLang DE
	.dexCategoryLeftAligned "FUCHS"
	.dexLang IT
	.dexCategoryLeftAligned "VOLPE"
	.dexLang ES
	.dexCategoryLeftAligned "ZORRO"
	.dexLang EN
	.dexText "NINETALES casts a sinister light from"
	.dexText "its bright red eyes to gain total"
	.dexText "control over its foe`s mind."
	.dexText "This POKéMON is said to live for a"
	.dexText "thousand years."
	.dexText ""
	.dexLang FR
	.dexText "FEUNARD peut envoyer un inquiétant"
	.dexText "rayon avec ses yeux rouge vif pour"
	.dexText "prendre le contrôle de l`esprit de son"
	.dexText "ennemi. On raconte que ce POKéMON"
	.dexText "peut vivre mille ans."
	.dexText ""
	.dexLang DE
	.dexText "VULNONA sendet einen unheimlichen"
	.dexText "Lichtstrahl aus seinen hellroten Augen"
	.dexText "aus, um totale Kontrolle über die"
	.dexText "Gedanken seines Gegners zu erlangen."
	.dexText "Man sagt, dieses POKéMON könne 1000"
	.dexText "Jahre leben."
	.dexLang IT
	.dexText "NINETALES emana sinistri bagliori"
	.dexText "dai luminosi occhi rossi per acquisire"
	.dexText "il controllo totale della mente del suo"
	.dexText "nemico. Si dice che possa vivere"
	.dexText "anche per mille anni."
	.dexText ""
	.dexLang ES
	.dexText "NINETALES emite una siniestra luz a"
	.dexText "través de los brillantes ojos rojos que"
	.dexText "tiene, para conseguir controlar del todo"
	.dexText "la mente de su rival."
	.dexText "Dicen que este POKéMON llega a vivir"
	.dexText "miles de años."

	.align 2, 0
dexEntryEu155:: @ 155 PICHU
	.2byte 1, 5, 5
	.2byte 10, 1, 0, 0, 10, 10, 0, 3  @ height
	.2byte 10, 10, 10, 4, 4, 10, 10, 10, 2, 0  @ weight
	.dexLang EN
	.dexName "PICHU"
	.dexLang FR
	.dexName "PICHU"
	.dexLang DE
	.dexName "PICHU"
	.dexLang EN
	.dexCategory "TINY MOUSE"
	.dexLang FR
	.dexCategoryLeftAligned "MINISOURIS"
	.dexLang DE
	.dexCategoryLeftAligned "BABYMAUS"
	.dexLang IT
	.dexCategoryLeftAligned "TOPINO"
	.dexLang ES
	.dexCategoryLeftAligned "RATONCITO"
	.dexLang EN
	.dexText "PICHU charges itself with electricity"
	.dexText "more easily on days with thunderclouds"
	.dexText "or when the air is very dry."
	.dexText "You can hear the crackling of static"
	.dexText "electricity coming off this POKéMON."
	.dexText ""
	.dexLang FR
	.dexText "PICHU se charge plus facilement en"
	.dexText "électricité les jours d`orage ou lorsque"
	.dexText "l`air est très sec."
	.dexText "On peut entendre le crépitement"
	.dexText "de l`électricité statique générée par"
	.dexText "ce POKéMON."
	.dexLang DE
	.dexText "An Gewittertagen oder Tagen, an denen"
	.dexText "die Luft sehr trocken ist, kann sich"
	.dexText "PICHU leichter mit Elektrizität"
	.dexText "aufladen. Dann kann man das Knistern"
	.dexText "statischer Aufladung hören."
	.dexText ""
	.dexLang IT
	.dexText "PICHU si carica di elettricità più"
	.dexText "facilmente in caso di cielo coperto da"
	.dexText "nubi temporalesche o aria molto secca."
	.dexText "Spesso si può percepire lo scoppiettio"
	.dexText "della sua carica elettrostatica."
	.dexText ""
	.dexLang ES
	.dexText "A PICHU le resulta más fácil cargarse"
	.dexText "de electricidad en días de nubarrones"
	.dexText "o cuando sopla un aire muy seco."
	.dexText "Es posible oír la electricidad estática"
	.dexText "que emana este POKéMON."
	.dexText ""

	.align 2, 0
dexEntryEu156:: @ 156 PIKACHU
	.2byte 1, 5, 6
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 1, 3, 2, 10, 10, 10, 6, 0  @ weight
	.dexLang EN
	.dexName "PIKACHU"
	.dexLang FR
	.dexName "PIKACHU"
	.dexLang DE
	.dexName "PIKACHU"
	.dexLang EN
	.dexCategory "MOUSE"
	.dexLang FR
	.dexCategoryLeftAligned "SOURIS"
	.dexLang DE
	.dexCategoryLeftAligned "MAUS"
	.dexLang IT
	.dexCategoryLeftAligned "TOPO"
	.dexLang ES
	.dexCategoryLeftAligned "RATÓN"
	.dexLang EN
	.dexText "Whenever PIKACHU comes across"
	.dexText "something new, it blasts it with a jolt"
	.dexText "of electricity."
	.dexText "If you come across a blackened berry,"
	.dexText "it`s evidence that this POKéMON"
	.dexText "mistook the intensity of its charge."
	.dexLang FR
	.dexText "Chaque fois que PIKACHU découvre"
	.dexText "quelque chose de nouveau, il envoie"
	.dexText "un arc électrique. Lorsqu`on tombe"
	.dexText "sur une BAIE carbonisée, ça signifie"
	.dexText "sans doute qu`un de ces POKéMON"
	.dexText "a envoyé une charge trop forte."
	.dexLang DE
	.dexText "Immer wenn PIKACHU auf etwas Neues"
	.dexText "stößt, jagt es einen Elektroschock"
	.dexText "hindurch."
	.dexText "Wenn du eine verkohlte Beere findest,"
	.dexText "hat dieses POKéMON seine elektrische"
	.dexText "Ladung falsch eingeschätzt."
	.dexLang IT
	.dexText "Quando PIKACHU incontra qualcosa"
	.dexText "che non conosce, lo colpisce con"
	.dexText "una scarica elettrica."
	.dexText "Quando si vede una bacca annerita,"
	.dexText "è evidente che questo POKéMON"
	.dexText "ha emesso una scossa troppo forte."
	.dexLang ES
	.dexText "Cada vez que PIKACHU se encuentra"
	.dexText "con algo nuevo, le lanza una sacudida"
	.dexText "eléctrica."
	.dexText "Si ves alguna BAYA chamuscada, seguro"
	.dexText "que ha sido PIKACHU; a veces no"
	.dexText "controla la intensidad de la descarga."

	.align 2, 0
dexEntryEu157:: @ 157 RAICHU
	.2byte 1, 5, 7
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 6, 6, 1, 10, 10, 3, 0, 0  @ weight
	.dexLang EN
	.dexName "RAICHU"
	.dexLang FR
	.dexName "RAICHU"
	.dexLang DE
	.dexName "RAICHU"
	.dexLang EN
	.dexCategory "MOUSE"
	.dexLang FR
	.dexCategoryLeftAligned "SOURIS"
	.dexLang DE
	.dexCategoryLeftAligned "MAUS"
	.dexLang IT
	.dexCategoryLeftAligned "TOPO"
	.dexLang ES
	.dexCategoryLeftAligned "RATÓN"
	.dexLang EN
	.dexText "If the electrical sacks become"
	.dexText "excessively charged, RAICHU plants its"
	.dexText "tail in the ground and discharges."
	.dexText "Scorched patches of ground will be"
	.dexText "found near this POKéMON`s nest."
	.dexText ""
	.dexLang FR
	.dexText "Si ses joues contiennent trop"
	.dexText "d`électricité, RAICHU plante sa queue"
	.dexText "dans le sol pour se décharger."
	.dexText "On trouve des parcelles de terre brûlée"
	.dexText "à proximité du nid de ce POKéMON."
	.dexText ""
	.dexLang DE
	.dexText "Wenn seine elektrische Ladung zu groß"
	.dexText "wird, entlädt RAICHU seine Energie ins"
	.dexText "Erdreich."
	.dexText "Neben dem Nest dieses POKéMON findet"
	.dexText "man häufig versengtes Erdreich."
	.dexText ""
	.dexLang IT
	.dexText "Se l`elettricità accumulata nelle guance"
	.dexText "diventa eccessiva, RAICHU la scarica"
	.dexText "piantando la coda nel terreno."
	.dexText "Vicino al suo nido sono presenti"
	.dexText "spesso chiazze di erba arsa."
	.dexText ""
	.dexLang ES
	.dexText "Si las bolsas de los mofletes se le"
	.dexText "cargan demasiado, RAICHU planta"
	.dexText "la cola en el suelo para liberar"
	.dexText "electricidad. Es común encontrar"
	.dexText "zonas chamuscadas cerca de la"
	.dexText "madriguera de este POKéMON."

	.align 2, 0
dexEntryEu158:: @ 158 PSYDUCK
	.2byte 1, 5, 8
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 4, 3, 2, 10, 10, 1, 9, 6  @ weight
	.dexLang EN
	.dexName "PSYDUCK"
	.dexLang FR
	.dexName "PSYKOKWAK"
	.dexLang DE
	.dexName "ENTON"
	.dexLang EN
	.dexCategory "DUCK"
	.dexLang FR
	.dexCategoryLeftAligned "CANARD"
	.dexLang DE
	.dexCategoryLeftAligned "ENTE"
	.dexLang IT
	.dexCategoryLeftAligned "PAPERO"
	.dexLang ES
	.dexCategoryLeftAligned "PATO"
	.dexLang EN
	.dexText "PSYDUCK uses a mysterious power."
	.dexText "When it does so, this POKéMON"
	.dexText "generates brain waves that are"
	.dexText "supposedly only seen in sleepers."
	.dexText "This discovery spurred controversy"
	.dexText "among scholars."
	.dexLang FR
	.dexText "PSYKOKWAK utilise un mystérieux"
	.dexText "pouvoir. Ce POKéMON peut générer"
	.dexText "des ondes cérébrales normalement"
	.dexText "observées chez les dormeurs."
	.dexText "Cette découverte a lancé une polémique"
	.dexText "dans le milieu universitaire."
	.dexLang DE
	.dexText "ENTON verwendet eine geheimnisvolle"
	.dexText "Kraft. Dabei erzeugt es Gehirnströme,"
	.dexText "die man sonst nur von Schlafenden"
	.dexText "kennt. Diese Entdeckung führte zu"
	.dexText "einer umstrittenen Diskussion unter"
	.dexText "Wissenschaftlern."
	.dexLang IT
	.dexText "PSYDUCK usa poteri misteriosi, che"
	.dexText "scatenano onde cerebrali rilevabili"
	.dexText "apparentemente soltanto su persone"
	.dexText "in stato di sonno. Questa scoperta"
	.dexText "ha causato reazioni contrastanti"
	.dexText "tra gli studiosi."
	.dexLang ES
	.dexText "PSYDUCK tiene un extraño poder,"
	.dexText "que consiste en generar ondas"
	.dexText "cerebrales iguales a las que se"
	.dexText "generan cuando se está dormido."
	.dexText "Este descubrimiento levantó una"
	.dexText "gran polémica entre eruditos."

	.align 2, 0
dexEntryEu159:: @ 159 GOLDUCK
	.2byte 1, 5, 9
	.2byte 10, 5, 0, 7, 10, 10, 1, 7  @ height
	.2byte 10, 1, 6, 8, 9, 10, 10, 7, 6, 6  @ weight
	.dexLang EN
	.dexName "GOLDUCK"
	.dexLang FR
	.dexName "AKWAKWAK"
	.dexLang DE
	.dexName "ENTORON"
	.dexLang EN
	.dexCategory "DUCK"
	.dexLang FR
	.dexCategoryLeftAligned "CANARD"
	.dexLang DE
	.dexCategoryLeftAligned "ENTE"
	.dexLang IT
	.dexCategoryLeftAligned "PAPERO"
	.dexLang ES
	.dexCategoryLeftAligned "PATO"
	.dexLang EN
	.dexText "The webbed flippers on its forelegs and"
	.dexText "hind legs and the streamlined body of"
	.dexText "GOLDUCK give it frightening speed."
	.dexText "This POKéMON is definitely much faster"
	.dexText "than even the most athletic swimmer."
	.dexText ""
	.dexLang FR
	.dexText "Les pattes avant et arrière palmées et"
	.dexText "le corps aérodynamique d`AKWAKWAK lui"
	.dexText "donnent une vitesse effrayante."
	.dexText "Ce POKéMON est bien plus rapide que les"
	.dexText "plus grands champions de natation."
	.dexText ""
	.dexLang DE
	.dexText "Die schwimmhäutigen Flossen an seinen"
	.dexText "Vorder- und Hinterbeinen und der"
	.dexText "stromlinienförmige Körper machen"
	.dexText "ENTORON unheimlich schnell. Dieses"
	.dexText "POKéMON ist auf jeden Fall schneller als"
	.dexText "die meisten Hochleistungsschwimmer."
	.dexLang IT
	.dexText "Le zampe anteriori e posteriori a pinna"
	.dexText "dotate di membrana interdigitale e"
	.dexText "il corpo longilineo di GOLDUCK"
	.dexText "gli conferiscono una velocità incre-"
	.dexText "dibile. Infatti è molto più veloce dei"
	.dexText "più esperti nuotatori umani."
	.dexLang ES
	.dexText "GOLDUCK alcanza una velocidad de"
	.dexText "vértigo gracias a las aletas palmípedas"
	.dexText "de las extremidades y a la forma"
	.dexText "aerodinámica de su cuerpo. Realmente,"
	.dexText "la velocidad de este POKéMON supera"
	.dexText "la de cualquier nadador."

	.align 2, 0
dexEntryEu160:: @ 160 WYNAUT
	.2byte 1, 6, 0
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 3, 0, 9, 10, 10, 1, 4, 0  @ weight
	.dexLang EN
	.dexName "WYNAUT"
	.dexLang FR
	.dexName "OKEOKE"
	.dexLang DE
	.dexName "ISSO"
	.dexLang EN
	.dexCategory "BRIGHT"
	.dexLang FR
	.dexCategoryLeftAligned "RAVI"
	.dexLang DE
	.dexCategoryLeftAligned "STRAHLEKIND"
	.dexLang IT
	.dexCategoryLeftAligned "BRILLANTE"
	.dexLang ES
	.dexCategoryLeftAligned "RADIANTE"
	.dexLang EN
	.dexText "WYNAUT can always be seen with a big,"
	.dexText "happy smile on its face. Look at its tail"
	.dexText "to determine if it is angry."
	.dexText "When angered, this POKéMON will be"
	.dexText "slapping the ground with its tail."
	.dexText ""
	.dexLang FR
	.dexText "OKEOKE a toujours un grand sourire"
	.dexText "qui illumine son visage. On peut savoir"
	.dexText "s`il est en colère en regardant sa queue."
	.dexText "Lorsqu`il est furieux, sa queue"
	.dexText "remue en frappant le sol."
	.dexText ""
	.dexLang DE
	.dexText "ISSO hat immer ein breites, fröhliches"
	.dexText "Lächeln auf seinem Gesicht. Um"
	.dexText "festzustellen, ob es wütend ist, muss"
	.dexText "man seinen Schweif betrachten. Wenn es"
	.dexText "wütend ist, schlägt es damit auf den"
	.dexText "Boden."
	.dexLang IT
	.dexText "WYNAUT ha sempre un sorriso grande e"
	.dexText "genuino stampato sul volto. La coda"
	.dexText "è indice del suo vero stato d`animo."
	.dexText "Se la sbatte violentemente a terra,"
	.dexText "significa che è infuriato."
	.dexText ""
	.dexLang ES
	.dexText "WYNAUT está siempre con una gran"
	.dexText "sonrisa puesta. Para ver si está"
	.dexText "enfadado, basta con mirarle la cola."
	.dexText "Cuando se le molesta, se pone a dar"
	.dexText "golpetazos en el suelo."
	.dexText ""

	.align 2, 0
dexEntryEu161:: @ 161 WOBBUFFET
	.2byte 1, 6, 1
	.2byte 10, 4, 0, 3, 10, 10, 1, 3  @ height
	.2byte 10, 10, 6, 2, 8, 10, 10, 2, 8, 5  @ weight
	.dexLang EN
	.dexName "WOBBUFFET"
	.dexLang FR
	.dexName "QULBUTOKE"
	.dexLang DE
	.dexName "WOINGENAU"
	.dexLang EN
	.dexCategory "PATIENT"
	.dexLang FR
	.dexCategoryLeftAligned "PATIENT"
	.dexLang DE
	.dexCategoryLeftAligned "GEDULD"
	.dexLang IT
	.dexCategoryLeftAligned "PAZIENZA"
	.dexLang ES
	.dexCategoryLeftAligned "PACIENTE"
	.dexLang EN
	.dexText "If two or more WOBBUFFET meet, they will"
	.dexText "turn competitive and try to outdo each"
	.dexText "other`s endurance."
	.dexText "However, they may try to see which one"
	.dexText "can endure the longest without food."
	.dexText "TRAINERS need to beware of this habit."
	.dexLang FR
	.dexText "Si un ou plusieurs QULBUTOKE se ren-"
	.dexText "contrent, ils se mesurent les uns aux"
	.dexText "autres et font des concours d`endu-"
	.dexText "rance. Parfois, ils tentent de voir qui"
	.dexText "peut rester le plus longtemps sans"
	.dexText "manger. Mieux vaut être prévenu."
	.dexLang DE
	.dexText "Wenn zwei oder mehr WOINGENAU"
	.dexText "aufeinander treffen, versuchen sie,"
	.dexText "gegenseitig ihre Geduld zu übertreffen."
	.dexText "Sie möchten herausfinden, welches"
	.dexText "POKéMON es am längsten ohne Nahrung"
	.dexText "aushält. Darauf müssen Trainer achten."
	.dexLang IT
	.dexText "Quando due o più WOBBUFFET si incon-"
	.dexText "trano, diventano competitivi tentando"
	.dexText "di vanificare la reciproca resistenza."
	.dexText "Talvolta fanno anche a gara per vedere"
	.dexText "chi resiste di più senza cibo. Gli"
	.dexText "ALLENATORI devono fare attenzione."
	.dexLang ES
	.dexText "Si dos o más WOBBUFFET se encuentran,"
	.dexText "se volverán competitivos e intentarán"
	.dexText "superarse en resistencia. Pero también"
	.dexText "puede que intenten aguantar sin"
	.dexText "comer; algo que los ENTRENADORES"
	.dexText "deben tener muy en cuenta."

	.align 2, 0
dexEntryEu162:: @ 162 NATU
	.2byte 1, 6, 2
	.2byte 10, 0, 0, 8, 10, 10, 0, 2  @ height
	.2byte 10, 10, 10, 4, 4, 10, 10, 10, 2, 0  @ weight
	.dexLang EN
	.dexName "NATU"
	.dexLang FR
	.dexName "NATU"
	.dexLang DE
	.dexName "NATU"
	.dexLang EN
	.dexCategory "TINY BIRD"
	.dexLang FR
	.dexCategoryLeftAligned "MINOISEAU"
	.dexLang DE
	.dexCategoryLeftAligned "KLEINVOGEL"
	.dexLang IT
	.dexCategoryLeftAligned "UCCELLINO"
	.dexLang ES
	.dexCategoryLeftAligned "PAJARITO"
	.dexLang EN
	.dexText "NATU cannot fly because its wings are"
	.dexText "not yet fully grown. If your eyes meet"
	.dexText "with this POKéMON`s eyes, it will stare"
	.dexText "back intently at you. But if you move"
	.dexText "even slightly, it will hop away to safety."
	.dexText ""
	.dexLang FR
	.dexText "NATU ne peut pas voler, car ses ailes"
	.dexText "n`ont pas encore fini de grandir. Si ses"
	.dexText "yeux croisent le regard de quelqu`un"
	.dexText "d`autre, il reste immobile et concentré."
	.dexText "Mais si la personne en question détour-"
	.dexText "ne son regard, il s`enfuit en lieu sûr."
	.dexLang DE
	.dexText "NATU kann nicht fliegen, da seine Flügel"
	.dexText "noch nicht ausgewachsen sind. Wenn du"
	.dexText "diesem POKéMON in die Augen schaust,"
	.dexText "starrt es dich konzentriert an. Wenn du"
	.dexText "dich aber bewegst, hüpft es weg, um sich"
	.dexText "in Sicherheit zu bringen."
	.dexLang IT
	.dexText "NATU non riesce a volare a causa delle"
	.dexText "ali non ancora totalmente sviluppate."
	.dexText "Se lo si guarda negli occhi, ricambia"
	.dexText "lo sguardo, ma al primo movimento"
	.dexText "scappa via per mettersi al sicuro."
	.dexText ""
	.dexLang ES
	.dexText "NATU no puede volar porque las alas"
	.dexText "no le han crecido lo suficiente."
	.dexText "Si tu mirada se cruza con la suya,"
	.dexText "te la devolverá fijamente. Pero si haces"
	.dexText "el mínimo movimiento, huirá dando"
	.dexText "saltitos para ponerse a salvo."

	.align 2, 0
dexEntryEu163:: @ 163 XATU
	.2byte 1, 6, 3
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 10, 3, 3, 1, 10, 10, 1, 5, 0  @ weight
	.dexLang EN
	.dexName "XATU"
	.dexLang FR
	.dexName "XATU"
	.dexLang DE
	.dexName "XATU"
	.dexLang EN
	.dexCategory "MYSTIC"
	.dexLang FR
	.dexCategoryLeftAligned "MYSTIQUE"
	.dexLang DE
	.dexCategoryLeftAligned "MYSTIK"
	.dexLang IT
	.dexCategoryLeftAligned "MAGICO"
	.dexLang ES
	.dexCategoryLeftAligned "MÍSTICO"
	.dexLang EN
	.dexText "XATU stands rooted and still in one"
	.dexText "spot all day long. People believe that"
	.dexText "this POKéMON does so out of fear of"
	.dexText "the terrible things it has foreseen in"
	.dexText "the future."
	.dexText ""
	.dexLang FR
	.dexText "XATU se tient debout et immobile toute"
	.dexText "la journée. Certains pensent que ce"
	.dexText "POKéMON a adopté cette position"
	.dexText "à cause de la terreur qu`il a ressentie"
	.dexText "en prévoyant l`avenir."
	.dexText ""
	.dexLang DE
	.dexText "XATU bleibt den ganzen Tag an ein und"
	.dexText "demselben Ort wie angewurzelt stehen."
	.dexText "Die Menschen glauben, dass es dies aus"
	.dexText "Angst vor den Dingen tut, die es für die"
	.dexText "Zukunft vorausgesehen hat."
	.dexText ""
	.dexLang IT
	.dexText "XATU rimane in piedi immobile nello"
	.dexText "stesso punto tutto il giorno."
	.dexText ""
	.dexText "Qualcuno crede che si comporti così"
	.dexText "per gli eventi terribili che ha previsto"
	.dexText "per il futuro."
	.dexLang ES
	.dexText "XATU permanece de pie inmóvil y"
	.dexText "tranquilo en el mismo sitio durante"
	.dexText "todo el día."
	.dexText "Se cree que no se mueve por temor"
	.dexText "a lo que ha visto que ocurrirá"
	.dexText "en el futuro."

	.align 2, 0
dexEntryEu164:: @ 164 GIRAFARIG
	.2byte 1, 6, 4
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 10, 9, 1, 5, 10, 10, 4, 1, 5  @ weight
	.dexLang EN
	.dexName "GIRAFARIG"
	.dexLang FR
	.dexName "GIRAFARIG"
	.dexLang DE
	.dexName "GIRAFARIG"
	.dexLang EN
	.dexCategory "LONG NECK"
	.dexLang FR
	.dexCategoryLeftAligned "LONG-COU"
	.dexLang DE
	.dexCategoryLeftAligned "LANGHALS"
	.dexLang IT
	.dexCategoryLeftAligned "LUNGOCOLLO"
	.dexLang ES
	.dexCategoryLeftAligned "GRANCUELLO"
	.dexLang EN
	.dexText "GIRAFARIG`s rear head also has a brain,"
	.dexText "but it is small. The rear head attacks in"
	.dexText "response to smells and sounds."
	.dexText "Approaching this POKéMON from behind"
	.dexText "can cause the rear head to suddenly"
	.dexText "lash out and bite."
	.dexLang FR
	.dexText "La tête à l`arrière de GIRAFARIG a aussi"
	.dexText "un cerveau, mais il est plus petit. Elle"
	.dexText "attaque en réponse aux sons et"
	.dexText "aux odeurs. Si on approche de ce"
	.dexText "POKéMON par derrière, cette petite"
	.dexText "tête peut tout à coup jaillir et mordre."
	.dexLang DE
	.dexText "Der Kopf an GIRAFARIGs Hinterteil hat"
	.dexText "ein eigenes Gehirn. Er reagiert mit"
	.dexText "Angriffen auf Gerüche und Geräusche."
	.dexText "Wenn man sich diesem POKéMON von"
	.dexText "hinten nähert, könnte der hintere Kopf"
	.dexText "plötzlich vorschnellen und zubeißen."
	.dexLang IT
	.dexText "La testa posteriore di GIRAFARIG è"
	.dexText "dotata di un cervello piccolissimo, che"
	.dexText "attacca soltanto in risposta agli odori"
	.dexText "e ai suoni. Avvicinando questo POKéMON"
	.dexText "da dietro sussiste il pericolo di essere"
	.dexText "morsi dalla testa posteriore."
	.dexLang ES
	.dexText "GIRAFARIG tiene un cerebro también"
	.dexText "en la cabeza trasera, que reacciona"
	.dexText "atacando ante olores y sonidos."
	.dexText "Si te acercas a este POKéMON desde"
	.dexText "atrás, puedes provocar que la cabeza"
	.dexText "trasera salga de repente y te muerda."

	.align 2, 0
dexEntryEu165:: @ 165 PHANPY
	.2byte 1, 6, 5
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 7, 3, 9, 10, 10, 3, 3, 5  @ weight
	.dexLang EN
	.dexName "PHANPY"
	.dexLang FR
	.dexName "PHANPY"
	.dexLang DE
	.dexName "PHANPY"
	.dexLang EN
	.dexCategory "LONG NOSE"
	.dexLang FR
	.dexCategoryLeftAligned "LONG-NEZ"
	.dexLang DE
	.dexCategoryLeftAligned "LANGRÜSSEL"
	.dexLang IT
	.dexCategoryLeftAligned "NASONE"
	.dexLang ES
	.dexCategoryLeftAligned "NARIZOTAS"
	.dexLang EN
	.dexText "PHANPY uses its long nose to shower"
	.dexText "itself. When others gather around, they"
	.dexText "thoroughly douse each other with"
	.dexText "water. These POKéMON can be seen"
	.dexText "drying their soaking-wet bodies at the"
	.dexText "edge of water."
	.dexLang FR
	.dexText "PHANPY utilise sa petite trompe pour se"
	.dexText "doucher. Quand plusieurs d`entre eux se"
	.dexText "réunissent, ils s`arrosent joyeusement."
	.dexText "On peut souvent voir ces POKéMON"
	.dexText "se sécher au bord de l`eau."
	.dexText ""
	.dexLang DE
	.dexText "PHANPY kann sich mit seiner langen Nase"
	.dexText "selbst duschen. Wenn andere dabei sind,"
	.dexText "begießen sie sich gegenseitig mit"
	.dexText "Wasser. Danach trocknet es seinen"
	.dexText "durchnässten Körper am Ufer."
	.dexText ""
	.dexLang IT
	.dexText "PHANPY usa la lunga proboscide per"
	.dexText "farsi la doccia. Questi POKéMON sono"
	.dexText "soliti raggrupparsi per spruzzarsi"
	.dexText "d`acqua a vicenda."
	.dexText "Poi, è frequente vederli mentre si"
	.dexText "asciugano il corpo fradicio a riva."
	.dexLang ES
	.dexText "PHANPY se vale de la larga trompa"
	.dexText "para ducharse. Mientras otros"
	.dexText "se agrupan a su alrededor, se dedican"
	.dexText "a echarse agua unos a otros."
	.dexText "Es muy fácil ver a estos POKéMON"
	.dexText "secándose cerca del agua."

	.align 2, 0
dexEntryEu166:: @ 166 DONPHAN
	.2byte 1, 6, 6
	.2byte 10, 3, 0, 7, 10, 10, 1, 1  @ height
	.2byte 10, 2, 6, 4, 6, 10, 1, 2, 0, 0  @ weight
	.dexLang EN
	.dexName "DONPHAN"
	.dexLang FR
	.dexName "DONPHAN"
	.dexLang DE
	.dexName "DONPHAN"
	.dexLang EN
	.dexCategory "ARMOR"
	.dexLang FR
	.dexCategoryLeftAligned "ARMURE"
	.dexLang DE
	.dexCategoryLeftAligned "PANZERTIER"
	.dexLang IT
	.dexCategoryLeftAligned "ARMATURA"
	.dexLang ES
	.dexCategoryLeftAligned "CORAZA"
	.dexLang EN
	.dexText "If DONPHAN were to tackle with its hard"
	.dexText "body, even a house could be destroyed."
	.dexText "Using its massive strength, the"
	.dexText "POKéMON helps clear rock and mud slides"
	.dexText "that block mountain trails."
	.dexText ""
	.dexLang FR
	.dexText "Si DONPHAN décidait de charger, il"
	.dexText "pourrait détruire une maison."
	.dexText "Grâce à sa force étonnante, ce"
	.dexText "POKéMON peut aider à déplacer les"
	.dexText "rochers et les coulées de boue qui"
	.dexText "bloquent les chemins de montagne."
	.dexLang DE
	.dexText "DONPHAN kann mit seinem harten Körper"
	.dexText "sogar ein Haus zerstören. Mit seiner"
	.dexText "imposanten Kraft hilft dieses POKéMON"
	.dexText "dabei, Erdrutsche aus dem Weg zu"
	.dexText "räumen, die Bergpfade versperren."
	.dexText ""
	.dexLang IT
	.dexText "Il massiccio corpo di DONPHAN dispone"
	.dexText "di una forza tale da poter abbattere"
	.dexText "persino una casa. La sua incredibile"
	.dexText "potenza aiuta a liberare i sentieri"
	.dexText "montani dopo una frana di massi"
	.dexText "o fango."
	.dexLang ES
	.dexText "Si DONPHAN tuviera que dar un golpe"
	.dexText "con todo el cuerpo, con lo robusto"
	.dexText "que es echaría abajo hasta una casa."
	.dexText "Estos POKéMON usan su fuerza para"
	.dexText "ayudar a despejar pasos de montaña"
	.dexText "cuando hay piedras o lodo."

	.align 2, 0
dexEntryEu167:: @ 167 PINSIR
	.2byte 1, 6, 7
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 1, 2, 1, 3, 10, 10, 5, 5, 0  @ weight
	.dexLang EN
	.dexName "PINSIR"
	.dexLang FR
	.dexName "SCARABRUTE"
	.dexLang DE
	.dexName "PINSIR"
	.dexLang EN
	.dexCategory "STAG BEETLE"
	.dexLang FR
	.dexCategoryLeftAligned "SCARABEE"
	.dexLang DE
	.dexCategoryLeftAligned "KNEIFKÄFER"
	.dexLang IT
	.dexCategoryLeftAligned "CERVOLANTE"
	.dexLang ES
	.dexCategoryLeftAligned "ESCARABAJO"
	.dexLang EN
	.dexText "PINSIR is astoundingly strong. It can"
	.dexText "grip a foe weighing twice its weight"
	.dexText "in its horns and easily lift it."
	.dexText "This POKéMON`s movements turn sluggish"
	.dexText "in cold places."
	.dexText ""
	.dexLang FR
	.dexText "SCARABRUTE est incroyablement fort."
	.dexText "Il peut attraper un ennemi qui pèse"
	.dexText "deux fois son poids dans ses mandibules"
	.dexText "et le soulever sans le moindre problème."
	.dexText "Lorsqu`il fait froid, les mouvements de"
	.dexText "ce POKéMON sont un peu ralentis."
	.dexLang DE
	.dexText "PINSIR ist erstaunlich stark. Es kann"
	.dexText "einen Feind, der doppelt so viel wiegt"
	.dexText "wie es selbst, mit seinen Hörnern"
	.dexText "packen und hochheben. Bei niedrigen"
	.dexText "Temperaturen werden die Bewegungen"
	.dexText "dieses POKéMON schwerfällig."
	.dexLang IT
	.dexText "PINSIR è incredibilmente forte. Può"
	.dexText "afferrare e sollevare tra le chele sul"
	.dexText "capo un nemico dal peso doppio rispetto"
	.dexText "al suo. I suoi movimenti sono impacciati"
	.dexText "in luoghi freddi."
	.dexText ""
	.dexLang ES
	.dexText "PINSIR es sorprendentemente grande."
	.dexText "Puede agarrar con los cuernos a un rival"
	.dexText "que pese el doble que él y levantarlo por"
	.dexText "los aires."
	.dexText "En zonas frías, los movimientos de este"
	.dexText "POKéMON se vuelven lentos."

	.align 2, 0
dexEntryEu168:: @ 168 HERACROSS
	.2byte 1, 6, 8
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 1, 1, 9, 0, 10, 10, 5, 4, 0  @ weight
	.dexLang EN
	.dexName "HERACROSS"
	.dexLang FR
	.dexName "SCARHINO"
	.dexLang DE
	.dexName "SKARABORN"
	.dexLang EN
	.dexCategory "SINGLE HORN"
	.dexLang FR
	.dexCategoryLeftAligned "UNICORNE"
	.dexLang DE
	.dexCategoryLeftAligned "EINZELHORN"
	.dexLang IT
	.dexCategoryLeftAligned "MONOCORNO"
	.dexLang ES
	.dexCategoryLeftAligned "UNICORNIO"
	.dexLang EN
	.dexText "HERACROSS charges in a straight line at"
	.dexText "its foe, slips beneath the foe`s grasp,"
	.dexText "and then scoops up and hurls the"
	.dexText "opponent with its mighty horn."
	.dexText "This POKéMON even has enough power"
	.dexText "to topple a massive tree."
	.dexLang FR
	.dexText "SCARHINO charge ses ennemis en ligne"
	.dexText "droite, se glisse dessous, les attrape"
	.dexText "et les projette violemment d`un coup"
	.dexText "de sa puissante corne. Ce POKéMON est"
	.dexText "tellement fort qu`il pourrait"
	.dexText "déraciner un arbre."
	.dexLang DE
	.dexText "SKARABORN geht direkt auf seinen"
	.dexText "Gegner los, rutscht auf ihn zu, um ihn"
	.dexText "auszuhebeln und mit seinem mächtigen"
	.dexText "Horn wegzuschleudern. Dieses POKéMON"
	.dexText "hat genug Kraft, um einen massigen"
	.dexText "Baum umzustoßen."
	.dexLang IT
	.dexText "HERACROSS si lancia all`attacco dritto"
	.dexText "contro il nemico, lo afferra con forza,"
	.dexText "lo solleva in aria e poi lo incorna"
	.dexText "violentemente scagliandolo lontano."
	.dexText "Riesce ad abbattere un grosso albero."
	.dexText ""
	.dexLang ES
	.dexText "HERACROSS carga en línea recta contra"
	.dexText "el enemigo, se le queda encajado por"
	.dexText "debajo, lo agarra y lo lanza con ayuda"
	.dexText "del fuerte cuerno que tiene."
	.dexText "Este POKéMON tiene fuerza hasta para"
	.dexText "echar abajo un árbol descomunal."

	.align 2, 0
dexEntryEu169:: @ 169 RHYHORN
	.2byte 1, 6, 9
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 2, 5, 3, 5, 10, 1, 1, 5, 0  @ weight
	.dexLang EN
	.dexName "RHYHORN"
	.dexLang FR
	.dexName "RHINOCORNE"
	.dexLang DE
	.dexName "RIHORN"
	.dexLang EN
	.dexCategory "SPIKES"
	.dexLang FR
	.dexCategoryLeftAligned "PIQUANT"
	.dexLang DE
	.dexCategoryLeftAligned "STACHLER"
	.dexLang IT
	.dexCategoryLeftAligned "PUNZONI"
	.dexLang ES
	.dexCategoryLeftAligned "CLAVOS"
	.dexLang EN
	.dexText "RHYHORN runs in a straight line,"
	.dexText "smashing everything in its path."
	.dexText "It is not bothered even if it rushes"
	.dexText "headlong into a block of steel."
	.dexText "This POKéMON may feel some pain from"
	.dexText "the collision the next day, however."
	.dexLang FR
	.dexText "RHINOCORNE charge droit devant lui,"
	.dexText "détruisant tout sur son passage. Il"
	.dexText "ne s`arrête jamais, même lorsqu`il charge"
	.dexText "un bloc d`acier. Malgré tout, il sent"
	.dexText "la douleur le lendemain."
	.dexText ""
	.dexLang DE
	.dexText "RIHORN läuft immer geradeaus und"
	.dexText "zerstampft alles, was ihm in die Quere"
	.dexText "kommt. Es macht ihm auch nichts aus,"
	.dexText "wenn es mit dem Kopf voran gegen einen"
	.dexText "Stahlklotz rennt. Am nächsten Tag"
	.dexText "allerdings könnte es Schmerzen haben."
	.dexLang IT
	.dexText "RHYHORN corre diritto per la sua strada"
	.dexText "fracassando tutto ciò che trova."
	.dexText "Non si scompone nemmeno scontrandosi"
	.dexText "con un blocco d`acciaio."
	.dexText "Tuttavia, il giorno seguente può"
	.dexText "accusare qualche dolore."
	.dexLang ES
	.dexText "RHYHORN corre en línea recta arrasando"
	.dexText "todo lo que encuentra en su camino."
	.dexText "Aun estrellándose de cabeza"
	.dexText "contra un bloque de acero, no se vería"
	.dexText "afectado. Bueno, como mucho notaría"
	.dexText "algo de dolor al día siguiente."

	.align 2, 0
dexEntryEu170:: @ 170 RHYDON
	.2byte 1, 7, 0
	.2byte 10, 6, 0, 3, 10, 10, 1, 9  @ height
	.2byte 10, 2, 6, 4, 6, 10, 1, 2, 0, 0  @ weight
	.dexLang EN
	.dexName "RHYDON"
	.dexLang FR
	.dexName "RHINOFEROS"
	.dexLang DE
	.dexName "RIZEROS"
	.dexLang EN
	.dexCategory "DRILL"
	.dexLang FR
	.dexCategoryLeftAligned "PERCEUR"
	.dexLang DE
	.dexCategoryLeftAligned "BOHRER"
	.dexLang IT
	.dexCategoryLeftAligned "TRAPANO"
	.dexLang ES
	.dexCategoryLeftAligned "TALADRO"
	.dexLang EN
	.dexText "RHYDON`s horn can crush even uncut"
	.dexText "diamonds. One sweeping blow of its tail"
	.dexText "can topple a building."
	.dexText "This POKéMON`s hide is extremely tough."
	.dexText "Even direct cannon hits don`t leave"
	.dexText "a scratch."
	.dexLang FR
	.dexText "La corne de RHINOFEROS peut même"
	.dexText "casser du diamant brut. Et avec un"
	.dexText "simple coup de queue, il peut détruire"
	.dexText "un bâtiment. La peau de ce POKéMON est"
	.dexText "incroyablement dure. Un boulet de canon"
	.dexText "ne lui ferait même pas une égratignure."
	.dexLang DE
	.dexText "Mit seinem Horn kann RIZEROS selbst"
	.dexText "Diamanten zerbrechen. Ein einziger"
	.dexText "Hieb mit seinem Schweif kann ein Haus"
	.dexText "zum Einsturz bringen. Die Haut dieses"
	.dexText "POKéMON ist so hart, dass nicht einmal"
	.dexText "Kanonenkugeln Kratzer hinterlassen."
	.dexLang IT
	.dexText "Il corno di RHYDON riesce a fracassare"
	.dexText "anche un diamante grezzo. Un colpo"
	.dexText "della sua coda abbatte un edificio."
	.dexText "La pelle-armatura di questo POKéMON è"
	.dexText "così coriacea da essere immune anche"
	.dexText "alle cannonate."
	.dexLang ES
	.dexText "RHYDON tiene un cuerno capaz de"
	.dexText "horadar hasta un diamante en bruto."
	.dexText "Y con una sacudida de la cola puede"
	.dexText "derribar un edificio. La piel de este"
	.dexText "POKéMON es muy fuerte; ni los disparos"
	.dexText "de un cañón le arañarían."

	.align 2, 0
dexEntryEu171:: @ 171 SNORUNT
	.2byte 1, 7, 1
	.2byte 10, 2, 0, 4, 10, 10, 0, 7  @ height
	.2byte 10, 10, 3, 7, 0, 10, 10, 1, 6, 8  @ weight
	.dexLang EN
	.dexName "SNORUNT"
	.dexLang FR
	.dexName "STALGAMIN"
	.dexLang DE
	.dexName "SCHNEPPKE"
	.dexLang EN
	.dexCategory "SNOW HAT"
	.dexLang FR
	.dexCategoryLeftAligned "CAPUCHE"
	.dexLang DE
	.dexCategoryLeftAligned "SCHNEEHUT"
	.dexLang IT
	.dexCategoryLeftAligned "CAPPELNEVE"
	.dexLang ES
	.dexCategoryLeftAligned "GORRO NIEVE"
	.dexLang EN
	.dexText "SNORUNT live in regions with heavy"
	.dexText "snowfall. In seasons without snow, such"
	.dexText "as spring and summer, this POKéMON"
	.dexText "steals away to live quietly among"
	.dexText "stalactites and stalagmites deep in"
	.dexText "caverns."
	.dexLang FR
	.dexText "Les STALGAMIN vivent dans les régions"
	.dexText "enneigées. Pendant les saisons sans"
	.dexText "neige, comme le printemps et l`été, ces"
	.dexText "POKéMON se retirent pour vivre dans les"
	.dexText "cavernes, au milieu des stalactites et"
	.dexText "des stalagmites."
	.dexLang DE
	.dexText "SCHNEPPKE lebt in Gebieten mit heftigem"
	.dexText "Schneefall. In Jahreszeiten, in denen es"
	.dexText "nicht schneit, wie im Frühling oder im"
	.dexText "Sommer, nimmt das POKéMON Reißaus, um"
	.dexText "in einer Höhle ein ruhiges Leben unter"
	.dexText "Stalaktiten und Stalagmiten zu führen."
	.dexLang IT
	.dexText "SNORUNT vive in regioni molto nevose."
	.dexText "Nelle stagioni più calde, come l`estate"
	.dexText "e la primavera, questo POKéMON"
	.dexText "si ritira a vivere in tranquillità nel"
	.dexText "cuore delle caverne tra stalattiti"
	.dexText "e stalagmiti."
	.dexLang ES
	.dexText "SNORUNT vive en zonas de grandes"
	.dexText "nevadas. En primavera y verano (cuando"
	.dexText "no nieva), se retira a las cavernas para"
	.dexText "vivir tranquilamente entre estalactitas"
	.dexText "y estalagmitas."
	.dexText ""

	.align 2, 0
dexEntryEu172:: @ 172 GLALIE
	.2byte 1, 7, 2
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 5, 6, 5, 5, 10, 2, 5, 6, 5  @ weight
	.dexLang EN
	.dexName "GLALIE"
	.dexLang FR
	.dexName "ONIGLALI"
	.dexLang DE
	.dexName "FIRNONTOR"
	.dexLang EN
	.dexCategory "FACE"
	.dexLang FR
	.dexCategoryLeftAligned "FACE"
	.dexLang DE
	.dexCategoryLeftAligned "ANTLITZ"
	.dexLang IT
	.dexCategoryLeftAligned "TUTTOMUSO"
	.dexLang ES
	.dexCategoryLeftAligned "CARA"
	.dexLang EN
	.dexText "GLALIE has a body made of rock, which it"
	.dexText "hardens with an armor of ice."
	.dexText "This POKéMON has the ability to freeze"
	.dexText "moisture in the atmosphere into any"
	.dexText "shape it desires."
	.dexText ""
	.dexLang FR
	.dexText "Le corps de ONIGLALI est fait de"
	.dexText "rochers qu`il endurcit grâce à une"
	.dexText "couche de glace. Ce POKéMON a le"
	.dexText "pouvoir de geler l`humidité ambiante et"
	.dexText "de lui donner n`importe quelle forme."
	.dexText ""
	.dexLang DE
	.dexText "FIRNONTOR hat einen Körper aus Stein,"
	.dexText "den es mit einem Panzer aus Eis noch"
	.dexText "verstärkt. Dieses POKéMON kann"
	.dexText "die Luftfeuchtigkeit der Atmosphäre"
	.dexText "einfrieren und in jegliche Form"
	.dexText "verwandeln."
	.dexLang IT
	.dexText "Il corpo di GLALIE è fatto di pietra"
	.dexText "rivestita da un`armatura di ghiaccio."
	.dexText "Questo POKéMON ha la capacità"
	.dexText "di congelare l`umidità nell`atmosfera"
	.dexText "e darle le forme più svariate."
	.dexText ""
	.dexLang ES
	.dexText "GLALIE endurece el cuerpo rocoso que"
	.dexText "tiene con una coraza de hielo. Este"
	.dexText "POKéMON tiene la habilidad de congelar"
	.dexText "la humedad del ambiente y formar"
	.dexText "la figura que se le antoje."
	.dexText ""

	.align 2, 0
dexEntryEu173:: @ 173 SPHEAL
	.2byte 1, 7, 3
	.2byte 10, 2, 0, 7, 10, 10, 0, 8  @ height
	.2byte 10, 10, 8, 7, 1, 10, 10, 3, 9, 5  @ weight
	.dexLang EN
	.dexName "SPHEAL"
	.dexLang FR
	.dexName "OBALIE"
	.dexLang DE
	.dexName "SEEMOPS"
	.dexLang EN
	.dexCategory "CLAP"
	.dexLang FR
	.dexCategoryLeftAligned "CLAP CLAP"
	.dexLang DE
	.dexCategoryLeftAligned "APPLAUS"
	.dexLang IT
	.dexCategoryLeftAligned "ROTOLANTE"
	.dexLang ES
	.dexCategoryLeftAligned "APLAUSO"
	.dexLang EN
	.dexText "SPHEAL is much faster rolling than"
	.dexText "walking to get around. When groups of"
	.dexText "this POKéMON eat, they all clap at once"
	.dexText "to show their pleasure. Because of"
	.dexText "this, their mealtimes are noisy."
	.dexText ""
	.dexLang FR
	.dexText "OBALIE est bien plus rapide quand"
	.dexText "il roule que quand il marche. Lorsque des"
	.dexText "groupes de ce POKéMON mangent,"
	.dexText "ils applaudissent tous en même temps"
	.dexText "pour montrer qu`ils sont contents."
	.dexText "Leurs repas sont très bruyants."
	.dexLang DE
	.dexText "SEEMOPS kann schneller rollen als laufen."
	.dexText "Wenn Gruppen dieses POKéMON"
	.dexText "zusammen essen, klatschen sie"
	.dexText "gleichzeitig, um ihre Freude zu zeigen."
	.dexText "Deswegen sind ihre Mahlzeiten sehr"
	.dexText "laut."
	.dexLang IT
	.dexText "SPHEAL si muove molto più velocemente"
	.dexText "rotolando che non camminando."
	.dexText "Quando si raggruppano per pranzo,"
	.dexText "questi POKéMON sbattono le zampette"
	.dexText "per dimostrare la loro gioia."
	.dexText "I loro pasti sono molto rumorosi."
	.dexLang ES
	.dexText "SPHEAL se desplaza por el suelo más"
	.dexText "rápido rodando que caminando."
	.dexText "Cuando come con otros de su especie,"
	.dexText "todos se ponen a aplaudir para expresar"
	.dexText "su alegría. Por eso, a veces son algo"
	.dexText "escandalosos."

	.align 2, 0
dexEntryEu174:: @ 174 SEALEO
	.2byte 1, 7, 4
	.2byte 10, 3, 0, 7, 10, 10, 1, 1  @ height
	.2byte 10, 1, 9, 3, 1, 10, 10, 8, 7, 6  @ weight
	.dexLang EN
	.dexName "SEALEO"
	.dexLang FR
	.dexName "PHOGLEUR"
	.dexLang DE
	.dexName "SEEJONG"
	.dexLang EN
	.dexCategory "BALL ROLL"
	.dexLang FR
	.dexCategoryLeftAligned "ROULE BOULE"
	.dexLang DE
	.dexCategoryLeftAligned "SPIELBALL"
	.dexLang IT
	.dexCategoryLeftAligned "ROTAPALLA"
	.dexLang ES
	.dexCategoryLeftAligned "RODABOLA"
	.dexLang EN
	.dexText "SEALEO has the habit of always juggling"
	.dexText "on the tip of its nose anything it sees"
	.dexText "for the first time."
	.dexText "This POKéMON occasionally entertains"
	.dexText "itself by balancing and rolling a SPHEAL"
	.dexText "on its nose."
	.dexLang FR
	.dexText "PHOGLEUR a pris l`habitude de jongler"
	.dexText "avec tout ce qu`il découvre pour la"
	.dexText "première fois. Ce POKéMON se divertit"
	.dexText "parfois en faisant tourner un"
	.dexText "OBALIE sur le bout de son museau."
	.dexText ""
	.dexLang DE
	.dexText "SEEJONG hat die Angewohnheit, alles,"
	.dexText "was es zum ersten Mal sieht, auf seiner"
	.dexText "Nasenspitze zu jonglieren. Dieses"
	.dexText "POKéMON hält sich bei Laune, indem es"
	.dexText "manchmal ein SEEMOPS auf seiner Nase"
	.dexText "balanciert und hin- und herrollt."
	.dexLang IT
	.dexText "SEALEO è solito giocare con qualsiasi"
	.dexText "cosa veda per la prima volta, tenendola"
	.dexText "in equilibrio sulla punta del naso."
	.dexText "Talvolta, si diverte a far rotolare"
	.dexText "sul proprio naso anche SPHEAL."
	.dexText ""
	.dexLang ES
	.dexText "Cada vez que SEALEO ve algo nuevo,"
	.dexText "se lo pone en el morro y empieza"
	.dexText "a darle vueltas."
	.dexText "A veces, para entretenerse,"
	.dexText "hace lo mismo con un SPHEAL."
	.dexText ""

	.align 2, 0
dexEntryEu175:: @ 175 WALREIN
	.2byte 1, 7, 5
	.2byte 10, 4, 0, 7, 10, 10, 1, 4  @ height
	.2byte 10, 3, 3, 2, 0, 10, 1, 5, 0, 6  @ weight
	.dexLang EN
	.dexName "WALREIN"
	.dexLang FR
	.dexName "KAIMORSE"
	.dexLang DE
	.dexName "WALRAISA"
	.dexLang EN
	.dexCategory "ICE BREAK"
	.dexLang FR
	.dexCategoryLeftAligned "BRISE GLACE"
	.dexLang DE
	.dexCategoryLeftAligned "EISBRECHER"
	.dexLang IT
	.dexCategoryLeftAligned "SPACCAGELO"
	.dexLang ES
	.dexCategoryLeftAligned "ROMPEHIELO"
	.dexLang EN
	.dexText "WALREIN`s two massively developed"
	.dexText "tusks can totally shatter blocks of"
	.dexText "ice weighing ten tons with one blow."
	.dexText "This POKéMON`s thick coat of blubber"
	.dexText "insulates it from subzero temperatures."
	.dexText ""
	.dexLang FR
	.dexText "Les deux énormes défenses de"
	.dexText "KAIMORSE peuvent détruire en un"
	.dexText "seul coup des blocs de glace de plus"
	.dexText "de dix tonnes. L`épaisse couche de"
	.dexText "graisse de ce POKéMON l`isole lorsque la"
	.dexText "température est en dessous de zéro."
	.dexLang DE
	.dexText "WALRAISA hat zwei massive Stoßzähne,"
	.dexText "die mit einem Hieb Eisblöcke"
	.dexText "zertrümmern können, die bis zu"
	.dexText "10 Tonnen wiegen. Es besitzt eine dicke"
	.dexText "Speckschicht, die es vor eisigen"
	.dexText "Temperaturen schützt."
	.dexLang IT
	.dexText "Le due zanne molto sviluppate di"
	.dexText "WALREIN sono in grado di ridurre"
	.dexText "in polvere blocchi di ghiaccio del"
	.dexText "peso di 100 quintali. Lo spesso strato"
	.dexText "di grasso attorno al corpo lo isola"
	.dexText "dalle rigide temperature polari."
	.dexLang ES
	.dexText "WALREIN tiene unos exagerados colmillos"
	.dexText "con los que puede hacer añicos bloques"
	.dexText "de hielo de hasta 10 toneladas de una"
	.dexText "sola dentellada. La gruesa capa de grasa"
	.dexText "de ballena que lo recubre le protege de"
	.dexText "temperaturas inferiores a 0 grados."

	.align 2, 0
dexEntryEu176:: @ 176 CLAMPERL
	.2byte 1, 7, 6
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 1, 1, 5, 7, 10, 10, 5, 2, 5  @ weight
	.dexLang EN
	.dexName "CLAMPERL"
	.dexLang FR
	.dexName "COQUIPERL"
	.dexLang DE
	.dexName "PERLU"
	.dexLang EN
	.dexCategory "BIVALVE"
	.dexLang FR
	.dexCategoryLeftAligned "BIVALVE"
	.dexLang DE
	.dexCategoryLeftAligned "BIVALVIA"
	.dexLang IT
	.dexCategoryLeftAligned "BIVALVE"
	.dexLang ES
	.dexCategoryLeftAligned "BIVALVO"
	.dexLang EN
	.dexText "CLAMPERL grows while being protected"
	.dexText "by its rock-hard shell. When its body"
	.dexText "becomes too large to fit inside the"
	.dexText "shell, it is sure evidence that this"
	.dexText "POKéMON is getting close to evolution."
	.dexText ""
	.dexLang FR
	.dexText "COQUIPERL grandit protégé par sa"
	.dexText "coquille dure comme de la pierre. Lorsque"
	.dexText "son corps devient trop grand pour sa"
	.dexText "coquille, cela signifie que ce POKéMON"
	.dexText "va bientôt évoluer."
	.dexText ""
	.dexLang DE
	.dexText "PERLU wächst, während es von seiner"
	.dexText "steinharten Schale geschützt wird."
	.dexText "Wenn sein Körper zu groß für seine"
	.dexText "Schale wird, ist dies ein sicheres"
	.dexText "Anzeichen dafür, dass dieses POKéMON"
	.dexText "kurz vor seiner Entwicklung steht."
	.dexLang IT
	.dexText "CLAMPERL cresce ben protetto dalla"
	.dexText "sua conchiglia dura come la pietra."
	.dexText "Quando cresce oltre la misura"
	.dexText "della conchiglia, significa che è"
	.dexText "prossimo all`evoluzione."
	.dexText ""
	.dexLang ES
	.dexText "CLAMPERL crece protegido por la sólida"
	.dexText "concha que tiene. Si vemos que el"
	.dexText "cuerpo no le cabe, será porque está"
	.dexText "a punto de evolucionar."
	.dexText ""
	.dexText ""

	.align 2, 0
dexEntryEu177:: @ 177 HUNTAIL
	.2byte 1, 7, 7
	.2byte 10, 5, 0, 7, 10, 10, 1, 7  @ height
	.2byte 10, 10, 5, 9, 5, 10, 10, 2, 7, 0  @ weight
	.dexLang EN
	.dexName "HUNTAIL"
	.dexLang FR
	.dexName "SERPANG"
	.dexLang DE
	.dexName "AALABYSS"
	.dexLang EN
	.dexCategory "DEEP SEA"
	.dexLang FR
	.dexCategoryLeftAligned "ABYSSE"
	.dexLang DE
	.dexCategoryLeftAligned "TIEFSEE"
	.dexLang IT
	.dexCategoryLeftAligned "ABISSI"
	.dexLang ES
	.dexCategoryLeftAligned "ABISAL"
	.dexLang EN
	.dexText "HUNTAIL`s tail is shaped like a fish."
	.dexText "It uses the tail to attract prey, then"
	.dexText "swallows the prey whole with its large,"
	.dexText "gaping mouth."
	.dexText "This POKéMON swims by wiggling its"
	.dexText "slender body like a snake."
	.dexLang FR
	.dexText "La queue de SERPANG est en forme de"
	.dexText "poisson. Il l`utilise pour attirer sa"
	.dexText "proie qu`il avale en une fois"
	.dexText "grâce à sa bouche béante. Ce POKéMON"
	.dexText "nage en tortillant son corps comme un"
	.dexText "serpent."
	.dexLang DE
	.dexText "AALABYSS` Schweif ist wie ein Fisch"
	.dexText "geformt. Es benutzt ihn, um Beute"
	.dexText "anzuziehen und schluckt diese dann"
	.dexText "im Ganzen herunter. Beim Schwimmen"
	.dexText "bewegt es seinen schlanken Körper"
	.dexText "wie eine Schlange."
	.dexLang IT
	.dexText "La coda di HUNTAIL è a forma di pesce."
	.dexText "Il POKéMON la usa come esca per la preda,"
	.dexText "che poi ingoia intera con l`enorme"
	.dexText "bocca spalancata."
	.dexText "Nuota ondeggiando il corpo"
	.dexText "snello a forma di serpente."
	.dexLang ES
	.dexText "HUNTAIL tiene una cola en forma de"
	.dexText "pez, que usa para atraer a su presa. Una"
	.dexText "vez la tiene cerca, la engulle sin más."
	.dexText "Este POKéMON nada haciendo serpentear"
	.dexText "el cuerpo como si fuera un reptil."
	.dexText ""

	.align 2, 0
dexEntryEu178:: @ 178 GOREBYSS
	.2byte 1, 7, 8
	.2byte 10, 5, 1, 1, 10, 10, 1, 8  @ height
	.2byte 10, 10, 4, 9, 8, 10, 10, 2, 2, 6  @ weight
	.dexLang EN
	.dexName "GOREBYSS"
	.dexLang FR
	.dexName "ROSABYSS"
	.dexLang DE
	.dexName "SAGANABYSS"
	.dexLang EN
	.dexCategory "SOUTH SEA"
	.dexLang FR
	.dexCategoryLeftAligned "MER DU SUD"
	.dexLang DE
	.dexCategoryLeftAligned "SÜDSEE"
	.dexLang IT
	.dexCategoryLeftAligned "SUDMARINO"
	.dexLang ES
	.dexCategoryLeftAligned "MAR DEL SUR"
	.dexLang EN
	.dexText "Although GOREBYSS is the very picture"
	.dexText "of elegance and beauty while swimming,"
	.dexText "it is also cruel. When it spots prey, this"
	.dexText "POKéMON inserts its thin mouth into the"
	.dexText "prey`s body and drains the prey of its"
	.dexText "body fluids."
	.dexLang FR
	.dexText "Même si ROSABYSS est l`image même"
	.dexText "de l`élégance et de la beauté quand il"
	.dexText "nage, il est aussi très cruel. Quand il"
	.dexText "repère sa proie, ce POKéMON insère sa"
	.dexText "fine bouche dans le corps de sa proie et"
	.dexText "aspire ses fluides corporels."
	.dexLang DE
	.dexText "Obwohl SAGANABYSS beim Schwimmen ein"
	.dexText "Bild von Eleganz und Schönheit bietet,"
	.dexText "kann es auch sehr grausam sein. Wenn es"
	.dexText "Beute sichtet, sticht es sein dünnes"
	.dexText "Maul in den Körper eines Gegners und"
	.dexText "entzieht ihm die Flüssigkeit."
	.dexLang IT
	.dexText "Nonostante GOREBYSS sia il ritratto"
	.dexText "dell`eleganza e della bellezza in nuoto,"
	.dexText "è anche molto crudele. Quando scova"
	.dexText "una preda, la perfora con il muso"
	.dexText "appuntito e la dissangua totalmente."
	.dexText ""
	.dexLang ES
	.dexText "Aunque GOREBYSS es la imagen"
	.dexText "de la elegancia y la belleza al nadar,"
	.dexText "es también la definición de la crueldad."
	.dexText "Al detectar a su presa, este POKéMON"
	.dexText "le hinca los finos dientes que tiene y"
	.dexText "le absorbe los fluidos corporales."

	.align 2, 0
dexEntryEu179:: @ 179 RELICANTH
	.2byte 1, 7, 9
	.2byte 10, 3, 0, 3, 10, 10, 1, 0  @ height
	.2byte 10, 10, 5, 1, 6, 10, 10, 2, 3, 4  @ weight
	.dexLang EN
	.dexName "RELICANTH"
	.dexLang FR
	.dexName "RELICANTH"
	.dexLang DE
	.dexName "RELICANTH"
	.dexLang EN
	.dexCategory "LONGEVITY"
	.dexLang FR
	.dexCategoryLeftAligned "LONGEVITE"
	.dexLang DE
	.dexCategoryLeftAligned "BESTAND"
	.dexLang IT
	.dexCategoryLeftAligned "LONGEVITÀ"
	.dexLang ES
	.dexCategoryLeftAligned "LONGEVO"
	.dexLang EN
	.dexText "RELICANTH is a POKéMON species that"
	.dexText "existed for a hundred million years"
	.dexText "without ever changing its form."
	.dexText "This ancient POKéMON feeds on"
	.dexText "microscopic organisms with its"
	.dexText "toothless mouth."
	.dexLang FR
	.dexText "Les RELICANTH sont une espèce de"
	.dexText "POKéMON qui a existé pendant cent"
	.dexText "millions d`années sans jamais changer"
	.dexText "de forme. Ce POKéMON antique se nourrit"
	.dexText "d`organismes microscopiques avec sa"
	.dexText "bouche édentée."
	.dexLang DE
	.dexText "RELICANTH ist eine POKéMON-Spezies,"
	.dexText "die vor hundert Millionen Jahren"
	.dexText "existierte, ohne jemals ihre Form zu"
	.dexText "verändern. Dieses antike POKéMON"
	.dexText "hat ein zahnloses Maul und ernährt sich"
	.dexText "von Mikroorganismen."
	.dexLang IT
	.dexText "RELICANTH è una specie esistente"
	.dexText "da cento milioni di anni senza"
	.dexText "alcuna mutazione di forma."
	.dexText "Questo antichissimo POKéMON"
	.dexText "si nutre di microrganismi come"
	.dexText "prova la sua bocca sdentata."
	.dexLang ES
	.dexText "RELICANTH pertenece a una especie"
	.dexText "de POKéMON que lleva millones de años"
	.dexText "sin cambiar de forma."
	.dexText "Este ancestral POKéMON se alimenta"
	.dexText "de microorganismos por la boca"
	.dexText "desdentada que tiene."

	.align 2, 0
dexEntryEu180:: @ 180 CORSOLA
	.2byte 1, 8, 0
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 1, 1, 0, 10, 10, 10, 5, 0  @ weight
	.dexLang EN
	.dexName "CORSOLA"
	.dexLang FR
	.dexName "CORAYON"
	.dexLang DE
	.dexName "CORASONN"
	.dexLang EN
	.dexCategory "CORAL"
	.dexLang FR
	.dexCategoryLeftAligned "CORAIL"
	.dexLang DE
	.dexCategoryLeftAligned "KORALLE"
	.dexLang IT
	.dexCategoryLeftAligned "CORALLO"
	.dexLang ES
	.dexCategoryLeftAligned "CORAL"
	.dexLang EN
	.dexText "Clusters of CORSOLA congregate in warm"
	.dexText "seas where they serve as ideal hiding"
	.dexText "places for smaller POKéMON."
	.dexText "When the water temperature falls, this"
	.dexText "POKéMON migrates to the southern seas."
	.dexText ""
	.dexLang FR
	.dexText "Les CORAYON se rassemblent dans les"
	.dexText "mers chaudes, offrant ainsi un abri"
	.dexText "idéal aux plus petits POKéMON."
	.dexText "Quand la température baisse, ce"
	.dexText "POKéMON migre vers les mers du sud."
	.dexText ""
	.dexLang DE
	.dexText "Scharen von CORASONN sammeln sich im"
	.dexText "warmen Meer und dienen kleineren"
	.dexText "POKéMON als ideale Plätze zum"
	.dexText "Verstecken. Wenn die Wassertemperatur"
	.dexText "sinkt, wandert dieses POKéMON in die"
	.dexText "südlichen Meere ab."
	.dexLang IT
	.dexText "I CORSOLA formano grandi colonie nei"
	.dexText "mari più caldi dove costituiscono"
	.dexText "rifugi ideali per POKéMON più piccoli."
	.dexText "Quando la temperatura dell`acqua"
	.dexText "si abbassa, migrano verso i mari del sud."
	.dexText ""
	.dexLang ES
	.dexText "Las aguas templadas son el hábitat de"
	.dexText "CORSOLA. Allí se agrupan grandes bancos"
	.dexText "de estos POKéMON que sirven de"
	.dexText "escondite a POKéMON más pequeños."
	.dexText "Cuando la temperatura del agua baja,"
	.dexText "suelen migrar a los Mares del Sur."

	.align 2, 0
dexEntryEu181:: @ 181 CHINCHOU
	.2byte 1, 8, 1
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 2, 6, 5, 10, 10, 1, 2, 0  @ weight
	.dexLang EN
	.dexName "CHINCHOU"
	.dexLang FR
	.dexName "LOUPIO"
	.dexLang DE
	.dexName "LAMPI"
	.dexLang EN
	.dexCategory "ANGLER"
	.dexLang FR
	.dexCategoryLeftAligned "POISSON"
	.dexLang DE
	.dexCategoryLeftAligned "ANGLER"
	.dexLang IT
	.dexCategoryLeftAligned "PESCATORE"
	.dexLang ES
	.dexCategoryLeftAligned "RAPE"
	.dexLang EN
	.dexText "CHINCHOU`s two antennas are filled with"
	.dexText "cells that generate strong electricity."
	.dexText "This POKéMON`s cells create so much"
	.dexText "electrical power, it even makes itself"
	.dexText "tingle slightly."
	.dexText ""
	.dexLang FR
	.dexText "Les deux antennes de LOUPIO sont"
	.dexText "chargées de cellules qui génèrent un"
	.dexText "courant de forte intensité. Ces cellules"
	.dexText "libèrent tellement d`électricité qu`elles"
	.dexText "vibrent légèrement."
	.dexText ""
	.dexLang DE
	.dexText "LAMPIs zwei Antennen sind mit Zellen"
	.dexText "gefüllt, die Elektrizität erzeugen."
	.dexText "Die elektrische Ladung ist so stark,"
	.dexText "dass es sogar ein leichtes Kribbeln"
	.dexText "verspürt."
	.dexText ""
	.dexLang IT
	.dexText "Le due antenne di CHINCHOU"
	.dexText "contengono cellule che generano"
	.dexText "un`elettricità incredibile,"
	.dexText "tanto forte da farlo vibrare tutto."
	.dexText ""
	.dexText ""
	.dexLang ES
	.dexText "Las dos antenas de CHINCHOU están"
	.dexText "llenas de células que generan potente"
	.dexText "electricidad. Crean tal cantidad que"
	.dexText "hasta el propio POKéMON siente cierto"
	.dexText "hormigueo."
	.dexText ""

	.align 2, 0
dexEntryEu182:: @ 182 LANTURN
	.2byte 1, 8, 2
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 10, 4, 9, 6, 10, 10, 2, 2, 5  @ weight
	.dexLang EN
	.dexName "LANTURN"
	.dexLang FR
	.dexName "LANTURN"
	.dexLang DE
	.dexName "LANTURN"
	.dexLang EN
	.dexCategory "LIGHT"
	.dexLang FR
	.dexCategoryLeftAligned "LUMIERE"
	.dexLang DE
	.dexCategoryLeftAligned "LEUCHTE"
	.dexLang IT
	.dexCategoryLeftAligned "LUCE"
	.dexLang ES
	.dexCategoryLeftAligned "LUZ"
	.dexLang EN
	.dexText "LANTURN is known to emit light."
	.dexText "If you peer down into the dark sea from"
	.dexText "a ship at night, you can sometimes see"
	.dexText "this POKéMON`s light rising from the"
	.dexText "depths where it swims. It gives the sea"
	.dexText "an appearance of a starlit night."
	.dexLang FR
	.dexText "On sait que LANTURN émet de la lumière."
	.dexText "Si on regarde attentivement la mer"
	.dexText "de nuit à partir d`un bateau, on peut"
	.dexText "voir la lumière générée par ce POKéMON"
	.dexText "éclairer les profondeurs. Cela donne à la"
	.dexText "mer l`apparence d`un ciel étoilé."
	.dexLang DE
	.dexText "LANTURN strahlt Licht ab. Wenn du"
	.dexText "nachts aufs dunkle Meer hinausblickst,"
	.dexText "kannst du vielleicht das Licht dieses"
	.dexText "PKMN aus der Tiefe, in der es schwimmt,"
	.dexText "heraufschimmern sehen. Es lässt das"
	.dexText "Meer wie eine sternklare Nacht wirken."
	.dexLang IT
	.dexText "LANTURN emette una luce intensa."
	.dexText "Osservando il mare da un`imbarcazione,"
	.dexText "di notte, è possibile scorgere la sua"
	.dexText "luce risalire dagli abissi dov`è"
	.dexText "solito nuotare. Il mare assume"
	.dexText "l`aspetto d`un cielo stellato."
	.dexLang ES
	.dexText "Todos saben que LANTURN emite luz. Si"
	.dexText "echas un ojo al mar desde un barco en"
	.dexText "una noche cerrada, quizás veas su luz"
	.dexText "a través de las aguas, brillando desde lo"
	.dexText "más profundo, por donde suele nadar."
	.dexText "Con él, el mar parece un cielo estrellado."

	.align 2, 0
dexEntryEu183:: @ 183 LUVDISC
	.2byte 1, 8, 3
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 1, 9, 2, 10, 10, 10, 8, 7  @ weight
	.dexLang EN
	.dexName "LUVDISC"
	.dexLang FR
	.dexName "LOVDISC"
	.dexLang DE
	.dexName "LIEBISKUS"
	.dexLang EN
	.dexCategory "RENDEZVOUS"
	.dexLang FR
	.dexCategoryLeftAligned "RENDEZVOUS"
	.dexLang DE
	.dexCategoryLeftAligned "RENDEZVOUS"
	.dexLang IT
	.dexCategoryLeftAligned "RENDEZVOUS"
	.dexLang ES
	.dexCategoryLeftAligned "CITA"
	.dexLang EN
	.dexText "LUVDISC live in shallow seas in the"
	.dexText "tropics. This heart-shaped POKéMON"
	.dexText "earned its name by swimming after"
	.dexText "loving couples it spotted in the"
	.dexText "ocean`s waves."
	.dexText ""
	.dexLang FR
	.dexText "LOVDISC vit dans les mers peu"
	.dexText "profondes des tropiques. Ce POKéMON"
	.dexText "en forme de cœur a gagné son nom en"
	.dexText "nageant derrière les couples d`amoureux"
	.dexText "qu`il repérait dans les eaux claires"
	.dexText "de l`océan."
	.dexLang DE
	.dexText "LIEBISKUS lebt in den seichten"
	.dexText "Gewässern der Tropen. Dieses herz-"
	.dexText "förmige POKéMON verdankt seinen Namen"
	.dexText "der Tatsache, dass es hinter Liebes-"
	.dexText "paaren herschwamm, die es in den Wellen"
	.dexText "des Ozeans beobachtet hatte."
	.dexLang IT
	.dexText "LUVDISC vive nei mari tropicali poco"
	.dexText "profondi. Questo POKéMON a forma di"
	.dexText "cuore ha preso questo nome per aver"
	.dexText "seguito una coppia innamorata"
	.dexText "individuata tra le onde oceaniche."
	.dexText ""
	.dexLang ES
	.dexText "LUVDISC vive en aguas tropicales poco"
	.dexText "profundas. Este POKéMON con forma"
	.dexText "de corazón se ha ganado la reputación"
	.dexText "que tiene por ir nadando detrás de las"
	.dexText "parejas de enamorados que veía entre"
	.dexText "las olas del océano."

	.align 2, 0
dexEntryEu184:: @ 184 HORSEA
	.2byte 1, 8, 4
	.2byte 10, 1, 0, 4, 10, 10, 0, 4  @ height
	.2byte 10, 10, 1, 7, 6, 10, 10, 10, 8, 0  @ weight
	.dexLang EN
	.dexName "HORSEA"
	.dexLang FR
	.dexName "HYPOTREMPE"
	.dexLang DE
	.dexName "SEEPER"
	.dexLang EN
	.dexCategory "DRAGON"
	.dexLang FR
	.dexCategoryLeftAligned "DRAGON"
	.dexLang DE
	.dexCategoryLeftAligned "DRACHE"
	.dexLang IT
	.dexCategoryLeftAligned "DRAGO"
	.dexLang ES
	.dexCategoryLeftAligned "DRAGÓN"
	.dexLang EN
	.dexText "If HORSEA senses danger, it will"
	.dexText "reflexively spray a dense black ink"
	.dexText "from its mouth and try to escape."
	.dexText "This POKéMON swims by cleverly flapping"
	.dexText "the fins on its back."
	.dexText ""
	.dexLang FR
	.dexText "Lorsque HYPOTREMPE sent un danger,"
	.dexText "il libère instinctivement une épaisse"
	.dexText "encre noire pour pouvoir s`échapper."
	.dexText "Ce POKéMON nage en agitant ses"
	.dexText "nageoires dorsales."
	.dexText ""
	.dexLang DE
	.dexText "Wenn SEEPER Gefahr wittert, versprüht"
	.dexText "es reflexartig eine tiefschwarze Tinte"
	.dexText "aus seinem Mund und ergreift die Flucht."
	.dexText "Dieses POKéMON kann schwimmen, indem"
	.dexText "es geschickt mit den Flossen auf seinem"
	.dexText "Rücken schlägt."
	.dexLang IT
	.dexText "Avvertendo il pericolo, HORSEA spruzza"
	.dexText "istintivamente una nube d`inchiostro"
	.dexText "nero dalla bocca, tentando poi la fuga."
	.dexText "Questo POKéMON nuota agitando"
	.dexText "abilmente le pinne sulla schiena."
	.dexText ""
	.dexLang ES
	.dexText "Si HORSEA siente peligro, echará"
	.dexText "por la boca una densa tinta negra"
	.dexText "inconscientemente e intentará huir."
	.dexText "Este POKéMON nada muy bien batiendo"
	.dexText "las aletas que tiene en el lomo."
	.dexText ""

	.align 2, 0
dexEntryEu185:: @ 185 SEADRA
	.2byte 1, 8, 5
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 10, 5, 5, 1, 10, 10, 2, 5, 0  @ weight
	.dexLang EN
	.dexName "SEADRA"
	.dexLang FR
	.dexName "HYPOCEAN"
	.dexLang DE
	.dexName "SEEMON"
	.dexLang EN
	.dexCategory "DRAGON"
	.dexLang FR
	.dexCategoryLeftAligned "DRAGON"
	.dexLang DE
	.dexCategoryLeftAligned "DRACHE"
	.dexLang IT
	.dexCategoryLeftAligned "DRAGO"
	.dexLang ES
	.dexCategoryLeftAligned "DRAGÓN"
	.dexLang EN
	.dexText "SEADRA generates whirlpools by spinning"
	.dexText "its body. The whirlpools are strong"
	.dexText "enough to swallow even fishing boats."
	.dexText "This POKéMON weakens prey with these"
	.dexText "currents, then swallows it whole."
	.dexText ""
	.dexLang FR
	.dexText "HYPOCEAN déclenche des tourbillons"
	.dexText "en faisant tournoyer son corps. Ces"
	.dexText "tourbillons sont assez puissants pour"
	.dexText "engloutir des bateaux de pêche. Ce"
	.dexText "POKéMON affaiblit sa proie grâce à ces"
	.dexText "courants, puis l`avale en une bouchée."
	.dexLang DE
	.dexText "SEEMON erzeugt Strudel, indem es sich"
	.dexText "schnell um die eigene Achse dreht. Diese"
	.dexText "Strudel können sogar Fischerboote in"
	.dexText "die Tiefe reißen. Damit schwächt es"
	.dexText "Beute, bevor es sie im Ganzen"
	.dexText "verschlingt."
	.dexLang IT
	.dexText "Roteando turbinosamente, SEADRA"
	.dexText "genera vortici così forti da riuscire a"
	.dexText "inghiottire persino un peschereccio."
	.dexText "In questo modo il POKéMON"
	.dexText "indebolisce le prede e poi le"
	.dexText "inghiotte intere."
	.dexLang ES
	.dexText "SEADRA gira sobre sí mismo y crea"
	.dexText "unos remolinos lo suficientemente"
	.dexText "fuertes como para engullir barcos"
	.dexText "de pesca. Este POKéMON aprovecha"
	.dexText "las corrientes que crea para debilitar"
	.dexText "a su presa y tragársela de una vez."

	.align 2, 0
dexEntryEu186:: @ 186 KINGDRA
	.2byte 1, 8, 6
	.2byte 10, 5, 1, 1, 10, 10, 1, 8  @ height
	.2byte 10, 3, 3, 5, 1, 10, 1, 5, 2, 0  @ weight
	.dexLang EN
	.dexName "KINGDRA"
	.dexLang FR
	.dexName "HYPOROI"
	.dexLang DE
	.dexName "SEEDRAKING"
	.dexLang EN
	.dexCategory "DRAGON"
	.dexLang FR
	.dexCategoryLeftAligned "DRAGON"
	.dexLang DE
	.dexCategoryLeftAligned "DRACHEN"
	.dexLang IT
	.dexCategoryLeftAligned "DRAGO"
	.dexLang ES
	.dexCategoryLeftAligned "DRAGÓN"
	.dexLang EN
	.dexText "KINGDRA sleeps on the seafloor where"
	.dexText "it is otherwise devoid of life."
	.dexText "When a storm arrives, the POKéMON is"
	.dexText "said to awaken and wander about in"
	.dexText "search of prey."
	.dexText ""
	.dexLang FR
	.dexText "HYPOROI dort au fond de l`océan, où"
	.dexText "aucune autre forme de vie ne réside."
	.dexText "On raconte que lorsqu`une tempête"
	.dexText "survient, c`est que ce POKéMON"
	.dexText "s`éveille et erre dans les profondeurs"
	.dexText "en quête de proies."
	.dexLang DE
	.dexText "SEEDRAKING schläft auf dem Meeres-"
	.dexText "boden, wo ansonsten niemand lebt. Wenn"
	.dexText "ein Sturm aufkommt, wacht es auf und"
	.dexText "macht sich auf die Suche nach Beute."
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "KINGDRA dorme sui fondali marini dove"
	.dexText "di solito non esistono forme di vita."
	.dexText ""
	.dexText "Si dice che in caso di tempesta KINGDRA"
	.dexText "si svegli e vada in cerca di prede."
	.dexText ""
	.dexLang ES
	.dexText "KINGDRA duerme en el suelo marino"
	.dexText "donde, en realidad, no tiene mucha vida."
	.dexText "Cuando estalla una tormenta,"
	.dexText "dicen que se despierta y se pone"
	.dexText "a vagar en busca de su presa."
	.dexText ""

	.align 2, 0
dexEntryEu187:: @ 187 BAGON
	.2byte 1, 8, 7
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 9, 2, 8, 10, 10, 4, 2, 1  @ weight
	.dexLang EN
	.dexName "BAGON"
	.dexLang FR
	.dexName "DRABY"
	.dexLang DE
	.dexName "KINDWURM"
	.dexLang EN
	.dexCategory "ROCK HEAD"
	.dexLang FR
	.dexCategoryLeftAligned "TETE DE ROC"
	.dexLang DE
	.dexCategoryLeftAligned "STEINHAUPT"
	.dexLang IT
	.dexCategoryLeftAligned "ROCCIOTESTA"
	.dexLang ES
	.dexCategoryLeftAligned "CABEZA ROCA"
	.dexLang EN
	.dexText "BAGON has a dream of one day soaring"
	.dexText "in the sky. In doomed efforts to fly,"
	.dexText "this POKéMON hurls itself off cliffs."
	.dexText "As a result of its dives, its head has"
	.dexText "grown tough and as hard as tempered"
	.dexText "steel."
	.dexLang FR
	.dexText "DRABY rêve de pouvoir un jour"
	.dexText "s`élancer dans les cieux. Bien que voué"
	.dexText "à l`échec, ce POKéMON se jette des"
	.dexText "falaises pour essayer de voler. A force,"
	.dexText "sa tête est devenue aussi dure"
	.dexText "que de l`acier."
	.dexLang DE
	.dexText "KINDWURM hat den Traum, fliegen zu"
	.dexText "können. In zahlreichen vergeblichen"
	.dexText "Versuchen stürzte es sich die Klippen"
	.dexText "herunter. Daher ist sein Kopf sehr"
	.dexText "robust und so hart wie Stahl geworden."
	.dexText ""
	.dexLang IT
	.dexText "BAGON serba in sé il sogno di volare"
	.dexText "alto in cielo. Nei suoi vani tentativi di"
	.dexText "spiccare il volo, si lancia a picco dalle"
	.dexText "alture. A causa di queste rovinose"
	.dexText "cadute, la testa gli è diventata dura"
	.dexText "come l`acciaio temprato."
	.dexLang ES
	.dexText "BAGON sueña con poder pasar un día"
	.dexText "volando por el cielo. En vanos intentos"
	.dexText "por volar, ha llegado a tirarse desde"
	.dexText "riscos. Como resultado de estas caídas"
	.dexText "en picado, se le ha puesto la cabeza"
	.dexText "dura como las piedras."

	.align 2, 0
dexEntryEu188:: @ 188 SHELGON
	.2byte 1, 8, 8
	.2byte 10, 3, 0, 7, 10, 10, 1, 1  @ height
	.2byte 10, 2, 4, 3, 6, 10, 1, 1, 0, 5  @ weight
	.dexLang EN
	.dexName "SHELGON"
	.dexLang FR
	.dexName "DRACKHAUS"
	.dexLang DE
	.dexName "DRASCHEL"
	.dexLang EN
	.dexCategory "ENDURANCE"
	.dexLang FR
	.dexCategoryLeftAligned "ENDURANT"
	.dexLang DE
	.dexCategoryLeftAligned "DURCHSTEHER"
	.dexLang IT
	.dexCategoryLeftAligned "RESISTENZA"
	.dexLang ES
	.dexCategoryLeftAligned "RESISTENCIA"
	.dexLang EN
	.dexText "Inside SHELGON`s armor-like shell, cells"
	.dexText "are in the midst of transformation"
	.dexText "to create an entirely new body."
	.dexText "This POKéMON`s shell is extremely heavy,"
	.dexText "making its movements sluggish."
	.dexText ""
	.dexLang FR
	.dexText "A l`intérieur de la carapace blindée de"
	.dexText "DRACKHAUS, ses cellules sont en pleine"
	.dexText "transformation pour créer un nouveau"
	.dexText "corps. La carapace de ce POKéMON est"
	.dexText "très lourde, ce qui rend ses mouvements"
	.dexText "très lents."
	.dexLang DE
	.dexText "In DRASCHELs panzerartiger Schale"
	.dexText "vollziehen seine Zellen eine"
	.dexText "Transformation, um einen völlig neuen"
	.dexText "Körper zu bilden. Die Schale dieses"
	.dexText "POKéMON ist ausgesprochen schwer, so"
	.dexText "dass seine Bewegungen träge wirken."
	.dexLang IT
	.dexText "All`interno della conchiglia-armatura"
	.dexText "di SHELGON, le cellule sono in continua"
	.dexText "trasformazione per creare un corpo"
	.dexText "completamente nuovo. La conchiglia"
	.dexText "pesantissima rende difficili i movimenti."
	.dexText ""
	.dexLang ES
	.dexText "Dentro de la capa acorazada de SHELGON,"
	.dexText "las células están en pleno proceso de"
	.dexText "creación de un cuerpo nuevo."
	.dexText "El peso de la coraza le hace tener unos"
	.dexText "movimientos lentos."
	.dexText ""

	.align 2, 0
dexEntryEu189:: @ 189 SALAMENCE
	.2byte 1, 8, 9
	.2byte 10, 4, 1, 1, 10, 10, 1, 5  @ height
	.2byte 10, 2, 2, 6, 2, 10, 1, 0, 2, 6  @ weight
	.dexLang EN
	.dexName "SALAMENCE"
	.dexLang FR
	.dexName "DRATTAK"
	.dexLang DE
	.dexName "BRUTALANDA"
	.dexLang EN
	.dexCategory "DRAGON"
	.dexLang FR
	.dexCategoryLeftAligned "DRAGON"
	.dexLang DE
	.dexCategoryLeftAligned "DRACHE"
	.dexLang IT
	.dexCategoryLeftAligned "DRAGO"
	.dexLang ES
	.dexCategoryLeftAligned "DRAGÓN"
	.dexLang EN
	.dexText "SALAMENCE came about as a result of a"
	.dexText "strong, long-held dream of growing"
	.dexText "wings. It is said that this powerful"
	.dexText "desire triggered a sudden mutation in"
	.dexText "this POKéMON`s cells, causing it to"
	.dexText "sprout its magnificent wings."
	.dexLang FR
	.dexText "DRATTAK a ce physique grâce à son"
	.dexText "désir de pouvoir s`envoler. On"
	.dexText "dit que cette puissante envie a"
	.dexText "déclenché une soudaine mutation"
	.dexText "moléculaire de ce POKéMON, faisant"
	.dexText "surgir de splendides ailes."
	.dexLang DE
	.dexText "BRUTALANDA träumte sehr lange davon,"
	.dexText "dass ihm Flügel wachsen mögen. Dieser"
	.dexText "sehnliche Wunsch hat wohl eine"
	.dexText "plötzliche Mutation in den Zellen dieses"
	.dexText "POKéMON hervorgerufen, so dass ihm"
	.dexText "plötzlich prächtige Flügel wuchsen."
	.dexLang IT
	.dexText "SALAMENCE rappresenta la realizzazione"
	.dexText "del sogno atavico e irrinunciabile delle"
	.dexText "ali. Si dice che questo forte desiderio"
	.dexText "abbia scatenato l`improvvisa mutazione"
	.dexText "delle sue cellule, portando infine"
	.dexText "alla crescita di ali meravigliose."
	.dexLang ES
	.dexText "SALAMENCE surgió del profundo deseo"
	.dexText "de tener alas."
	.dexText "Dicen que este fuerte deseo fue lo que"
	.dexText "causó la repentina mutación de las"
	.dexText "células y el crecimiento de las alas."
	.dexText ""

	.align 2, 0
dexEntryEu190:: @ 190 BELDUM
	.2byte 1, 9, 0
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 2, 0, 9, 9, 10, 10, 9, 5, 2  @ weight
	.dexLang EN
	.dexName "BELDUM"
	.dexLang FR
	.dexName "TERHAL"
	.dexLang DE
	.dexName "TANHEL"
	.dexLang EN
	.dexCategory "IRON BALL"
	.dexLang FR
	.dexCategoryLeftAligned "BOULEFER"
	.dexLang DE
	.dexCategoryLeftAligned "EISENKUGEL"
	.dexLang IT
	.dexCategoryLeftAligned "FERROSFERA"
	.dexLang ES
	.dexCategoryLeftAligned "BOLA HIERRO"
	.dexLang EN
	.dexText "BELDUM keeps itself floating by"
	.dexText "generating a magnetic force that"
	.dexText "repels earth`s natural magnetism."
	.dexText "When it sleeps, this POKéMON anchors"
	.dexText "itself to a cliff using the hooks on"
	.dexText "its rear."
	.dexLang FR
	.dexText "TERHAL peut léviter en générant un"
	.dexText "champ magnétique qui repousse le"
	.dexText "magnétisme naturel de la terre."
	.dexText "Lorsqu`il dort, ce POKéMON s`ancre à une"
	.dexText "falaise grâce à ses crochets dorsaux."
	.dexText ""
	.dexLang DE
	.dexText "TANHEL hält sich am Schweben, indem es"
	.dexText "eine magnetische Kraft erzeugt, die die"
	.dexText "natürliche Anziehungskraft der Erde"
	.dexText "abstößt. Wenn es schläft, verankert"
	.dexText "sich dieses POKéMON mit den Haken an"
	.dexText "seinem Hinterteil an einem Felsen."
	.dexLang IT
	.dexText "BELDUM fluttua nell`aria generando"
	.dexText "una forza magnetica contraria alla"
	.dexText "naturale forza di gravità terrestre."
	.dexText "Quando dorme, si ancora alle"
	.dexText "scogliere usando il suo gancio"
	.dexText "posteriore."
	.dexLang ES
	.dexText "BELDUM se mantiene flotando en el aire"
	.dexText "gracias a la fuerza magnética que"
	.dexText "genera y que repele la gravedad."
	.dexText "Para dormir, este POKéMON se ancla a los"
	.dexText "riscos usando los ganchos que tiene."
	.dexText ""

	.align 2, 0
dexEntryEu191:: @ 191 METANG
	.2byte 1, 9, 1
	.2byte 10, 3, 1, 1, 10, 10, 1, 2  @ height
	.2byte 10, 4, 4, 6, 4, 10, 2, 0, 2, 5  @ weight
	.dexLang EN
	.dexName "METANG"
	.dexLang FR
	.dexName "METANG"
	.dexLang DE
	.dexName "METANG"
	.dexLang EN
	.dexCategory "IRON CLAW"
	.dexLang FR
	.dexCategoryLeftAligned "PINCEFER"
	.dexLang DE
	.dexCategoryLeftAligned "EISENKLAUE"
	.dexLang IT
	.dexCategoryLeftAligned "FERRUNGHIA"
	.dexLang ES
	.dexCategoryLeftAligned "GARRAHIERRO"
	.dexLang EN
	.dexText "When two BELDUM fuse together, METANG"
	.dexText "is formed. The brains of the BELDUM are"
	.dexText "joined by a magnetic nervous system."
	.dexText "This POKéMON turns its arms to the rear"
	.dexText "for traveling at high speed."
	.dexText ""
	.dexLang FR
	.dexText "Lorsque deux TERHAL fusionnent,"
	.dexText "un METANG se forme. Les cerveaux"
	.dexText "des TERHAL sont reliés par un"
	.dexText "système nerveux magnétique. Ce"
	.dexText "POKéMON dirige ses bras vers"
	.dexText "l`arrière pour voyager à grande vitesse."
	.dexLang DE
	.dexText "Wenn zwei TANHEL miteinander"
	.dexText "verschmelzen, entsteht daraus METANG."
	.dexText "Die Gehirne der TANHEL werden mit"
	.dexText "einem magnetischen Nervensystem ver-"
	.dexText "bunden. Es schlägt seine Arme nach hin-"
	.dexText "ten, um sich schnell bewegen zu können."
	.dexLang IT
	.dexText "Fondendosi, due BELDUM formano"
	.dexText "METANG. I cervelli dei BELDUM sono"
	.dexText "uniti da un sistema nervoso magnetico."
	.dexText "Questo POKéMON ruota le zampe"
	.dexText "all`indietro per muoversi ad elevata"
	.dexText "velocità."
	.dexLang ES
	.dexText "Cuando se funden dos BELDUM, uniendo"
	.dexText "los cerebros por un sistema nervioso"
	.dexText "magnético, se forma un METANG."
	.dexText "Para desplazarse a mayor velocidad,"
	.dexText "este POKéMON echa los brazos hacia"
	.dexText "atrás."

	.align 2, 0
dexEntryEu192:: @ 192 METAGROSS
	.2byte 1, 9, 2
	.2byte 10, 5, 0, 3, 10, 10, 1, 6  @ height
	.2byte 1, 2, 1, 2, 5, 10, 5, 5, 0, 0  @ weight
	.dexLang EN
	.dexName "METAGROSS"
	.dexLang FR
	.dexName "METALOSSE"
	.dexLang DE
	.dexName "METAGROSS"
	.dexLang EN
	.dexCategory "IRON LEG"
	.dexLang FR
	.dexCategoryLeftAligned "PATTEFER"
	.dexLang DE
	.dexCategoryLeftAligned "EISENFUSS"
	.dexLang IT
	.dexCategoryLeftAligned "FERRARTO"
	.dexLang ES
	.dexCategoryLeftAligned "PATA HIERRO"
	.dexLang EN
	.dexText "METAGROSS is the result of two METANG"
	.dexText "achieving fusion. When hunting, this"
	.dexText "POKéMON pins the prey to the ground"
	.dexText "under its massive body. It then eats"
	.dexText "the helpless victim using the large"
	.dexText "mouth on its stomach."
	.dexLang FR
	.dexText "METALOSSE est le résultat de la fusion"
	.dexText "de deux METANG. Lorsqu`il chasse,"
	.dexText "ce POKéMON bloque sa proie au sol,"
	.dexText "sous son corps massif. Il mange ensuite"
	.dexText "la victime impuissante avec son énorme"
	.dexText "bouche, ouverte sur son estomac."
	.dexLang DE
	.dexText "METAGROSS ist aus der Verschmelzung"
	.dexText "zweier METANG hervorgegangen. Auf der"
	.dexText "Jagd drückt es seine Beute mit seinem"
	.dexText "massigen Körper zu Boden. Dann frisst"
	.dexText "es sein hilfloses Opfer auf."
	.dexText ""
	.dexLang IT
	.dexText "METAGROSS è il risultato della fusione"
	.dexText "di due METANG. In caccia questo"
	.dexText "POKéMON blocca la preda al suolo"
	.dexText "con il proprio corpo massiccio."
	.dexText "Poi divora la vittima indifesa con"
	.dexText "la grande bocca dello stomaco."
	.dexLang ES
	.dexText "METAGROSS es el resultado de la fusión"
	.dexText "de dos METANG. Cuando caza,"
	.dexText "acorrala a su presa, sujetándola contra"
	.dexText "el suelo con el cuerpo."
	.dexText "Después, devora a la víctima indefensa"
	.dexText "con la gran boca del estómago."

	.align 2, 0
dexEntryEu193:: @ 193 REGIROCK
	.2byte 1, 9, 3
	.2byte 10, 5, 0, 7, 10, 10, 1, 7  @ height
	.2byte 10, 5, 0, 7, 1, 10, 2, 3, 0, 0  @ weight
	.dexLang EN
	.dexName "REGIROCK"
	.dexLang FR
	.dexName "REGIROCK"
	.dexLang DE
	.dexName "REGIROCK"
	.dexLang EN
	.dexCategory "ROCK PEAK"
	.dexLang FR
	.dexCategoryLeftAligned "PIC ROCHEUX"
	.dexLang DE
	.dexCategoryLeftAligned "STEINGIPFEL"
	.dexLang IT
	.dexCategoryLeftAligned "PICCO"
	.dexLang ES
	.dexCategoryLeftAligned "PICO ROCA"
	.dexLang EN
	.dexText "REGIROCK was sealed away by people"
	.dexText "long ago. If this POKéMON`s body is"
	.dexText "damaged in battle, it is said to seek"
	.dexText "out suitable rocks on its own to repair"
	.dexText "itself."
	.dexText ""
	.dexLang FR
	.dexText "REGIROCK fut isolé par les gens il"
	.dexText "y a très longtemps. Lorsque le corps de"
	.dexText "ce POKéMON est endommagé au combat,"
	.dexText "on raconte qu`il cherche des rochers"
	.dexText "pour se réparer."
	.dexText ""
	.dexLang DE
	.dexText "REGIROCK wurde vor langer Zeit von"
	.dexText "Menschen weggeschlossen. Wenn der"
	.dexText "Körper dieses POKéMON im Kampf"
	.dexText "Schaden nimmt, sucht es nach"
	.dexText "passenden Steinen, um sich selber zu"
	.dexText "reparieren."
	.dexLang IT
	.dexText "Molto tempo fa REGIROCK era stato"
	.dexText "imprigionato dagli esseri umani."
	.dexText ""
	.dexText "Se subisce danni in lotta, cerca"
	.dexText "nuove rocce adatte per riparare"
	.dexText "le rotture."
	.dexLang ES
	.dexText "A REGIROCK lo mantuvieron encerrado"
	.dexText "y lejos hace tiempo."
	.dexText "Dicen que, si resulta dañado en combate,"
	.dexText "se pone él mismo a buscar piedras"
	.dexText "parecidas a las suyas y se las pone para"
	.dexText "recomponerse."

	.align 2, 0
dexEntryEu194:: @ 194 REGICE
	.2byte 1, 9, 4
	.2byte 10, 5, 1, 1, 10, 10, 1, 8  @ height
	.2byte 10, 3, 8, 5, 8, 10, 1, 7, 5, 0  @ weight
	.dexLang EN
	.dexName "REGICE"
	.dexLang FR
	.dexName "REGICE"
	.dexLang DE
	.dexName "REGICE"
	.dexLang EN
	.dexCategory "ICEBERG"
	.dexLang FR
	.dexCategoryLeftAligned "ICEBERG"
	.dexLang DE
	.dexCategoryLeftAligned "EISBERG"
	.dexLang IT
	.dexCategoryLeftAligned "ICEBERG"
	.dexLang ES
	.dexCategoryLeftAligned "ICEBERG"
	.dexLang EN
	.dexText "REGICE cloaks itself with frigid air of"
	.dexText "negative 328 degrees F."
	.dexText "Things will freeze solid just by going"
	.dexText "near this POKéMON."
	.dexText "Its icy body is so cold, it will not melt"
	.dexText "even if it is immersed in magma."
	.dexLang FR
	.dexText "REGICE se recouvre d`air glacé à"
	.dexText "- 200 degrés. Tout ce qui passe à"
	.dexText "proximité de ce POKéMON gèle"
	.dexText "sur place. Son corps est si froid"
	.dexText "qu`il ne fond jamais, même s`il plonge"
	.dexText "dans du magma."
	.dexLang DE
	.dexText "REGICE umhüllt sich selbst mit kalter"
	.dexText "Luft von 200 Grad minus. Alles"
	.dexText "und jeder, der sich diesem POKéMON"
	.dexText "nähert, friert sofort ein. Sein eisiger"
	.dexText "Körper ist so kalt, dass nicht einmal"
	.dexText "Magma es schmelzen könnte."
	.dexLang IT
	.dexText "REGICE si avvolge in un manto d`aria"
	.dexText "alla temperatura di meno 200 gradi C."
	.dexText "Ogni cosa che si avvicina a questo"
	.dexText "POKéMON si congela all`istante."
	.dexText "Il suo corpo gelido non si fonde"
	.dexText "nemmeno se immerso nel magma."
	.dexLang ES
	.dexText "REGICE se rodea de un aire gélido que"
	.dexText "llega a -200 grados centígrados y deja"
	.dexText "congelado a todo lo que se le acerca."
	.dexText "Es imposible derretir a este POKéMON;"
	.dexText "tiene una temperatura demasiado baja."
	.dexText ""

	.align 2, 0
dexEntryEu195:: @ 195 REGISTEEL
	.2byte 1, 9, 5
	.2byte 10, 6, 0, 3, 10, 10, 1, 9  @ height
	.2byte 10, 4, 5, 1, 9, 10, 2, 0, 5, 0  @ weight
	.dexLang EN
	.dexName "REGISTEEL"
	.dexLang FR
	.dexName "REGISTEEL"
	.dexLang DE
	.dexName "REGISTEEL"
	.dexLang EN
	.dexCategory "IRON"
	.dexLang FR
	.dexCategoryLeftAligned "FER"
	.dexLang DE
	.dexCategoryLeftAligned "EISEN"
	.dexLang IT
	.dexCategoryLeftAligned "FERRO"
	.dexLang ES
	.dexCategoryLeftAligned "HIERRO"
	.dexLang EN
	.dexText "REGISTEEL has a body that is harder"
	.dexText "than any kind of metal."
	.dexText "Its body is apparently hollow."
	.dexText "No one has any idea what this POKéMON"
	.dexText "eats."
	.dexText ""
	.dexLang FR
	.dexText "Le corps de REGISTEEL est plus dur"
	.dexText "que n`importe quel métal existant. Il est"
	.dexText "apparemment creux."
	.dexText "Personne ne sait ce que ce POKéMON"
	.dexText "mange."
	.dexText ""
	.dexLang DE
	.dexText "REGISTEEL hat einen Körper, der härter"
	.dexText "ist als jede Art von Metall. Sein Körper"
	.dexText "scheint hohl zu sein."
	.dexText "Niemand hat eine Ahnung, was dieses"
	.dexText "POKéMON wohl frisst."
	.dexText ""
	.dexLang IT
	.dexText "REGISTEEL ha un corpo più duro"
	.dexText "di ogni tipo di metallo. Pare inoltre"
	.dexText "che all`interno sia totalmente vuoto."
	.dexText "Nessuno sa cosa mangi"
	.dexText "questo POKéMON."
	.dexText ""
	.dexLang ES
	.dexText "No hay metal que supere en dureza"
	.dexText "el cuerpo de REGISTEEL, que tiene"
	.dexText "aspecto de estar hueco."
	.dexText "Nadie sabe de qué se alimenta"
	.dexText "este POKéMON."
	.dexText ""

	.align 2, 0
dexEntryEu196:: @ 196 LATIAS
	.2byte 1, 9, 6
	.2byte 10, 4, 0, 7, 10, 10, 1, 4  @ height
	.2byte 10, 10, 8, 8, 2, 10, 10, 4, 0, 0  @ weight
	.dexLang EN
	.dexName "LATIAS"
	.dexLang FR
	.dexName "LATIAS"
	.dexLang DE
	.dexName "LATIAS"
	.dexLang EN
	.dexCategory "EON"
	.dexLang FR
	.dexCategoryLeftAligned "EON"
	.dexLang DE
	.dexCategoryLeftAligned "ÄON"
	.dexLang IT
	.dexCategoryLeftAligned "EONE"
	.dexLang ES
	.dexCategoryLeftAligned "EÓN"
	.dexLang EN
	.dexText "LATIAS is highly intelligent and capable"
	.dexText "of understanding human speech."
	.dexText "It is covered with a glass-like down."
	.dexText "The POKéMON enfolds its body with its"
	.dexText "down and refracts light to alter its"
	.dexText "appearance."
	.dexLang FR
	.dexText "LATIAS est très intelligent et"
	.dexText "comprend le langage des hommes. Il est"
	.dexText "recouvert d`une espèce de duvet"
	.dexText "ressemblant à du verre. Ce POKéMON"
	.dexText "s`enveloppe dans ce duvet et reflète la"
	.dexText "lumière pour changer son apparence."
	.dexLang DE
	.dexText "LATIAS ist sehr intelligent und kann die"
	.dexText "menschliche Sprache verstehen. Es ist"
	.dexText "mit gläsernen Daunen bedeckt."
	.dexText "Dieses POKéMON umhüllt seinen Körper"
	.dexText "mit den Daunen und kann Licht brechen,"
	.dexText "um seine Gestalt zu verändern."
	.dexLang IT
	.dexText "Estremamente intelligente, LATIAS"
	.dexText "è in grado di capire il linguaggio umano."
	.dexText "Il suo corpo è ricoperto di piumino"
	.dexText "vetroso che usa per rifrangere"
	.dexText "la luce e mutare il proprio aspetto."
	.dexText ""
	.dexLang ES
	.dexText "LATIAS tiene un nivel de inteligencia"
	.dexText "tan alto que es capaz de entender"
	.dexText "el lenguaje humano."
	.dexText "Este POKéMON usa el plumón cristalizado"
	.dexText "del que está cubierto como peto para"
	.dexText "desprender luz y cambiar de aspecto."

	.align 2, 0
dexEntryEu197:: @ 197 LATIOS
	.2byte 1, 9, 7
	.2byte 10, 6, 0, 7, 10, 10, 2, 0  @ height
	.2byte 10, 1, 3, 2, 3, 10, 10, 6, 0, 0  @ weight
	.dexLang EN
	.dexName "LATIOS"
	.dexLang FR
	.dexName "LATIOS"
	.dexLang DE
	.dexName "LATIOS"
	.dexLang EN
	.dexCategory "EON"
	.dexLang FR
	.dexCategoryLeftAligned "EON"
	.dexLang DE
	.dexCategoryLeftAligned "ÄON"
	.dexLang IT
	.dexCategoryLeftAligned "EONE"
	.dexLang ES
	.dexCategoryLeftAligned "EÓN"
	.dexLang EN
	.dexText "LATIOS has the ability to make its foe"
	.dexText "see an image of what it has seen or"
	.dexText "imagines in its head."
	.dexText "This POKéMON is intelligent and"
	.dexText "understands human speech."
	.dexText ""
	.dexLang FR
	.dexText "LATIOS a le pouvoir de faire en sorte"
	.dexText "que son adversaire voie une image"
	.dexText "provenant de son subconscient."
	.dexText "Ce POKéMON est intelligent et comprend"
	.dexText "le langage humain."
	.dexText ""
	.dexLang DE
	.dexText "LATIOS kann seinem Feind ein Bild"
	.dexText "von etwas, das dieser einmal gesehen"
	.dexText "hat, in den Kopf projizieren. Dieses"
	.dexText "POKéMON ist intelligent und es versteht"
	.dexText "die menschliche Sprache."
	.dexText ""
	.dexLang IT
	.dexText "LATIOS ha l`abilità di far vedere al"
	.dexText "proprio nemico l`immagine di ciò che ha"
	.dexText "visto o immaginato nella propria testa."
	.dexText "Questo POKéMON è intelligente e"
	.dexText "capisce il linguaggio umano."
	.dexText ""
	.dexLang ES
	.dexText "LATIOS tiene la habilidad de hacer"
	.dexText "que su rival vea algo que él ha visto"
	.dexText "o imaginado."
	.dexText "Este POKéMON es muy inteligente."
	.dexText "Es capaz de entender el lenguaje"
	.dexText "humano."

	.align 2, 0
dexEntryEu198:: @ 198 KYOGRE
	.2byte 1, 9, 8
	.2byte 1, 4, 0, 9, 10, 10, 4, 5  @ height
	.2byte 10, 7, 7, 6, 0, 10, 3, 5, 2, 0  @ weight
	.dexLang EN
	.dexName "KYOGRE"
	.dexLang FR
	.dexName "KYOGRE"
	.dexLang DE
	.dexName "KYOGRE"
	.dexLang EN
	.dexCategory "SEA BASIN"
	.dexLang FR
	.dexCategoryLeftAligned "BASSINMARIN"
	.dexLang DE
	.dexCategoryLeftAligned "SEEGRÜNDLER"
	.dexLang IT
	.dexCategoryLeftAligned "OCEANO"
	.dexLang ES
	.dexCategoryLeftAligned "CUENCA MAR"
	.dexLang EN
	.dexText "KYOGRE is named in mythology as the"
	.dexText "POKéMON that expanded the sea by"
	.dexText "covering the land with torrential rains"
	.dexText "and towering tidal waves."
	.dexText "It took to sleep after a cataclysmic"
	.dexText "battle with GROUDON."
	.dexLang FR
	.dexText "La mythologie mentionne KYOGRE"
	.dexText "comme le POKéMON qui a agrandi la"
	.dexText "mer en déclenchant des pluies"
	.dexText "torrentielles et des raz-de-marée."
	.dexText "Il s`est endormi à la suite d`un combat"
	.dexText "cataclysmique contre GROUDON."
	.dexLang DE
	.dexText "In der Mythologie taucht KYOGRE als"
	.dexText "dasjenige POKéMON auf, das das Meer"
	.dexText "vergrößert hat, indem es sintflutartige"
	.dexText "Regenfälle und Sturmfluten erzeugt hat."
	.dexText "Nach einem katastrophalen Kampf mit"
	.dexText "GROUDON legte es sich schlafen."
	.dexLang IT
	.dexText "Nella mitologia KYOGRE è considerato"
	.dexText "il POKéMON che ha ingrandito il mare"
	.dexText "allagando la terra con alluvioni"
	.dexText "ed enormi maree. Dopo un cataclisma"
	.dexText "causato dalla sua lotta con GROUDON"
	.dexText "è andato in letargo."
	.dexLang ES
	.dexText "En mitología se conoce a KYOGRE como"
	.dexText "el POKéMON que extendió la superficie"
	.dexText "de los mares haciendo que diluviara"
	.dexText "y creando maremotos. Tras un combate"
	.dexText "contra GROUDON, que acabó"
	.dexText "en cataclismo, se echó a dormir."

	.align 2, 0
dexEntryEu199:: @ 199 GROUDON
	.2byte 1, 9, 9
	.2byte 1, 1, 0, 6, 10, 10, 3, 5  @ height
	.2byte 2, 0, 9, 4, 4, 10, 9, 5, 0, 0  @ weight
	.dexLang EN
	.dexName "GROUDON"
	.dexLang FR
	.dexName "GROUDON"
	.dexLang DE
	.dexName "GROUDON"
	.dexLang EN
	.dexCategory "CONTINENT"
	.dexLang FR
	.dexCategoryLeftAligned "CONTINENT"
	.dexLang DE
	.dexCategoryLeftAligned "KONTINENT"
	.dexLang IT
	.dexCategoryLeftAligned "CONTINENTE"
	.dexLang ES
	.dexCategoryLeftAligned "CONTINENTE"
	.dexLang EN
	.dexText "GROUDON has long been described in"
	.dexText "mythology as the POKéMON that raised"
	.dexText "lands and expanded continents."
	.dexText "This POKéMON took to sleep after a"
	.dexText "cataclysmic battle with KYOGRE."
	.dexText ""
	.dexLang FR
	.dexText "GROUDON est depuis longtemps décrit"
	.dexText "dans la mythologie comme le POKéMON qui"
	.dexText "a créé les terres et agrandi"
	.dexText "les continents. Ce POKéMON s`est"
	.dexText "endormi après un combat cataclysmique"
	.dexText "contre KYOGRE."
	.dexLang DE
	.dexText "GROUDON wurde lange Zeit in der"
	.dexText "Mythologie als ein POKéMON"
	.dexText "beschrieben, das Land erschaffen und"
	.dexText "Kontinente vergrößern kann. Dieses"
	.dexText "POKéMON fiel nach einem erbitterten"
	.dexText "Kampf mit KYOGRE in den Schlaf."
	.dexLang IT
	.dexText "La mitologia descriveva GROUDON"
	.dexText "come colui che fa emergere"
	.dexText "le terre ed espandere i continenti."
	.dexText "Questo POKéMON entrò in letargo"
	.dexText "dopo una lotta contro KYOGRE"
	.dexText "che causò un cataclisma."
	.dexLang ES
	.dexText "A GROUDON siempre se le ha descrito"
	.dexText "en mitología como el POKéMON que elevó"
	.dexText "la tierra y expandió los continentes."
	.dexText "Tras un combate contra KYOGRE"
	.dexText "que acabó en cataclismo, se echó"
	.dexText "a dormir."

	.align 2, 0
dexEntryEu200:: @ 200 RAYQUAZA
	.2byte 2, 0, 0
	.2byte 2, 3, 0, 0, 10, 10, 7, 0  @ height
	.2byte 10, 4, 5, 5, 2, 10, 2, 0, 6, 5  @ weight
	.dexLang EN
	.dexName "RAYQUAZA"
	.dexLang FR
	.dexName "RAYQUAZA"
	.dexLang DE
	.dexName "RAYQUAZA"
	.dexLang EN
	.dexCategory "SKY HIGH"
	.dexLang FR
	.dexCategoryLeftAligned "CIEUX"
	.dexLang DE
	.dexCategoryLeftAligned "HIMMELHOCH"
	.dexLang IT
	.dexCategoryLeftAligned "STRATOSFERA"
	.dexLang ES
	.dexCategoryLeftAligned "CIELO"
	.dexLang EN
	.dexText "RAYQUAZA is said to have lived for"
	.dexText "hundreds of millions of years in the"
	.dexText "earth`s ozone layer, above the clouds."
	.dexText "Its existence had been completely"
	.dexText "unknown because it lived so high in"
	.dexText "the sky."
	.dexLang FR
	.dexText "On raconte que RAYQUAZA a vécu"
	.dexText "pendant des centaines de millions"
	.dexText "d`années dans la couche d`ozone de la"
	.dexText "planète, au-dessus des nuages. Il vivait"
	.dexText "tellement loin que son existence était"
	.dexText "totalement inconnue."
	.dexLang DE
	.dexText "RAYQUAZA soll für hunderte Millionen"
	.dexText "Jahre in der Ozonschicht der Erde über"
	.dexText "den Wolken gelebt haben. Daher wusste"
	.dexText "man so lange nicht von seiner Existenz."
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "Pare che RAYQUAZA abbia vissuto"
	.dexText "per centinaia di migliaia di anni nello"
	.dexText "strato di ozono terrestre oltre le nubi."
	.dexText "Si ignorava la sua esistenza"
	.dexText "poiché viveva così in alto,"
	.dexText "sperduto nel cielo."
	.dexLang ES
	.dexText "Dicen que RAYQUAZA ha vivido más allá"
	.dexText "de las nubes, en la capa de ozono,"
	.dexText "durante cientos de millones de años."
	.dexText "Por este motivo nunca se había tenido"
	.dexText "constancia de su existencia."
	.dexText ""

	.align 2, 0
dexEntryEu201:: @ 201 JIRACHI
	.2byte 2, 0, 1
	.2byte 10, 1, 0, 0, 10, 10, 0, 3  @ height
	.2byte 10, 10, 10, 2, 4, 10, 10, 10, 1, 1  @ weight
	.dexLang EN
	.dexName "JIRACHI"
	.dexLang FR
	.dexName "JIRACHI"
	.dexLang DE
	.dexName "JIRACHI"
	.dexLang EN
	.dexCategory "WISH"
	.dexLang FR
	.dexCategoryLeftAligned "SOUHAIT"
	.dexLang DE
	.dexCategoryLeftAligned "WÜNSCHER"
	.dexLang IT
	.dexCategoryLeftAligned "DESIDERIO"
	.dexLang ES
	.dexCategoryLeftAligned "DESEO"
	.dexLang EN
	.dexText "A legend states that JIRACHI will make"
	.dexText "true any wish that is written on notes"
	.dexText "attached to its head when it awakens."
	.dexText "If this POKéMON senses danger, it will"
	.dexText "fight without awakening."
	.dexText ""
	.dexLang FR
	.dexText "Une légende raconte qu`à son réveil,"
	.dexText "JIRACHI réalise n`importe quel"
	.dexText "souhait inscrit sur les papiers collés"
	.dexText "sur sa tête. Si ce POKéMON se sent en"
	.dexText "danger, il se défend sans même se"
	.dexText "réveiller."
	.dexLang DE
	.dexText "Einer Legende nach erfüllt JIRACHI"
	.dexText "jeden Wunsch, der auf einen Notizzettel"
	.dexText "an seinem Kopf geschrieben wird. Wenn"
	.dexText "dieses POKéMON Gefahr wittert, kämpft"
	.dexText "es bereits, bevor es überhaupt"
	.dexText "aufgewacht ist."
	.dexLang IT
	.dexText "La leggenda racconta che JIRACHI"
	.dexText "realizza ogni desiderio scritto su"
	.dexText "bigliettini che trova attaccati alla"
	.dexText "propria testa, quando si sveglia."
	.dexText "In caso di pericolo, lotta senza"
	.dexText "mai svegliarsi."
	.dexLang ES
	.dexText "Cuenta la leyenda que JIRACHI hará"
	.dexText "realidad el deseo que se le escriba en"
	.dexText "las notas que lleva en la cabeza cuando"
	.dexText "las lea al despertarse."
	.dexText "Si este POKéMON siente peligro, luchará"
	.dexText "sin haber llegado a despertarse."

	.align 2, 0
dexEntryEu202:: @ 101010 CHIKORITA
	.2byte 10, 10, 10
	.2byte 10, 2, 1, 1, 10, 10, 0, 9  @ height
	.2byte 10, 10, 1, 4, 1, 10, 10, 10, 6, 4  @ weight
	.dexLang EN
	.dexName "CHIKORITA"
	.dexLang FR
	.dexName "GERMIGNON"
	.dexLang DE
	.dexName "ENDIVIE"
	.dexLang EN
	.dexCategory "LEAF"
	.dexLang FR
	.dexCategoryLeftAligned "FEUILLE"
	.dexLang DE
	.dexCategoryLeftAligned "LAUB"
	.dexLang IT
	.dexCategoryLeftAligned "FOGLIA"
	.dexLang ES
	.dexCategoryLeftAligned "HOJA"
	.dexLang EN
	.dexText "Bonus appearance on Ruby Field."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang FR
	.dexText "POKéMON additionnel"
	.dexText "intervenant sur le"
	.dexText "plateau du Flipper Rubis."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang DE
	.dexText "Bonus für Rubin."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "Pokémon ospite speciale"
	.dexText "del Flipper Rubino."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang ES
	.dexText "Un invitado especial"
	.dexText "de la mesa Rubí."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""

	.align 2, 0
dexEntryEu203:: @ 101010 CYNDAQUIL
	.2byte 10, 10, 10
	.2byte 10, 1, 0, 8, 10, 10, 0, 5  @ height
	.2byte 10, 10, 1, 7, 4, 10, 10, 10, 7, 9  @ weight
	.dexLang EN
	.dexName "CYNDAQUIL"
	.dexLang FR
	.dexName "HERICENDRE"
	.dexLang DE
	.dexName "FEURIGEL"
	.dexLang EN
	.dexCategory "FIRE MOUSE"
	.dexLang FR
	.dexCategoryLeftAligned "SOURIS FEU"
	.dexLang DE
	.dexCategoryLeftAligned "FEUERMAUS"
	.dexLang IT
	.dexCategoryLeftAligned "FUOCOTOPO"
	.dexLang ES
	.dexCategoryLeftAligned "RATÓNFUEGO"
	.dexLang EN
	.dexText "Bonus appearance on Ruby Field."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang FR
	.dexText "POKéMON additionnel"
	.dexText "intervenant sur le"
	.dexText "plateau du Flipper Rubis."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang DE
	.dexText "Bonus für Rubin."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "Pokémon ospite speciale"
	.dexText "del Flipper Rubino."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang ES
	.dexText "Un invitado especial"
	.dexText "de la mesa Rubí."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""

	.align 2, 0
dexEntryEu204:: @ 101010 TOTODILE
	.2byte 10, 10, 10
	.2byte 10, 2, 0, 0, 10, 10, 0, 6  @ height
	.2byte 10, 10, 2, 0, 9, 10, 10, 10, 9, 5  @ weight
	.dexLang EN
	.dexName "TOTODILE"
	.dexLang FR
	.dexName "KAIMINUS"
	.dexLang DE
	.dexName "KARNIMANI"
	.dexLang EN
	.dexCategory "BIG JAW"
	.dexLang FR
	.dexCategoryLeftAligned "MACHOIRE"
	.dexLang DE
	.dexCategoryLeftAligned "GROSSMAUL"
	.dexLang IT
	.dexCategoryLeftAligned "MASCELLONE"
	.dexLang ES
	.dexCategoryLeftAligned "FAUCES"
	.dexLang EN
	.dexText "Bonus appearance on Ruby Field."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang FR
	.dexText "POKéMON additionnel"
	.dexText "intervenant sur le"
	.dexText "plateau du Flipper Rubis."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang DE
	.dexText "Bonus für Rubin."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "Pokémon ospite speciale"
	.dexText "del Flipper Rubino."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang ES
	.dexText "Un invitado especial"
	.dexText "de la mesa Rubí."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""

	.align 2, 0
dexEntryEu205:: @ 101010 AERODACTYL
	.2byte 10, 10, 10
	.2byte 10, 5, 1, 1, 10, 10, 1, 8  @ height
	.2byte 10, 1, 3, 0, 1, 10, 10, 5, 9, 0  @ weight
	.dexLang EN
	.dexName "AERODACTYL"
	.dexLang FR
	.dexName "PTERA"
	.dexLang DE
	.dexName "AERODACTYL"
	.dexLang EN
	.dexCategory "FOSSIL"
	.dexLang FR
	.dexCategoryLeftAligned "FOSSILE"
	.dexLang DE
	.dexCategoryLeftAligned "FOSSIL"
	.dexLang IT
	.dexCategoryLeftAligned "FOSSILE"
	.dexLang ES
	.dexCategoryLeftAligned "FÓSIL"
	.dexLang EN
	.dexText "Bonus appearance on Ruby Field."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang FR
	.dexText "POKéMON additionnel"
	.dexText "intervenant sur le"
	.dexText "plateau du Flipper Rubis."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang DE
	.dexText "Bonus für Rubin."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang IT
	.dexText "Pokémon ospite speciale"
	.dexText "del Flipper Rubino."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""
	.dexLang ES
	.dexText "Un invitado especial"
	.dexText "de la mesa Rubí."
	.dexText ""
	.dexText ""
	.dexText ""
	.dexText ""

	.dexLang US
