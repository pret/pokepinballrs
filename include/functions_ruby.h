#ifndef GUARD_FUNCTIONS_RUBY_H
#define GUARD_FUNCTIONS_RUBY_H

#include "functions_main_boards.h"

extern void UpdateNuzleafEntity(void);
extern void DrawRubyNuzleafPlatformSprite(void);
extern void RubyPondTriBumperHandleHitAndDraw(void);
extern void DrawWhiscash(void);
extern void AnimateSharpedoEntity(void);
extern void UpdateChikoritaAttackAnimation(void);
extern void AnimateChikoritaSprite(void);
extern void UpdateGulpinBossState(void);

extern void UpdateRubyRampPrizeGate(void);
extern void DrawRubySideBumperSprites(void);
extern void UpdateRubySideBumperAnimation(void);
extern void UpdateRubyBoardEntityRendering(void);
extern void UpdateRubyBoardEntityLogic(void);
extern void HandleRubyFlipperButtonInput(void);
extern void RubyPond_EntityLogic(void);

#endif //GUARD_FUNCTIONS_RUBY_H