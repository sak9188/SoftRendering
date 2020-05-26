#pragma once
#define SFR_TYPE
#include "SFRSetting.h"

#include <glm\glm.hpp>

namespace SFR
{
	glm::uint Con_vec4ToColor(glm::vec4 vec)
	{
		return (int(vec.r * 255) << 24) | (int(vec.g * 255) << 16) | (int(vec.b * 255) << 8) | int(vec.a * 255);
	}
}