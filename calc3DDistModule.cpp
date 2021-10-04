//
// Created by Sarah Ogent on 10/4/21.
//

#include "calc3DDistModule.h"
#include <iostream>
#include <cmath>

float calc3Ddistance(float x1, float x2, float y1, float y2, float z1, float z2){
    float xUnderSQRT = x1-x2;
    double xSquared = pow(xUnderSQRT, 2);
    float yUnderSQRT = y1-y2;
    double ySquared = pow(yUnderSQRT, 2);
    float zUnderSQRT = z1 - z2;
    double zSquared = pow(zUnderSQRT, 2);
    float sumUnderSQRT = xSquared+ySquared+zSquared;
    float xyzUnderSQRT = sqrt(sumUnderSQRT);

    return xyzUnderSQRT;



}
