/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: test_main
 * Author: lvyingchao 00596108
 * Create: 2021-05-11
 */

#include <iostream>
#include "../code/source/stub/ClientStub.h"

using namespace std;

struct B {
    int a;
    int b;
};

struct A {
    int a;
    B b;
};

int main() {
    cout << "hello client" << endl;

    ClientStub client;
    AddReturn addReturn{};
    client.call("server1.remoteAdd", addReturn, 2, 3);
    cout << addReturn.ans << endl;
}

