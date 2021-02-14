/*****************************************************************
 * Copyright (C) 2017-2019 Robert Valler - All rights reserved.
 *
 * This file is part of the project: StarterApp
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/


#include "test_control_app.h"

int main(int argc, char *argv[])
{

    CTestControlApp testApp;

    testApp.interface_1(1);
    testApp.interface_2(1);
    testApp.Process();


}
