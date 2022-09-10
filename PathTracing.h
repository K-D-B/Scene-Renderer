#pragma once
#include<vector>
#include<limits>
#include<cstdlib>
#include"PTVec.h"
#include"PTRay.h"
#include"hittable.h"

namespace PT {
	const double infinity = std::numeric_limits<double>::infinity();
	
	vec3 rayColor(Ray r,hittable& world,int depth);

	void render();
}

