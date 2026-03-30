#pragma once
#include "clsUser.h"

clsUser currentUser = clsUser::find("", "");



clsUser getCurrentUser()
{
	return currentUser;
}


