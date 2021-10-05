//
// Created by Sarah Ogent on 10/4/21.
//

#include "calc3DDistModule.h"
#include <iostream>
#include <cmath>

double calcDistance(double& x1, double& x2, double& y1, double& y2, double& z1, double& z2){
    double xUnderSQRT = x1-x2;
    double xSquared = pow(xUnderSQRT, 2);
    double yUnderSQRT = y1-y2;
    double ySquared = pow(yUnderSQRT, 2);
    double zUnderSQRT = z1 - z2;
    double zSquared = pow(zUnderSQRT, 2);
    double sumUnderSQRT = xSquared+ySquared+zSquared;
    double xyzUnderSQRT = sqrt(sumUnderSQRT);

    return xyzUnderSQRT;
}
