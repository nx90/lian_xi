/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2021-2021. All rights reserved.
 * Description: server_infos
 * Author: lvyingchao 00596108
 * Create: 2021-05-11
 */
//
// Created by l00596108 on 2021/5/11.
//

#ifndef MYRPC_SERVER_INFOS_H
#define MYRPC_SERVER_INFOS_H

#include <map>
#include <string>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


const struct sockaddr_in server1Sockaddr{AF_INET, htons(7777), htonl(INADDR_ANY), ""};

const std::map<std::string, sockaddr_in> serverAddrs {
        {"server1", server1Sockaddr}
};

#endif //MYRPC_SERVER_INFOS_H
