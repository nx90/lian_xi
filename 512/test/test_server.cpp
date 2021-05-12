/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: test_server
 * Author: lvyingchao 00596108
 * Create: 2021-05-11
 */

#include <iostream>
#include "../code/source/stub/ServerStub.h"

using namespace std;

int main() {
    cout << "hello server" << endl;
    ServerStub server;
    server.go();

}
