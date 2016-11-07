/* ============================================================
   FileName:    Action.hpp
   Created:     2016/11/07 by PorcaM
   Modified:	2016/11/07 by PorcaM
   ============================================================ */

#ifndef ACTION_HPP
#define ACTION_HPP

#include "characters/Character.h"

/* ============================================================
   Interface for skill action.
   ============================================================ */
class Action {
 public:
	static virtual void Do(Character *target,
						   int		  amount) = 0;
};

#endif	/* end of include guard: ACTION_HPP */
